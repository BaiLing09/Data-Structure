#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <Eigen/Core>

using namespace std;

int main()
{
    cv::Mat A;
    A = (cv::Mat_<float>(3,3) << 1,1,1,1,1,1,1,1,1);
    for(int i = 0 ; i < 10 ; i++)
    std::cout << "Hello World!" << std::endl;
    std::cout << A<<std::endl;

    Eigen::Matrix<float, 2, 3> matrix_23;
    // 下面是对Eigen阵的操作
    // 输入数据（初始化）
    matrix_23 << 1, 2, 3, 4, 5, 6;
    // 输出
    cout << matrix_23 << endl;
    return 0;
}