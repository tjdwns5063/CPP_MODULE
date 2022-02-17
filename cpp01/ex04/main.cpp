#include <iostream>
#include <fstream>

void	writeReplaceLine(std::ofstream& outStream, std::string line) {
	if (outStream.is_open() == true) {
		outStream.write(line.c_str(), line.size());
	}
}

std::string	makeNewLine(std::string line, std::string s1, std::string s2) {
	std::string::size_type	n;
	std::string::size_type	size;
	int						idx;
	std::string				newString;

	if (line == "" && (s1 == "\\n" || s1 == "\\0")) {
		newString.append(s2);
		return (newString);
	}
	n = line.find(s1.c_str());
	size = s1.size();
	idx = 0;
	while (n != std::string::npos) {
		while (idx < static_cast<int>(n)) {
			newString.append(1, line[idx]);
			idx++;
		}
		newString.append(s2);
		n = line.find(s1.c_str(), n + size);
		idx += size;
	}
	std::cout << "idx : " << idx << '\n';
	while (idx < static_cast<int>(line.size())) {
		newString.append(1, line[idx]);
		idx++;
	}
	return (newString);
}

void	readAndWriteFile(std::string fileName, std::string s1, std::string s2) {
	std::ifstream	readStream;
	std::ofstream	outStream;
	std::string		line;
	std::string		newLine;

	readStream.open(fileName);
	outStream.open(fileName + ".replace");
	if (readStream.is_open() == true) {
		while (readStream && !readStream.eof()) {
			getline(readStream, line);
			newLine = makeNewLine(line, s1, s2);
			if (!readStream.eof())
				newLine.append("\n");
			writeReplaceLine(outStream, newLine);
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