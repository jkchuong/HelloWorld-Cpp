#include "Section11.h"

// need to pass size as we don't know array size in c
void print_array(int arr[], size_t size)
{
	for (size_t i{ 0 }; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << '\n';

	arr[0] = 50000; // this would change the actual array, could be a bug
}

// use const to prevent array from being changed
void print_array_const(const int arr[], size_t size)
{
	for (size_t i{ 0 }; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << '\n';

	//arr[0] = 50000; // this would give compile error since we can no longer change the array
}

// we are passing in array reference so this changes the actual array and not a copy
void set_array(int arr[], size_t size, int value)
{
	for (size_t i{ 0 }; i < size; i++)
	{
		arr[i] = value;
	}
}

// ampersand in front of variable will reference actual parameter, not a copy
void scale_number(int& num)
{
	if (num > 100)
		num = 100;
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// Pass by value - vector will be copied so original vector remains unchanged - can be inefficient
void print_vector(std::vector<int> v)
{
	for (auto num : v)
		std::cout << num << '\n';
}

// Pass by const reference - vector will not be copied over and it cannot be changed 
// The & is the addres-of operator
void print_vector_ref(const std::vector<int>& v)
{
	for (auto num : v)
		std::cout << num << '\n';
}

// This has local scope but retains its value even after function ends
// static so it only initializes once and stays there
void static_local_example()
{
	static int num{ 5000 }; // i.e prints 5000 then 6000, second time it's run it prints 6000 then 7000
	std::cout << "Local static num is: " << num << " in start\n";
	num += 1000;
	std::cout << "Local static num is: " << num << " in end\n";
}

// will suggest to compiler to inline the function and could make code faster
// compilers will likely inline without your suggestion
inline int add_numbers(int a, int b)
{
	return a + b;
}

// recursive functions calls itself either directly or indirectly
unsigned long long factorial(unsigned long long n)
{
	if (n == 0) // base case - will stop the recursion
		return 1;

	return n * factorial(n - 1); // recursive
}

// infinite recursion will result in stack overflow error
unsigned long long fibonacci(unsigned long long n)
{
	if (n <= 1) // base case
		return n;

	return fibonacci(n - 1) + fibonacci(n - 2); // recursion
}

void print_numbers(std::vector<int>& numbers, int& retflag)
{
	retflag = 1;
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

	{
		retflag = 2; return;
	};
}

void add_number(std::vector<int>& numbers, int& retflag)
{
	retflag = 1;
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

	{
		retflag = 2; return;
	};
}

void calculate_mean(std::vector<int>& numbers, int& retflag)
{
	retflag = 1;
	if (numbers.size() == 0)
	{
		std::cout << "Unable to calculate the mean - no data.\n";
		{
			retflag = 2; return;
		};
	}


	int total{};

	for (auto number : numbers)
		total += number;

	std::cout << "The mean is: " << (static_cast<double>(total) / numbers.size()) << '\n';

	{
		retflag = 2; return;
	};
}


void find_largest(std::vector<int>& numbers, int& retflag)
{
	retflag = 1;
	if (numbers.size() == 0)
	{
		std::cout << "Unable to find smallest- no data.\n";
		{
			retflag = 2; return;
		};
	}

	// initialize with first number so we have something to compare to
	int largest{ numbers.at(0) };

	for (auto number : numbers)
	{
		// get the larger number of the comparison
		largest = ((number > largest) ? number : largest);
	}

	std::cout << "The largest number is " << largest << '\n';

	{
		retflag = 2; return;
	};
}

void find_smallest(std::vector<int>& numbers, int& retflag)
{
	retflag = 1;
	if (numbers.size() == 0)
	{
		std::cout << "Unable to find smallest- no data.\n";
		{
			retflag = 2; return;
		};
	}

	// initialize with first number so we have something to compare to
	int smallest{ numbers.at(0) };

	for (auto number : numbers)
	{
		// get the smaller number of the comparison
		smallest = ((number < smallest) ? number : smallest);
	}

	std::cout << "The smallest number is " << smallest << '\n';

	{
		retflag = 2; return;
	};
}

void execute_choice(char choice, std::vector<int>& numbers)
{
	switch (choice)
	{
	case 'P':
	case 'p':
	{
		int retflag;
		print_numbers(numbers, retflag);
		if (retflag == 2) break;
	}

	case 'A':
	case 'a':
	{
		int retflag;
		add_number(numbers, retflag);
		if (retflag == 2) break;
	}

	case 'M':
	case 'm':
	{
		int retflag;
		calculate_mean(numbers, retflag);
		if (retflag == 2) break;
	}

	case 'S':
	case 's':
	{
		int retflag;
		find_smallest(numbers, retflag);
		if (retflag == 2) break;
	}

	case 'L':
	case 'l':
	{
		int retflag;
		find_largest(numbers, retflag);
		if (retflag == 2) break;
	}

	case 'Q':
	case 'q':
		std::cout << "Goodbye\n";
		break;

	default:
		std::cout << "Unknown selection, please try again.\n";
	}
}

void request_input(char& choice)
{
	std::cout << "Enter your choice: ";
	std::cin >> choice;
}

void print_choices()
{
	std::cout << "P - Print numbers\n";
	std::cout << "A - Add a number\n";
	std::cout << "M - Display mean of the numbers\n";
	std::cout << "S - Display the smallest number\n";
	std::cout << "L - Display the largest number\n";
	std::cout << "Q - Quit\n\n";
}











