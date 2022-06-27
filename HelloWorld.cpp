#include "HelloWorld.h" // Source files should #include their paired header file (if one exists)
#include "Calculator.h" // These are directives (or preprocessor directive) -> includes (copies) the contents of these files to be compiled
#include "io.h"
#include "Section11.h"
#include "Section12.h"
#include "Player.h"
#include "Shallow.h"
#include "Deep.h"
#include "Move.h"
#include "Movie.h"
#include "Movies.h"
#include "Mystring.h"
#include "Account.h"
#include "Savings_Account.h"
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "IPrintable.h"
#include <iostream>     // Angled brackets for header files we didn't make. Quotes does files we make.
#include <cstdint>      // for int_least#_t
#include <iomanip>      // for output manipulator std::setprecision()
#include <string>       // allows use of std::string for C++ Strings
#include <string_view>
#include <vector>       // for using vectors
#include <iomanip>      // IO manipulation
#include <cctype>       // for character-based functions
#include <cstring>      // Functions that work with C-style strings
#include <cstdlib>      // General purpose functions e.g convert C-style strings to other types (int, float, long, rand etc)
#include <ctime>        // required for time
#include <memory>       // for smart pointers

/*
* Arrange as:
* 1. Paired header file
* 2. Other headers from project
* 3. 3rd parter headers
* 4. Standard library headers
*/

#define PRINT_JOE // This has scope in purely this file and no where else

//using namespace std; // This is a "using directive" that lets us use functinos in std namespace without adding std:: 

//int add(int x, int y); // forward declaration - not needed here since we we used directives to include method
//int getInteger();


int main()
{
	//Chapter1();
	//Chapter2();

	//Chapter2_2();
	//Chapter4();
	//Chapter4_3();
	//Chapter4_4();

	//Section6_Challenge();

	//Section7();
	//Section7_Challenge();

	//Section8();
	//Section8_Challenge();

	//Section9();
	//Section9_Challenge();

	//Section10();
	//Section10_Challenge();
	//Section10_Assignment();

	//Section11();
	//Section11_Challenge();

	//Section12();
	//Section12_Challenge();

	//Section13();
	//Section13_Challenge();

	//Section14();

	//Section15();

	//Section16();

	//Section17();
	//Section17_Challenge();

	Section18();


	return 0;
}

// Variables 
void Chapter1()
{
	int a;	    // no initializer (only definition)
	int b = 5;  // initialize with equals
	int c(6);   // initialize with parenthesis 
	int d{ 7 }; // initialize with braces

	int width = 5;   // copy initialization of value 5 into variable width
	int width2(5);   // direct initialization of value 5 into variable width2 (can be more efficient for complicated types)
	int width3{ 5 }; // brace initialization of value 5 into variable width3
					 //int width{ 4.5 }; will throw and error so brace initialization is preffered when possible
					 //int width = 4.5 or int width(4.5) will result in width = 4 (lose the .5)

	int width4{}; // zero initialization to value 0

	std::cout << "Hello World!" << width3 << std::endl;

	std::cout << "This is a new line" << std::endl;

	std::cout << "This line is not flushed by endl \n";

	std::cout << "This line is not flushed by endl and uses standalone new line" << '\n'; // prefer \n over endl


	std::cout << "Enter a number: ";
	int x{};       // define variable x t o hold user input (and zero-initilize it)
	std::cin >> x; // get number from keyboard and store it in variable x

	std::cout << "You entered " << x << '\n';

	std::cout << "Enter two numbers separated by a space: ";
	int y{};
	int z{};
	std::cin >> x >> y; // get two numbers and store in varaible y and z respectively

	std::cout << "You entered " << x << " and " << y << '\n';

	int x2; // unintialized value can have random values -> always initialize variables unless intentionally not needed
	        //std::cout << x2; will throw an error or print random values

	int myFunctionName();
	int myVariableName;

	int input1{};

	std::cout << "Enter an integer: ";
	std::cin >> input1;
	std::cout << "Double " << input1 << " is: " << input1 * 2 << '\n';
	std::cout << "Triple " << input1 << " is: " << input1 * 3 << '\n';


	int input2{};
	int input3{};

	std::cout << "Enter an integer: ";
	std::cin >> input2;
	std::cout << "Enter another integer: ";
	std::cin >> input3;
	std::cout << input2 << " + " << input3 << " is " << input2 + input3 << ".\n";
	std::cout << input2 << " - " << input3 << " is " << input2 - input3 << ".";
}

// using other directives
void Chapter2()
{
	int num{ getInteger() }; // first call
	int num2{ getInteger() }; // second call
	std::cout << num << " doubled is: " << num * 2 << '\n'; // std::cout means cout in the namespace std

	print(num2);
	print(add(num, num2)); // This add is taking the add from Calculator.cpp

#ifdef PRINT_JOE
	std::cout << "JOE\n"; // will run
#endif

#ifdef PRINT_BOB
	std::cout << "JOE\n"; // won't run
#endif
	
#ifndef PRINT_ALICE
	std::cout << "JOE\n"; // will run
#endif

#if 0
	std::cout << "Steven\n"; // won't run
#endif



}

void print(int x)
{
	std::cout << x << '\n';
}

void Chapter2_2()
{
	int x{};
	int y{};
	x = readNumber();
	y = readNumber();
	writeAnswer(x / y);
}

// Data types & boolean outputs
void Chapter4()
{
	std::cout << "bool:\t\t" << sizeof(bool) << "bytes\n";
	std::cout << "char:\t\t" << sizeof(char) << "bytes\n";
	std::cout << "wchar_t:\t" << sizeof(wchar_t) << "bytes\n";
	std::cout << "char16_t:\t" << sizeof(char16_t) << "bytes\n";
	std::cout << "char32_t:\t" << sizeof(char32_t) << "bytes\n";
	std::cout << "short:\t\t" << sizeof(short) << "bytes\n";
	std::cout << "int:\t\t" << sizeof(int) << "bytes\n";
	std::cout << "long:\t\t" << sizeof(long) << "bytes\n";
	std::cout << "long long:\t" << sizeof(long long) << "bytes\n";
	std::cout << "float:\t\t" << sizeof(float) << "bytes\n";
	std::cout << "double:\t\t" << sizeof(double) << "bytes\n";
	std::cout << "long double:\t" << sizeof(long double) << "bytes\n";

	std::cout << 20 / 5;
	std::cout << 8 / 5 << '\n'; // lose fractional

	unsigned short x{ 65535 }; // largest 16-bit unsigned value
	std::cout << "x was: " << x << '\n';

	x = 65536; // 65536 out of range so get wrap-around
	std::cout << "x is now: " << x << '\n';

	x = 65537; // 65537 out of range so get wrap-around
	std::cout << "x is now: " << x << '\n';

	x = -1; // -1 out of range so get wrap-around
	std::cout << "x is now: " << x << '\n';

	x = -2; // -2 out of range so get wrap-around
	std::cout << "x is now: " << x << '\n';

	std::int16_t i{ 5 };
	std::cout << i << '\n';

	// smalleset signed integer at least this number of bits
	std::cout << "least 8: " << sizeof(std::int_least8_t) * 8 << "bits\n";
	std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << "bits\n";
	std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << "bits\n\n";

	// fastest signed/unsigned integer at least this number of bits
	std::cout << "fasat 8: " << sizeof(std::int_fast8_t) * 8 << "bits\n";
	std::cout << "fasat 16: " << sizeof(std::int_fast16_t) * 8 << "bits\n";
	std::cout << "fasat 32: " << sizeof(std::int_fast32_t) * 8 << "bits\n";

	float fValue{ 5.0f }; // f means float type
	double dValue{ 5.0 }; // floating point defaults to double

	std::cout << 5.0 << '\n'; // loses the .0
	std::cout << 6.7f << '\n'; // alright
	std::cout << 9876543.21 << "\n\n"; // converted to scientific notation

	std::cout << 9.87654321f << '\n';
	std::cout << 987.654321f << '\n';
	std::cout << 987654.321f << '\n';
	std::cout << 9876543.21f << '\n';
	std::cout << 0.0000987654321f << "\n\n";

	// There are always rounding errors with floating point numbers
	std::cout << std::setprecision(16);  // show 16 difits of precision
	std::cout << 3.33333333333333333333333333333333333333f << '\n'; // f suffix means float
	std::cout << 3.33333333333333333333333333333333333333 << "\n\n"; // no suffix means double

	std::cout << true << '\n'; // true evaluates to 1
	std::cout << !true << '\n'; // !true evaluates to 0

	std::cout << std::boolalpha; // print bools as true or false and allows "true" and "false" inputs
	bool b{ false };
	std::cout << b << '\n'; // b is false, which evaluates to 0
	std::cout << !b << "\n\n"; // !b is true, which evaluates to 1

	std::cout << "Enter an integer: ";
	int x1{};
	std::cin >> x1;

	std::cout << "Enter another integer: ";
	int x2{};
	std::cin >> x2;

	std::cout << std::boolalpha;

	std::cout << x1 << " and " << x2 << " are equal? ";
	std::cout << isEqual(x1, x2) << '\n';

	std::cout << "Enter an integer: ";
	int conditionalInt{};
	std::cin >> conditionalInt;

	if (conditionalInt > 0)
		std::cout << "The value is positive\n";
	else if (conditionalInt < 0)
		std::cout << "The value is negative\n";
	else
		std::cout << "The value is zero\n";

	std::cout << '\n';

	char ch2{ 'a' }; // initialize with code point for 'a' (stored as integer 97)
	char ch1{ 97 }; // initialize with integer 97 (a) - not preferred

	char cha{ 5 }; // initialize with integer 5 (stored as integer 5)
	char chb{ '5' }; // initialize with code point for '5' (stored as integer 53)


	std::cout << "Input a keyboard character: ";

	char ch{};
	std::cin >> ch;
	std::cout << "You entered: " << ch << '\n'; // only first input character is extracted, rest is used as input buffer -> queues the inputs

	print(static_cast<int>(5.5)); // explicitly convert double value 5.5 to int

	std::cout << ch1 << " has value " << static_cast<int>(ch1) << '\n'; // print value of variable ch1 as int

	std::cout << "Enter a number between 0 and 255: ";
	std::int8_t myint{};
	std::cin >> myint;

	std::cout << "You entered: " << static_cast<int>(myint);
	// can cause problems, int8_t interprets input as char not int
	// if we enter 35, it will take the char 3 as the input. Char 3 has ASCII code 51, so we return 51.

	std::string myName{}; // empty string
	std::string myOtherName{ "Jimmy" }; // initialize with literal
	myName = "Andy"; // assign variable myName with literal
	myOtherName = "34"; // NOT the same as integer 34. C++ won't automatically convert string to int

	std::cout << "Enter your full name: ";
	std::string name{};
	//std::cin >> name; // issue here, cin only takes things up to the first whitespace (i.e, the space in your name)
	std::getline(std::cin >> std::ws, name); // this reads the full line of text into name
	// std::ws tells cin to ignore any leading whitspace - good as if we press Enter, we're actually entering \n!

	std::cout << "Enter your age: ";
	int age{};
	//std::cin >> age; // This takes the value after the white space from the above cin
	std::cin >> age; // this reads the full line of text into age

	std::cout << "Your name is " << name << " and your age is " << age << '\n';
	std::cout << "Your age + lenght of name is: " << static_cast<int>(name.length()) + age << '\n';

	std::cout << 3.4; // 3.4 is a double literal
	double pi{ 3.14159 }; // 3.14159 is a double literain standard notation
	double avogadro{ 6.02e23 }; // 6.02 x 10^23 is a double literal in scientific notation
	double electron{ 1.6e-19 }; // charge on an electron is 1.6 x 10^-19

	int octal{ 012 }; // 0 before number means it's octal -> prints 10
	int hexa{ 0xF }; // 0x before number means it's hexadecimal -> prints 15

	int bin{};    // assume 16-bit ints
	bin = 0x0001; // assign binary 0000 0000 0000 0001 to the variable
	bin = 0x0002; // assign binary 0000 0000 0000 0010 to the variable
	bin = 0x0004; // assign binary 0000 0000 0000 0100 to the variable
	bin = 0x0008; // assign binary 0000 0000 0000 1000 to the variable
	bin = 0x0010; // assign binary 0000 0000 0001 0000 to the variable
	bin = 0x0020; // assign binary 0000 0000 0010 0000 to the variable
	bin = 0x0040; // assign binary 0000 0000 0100 0000 to the variable
	bin = 0x0080; // assign binary 0000 0000 1000 0000 to the variable
	bin = 0x00FF; // assign binary 0000 0000 1111 1111 to the variable
	bin = 0x00B3; // assign binary 0000 0000 1011 0011 to the variable
	bin = 0xF770; // assign binary 1111 0111 0111 0000 to the variable

	int bin2{};
	bin = 0b1; // assign binary 0000 0000 0000 0001 to the variable
	bin = 0b11;
	bin = 0b1010;
	bin = 0b1111'0000; // assign binary 0000 0000 1111 0000 to the variable
	// ' can be used as a digit separator 

	const double gravity{ 9.8 }; // symbolic constant must be initialized and cannot be changed. This is compile-time constant
	const int someOtherThing{ age }; // this is runtime constant.

	constexpr double gravity2{ 9.8 }; // contexpr ensures a constant must be a compile-time constant
	constexpr int sum{ 4 + 5 }; // ok, the value of 4+5 can be resolved at compile time

	using namespace std::literals;

	constexpr std::string_view someName{ "Alex"sv }; // string_view can be constexpr
	std::cout << "My name is: " << someName << '\n';

}

