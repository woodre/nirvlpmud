#include <ansi.h>
#include "std.h"
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
   extra_init() {
     if(this_player()) tell_object(this_player(), HIR+"THIS IS AN ANCIENT AREA NOT SUGGESTED FOR NEW PLAYERS.\nIT CAN BE QUITE FEROCIOUS AND THE DESCRIPTIONS ARE LAME.\nIT IS INTENDED LARGELY FOR NOSTALGIA, NOT KILLIN'S. THANK YOU :)\n"+NORM);
     add_action("exit1","exit");
   }


/*



*/


string dest;
ONE_EXIT("players/rich/hall1.c", "north",
   "Transporter Room",

           
"This is the main transporter room,in the center you see the\n" +
           "transporter controls,in the corner you see the transporter pads.\n" +
           "Type "+HIR+"exit"+NORM+" to leave or go north to a hallway.\n",
           1)
realm() {return "enterprise";}
exit1() {
   write("You step onto the transporter pad and see the transporter...\n");
   write("being activated by the technician.\n");
   write("You feel your body split into a million pieces...\n");
   write("You suddenly rematerialize and seem to be elsewhere.\n");

    if(dest==0) {
       call_other(this_player(),"move_player","leaves#room/church");
       return 1;
        }
    call_other(this_player(),"move_player","beams out" + "#" + dest);


/*  Rich, the exit command in this room was failing, as it could not
    find the file_name(dest).  I commented out the move_player line
    and added a temporary one after it so that players would not
    be trapped. 
                     --Lestat                                  */

   return 1;
   }
set_dest(arg) {
    dest=arg;
   }
