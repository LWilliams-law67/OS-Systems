
#ifndef PAGE_HPP
#define PAGE_HPP

class Page
{
    private:
        int pageNum, frameNum;

    public:
        Page(int pageNum, int frameNum);
        int getPageNum();
        int getFrameNum();
        void setPageNum(int pageNum);
        void setFrameNum(int frameNum);
};

#endif