bool isEqual(int x, int y)
{
	return (x == y);
}

void Chapter4_3()
{
	std::cout << "Enter a double value: ";
	double num1{};
	std::cin >> num1;

	std::cout << "Enter a double value: ";
	double num2{};
	std::cin >> num2;

	std::cout << "Enter one of the following: +, -, *, or /: ";
	char operation{};
	std::cin >> operation;

	double answer{};

	switch (operation)
	{
		case '+':
			answer = num1 + num2;
			break;
		case '-':
			answer = num1 - num2;
			break;
		case '*':
			answer = num1 * num2;
			break;
		case '/':
			answer = num1 / num2;
			break;
	}

	std::cout << num1 << operation << num2 << " is " << answer;
}

double distanceFallen(double seconds)
{
	constexpr double gravity{ 9.8 };

	return gravity * ((seconds * seconds)/2);
}

// Simulate ball dropped off a tower
void Chapter4_4()
{
	int secondsAfterDropping{ 0 };
    double heightOfTower{};
	double heightOfBall{};

	std::cout << "Enter the height of the tower in meters: ";
	std::cin >> heightOfTower;
	heightOfBall = heightOfTower;

	while (heightOfBall > 0)
	{
		std::cout << "At " << secondsAfterDropping << " seconds, the ball is at height: " << heightOfBall << " meters\n";
		secondsAfterDropping++;
		heightOfBall = heightOfTower - distanceFallen(secondsAfterDropping);
	}

	std::cout << "At " << secondsAfterDropping << " seconds, the ball is on the ground.";
}

// Variables and consts
void Section6_Challenge()
{
	const double smallRoomFee{ 25 };
	const double largeRoomFee{ 35 };
	const double salesTax{ 0.06 };

	int smallRoomsToClean{ 0 };
	int largeRoomsToClean{ 0 };
	double cost{ 0 };
	double tax{ 0 };
	double costWithTax{ 0 };

	std::cout << "Number of small rooms: ";
	std::cin >> smallRoomsToClean;
	std::cout << "Number of large rooms: ";
	std::cin >> largeRoomsToClean;

	std::cout << "Price per small room: $" << smallRoomFee << '\n';
	std::cout << "Price per large room: $" << largeRoomFee << '\n';

	cost = (smallRoomFee * static_cast<double>(smallRoomsToClean)) + (largeRoomFee * static_cast<double>(largeRoomsToClean));
	tax = cost * salesTax;
	costWithTax = cost + tax;

	std::cout << "Cost: $" << cost << '\n';
	std::cout << "Tax: $" << tax << '\n';
	std::cout << "Total estimate: $" << costWithTax << '\n';

}

// Arrays and vectors
void Section7()
{
	int test_scores[5] {100, 99, 95, 87, 88}; // create array of length 5 and only length 5
	int high_score_per_level[10]{ 3, 5 }; // init to 3, 5 and remaining to 0
	int another_array[]{ 1, 2, 3, 4, 5 }; // size automatically calculated
	// Always initialize arrays

	std::cout << test_scores[1];
	std::cin >> test_scores[1];
	std::cout << test_scores[1];

	std::cout << "\n\n";

	char vowels[]{ 'a', 'e', 'i', 'o', 'u' };
	std::cout << "The first vowel is: " << vowels[0] << '\n';
	std::cout << "The last vowel is: " << vowels[4] << '\n';
	//std::cin >> vowels[5]; <- out of bounds, don't do this!

	std::cout << test_scores << '\n'; // Will print test_scores hex memory address

	const int rows{ 3 };
	const int cols{ 4 };

	int movie_rating[rows][cols]
	{
		{0, 4, 3, 5},
		{2, 3, 3, 5},
	    {1, 4, 4, 5}
	};

	std::cin >> movie_rating[1][2];
	std::cout << movie_rating[1][2];

	// Vectors are a dynamic array - can grow and shrink at run time and have more methods
	std::vector <char> vowels2 { 'a', 'e', 'i', 'o', 'u' }; // accessing values in vectors same as array
	std::vector<int> test_scores2 (10);                     // automatically set to 0 of length 10
	std::vector<double> hi_temps(365, 80.0);                // vector length 365 with all values initialized to 80

	std::cin >> hi_temps[4];
	std::cout << hi_temps.at(4) << '\n';

	test_scores2.push_back(90); // Adds 90 to the end of the vector and extends the vector
	std::cout << test_scores2.at(10) << '\n';
}

// Arrays and vectors
void Section7_Challenge()
{
	std::cout << "\n\n";

	std::vector<int> vector1;
	std::vector<int> vector2;

	vector1.push_back(10);
	vector1.push_back(20);

	std::cout << vector1[0] << '\n' << vector1[1] << '\n' << vector1.size() << '\n';

	vector2.push_back(100);
	vector2.push_back(200);

	std::cout << vector2[0] << '\n' << vector2[1] << '\n' << vector2.size() << '\n';

	std::vector<std::vector<int>> vector_2d;

	vector_2d.push_back(vector1); // This makes a copy of vector1, not vector1 itself
	vector_2d.push_back(vector2);

	std::cout << vector_2d.at(0).at(0) << '\n';
	std::cout << vector_2d.at(0).at(1) << '\n';
	std::cout << vector_2d.at(1).at(0) << '\n';
	std::cout << vector_2d.at(1).at(1) << '\n';

	vector1.at(0) = 1000; // Does not change vector_2d

	std::cout << vector_2d.at(0).at(0) << '\n';
	std::cout << vector_2d.at(0).at(1) << '\n';
	std::cout << vector_2d.at(1).at(0) << '\n';
	std::cout << vector_2d.at(1).at(1) << '\n';
}

