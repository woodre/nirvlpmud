
inherit "/players/molasar/rowan/room/room.c";

reset(arg) {
   if(arg)
     return;
   set_light(1);
   set_short("You are on the southern road of Drakeshore");
   set_long("You are on the southern road of Drakeshore.\n"+
   "This stretch of road was created exceptionally wide to accomadate\n"+
   "the large flow of traffic to the marketplace south of here.\n");
   add_exit("north","/players/molasar/rowan/drake/road3");
   add_exit("south","/players/molasar/rowan/drake/clearing");
}

