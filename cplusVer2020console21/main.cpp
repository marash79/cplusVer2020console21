
#include "classes.h"





int main()
{
    const int sz{ 9 };
    IElectronics* ware[sz];

 //  Генерируем склад
    for (int i = 0; i < 3; ++i) {
        ware[i] = new PowerBank((i + 1) * 100, "XiaoMi", "model" + std::to_string(i));
        ware[i + 3] = new Fridge((i+1) * 10, "Samsung", "Nofrost" + std::to_string(i));
        ware[i + 6] = new portablePlayer((i+1) * 100, (i + 1)* 200, "Apple", "Ipod"+ std::to_string(i), 100 + i * 25);
    }
 //выбираем тип товара для показа
    int choice{};
    do{
        std::cout << "\nPlease choose product : 1 - PowerBank, 2 - Refrigerators, 3 - Portable players, 0 to exit" << std::endl;
        int step{};
        std::cin >> choice;
        switch (choice)
        {
        case 0:
            break;
        case 1:
            step = 0;
            break;
        case 2:
            step = 3;
            break;
        case 3:
            step = 6;
            break;
        default:
            std::cout << "\nPlease choose product 1 to 3 or 0, to exit" << std::endl;
            break;
        }
        //показываем
        if (choice!=0)
        for (int i = 0; i < 3; ++i) {
            std::cout << '\n' << i << "->";
            ware[i + step]->showSpec();
        } 
    } while (choice);
    // удаляем выделенные ресурсы
    for (int i = 0; i < sz; ++i) 
        delete ware[i];
    return 0;
}