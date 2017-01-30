inherit "obj/clean";
#include "definitions.h"


init() { add_action("goplace","enter"); }

id(str) { return str == "city" || str == "ruins" ||
                 str == "jao e-tinukai'i"; }

get() { return 0; }
drop() { return 1; }
query_weight() { return 0; }
query_value() { return 0; }

reset() {}

short() { return "Jao e-Tinukai'i, the Forgotten City"; }

long()
{
  write(
"     Before your travel weary eyes stands a mighty city of the Sithi.\n"+
"Though it is in ruins, a faint shadow of its former past still remains.\n"+
"There are no gates, and if there were, they are long gone now.\n"+
"You may 'enter' at will.\n");
}


goplace()
{
  say(TPN+" enters the city of the Sithi.\n");
  write("You enter the city of the Sithi.\n\n");
  move_object(TP, JAO_TINUKAIIROOM+"/tstart.c");
  write_file("/players/dune/log/QUEST_ROOM",
             this_player()->query_real_name()+
             " (level "+this_player()->query_level()+
             ") entered Jao e-Tinukai'i."+
             " ("+ctime()+")\n");
  return 1;
}
