#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main(void)
{
    int n;
    int i;
    char name[10], status[10];
    map<string, string> enterLog;
    map<string, string>::iterator it;
    vector<string> inCompany;
    vector<string> outCompany;

    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%s %s", name, status);
        if(enterLog.size() > 0 && enterLog.find(name) != enterLog.end())
            enterLog[name] = status;
        else
            enterLog.insert(make_pair(name, status));
    }

    for(it=enterLog.begin();it!=enterLog.end();it++)
    {
        pair<string, string> log = *it;
        if(log.second == "enter")
        {
            inCompany.push_back(log.first);
        }
        else if(log.second == "leave")
        {
            outCompany.push_back(log.first);
        }
    }

    /*
    // debug
    printf("-------debug------\n");
    printf("inCompany: %lu, outCompany: %lu\n", inCompany.size(), outCompany.size());
    printf("inCompany:");
    for(i=0;i<inCompany.size();i++)
        printf(" %s", inCompany[i].c_str());
    printf("\n");
    printf("outCompany:");
    for(i=0;i<outCompany.size();i++)
        printf(" %s", outCompany[i].c_str());
    printf("\n");
    printf("-------debug------\n");
    */

    sort(inCompany.begin(), inCompany.end());

    for(i=inCompany.size()-1;i>=0;i--)
    {
        printf("%s\n", inCompany[i].c_str());
    }

    return 0;
}