// Operators
void Section8()
{
	int total{};
	int num1{}, num2{}, num3{};
	const int count{ 3 };


	std::cout << "Enter 3 integers separated by spaces: ";
	std::cin >> num1 >> num2 >> num3;

	total = num1 + num2 + num3;

	double average{ 0.0 };

	//average = total / count; // Will only give integer values since total and count are integers
	//average = (double)total / count; // Old style
	average = static_cast<double>(total) / count; // This will convert the result to a double value

	std::cout << "The 3 numbers were: " << num1 << ", " << num2 << ", " << num3 << std::endl;
	std::cout << "The sum of the numbers is: " << total << std::endl;
	std::cout << "The average of the numbers is: " << average << std::endl;
	
	double double1{}, double2{};
	bool equal_result{};
	bool not_equal_result{};
	
	std::cout << "Enter two doubles separated by a space: ";
	std::cin >> double1 >> double2;

	// These can cause weird behaviour as it's not completely precise
	// I.e 12.0 and 11.999999999999 are equal - need special libraries for higher precision
	equal_result = (double1 == double2);
	not_equal_result != (double1 == double2);
	std::cout << "Comparison result (equals): " << equal_result << std::endl;
	std::cout << "Comparison result (not equals): " << not_equal_result << std::endl;

	// Compound operators
	bool resultingBool{};
	int lhs = 5;
	int rhs = 10;
	lhs += rhs; // lhs = lhs + (rhs);
	lhs -= rhs; // lhs = lhs - (rhs);
	lhs *= rhs; // lhs = lhs * (rhs);
	lhs /= rhs; // lhs = lhs / (rhs);
	lhs %= rhs; // lhs = lhs % (rhs);


	std::cout << std::endl;
}

// Calculating change from cents
void Section8_Challenge()
{
	int numberOfCents1{}, numberOfCents2{};
	int dollarCount{}, quarterCount{}, dimeCount{}, nickelCount{}, pennyCount{};
	const int dollar{ 100 }, quarter{ 25 }, dime{ 10 }, nickel{ 5 }, penny{ 1 };

	std::cout << "Enter a number representing the number of cents: ";
	std::cin >> numberOfCents1;
	numberOfCents2 = numberOfCents1; // duplicate for second solution

	/*
	* 1 dollar  = 100 cents
	* 1 quarter = 25 cents
	* 1 dime    = 10 cents
	* 1 nickel  = 5 cents
	* 1 penny   = 1 cent
	*/

	// One solution
	while (numberOfCents1 >= dollar)
	{
		numberOfCents1 -= dollar;
		dollarCount++;
	}
		
	while (numberOfCents1 >= quarter)
	{
		numberOfCents1 -= quarter;
		quarterCount++;
	}
		
	while (numberOfCents1 >= dime)
	{
		numberOfCents1 -= dime;
		dimeCount++;
	}
	
	while (numberOfCents1 >= nickel)
	{
		numberOfCents1 -= nickel;
		nickelCount++;
	}
	
	while (numberOfCents1 >= penny)
	{
		numberOfCents1 -= penny;
		pennyCount++;
	}

	std::cout << "Dollars: " << dollarCount << '\n';
	std::cout << "Quarters: " << quarterCount << '\n';
	std::cout << "Dimes: " << dimeCount << '\n';
	std::cout << "Nickels: " << nickelCount << '\n';
	std::cout << "Pennies: " << pennyCount << '\n';


	// Another Solution
	std::cout << "\nWithout loops\n";

	dollarCount = 0;
	quarterCount = 0;
	dimeCount = 0;
	nickelCount = 0;
	pennyCount = 0;

	dollarCount = numberOfCents2 / dollar; // Get whole number of dollars that fit
	numberOfCents2 -= dollar * dollarCount; // Get the remainder left (should be less than a dollar)
	
	quarterCount = numberOfCents2 / quarter;
	numberOfCents2 -= quarter * quarterCount;
	
	dimeCount = numberOfCents2 / dime;
	numberOfCents2 -= dime * dimeCount;
	
	nickelCount = numberOfCents2 / nickel;
	numberOfCents2 -= nickel * nickelCount;
	
	pennyCount = numberOfCents2 / penny;
	numberOfCents2 -= penny * pennyCount;

	std::cout << "Dollars: " << dollarCount << '\n';
	std::cout << "Quarters: " << quarterCount << '\n';
	std::cout << "Dimes: " << dimeCount << '\n';
	std::cout << "Nickels: " << nickelCount << '\n';
	std::cout << "Pennies: " << pennyCount << '\n';
}

// Flow control
void Section9()
{
	int num{100};
	int min{ 10 }, max{ 100 };
	std::cout << "Enter a number: ";
	//std::cin >> num;

	if (num >= min)
	{
		int diff{ num - min }; // scope is within the if statement
		std::cout << num << " is greater than or equal to " << min << '\n';
		std::cout << num << " is " << diff << " greater than " << min;
	}

	if (num <= max)
	{
		int diff{ max - num };
		std::cout << num << " is less than  or equal to " << max << '\n';
		std::cout << num << " is " << diff << " less than " << max << '\n';
	}

	int score{80};
	char letter_grade{};

	std::cout << "Enter your score on the exam (0 - 100): ";
	//std::cin >> score;

	if (score >= 0 && score <= 100)
	{
		if (score >= 90)
			letter_grade = 'A';
		else if (score >= 80)
			letter_grade = 'B';
		else if (score >= 70)
			letter_grade = 'C';
		else if (score >= 60)
			letter_grade = 'D';
		else
			letter_grade = 'F';

		std::cout << "Your grade is: " << letter_grade << '\n';

		if (letter_grade == 'F')
			std::cout << "Sorry, you must repeat this class.\n";
		else
			std::cout << "Congratulations, you pass this class.\n";
	}
	else
	{
		std::cout << "Sorry, value not in range.\n";
	}

	std::cout << "Enter the letter grade you expect on the exam: ";
	//std::cin >> letter_grade;

	switch (letter_grade)
	{
    	case 'A': // Once a case statement is successfull, it will execute everything underneath it
		case 'a': // Unless a break is reached.
			std::cout << "You need at least 90\n";
			break;
		case 'B':
		case 'b':
			std::cout << "You need 80-89\n";
			break;
		case 'C':
		case 'c':
			std::cout << "You need 70-79\n";
			break;
		case 'D':
		case 'd':
			std::cout << "You need 60-69\n";
			break;
		case 'F':
		case 'f':
		{
			char confirm{};
			std::cout << "Are you sure (Y/N): ";
			std::cin >> confirm;

			if (confirm == 'Y' || confirm == 'y')
				std::cout << "You need 59 or under\n";
			else if (confirm == 'N' || confirm == 'n')
				std::cout << "Go study\n";
			else
				std::cout << "Illegal choice";
			
			break;
		}
		default:
			std::cout << "Sorry, not a valid grade\n";
	}

	// conditional operator
	num = 4;
	
	if (num % 2 == 0)
		std::cout << num << " is even.\n";
	else
		std::cout << num << " is odd.\n";

	// Does the same as above
	std::cout << num << " is " << ((num % 2 == 0) ? "even." : "odd.") << '\n';

	// for loops
	for (int i {1}; i <= 5; i+=2)
		std::cout << i << '\n';

	std::vector<int> scores{ 100, 90, 87 };
	for (int i{ 0 }; i < scores.size(); i++)
		std::cout << scores[i] << '\n';

	// can use comma operator to manipulate multiple iterators ( i < 5 wil never happen here as j < 7 occurs first)
	for (int i{ 0 }, j{ 5 }; i < 5, j < 7; i++, j++)
		std::cout << i << " * " << j << " : " << (i * j) << '\n';

	// will loop forever, all expressions in for loop are optional
	//for (;;)
	//	std::cout << "Endless loop" << '\n';

	for (int i{ 1 }; i <= 100; i++)
	{
		std::cout << i;
		if (i % 10 == 0)
			std::cout << '\n';
		else
			std::cout << " ";
	}

	for (int i{ 1 }; i <= 100; i++)
	{
		std::cout << i << ((i % 10 == 0) ? '\n' : ' ');
	}

	// range-based loop
	std::vector<int> new_scores{ 100, 90, 96 };

	for (int score : new_scores)
		std::cout << score << '\n';
	

	for (auto score : new_scores) // auto determines the type by itself
		std::cout << score << '\n';

	// remove spaces from string
	for (auto c : "This is a test")
		if (c != ' ')
			std::cout << c;
	
	std::cout << '\n';

	// while (can use conditional or boolean flag)
	bool done{ false };
	int number{ 3 };

	while (!done)
	{
		std::cout << "Enter an integer between 1 and 5: ";
		//std::cin >> number;

		if (number <= 1 || number >= 5)
		{
			std::cout << "Out of range, try again" << '\n';
		}
		else
		{
			std::cout << "Thanks!" << '\n';
			done = true;
		}
	}

	// do-while (executes at least once)
	char choice{};
	do
	{
		std::cout << "1. Do this \n2. Do that \n3. Do something else \nQ. Quit\n\n";
		std::cout << "Enter your selection: ";
		std::cin >> choice;

		switch (choice)
		{
		    case '1':
				std::cout << "Doing this.\n";
				break;
			case '2':
				std::cout << "Doing that.\n";
				break;
			case '3':
				std::cout << "Doing something else.\n";
				break;
			case 'Q':
			case 'q':
				std::cout << "Quitting.\n";
				break;
			default:
				std::cout << "I can't do that.\n";
				break;
		}

		std::cout << "------------------------------\n";
	}
	while (choice != 'Q' && choice != 'q');

	// continue and break
	std::vector<int> values{ 1, 2, -1, 3, -1, -99, 7, 8, 10 };
	for (auto val : values)
	{
		if (val == -99)
			break; // exits for loop here
		else if (val == -1)
			continue; // skips the rest of the code and continues to the next iteration
		else
			std::cout << val << '\n';
	}

	// nested loop
	for (int num1{ 1 }; num1 <= 10; num1++)
	{
		for (int num2{ 1 }; num2 <= 10; num2++)
		{
			std::cout << num1 * num2 << " ";
		}

		std::cout << '\n';
	}

	int num_items{};

	std::cout << "How many items do you have? ";
	std::cin >> num_items;

	std::vector<int> data{};

	for (int i{ 1 }; i <= num_items; i++)
	{
		int data_item{};
		std::cout << "Enter data item " << i << ": ";
		std::cin >> data_item;
		data.push_back(data_item);
	}

	std::cout << "You entered\n";

	for (auto data_item : data)
	{
		std::cout << data_item << '\n';
	}

	std::cout << "Here is the histogram\n";

	for (auto data_item : data)
	{
		for (int i{ 1 }; i <= data_item; i++)
		{
			std::cout << ((i % 5 == 0) ? '*' : '-');
		}
		
		std::cout << '\n';
	}
}

