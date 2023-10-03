#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;

int main(int argc, char *argv[]) {
    cv::VideoCapture vcap(0);
    std::string slowVideo("Slow video");
    std::string testVideo("Testing window");
    cv::namedWindow(slowVideo, CV_WINDOW_NORMAL);
    cv::namedWindow(testVideo, CV_WINDOW_NORMAL);
    bool isTesting(true);
    cv::Mat img;
    vcap >> img;
    cv::flip (img, img, 1);
    cv::imshow(slowVideo, img);
    cv::imshow(testVideo, img);
    double bright(1.0);
    const int ESC(27);
    while (true) {
        vcap >> img;
        cv::flip (img, img, 1);
        cv::multiply(img, bright, img);
        if (isTesting) {
            cv::imshow(testVideo, img);
        }
        int key = cv::waitKey(1);
        if (key == ESC) {
            break;
        } else if (key == 'c') {
            isTesting = false;
            cv::destroyWindow(testVideo);
        } else if (key == '-') {
            bright -= 0.05;
        } else if (key == '+') {
            bright += 0.05;
        } else if (key != -1) {
            cv::imshow(slowVideo, img);
        }
    }
    cv::destroyAllWindows();
    return 0;
}
