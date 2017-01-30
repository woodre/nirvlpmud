inherit "obj/clean";
#include "definitions.h"


init() { add_action("goplace","enter"); }

id(str) { return str == "city" || str == "ruins" ||
                 str == "kementari"; }

get() { return 0; }
drop() { return 1; }
query_weight() { return 0; }
query_value() { return 0; }

reset() { }

short() { return "The Ruins of Kementari"; }

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
  move_object(TP, KEMENTARIROOM+"/kementari1.c");
  write_file("/players/dune/log/QUEST_ROOM",
             this_player()->query_real_name()+
             " (level "+this_player()->query_level()+
             ") entered Kementari."+
             " ("+ctime()+")\n");
  return 1;
}