void Section9_Challenge()
{
	std::vector<int> numbers;
	char choice{};

	do
	{
		std::cout << "P - Print numbers\n";
		std::cout << "A - Add a number\n";
		std::cout << "M - Display mean of the numbers\n";
		std::cout << "S - Display the smallest number\n";
		std::cout << "L - Display the largest number\n";
		std::cout << "Q - Quit\n\n";

		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch (choice)
		{
			case 'P':
			case 'p':
			{
				if (numbers.size() > 0)
				{
					std::cout << "[ ";
					for (auto number : numbers)
					{
						std::cout << number << " ";
					}
					std::cout << ']';
				}
				else
				{
					std::cout << "[] - the list is empty";
				}

				std::cout << '\n';

				break;
			}

			case 'A':
			case 'a':
			{
				int numberToAdd;
				std::cout << "Enter the number to add: ";
				std::cin >> numberToAdd;

				// Check that it's an integer
				//if (std::cin.fail())
				//{
				//	std::cout << "Do you know what a number is?\n";
				//	break;
				//}
					

				numbers.push_back(numberToAdd);

				std::cout << numberToAdd << " added.\n";

				break;
			}

			case 'M':
			case 'm':
			{
				if (numbers.size() == 0)
				{
					std::cout << "Unable to calculate the mean - no data.\n";
					break;
				}


				int total{};

				for (auto number : numbers)
					total += number;

				std::cout << "The mean is: " << (static_cast<double>(total) / numbers.size()) << '\n';

				break;
			}

			case 'S':
			case 's':
			{
				if (numbers.size() == 0)
				{
					std::cout << "Unable to find smallest- no data.\n";
					break;
				}

				// initialize with first number so we have something to compare to
				int smallest{numbers.at(0)};

				for (auto number : numbers)
				{
					// get the smaller number of the comparison
					smallest = ((number < smallest) ? number : smallest);
				}

				std::cout << "The smallest number is " << smallest << '\n';

				break;
			}

			case 'L':
			case 'l':
			{
				if (numbers.size() == 0)
				{
					std::cout << "Unable to find smallest- no data.\n";
					break;
				}

				// initialize with first number so we have something to compare to
				int largest{ numbers.at(0) };

				for (auto number : numbers)
				{
					// get the larger number of the comparison
					largest = ((number > largest) ? number : largest);
				}

				std::cout << "The largest number is " << largest << '\n';

				break;
			}

			case 'Q':
			case 'q':
				std::cout << "Goodbye\n";
				break;

			default:
				std::cout << "Unknown selection, please try again.\n";
		}

		std::cout << "\n-------------------------------\n";
	}
	while (choice != 'Q' && choice != 'q');

}

// Characters and Strings
void Section10()
{
	// C-style strings
	char uninitialized_first_name[20];
	char first_name[20]{};
	char last_name[20]{};
	char full_name[50]{"Jimmy Chuong"};
	char temp[50]{};

	std::cout << uninitialized_first_name << '\n'; // will likely display garbage

	//std::cout << "Please enter your first name: ";
	//std::cin >> first_name;
	//std::cout << "Please enter your last name: ";
	//std::cin >> last_name;
	//std::cout << "--------------------------------------\n";

	//// strlen(XXX) will return data of type size_t - platform-dependent. size_t =/= unsigned int
	//// C-type strings are chars stored in array that ends in null pointer - no null pointer leads to problems
	//std::cout << "Hello, " << first_name << " your first name has " << strlen(first_name) << " characters\n";
	//std::cout << "and your last name, " << last_name << " has " << strlen(last_name) << " characters\n";

	// These methods are unsafe, can cause corrupted data
	//strcpy(full_name, first_name);   // copy first_name to full_name
	//strcat(full_name, " ");          // concatenate full_name and a space
	//strcat(full_name, last_name);     // concatenate last_name to full_name
	//std::cout << "Your full name is " << full_name << '\n';

	// Will take entire line
	std::cout << "Enter your full name: ";
	//std::cin.getline(full_name, 50); // reads 50 characters
	std::cout << "Your full name is " << full_name << '\n';

	// Will only take name up to white space
	//std::cout << "Enter your full name: ";
	//std::cin >> full_name;
	//std::cout << "Your full name is " << full_name << '\n';

	strcpy_s(temp, full_name);

	if (strcmp(temp, full_name) == 0) // string compare, since we copied we expect them to be the same
		std::cout << temp << " and " << full_name << " are the same\n";
	else
		std::cout << temp << " and " << full_name << " are the different\n";

	std::cout << "--------------------------------------\n";

	for (size_t i{ 0 }; i < strlen(full_name); i++)
	{
		if (isalpha(full_name[i])) // if character is alpha character
			full_name[i] = toupper(full_name[i]); // make character capital
	}

	std::cout << "Your full name is " << full_name << '\n';

	std::cout << "--------------------------------------\n";

	if (strcmp(temp, full_name) == 0) // string compare, since we copied we expect them to be the same
		std::cout << temp << " and " << full_name << " are the same\n";
	else
		std::cout << temp << " and " << full_name << " are the different\n";

	std::cout << "--------------------------------------\n";

	// strcmp returns < 0 if first string lexically comes before second string, > 0 if other way round
	std::cout << "Result of comparing " << temp << " and " << full_name << ": " << strcmp(temp, full_name) << '\n';
	std::cout << "Result of comparing " << full_name << " and " << temp << ": " << strcmp(full_name, temp) << '\n';

	// C++ style strings
	std::string s1;               // Empty - C++ style strings are always initialized
	std::string s2{ "Frank" };    // Frank
	std::string s3{ s2 };         // Frank
	std::string s4{ "Frank", 3 }; // Fra - Take first 3 characters
	std::string s5{ s3, 0, 2 };   // Fr - First index is starting index. Second is length i.e take index 0 and 1
	std::string s6(3, 'X');       // XXX

	s1 = "C++ Rocks!";
	s2 = s1; // s2 now says "C++ Rocks!"

	std::string part1{ "C++" };
	std::string part2{ "is a powerful" };

	std::string sentence;
	sentence = part1 + " " + part2 + " language"; // C++ is a powerful language
	// sentence = "C++" + " is powerful"; // Illegal as these are both C-style strings

	s1 = "";
	s2 = "Frank";

	std::cout << s2[0] << '\n'; // F
	std::cout << s2.at(0) << '\n'; // F
	s2[0] = 'f'; // frank
	s2.at(0) = 'p'; // prank

	for (char c : s2)
		std::cout << c << '\n';

	for (int c : s2)
		std::cout << '\n'; // Will print out ASCII code with 0 at the end for null character

	// C++ strings can be compared lexically - i.e A < Z
	s1 = "Apple";
	s2 = "Banana";
	s3 = "Kiwi";
	s4 = "apple";
	s5 = s1;

	std::cout << s1 + " == " + s5 + ": " << (s1 == s5) << '\n'; // True
	std::cout << s1 + " == " + s2 + ": " << (s1 == s2) << '\n'; // False
	std::cout << s1 + " != " + s2 + ": " << (s1 != s2) << '\n'; // True
	std::cout << s1 + " < " + s2 + ": " << (s1 < s2) << '\n';  // True
	std::cout << s1 + " > " + s2 + ": " << (s1 > s2) << '\n';  // False
	std::cout << s4 + " < " + s5 + ": " << (s4 < s5) << '\n';  // False - a is higher than A
	std::cout << s1 + " == Apple : " << (s1 == "Apple") << '\n'; // True
	
	s1 = "This is a test";
	std::cout << s1.substr(0, 4) << '\n';   // This
	std::cout << s1.substr(5, 2) << '\n';   // is
	std::cout << s1.substr(10, 4) << '\n';  // test

	// Finds first index of first appearance
	std::cout << s1.find("This") << '\n';   // 0
	std::cout << s1.find("is") << '\n';     // 2
	std::cout << s1.find("test") << '\n';   // 10
	std::cout << s1.find('e') << '\n';      // 11
	std::cout << s1.find("is", 4) << '\n';  // 5 - start search from index 4
	std::cout << s1.find("XX") << '\n';     // string::npos - no position, some random stuff

	size_t position = s1.find("XX");
	if (position != std::string::npos)
		std::cout << "Found XX at position: " << position << '\n';
	else
		std::cout << "Sorry XX could not be found\n";


	// Erases substring of characters
	std::cout << s1.erase(0, 5) << '\n'; // is a test
	s1.clear(); // empties string s1

	// Getting line
	std::cin >> s1;   // Hello there
	std::cout << s1 << '\n';  // Hello - extracted up to first space

	std::getline(std::cin, s1); // Read entire line until \n
	std::cout << s1 << '\n'; // Hello there

	std::getline(std::cin, s1, 'x'); // third argument is the delimiter. Stop reading input at delimiter
	std::cout << s1 << '\n'; // e.g input this isx, return this is
}

// Substitution encryption - try enigma machine?
void Section10_Challenge()
{
	// Substitution Sample
	const std::string alphabet{ "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ " };
	const std::string key{ "XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyztkfuompciasr " };

	std::string decrypted{};
	std::string encrypted{};

	std::cout << "Enter the sentence to encrypt: ";
	std::getline(std::cin, decrypted);

	// For each character, get the position in the alphabet, then get corresponding key
	for (char letter : decrypted)
	{
		size_t position = alphabet.find(letter);

		if (position != std::string::npos)
		{
			encrypted += (key.at(position));
		}
		else
		{
			encrypted += '*';
		}
	}

	std::cout << "The encrpted message is: " + encrypted;
}

