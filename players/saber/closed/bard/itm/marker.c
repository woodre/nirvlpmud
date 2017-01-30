/*
 *  This a a headstone, left after a bard buries a creature.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

#define tp this_player()->query_name()
#define DEAD this_object()->query_dead_name()
string D_NAME;

inherit "obj/treasure";

reset(arg)  {
   if (arg) return;
   set_id("marker");
   set_alias("headstone");
   set_weight(4);
   set_value(0);
        }

short()  { return "A headstone";    }
long()   { write( "A headstone reading \"The unknown corpse\".\n"+
                  "If you wish, you may < lay > < flowers > upon it.\n");    }

init()  {  
  add_action("lay_flowers", "lay");   
        }

lay_flowers(str)  {
  if(str == "flowers") {
    write("You lay flowers down upon the grave.\n"+
          "Your feel a sense of great peace.\n");
    say(tp+" lays flowers at the grave.\n");
    return 1;   
        }
        }

get()  { return 0; }

