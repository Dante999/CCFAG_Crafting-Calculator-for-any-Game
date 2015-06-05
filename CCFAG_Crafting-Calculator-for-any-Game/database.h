#ifndef DATABASE_H
#define DATABASE_H

#include "item.h"

#include <string>
#include <map>

#define TAG_START_CATEGORY L"<category name="
#define TAG_START_ITEM     L"<item id="
#define TAG_START_NAMEENG  L"<NameEng>"
#define TAG_START_NAMEGER  L"<NameGer>"
#define TAG_START_RECIPE   L"<recipe id="

#define TAG_END_CATEGORY L"</category>"
#define TAG_END_ITEM     L"</item id>"
#define TAG_END_NAMEENG  L"</NameEng>"
#define TAG_END_NAMEGER  L"</NameGer>"
#define TAG_END_RECIPE   L"</recipe>"

#define TAB L"    "

typedef std::map <std::wstring, Item*> typeItemMap;
typedef std::map <std::wstring, typeItemMap*> typeCategoryMap;


class Database
{
public:
    Database();
    Database(std::wstring filename);
    ~Database();



    typeCategoryMap categoryMap;
    typeItemMap *currentItemMap;

    typeCategoryMap::iterator itCategory;
    typeItemMap::iterator itItem;

private:
    std::string filename;
    std::wstring getParameterFromTag(std::wstring temp);
    std::wstring getValueFromTag(std::wstring temp);

    void loadFromFile();
    void saveToFile();

    Item *currentItem;
};

#endif // DATABASE_H
