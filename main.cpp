#include "page.hpp"
#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

template<typename T> void printElement(T t, const int& width, const char& separator)
{
    cout << left << setw(width) << setfill(separator) << t;
}

int main()
{
    // constants for formatting output of Page Map Table.
    const int width = 8;
    const char separator = ' ';

    // Vector to store pages and their associated data.
    vector<Page> pages = vector<Page>();
    int pageNum, frameNum, location, locationsPer, offset, sizeOfProcess;
    Page p = Page(0,0);

    // User provides input for process and designated page sizes.
    cout << "Please enter the size of the process as an integer of logical locations: ";
    cin >> sizeOfProcess;
    cout << "Enter the page/frame size as an integer of logical locations: ";
    cin >> locationsPer;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;

    // Calculates the total number of pages for the process.
    pageNum = sizeOfProcess / locationsPer;

    // User provides input for assigned frame number for each page then adds the pages to the vector.
    cout << "There are " << pageNum + 1 << " pages (0-" << pageNum << ") for this process." << endl;
    cout << "Please provide a frame number for each page." << endl;
    for(int i = 0; i <= pageNum; i++)
    {
        cout << "Page " << i << ": ";
        cin >> frameNum;
        p = Page(i, frameNum);
        pages.push_back(p);
    }

    printElement("Page#", width, separator);
    printElement("Frame#", width, separator);
    for(vector<Page>::iterator i = pages.begin(); i < pages.end(); i++)
    {
        printElement(i->getPageNum(), width, separator);
        printElement(i->getFrameNum(), width, separator);
        cout << endl;
    }

    // Get location # from user.
    cout << "Please enter a memory location as an integer: ";
    cin >> location;
    cout << endl;

    // Calculate and set offset and absolute location from beginning of memory map.
    int residesInPage = location / locationsPer;
    int logicalLocation = location - (locationsPer * (residesInPage - 1));
    offset = logicalLocation - 1;
    p = pages.at(residesInPage);
    int absloc = (p.getFrameNum() * locationsPer) + (offset);

    printElement("Page#", width, separator);
    printElement("Frame#", width, separator);
    printElement("Offset", width, separator);
    printElement("AbsLoc", width, separator);
    printElement(offset, width, separator);
    printElement(absloc, width, separator);

}
