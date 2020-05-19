#include <iostream>
#include <string>

using namespace std;

enum GENDER {
    U, M, F
};

class Human {
    int age;
    GENDER gender;
    string name;
public:
    Human(string name, int age, GENDER gender) : age(age) {
        this->gender = gender;
        this->name = name;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        this->age = age;
    }

    string getName() const {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    GENDER getGender() const {
        return gender;
    }

    void setGender(GENDER gender) {
        this->gender = gender;
    }

    void getAll() {
        cout << name << " " << age << " " << gender << " ";
    }
};

class Student : public Human {
    std::string numberOfZachetka;
public:
    Student(string name, int age, GENDER gender, const std::string &numberOfZachetka) : Human(name, age, gender) {
        this->numberOfZachetka = numberOfZachetka;
    }

    const std::string &getNumberOfZachetka() const {
        return numberOfZachetka;
    }

    void setNumberOfZachetka(const std::string &numberOfZachetka) {
        this->numberOfZachetka = numberOfZachetka;
    }
};

class BadStudent: public Student {
};

class GoodStudent: public Student {
};

class Specialist: public BadStudent, GoodStudent {

};

class Professor: public Human {
    int salary;
public:
    Professor(string name, int age, GENDER gender, int salary) : Human(name, age, gender) {
        this->salary = salary;
    }

    int getSalary() const {
        return salary;
    }

    void setSalary(int salary) {
        this->salary = salary;
    }
};

int main() {
    Human vasya("vasya",24, GENDER::M);
    Student olya( "olya",25, GENDER::F, "345678907654");
    Professor kolya("kolya",34, GENDER::M, 30000);

    vasya.getAll();
    cout << endl;

    olya.getAll();
    std::cout << olya.getNumberOfZachetka() << endl;
    olya.setNumberOfZachetka("000000000001");
    std::cout << olya.getNumberOfZachetka() << endl;

    kolya.getAll();
    cout << kolya.getSalary() << endl;

    return 0;
}