// Letter Pyramid
void Section10_Assignment()
{
	std::cout << "Enter a sentence to make a letter pyramid out of: ";

	std::string input;
	std::getline(std::cin, input);

	// I know variables should be named consistently :(
	size_t totalLength{ (input.size() * 2) - 1 }; // total length of the final string in pyramid
	size_t middlePosition{ input.size() - 1};     // middle position of the pyramid

	std::cout << "Total Length: " << totalLength << '\n';

	/*
	*  PART 1: PRINT RIGHT SEQUENCE
	*  Print the current letter
	*  Print all the letters before it
	*/

	for (int i{ 0 }; i < input.size(); i++)
	{
		for (int j{ i }; j >= 0; j--)
		{
			std::cout << input.at(i - j);
		}

		std::cout << '\n';
	}

	std::cout << "-------------------------------------------\n";

	/*
	*  PART 2: PRINT IN RIGHT POSITION
	*  Print current letter in the middle
	*  Print all the letters before it before and after the middle position
	*/

	for (int i{ 0 }; i < input.size(); i++)
	{
		std::string layer(totalLength, ' ');

		for (int j{ i }; j >= 0; j--)
		{
			layer.at(middlePosition - j) = input.at(i - j);
			layer.at(middlePosition + j) = input.at(i - j);
		}

		std::cout << layer;
		std::cout << '\n';
	}
}

// Functions
void Section11()
{
	int random_number{};
	size_t count{ 10 };
	int min{ 1 }; // lower bound (inclusive)
	int max{ 5 }; // upper bound (inclusive)

	std::cout << "RAND_MAX on my system is: " << RAND_MAX << '\n';
	srand(time(nullptr)); // seed random number generator - no seed -> same sequence

	for (size_t i{ 1 }; i <= count; i++)
	{
		random_number = rand() % max + min; // generate a random number [min, max]
		std::cout << random_number << '\n';
	}

	int my_scores[]{ 100, 89, 90, 99, 67 };
	print_array(my_scores, 5);
	set_array(my_scores, 5, 100);
	print_array(my_scores, 5); // this will all be 100
	
	int number{ 9999 };
	std::cout << number << '\n'; 
	scale_number(number);
	std::cout << number << '\n'; // number will now be 100 as we used & in parameter

	int a{ 10 }, b{ 4576 };
	std::cout << "A is " << a << " and B is " << b << '\n';
	swap(a, b);
	std::cout << "A is " << a << " and B is " << b << '\n'; // numbers have swapped

	std::vector my_vector{ 123, 456, 789 };
	print_vector_ref(my_vector);

	// scope
	int num{ 100 };
	int num2{ 500 };
	std::cout << "Local num is: " << num << '\n';

	{
		int num{ 200 }; // new level of scope
		std::cout << "Local num is: " << num << '\n';
	}

	static_local_example(); // 5000 6000
	static_local_example(); // 6000 7000

	std::cout << factorial(8) << '\n';
	std::cout << fibonacci(30) << '\n';
}

// Modulaize Section 9 challenge with functions
void Section11_Challenge()
{
	std::vector<int> numbers;
	char choice{};

	do
	{
		print_choices();
		request_input(choice);
		execute_choice(choice, numbers);

		std::cout << "\n-------------------------------\n";
	}
	while (choice != 'Q' && choice != 'q');
}

// Pointers and References
void Section12()
{
	/*
	*  address-of operator & and dereference operator * acts as opposites
	*  & gets the address of an object
	*  * gets the objects at an address
	*  type* -> address that stores object of type type
	*/

	// Always initialize pointers before you use them
	// variable_type* pointer_name;
	//int* int_ptr;                   // pointer to an integer -> will contain garbage data as it is unintialized
	double* double_ptr{nullptr};      // pointer to a double
	char* char_ptr{nullptr};          // pointer to a char
	std::string* string_ptr{nullptr}; // pointer to a C++ style string

	std::cout << "Value of double_ptr is: " << double_ptr << '\n';
	std::cout << "sizeof double_ptr is: " << double_ptr << '\n'; // pointers are all size 4

	int num{ 10 };
	std::cout << "Value of num is: " << num << '\n';
	std::cout << "sizeof num is: " << sizeof num << '\n';
	std::cout << "Address of num is: " << &num << '\n';

	int score{ 100 };
	double high_temp{ 100.7 };
	double low_temp{ 37.2 };

	int* score_ptr{ nullptr };
	double* temp_ptr{ nullptr };

	score_ptr = &score;
	//score_ptr = &high_temp; // compile error - can't assign pointer for doube to pointer for int

	temp_ptr = &high_temp; // points to high temp
	temp_ptr = &low_temp;  // points to low temp

	temp_ptr = nullptr;

	std::vector<std::string>* vector_string_pointer{ nullptr };
	std::cout << "sizeof vector_string_pointer is: " << sizeof vector_string_pointer << '\n';
	std::cout << "sizeof temp_ptr is: " << sizeof temp_ptr << '\n';

	std::cout << "Value of score is: " << score << '\n';
	std::cout << "Address of score is: " << &score << '\n';
	std::cout << "Value of score_ptr is: " << score_ptr << '\n'; // should equal to the above line

	std::cout << "-----------------------------------------------\n";

	// dereferencing a pointer -> access the data it points at
	std::cout << "Value of score at score_ptr is: " << *score_ptr << '\n';
	// I.e get the integer that score_ptr is pointing to and make it 200
	*score_ptr = 200; // Set the value the address is pointing to, to 200. 
	std::cout << "Value of score is at score_ptr is: " << *score_ptr << '\n';
	std::cout << "Value of score is: " << score << '\n';

	temp_ptr = &high_temp;
	std::cout << "Value that temp_ptr is pointing to is: " << *temp_ptr << '\n';
	temp_ptr = &low_temp;
	std::cout << "Value that temp_ptr is pointing to is: " << *temp_ptr << '\n';

	std::string name{ "Frank" };
	std::string* string_ptr2{ &name };

	std::cout << *string_ptr2 << '\n';
	name = "James";
	std::cout << *string_ptr2 << '\n';

	std::cout << "-----------------------------------------------\n";


	// Dynamic Memory Allocation
	/*
	*  Allocate an integer onto the heap with new int
	*  Allocated data will contain garbage (some random integer)
	*  Only way to access it is via the pointer
	*/
	int* int_ptr{ nullptr };
	int_ptr = new int;
	
	std::cout << int_ptr << '\n'; // some address
	std::cout << *int_ptr << '\n'; // some random integer

	*int_ptr = 100;

	std::cout << *int_ptr << '\n'; // 100

	delete int_ptr; // free up allocated storage after we're done. Make sure the deleted storage was one we allocated with new

	// allocate storage for an array
	int* array_ptr{ nullptr };
	int size{5}; // array of size 5

	array_ptr = new int[size]; // allocate array on the heap

	delete[] array_ptr; // release the memory back onto the heap

	// pointer to an array and array name can almost always be used interchangeably
	int scores[]{ 100, 95, 99, 89, -1 };
	std::cout << scores << '\n';  // print address
	std::cout << *scores << '\n'; // prints the object at the address of scores i.e the first item 100

	int* scores_ptr{ scores };
	std::cout << scores_ptr << '\n';  // same address as above
	std::cout << *scores_ptr << '\n'; // same item as above

	std::cout << scores_ptr[0] << " is the same as " << scores[0] << '\n';
	std::cout << scores_ptr[1] << " is the same as " << scores[1] << '\n';
	std::cout << scores_ptr[2] << " is the same as " << scores[2] << '\n';

	/*
	*  Show address of first item
	*  Show address of second item 
	*  Adding 1 does not add 1 to the address, it adds size of 1 integer to the address
	*  So it adds 4 byte as the next integer is 4 bytes away
	*/

	std::cout << "Size of integer is: " << sizeof score << '\n';

	std::cout << "Address of 1st item in array: " << scores_ptr << '\n';   
	std::cout << "Address of 2nd item in array: " << (scores_ptr + 1) << '\n'; // 4 more than the previous
	std::cout << "Address of 3rd item in array: " << (scores_ptr + 2) << '\n'; // 4 more than the previous

	// Will do the same thing since scores array is already the address
	std::cout << "Value at " << scores_ptr << " is " << *scores << '\n';
	std::cout << "Value at " << (scores_ptr + 1) << " is " << *(scores + 1) << '\n';
	std::cout << "Value at " << (scores_ptr + 2) << " is " << *(scores + 2) << '\n';


	std::cout << "-----------------------------------------------\n";

	// Pointer Arithmetic
	
	/*
	*  Only makes sense for raw arrays
	*  ++ increments the pointer to the next item in the address (for int, it moves by 4 bytes)
	*  -- decrements the pointer to the previuos item in the address (for int, it moves by 4 bytes)
	*/
	
	while (*scores_ptr != -1)
	{
		std::cout << *scores_ptr << '\n';
		scores_ptr++; 
	}

	scores_ptr = scores;

	// does the same as above
	while (*scores_ptr != -1)
	{
		std::cout << *scores_ptr++ << '\n'; // increments the pointer, not the pointer value
	}

	std::string s1{ "Frank" };
	std::string s2{ "Frank" };
	std::string s3{ "Jimmy" };

	std::string* p1{ &s1 };
	std::string* p2{ &s2 };
	std::string* p3{ &s1 };

	std::cout << std::boolalpha;
	std::cout << p1 << "==" << p2 << ": " << (p1 == p2) << '\n';      // false as they point to different addresses
	std::cout << p1 << "==" << p3 << ": " << (p1 == p3) << '\n';      // true as they point to the same address
	std::cout << *p1 << "==" << *p2 << ": " << (*p1 == *p2) << '\n';  // true as we are comparing the same values
	std::cout << *p1 << "==" << *p2 << ": " << (*p1 == *p3) << '\n';  

	p3 = &s3;
	std::cout << *p1 << "==" << *p3 << ": " << (*p1 == *p3) << '\n';  // now false as p3 points to different address

	std::string stuffs[] {"Jimmy", "Barry", "Andy", "Karry", "Jameson"};

	std::string* name_ptr1{ nullptr };
	std::string* name_ptr2{ nullptr };

	name_ptr1 = &stuffs[0]; // Jimmy
	name_ptr2 = &stuffs[3]; // Karry

	// Use pointer1 - pointer2 to find the distance in the stack between the two items
	std::cout << "In the array, " << *name_ptr2 << " is " << (name_ptr2 - name_ptr1) << " items away from " << *name_ptr1 << '\n';

	// pointers to constants
	int high_score{ 100 };
	int low_score{ 65 };
	const int* some_score_ptr{ &high_score }; // pointer itself can change, but data pointed at cannot be changed
	//*some_score_ptr = 86; // Error 
	some_score_ptr = &low_score;

	// constant pointers
	int* const const_score_ptr{ &high_score }; // pointer itself is constant, but data pointed at can change
	*const_score_ptr = 86; // okay
	//const_score_ptr = &low_score; // Error

	// constant pointer to constant
	const int* const const_score_const_ptr{ &high_score }; // pointer and data are both constant
	//*const_score_const_ptr = 86; // Error
    //const_score_const_ptr = &low_score; // Error

	std::cout << "-----------------------------------------------\n";
	
	int value{ 10 };
	std::cout << value << '\n';
	double_data(&value); // double the data stored at the address of value
	std::cout << value << '\n';
	double_data(&value); // double the data again stored at the address of value
	std::cout << value << '\n';

	int x{ 100 };
	int y{ 200 };
	std::cout << "x is: " << x << '\n';
	std::cout << "y is: " << y << '\n';

	swap_12(&x, &y);

	std::cout << "x is: " << x << '\n';
	std::cout << "y is: " << y << '\n';

	std::cout << "-----------------------------------------------\n";

	std::vector<std::string> stooges{ "Larry", "Moe", "Curly" };
	display(&stooges);

	int scores2[]{ 100, 99, 48, 43, 53, 86, -1 };
	display(scores2, -1);

	x = 100;
	y = 200;

	int* largest_ptr{ nullptr };
	largest_ptr = largest_int(&x, &y);
	std::cout << *largest_ptr << '\n';

	int* my_array; // to be allocated by the function
	my_array = create_array(100, 20); // create array with size 100 and values 20
	
	// do array stuff
	my_array[15] = -1;
	display(my_array, -1);
	
	delete[] my_array; // release memory

	for (auto str : stooges) // adding const str will result in compile error
		str = "Funny"; // this changes a COPY of the vector element

	for (auto str : stooges)
		std::cout << str << '\n'; // Larry Moe Curly

	for (auto& str : stooges) // address-of operator
		str = "Funny"; // this changes the actual vector element

	for (auto str : stooges)
		std::cout << str << '\n'; // Funny Funny Funny

	std::cout << "-----------------------------------------------\n";

	/*
	*  L-values - values that have names and are addressable
	*  They are modifiable if not constant
	* 
	*  R-values - anything that's not an L-value
	*/

	int paul{ 100 }; // paul is an L-value
	paul = 1000;
	paul = 2000 + 20;

	std::string jason; // jason is an L-value
	jason = "Frank";

	//100 = x;         // 100 is not an L-value. not addressable
	//"Frank" = jason; // "Frank" is not an L-value, not addressable

	int& ref1 = paul; // ref1 is reference to L-value
	ref1 = 1000;
	std::cout << ref1 << '\n';

	//int& ref2 = 100; // Error, 100 is an R-value

	int num_something{ 10 };
	square(num); // okay
	//square(5); // Error - 5 is not an L-value
}

