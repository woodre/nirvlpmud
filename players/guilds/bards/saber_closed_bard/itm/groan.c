/*
 * The object for the groan cantrip.
 * Bard v3.0
 */

int z;

#include "/players/saber/closed/esc2.h"
#define NORM ESC+"[2;37;0m"
#define BOLD ESC+"[1m"

reset(arg) {
   if(arg) return;

  call_out("groan",random(30));
  call_out("kill_it",300);
        }

get()    { return 1;   }
drop()   { return 1;   }
can_put_and_get()  { return 0; }

is_illusion()   { return "illusion"; }

id(str) { return str == "groan_obj"; }

query_value() { return 1; }
  
init()  {
  add_action("end_it","groan");
  if(present("pro_from_cant", this_player()))  {
    write(BOLD+"\nThere is a 'groan' cantrip active in this room."+NORM+"\n"+
      BOLD+"To dispel it, type < groan off > "+NORM+"\n\n");
        }
        }
        
        
groan() {
  z=random(5);

if (z == 1)  {
  tell_room(environment(this_object()),
    "You hear somebody groan in pain.\n");
   call_out("groan",random(35));
   return 1;
        }
if (z == 2)  {
 tell_room(environment(this_object()),
   "Somebody groans in pain.\n");
  call_out("groan",random(35));
  return 1;
        }
if (z == 0)  {
 tell_room(environment(this_object()),
   "You hear somebody behind you groan in pain.\n");
 call_out("groan",random(35));
 return 1;
         }
if (z == 3) {
  tell_room(environment(this_object()),
    "You hear somebody groan.\n");
  call_out("groan",random(35));
  return 1;
        }
if (z == 4) {
 tell_room(environment(this_object()),
   "You hear somebody moan in pain.\n");
  call_out("groan",random(35));
  return 1;   
        }
        }


end_it(str)  {
  if(str == "off")  {
   if(present("instrument", this_player())  ||
      present("pro_from_cant", this_player()))  {
        write("You dispel the cantrip.\n");
        say(this_player()->query_name()+" dispels the groan cantrip.\n");
        kill_it();
        return 1;
        }
        }
        }
        

kill_it()  {
  destruct(this_object());
  return 1;
        }
