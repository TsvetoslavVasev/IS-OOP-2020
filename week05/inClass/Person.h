#pragma once
#include<iostream>
#include<cstring>

using namespace std;
class Person {
private:
	char* name;
	int age;

public:
	Person();
	Person(const char*, int);
	Person(const Person& other);
	Person& operator=(const Person&);
	~Person();

	virtual void move() const {
		cout << "Person is walking";
	}

	const char* getName()const;
	int getAge() const;

	friend ostream& operator<<(std::ostream&, const Person&);
};

Person::Person() {
	this->name = nullptr;
	this->age = 0;
}

Person::Person(const char* name, int age) {
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->age = age;
}

Person::Person(const Person& other) {
	this->name = new char[strlen(other.name) + 1];
	strcpy_s(this->name, strlen(other.name) + 1, other.name);
	this->age = other.age;
}

Person& Person::operator=(const Person& other) {
	if (this != &other) {
		delete[] this->name;
		this->name = new char[strlen(other.name) + 1];
		strcpy_s(this->name, strlen(other.name) + 1, name);
		this->age = other.age;
	}
	return *this;
}

Person::~Person() {
	delete[] this->name;
}

const char* Person::getName() const {
	return this->name;
}

int Person::getAge() const {
	return this->age;
}


ostream& operator<<(std::ostream& output, const Person& person)
{
	output << "Name: " << person.name << endl;
	output << "Age: " << person.age << endl;
	return output;
}
