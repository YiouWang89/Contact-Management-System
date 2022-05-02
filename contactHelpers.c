//==============================================
// Name:           Yiou(Anna) Wang
// Student Number: 151558194
// Email:          ywang811@myseneca.ca
// Section:        NGG
// Date:           2020.7.22
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        contents below...                        |
// +-------------------------------------------------+

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "contacts.h"
#include "contactHelpers.h"

#define MAXCONTACTS 5


//--------------------------------
// Function Definitions
//--------------------------------

// Clear the standard input buffer
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt function definition goes here:
int getInt(void)
{
	int a;
	char i;
	scanf("%d%c", &a, &i);

	while (i != '\n')
	{
		clearKeyboard();
		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		scanf("%d%c", &a, &i);
	}
	return a;
}

// getIntInRange function definition goes here:
int getIntInRange(int min, int max)
{
	int a;
	a = getInt();
	while (a < min || a > max)
	{
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		a = getInt();
	}
	return a;
}

// yes function definition goes here:
int yes(void)
{
	int a = 0;
	char yesNo, i;
	scanf("%c%c", &yesNo, &i);

	while (i != '\n')
	{
		clearKeyboard();
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		scanf("%c%c", &yesNo, &i);
	}

	while (yesNo != 'y' && yesNo != 'Y' && yesNo != 'n' && yesNo != 'N')
	{
		clearKeyboard();
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		scanf("%c%c", &yesNo, &i);
	}

	if (yesNo == 'y' || yesNo == 'Y')
		a = 1;

	return a;
}

// menu function definition goes here:
int menu(void)
{
	int a;
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n\n");
	printf("Select an option:> ");
	a = getIntInRange(0, 6);
	return a;
}

