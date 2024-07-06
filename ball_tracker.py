import cv2
import numpy as np
import csv
import time

def define_quadrants(frame):
    height, width, _ = frame.shape
    quadrants = {
        1: (0, width // 2, 0, height // 2),
        2: (width // 2, width, 0, height // 2),
        3: (0, width // 2, height // 2, height),
        4: (width // 2, width, height // 2, height)
    }
    return quadrants

def get_quadrant(x, y, quadrants):
    for quadrant, (x1, x2, y1, y2) in quadrants.items():
        if x1 <= x < x2 and y1 <= y < y2:
            return quadrant
    return None

def track_balls(video_path, output_video, output_csv):
    cap = cv2.VideoCapture(video_path)
    fourcc = cv2.VideoWriter_fourcc(*'XVID')
    out = cv2.VideoWriter(output_video, fourcc, 20.0, (int(cap.get(3)), int(cap.get(4))))
    quadrants = None
    ball_positions = {}
    frame_count = 0
    fps = cap.get(cv2.CAP_PROP_FPS)
    start_time = time.time()

    with open(output_csv, 'w', newline='') as csvfile:
        fieldnames = ['Time', 'Quadrant Number', 'Ball Colour', 'Type']
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
        writer.writeheader()

        while cap.isOpened():
            ret, frame = cap.read()
            if not ret:
                break

            if quadrants is None:
                quadrants = define_quadrants(frame)

            hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

            colors = {
                'Red': ([0, 120, 70], [10, 255, 255]),
                'Green': ([36, 25, 25], [70, 255, 255]),
                'Blue': ([94, 80, 2], [126, 255, 255]),
            }

            for color_name, (lower, upper) in colors.items():
                lower_np = np.array(lower, dtype=np.uint8)
                upper_np = np.array(upper, dtype=np.uint8)
                mask = cv2.inRange(hsv, lower_np, upper_np)
                contours, _ = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

                for contour in contours:
                    if cv2.contourArea(contour) > 500:
                        x, y, w, h = cv2.boundingRect(contour)
                        cx, cy = x + w // 2, y + h // 2
                        current_quadrant = get_quadrant(cx, cy, quadrants)

                        if color_name not in ball_positions:
                            ball_positions[color_name] = {}

                        previous_quadrant = ball_positions[color_name].get('quadrant')
                        if current_quadrant != previous_quadrant:
                            timestamp = frame_count / fps
                            if previous_quadrant is not None:
                                writer.writerow({
                                    'Time': timestamp,
                                    'Quadrant Number': previous_quadrant,
                                    'Ball Colour': color_name,
                                    'Type': 'Exit'
                                })
                                cv2.putText(frame, f"Exit {previous_quadrant} {color_name} {timestamp:.2f}",
                                            (10, frame.shape[0] - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 2)
                            writer.writerow({
                                'Time': timestamp,
                                'Quadrant Number': current_quadrant,
                                'Ball Colour': color_name,
                                'Type': 'Entry'
                            })
                            cv2.putText(frame, f"Entry {current_quadrant} {color_name} {timestamp:.2f}",
                                        (10, frame.shape[0] - 30), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 2)
                            ball_positions[color_name]['quadrant'] = current_quadrant

            out.write(frame)
            frame_count += 1

        cap.release()
        out.release()

track_balls('input_video.mp4', 'output_video.avi', 'ball_tracking_output.csv')
