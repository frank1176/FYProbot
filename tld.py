import cv2
import sys

def main():

    # specify the video source. Can be either device index or name of a video file.
    # In this case, we are using the first webcam of the system.
    video_src = 0 

    # create a window named 'Tracking'
    cv2.namedWindow("Tracking")

    # read from the video capture
    cap = cv2.VideoCapture(video_src)

    # check if video opened successfully
    if not cap.isOpened:
        print("Could not open video")
        sys.exit()

    # read first frame
    ok, frame = cap.read()
    if not ok:
        print("Cannot read video")
        sys.exit()

    # define an initial bounding box
    bbox = (287, 23, 86, 320)

    # Uncomment the line below to select a different bounding box
    # bbox = cv2.selectROI(frame, False)

    # initialize tracker with first frame and bounding box
    tracker = cv2.TrackerKCF_create()
    ok = tracker.init(frame, bbox)

    while True:
        # read a new frame
        ok, frame = cap.read()
        if not ok:
            break
        
        # start timer
        timer = cv2.getTickCount()

        # update tracker
        ok, bbox = tracker.update(frame)

        # calculate frames per second (FPS)
        fps = cv2.getTickFrequency() / (cv2.getTickCount() - timer);

        # draw bounding box
        if ok:
            # tracking success
            p1 = (int(bbox[0]), int(bbox[1]))
            p2 = (int(bbox[0] + bbox[2]), int(bbox[1] + bbox[3]))
            cv2.rectangle(frame, p1, p2, (255,0,0), 2, 1)
        else:
            # tracking failure
            cv2.putText(frame, "Tracking failure detected", (100,80), cv2.FONT_HERSHEY_SIMPLEX, 0.75,(0,0,255),2)

        # display tracker type on frame
        cv2.putText(frame, "TLD Tracker", (100,20), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (50,170,50),2);
    
        # display FPS on frame
        cv2.putText(frame, "FPS : " + str(int(fps)), (100,50), cv2.FONT_HERSHEY_SIMPLEX, 0.75, (50,170,50), 2);

        # show frame
        cv2.imshow("Tracking", frame)

        # quit if 'q' is pressed
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    # release the VideoCapture
    cap.release()

    # destroy all windows
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()