// contactManagerSystem function definition goes here:
void contactManagerSystem(void)
{
	int option, a = 0;
	option = menu();
	struct Contact mycontact[MAXCONTACTS] = {
		{ {"Rick", {'\0'}, "Grimes"}, {11, "Trailer Park", 0, "A7A 2J2", "King City"}, {"4161112222", "4162223333", "4163334444"} },
		{ {"Maggie", "R.", "Greene"}, {55, "Hightop House", 0, "A9A 3K3", "Bolton"}, {"9051112222", "9052223333", "9053334444"} },
		{ {"Morgan", "A.", "Jones"}, {77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough"}, {"7051112222", "7052223333", "7053334444"} },
		{ {"Sasha", {'\0'}, "Williams"}, { 55, "Hightop House", 0, "A9A 3K3", "Bolton" }, {"9052223333", "9052223333", "9054445555"} },
	};

	while (a == 0)
	{
		while (option != 0)
		{
			switch (option)
			{

			case 1:
				printf("\n");
				displayContacts(mycontact, MAXCONTACTS);
				break;
			case 2:
				printf("\n");
				addContact(mycontact, MAXCONTACTS);
				break;
			case 3:
				printf("\n");
				updateContact(mycontact, MAXCONTACTS);
				break;
			case 4:
				printf("\n");
				deleteContact(mycontact, MAXCONTACTS);
				break;
			case 5:
				printf("\n");
				searchContacts(mycontact, MAXCONTACTS);
				break;
			case 6:
				printf("\n");
				sortContacts(mycontact, MAXCONTACTS);
				break;
			}
			pause();
			printf("\n");
			option = menu();
		}
		printf("\nExit the program? (Y)es/(N)o: ");
		a = yes();
		printf("\n");
		if (a == 1)
			printf("Contact Management System: terminated\n");
		else option = menu();

	}
}



// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char phoneNum[])
{
	int needInput = 1, i, letter = 0;

	while (needInput == 1)
	{
		scanf("%10s", phoneNum);
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(phoneNum) == 10)
		{
			letter = 0;
			for (i = 0; i < 10; i++)
			{
				if (isdigit(phoneNum[i]) == 0)
				{
					letter++;
				}
					
			}
			if (letter > 0)
				printf("Enter a 10-digit phone number: ");
			else
				needInput = 0;
		}
		else
		{
			printf("Enter a 10-digit phone number: ");
		}
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i, index = -1;
	for (i = 0; i < size; i++)
	{
		if (strcmp(cellNum, contacts[i].numbers.cell) == 0)
		{
			index = i;
			i += size;
		}
	}

	return index;
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int count)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d", count);
	printf("\n\n");
}



// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* contact)
{
	if (strlen(contact->name.middleInitial) != 0)
	{
		printf(" %s %s %s \n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
	}
	else
	{
		printf(" %s %s \n", contact->name.firstName, contact->name.lastName);
	}
	
	printf("    C: %-10s    H: %-10s    B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	if (contact->address.apartmentNumber > 0)
	{
		printf("       %d %s, Apt# %d, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.apartmentNumber, contact->address.city, contact->address.postalCode);
	}
	else
	{
		printf("       %d %s, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.city, contact->address.postalCode);
	}	
}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size)
{
	int i = 0, count = 0;
	displayContactHeader();
	for (i = 0; i < size; i++)
	{
		if ((strlen(contacts[i].numbers.cell) != 0))
		{
			displayContact(&contacts[i]);
			count++;
		}
	}
	displayContactFooter(count);
}

// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size)
{
	int found_index;
	char phone_number[11] = { 0 };
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(phone_number);
	found_index = findContactIndex(contacts, size, phone_number);
	if (found_index > 0)
	{
		printf("\n");
		displayContact(&contacts[found_index]);
		printf("\n");
	}
	else
	printf("*** Contact NOT FOUND ***\n\n");

}


// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size)
{
	int index;
	char number[11] = { 0 };
	index = findContactIndex(contacts, size, number);
	if (index < 0)
	{
		printf("*** ERROR: The contact list is full! ***\n\n");
	}
	if (index >= 0)
	{
		printf("\n");
		getContact(&contacts[index]);
		printf("---New contact added! ---\n\n");

	}
}



// updateContact:
// Put empty function definition below:
void updateContact(struct Contact contacts[], int size)
{
	int index = -1, up_name = 0, up_address = 0, up_num = 0;
	char Cell_number[11] = { 0 };
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(Cell_number);
	index = findContactIndex(contacts, size, Cell_number);
	if (index < 0)
	{
		printf("*** Contact NOT FOUND ***\n\n");
	}
	else
	{
		printf("\n");
		printf("Contact found:");
		printf("\n");
		displayContact(&contacts[index]);
		printf("\n");
		printf("Do you want to update the name? (y or n): ");
		up_name = yes();
		if (up_name == 1)
			getName(&contacts[index].name);

		printf("Do you want to update the address? (y or n): ");
		up_address = yes();
		if (up_address == 1)
		{
			getAddress(&contacts[index].address);
		}
	
		printf("Do you want to update the numbers? (y or n): ");
		up_num = yes();
		if (up_num == 1)
			getNumbers(&contacts[index].numbers);

		printf("--- Contact Updated! ---\n\n");

	}
}

// deleteContact:
// Put empty function definition below:
void deleteContact(struct Contact contacts[], int size)
{
	int index = -1, delete = 0;
	char Cell_number[11] = { 0 }, delete_num[] = { 0 };
	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(Cell_number);
	index = findContactIndex(contacts, size, Cell_number);
	if (index < 0)
	{
		printf("*** Contact NOT FOUND ***\n");
	}
	else
	{
		printf("\n");
		printf("Contact found:");
		printf("\n");
		displayContact(&contacts[index]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		delete = yes();
		if (delete == 1)
		{
			strcpy(contacts[index].numbers.cell, delete_num);
			printf("--- Contact deleted! ---\n\n");
		}
		else
			printf("\n");
	}


}

// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contacts[], int size)
{
	int i, j, a;
	int tem_ap_num, tem_street_num ;
	char temp_number[11] = { 0 };
	char temp_name[] = { 0 };
	char temp_address[] = { 0 };
	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			a = strcmp(contacts[j].numbers.cell, contacts[i].numbers.cell);
			if (a < 0 && strlen(contacts[i].numbers.cell)!=0 && strlen(contacts[j].numbers.cell) != 0 )
			{
				//Copy name
				strcpy( temp_name,  contacts[j].name.firstName);
				strcpy( contacts[j].name.firstName,  contacts[i].name.firstName);
				strcpy( contacts[i].name.firstName,  temp_name);

				strcpy( temp_name,  contacts[j].name.middleInitial);
				strcpy( contacts[j].name.middleInitial,  contacts[i].name.middleInitial);
				strcpy( contacts[i].name.middleInitial,  temp_name);

				strcpy( temp_name,  contacts[j].name.lastName);
				strcpy( contacts[j].name.lastName,  contacts[i].name.lastName);
				strcpy( contacts[i].name.lastName,  temp_name);

				//-------------------------------------------------------------
				//Copy Address
				tem_ap_num = contacts[j].address.apartmentNumber;
				contacts[j].address.apartmentNumber = contacts[i].address.apartmentNumber;
				contacts[i].address.apartmentNumber = tem_ap_num;


				strcpy( temp_address,  contacts[j].address.city);
				strcpy( contacts[j].address.city,  contacts[i].address.city);
				strcpy( contacts[i].address.city,  temp_address);

				strcpy( temp_address,  contacts[j].address.postalCode);
				strcpy( contacts[j].address.postalCode,  contacts[i].address.postalCode);
				strcpy( contacts[i].address.postalCode,  temp_address);

				strcpy( temp_address,  contacts[j].address.street);
				strcpy( contacts[j].address.street,  contacts[i].address.street);
				strcpy( contacts[i].address.street,  temp_address);

				tem_street_num = contacts[j].address.streetNumber;
				contacts[j].address.streetNumber = contacts[i].address.streetNumber;
				contacts[i].address.streetNumber = tem_street_num;

			//	//----------------------------------------------------------------
			//	//Copy Numbers
				strcpy( temp_number,  contacts[j].numbers.cell);
				strcpy( contacts[j].numbers.cell,  contacts[i].numbers.cell);
				strcpy( contacts[i].numbers.cell,  temp_number);

				strcpy( temp_number,  contacts[j].numbers.business);
				strcpy( contacts[j].numbers.business,  contacts[i].numbers.business);
				strcpy( contacts[i].numbers.business,  temp_number);

				strcpy( temp_number,  contacts[j].numbers.home);
				strcpy( contacts[j].numbers.home,  contacts[i].numbers.home);
				strcpy( contacts[i].numbers.home,  temp_number);
			}
				

		}
		
		
	}

	printf("---Contacts sorted! ---\n\n");
}