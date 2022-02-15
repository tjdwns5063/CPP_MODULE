#include <iostream>
#include <fstream>

void	replaceLine(std::string& line, std::string s1, std::string s2) {
	std::string::size_type	n;
	std::string::size_type	size;
	std::string				replaceLine;
	int						idx;

	n = line.find(s1.c_str());
	size = s2.size();
	if (n == std::string::npos) {
		return ;
	}
	idx = 0;
	while (idx < static_cast<int>(size)) {
		line[n + idx] = s2[idx];
		idx++;
	}
}

void	writeReplaceLine(std::ofstream& outStream, std::string line) {
	if (outStream.is_open() == true) {
		if (line == "") {
			outStream.write("\n", 1);
		} else {
			outStream.write(line.c_str(), line.size());
		}
	} else {
		return ;
	}
}

void	readAndWriteFile(std::string fileName, std::string s1, std::string s2) {
	std::ifstream	readStream;
	std::ofstream	outStream;
	std::string		line;

	readStream.open(fileName);
	outStream.open(fileName + ".replace");
	if (readStream.is_open() == true) {
		while (readStream) {
			getline(readStream, line);
			replaceLine(line, s1, s2);
			writeReplaceLine(outStream, line);
		}
	}
	readStream.close();
	outStream.close();
}

int main(int argc, char *argv[]) {
	try {
		if (argc < 4)
			throw 0;
	} catch (int except) {
		std::cout << "Argument is always more than 3\n";
		return (1);
	}
	std::string	fileName = argv[1];
	std::string	s1 = argv[2];
	std::string s2 = argv[3];

	std::cout << fileName << ' ' << s1 << ' ' << s2 << '\n';
	readAndWriteFile(fileName, s1, s2);
}