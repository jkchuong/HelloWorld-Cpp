#include "HelloWorld.h" // Source files should #include their paired header file (if one exists)
#include "Calculator.h" // These are directives (or preprocessor directive) -> includes (copies) the contents of these files to be compiled
#include "io.h"
#include <iostream>     // Angled brackets for header files we didn't make. Quotes does files we make.
#include <cstdint>      // for int_least#_t
#include <iomanip>      // for output manipulator std::setprecision()
#include <string>       // allows use of std::string
#include <string_view>
#include <vector>       // for using vectors

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
	Section7_Challenge();


	return 0;
}

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
	bin - 0b1010;
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

// simulat ball dropped off a tower
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