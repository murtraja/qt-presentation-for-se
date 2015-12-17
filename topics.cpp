#include "topics.h"

Topics::Topics()
{
    // cout<<"In topics constructor";
    // WARNING!
    // do not hardcode the file path, include the file as a resource instead just
    // like the image
    ifstream ifile("/home/murtraja/Documents/qt_presentation/presentation_flow.txt");
    if(ifile.is_open())
    {
        string line;
        while(getline(ifile, line))
        {
            this->topics.push_back(line);
        }
    }

}

vector<string> Topics::getTopics()
{
    return this->topics;
}

Topics::~Topics()
{

}

