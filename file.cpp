#include "file.h"
void eil_po_eil(std::string read_vardas, std::string write_vardas) {
    std::vector<std::string> splited;
    std::string eil;
    int i= 0, h=0;
    int choice;
    bool programOn = true;
    //----------------------------------------------------------------------
    std::ifstream open_f(read_vardas);
    while (open_f) {
        if (!open_f.eof()) {
            std::getline(open_f, eil);
            splited.push_back(eil);
            h++;
        }
        else break;
    }
    open_f.close();
    std::cout << "eiluciu: " << h << std::endl;

    Student* kip;
    kip = new Student[h];
    std::ofstream out_f(write_vardas);
    for (std::string a : splited) {

        out_f << a << "\n";
        kip[i].get(a);
        i++;

    }
    out_f.close();
    splited.resize(0);
    for (i = 0; i < h; i++)
    {
        kip[i].countAverage();
        kip[i].countMedian();
    }
    //----------------------------------------------------------------------
    while (programOn != false) {
        std::cout << "*******************************\n";
        std::cout << " 1 - Studentu vidurkis\n";
        std::cout << " 2 - Studentu mediana\n";
        std::cout << " 3 - Studentu vidurkis ir mediana\n";
        std::cout << " 0 - Uzdaryti\n";
        std::cout << " Iveskite savo pasirinkima ir spauskite Enter: ";

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            for (i = 0; i < h; i++)
            {
                kip[i].printfile(1);
            }
            break;
        case 2:
            for (i = 0; i < h; i++)
            {
                kip[i].printfile(2);
            }
            break;
        case 3:
            for (i = 0; i < h; i++)
            {
                kip[i].printfile(3);
            }
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
    //----------------------------------------------------------------------
    delete[] kip;

}