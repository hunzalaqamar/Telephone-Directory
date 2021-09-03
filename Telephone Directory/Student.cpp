	//this is the student cpp file which includes the class definations and function definations

	#include <iostream>              //including input output stream

	#include <string>                //including library string

	#include "Student.h"            //including student header file

	void displayMenu();                 //function prototype

	void logo();                        //function prototype

	using namespace std;           //using standard namespace

	Student::Student()             //accessing default constructor to initialize private data members
	{
		rollNo = -1;                 //initialized

		studentName[0] = '\0';    //initialized

		studentAddress[0] = '\0';  //initialized

		telephone[0] = '\0';       //initialized
	}

	void Student::setRollNo(long long int newId)     //accessing setRollNo function to update student's roll no to user need
	{
		rollNo = newId;                   //value updating
	}

	void Student::setName(char* newName)  //accessing setName function to update student's name to user need
	{
		int i;                                   //declaration of varibles

		for (i = 0;i < strlen(newName);i++)   //loop
		{
			studentName[i] = newName[i];         //value updating index by index
		}

		for (i = strlen(newName);i < 100;i++) //loop for clearing garbage from the remaining indexes of the student name array
		{
			studentName[i] = '\0';               //cleaning
		}
	}

	void Student::setAddress(char* newAddress) //accessing setAddress function to update student's Address to user need
	{
		int i;                                   //declaration of varibles

		for (i = 0;i < strlen(newAddress);i++)     //loop
		{
			studentAddress[i] = newAddress[i];        //value updating index by index
		}

		for (i = strlen(newAddress);i < 100;i++)   //loop for clearing garbage from the remaining indexes of the student Address array
		{
			studentAddress[i] = '\0';                //cleaning
		}
	}

	void Student::setTelephone(char* newTelephone)  //accessing setTelephone function to update student's Telephone to user need
	{
		int i;                                   //declaration of varibles

		for (i = 0;i < strlen(newTelephone);i++)  //loop
		{
			telephone[i] = newTelephone[i];          //value updating index by index
		}

		for (i = strlen(newTelephone);i < 100;i++) //loop for clearing garbage from the remaining indexes of the Telephone array
		{
			telephone[i] = '\0';                    //cleaning
		}
	}
	void telephoneDirectory::executeSwitch()          //function defination
	{
		int directorySize, choice, index = 0, indexAdjust = 0, temp, check = 0;            //declatation of variables

		bool indexIncrease = false, removeCheck = false;                                          //declaration of variables

		logo();														//calling logo function

		cout << "\n\nHow Many Student's Data You Want To Enter ?";		//display

		cout << "\n\n(Note:You Can Enter Data Of Maximum 100 Students And Minimum Of 1 Student)";     //display

		cout << "\n\nYour Choice : ";											//display

		cin >> directorySize;                                       //user input 

		if (directorySize > 0 && directorySize <= 100)		//condition to check if directory size in is'nt invalid
		{

			while (1)                                           //infinate while loop
			{
				displayMenu();                                  //calling displaymenu

				cin >> choice;                                  //user input

				switch (choice)                                 //switch
				{

				case 1:                                        //case 1
				{

					system("CLS");                            //clear screen

					if (check == 0)                        //if condition for normal student adding
					{
						if (index < directorySize)                //if condition to detect array size
						{
							studentArray[index].addStudent(directorySize, studentArray, indexIncrease, index);     //accessing array of objects with function

							displayMenu();                        //displaying menu

							if (indexIncrease == true)          //boolen variable user for incrementing
							{
								index++;                          //incrementing the indexing variable
							}

							break;                                //break
						}
						else                                      //else
						{
							cout << "\nDirectory Is Full Cannot Add Anymore Students\n";          //display

							system("PAUSE");                                                //screen catch

							break;                                           //break
						}
					}
					else if (check > 0)                  //else if condition for remove student checking
					{
						if (index < directorySize)                //if condition to detect array size
						{
							studentArray[index].addStudent(directorySize, studentArray, indexIncrease, index);     //accessing array of objects with function

							displayMenu();                        //displaying menu

							if (indexIncrease == true)              //boolean variable for index increamenting
							{
								check = 0;                          //check variable re-initialized

								index = temp;                      //copying temp variable value in index variable
							}

							break;                           //break;
						}
					}

					break;                                                 //breaking case
				}
				case 2:                                                   //case 2
				{
					system("CLS");                                            //clear screen

					studentArray[index].updateStudentData(directorySize, studentArray);   //accessing array of object with specified function

					displayMenu();                                           //display menu function

					break;                                                  //breaking swtich
				}
				case 3:                                                    //case 3
				{
					if (check == 0)                   //if condition to chec whether user has deleted any data or not
					{
						temp = index;                //copying index value to temp

						system("CLS");                                           //clear screen

						studentArray[index].deleteStudentData(directorySize, studentArray, indexAdjust, removeCheck);   //accessing array of object with specified function

						displayMenu();											//display menu function

						if (removeCheck == true)                              //if condition to check whether the student is deleted or not
						{
							index = indexAdjust;							                   //decrementing index variable

							check++;                                           //check variable increment if student is deleted
						}

						break;
					}
					else
					{
						system("CLS");                                 //clear screen

						cout << "\nYou Have Deleted A Student's Data Before, Please Add A New Student's Data Before Deleting Any other Student's Data.\n";			//display

						system("PAUSE");			//catch screen
					}

					break;                                               //breaking switch
				}
				case 4:                                                 //case 4
				{
					system("CLS");                                           //clear screen

					studentArray[index].searchStudent(directorySize, studentArray);   //accessing array of object with specified function

					cout << "\n";                                //display

					system("PAUSE");                           //screen catch

					displayMenu();                                        //display menu function

					break;                                    //breaking switch
				}
				case 5:                                   //case 5
				{
					system("CLS");                                        //clear screen

					studentArray[index].displayDirectory(directorySize, studentArray);    //accessing array of object with specified function

					cout << "\n";                                        //display

					system("PAUSE");                                    //screen catch

					displayMenu();                                      //display menu function call

					break;                                              //breaking switch
				}
				case 6:
				{
					cout << "\n\nExiting Now\n";             //display

					system("PAUSE");                        //screen catch

					exit(0);                                //exiting completely
				}
				default:
				{
					cout << "Invalid Choice Try Again\n";          //display

					system("PAUSE");                             //screen catch

					displayMenu();                               //displaying menu

					break;                                       //breaking switch
				}
				break;

				}
			}
		}
		else
		{

			cout << "\nInvalid Number Try Again !!\n";

			system("PAUSE");

			executeSwitch();

		}
	}

	void Student::addStudent(int directorySize, Student* studentArray, bool &indexIncrease, int &index)                 //function to add student
	{
		long long int tempRollNo;           //declaration of variables

		int match = 0, i = 0, saveChoice = 0;                 //declaration of variables

		char tempStudentName[100], tempStudentAddress[100], tempTelephone[100];

		cout << "\nEnter Student's Roll Number (Digits Only And Should Not Be Greater Than 10 digits) : ";  //display

		cin >> tempRollNo;                    //getting user input for roll no

		for (i = 0;i < directorySize;i++)           //loop
		{
			if (studentArray[i].rollNo == tempRollNo)   //condition to check existing student
			{
				cout << "Student Already Exists TryAgain \n";    //display

				system("PAUSE");              //catch window

				indexIncrease = false;        //index increasing variable

				match++;                       //counter

			}
		}

		if (match == 0)                           //condition to execute when student is new
		{
			cout << "\nEnter Student's Name : ";   //display

			cin.ignore();                         //cin.ignore function to stop rejection of getline

			cin.getline(tempStudentName, 100);        //geting user input for name

			cout << "\nEnter Student's Address : ";   //display

			cin.getline(tempStudentAddress, 100);   //getting user input for address

			cout << "\nEnter Student's Telephone Number : ";               //display

			cin.getline(tempTelephone, 100);     //getting user input for telephone

			cout << "\nDo you Want to Save Ths Information (Press 1 For Yes And Press 2 For No)";   //display

			cout << "\n\nYour Choice : ";                            //display

			cin >> saveChoice;                                //variable to get save choice from user

			if (saveChoice == 1)                             //if conditipn to save 
			{
				studentArray[index].rollNo = tempRollNo;           //condition if student is not already in so it would made him as new one

				for (i = 0;i < 100;i++)
				{

					studentArray[index].studentName[i] = tempStudentName[i];                //copying name to specific student's object

					studentArray[index].studentAddress[i] = tempStudentAddress[i];         //copying address to specific student's object

					studentArray[index].telephone[i] = tempTelephone[i];               //copying telephone to specific student's object
				}

				cout << "\n\nStudent Added Successfully\n";  //display

				system("PAUSE");                      //catching screen

				indexIncrease = true;             //index increasing variable sending value as boolean
			}

			else                           //else
			{
				cout << "\nStudent's Data Not Saved\n";             //display

				system("PAUSE");                               //catch window

				indexIncrease = false;                           //boolen variable to false
			}
		}
	}
	void Student::deleteStudentData(int directorySize, Student* studentArray, int &indexAdjust, bool &removeCheck)  //function to remove student
	{
		int choice, flag = 0, i;  //declaration of variables

		long long int getRoll;  //declaration of variables

		cout << "\n\nEnter Roll No Of Student To Delete Its Data : ";  //display

		cin >> getRoll;                                     //getting user input

		for (i = 0;i < directorySize;i++)               //loop
		{

			if (studentArray[i].rollNo == getRoll)        //condition to search student
			{
				flag++;                //counter

				indexAdjust = i;                     //copying value of i at which student is found into passed by reference vatiable indexAdjust

				cout << "\n\nStudent Found!";             //display

				cout << "\n\nRoll Number Of Student Is : " << studentArray[i].rollNo;   //display

				cout << "\n\nName Of Student Is : " << studentArray[i].studentName;    //display

				cout << "\n\nAddress Of The Student Is : " << studentArray[i].studentAddress;  //display

				cout << "\n\nTelephone Number Of Student Is : " << studentArray[i].telephone;   //display

				cout << "\n\nAre You Sure You Want to Delete Data Of This Student? : Press 1 For Yes And 2 For No";   //display

				cout << "\n\nYour Choice : ";          //display

				cin >> choice;                       //getting user input

				if (choice == 1)                //choice check
				{
					studentArray[i].rollNo = -1;      //set that students data to Null

					studentArray[i].studentName[0] = '\0';  //set that students data to Null

					studentArray[i].studentAddress[0] = '\0';  //set that students data to Null

					studentArray[i].telephone[0] = '\0';   //set that students data to Null

					cout << "\n\nStudent's Data Deleted Successfully\n";  //display

					removeCheck = true;         //boolean variable

					system("PAUSE");          //screen catch

					break;                  //breaking switch
				}

				else                    //else
				{
					cout << "\n\nStudent's Data Not Deleted\n";			//display

					system("PAUSE");                               //catch screen

					break;									//break;
				}
			}
		}
		if (flag == 0)						//condition to show if student doesn't found
		{
			cout << "\n\nStudent Not Found!\n";   //display

			system("Pause");            //screen catch

			removeCheck = false;            //boolean variable
		}

	}
	void Student::updateStudentData(int directorySize, Student* studentArray) //function to update student's data
	{
		int updateChoice, getRoll, flag = 0, i, j, matchId = 0;                                     //declaration of variables

		long long int newId;                                                    //declaration of variables

		char newName[100], newAddress[100], newTelephone[100];           //declaration of variables

		cout << "\n\nEnter Roll No Of Student To Update Its Data : ";  //display

		cin >> getRoll;                             //user input

		for (i = 0;i < directorySize;i++)           //loop
		{

			if (studentArray[i].rollNo == getRoll)   //condition to find specific student
			{
				flag++;                //counter

				cout << "\n\nStudent Found!";       //display

				cout << "\n\nRoll Number Of Student Is : " << studentArray[i].rollNo;   //display

				cout << "\n\nName Of Student Is : " << studentArray[i].studentName;    //display

				cout << "\n\nAddress Of The Student Is : " << studentArray[i].studentAddress;  //display

				cout << "\n\nTelephone Number Of Student Is : " << studentArray[i].telephone << "\n";   //display

				system("PAUSE");                                               //catch screen

				cout << "\n\nWhich Field You Want to Update";                    //display

				cout << "\n\n1:Do You Want To Update Roll No Of The Student ?";  //display

				cout << "\n\n2:Do You Want To Update Name Of The Student ?";    //display

				cout << "\n\n3:Do You Want To Update Address Of The Student ?"; //display

				cout << "\n\n4:Do You Want To Update Telephone Number Of The Student ?"; //display

				cout << "\n\nYour Choice : ";                                         //display

				cin >> updateChoice;                                                //user input

				switch (updateChoice)                                      //switch
				{
				case 1:                                           //case 1
				{
					cout << "\n\nEnter New Id For This Student : ";  //display

					cin >> newId;                               //user input for new id

					for (j = 0;j < directorySize;j++)          //loop
					{
						if (studentArray[j].rollNo == newId)     //if condition to search if the new entered id exist's before or not
						{
							cout << "\nStudent Roll No Already Exists Try Again.";      //display

							system("PAUSE");                       //catch screen

							matchId++;                           //matchId variable as check
						}
					}

					if (matchId == 0)
					{
						studentArray[i].setRollNo(newId);              //accessing array of objects with specific data updating function

						cout << "\n\nStudent's Id Changed Successfully\n";       //display

						system("PAUSE");                                       //catch screen
					}

					break;                        //breaking switch
				}

				case 2:                           //case 2
				{
					cout << "\n\nEnter New Name For This Student : ";             //display

					cin.ignore();                                           //to stop rejection of getline

					cin.getline(newName, 100);                              //user input for new name

					studentArray[i].setName(newName);                    //accessing array of objects with specific data updating function

					cout << "\n\nStudent's Name Changed Successfully\n";   //display

					system("PAUSE");                                  //catch screen

					break;                                  //breaking switch
				}

				case 3:                                      //case 3 
				{
					cout << "\n\nEnter New Address Of This Student : ";      //display

					cin.ignore();                                         //to stop rejection of getline

					cin.getline(newAddress, 100);                         //user input for new address

					studentArray[i].setAddress(newAddress);             //accessing array of objects with specific data updating function

					cout << "\n\nStudent's Address Changed Successfully\n";     //display

					system("PAUSE");                                //catch screen

					break;                        //breaking switch
				}

				case 4:                    //case 4
				{
					cout << "\n\nEnter New Telephone Number For This Student : ";        //display

					cin.ignore();                                       //to stop rejection of getline

					cin.getline(newTelephone, 100);                     //user input of new telephone number

					studentArray[i].setTelephone(newTelephone);        //accessing array of objects with specific data updating function

					cout << "\n\nStudent's Telephone Number Changed Successfully\n";          //display

					system("PAUSE");                                   //catch screen

					break;                                            //breaking switch
				}

				default:                                 //default
				{
					cout << "\n\nInvalid Choice Try Again\n";  //display

					system("PAUSE");                          //screen catch

					break;                                 //break
				}

				}
			}
		}

		if (flag == 0)                     //condition to check if student is founded or not
		{
			cout << "\n\nStudent Not Found!\n";       //display

			system("PAUSE");                         //catch screen
		}


	}
	void Student::searchStudent(int directorySize, Student* studentArray)    //function to search students data
	{

		int flag = 0, i;            //declaring variables

		long long int getRoll;      //declaring variables

		cout << "\n\nEnter Roll No Of Student To Search : ";   //display

		cin >> getRoll;                             //getting user input

		for (i = 0;i < directorySize;i++)           //loop
		{

			if (studentArray[i].rollNo == getRoll)  //condition to search student
			{
				cout << "\n\nStudent Found!";  //display

				cout << "\n\nRoll Number Of Student Is : " << studentArray[i].rollNo;   //display

				cout << "\n\nName Of Student Is : " << studentArray[i].studentName;   //display

				cout << "\n\nAddress Of The Student Is : " << studentArray[i].studentAddress;  //display

				cout << "\n\nTelephone Number Of Student Is : " << studentArray[i].telephone;  //display

				flag++;          //counter

				break;    //breaking switch
			}
		}

		if (flag == 0)   //condition to check if student is not their
		{
			cout << "\n\nStudent Not Found!\n";   //display

			system("Pause");                     //screen catch
		}

	}
	void Student::displayDirectory(int directorySize, Student* studentArray)   //function to display all students directory
	{
		system("CLS");                //clear screen

		for (int i = 0;i < directorySize;i++)  //loop
		{
			if (studentArray[i].rollNo != -1)
			{
				cout << "               \nStudent's Name Is : " << studentArray[i].studentName;   //display
				cout << "               \nStudent's Roll Number Is : " << studentArray[i].rollNo; //display
				cout << "               \nStudent's Address Is  : " << studentArray[i].studentAddress; //display
				cout << "               \nStudent's Telephone Number Is : " << studentArray[i].telephone; //display
				cout << "\n\n";    //display
			}
			else
			{
				continue;
			}
		}
	}

	void logo()
	{
		system("CLS");

		cout << " \n**************************************************************************";
		cout << " \n                  Telephone Directory For Students				         ";
		cout << " \n**************************************************************************";
	}

	void displayMenu()
	{
		system("CLS");                             //clear screen

		cout << "\n*****************************************************";     //display
		cout << "\n              Telephone Directory                    ";     //display
		cout << "\n*****************************************************";     //display
		cout << "\n                    Main Menu                        ";     //display
		cout << "\n*****************************************************";     //display
		cout << "\n1: Insert A Student's Data ";                               //display
		cout << "\n2: Update A Student's Data ";                               //display  
		cout << "\n3: Delete A Student's Data ";                               //display
		cout << "\n4: Search A Student ";                                      //display
		cout << "\n5: Display All The Directory ";                             //display
		cout << "\n6: Exit ";                                                 //display
		cout << "\nYour Choice: ";                                            //display
	}
