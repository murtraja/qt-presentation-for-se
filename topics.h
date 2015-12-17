#ifndef TOPICS_H
#define TOPICS_H
#include<string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Topics
{
    vector<string> topics;

public:
    Topics();
    vector<string> getTopics();
    ~Topics();
};

#endif // TOPICS_H
