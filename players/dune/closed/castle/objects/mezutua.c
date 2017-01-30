inherit "obj/clean";
#include "definitions.h"


init() { add_action("goplace","enter"); }

id(str) { return str == "city" || str == "ruins" ||
                 str == "mezutua"; }

get() { return 0; }
drop() { return 1; }
query_weight() { return 0; }
query_value() { return 0; }

reset() { }

short() { return "Mezutu'a, the City of Fire"; }

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
  move_object(TP, MEZUTUAROOM+"/tube.c");
  write_file("/players/dune/log/QUEST_ROOM",
             this_player()->query_real_name()+
             " (level "+this_player()->query_level()+
             ") entered Mezutua."+
             " ("+ctime()+")\n");
  return 1;
}