void Section12_Challenge()
{
	const size_t array1_size{ 5 };
	const size_t array2_size{ 3 };

	int array1[]{ 1, 2, 3, 4, 5 };
	int array2[]{ 10, 20, 30 };
	
	// careful of duplicate array names -> need to be clear or use namespaces
	std::cout << "Array 1: ";
	print_array_12(array1, array1_size);
	std::cout << "Array 2: ";
	print_array_12(array2, array2_size);

	int* results = apply_all(array1, array1_size, array2, array2_size);
	constexpr size_t result_size{ array1_size * array2_size };

	std::cout << "Result: ";
	print_array_12(results, result_size);
}

class Account13
{
private:
	// Attributes
	std::string name;
	double balance;

public:
	// Methods
	void set_balance(double bal);
	double get_balance();
	void deposit(double bal)
	{
		balance += bal;
	}

	void withdraw(double bal)
	{
		balance -= bal;
	}

	// Constructors
	Account13(){ };
	Account13(std::string name, double balance){ };
	Account13(std::string name){ };
	Account13(double balance){ };

	// Destructor
	~Account13(){ };
};

// implementing memeber methods outside of class declaration
void Account13::set_balance(double bal)
{
	balance = bal;
}

double Account13::get_balance()
{
	return balance;
}

void display_shallow(Shallow s) // copy constructor is called here
{
	std::cout << s.get_data_value() << '\n';
} // destructor for Shallow s is called here

void display_deep(Deep d) // copy constructor is called here
{
	std::cout << d.get_data_value() << '\n';
} // destructor for Deep d is called here

void func_lvalue(int& num)
{
	std::cout << num << '\n';
}

void func_rvalue(int &&num)
{
	std::cout << num << '\n';
}

void display_player_name(const Player& p)
{
	std::cout << p.get_name() << '\n';
}

void display_active_players()
{
	std::cout << "Active players: " << Player::get_num_players() << '\n';
}

// OOP
void Section13()
{
	display_active_players();
	Player jimmy;
	Player hero;
	Player andy{ "Andy", 10, 10 };
	Player mother{ "Mother" };

	// cannot access private acces 
	//jimmy.name = "Jimmy";
	//hero.name = "hero";

	jimmy.set_name("Jimmy");
	hero.set_name("Hero");

	// Issue here with using copy constructors?
	//Player players[]{ jimmy, hero };
	//std::vector<Player> players_vec{ jimmy };
	//players_vec.push_back(hero);

	Player* enemy{ nullptr };
	enemy = new Player;

	//(*enemy).name = "Enemy";
	//enemy->health = 800; // arrow operator, functions equivalent to above

	enemy->set_name("Enemy");

	jimmy.talk("I'm gonna kill you!");
	enemy->talk("Try your worst!");
	enemy->get_name();

	delete enemy; // Destructor called

	Player* enemy2{ nullptr };
	enemy2 = new Player("Enemy", 1000, 0);
	delete enemy2; // Destructor called

	display_active_players();

	std::cout << "-----------------------------------------------\n";

	{
		Player player;
		Player slayer("Slayer1");
		Player slayer2("Slayer2", 10);
		Player slayer3("Slayer3", 10, 100);
		display_active_players();

	} // Destructors called in reverse order they were created

	std::cout << "-----------------------------------------------\n";

	Account13 jimmy_account;
	//jimmy_account.name = "Frank's accouint";
	//jimmy_account.balance = 50000.0;
	jimmy_account.deposit(800);
	jimmy_account.withdraw(47976);

	std::cout << "-----------------------------------------------\n";

	Player to_be_copied{ "To Be Copied" };
	std::cout << "to_be_copied is called " << to_be_copied.get_name() << '\n';
	Player the_copier{ to_be_copied };
	std::cout << "the_copier is called " << the_copier.get_name() << '\n';
	
	display_active_players();

	std::cout << "-----------------------------------------------\n";

	// Shallow vs Deep copy constructors
	

	//Shallow obj1{ 100 };
	//display_shallow(obj1); // copy constructor called for function -> problem, data in obj1 will point to invalid memory 
	// will crash once destructor for Shallow is called!
	//Shallow obj2(obj1);
	//obj2.set_data_value(1000); // This also changes data for obj1 since they both point to same part of memory

	Deep obj1{ 100 };
	display_deep(obj1); // This will now run correctly as they are unique parts of the memory
	Deep obj2{ obj1 };
	obj2.set_data_value(1000);

	std::cout << "-----------------------------------------------\n";

	// Move Constructors
	int x{ 100 };
	int& l_ref = x;    // l-value reference
	l_ref = 10;        // change x to 10

	int&& r_ref = 200; // r-value ref
	r_ref = 300;       // change r_ref to 300

	//int&& x_ref = x; // Compile error

	func_lvalue(l_ref);
	//func_lvalue(200); // Error - only take L-values

	//func_rvalue(l_ref); // Error - only take R-values
	func_rvalue(200);

	std::vector<Move> vec;

	// Constructor for Move(int) is called
	// then move constructor is used for vec as Move{10} is an R-value
	// No more deep copies then destroying data - inefficient 
	vec.push_back(Move{ 10 }); 
	vec.push_back(Move{ 20 }); 
	vec.push_back(Move{ 30 }); 
	vec.push_back(Move{ 40 }); 
	vec.push_back(Move{ 50 }); 
	vec.push_back(Move{ 60 }); 
	vec.push_back(Move{ 70 }); 
	vec.push_back(Move{ 80 }); 

	std::cout << "-----------------------------------------------\n";

	const Player villain{ "Villain", 100, 55 };
	Player heroine{ "Heroine", 100, 15 };
	//villain.set_name("Vile"); // Error - can't change villain attributes
	std::cout << villain.get_name() << '\n'; // Fine, since get name is declared const
	display_player_name(heroine);
	display_active_players();

	std::cout << "-----------------------------------------------\n";

} // All destructors called

// Movie and movies
void Section13_Challenge()
{
	Movies my_movies;
	my_movies.display_movies();

	my_movies.create_movie("John Wick", Movie::Rating::R);
	my_movies.display_movies();
	my_movies.add_movie("Teletubbies", Movie::Rating::PG, 5400);
	my_movies.display_movies();
	my_movies.display_movies();
	my_movies.watch_movie("John Wick");

	// Negative cases
	my_movies.watch_movie("John Wack");
	my_movies.create_movie("John Wick", Movie::Rating::R);
	my_movies.create_movie("Teletubbies", Movie::Rating::R);
	my_movies.add_movie("John Wick", Movie::Rating::G, 20);
}

