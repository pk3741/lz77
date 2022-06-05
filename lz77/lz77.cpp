#include <iostream>
#include <vector>
#include <string>


std::vector<std::string> possSubstrings(const std::string& str, size_t length)
{
	std::vector<std::string> output;
	for (int i = 0; i < length; i++)
		for (int len = 1; len <= length - i; len++)
			output.push_back(str.substr(i, len));
	return output;
}

std::vector<std::string> possSubstringsFromZero(const std::string& str, size_t length)
{
	std::vector<std::string> output;
		for (int len = 1; len <= length; len++)
		{
			output.push_back(str.substr(0, len));
		}
	return output;
}

std::string longestSubstring(std::vector<std::string> a, std::vector<std::string> b)
{
	std::string output = "";
	for (size_t i = 0; i < a.size(); i++)
	{
		for (size_t j = 0; j < b.size(); j++)
		{
			if (a[i] == b[j])
			{
				if (a[i].length() > output.length()) output = a[i];
			}
		}
	}
	return output;

}

std::string shiftStr(const std::string& str, int npos)
{
	return str.substr(npos);
}

std::string longestSubstring(std::string a, std::string b)
{
	std::vector<std::string> avec;
	std::vector<std::string> bvec;

	std::string longest = "";
	for (int i = 0; i < a.length(); i++)
	{
		for (int len = 1; len <= a.length() - i; len++)
		{
			avec.push_back(a.substr(i, len));
		}
	}

	for (int i = 0; i < b.length(); i++)
	{
			bvec.push_back(b.substr(0, i));
	}

	for (int i = 0; i < avec.size(); i++)
	{
		for (int j = 0; j < bvec.size(); j++)
		{
			if (avec[i] == bvec[j])
			{
				if (avec[i].length() > longest.length())
				{
					if (avec[i].length() < 4)
					{
						longest = avec[i];
					}
				}
			}
		}
	}
	return longest;
}

int main()
{
   //encoding
	//init
	int choose = 0;
	std::cin >> choose;

	if (choose == 0)
	{
		std::string input;
		std::cout << "Dane wejsciowe: ";
		std::cin >> input;
		std::string output = "";
		/*
		std::string buffer = "";
		std::string coding = "xxxxx";
		int bufferSize = 4;
		for (int i = 0; i < bufferSize; i++)
		{
			buffer += input[0];
		}
		output += input[0];
		std::string working = buffer + input;
		while (working.length() >= 4)
		{
			std::cout << buffer << coding << std::endl;
			buffer = working.substr(0, bufferSize);
			coding = working.substr(bufferSize, working.length());
			std::string ls = longestSubstring(possSubstrings(buffer, bufferSize), possSubstringsFromZero(coding, bufferSize - 1));
			std::cout << "ls: " << ls << std::endl;
			size_t ls_pos = buffer.find(ls);
			if (ls_pos >= buffer.length()) ls_pos = 3;
			std::cout << "ls_pos: " << ls_pos << std::endl;
			size_t ls_length = ls.length();

			std::cout << "output: " << std::to_string(ls_pos) + std::to_string(ls_length) + coding[ls.length()] << std::endl;
			output += std::to_string(ls_pos) + std::to_string(ls_length) + coding[ls.length()];
			if (coding.length() == 1) output += coding;
			working = shiftStr(working, (int)ls_length + 1);
			std::cout << "==================\n";
		}
		std::cout << "Output: " << output << std::endl;*/
		int bufferSize = 4;
		std::string dict = "";
		for (int i = 0; i < bufferSize; i++)
		{
			dict += input[0];
		}
		std::cout << "output: " << input[0] << std::endl;
		output += input[0];

		std::string buffer = input;

		std::cout << "=================================\n";
		while (buffer.length() > 0)
		{
			std::cout << "dict/bufer: " << dict << "/";
			std::cout << buffer << std::endl;

			std::string longest = longestSubstring(dict, buffer);
			std::cout << "longest substring of them: " << longest << std::endl;
			int position_in_dict = (int)dict.find(longest);
			std::cout << "Position_in_dict: " << position_in_dict << std::endl;
			int position_in_buffer = (int)buffer.find(longest);
			std::cout << "Position_in_buffer: " << position_in_buffer << std::endl;
			int length = (int)longest.length();
			std::cout << "Length: " << length << std::endl;
			int next_position = position_in_buffer + length;
			std::cout << "Next position: " << next_position << std::endl;
			char next = buffer[next_position];
			std::cout << "Next char: " << next << std::endl;
			std::string coder_output = std::to_string(position_in_dict) + std::to_string(length) + next;
			std::cout << "Coder output: " << coder_output << std::endl;
			output += coder_output;
			dict = dict + buffer.substr(0, length + 1);
			dict = shiftStr(dict, length + 1);
			std::cout << "newdict: " << dict << std::endl;
			buffer = shiftStr(buffer, length + 1);
			std::cout << "newbuffer: " << buffer << std::endl;
			std::cout << "input: " << input << std::endl;
			std::cout << "buffer.lenght: " << buffer.length() << std::endl;
			if (length > 0 && buffer.length() - 1 > 1)
			{
				if(input.length()>0)
					input = shiftStr(input, 4);
			}
			else if (buffer.length() - 1 > 1)
			{
				if (input.length() > 0)
				input = shiftStr(input, 1);
			}

			std::cout << "input: " << input << std::endl;
			std::cout << "buffer_length: " << buffer.length() << std::endl;
			int actual_buffer_length = buffer.length();
			for (int i = 0; i < 4 - actual_buffer_length; i++)
			{
				if(input.length()>0)
					buffer += input[i];
			}
			std::cout << "newbuffer: " << buffer << std::endl;
			std::cout << "======================================\n";
		}
		std::cout << "Output: " << output << std::endl;
	}
	else if(choose==1)
	{

		std::string input;
		std::cout << "Dane wejsciowe: ";
		std::cin >> input;
		std::string buffer = "XXXX";

		std::string output = "";
		std::string coding = "";
		for (int i = 0; i < 4; i++)
		{
			buffer[i] = input[0];
		}
		std::cout << "buffer: " << buffer << std::endl;
		input = shiftStr(input, 1);


		while (input.length()>1)
		{
			std::cout << input << std::endl;
			std::string actual = input.substr(0, 3);
			std::cout << actual << std::endl;
			
			int pos = input[0] - '0';
			int length = input[1] - '0';
			char ch = input[2];
			
			std::cout << "(" << pos << "," << length << "," << ch << ")" << std::endl;
			std::cout << "buffer:" << buffer << std::endl;
			for (int i = pos; i < pos + length; i++)
			{
				coding+= buffer[i];
			}
			coding += ch;
			std::cout << "coding: " << coding << std::endl;
			output += coding;
			buffer += coding;
			if (coding.length() == 1)
			{
				coding = coding[0] + coding;
			}
			buffer = shiftStr(buffer, length + 1);
			coding = shiftStr(coding, length + 1);
			input = shiftStr(input, 3);
			
			std::cout << "==============\n";
		}
		std::cout << "output: " << output << std::endl;
	}

}
