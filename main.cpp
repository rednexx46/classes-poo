#include <iostream>

using std::string;

class AbstractEmployee { // makes obligatory use askForPromotion
    virtual void askForPromotion() = 0;
};

class Employee : AbstractEmployee { // private by default
private:
    string company;
    int age;
protected:
    string name;
public:
    void setName(string name) {
        this->name = name;
    }

    string getName() {
        return this->name;
    }

    void setCompany(string company) {
        this->company = company;
    }

    string getCompany() {
        return this->company;
    }

    void setAge(int age) {
        if (age >= 18)
            this->age = age;
    }

    int getAge() {
        return this->age;
    }

    void introduceYourself() {
        std::cout << "Name - " << name << std::endl;
        std::cout << "Company - " << company << std::endl;
        std::cout << "Age - " << age << std::endl;
    }

    void askForPromotion() {
        if (this->age > 30)
            std::cout << this->name << " got Promoted!" << std::endl;
        else
            std::cout << this->name << ", sorry NO Promotion for you!" << std::endl;
    }

    virtual void work() {
        std::cout << this->name << " is checking email, task backlog, perfoming tasks..." << std::endl;
    }

    // constructor already exists by default (if not created, if created the constructor changes to that one)
    Employee(string name, string company, int age) {
        this->name = name;
        this->company = company;
        this->age = age;
    }
};

class Developer : public Employee {
public:
    void setFavProgrammingLanguage(string programmingLanguage) {
        this->favProgrammingLanguage = programmingLanguage;
    }

    string getFavProgrammingLanguage() {
        return this->favProgrammingLanguage;
    }

    Developer(string name, string company, int age, string favProgrammingLanguage) : Employee(name, company, age) {
        this->favProgrammingLanguage = favProgrammingLanguage;
    }

    void fixBug() {
        std::cout << name << " fixed BUG using " << getFavProgrammingLanguage() << std::endl;
    }

    void work() {
        std::cout << this->name << " is writing " << this->favProgrammingLanguage << " code" << std::endl;
    }

private:
    string favProgrammingLanguage;

};

class Teacher : public Employee {
private:
    string subject;
public:
    void setSubject(string subject) {
        this->subject = subject;
    }

    string getSubject() {
        return this->subject;
    }

    void prepareLesson() {
        std::cout << name << " is preparing " << this->subject << " lesson" << std::endl;
    }

    Teacher(string name, string company, int age, string subject) : Employee(name, company, age) {
        this->subject = subject;
    }

    void work() {
        std::cout << this->name << " is teaching " << this->subject << std::endl;
    }

};

int main() {

    /*Employee employee01 = Employee("Jose Xavier", "OneSource", 20);
    employee01.name = "Jose Xavier";
    employee01.company = "OneSource";
    employee01.age = 20;
    employee01.introduceYourself();
    employee01.askForPromotion();*/

    /*Employee employee02 = Employee("Daniela Maria", "Amazon", 32);
    employee02.name = "Daniela Maria";
    employee02.company = "Amazon";
    employee02.age = 26;
    employee02.introduceYourself();
    employee02.askForPromotion();*/

    //employee01.setAge(16);
    //std::cout << employee01.getName() << " is " << employee01.getAge() << " years old." << std::endl;

    Developer d = Developer("Pedro Ramos", "OneSource", 30, "C++");
    /*d.fixBug();
    d.fixBug();
    d.fixBug();
    d.askForPromotion();*/

    Teacher t = Teacher("JOAO DURAES", "IZEK", 37, "POO");
    //t.prepareLesson();
    //t.askForPromotion();

    /*d.work();
    t.work();*/

    // The most common use of polymorphism is when a
    // parent class reference is used to refer a child class object

    Employee *e01 = &d;
    Employee *e02 = &t;

    e01->work();
    e02->work();

}
