#pragma strict_types

#include <ansi.h>
#include "../RangerDefs.h"

string Name;
status Online;
object Base;
int Power;

void
SName(string name) { Name = name; }

string
QName() { return Name; }

void
SBase(object base) { Base = base; }

string
QBase() { return ("/players/guilds/Rangers/CommandCenter/CommandCenter"); }

void
SOnline(status online) { Online = online; }

status
QOnline() { return Online; }

void
APower(int arg) { Power += arg; }

int
QPower() { return Power; }
