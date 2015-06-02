#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <map>

#define TAGCATEGORY L"<category name="
#define TAGITEM     L"<item id="
#define TAGNAMEENG  L"<NameEng>"
#define TAGNAMEGER  L"<NameGer>"
#define TAGRECIPE   L"<recipe id="




class Database
{
public:
    Database();
    ~Database();
private:
    std::wstring filename;
    std::wstring getParameterFromTag(std::wstring temp);

    void loadFromFile();
    void saveToFile();

    //std::map <std::wstring, std::map> categoryMap;
};

#endif // DATABASE_H