// Operator Overloading as global function
// Similar to overloaded member function except we have lhs instead of this 
// This works because we have friend keywork in Mystring.h
Mystring operator+(const Mystring& lhs, const Mystring& rhs)
{
	char* buff = new char[std::strlen(lhs.get_str()) + std::strlen(rhs.get_str()) + 1];
	std::strcpy(buff, lhs.get_str());
	std::strcat(buff, rhs.get_str());
	Mystring temp{ buff };
	delete[] buff;
	return temp;
}

// Overloading Operators 
void Section14()
{
	Mystring empty;            // no-args constructor
	Mystring larry{ "Larry" }; // overload constructor
	Mystring stooge{ larry };  // copy constructor

	empty.display();
	larry.display();
	stooge.display();

	Mystring s1{ "Frank" };
	Mystring s2 = s1; // NOT assignment - same as Mystring s2{s1}
	Mystring s3;

	// copy assignment
	s3 = s1; // b.operator=(a)
	s1 = s2;
	s2 = s3;

	// move assignment
	s3 = "This is a test"; // b.operator=("This is a test");

	Mystring hello{ "Hello" };  // Overloaded constructor
	hello = Mystring{ "Hola" }; // Overloaded constructor then move assignment
	hello = "Bonjour";          // Overloaded constructor then move assignment

	std::cout << "==========================================\n";

	// other operators
	s1 = "S1";
	s2 = "S2";
	s3 = "S1";

	s1.display();
	s1 = -s1; // unary minus
	s1.display();

	std::cout << (s1 == s2) << '\n'; // comparison
	std::cout << (s1 == s3) << '\n';

	s3 = s1 + s2;
	s3.display();

	s1 = "Moe" + s3; // Will only work with overloaded global function
	s1.display();
	s1 = s3 + "Moe"; // OK, can add Moe from the left
	s1.display();

	std::cout << "==========================================\n";

	Mystring jimmy{ "Jimmy" };
	Mystring andy{ "Andy" };
	Mystring ruby;

	std::cout << "Enter the third stooge's first name ";
	std::cin >> ruby;

	std::cout << "The three stooges are " << jimmy << ", " << andy << ", and " << ruby << '\n';
	std::cout << "Enter the three stooges names separated by a space: ";
	std::cin >> jimmy >> andy >> ruby;
	std::cout << "The three stooges are " << jimmy << ", " << andy << ", and " << ruby << '\n';
}

// Public Inheritance (no private or protected inheritance)
void Section15()
{
	std::cout << "\n================== Account ==================\n\n";
	Account acc{};
	acc.deposit(2000);
	acc.withdraw(500);

	std::cout << '\n';

	Account* p_acc{ nullptr };
	p_acc = new Account();
	p_acc->deposit(1000);
	p_acc->withdraw(500);
	delete p_acc;
	
	std::cout << "\n======================= double Parameter =========================\n\n";
	Account acc_2{ 3.6 };
	acc.deposit(2000);
	acc.withdraw(500);

	std::cout << "\n======================= string Parameter =========================\n\n";
	Account acc_3{ "Johnson" };
	acc.deposit(2000);
	acc.withdraw(500);

	std::cout << "\n================== Savings Account ==================\n\n";
	// Account (Base class) is created before Savings Account (Derived class)
	Savings_Account sav_acc{};
	sav_acc.deposit(2000);
	sav_acc.withdraw(500);

	std::cout << '\n';

	Savings_Account* p_sav_acc{ nullptr };
	p_sav_acc = new Savings_Account();
	p_sav_acc->deposit(1000);
	p_sav_acc->withdraw(500);
	delete p_sav_acc; // Savings Account is destroyed before Account 

	Account* p = new Savings_Account(); // pointer thinks it's pointing to just an Account
	p->deposit(1000); // Will call Account::withdraw(), should be Savings_Account::withdraw() - Use Polymorphism

	std::cout << "\n====================== double Parameter ==========================\n\n";
	Savings_Account sav_acc_2{ 1.1 }; // will call no args base class constructor 
	sav_acc.deposit(2000);
	sav_acc.withdraw(500);
	
	std::cout << "\n====================== string Parameter ==========================\n\n";
	Savings_Account sav_acc_3{ "Kelly" }; // will call one-args string base class constructor 
	sav_acc.deposit(2000);
	sav_acc.withdraw(500);

	std::cout << "\n====================== Copy Constructor/Assignment ==========================\n\n";
	Account acc_4{ "Berthold" };
	Account acc_5 = acc_4;   // Copy Constructor
	acc_5 = acc;             // Copy Assignment


	Savings_Account sav_acc_4{ 5.8 };
	Savings_Account sav_acc_5{ sav_acc_4 }; // Copy Constructor
	sav_acc_4 = sav_acc_3;                  // Copy Assignemnt

	std::cout << "\n====================== Redfine Base Methods ==========================\n\n";
	Account a1{ 2000 };
	std::cout << a1 << '\n'; // Account balance: 2000
	a1.deposit(800);
	std::cout << a1 << '\n'; // Account balance: 2800
	a1.withdraw(1000);
	std::cout << a1 << '\n'; // Account balance: 1800
	a1.withdraw(8000); // Not enough funds
	std::cout << a1 << '\n'; // Account balance: 1800

	std::cout << "\n\n\n";

	Savings_Account s1{ 10.1 };
	std::cout << s1 << '\n';
	s1.deposit(1000);
	std::cout << s1 << '\n'; // Account balance: 1101
	s1.withdraw(500);
	std::cout << s1 << '\n'; // Account balance: 601
	s1.withdraw(8000); // Not enough funds
	std::cout << s1 << '\n'; // Account balance: 601

	std::cout << "\n================== End of scope ==================\n\n";

}

void do_something_wrong(Account account)
{
	account.say_something();
}

void do_something(Account& account)
{
	account.say_something();
}

std::ostream& operator<<(std::ostream& os, const IPrintable& obj)
{
	obj.print(os);
	return os;
}

void print(const IPrintable& obj)
{
	std::cout << obj << '\n';
}

// Polymorphism - i.e virtual functions
void Section16()
{
	std::cout << "\n==== Pointers ====\n\n";
	Account* p1 = new Account();
	Account* p2 = new Savings_Account();

	p1->deposit(1000);
	p2->deposit(1000); // deposit not marked as virtual, will use Account::deposit

	p1->withdraw(100);
	p2->withdraw(100); // withdraw marked as virtual, will use Savings_Account::withdraw

	std::cout << "\n==== Redefinition ====\n\n";

	p1->say_hello();
	p2->say_hello(); // will use Account::say_hello due to redefinition
	
	std::cout << "\n==== Overriding ====\n\n";

	// override ensures we override the virtual function, not redefine it
	p1->say_something();
	p2->say_something(); // will now use Savings_Account::say_something due override

	std::cout << "\n==== Base Class References ==== \n\n";

	Account a;
	Account& ref = a;
	ref.say_something();

	Savings_Account s;
	Account& ref1 = s;
	ref1.say_something();

	do_something_wrong(a); 
	do_something_wrong(s); // This will use Account::say_something

	do_something(a);
	do_something(s); // This wil use Savings_Account::say_something

	std::cout << "\n==== Abstract Class ==== \n\n";

	//Shape p;                // Compile error - cannot instantiate abstract class
	//Shape* p = new Shape(); // Compile error - cannot instantiate abstract class

	Shape* ptr = new Circle();
	ptr->draw();
	ptr->rotate();

	Shape* s1 = new Circle();
	Shape* s2 = new Square();

	std::vector<Shape*> shapes{ s1, s2};
	for (const auto p : shapes)
		p->draw();

	std::cout << "\n==== Interfaces ==== \n\n";
	
	std::cout << *s1 << '\n'; // Using IPrintable to print these things
	std::cout << *s2 << '\n';

	print(*s1);
	print(*s2);

	std::cout << "\n======================\n\n";

	delete s1;
	delete s2;
	delete ptr;
	delete p1; 
	delete p2;
}

class B; // forward declaration
class B_Weak;

class A
{
	std::shared_ptr<B> b_ptr;         // make weak to break strong circular reference
	std::weak_ptr<B_Weak> b_weak_ptr; // now there will be no memory leak
public:
	void set_B(std::shared_ptr<B>& b)
	{
		b_ptr = b;
	}

	void set_B_weak(std::shared_ptr<B_Weak>& b)
	{
		b_weak_ptr = b;
	}

	A() { std::cout << "A Constructor" << '\n'; }
	~A() { std::cout << "A Destructor" << '\n'; }
};

class B
{
	std::shared_ptr<A> a_ptr;
public:
	void set_A(std::shared_ptr<A>& a)
	{
		a_ptr = a;
	}

	B() { std::cout << "B Constructor" << '\n'; }
	~B() { std::cout << "B Destructor" << '\n'; }
};

class B_Weak
{
	std::shared_ptr<A> a_ptr;
public:
	void set_A(std::shared_ptr<A>& a)
	{
		a_ptr = a;
	}

	B_Weak() { std::cout << "B_Weak Constructor" << '\n'; }
	~B_Weak() { std::cout << "B_Weak Destructor" << '\n'; }
};

class Test
{
private:
	int data;

public:
	Test() : data{0} { std::cout << "Test Constructor: " << data << '\n'; }
	Test(int data) : data{data} { std::cout << "Test Constructor: " << data << '\n'; }
	int get_data() const { return data; }
	~Test() { std::cout << "Test Destructor: " << data << '\n'; }
};

void my_deleter(Test* ptr)
{
	std::cout << "Using my custom function deleter" << '\n';
	delete ptr;
}

