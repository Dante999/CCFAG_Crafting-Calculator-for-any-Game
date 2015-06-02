#include "item.h"
#include <string>
#include <iostream>


Item::Item()
{

}

Item::Item(std::wstring itemID)
{
    this->itemID = itemID;
}

Item::~Item()
{

}

/** Getters **/

std::wstring Item::getID(void)
{
    return this->itemID;
}

std::wstring Item::getNameEng(void)
{
    return this->nameEng;
}

std::wstring Item::getNameGer(void)
{
    return this->nameGer;
}


/** Setters **/


void Item::setID(std::wstring itemID)
{
    this->itemID = itemID;
}

void Item::setNameEng(std::wstring nameEng)
{
    this->nameEng = nameEng;
}

void Item::setNameGer(std::wstring nameGer)
{
    this->nameGer = nameGer;
}

void Item::addRecipeItem(int quantity, std::wstring itemID)
{
    recipe *newRecipeItem = new recipe;

    newRecipeItem->itemID = itemID;
    newRecipeItem->quantity = quantity;

    this->recipeVector.push_back(newRecipeItem);
}

void Item::print(void)
{
    unsigned int i;

    std::wcout << L"----- ItemObjekt -----" << std::endl;
    std::wcout << L"ID: |"                   << this->itemID  << L"|" << std::endl;
    std::wcout << L"NameEng: |"              << this->nameEng << L"|" << std::endl;
    std::wcout << L"NameGer: |"              << this->nameGer << L"|" << std::endl;

    for(i=0; i<recipeVector.size(); i++)
    {
        std::wcout << L"Recipe: |" << recipeVector[i]->quantity << L"|" << L" x ";
        std::wcout << L"|" << recipeVector[i]->itemID << L"|" << std::endl;
    }

    std::wcout << L"----------------------" << std::endl;
}

