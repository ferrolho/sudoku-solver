struct Coords {
	unsigned int x;
	unsigned int y;
};

bool Finished(const vector<vector<int> > &Puzzle) {
	// calculating line and columns sum
	for (unsigned int i = 0; i < 9; i++) {
		// initializing sum values on each cycle start
		unsigned int lineSum = 0;
		unsigned int columnSum = 0;

		for (unsigned int j = 0; j < 9; j++) {
			lineSum += Puzzle[i][j];
			columnSum += Puzzle[j][i];

			// now analysing sum results
			if (i == 8 && j == 8)
				// if the line or column sum is different than 45 (1+2+...+8+9), return false (puzzle not finished)
				if (lineSum != 45 || columnSum != 45)
					return 0;
		}
	}

	// calculating module sums
	for (unsigned int i = 0; i < 3; i++) {
		for (unsigned int j = 0; j < 3; j++) {
			// initializing module sum before checking each module
			unsigned int moduleSum = 0;

			// computing module sum
			for (unsigned int y = 0; y < 3; y++) {
				for (unsigned int x = 0; x < 3; x++) {
					sum += Puzzle[i*3 + y][j*3 + x];
				}
			}

			// if the sum of a module is different than 45, return false (puzzle not finished)
			if (moduleSum != 45)
				return 0;
		}
	}

	// if everything before this is OK: Puzzle solved: return true (finished)
	return 1;
}

bool NumberExistsInColumn(unsigned int Number, unsigned int Column, const vector<vector<int> > &Puzzle) {
	for (unsigned int i = 0; i < 9; i++)
		// if number found, return true (Number exists)
		if (Puzzle[i][Column] == Number)
			return true;

	// if no match found, return false (Number does not exist)
	return false;
}

bool NumberExistsInLine(unsigned int Number, unsigned int Line, const vector<vector<int> > &Puzzle) {
	for (unsigned int j = 0; j < 9; j++)
		// if number found, return true (Number exists)
		if (Puzzle[Line][j] == Number)
			return true;

	// if no match found, return false (Number does not exist)
	return false;
}

Coords GetCoordsOfNumberInColumn(unsigned int Number, unsigned int Column, const vector<vector<int> > &Puzzle) {
	// declaring struct that holds the Number coords
	Coords solution;

	// scan the entire column
	for (unsigned int i = 0; i < 9; i++) {
		// if Number found, return solution with the respective coords
		if (Puzzle[i][Column] == Number) {
			// defining solution x and y coords
			solution.x = Column;
			solution.y = i;

			// returning solution
			return solution;
		}
	}
}

Coords GetCoordsOfNumberInLine(unsigned int Number, unsigned int Line, const vector<vector<int> > &Puzzle) {
	// declaring struct that holds the Number coords
	Coords solution;

	// scan the entire line
	for (unsigned int j = 0; j < 9; j++) {
		// if Number found, return solution with the respective coords
		if (Puzzle[Line][j] == Number) {
			// defining solution x and y coords
			solution.x = j;
			solution.y = Line;

			// returning solution
			return solution;
		}
	}
}
