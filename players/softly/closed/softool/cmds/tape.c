#include "/players/softly/closed/ansi.h"
#define tpn this_player()->query_name()

main(str)
{
  object target;
  if(!str){ write("Tape who?\n"); return 1; 
  }
  target = find_living(str);
  if(!target) return 0;
  write(tpn+ " pulls out some duct tape and tapes "+str+"'s mouth shut!\n");
  tell_object(target,
	      tpn+" pulls out some duct tape and tapes your mouth shut!\n\n");
  move_object(clone_object("/players/softly/closed/softool/tapem.c"), target);
  return 1; 
}
 


