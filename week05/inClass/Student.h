#pragma once
#include "Person.h"
class Student : public Person {
private:
	char* university;
	int term;
public:
	Student();
	Student(const char*, int, const char*, int);
	Student(const Student&);
	Student& operator=(const Student&);
	~Student();

	const char* getUniversity() const;
	int getTerm() const;
	void move() const override {
		cout << "Student is running";
	}
	friend ostream& operator<<(ostream&, const Student&);
};
Student::Student() : Person() {
	//Person();
	this->university = nullptr;
	this->term = 0;
}

Student::Student(const char* name, int age, const char* university, int term) : Person(name, age) {
	this->university = new char[strlen(university) + 1];
	strcpy_s(this->university, strlen(university) + 1, university);
	this->term = term;
}

Student::Student(const Student& other) : Person(other) {
	this->university = new char[strlen(other.university) + 1];
	strcpy_s(this->university, strlen(other.university) + 1, other.university);
	this->term = other.term;
}

Student& Student::operator=(const Student& other) {
	if (this != &other) {
		Person::operator=(other);
		delete[] this->university;

		this->university = new char[strlen(other.university) + 1];
		strcpy_s(this->university, strlen(other.university) + 1, other.university);
		this->term = other.term;
	}
	return *this;
}

Student::~Student() {
	delete[] this->university;
}

const char* Student::getUniversity() const {
	return this->university;
}

int Student::getTerm() const {
	return this->term;
}

ostream& operator<<(ostream& output, const Student& student)
{
	output << "Name: " << student.getName() << endl;
	output << "Age: " << student.getAge() << endl;
	output << "University: " << student.university << endl;
	output << "Term: " << student.term << endl;
	return output;
}
