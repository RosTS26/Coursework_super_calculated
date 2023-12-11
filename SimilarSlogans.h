string similarSlogans(string formula) {
	formula += '.'; // ƒодаЇм крапку в к≥нец виразу €к флаг
	vector <string> masSlog; // ћасив член≥в
	vector <int> valueSlog; // ћасив значенн€ член≥в
	string slog = "";
	string val = "";
	string rezult = "";

	// √оловний цикл 
	for (int i = 0; i < formula.size(); i++) {
		// ѕерший елемент "-" записуЇтьс€ в значенн€
		if (i == 0 && formula[i] == '-') val += "-";

		// якщо елемент виразу дор≥внюЇ в≥д 0 до 9, записуЇмо його в val
		else if (formula[i] >= '0' && formula[i] <= '9') {
			val += formula[i];
		}

		// якщо елемент виразу дор≥внюЇ в≥д "a" до "z", записуЇмо його в slog
		else if (formula[i] >= 'a' && formula[i] <= 'z' && formula[i] != '-') {
			slog += formula[i];
		}

		// якщо елемент виразу дор≥внюЇ "^" записуЇмо його в slog
		else if (formula[i] == '^') {
			slog += formula[i];
			// якщо п≥сл€ "^" немаЇ числа, виводимо пов≥домлен€ про помилку
			if (formula[i + 1] <= '0' || formula[i + 1] >= '9') return "INPUT ERROR";

			// «аписуЇмо числа п≥сл€ "^" в slog
			for (int j = i + 1; j < formula.size(); j++) {
				if (formula[j] >= '0' && formula[j] <= '9') {
					slog += formula[j];
				}
				else {
					i = j - 1;
					break;
				}
			}
		}

		else {
			// ƒодаЇм в масив записаний член 
			masSlog.push_back(slog);
			// якщо val в≥дсутн≥й, додаЇм одиницю
			if (val == "" && formula[i] != '.') valueSlog.push_back(1);
			else {
				// ¬ин€ток, €кщо цикл п≥д≥йшов до флага (".")
				// якщо Ї помилка вводу типу даних, додаЇм одиницю
				try {
					valueSlog.push_back(stoi(val));
				}
				catch (invalid_argument) {
					if (val == "-") valueSlog.push_back(-1);
					else valueSlog.push_back(1);
				}
			}
			// „истимо slog та val в≥д данних
			slog = "";
			if (formula[i] == '-') val = "-";
			else val = "";
		}
	}

	// ѕроходимо по кожному члену
	for (int i = 0; i < masSlog.size(); i++) {
		for (int j = i + 1; j < masSlog.size(); j++) {
			// якщо зустр≥чаЇмо подобн≥ члени, додаЇмо ≥х значенн€
			if (masSlog[i] == masSlog[j]) {
				valueSlog[i] += valueSlog[j];
				// ¬идал€Їмо найдений член з≥ списку
				masSlog.erase(masSlog.begin() + j);
				valueSlog.erase(valueSlog.begin() + j);
				j--;
			}
		}
		// «аписуЇмо результат в rezult
		// якщо значенн€ члену дор≥внюЇ 0, видал€Їмо його
		if (valueSlog[i] == 0) {
			masSlog.erase(masSlog.begin() + i);
			valueSlog.erase(valueSlog.begin() + i);
			i--;
		}
		else if (valueSlog[i] == 1 && i != 0) rezult += ("+" + masSlog[i]);
		else if (valueSlog[i] == 1 && i == 0) rezult += masSlog[i];
		else if (valueSlog[i] == -1) rezult += ("-" + masSlog[i]);
		else if (valueSlog[i] > 0 && i != 0) rezult += ("+" + to_string(valueSlog[i]) + masSlog[i]);
		else rezult += (to_string(valueSlog[i]) + masSlog[i]);
	}
	if (rezult == "") return "0";
	else return rezult;
}

// ѕерев≥рка на помилку введенн€ виразу
bool inputErrorSS(string f) {
	string ch = "0123456789+-^";

	// ѕерев≥р€Їмо кожний елемент виразу на доступн≥ значенн€
	for (int i = 0; i < f.size(); i++) {
		if (ch.find(f[i]) == -1 && (f[i] < 'a' || f[i] > 'z')) {
			return true;
		}
	}
	// якщо перший або останн≥й елемент дор≥внюЇ "+-^" - помилка
	if (f.back() == '+' || f.back() == '-' || f.back() == '^' ||
		f.front() == '^' || f.front() == '+') return true;

	return false;
}