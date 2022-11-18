#include "file.h"
#include "test.h"
int main()
{
    std::string file, file1;
    int choice;
    bool programOn = true;
    while (programOn != false) {
        std::cout << "*******************************\n";
        std::cout << " 1 - Studento ivedimas\n";
        std::cout << " 2 - Studentai faile\n";
        std::cout << " 0 - Uzdaryti\n";
        std::cout << " Iveskite savo pasirinkima ir spauskite Enter: ";

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            ivedimas();
            break;
        case 2:
            std::cout << "Isveskite tekstinio(txt) failo pavadinima" << "\n";
            std::cin >> file;
            file1 = file + "-copy.txt";
            file = file + ".txt";
            eil_po_eil(file, file1);
            break;
        case 0:
            std::cout << "Darbas su programa baigtas.\n";
            programOn = false;
            break;
        default:
            std::cout << "Tokio pasirinkimo nera. \n";
            std::cout << "Bandykite dar karta.\n";
            std::cin >> choice;
            break;
        }

    }
    return 0;
}