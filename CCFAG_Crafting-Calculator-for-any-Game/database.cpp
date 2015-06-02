#include "database.h"
#include "item.h"

#include <iostream>
#include <fstream>

Database::Database()
{
    this->filename = L"items.xml";

    loadFromFile();
}

Database::~Database()
{

}

void Database::loadFromFile()
{
    std::wifstream databaseFile;
    std::wstring lineBuffer;
    const size_t nExist = std::wstring::npos;
    int lineCounter = 0;

    std::wstring category;
    std::wstring itemID;

    bool bCommentBlock = false;

    databaseFile.open("items.xml");

    while(getline(databaseFile, lineBuffer, L'\n') )
    {
        lineCounter++;

        if( lineBuffer.find(L"<!--") != nExist)
        {
            bCommentBlock = true;
        }
        if( lineBuffer.find(L"-->") != nExist)
        {
            bCommentBlock = false;
        }

        if( bCommentBlock == false)
        {

            if( lineBuffer.find(TAGCATEGORY) != nExist)
            {
                std::wcout << L"Kategorie: >" << getParameterFromTag(lineBuffer) << L"<" << std::endl;

                category = getParameterFromTag(lineBuffer);
            }

            else if( lineBuffer.find(TAGITEM) != nExist)
            {
                std::wcout << L"ItemID: >" << getParameterFromTag(lineBuffer) << L"<" << std::endl;

                itemID = getParameterFromTag(lineBuffer);

                Item *newItem = new Item(itemID);

                itemMap[category][itemID] = newItem;
            }
        }
    }
}


std::wstring Database::getParameterFromTag(std::wstring temp)
{
    size_t pos;
    const size_t nExist = std::wstring::npos;

    pos = temp.find('"');

    if ( pos != nExist)
    {
       temp.erase(0 , pos+1);
       pos = temp.find(L'"');

       if ( pos != nExist)
       {
            temp.erase(pos);
            return temp;
       }

       else
       {
           std::wcout << L"Fehler 1, getParameterFromTag()" << std::endl;
       }
    }

    else
    {
       std::wcout << L"Fehler 2, getParameterFromTag()" << std::endl;
    }

    return L"";

}

void Database::saveToFile()
{
    // TODO
}

