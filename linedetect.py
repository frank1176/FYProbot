import cv2
import numpy as np

# Create a VideoCapture object
cap = cv2.VideoCapture(1) 

if not cap.isOpened(): 
    print("Cannot open camera")
    exit()

# Get frame's width and height
frame_width = int(cap.get(cv2.CAP_PROP_FRAME_WIDTH))
frame_height = int(cap.get(cv2.CAP_PROP_FRAME_HEIGHT))

while True:
    # Capture frame-by-frame
    ret, frame = cap.read()
    if not ret:
        print("Can't receive frame (stream end?). Exiting ...")
        break

    # Calculate the x coordinates for the lines
    x1 = frame_width // 3
    x2 = 2 * frame_width // 3

    # Draw the first line at 1/3 of the frame width
    line_frame = cv2.line(frame, (x1, 0), (x1, frame_height), (0, 255, 0), 2)

    # Draw the second line at 2/3 of the frame width
    line_frame = cv2.line(line_frame, (x2, 0), (x2, frame_height), (0, 0, 255), 2)

    # Display the resulting frame
    cv2.imshow('Frame with Line', line_frame)

    # Wait for 'q' key to close the program
    if cv2.waitKey(1) == ord('q'):
        break

# When everything done, release the capture and destroy the windows
cap.release()
cv2.destroyAllWindows()
