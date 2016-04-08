#include "Matrix.h"

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <cstdlib>
using namespace std;

Matrix::Matrix(const string& inputfilename) {
	load(inputfilename);
}

void Matrix::load(const string& inputfilename) {
	fstream input;
	try {
		input.open(inputfilename.c_str(), ios::in);
		if (!input.is_open()) {
			throw runtime_error("Input file " + inputfilename + " does not exist!");
		}
		formatted_in(input);
		input.close();
	}
	catch (runtime_error err) {
		cerr << err.what() << endl;
		abort();
	}
}

void Matrix::save(const string& outputfilename) const {
	fstream output;
	try {
		output.open(outputfilename.c_str(), ios::out);
		if (!output.is_open()) {
			throw runtime_error("Output file " + outputfilename + " cannot be created!");
		}
		formatted_out(output);
		output.close();
	}
	catch (runtime_error err) {
		cerr << err.what() << endl;
		abort();
	}
}

void Matrix::save_product(const string& outputfilename) const {
	save(outputfilename);
}

void Matrix::display() const {
	formatted_out(cout);
}

void Matrix::display_product() const {
	display();
}

void Matrix::formatted_in(istream& inputstream) {
	inputstream >> row_num >> column_num;
	set_row_column(row_num, column_num);
	for (int i = 0; i < row_num; ++i) {
		for (int j = 0; j < column_num; ++j) {
			inputstream >> at(i, j);
		}
	}
}

void Matrix::formatted_out(ostream& outputstream) const {
	outputstream << row_num << ' ' << column_num << endl;
	for (int i = 0; i < row_num; ++i) {
		for (int j = 0; j < column_num; ++j) {
			outputstream << at(i, j) << ' ';
		}
		outputstream << endl;
	}
}

Matrix Matrix::multiply(const Matrix& mat) const {
	try {
		if (this->column() != mat.row())
			throw runtime_error("Error: Matrix dimensions do not match!");
		Matrix ansmat(this->row(), mat.column());
		for (int i = 0; i < ansmat.row(); ++i) {
			for (int j = 0; j < ansmat.column(); ++j) {
				double tempsum = 0;
				for (int k = 0; k < this->column(); ++k) {
					tempsum += (this->at(i, k) * mat.at(k, j));
				}
				ansmat.at(i, j) = tempsum;
			}
		}
		return ansmat;
	}
	catch (runtime_error err) {
		cerr << err.what() << endl;
		abort();
	}
}

Matrix& Matrix::operator = (const Matrix& mat) {
	set_row_column(mat.row(), mat.column());
	data = mat.mat_data();
	return (*this);
}

inline double& Matrix::at(int r, int c) {
	return data.at(r * column_num + c);
}

inline const double& Matrix::at(int r, int c) const {
	return data.at(r * column_num + c);
}

void Matrix::set_row_column(int r, int c) {
	row_num = r;
	column_num = c;
	data.assign(row_num * column_num, 0);
}

void Matrix::reset() {
	row_num = 0;
	column_num = 0;
	data.clear();
}