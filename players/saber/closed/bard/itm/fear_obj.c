/*
 * The object for the haunt cantrip.
 * Bard v3.0
 */

int z;

#include "/players/saber/closed/esc2.h"
#define NORM ESC+"[2;37;0m"
#define BOLD ESC+"[1m"

reset(arg) {
   if(arg) return;

  call_out("haunt",random(30));
  call_out("kill_it",300+random(150));
        }

get()    { return 1;   }
drop()   { return 1;   }
can_put_and_get()  { return 0; }

id(str) { return str == "fear_obj"; }

query_value() { return 1; }


init()  {
  add_action("end_it","haunt");
  if(present("pro_from_cant", this_player()))  {
    write(BOLD+"\nThere is a 'haunt' cantrip active in this room."+NORM+"\n"+
      BOLD+"To dispel it, type < haunt off > "+NORM+"\n\n");
        }
        }
          

haunt() {
  z=random(9);

if (z == 1)  {
  tell_room(environment(this_object()),
    "You hear something move behind you.\n");
   call_out("haunt",random(45));
   return 1;
        }
if (z == 2)  {
 tell_room(environment(this_object()),
   "Something begins to materialize in front of you, but then fades away.\n");
  call_out("haunt",random(45));
  return 1;
        }
if (z == 0)  {
 tell_room(environment(this_object()),
   "You catch a glimpse of movement off to your right.\n");
 call_out("haunt",random(45));
 return 1;
         }
if (z == 3) {
  tell_room(environment(this_object()),
    "You catch a glimpse of movement off to your left.\n");
  call_out("haunt",random(45));
  return 1;
        }
if (z == 4) {
 tell_room(environment(this_object()),
   "You feel spectral hands rifle through your possessions.\n");
  call_out("haunt",random(45));
  return 1;   
        }
if (z == 5) {
 tell_room(environment(this_object()),
   "You sense somebody scanning your thoughts from afar.\n");
  call_out("haunt",random(45));
  return 1;   
        }
if (z == 6) {
 tell_room(environment(this_object()),
   "In the distance, you hear somebody scream.\n");
  call_out("haunt",random(45));
  return 1;   
        }
if (z == 7) {
 tell_room(environment(this_object()),
   "You catch the faint oder of decomposing bodies.\n");
  call_out("haunt",random(45));
  return 1;   
        }
if (z == 8) {
 tell_room(environment(this_object()),
   "You begin to feel that somebody is watching you.\n");
  call_out("haunt",random(45));
  return 1;   
        }        
        }

end_it(str)  {
  if(str == "off")  {
   if(present("instrument", this_player())  ||
      present("pro_from_cant", this_player()))  {
        write("You dispel the cantrip.\n");
        say(this_player()->query_name()+" dispels the haunt cantrip.\n");
        kill_it();
        return 1;
        }
        }
        }
        
        
kill_it()  {
  destruct(this_object());
  return 1;
        }
