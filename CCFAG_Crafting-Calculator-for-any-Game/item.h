#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>

class Item
{
public:
    Item(std::wstring itemID);
    Item();
    ~Item();

    void addRecipeItem(int quantity, std::wstring itemID);

    void setID(std::wstring itemID);
    void setNameEng(std::wstring nameEng);
    void setNameGer(std::wstring nameGer);

    std::wstring getID(void);
    std::wstring getNameEng(void);
    std::wstring getNameGer(void);

    void print(void);

    struct recipe{
                    std::wstring itemID;
                    int quantity;
                  };

    std::vector <recipe*> recipeVector;

private:
    std::wstring itemID;
    std::wstring nameEng;
    std::wstring nameGer;








};

#endif // ITEM_H
