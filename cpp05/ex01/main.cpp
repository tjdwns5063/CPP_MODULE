#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void) {
    Bureaucrat me("me", 6);
    Form    form("form", 5, 5);

    me.signForm(form);
}