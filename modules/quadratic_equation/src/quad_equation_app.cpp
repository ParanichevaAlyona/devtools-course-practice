// Copyright 2021 ParanichevaAlyona

#include <iostream>
#include <string>
#include <sstream>
#include <utility>

#include "include/quad_equation_app.h"
#include "include/QuadraticEquation.h"

using std::stoi;

QuadEquationApp::QuadEquationApp() : message_("") {}

void QuadEquationApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a quadratic equations calculator application.\n\n" +
        "Please provide arguments in the following format:\n$"
        + appname + "<a> <b> <c> \n\n" \

        "Where all arguments are integer numbers. \n" \
        "Example: " + appname + " 2 -3 7.\n\n";
}

bool QuadEquationApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
        help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return false;
    }
    return true;
}

std::string QuadEquationApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    try {
        args.a = stoi(argv[1]);
        args.b = stoi(argv[2]);
        args.c = stoi(argv[3]);
    }
    catch (const char* s) {
        return s;
    }


    std::ostringstream stream;
    try {
        QuadraticEquation eq(args.a, args.b, args.c);
        std::pair <double, double> res = eq.solver();
        stream << "First root = " << res.first << ", second root = "
            << res.second << ".";
        message_ = stream.str();
    }
    catch (const char* s) {
        stream << s;
        message_ = stream.str();
    }
    return message_;
}
