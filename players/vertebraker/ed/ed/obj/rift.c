#include "/players/vertebraker/define.h"
inherit ITEM;
reset(arg) {
    if(arg) return;
    set_id("rift");
    set_short(HIY+"A Reality Rift"+NORM);
    set_long(
"This is a rift in reality, created by an unknown force!  You can 'enter' it!\n");
    }

get() { return 0; }

init() {
  ::init();
  add_action("enter_me","enter"); }

enter_me(arg) {
  if(!arg) { write("Enter what?\n"); return 1; }
   if(arg == "rift" || arg == "yellow rift") {
write(RED+"\n :::"+BOLD+" W A R N I N G "+NORM+RED+":::\n"+
NORM+" Within this portal lies a land of demons, horror, and otherwise\n"+
"terrible acts.  It is recommended that before the player enters, he [or she]\n"+
"has stocked up on the appropriate items and is truly ready for the\n"+
"demonic onslaught within - hence, this warning was created...\n"+
" If you at any time, die, or fail to leave, you waive all your rights\n"+
"to reclaiming lost equipment for the entirety of your stay...\n"+
"Do you agree to these terms? [y/n]: ");
  input_to("warning");
    return 1; }
  }

warning(arg) {
  if(arg != "y") {
    write("....Hopefully you will attempt another time.\n");
    return 1; }
  write("Now play nice with my zombie friends! - Vertebraker 12-7-99\n");
  write("You boldly step into the "+HIY+"yellow"+NORM+" rift and disappear!\n");
  say(TPN+" boldly steps into the "+HIY+"yellow"+NORM+" rift and disappears!\n");
    move_object(TP,"/players/vertebraker/ed/ed/room/b3");
    command("look",TP);
    tell_room(ENV(TP),HIY+TPN+" enters in a flash of light!\n"+NORM,({TP}));
   write_file("/players/vertebraker/log/e-realms",ctime()+" "+TPN+" "+TP->query_level()+"+"+TP->query_extra_level()+" entered EvilDead 1\n");
  return 1; }
