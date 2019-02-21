#include <iostream>

std::string line(int l, std::string c) {
	std::string s = "";
	for (int i = 0; i < l; i++) {
		s += c;
	}
	return (s + "\n");
}

std::string alternating_line(int l, std::string x, std::string y) {
	std::string s = "";
	for (int i = 0; i < l; i++) {
		if (i % 2 == 0) {
			s += x;
		}
		else {
			s += y;
		}
	}
	return (s + "\n");
}

std::string alternating_line3x3(int l, std::string x, std::string y) {
	std::string s = "";
	bool flag = true;
	for (int i = 0; i < l; i++) {
		if (flag) {
			s += x;
		}
		else {
			s += y;
		}
		if ((i + 1) % 3 == 0) {
			flag = !flag;
		}
	}
	return (s + "\n");
}

// Task A
std::string box(int w, int h) {
	std::string ans = "";
	for (int i = 0; i < h; i++) {
		ans += line(w, "*");
	}
	return ans;
}

// Task B
std::string checkerboard(int w, int h) {
	std::string ans = "";
	for (int i = 0; i < h; i++) {
		if (i % 2 == 0) {
			ans += alternating_line(w, "*", " ");
		}
		else {
			ans += alternating_line(w, " ", "*");
		}
	}
	return ans;
}

// Task C
std::string cross(int size) {
	std::string ans = "";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (j == i || j == (size - i - 1)) {
				ans += "*";
			}
			else {
				ans += " ";
			}
		}
		ans += "\n";
	}
	return ans;
}

// Task D
std::string lower_triangle(int length) {
	std::string ans = "";
	for (int i = 1; i <= length; i++) {
		ans += line(i, "*");
	}
	return ans;
}

// Task E
std::string upper_triangle(int length) {
	std::string ans = "";
	for (int i = length; i > 0; i--) {
		ans += line(i, "*");
	}
	return ans;
}

// Task F
std::string trapezoid(int w, int h) {
	std::string ans = "";
	if (w/2 < h) {
		ans = "Impossible shape!\n";
	}
	else {
		for (int i = 0; i < h; i++) {
			int stars = w - (2 * i);
			ans += line(i, " ").substr(0, i);
			ans += line(stars, "*").substr(0, stars);
			ans += line(i, " ");
		}
	}
	return ans;
}

//Task G
std::string checkerboard3x3 (int w, int h) {
	std::string ans = "";
	bool line_flag = true;
	for (int i = 0; i < h; i++) {
		if (line_flag) {
			ans += alternating_line3x3(w, "*", " ");
		}
		else {
			ans += alternating_line3x3(w, " ", "*");
		}
		if ((i + 1) % 3 == 0) {
			line_flag = !line_flag;
		}
	}
	return ans;
}