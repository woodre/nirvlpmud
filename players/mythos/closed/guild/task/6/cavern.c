#include "/players/mythos/closed/guild/def.h"
int n, s;
object task;
inherit "room/room";
reset(arg) {
  if(!arg) {
   n = 0;
  set_light(-1);
    short_desc = "DARKNESS";
    long_desc =
    "You enter a dark cavern.  Everything is quiet here \n"+
    "and nothing stirs...\n";
  items = ({
    "out","The exit....",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/forest/rooms/cavern.c", "out",
  });
} }
realm() { return "NT";}

init() {
  ::init();
    if(!pp) { 
       tell_object(tp,"Something flashes and you are thrown out of the cavern!\n");
        tp->heal_self(-30);
        move_object(tp,"/players/mythos/closed/guild/forest/rooms/cavern.c");
        return 1;}
    if(n) { tell_object(tp,"Someone wishes to be alone!\n");
            move_object(tp,"/players/mythos/closed/guild/forest/rooms/cavern.c"); }
    else {
      if(tl > 9 && tgl == 5 && qtf > 4 && !n) {
        move_object(clone_object("/players/mythos/closed/guild/task/6/egg.c"),this_object());
        n = 1; 
        task = find_player(tpn);
        call_out("check",10);} }
  add_action("oout","out");
}

set_n() { n = 0; }

oout() {
  if(n) { write("Something prevents you from leaving.\n");
  return 1;}
}

check() {
  if(!task) { s = s + 1; }
  if(s > 10) { n = 0; 
    if(present("egg",this_object())) { destruct(present("egg",this_object())); }
     return 1;}
call_out("check",10);
return 1; }
  
