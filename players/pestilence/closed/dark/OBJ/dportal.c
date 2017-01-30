inherit "obj/treasure";
#include "/players/pestilence/ansi.h"

reset(arg) {
  if(arg) return;
  set_id("portal");
  set_alias("swirling portal");
  set_short(""+HIK+"A "+HIK+"DARK"+HIW+" portal"+NORM+"");
  set_long(
"This is a "+HIW+"swirling"+HIK+" portal"+NORM+" that leads to into\n"+
"the guild hall, so a player could join the 'Dark Order'.\n"
  );
  set_value(0);
  call_out("dark", 10);

}

get() { return 0; }

init() {
  ::init();
add_action("enter","enter");
}

enter(arg) {
   if(!arg) { notify_fail("You must enter the portal.\n");
       return 0;}
  if(arg == "portal"){
     write("You enter the through the portal.\n");
     this_player()->move_player("into the portal#/players/pestilence/closed/dark/room/dhall.c");
  write_file("/players/pestilence/closed/dark/log/dportal",ctime(time())+" "+this_player()->query_name()+" entered the dark portal.\n");
     return 1; }
        else
            write("You must enter the portal.\n");
        return 1;
    }

dark()
{

        if (environment()) {
                tell_room(environment(),
                                  "The "+HIK+"DARK "+HIW+"Portal"+NORM+" vanishes.\n");
        }
        destruct(this_object());
        return 1;
}

