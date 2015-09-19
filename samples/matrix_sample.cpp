#include "matrix.hpp"
#include "filters.hpp"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main()
{
    cout << "---------------------------" << endl;

    Matrix m(3, 4);
    m.Random();
    cout << m;

    cout << "---------------------------" << endl;

    Filters* filters = createFilters(OPENCV);

    Matrix mf(3, 4);
    m.Zeros();
    filters->boxFilter(m, mf);
    cout << mf;

    cout << "---------------------------" << endl;

    // some experiments
    const std::string input = "./testdata/image.png";
    const std::string output = "./testdata/image_box_color.png";

    Mat srcMat, dstMat;
    srcMat = imread(input, CV_LOAD_IMAGE_COLOR);

    boxFilter(srcMat, dstMat, -1, Size2i(3,3));
    imwrite("./testdata/image_box_color.png", dstMat);
    
    boxFilter(srcMat, dstMat, -1, Size2i(5,5));
    imwrite("./testdata/image_box_color_5.png", dstMat);

    boxFilter(srcMat, dstMat, -1, Size2i(3,3), cv::Point(-1,-1), false, 4);
    imwrite("./testdata/image_box_color_no_norm.png", dstMat);

    return 0;
}
