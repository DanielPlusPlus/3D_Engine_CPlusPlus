#include "BitmapHandler.h"
#pragma warning(disable : 4996)
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

BitmapHandler::BitmapHandler()
{
    this->width = 800;
    this->height = 600;
    this->data.resize(width * height * 3, 255);
}

BitmapHandler::BitmapHandler(int width, int height)
{
    this->width = width;
    this->height = height;
    this->data.resize(width * height * 3, 255);
}

BitmapHandler::~BitmapHandler()
{
}

void BitmapHandler::loadFromFile(std::string filename)
{
    int channels;
    unsigned char* image = stbi_load(filename.c_str(), &width, &height, &channels, 3);

    if (image) {
        data.resize(width * height * 3);
        std::copy(image, image + (width * height * 3), data.begin());
        stbi_image_free(image);
    }
    else {
        std::cout << "Nie mo¿na za³adowaæ tekstury " << filename << std::endl;
    }
}

void BitmapHandler::saveToFilePNG(std::string filename)
{
    stbi_write_png(filename.c_str(), width, height, 3, data.data(), 0);
}

void BitmapHandler::saveToFileJPG(std::string filename)
{
    stbi_write_jpg(filename.c_str(), width, height, 3, data.data(), 100);
}

void BitmapHandler::saveToFileBMP(std::string filename)
{
    stbi_write_bmp(filename.c_str(), width, height, 3, data.data());
}

void BitmapHandler::saveToFileTGA(std::string filename)
{
    stbi_write_tga(filename.c_str(), width, height, 3, data.data());
}

void BitmapHandler::copyFromBitmap(BitmapHandler texture)
{
    if (width == texture.width && height == texture.height) {
        data = texture.data;
    }
    else {
        std::cout << "Nie mo¿na skopwiowaæ tekstury z innego obiektu BitmapHandler" << std::endl;
    }
}

void BitmapHandler::draw()
{
	glDrawPixels(width, height, GL_RGB, GL_UNSIGNED_BYTE, data.data());
}
