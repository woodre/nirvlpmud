#include "/sys/ansi.h"
#include "/players/mythos/closed/guild/def.h"
object tasker;
int ti;
inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(0);
  ti = 0;
    short_desc = HIK+"Forbidden Castle"+NORM;
    long_desc =
    YEL+"You are in a large hall.  A large portrait hangs above you.\n"+
    "The walls are made of a black stone, while the ceiling domes\n"+
    "far above you.  Something makes you shiver in fear.......\n"+NORM;
  items = ({
    "north",HIK+"Darkness"+NORM+"....",
    "east",HIK+"Darkness"+NORM+"....",
    "south",HIK+"Darkness"+NORM+"....",
    "west",HIK+"Darkness"+NORM+"....",
    "portrait","A regal looking man seems to look at you....\n"+
               "Evil seems to flow from it\nYou shudder... you might be able to touch it.\n",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/forest/rooms/castle4.c", "north",
    "/players/mythos/closed/guild/forest/rooms/castle5.c", "east",
    "/players/mythos/closed/guild/forest/rooms/castle3.c", "south",
    "/players/mythos/closed/guild/forest/rooms/castle.c", "west",
  });
} }
realm() { return "NT";}

init() {
  ::init();
    this_player()->set_fight_area();
    if(!pp) { tell_object(tp,HIR+"Do NOT venture further!\n"+
                                  "Your life is in danger!\n"+NORM);}
     else { tell_object(tp,HIB+"Suddenly the fae overwhelm you!\n"+
                               "DARK FAE dances and flows throughout the castle.\n"+NORM);
  /*
  add_action("touch","touch");
  */
}
}

/*
touch(str) {
tasker = tp;
object ob;
  if(!str) return 0;
  if(str == "portrait") {
  if(ti) { write("Nothing happens.....\n"); return 1;}
    if(!pp) { 
      write("Suddenly, you feel EVIL flood the room!\n");
      tell_room(this_object(),BOLD+"A dark aura envelopes the room....\n"+NORM);
      ob = clone_object("/players/mythos/closed/guild/forest/mon/smog.c");
      move_object(ob,this_object());
      ob->attack_object(tp);
    } else {
    write("You feel something seep into you....\nA black slimey thing touches your soul.\n");
    write(RED+" : "+NORM);
    input_to("por");
    return 1;}
    ti = 1;
    call_out("time",1000);
    return 1;}
 }
 
 
 time() { ti = 0; return 1;}
 
 por(str) {
   if(!str) {
     write(RED+" : "+NORM);
    input_to("por"); }
   if(str== " ") {  
   }
   else { 
   }
   ti = 1;
    call_out("time",1000);
return 1;}
*/
