
inherit "/players/molasar/rowan/room/room.c";

reset(arg) {
   if(arg)
     return;
   set_light(0);
   set_short("A passage underneath the mountain");
   set_long("You are in a passage underneath the mountain.\n");
   add_exit("up","/players/molasar/rowan/mtn/wunder2");
   add_exit("east","/players/molasar/rowan/mtn/under5");
}

