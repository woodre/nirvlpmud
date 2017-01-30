#include <ansi.h>
#define MAX_BEATS 10

int beats;

id(str) { return str=="didshadowstep"; }

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
    return destruct(this_object());
  }
}