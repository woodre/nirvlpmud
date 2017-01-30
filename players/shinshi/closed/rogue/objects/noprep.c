#include <ansi.h>
#define MAX_BEATS 900

int beats;

id(str) { return str=="shinshi_stop_prep"; }

drop() { return 1; }

start_it()
{
  set_heart_beat(1);
}

heart_beat()
{
	object ob;
  
  ob = environment();
  if(++beats == MAX_BEATS)
  {
       tell_object(ob, "\n"+ "\n"+ "\n"+ "		You regain the ability to\n		"+HIR+"		 pickpocket"+NORM+".\n");
    return destruct(this_object());
  }
}