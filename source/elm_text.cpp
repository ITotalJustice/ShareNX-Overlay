#include "elm_text.hpp"

Text::Text(u16 x, u16 y, u16 w, u16 h, const std::string &txt) : m_text(txt) {
    this->setPosition(x, y);
    this->setSize(w, h);
}

Text::~Text() { }

void Text::draw(tsl::Screen *screen, u16 x1, u16 y1) {
    const auto [x, y] = this->getPosition();
    const auto [w, h] = this->getSize();

    screen->drawRect(x, y, w, 1, a({ 0x5, 0x5, 0x5, 0xF }));
    screen->drawRect(x, y + h - 1, w, 1, a({ 0x5, 0x5, 0x5, 0xF }));

    screen->drawString(this->m_text.c_str(), false, x + 20, y + 45, 23, a({ 0xF, 0xF, 0xF, 0xF }));
}

void Text::layout() {

}

void Text::setText(const std::string &txt) {
    this->m_text = txt;
}