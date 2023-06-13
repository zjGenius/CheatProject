#include "l_opencv.h"

/**
 * @brief 显示并保存图片
 *
 * @return int
 */
int test_imge()
{
    char imageName[] = "./shake.png";
    cv::Mat M = cv::imread(imageName, cv::IMREAD_COLOR); // 读入图片

    if (M.empty()) // 判断文件是否正常打开
    {
        LOG_E("Can not load image %s\n", imageName);
        cv::waitKey(6000); // 等待6000 ms后窗口自动关闭
        return -1;
    }

    cv::imshow("image", M); // 显示图片
    cv::waitKey(0);
    cv::imwrite("pic.bmp", M); // 存为bmp格式图片
    LOG_D("\nOK\n");
    return 0;
}

/**
 * @brief 边缘检测
 *  边缘检测其实就是找到图像上的边缘，很好玩，进行边缘检测的前提是先将图片灰度化，如果想边缘更清晰的话，可以在检测前加一步滤波。
 *  如果对一个函数的参数不是很了解，可以去修改参数的值，看效果发生变化，就知道这个参数的影响在哪里了
 * @return int
 */
int test_imge1()
{
    cv::Mat src = cv::imread("./shake.png");
    cv::namedWindow("原图", cv::WINDOW_FREERATIO);
    cv::imshow("原图", src);
    cv::Mat dst;
    cv::cvtColor(src, src, cv::COLOR_BGR2GRAY);
    cv::blur(src, src, cv::Size(3, 3));
    cv::Canny(src, dst, 3, 8, 3);
    cv::namedWindow("边缘检测", cv::WINDOW_FREERATIO);
    cv::imshow("边缘检测", dst);
    cv::waitKey(0);
    return 0;
}

/**
 * @brief 三种形态学处理：腐蚀，膨胀，滤波
 *  腐蚀：erode() 将一张图片边界点去除。
    膨胀：dilate() 对图像的边界进行扩张。
    这两个操作正好是相反的，他们操作的组合还能组成开运算，闭运算，顶帽，黑帽等一系列形态学处理
 *
 * @return int
 */
int test_imge2()
{
    cv::Mat src = cv::imread("./shake.png");
    cv::namedWindow("原图", cv::WINDOW_FREERATIO);
    cv::imshow("原图", src);
    cv::Mat dst1, dst2, dst3;
    cv::Mat element = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(15, 15));

    cv::erode(src, dst1, element); // 腐蚀
    cv::namedWindow("腐蚀", cv::WINDOW_FREERATIO);
    cv::imshow("腐蚀", dst1);

    cv::dilate(src, dst2, element); // 膨胀
    cv::namedWindow("膨胀", cv::WINDOW_FREERATIO);
    cv::imshow("膨胀", dst2);

    cv::blur(src, dst3, cv::Size(7, 7)); // 滤波
    cv::namedWindow("滤波", cv::WINDOW_FREERATIO);
    cv::imshow("滤波", dst3);

    cv::waitKey(0);
    return 0;
}

void test_mat()
{
    // 利用成员函数 create() 创建图像矩阵
    cv::Mat M;
    M.create(4, 4, CV_8UC1); // 4行4列，开辟内存，但未指定像素的初值
    std::cout << "M = " << std::endl
              << " " << M << std::endl
              << std::endl;

    // 利用Mat类的构造函数创建图像矩阵
    // 2维图像—平面图像
    cv::Mat M1(2, 2, CV_8UC3, cv::Scalar(0, 0, 255)); // 2行2列，给定全体像素的值
    std::cout << "M1 = " << std::endl
              << " " << M1 << std::endl
              << std::endl;
}

void test_draw()
{
    char imageName[] = "./shake.png";
    cv::Mat M = cv::imread(imageName, cv::IMREAD_COLOR); // 读入图片
    // 画圆
    cv::Point center = cv::Point(255, 255); // 圆心
    int r = 100;                            // 半径
    cv::circle(M, center, r, cv::Scalar(0, 0, 0));
    // 参数为：原图像、圆心、半径、颜色、粗细、线型
    cv::imshow("image", M); // 显示图片
    cv::waitKey();
}