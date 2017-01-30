
inherit "/players/molasar/rowan/room/room.c";

reset(arg) {
   if(arg)
     return;
   set_light(0);
   set_short("A passage underneath the mountain");
   set_long("You are in a passage underneath the mountain.\n");
   add_exit("north","/players/molasar/rowan/mtn/eunder1");
   add_exit("south","/players/molasar/rowan/mtn/prison");
}

