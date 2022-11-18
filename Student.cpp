#include "student.h"

Student::Student() {
    name = "null";
    lastname = "null";
    grades = { 0 };
    exam = 0;
}

Student::~Student() {
    name = "null";
    lastname = "null";
    grades = { 0 };
    exam = 0;
    exam = 0;
    average = 0;
    median = 0;
}
//Student(const Student& original_object) {
    //cout << "Kopijavimo konstruktorius" << endl;
//}
void Student::get(std::string str) {
    std::istringstream ss(str);
    std::string word;
    int i = 0;


    while (ss >> word)
    {
        gradesinstring.push_back(word);
    }
    for (const auto& elem : gradesinstring) {

        if (i == 0) {
            name = elem;
            gradesinstring.erase(gradesinstring.begin() + 0);
            i++;
        }
        if (i == 1) {
            lastname = elem;
            gradesinstring.erase(gradesinstring.begin() + 0);
            i++;
        }
    }
    grades.erase(grades.begin() + 0);
    std::transform(gradesinstring.begin(), gradesinstring.end(), std::back_inserter(grades),
        [&](std::string s) {
            return stoi(s);
        });
    exam = grades[grades.size() - 1];
    grades.resize(grades.size() - 1);
    gradesinstring.clear();
   /* ********************
   std::cout << "{";
    for (int a : grades) {

        std::cout << a << " ";
    }
    std::cout << "} \n";
    std::cout << grades.size() <<"\n";
    gradesinstring.clear();
    ***********************/
}


void Student::input() {
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    int grade = 0, i = 1; int check = 0;
    grades.clear();
    std::cout << "Iveskite studento varda \n";
    std::cin >> name;
    std::cout << "Iveskite studento pavarde \n";
    std::cin >> lastname;
    SetConsoleTextAttribute(color, 12);
    std::cout << "*****Noredami nutraukti pazymiu ivedima - iveskite didesni skaiciu uz 10*****" << std::endl;
    SetConsoleTextAttribute(color, 7);
    std::cout << "Iveskite studento namu darbu pazymius \n";
    while (grade < 11) {
        std::cout << i << "-as pazimys: \n";
        std::cin >> grade;
        if (grade <= 10 && grade >= 0) {
            i++;
            grades.push_back(grade);
        }
        if (grade < 0) {
            SetConsoleTextAttribute(color, 12);
            std::cout << "***KLAIDA*** Ivedete neigiama ivertinima \n";
            SetConsoleTextAttribute(color, 7);
            grade = 0;
        };
        if (grade > 10) {
            std::cout << "Namu darbu ivertinimu ivedimas baigtas \n";
        }
    };
    while (check < 1) {
        std::cout << "Iveskite studento egzamino ivetrtinima \n";
        std::cin >> exam;
        if (exam < 11 && exam > 0) {
            check = 1;
        }
    }
}
void Student::inputrand() {
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    int grade = 0, i = 1; int n = 0; int check = 0;
    grades.clear();
    std::cout << "Iveskite studento varda \n";
    std::cin >> name;
    std::cout << "Iveskite studento pavarde \n";
    std::cin >> lastname;
    std::cout << "Iveskite pazymiu kieki \n";
    std::cin >> n;
    while (i <= n) {
        grade = rand() % 10 + 1;
        std::cout << i << "-as pazimys: " << grade << std::endl;
        grades.push_back(grade);
        i++;
    };
    exam = rand() % 10 + 1;
    std::cout << "Egzaminas : " << exam << std::endl;
    countAverage();
    countMedian();
}
void Student::countAverage() {
    double gradeSum = 0;
    for (const auto& elem : grades) {
        gradeSum = gradeSum + elem;
    }
    average = (gradeSum + exam)/ (grades.size()+1);
}
void Student::countMedian()
{
    std::vector<int> gradesCopy;
    gradesCopy.push_back(exam);
    gradesCopy = grades;
    sort(gradesCopy.begin(), gradesCopy.end());
    if (gradesCopy.size() % 2 == 0)
        median = (gradesCopy[gradesCopy.size() / 2 - 1] + gradesCopy[gradesCopy.size() / 2]) / 2;
    else
        median = gradesCopy[gradesCopy.size() / 2];
}
void Student::print(int x) {
    a = x;
    
    if (a == 1)
    {
        std::cout << name << " " << lastname << " ";
        std::cout << average << "\n";
    }
    else if (a == 1)
    {
        std::cout << name << " " << lastname << " ";
        std::cout << median << "\n";
    }
}
void Student::printfile(int x) {
    a = x;
    double sk = 0.0;
    std::ostringstream str1, str2;
    str1 << average;
    str2 << median;
    gradesinstring.push_back(name);
    gradesinstring.push_back(lastname);
    if (a == 1)
    {
        std::string average1 = str1.str();
        gradesinstring.push_back(average1);
        for (std::string a : gradesinstring) {
            if (int(sk) % 23 != 22.0) std::cout << std::setw(20) << std::fixed << a;
            else std::cout << std::setw(20) << std::fixed << a << std::endl;
            sk++;
        }
        gradesinstring.resize(0);
        std::cout << "\n";
    }
    else if (a == 2)
    {
        std::string median1 = str2.str();
        gradesinstring.push_back(median1);
        for (std::string a : gradesinstring) {
            if (int(sk) % 23 != 22.0) std::cout << std::setw(20) << std::fixed << a;
            else std::cout << std::setw(20) << std::fixed << a << std::endl;
            sk++;
        }
        gradesinstring.resize(0);
        std::cout << "\n";
    }
    else if (a == 3)
    {
        std::string average1 = str1.str();
        std::string median1 = str2.str();
        gradesinstring.push_back(average1);
        gradesinstring.push_back(median1);
        for (std::string a : gradesinstring) {
            if (int(sk) % 23 != 22.0) std::cout << std::setw(20) << std::fixed << a;
            else std::cout << std::setw(20) << std::fixed << a << std::endl;
            sk++;
        }
        gradesinstring.resize(0);
        std::cout << "\n";
    }
}
