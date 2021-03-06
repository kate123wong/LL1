#include "PredictionMatrix.h"

PredictionMatrix::PredictionMatrix() {
}

PredictionMatrix::PredictionMatrix(const PredictionMatrix& copy) {
	this->data = copy.data;
}

PredictionMatrix::~PredictionMatrix() {
}

bool PredictionMatrix::has(const std::string& S, const std::string& a) {
	if (this->data.find(S) == this->data.end()) {
		return false;
	}
	if (this->data[S].find(a) == this->data[S].end()) {
		return false;
	}
	return true;
}

std::string PredictionMatrix::get(const std::string& S, const std::string& a) {
	if (!this->has(S, a)) {
		return "";
	}
	return this->data[S][a];
}

void PredictionMatrix::add(const std::string& S, const std::string& a, const std::string& exp) {
	if (this->data.find(S) == this->data.end()) {
		this->data.insert(std::pair<std::string, std::map<std::string, std::string> >(S, std::map<std::string, std::string>()));
	}
	if (this->data[S].find(a) == this->data[S].end()) {
		this->data[S].insert(std::pair<std::string, std::string>(a, ""));
	}
	this->data[S][a] = exp;
}