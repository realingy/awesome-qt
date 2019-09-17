#include <opencv2/opencv.hpp>
#include <QList>
#include <QDebug>

using namespace cv;

Mat stitchImages(const QList<QList<Mat> > &imageArray, const QList<QList<Rect> > &mappedRects, const bool &colorMode)
{
    Rect outRect(0, 0, 0, 0);

    foreach(const QList<Rect>& rects, mappedRects)
        for(const Rect &rect : rects)
            outRect |= rect;

    Mat img;
    std::vector<Mat> imgBGR(3);

    if (colorMode)
        for (int i = 0; i < 3; i++)
            imgBGR[i] = Mat(outRect.size(), CV_16UC1, Scalar(0));
    else
        img = Mat(outRect.size(), CV_16UC1, Scalar(0));

    int colorChannel = 0;

    for (int i = 0; i < imageArray.length(); i++)
	{
        for (int j = 0; j < imageArray[i].length(); j++)
        {
            Mat & dstI = (colorMode) ? imgBGR[(colorChannel++) % 3] : img;
            Mat dstPatch = dstI(mappedRects[i][j]);
            Mat dstMask = (dstPatch==0);
            imageArray[i][j].copyTo(dstPatch, dstMask);

            //average blender
            dstPatch = dstPatch/2+ imageArray[i][j]/2;
        }
	}

    if (colorMode)
        merge(imgBGR, img);

    return img;
}

int main()
{

}


