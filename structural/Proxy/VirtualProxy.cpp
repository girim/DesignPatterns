#include <iostream>

struct Image
{
    virtual ~Image() = default;
    virtual void draw() = 0;
};

struct Bitmap : public Image
{
    Bitmap(const std::string& filename)
    {
        std::cout << "Loading filename  "<< filename << "\n";
    }

    virtual void draw() override
    {
        std::cout << "Drawing Bitmap ...." << "\n";
    }
};

struct LazzyBitmap : public Image
{
    std::string& filename_;
    Bitmap* bmp_{nullptr};

    LazzyBitmap(std::string filename) : filename_(filename){}
    ~LazzyBitmap() { delete bmp_;};

    virtual void draw() override
    {
        if(!bmp_)
        {
            bmp_ = new Bitmap(filename_);
            bmp_->draw();
        }
    }
};

void drawImage(Image& img)
{
    img.draw();
}

int main(int argc, char const *argv[])
{
    LazzyBitmap lazzyBitmap{"test.bmp"};
    drawImage(lazzyBitmap);
    
    return 0;
}







