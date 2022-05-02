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
// |        source code below...                     |
// +-------------------------------------------------+
#include <stdio.h>
#include <string.h>
#include "contacts.h"
#include "contactHelpers.h"

// getName:
void getName(struct Name* name)
{

    int middle;
    char empty_name[] = { 0 };
    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]%*c", name->firstName);

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    middle = yes();


    if (middle == 1)
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]%*c", name->middleInitial);
    }
    else
    {
        strcpy(name->middleInitial, empty_name);
    }

    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]%*c", name->lastName);
}

// getAddress:
void getAddress(struct Address* address)
{
    int street, b, apartment_number = 0;

    printf("Please enter the contact's street number: ");
    street = getInt();

    while (street < 0)
    {
        printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        street = getInt();
    }

    address->streetNumber = street;

    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]%*c", address->street);

    printf("Do you want to enter an apartment number? (y or n): ");
    b = yes();

    if (b == 1)
    {
        printf("Please enter the contact's apartment number: ");
        apartment_number = getInt();
    }

    while (apartment_number < 0)
    {
        printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
        apartment_number = getInt();
    }
    address->apartmentNumber = apartment_number;

    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]", address->postalCode);
    clearKeyboard();

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]%*c", address->city);
}

// getNumbers:
void getNumbers(struct Numbers* numbers)
{
    int home, business;
    char empty_number[] = { 0 };

    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(numbers->cell);


    printf("Do you want to enter a home phone number? (y or n): ");
    home = yes();

    if (home == 1)
    {
        printf("Please enter the contact's home phone number:");
        getTenDigitPhone(numbers->home);
    }
    else
    {
        strcpy(numbers->home, empty_number);
    }


    printf("Do you want to enter a business phone number? (y or n): ");
    business = yes();

    if (business == 1)
    {
        printf("Please enter the contact's business phone number:");
        getTenDigitPhone(numbers->business);
    }
    else
    {
        strcpy(numbers->business, empty_number);
    }
}

// getContact:
// Define Empty function definition below:
void getContact(struct Contact* Contact)
{
    getName(&Contact->name);
    getAddress(&Contact->address);
    getNumbers(&Contact->numbers);
}
