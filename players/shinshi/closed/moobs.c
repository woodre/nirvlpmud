#include <ansi.h>

int waist, num;
string cup, cupSTR;

id(str) { return str == "lolyouhavemanboobs"; }

long()
{
        write("\n"+
"These\n"+
"Are\n"+
"Man\n"+
"BOOBS.\n");
}

extra_look()
{
        if(environment() == this_player())
                write(HIR+"You have a pair of "+num+" "+cupSTR+" sized man boobs!\n"+NORM);
        else
        		write(HIR+environment()->query_name() + " has a pair of "+num+" "+cupSTR+" sized man boobs!\n"+NORM);
}

drop() { return 1; }
get() { return 1; }
quit() { destruct(this_object()); enviroment()->quit(); return 1; }

set_waist(waist) { num = waist; }
set_cup(cup) { cupSTR = cup; }