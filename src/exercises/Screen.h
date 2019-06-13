#pragma once


#include <string>

class Screen;

class Window_mgr {
public:
	using screen_index = std::vector<Screen>::size_type;
	void clear(screen_index);
	Window_mgr();

private:
	std::vector<Screen> screens;  //{Screen(24, 80)};
};

class Screen {

	friend void Window_mgr::clear(screen_index);

public:
	using pos = std::string::size_type;
	using content_type = char;

	Screen() = default;
	Screen(pos ht, pos wd)
		: height(ht), width(wd), contents(ht * wd, ' ') {}
	Screen(pos ht, pos wd, content_type c)
		: height(ht), width(wd), contents(ht * wd, c) {}

	const content_type &get() const { return contents[cursor]; }
	content_type &get() { return contents[cursor]; }
	const content_type &get(pos row, pos col) const;
	content_type &get(pos row, pos col);

	Screen &move(pos row, pos col);

	Screen &set(char c);
	Screen &set(pos r, pos col, char c);

	Screen &display(std::ostream &os) { _display(os); return *this; }
	const Screen &display(std::ostream &os) const { _display(os); return *this; }
private:
	pos cursor = 0;
	pos width = 0;
	pos height = 0;
	std::string contents;

	void _display(std::ostream &os) const { os << contents; }
};

inline
const Screen::content_type &Screen::get(pos row, pos col) const {
	return contents[row * width + col];
}

inline
Screen::content_type &Screen::get(pos row, pos col) {
	return contents[row * width + col];
}

inline
Screen &Screen::move(pos row, pos col) {
	cursor = row * width + col;
	return *this;
}

inline
Screen &Screen::set(pos r, pos col, char c){
	contents[r*width+col] = c;
	return *this;
}

inline
Screen &Screen::set(char c) {
	contents[cursor] = c;
	return *this;
}


Window_mgr::Window_mgr() : screens{ Screen(24, 80) } {}

void Window_mgr::clear(screen_index i) {
	Screen &s = screens[i];
	s.contents = std::string(s.height * s.width, ' ');
}