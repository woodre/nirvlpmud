#pragma strict_types, verbose_errors

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
General Notes:
These are a set of convenience methods for adding colors to strings without
having a lot of extra cruft in the code when you constantly append the ANSI
constants. e.g. "blu(string)" instead of "BLU + string + NORM".
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Includes
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
#include <ansi.h>

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Color-adding methods.
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */
string blk(string arg) {
	return BLK + arg + NORM;
}

string red(string arg) {
	return RED + arg + NORM;
}

string grn(string arg) {
	return GRN + arg + NORM;
}

string yel(string arg) {
	return YEL + arg + NORM;
}

string blu(string arg) {
	return BLU + arg + NORM;
}

string mag(string arg) {
	return MAG + arg + NORM;
}

string cyn(string arg) {
	return CYN + arg + NORM;
}

string wht(string arg) {
	return WHT + arg + NORM;
}

string hiblk(string arg) {
	return HIBLK + arg + NORM;
}

string hik(string arg) {
	return hiblk(arg);
}

string gry(string arg) {
	return hiblk(arg);
}

string hir(string arg) {
	return HIR + arg + NORM;
}

string hig(string arg) {
	return HIG + arg + NORM;
}

string hiy(string arg) {
	return HIY + arg + NORM;
}

string hib(string arg) {
	return HIB + arg + NORM;
}

string him(string arg) {
	return HIM + arg + NORM;
}

string hic(string arg) {
	return HIC + arg + NORM;
}

string hiw(string arg) {
	return HIW + arg + NORM;
}
