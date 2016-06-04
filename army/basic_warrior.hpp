#ifndef __BASIC_WARRIOR_HPP__
#define __BASIC_WARRIOR_HPP__

class BasicWarrior
{
protected:
	char* name;
	int skill;
	int age;
	double salary;

public:
	BasicWarrior();
	BasicWarrior(const char*, int, int, double);
	~BasicWarrior();

	const char* getName() const;
	void setName(const char*);

	int getSkill() const;
	void setSkill(int);
	
	int getAge() const;
	void setAge(int);

	double getSalary() const;
	void setSalary(double);

protected:
	BasicWarrior(const BasicWarrior&);
	BasicWarrior& operator=(const BasicWarrior&);
};

#endif
