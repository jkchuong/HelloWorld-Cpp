#include "HelloWorld.h" // Source files should #include their paired header file (if one exists)
#include "Calculator.h" // These are directives (or preprocessor directive) -> includes (copies) the contents of these files to be compiled
#include "io.h"
#include <iostream>     // Angled brackets for header files we didn't make. Quotes does files we make.
#include <cstdint>      // for int_least#_t
#include <iomanip>      // for output manipulator std::setprecision()
#include <string>       // allows use of std::string for C++ Strings
#include <string_view>
#include <vector>       // for using vectors
#include <iomanip>      // IO manipulation
#include <cctype>       // for character-based functions
#include <cstring>      // Functions that work with C-style strings
#include <cstdlib>      // General purpose functions e.g convert C-style strings to other types (int, float, long, etc)

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

	Section10();

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