#include <iostream>
#include "CDataChain.h";
#include "CWorkspace.h";
#include "CDialogManager.h";
#include "CDlgCommand.h";
#include "CLink.h"

void Init(CWorkspace& ws)
{
    int nDepth;
    int nMaxLength;
    cout << "Depth: ";
    cin >> nDepth;
    cout << "Max Length: ";
    cin >> nMaxLength;

    ws.Init(nDepth, nMaxLength);
}
void ShowFullSequence(CWorkspace& ws)
{
    cout << ws.GetChainString() << std::endl;
}
void Save(CWorkspace& ws)
{
    string sPath;
    cout << "Path: ";
    cin >> sPath;
    ws.Save(sPath);
}
void Load(CWorkspace& ws)
{
    string sPath;
    cout << "Path: ";
    cin >> sPath;
    ws.Load(sPath);
}
void FindSubstring(CWorkspace& ws)
{

    string sStr;
    cout << "String: ";
    cin >> sStr;
    int i = ws.FindSubstring(sStr);
    if (i == -1)
        cout << "Not Exist"<<endl;
    else
        cout << "Index of substring: "<<i<<endl;
}
void ShowAllLinks(CWorkspace& ws)
{
    LinksArray Link;
    ws.GetAllLinks(Link);
    for (int i = 0; i < Link.size(); i++)
    {
        cout << i+1 + ". ";
        Link[i]->Output(cout);
    }
}
void RemoveLink(CWorkspace& ws)
{
    ShowAllLinks(ws); 
    int i;
    cin >> i;
    ws.RemoveLink(i - 1);
}
void AddLink(CWorkspace& ws)
{
    string sStr;
    int nInd;
    cout << "1. URL" << endl;
    cout << "2. Person" << endl;
    cin >> nInd;
    cout << "Sub Str: ";
    cin >> sStr;
    if (nInd == 1)
    {
        string sURL;
        cout << "URL: ";
        cin >> sURL;
        ws.AddURL(sStr.c_str(), sURL.c_str());
    }
    else if (nInd == 2)
    {
        int nGroup;
        cout << "Group: ";
        cin >> nGroup;
        string sName;
        cout << "Name: ";
        cin >> sName;
        ws.AddPerson(sStr.c_str(), nGroup,sName.c_str());
    }
    else
    {
        AddLink(ws);
    }

    
}

int main()
{
    CDataSimple data;
    CWorkspace ws(data);
    CDialogManager mgr(ws);
    mgr.RegisterCommand("Init sequence", Init);
    mgr.RegisterCommand("Show sequence", ShowFullSequence);
    mgr.RegisterCommand("Save", Save);
    mgr.RegisterCommand("Load", Load);
    mgr.RegisterCommand("Find substring", FindSubstring);
    mgr.RegisterCommand("Show All Links", ShowAllLinks);
    mgr.RegisterCommand("Remove Link", RemoveLink);
    mgr.RegisterCommand("Add Link", AddLink);
    mgr.Run();
    return 0;
}
