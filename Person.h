#ifndef PERSON_H
#define PERSON_H
#include <string>


class Person {
public:
    std::string name;
    int age;
    std::string nationality;

    Person();
    Person(const std::string& nm, int a, const std::string& n);
    Person(const Person& other);
    Person(Person&& other) noexcept;
    virtual ~Person() = default;

    Person& operator=(const Person& other) = default;
    Person& operator=(Person&& other) noexcept = default;

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] int getAge() const;
    [[nodiscard]] std::string getNationality() const;

    void setName(const std::string& nm);
    void setAge(int a);
    void setNationality(const std::string& n);

    virtual void displayInfo() const = 0;
    [[nodiscard]] virtual std::string getRole() const { return "Person"; }

    static void staticMethod();
    static void demonstrateStaticBinding();
};

#endif
