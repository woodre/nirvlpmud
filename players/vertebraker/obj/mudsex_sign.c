#include <ansi.h>

status id(string str)
{
 return (str=="sign"||str=="warning sign"||str=="mudsex_sign");
}

string short()
{
 return "A "+HIR+BLINK+"BIG RED WARNING SIGN"+NORM+NORM;
}

void long()
{
 write("\n\t\
The sign reads:\n\n\
"+HIR+BLINK+"\n\n\tJust say NO\n\
\t to MUDSEX!\n"+NORM+NORM);
 write("\nPaid for by the Nirvana Abstinence Council.\n\n");
}

int query_weight()
{
 return 10398038;
}
