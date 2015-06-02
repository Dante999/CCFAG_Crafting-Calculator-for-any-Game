#include "database.h"
#include "item.h"

#include <iostream>
#include <fstream>
#include <QString>

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
    Item *currentItem;

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
                category = getParameterFromTag(lineBuffer);
            }

            else if( lineBuffer.find(TAGITEM) != nExist)
            {
                itemID = getParameterFromTag(lineBuffer);

                Item *newItem = new Item(itemID);

                currentItem = newItem;
                itemMap[category][itemID] = newItem;

            }

            else if( lineBuffer.find(TAGNAMEENG) != nExist)
            {
                std::wstring nameEng = getValueFromTag(lineBuffer);

                currentItem->setNameEng(nameEng);
            }

            else if( lineBuffer.find(TAGNAMEGER) != nExist)
            {
                std::wstring nameGer = getValueFromTag(lineBuffer);

                currentItem->setNameGer(nameGer);
            }

            else if( lineBuffer.find(TAGRECIPE) != nExist)
            {
                std::wstring recipeItemID = getParameterFromTag(lineBuffer);
                QString  recipeItemQuantity = QString::fromStdWString(getValueFromTag(lineBuffer));

                currentItem->addRecipeItem(recipeItemQuantity.toInt(), recipeItemID);
            }
        }
    }

    std::wcout << "Fertig" << std::endl;
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

std::wstring Database::getValueFromTag(std::wstring temp)
{
    size_t pos;
    const size_t nExist = std::wstring::npos;

    pos = temp.find('>');

    if( pos != nExist)
    {
        temp.erase(0, pos+1);
    }

    pos = temp.find('<');

    if( pos != nExist)
    {
        temp.erase(pos);
    }

    return temp;
}

void Database::saveToFile()
{
    // TODO
}

