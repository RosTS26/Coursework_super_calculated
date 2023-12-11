// �� ������ ��������
bool operation(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// ������� ��������� ��������, �� �������
int prioritet(char op) {
	if (op < 0) return 3;
	else {
		if (op == '+' || op == '-') return 1;
		else if (op == '*' || op == '/') return 2;
		else if (op == '^') return 4;
		else return -1;
	}
}

// ������� ������ ������� ���������
void action(vector<double>& value, char op) {
	// ���� ����� ���� "-", ����� �������
	if (op < 0) {
		double unitar = value.back();
		value.pop_back();
		if (-op == '-') value.push_back(-unitar);
	}
	// ��� ������� ��������
	else {
		// ���� 2 �����
		double right = value.back();
		value.pop_back();
		double left = value.back();
		value.pop_back();
		// �������� ����������� ��
		if (op == '+') value.push_back(left + right);
		else if (op == '-') value.push_back(left - right);
		else if (op == '/') value.push_back(left / right);
		else if (op == '*') value.push_back(left * right);
		else if (op == '^') value.push_back(pow(left, right));
	}
}

// �����������
double calculus(string& formula) {
	bool unary = true;	// ������� ����� ��� �������� ������� �� ������� ���������
	vector<double> value;	// ����� ��� �����
	vector<char> op;	// ����� ��� ���������

	for (int i = 0; i < formula.size(); i++) {
		// ���� �������� ������� "������� �����", �� ������� �� � ����
		if (formula[i] == '(') {
			op.push_back('(');
			unary = true;
		}
		// ���� "���������� �����" - �������� �� ��������, �� ����������� ��������
		else if (formula[i] == ')') {
			while (op.back() != '(') {	// ��������� ���� �� ������� �����
				action(value, op.back());
				op.pop_back();
			}
			op.pop_back();
			unary = false;
		}
		// ���� ������� ����� � ����� �� ���������, ��...
		else if (operation(formula[i])) {
			char zn = formula[i];	// ������������ ������ ���� ���������
			if (unary == true) zn = -zn;	// ������ ����������� ��������, ��� ������������ ��������
			// ���� �� ��� ��, ���� ����� ��������� ���������� � �������� ��������� >= ��������� zn 
			while (!op.empty() && prioritet(op.back()) >= prioritet(zn)) {
				action(value, op.back());	// �������� ��������� ����������
				op.pop_back();
			}
			op.push_back(zn);
			unary = true;
		}
		else {
			string number;	// ������ ����� ��� ��������� �������� ��������
			while (i < formula.size() && isdigit(formula[i])) number += formula[i++];
			i--;
			value.push_back(atol(number.c_str()));	// �������� � ���� �� ��������� ��������
			unary = false;
		}
	}
	// �������� �� �� ���������� �������� � �����
	while (!op.empty()) {
		action(value, op.back());
		op.pop_back();
	}

	return value.back(); // �������� ��������� �����
}

// ��������� ���������
string deleteSpace(string formula) {
	string newFormula;
	for (int i = 0; i < formula.size(); i++) {
		// ���� ������� ������ ����� - �������� ����
		if (formula[i] != ' ') {
			newFormula.push_back(formula[i]);
		}
	}
	return newFormula; // �������� ����� ����� ��� ���������
}

// �������� �� ������� �������� � �����
bool inputError(string f) {
	int checkbkt = 0; // г����� �������� �� �������� �����
	string ch = "0123456789+-*/()^"; // ������� �����
	string num = "0123456789-(";

	for (int i = 0; i < f.size(); i++) {
		// ���� ������� ������ �� ����������� ���� - �������
		if (ch.find(f[i]) == -1 || checkbkt < 0) {
			return true;
		}
		if (f[i] == '(') checkbkt++; // ���� ����� �������, +1
		if (f[i] == ')') checkbkt--; // ���� ����� �������, -1
		// ���� ������� ������ "(" � ��������� ������� �� ������ ����� - �������
		if (f[i] == '(' && num.find(f[i + 1]) == -1) return true;
	}

	if (checkbkt != 0) return true; // ���� � ������ �������� �� �������� ����� - �������
	// ���� ������ ��� ������� ������� ������� ������ �� ����� - �������
	if (f.back() == '+' || f.back() == '-' || f.back() == '*' || f.back() == '^' || f.back() == '/' ||
		f.front() == '+' || f.front() == '*' || f.front() == '^' || f.front() == '/') return true;

	return false;
}


// ������� ���������
int compare(string x, string y) {
	// ���������� 2 ������
	double valueX, valueY;
	valueX = calculus(x);
	valueY = calculus(y);

	// ��������� �� ������ �� ������� ����� ��� �������
	if (valueX > valueY) {
		return 1;
	}
	else if (valueX < valueY) {
		return 2;
	}
	else {
		return 0;
	}
}