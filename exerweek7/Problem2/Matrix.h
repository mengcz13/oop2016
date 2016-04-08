#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <istream>
#include <ostream>
#include <string>
#include <iostream>

class Matrix {
public:
	Matrix(int r = 0, int c = 0) : row_num(r), column_num(c) { data.assign(row_num * column_num, 0); }
	Matrix(const std::string&);
	Matrix(const Matrix& mat) {
		set_row_column(mat.row(), mat.column());
		data = mat.mat_data();
	}
	void load(const std::string&);
	void save(const std::string&) const;
	void save_product(const std::string&) const; // Same as save()
	void display() const;
	void display_product() const; // Same as display()
	void formatted_in(std::istream&); // Uniform interface for pretty input, accept fstream and cin
	void formatted_out(std::ostream&) const; // Uniform interface for pretty output, accept fstream and cout
	Matrix multiply(const Matrix&) const;
	Matrix& operator = (const Matrix&);
	const int row() const { return row_num; }
	const int column() const { return column_num; }
	const std::vector<double>& mat_data() const { return data; }
	double& at(int, int); // Visit by rank and modify
	const double& at(int, int) const; // Visit by rank for const
	void set_row_column(int, int); // Initialize the matrix with given row and column
	void reset(); // Clear all data and reset
private:
	int row_num;
	int column_num;
	std::vector<double> data;
};

#endif