
inherit "/players/molasar/rowan/room/room.c";

realm() { return "NT"; }

reset(arg) {
   if(arg)
     return;
   set_light(1);
   set_short("Mansion Path");
   set_long("You are on a path to the Governor's Mansion.\n"+
   "The path is made up of multicolored cobblestones. The colors range\n"+
   "from red to black to white. Along both sides of the path are waist\n"+
   "high trellises covered in roses of the same colors. A soft breeze\n"+ 
   "causes some of petals to fly off covering the path and fills the\n"+
   "area with a sweet aroma.\n");
   add_item("trellisses","This frame of latticework is used to support the\n"+
   "numerous roses which mark the edges of the path.");
   add_item("cobblestones","The cobblestones are in many different colors\n"+
   "and are in suprisingly good shape.");
   add_item("petals","These petals have been blown from the roses which\n"+
   "cover the trellises.");
   add_exit("enter","/players/molasar/rowan/drake/mansion/foyer");
   add_exit("south","/players/molasar/rowan/drake/nroad2");
}

