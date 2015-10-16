#include "opencv2/opencv.hpp"

// defined in opencv/modules/videoio/src/precomp.hpp
struct CvCapture
{
    virtual ~CvCapture() {}
    virtual double getProperty(int) const { return 0; }
    virtual bool setProperty(int, double) { return 0; }
    virtual bool grabFrame() { return true; }
    virtual IplImage* retrieveFrame(int) { return 0; }
    virtual int getCaptureDomain() { return CV_CAP_ANY; } // Return the type of the capture object: CV_CAP_VFW, etc...
};

enum
{
    PSEYE_CAP_ANY       =0,     // autodetect
    PSEYE_CAP_CLMULTI   =100,
    PSEYE_CAP_CLEYE     =200,
    PSEYE_CAP_PS3EYE    =300
};

class PSEyeVideoCapture : public cv::VideoCapture {
public:
    PSEyeVideoCapture(int camindex)
    : cv::VideoCapture(camindex)
    {
        // Only require super constructor
    };
    
    bool open(int index);
    
    static CvCapture* pseyeCreateCameraCapture(int index);
    /*
    static CvCapture* pseyeCreateCameraCapture_CLMULTI(int index);
    static CvCapture* pseyeCreateCameraCapture_CLEYE(int index);
    */
    static CvCapture* pseyeCreateCameraCapture_PS3EYE(int index);
};

/*
class PSEEYECaptureCAM_CLMULTI : public CvCapture
{
public:
    PSEEYECaptureCAM_CLMULTI();
    virtual ~PSEEYECaptureCAM_CLMULTI();
    virtual bool open( int index );
    virtual void close();
    virtual double getProperty(int) const;
    virtual bool setProperty(int, double);
    virtual bool grabFrame();
    virtual IplImage* retrieveFrame(int);
    virtual int getCaptureDomain() { return CV_CAP_MSMF; } // Return the type of the capture object: CV_CAP_VFW, etc...
protected:
    void init();
    int index, width, height, fourcc;
    IplImage* frame;
    videoInput VI;
};

class PSEEYECaptureCAM_CLEYE : public CvCapture
{
public:
    PSEEYECaptureCAM_CLEYE();
    virtual ~PSEEYECaptureCAM_CLEYE();
    virtual bool open( int index );
    virtual void close();
    virtual double getProperty(int) const;
    virtual bool setProperty(int, double);
    virtual bool grabFrame();
    virtual IplImage* retrieveFrame(int);
    virtual int getCaptureDomain() { return CV_CAP_MSMF; } // Return the type of the capture object: CV_CAP_VFW, etc...
protected:
    void init();
    int index, width, height, fourcc;
    IplImage* frame;
    videoInput VI;
};
*/

class PSEEYECaptureCAM_PS3EYE : public CvCapture
{
public:
    PSEEYECaptureCAM_PS3EYE();
    virtual ~PSEEYECaptureCAM_PS3EYE();
    virtual bool open( int index );
    virtual void close();
    virtual double getProperty(int) const;
    virtual bool setProperty(int, double);
    virtual bool grabFrame();
    virtual IplImage* retrieveFrame(int);
    virtual int getCaptureDomain() { return CV_CAP_MSMF; } // Return the type of the capture object: CV_CAP_VFW, etc...
protected:
    void init();
    int index, width, height, fourcc;
    IplImage* frame;
};