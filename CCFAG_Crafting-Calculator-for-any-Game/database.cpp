#include "database.h"
#include "item.h"

#include <iostream>
#include <fstream>
#include <QString>
#include <map>

Database::Database()
{
    this->filename = L"items.xml";

    loadFromFile();
    saveToFile();
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

            if( lineBuffer.find(TAG_START_CATEGORY) != nExist)
            {
                category = getParameterFromTag(lineBuffer);

                typeItemMap *newItemMap = new typeItemMap;
                this->currentItemMap = newItemMap;

                this->categoryMap[category] = this->currentItemMap;
            }

            else if( lineBuffer.find(TAG_START_ITEM) != nExist)
            {
                itemID = getParameterFromTag(lineBuffer);

                Item *newItem = new Item(itemID);
                this->currentItem = newItem;

                (*currentItemMap)[itemID] = this->currentItem;
            }

            else if( lineBuffer.find(TAG_START_NAMEENG) != nExist)
            {
                std::wstring nameEng = getValueFromTag(lineBuffer);

                currentItem->setNameEng(nameEng);
            }

            else if( lineBuffer.find(TAG_START_NAMEGER) != nExist)
            {
                std::wstring nameGer = getValueFromTag(lineBuffer);

                currentItem->setNameGer(nameGer);
            }

            else if( lineBuffer.find(TAG_START_RECIPE) != nExist)
            {
                std::wstring recipeItemID = getParameterFromTag(lineBuffer);
                QString  recipeItemQuantity = QString::fromStdWString(getValueFromTag(lineBuffer));

                currentItem->addRecipeItem(recipeItemQuantity.toInt(), recipeItemID);
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
    std::wofstream databaseFile;
    typeCategoryMap::iterator it1;
    typeItemMap::iterator it2;

    databaseFile.open("items.xml", std::ios::trunc);

    for(it1 = categoryMap.begin(); it1 != categoryMap.end(); it1++)
    {
        databaseFile << TAG_START_CATEGORY << L"\"" << it1->first << L"\"" << L">" << std::endl;
        databaseFile << std::endl;

        for(it2 = it1->second->begin(); it2 != it1->second->end(); it2++)
        {
            this->currentItem = it2->second;

            databaseFile << TAB << TAG_START_ITEM;
            databaseFile << L"\"" << this->currentItem->getID() << L"\"";
            databaseFile << L">" << std::endl;

            databaseFile << TAB << TAB;
            databaseFile << TAG_START_NAMEENG;
            databaseFile << this->currentItem->getNameEng();
            databaseFile << TAG_END_NAMEENG << std::endl;

            databaseFile << TAB << TAB;
            databaseFile << TAG_START_NAMEGER;
            databaseFile << this->currentItem->getNameGer();
            databaseFile << TAG_END_NAMEGER << std::endl;

            size_t i;

            for(i=0; i<this->currentItem->recipeVector.size(); i++)
            {
                databaseFile << TAB << TAB;
                databaseFile << TAG_START_RECIPE;
                databaseFile << L"\"" << this->currentItem->recipeVector[i]->itemID << L"\"";
                databaseFile << L">";
                databaseFile << this->currentItem->recipeVector[i]->quantity;
                databaseFile << TAG_END_RECIPE << std::endl;
            }


            databaseFile << TAB;
            databaseFile << TAG_END_ITEM << std::endl << std::endl;
        }

        databaseFile << TAG_END_CATEGORY << std::endl;
        databaseFile << std::endl;

    }


    databaseFile.close();


}

