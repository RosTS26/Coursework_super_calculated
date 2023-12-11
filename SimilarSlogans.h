string similarSlogans(string formula) {
	formula += '.'; // ����� ������ � ���� ������ �� ����
	vector <string> masSlog; // ����� �����
	vector <int> valueSlog; // ����� �������� �����
	string slog = "";
	string val = "";
	string rezult = "";

	// �������� ���� 
	for (int i = 0; i < formula.size(); i++) {
		// ������ ������� "-" ���������� � ��������
		if (i == 0 && formula[i] == '-') val += "-";

		// ���� ������� ������ ������� �� 0 �� 9, �������� ���� � val
		else if (formula[i] >= '0' && formula[i] <= '9') {
			val += formula[i];
		}

		// ���� ������� ������ ������� �� "a" �� "z", �������� ���� � slog
		else if (formula[i] >= 'a' && formula[i] <= 'z' && formula[i] != '-') {
			slog += formula[i];
		}

		// ���� ������� ������ ������� "^" �������� ���� � slog
		else if (formula[i] == '^') {
			slog += formula[i];
			// ���� ���� "^" ���� �����, �������� ���������� ��� �������
			if (formula[i + 1] <= '0' || formula[i + 1] >= '9') return "INPUT ERROR";

			// �������� ����� ���� "^" � slog
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
			// ����� � ����� ��������� ���� 
			masSlog.push_back(slog);
			// ���� val �������, ����� �������
			if (val == "" && formula[i] != '.') valueSlog.push_back(1);
			else {
				// �������, ���� ���� ������ �� ����� (".")
				// ���� � ������� ����� ���� �����, ����� �������
				try {
					valueSlog.push_back(stoi(val));
				}
				catch (invalid_argument) {
					if (val == "-") valueSlog.push_back(-1);
					else valueSlog.push_back(1);
				}
			}
			// ������� slog �� val �� ������
			slog = "";
			if (formula[i] == '-') val = "-";
			else val = "";
		}
	}

	// ��������� �� ������� �����
	for (int i = 0; i < masSlog.size(); i++) {
		for (int j = i + 1; j < masSlog.size(); j++) {
			// ���� ��������� ������ �����, ������ �� ��������
			if (masSlog[i] == masSlog[j]) {
				valueSlog[i] += valueSlog[j];
				// ��������� �������� ���� � ������
				masSlog.erase(masSlog.begin() + j);
				valueSlog.erase(valueSlog.begin() + j);
				j--;
			}
		}
		// �������� ��������� � rezult
		// ���� �������� ����� ������� 0, ��������� ����
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

// �������� �� ������� �������� ������
bool inputErrorSS(string f) {
	string ch = "0123456789+-^";

	// ���������� ������ ������� ������ �� ������� ��������
	for (int i = 0; i < f.size(); i++) {
		if (ch.find(f[i]) == -1 && (f[i] < 'a' || f[i] > 'z')) {
			return true;
		}
	}
	// ���� ������ ��� ������� ������� ������� "+-^" - �������
	if (f.back() == '+' || f.back() == '-' || f.back() == '^' ||
		f.front() == '^' || f.front() == '+') return true;

	return false;
}