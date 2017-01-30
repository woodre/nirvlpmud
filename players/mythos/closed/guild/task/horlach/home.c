#include "/players/mythos/closed/guild/def.h"

inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(-2);
    short_desc = BOLD+"DARKNESS"+NORM;
    long_desc =
    "You enter a large cave.  Before you stands a large "+BLU+"glowing"+NORM+"\n"+
    "portal.  Step into the portal to begin what must be done.\n"+
    "Finish what is started.\n"+
    "Know that death is not real beyond the portal.\n";
  items = ({
    "north","Darkness....",
    "east","Darkness....",
    "south","Darkness....",
    "west","Darkness....",
    "portal","Step into it",
  });

} }

realm() { return "NT";}

init() {
  ::init();
        if(pp && !present("bold",tp)) {
        move_object(clone_object("/players/mythos/closed/guild/task/horlach/bold.c"),
                    tp);
        tp->save_me(); }
        add_action("step","step");
    
}

step(str) {
  if(!str) return 0;
  if(str == "portal") {
  if(!pp) { 
       tell_object(tp,"Something flashes!\n");
        tp->heal_self(-1000);
        move_object(tp,"/room/church.c"); 
        return 1;}
    say(capitalize(tpn)+" steps into the portal.\n");
    tell_room(this_object(),HIC+"\t\tFLASH\n"+NORM);
    move_object(tp,clone_object("/players/mythos/closed/guild/task/horlach/gate.c"));
  return 1;}
return 0; }

