#include <ansi.h>
#define MAX_BEATS 3

int beats;

id(str) { return str == "shockwave_stun_bitch"; }
get() { return 1; }
drop() { return 1; }

init(){

#ifndef __LDMUD__
      add_action("stun_move"); add_xverb("");
#else
      add_action("stun_move", "");
#endif
}

start_it()
{
	set_heart_beat(1);
}

stun_move(str) {
  if(environment(this_object())) {
    if(living(environment(this_object()))) {     
      if(str == "north" || str == "south" || str == "east" ||
         str == "west" || str == "up" || str == "down" ||
         str == "in" || str == "out" || str == "northwest" ||
         str == "southwest" || str == "northeast" ||
         str == "southeast" || str == "exit" || str == "leave") {
      write(BOLD+"You are still "+YEL+"dazed from the "+YEL+"shockwave"+NORM+BOLD+"!\n"+NORM);
      return 1;
      }
    }
  }
}

heart_beat()
{
	object ob;
	
	ob = environment();
	if(beats++ == MAX_BEATS)
	{
		tell_object(ob, BOLD+"\n\n\nYou recover from the "+YEL+"shockwave"+NORM+BOLD+"!\n\n");
		return destruct(this_object());
	}
}