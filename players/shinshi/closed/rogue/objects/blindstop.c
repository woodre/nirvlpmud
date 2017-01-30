#include <ansi.h>
#define MAX_BEATS 300

int beats;

id(str) { return str=="shinshi_no_blind"; }

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
       tell_object(ob, "\n"+ "\n"+ "\n"+ "		You regain the ability to\n		"+HIR+"		 blind"+NORM+".\n");
    return destruct(this_object());
  }
}