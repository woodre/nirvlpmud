
inherit "/players/molasar/rowan/room/room.c";

reset(arg) {
   if(arg)
     return;
   set_light(1);
   set_short("The Main Road of Drakeshore");
set_long("You are on the main road that runs through the city of "+ 
"Drakeshore.\n"+
"The once grand street has fallen into a state of disrepair. The roadway\n"+ 
"is cracked and numerous potholes make walking difficult.\n");
   add_item("potholes","Neglect has caused parts of the road to wear\n"+
                       "down leaving large holes.");
   add_exit("north","/players/molasar/rowan/drake/ruin1");
   add_exit("east","/players/molasar/rowan/drake/ghouse");
   add_exit("west","/players/molasar/rowan/drake/road2");
}

