#pragma once
#include <vector>
#include <iostream>

void print_array(int arr[], size_t size);
void print_array_const(int arr[], size_t size);
void set_array(int arr[], size_t size, int value);
void scale_number(int& num);
void swap(int& a, int& b);
void print_vector(std::vector<int> v);
void print_vector_ref(const std::vector<int>& v);
void static_local_example();
inline int add_numbers(int a, int b);
unsigned long long factorial(unsigned long long n);
unsigned long long fibonacci(unsigned long long n);

void print_numbers(std::vector<int>& numbers, int& retflag);
void add_number(std::vector<int>& numbers, int& retflag);
void calculate_mean(std::vector<int>& numbers, int& retflag);
void find_largest(std::vector<int>& numbers, int& retflag);
void find_smallest(std::vector<int>& numbers, int& retflag);
void execute_choice(char choice, std::vector<int>& numbers);
void request_input(char& choice);
void print_choices();
