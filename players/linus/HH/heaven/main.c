#include "/players/linus/HH/hdefs.h"

inherit "room/room.c";

reset(arg){
 if(!arg){
 set_light(0);
 custom_exits = 1;

}

}
init() {
  ::init();
   if(this_player()->is_player()) wandering();
    add_action("move_around","north");
    add_action("move_around","south");
    add_action("move_around","east");
    add_action("move_around","west");
    add_action("move_around","northwest");
    add_action("move_around","northeast");
    add_action("move_around","southwest");
    add_action("move_around","southeast");
    add_action("listen_to_this_shit","listen");
}

listen_to_this_shit() {
 write("The soft music of harps resonate throughout the area.\n");
  return 1;
}

move_around() {
  int blah;
  string destdir;
  blah = random(21);
  write("You step into the mist...\n");
    if(blah < 5) destdir = HN2;
    if(blah > 4 && blah < 10) destdir = HN3;
    if(blah > 9 && blah < 15) destdir = HN4;
    if(blah > 14 && blah < 20) destdir = HN5;
    if(blah > 19) destdir = HN6;
  call_other(TP,"move_player",destdir);
return 1;
}

wandering() {
  object npc, dude;
  int det;
npc = present("linus_angel_mob");
det = random(100);
  if(det < 25) dude = MOB + "angel";
  if(det > 24 && det < 50) dude = MOB + "dog";
  if(det > 49 && det < 75) dude = MOB + "blah";
  if(det > 74) dude = MOB + "mob";
   if(!npc && random(100) < 45) {
    MO(CO(dude),TO);
     return 1;
 }
return 1;
}
