#pragma once
#include <string>
enum DegreeType { SECURITY, NETWORK, SOFTWARE };

//parallel array pops out of string for each degree type, using degree type as an index
static const std::string degreeTypeStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };