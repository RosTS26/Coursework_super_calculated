// Усі можливі операції
bool operation(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Функція пріоритету операції, що надійшла
int prioritet(char op) {
	if (op < 0) return 3;
	else {
		if (op == '+' || op == '-') return 1;
		else if (op == '*' || op == '/') return 2;
		else if (op == '^') return 4;
		else return -1;
	}
}

// Принцип роботи кожного оператора
void action(vector<double>& value, char op) {
	// Якщо стоїть знак "-", вираз унарний
	if (op < 0) {
		double unitar = value.back();
		value.pop_back();
		if (-op == '-') value.push_back(-unitar);
	}
	// Для бінарних операцій
	else {
		// Маємо 2 числа
		double right = value.back();
		value.pop_back();
		double left = value.back();
		value.pop_back();
		// Виконуємо арифметичну дію
		if (op == '+') value.push_back(left + right);
		else if (op == '-') value.push_back(left - right);
		else if (op == '/') value.push_back(left / right);
		else if (op == '*') value.push_back(left * right);
		else if (op == '^') value.push_back(pow(left, right));
	}
}

// Калькулятор
double calculus(string& formula) {
	bool unary = true;	// Бульова змінна для розподілу унарних та бінарних операторів
	vector<double> value;	// Масив для чисел
	vector<char> op;	// Масив для операторів

	for (int i = 0; i < formula.size(); i++) {
		// Якщо поточний елемент "відкрита дужка", то кладемо її у стек
		if (formula[i] == '(') {
			op.push_back('(');
			unary = true;
		}
		// Якщо "закриваюча дужка" - виконуємо всі операції, що знаходяться всередині
		else if (formula[i] == ')') {
			while (op.back() != '(') {	// Проходимо цикл до відкритої дужки
				action(value, op.back());
				op.pop_back();
			}
			op.pop_back();
			unary = false;
		}
		// Якщо елемент рядка є одним із операторів, то...
		else if (operation(formula[i])) {
			char zn = formula[i];	// Привласнюємо змінний знак оператора
			if (unary == true) zn = -zn;	// Надаємо негативного значення, для розпізнавання унарності
			// Цикл до тих пір, поки масив операторів заповнений і пріоритет оператора >= пріоритета zn 
			while (!op.empty() && prioritet(op.back()) >= prioritet(zn)) {
				action(value, op.back());	// Виконуємо алгебраїчні обчислення
				op.pop_back();
			}
			op.push_back(zn);
			unary = true;
		}
		else {
			string number;	// задаємо рядок для знайдених числових операндів
			while (i < formula.size() && isdigit(formula[i])) number += formula[i++];
			i--;
			value.push_back(atol(number.c_str()));	// Помістимо в стек із числовими виразами
			unary = false;
		}
	}
	// Виконаємо ще не використані операції у стеку
	while (!op.empty()) {
		action(value, op.back());
		op.pop_back();
	}

	return value.back(); // Виводимо отриманий вираз
}

// Видалення прогалини
string deleteSpace(string formula) {
	string newFormula;
	for (int i = 0; i < formula.size(); i++) {
		// Якщо елемент виразу пробіл - ігноруємо його
		if (formula[i] != ' ') {
			newFormula.push_back(formula[i]);
		}
	}
	return newFormula; // Виводимо новий вираз без прогалини
}

// Перевірка на помилку введення у виразі
bool inputError(string f) {
	int checkbkt = 0; // Різниця відкритих та закритих дужок
	string ch = "0123456789+-*/()^"; // Доступні знаки
	string num = "0123456789-(";

	for (int i = 0; i < f.size(); i++) {
		// Якщо елемент виразу має недоступний знак - помилка
		if (ch.find(f[i]) == -1 || checkbkt < 0) {
			return true;
		}
		if (f[i] == '(') checkbkt++; // Якщо дужка відкрита, +1
		if (f[i] == ')') checkbkt--; // Якщо дужка закрита, -1
		// Якщо елемент виразу "(" і наступний елемент не містить числа - помилка
		if (f[i] == '(' && num.find(f[i + 1]) == -1) return true;
	}

	if (checkbkt != 0) return true; // Якщо є різниця відкритих та закритих дужок - помилка
	// Якщо перший або останній елемент дорівнює одному із знаків - помилка
	if (f.back() == '+' || f.back() == '-' || f.back() == '*' || f.back() == '^' || f.back() == '/' ||
		f.front() == '+' || f.front() == '*' || f.front() == '^' || f.front() == '/') return true;

	return false;
}


// Функція порівняння
int compare(string x, string y) {
	// Обчисляємо 2 вирази
	double valueX, valueY;
	valueX = calculus(x);
	valueY = calculus(y);

	// Порівнюємо ці вирази та виводим число для обробки
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