// Smart pointers
void Section17()
{
	std::cout << "\n====== unique pointers ======\n\n";

	/*
	*  unique_ptr
	*  Points to an object on the heap
	*  Unique - can only be one pointing to the object
	*  Owns the object it points to
	*  Cannot be assigned or copied
	*  Can be moved
	*  When destroyed, also destroyed what it points to
	*/


	{
		std::unique_ptr<int> p1{ new int {100} };
		std::cout << *p1 << '\n';
		*p1 = 200;
		std::cout << *p1 << '\n';
		std::cout << p1.get() << '\n'; // Gets the address
		p1.reset(); // now nullptr
		std::cout << p1.get() << '\n'; // Gets the address

		if (p1)
			std::cout << *p1 << '\n'; // won't execute
	} // automatically deleted here

	std::unique_ptr<Account> p1{ new Account{"Jimmy"} };
	std::cout << *p1 << '\n';

	p1->deposit(1000);
	p1->withdraw(200);

	std::vector<std::unique_ptr<int>> vec;
	std::unique_ptr<int> ptr{ new int {100} };
	//vec.push_back(ptr); // ERROR - copy not allowed!
	vec.push_back(std::move(ptr));

	// better way to make unique pointers - no new or delete
	std::unique_ptr<int> p2 = std::make_unique<int>(100); 
	std::unique_ptr<Account> p3 = std::make_unique<Account>("Jimmy");
	auto p4 = std::make_unique<Player>("Hero", 100, 100);
	auto p5 = std::make_unique<Player>("Jimmy", 100, 100);

	//p4 = p5; // ERROR - cannot be assigned
	p4 = std::move(p5); // Fine - moving ownership is okay - issues with counting number of players though

	if (!p5)
		std::cout << "p5 is nullptr\n";

	std::vector<std::unique_ptr<Account>> accounts;

	accounts.push_back(std::make_unique<Account>("Billiamson"));
	accounts.push_back(std::make_unique<Savings_Account>("Jefferson"));
	accounts.push_back(std::make_unique<Account>("Rodney"));
	accounts.push_back(std::make_unique<Savings_Account>("Carling"));

	//for (auto acc : accounts) // Error here since we can't copy
	//	std::cout << *acc << '\n';

	for (const auto& acc : accounts)
		acc->say_something();

	std::cout << "\n====== shared pointers ======\n\n";

	/*
	*  shared_ptr
	*  Points to an object on the heap
	*  Not unique, many shared_ptr to the same object on heap
	*  Shared ownership relationship
	*  CAN be assigned and copied and moved
	*  Doesn't support managing arrays by default
	*  Object on heap destroyed when use count is zero
	*/

	{
		std::shared_ptr<int> p1{ new int {100} };
		std::cout << *p1 << '\n';
		*p1 = 200;
		std::cout << *p1 << '\n';

		std::cout << p1.use_count() << '\n'; // 1 shared_ptr managing heap object 
		std::shared_ptr<int> p2 { p1 };      // shared ownership
		std::cout << p1.use_count() << '\n'; // 2
		std::cout << p2.use_count() << '\n'; // 2

		p1.reset(); // decrement use_count and null out p1
		std::cout << p1.use_count() << '\n'; // 0
		std::cout << p2.use_count() << '\n'; // 1


	} //automatically deleted here

	std::shared_ptr<Account> s1{ new Savings_Account{"Jimothiy"}};
	s1->say_something();

	std::vector<std::shared_ptr<int>> ints;

	std::shared_ptr<int> int_ptr{ new int {100} };
	ints.push_back(int_ptr); // OK - copy is allowed for shared_ptr

	std::cout << int_ptr.use_count() << '\n'; // 2 since we copied it into the vector

	std::shared_ptr<int> int1 = std::make_shared<int>(100); // use_count: 1
	std::shared_ptr<int> int2 = { int1 };                   // use_count: 2
	std::shared_ptr<int> int3;
	int3 = int2;                                            // use_count: 3

	std::cout << int1.use_count() << '\n';

	std::shared_ptr<Account> acc1 = std::make_shared<Savings_Account>(978.43);
	std::shared_ptr<Account> acc2 = std::make_shared<Account>(87456923876.37);
	std::shared_ptr<Account> acc3 = std::make_shared<Savings_Account>(274356.262);
	std::shared_ptr<Account> acc4 = std::make_shared<Account>(54.0);

	std::vector<std::shared_ptr<Account>> accounts2;
	accounts2.push_back(acc1);
	accounts2.push_back(acc2);
	accounts2.push_back(acc3);
	accounts2.push_back(acc4);

	accounts2.push_back(acc1);
	accounts2.push_back(acc2);
	accounts2.push_back(acc3);
	accounts2.push_back(acc4);

	for (const auto& acc : accounts2)
	{
		acc->say_something();
		std::cout << "Use count: " << acc.use_count() << '\n';
	}

	std::cout << "\n====== weak pointers ======\n\n";

	/*
	*  weak_ptr
	*  Non-owning "weak" pointer
	*  Points to an object on the heap
	*  Does not participate in owning relationship
	*  Always created from a shared_ptr
	*  Does not increment or decrement reference use count
	*  Used to prevent strong reference cycles which could prevent objects from being deleted
	*/

	{
		std::shared_ptr<A> a = std::make_shared<A>();
		std::shared_ptr<B> b = std::make_shared<B>();
		a->set_B(b);
		b->set_A(a); // establishing circular reference 
	} // Destructors of A and B will not be called - Memory leak! 

	std::cout << '\n';

	{
		std::shared_ptr<A> a = std::make_shared<A>();
		std::shared_ptr<B_Weak> b = std::make_shared<B_Weak>();
		a->set_B_weak(b);
		b->set_A(a); // establishing circular reference 
	} // Destructors will be called since we have a weak pointer

	std::cout << "\n====== Custom Deleters ======\n\n";

	// For when we want to do more than just destroy object on heap

	{
		std::shared_ptr<Test> ptr{ new Test{} };
	} // using default destructor

	{
		std::shared_ptr<Test> ptr{ new Test{100}, my_deleter };
	} // using custom deleter

	
	{
		std::shared_ptr<Test> ptr(new Test{ 1000 },
			[](Test* ptr) // [] is the lambda function
			{
				std::cout << "Using my custom lambda deleter\n";
				delete ptr;
			});
	} // using lambda expression

	std::cout << "\n======================\n\n";

}

// Can we shorten this?
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make(); 
void fill(std::vector<std::shared_ptr<Test>>& vec, int num);
void display(const std::vector<std::shared_ptr<Test>>& vec);


void Section17_Challenge()
{
	std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
	vec_ptr = make();
	std::cout << "How many data points do you want to enter: ";
	int num;
	std::cin >> num;
	fill(*vec_ptr, num);
	display(*vec_ptr);
}

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make()
{
	return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::vector<std::shared_ptr<Test>>& vec, int num)
{
	for (int i{ 0 }; i < num; i++)
	{
		std::cout << "Enter data point " << i + 1 << ": ";
		int input;
		std::cin >> input;
		vec.push_back(std::make_shared<Test>(input));
	}
}

void display(const std::vector<std::shared_ptr<Test>>& vec)
{
	std::cout << "\nDisplaying vector data\n==================\n";

	for (const auto& sp_test : vec)
	{
		std::cout << sp_test->get_data() << '\n';
	}

	std::cout << "==================\n";
}

class DivideByZeroException{ };
class NegativeValueException{ };

double calculate_mpg(int miles, int gallons)
{
	if (gallons == 0)
		throw DivideByZeroException{};

	if (miles < 0 || gallons < 0)
		throw NegativeValueException{};

	return static_cast<double>(miles) / gallons;
}



// Exception Handling
void Section18()
{
	int miles{};
	int gallons{};
	double miles_per_gallon{};

	std::cout << "Enter the miles: ";
	std::cin >> miles;
	std::cout << "Enter the gallons: ";
	std::cin >> gallons;

	//miles_per_gallon = miles / gallons; // will crash
	//miles_per_gallon = static_cast<double>(miles) / gallons; // will give infinity and not crash

	/*
	*  Stack Unwinding
	*  If exception is thrown with no try-catch block in function
	*  Call stack will unwind until a handler is found or program terminates
	*  Will not execute rest of function
	*  -> May lead to memory leak if things in the function aren't handled right
	*  -> i.e not deleting pointers 
	*/

	try
	{
		if (gallons == 0)
			throw DivideByZeroException{}; // Best practice to throw object, not integer

		miles_per_gallon = static_cast<double>(miles) / gallons;
		std::cout << "Result: " << miles_per_gallon << '\n';
	}
	catch (DivideByZeroException& ex) // catch by reference
	{
		std::cerr << "Sorry, can't divide by zero\n";
	}

	std::cout << "\n===============\n\n";

	try
	{
		miles_per_gallon = calculate_mpg(miles, gallons); // Throw exception from function
		std::cout << "Result: " << miles_per_gallon << '\n';
	}
	catch (DivideByZeroException& ex)
	{
		std::cerr << "Tried to divide by 0\n";
	}
	catch (NegativeValueException& ex) // handle multiple exceptions
	{
		std::cerr << "Negative value error" << '\n';
	}
	catch (...)
	{
		std::cerr << "Unknown exception\n"; // catch all exception
	}

	std::cout << "\n===============\n\n";

	if (gallons != 0)
	{
		miles_per_gallon = static_cast<double>(miles) / gallons;
		std::cout << "Result: " << miles_per_gallon << '\n';
	}
	else
	{
		std::cerr << "Sorry, can't divide by zero\n";
	}
	
	std::cout << "\n===============\n\n";

	try
	{
		std::unique_ptr<Account> my_account = std::make_unique<Account>(-0.3);
		std::cout << *my_account << '\n';
	}
	catch (const IllegalBalanceException& ex)
	{
		std::cerr << ex.what() << '\n';
	}

	try
	{
		std::unique_ptr<Account> my_account = std::make_unique<Savings_Account>(-0.3);
		my_account->say_something();
	}
	catch (const IllegalFundsException& ex)
	{
		std::cerr << ex.what() << '\n';
	}


	std::cout << "\n===============\n\n";

	std::cout << "Bye\n";
}