
inherit "/players/molasar/rowan/room/room.c";

reset(arg) {
   if(arg)
     return;
   set_light(0);
   set_short("A passage under the mountain");
   set_long("You are in a passage underneath the mountain.\n");
   add_exit("north","/players/molasar/rowan/mtn/under3");
   add_exit("down","/players/molasar/rowan/mtn/under5");
}

