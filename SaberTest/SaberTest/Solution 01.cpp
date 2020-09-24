#include "Solution 01.h"

void DecimalToBinary(int _decimal)
{
	if (!_decimal)
	{
		std::cout << 0 << std::endl;
		return;
	}


	bool negative = false;

	if (_decimal < 0)
	{
		negative = true;
		_decimal *= -1;
	}


	std::string binary;

	while (_decimal)
	{
		binary = std::to_string(_decimal % 2) + binary;
		_decimal /= 2;
	}

	if (!negative)
	{
		std::cout << binary << std::endl;
		return;
	}


	// Number is negtive, reversing bytes & +1
	std::string reversed;
	// int size is 32 bytes
	int positive_length = binary.length();
	int start_length = 32 - positive_length;
	for (int i = 0; i < start_length; ++i)
	{
		reversed += '1';
	}
	for (int i = 0; i < positive_length; ++i)
	{
		if (binary[i] == '1')
		{
			reversed += '0';
		}
		else
		{
			reversed += '1';
		}
	}

	// Addition of reversed & 1
	std::string negative_binary;
	bool is_added = false;
	for (int i = 0; i < 32; ++i)
	{
		if (!is_added)
		{
			if (reversed[31 - i] == '0')
			{
				negative_binary = '1' + negative_binary;
				is_added = true;
			}
			else
			{
				negative_binary = '0' + negative_binary;
			}
		}
		else
		{
			negative_binary = reversed[31 - i] + negative_binary;
		}
	}
	std::cout << negative_binary << std::endl;
	return;
}