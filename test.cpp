#include "test.h"
void ivedimas() {
    int choice;
    int n, i = 0;
    bool programOn = true;
    //--------------------------------------------------------------------
    std::cout << "Studentu skaicius: ";
    std::cin >> n;
    Student* s;
    s = new Student[n];
    //-------------------------------------------------------------------
    while (programOn != false) {
        std::cout << "*******************************\n";
        std::cout << " 1 - Ivesti studenta\n";
        std::cout << " 2 - Ivesti studenta su atstiktiniais ivertinimais\n";
        std::cout << " 3 - Studentu vidurkis\n";
        std::cout << " 4 - Studentu mediana\n";
        std::cout << " 5 - Studentu vidurkis ir mediana\n";
        std::cout << " 0 - Uzdaryti\n";
        std::cout << " Iveskite savo pasirinkima ir spauskite Enter: ";

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            if (i < n) {
                s[i].input();
                i++;
            }
            else i = 0;
            break;
        case 2:
            if (i < n) {
                s[i].inputrand();
                i++;
            }
            else i = 0;
            break;
        case 3:
            for (i = 0; i < n; i++)
            {
                s[i].printfile(1);
            }
            break;
        case 4:
            for (i = 0; i < n; i++)
            {
                s[i].printfile(2);
            }
            break;
        case 5:
            for (i = 0; i < n; i++)
            {
                s[i].printfile(3);
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
}