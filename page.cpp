#include "page.hpp"

Page::Page(int pageNum, int frameNum)
{
    setPageNum(pageNum);
    setFrameNum(frameNum);
}

int Page::getPageNum()
{
    return this->pageNum;
}

int Page::getFrameNum()
{
    return this->frameNum;
}

void Page::setPageNum(int pageNum)
{
    this->pageNum = pageNum;
}

void Page::setFrameNum(int frameNum)
{
    this->frameNum = frameNum;
}
