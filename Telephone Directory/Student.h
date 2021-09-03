	//this is the student header file which includes all the declarations including class declaration and function declarations

	class Student                                      //class of name Student
	{
	private:                                          //private section cannot be accessed from outside class

		long long int rollNo;                                   //rollNo of student

		char studentName[100];                         //student name array

		char studentAddress[100];                     //students address

		char telephone[100];                         //students telephone

	public:                                        //public section can be accessed from outside the class

		Student();                                 //default constructor

		void setRollNo(long long int newId);           //setter

		void setName(char* newName);               //setter

		void setAddress(char* newAddress);         //setter

		void setTelephone(char* newTelephone);     //setter

		void addStudent(int directorySize, Student* studentArray, bool &indexIncrease, int &index);                        //function to add student's data

		void updateStudentData(int directorySize, Student* studentArray);  //function to update student's data

		void deleteStudentData(int directorySize, Student* studentArray, int &indexAdjust, bool &removeCheck);    //function to remove any student's data

		void searchStudent(int directorySize, Student* studentArray);       //function to search student's data

		void displayDirectory(int directorySize, Student* studentArray);    //function to display all the data stored 
	};

	class telephoneDirectory            //class 2
	{
	private:                         //private attributes

		Student studentArray[100];         //array of objects

	public:               //public attributes

		void executeSwitch();       //function prototype
	};