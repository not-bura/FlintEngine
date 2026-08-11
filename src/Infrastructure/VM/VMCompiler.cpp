#include "VMCompiler.h"
#include "Domain/UTF8/UTF8.h"

using namespace FlintEngine;

void VMCompiler::Compile()
{
	auto source = "source code";
	auto j = u8"kkkkk";

	UTF8String a = { u8"AA" };

	UTF8String text = { source };
	UTF8String text2 = { j };

	auto tes = text[0];
}