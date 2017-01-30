#include "/players/feldegast/defines.h"
inherit "/players/feldegast/std/book.c";

void reset(int arg)
{
  if(arg)return;
  set_id("scroll");
  set_alias("rules");
  set_short("Scroll of Rules and Regulations");
  set_long(
"This is a scroll containing the rules and regulations for Nirvana's\n"+
"tournament.  Perhaps you should read it?\n"
  );
  set_weight(1);
  set_value(1);
  set_file(OBJ_PATH+"text/rules.txt");
}
