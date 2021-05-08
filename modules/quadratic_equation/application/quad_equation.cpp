// Copyright 2021 ParanichevaAlyona

#include "include/quad_equation_app.h"

#include <iostream>
#include <string>

int main(int argc, const char** argv) {
    QuadEquationApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
