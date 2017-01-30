
inherit "/players/molasar/rowan/room/room.c";

reset(arg) {
   if(arg)
     return;
   set_light(1);
   set_short("You are on the northern road of Drakeshore");
   set_long("You are on the northern road of Drakeshore.\n"+
"This road is much smaller than the main road that runs through the city.\n"+
"It is in a similiar state however. Huge chunks of stone have been torn up\n"+
"or smashed into small pieces leaving large holes. The buildings\n"+ 
"surrounding the road are still intact, but the majority have been gutted\n"+
"by flames leaving only the supporting walls.\n");
   add_exit("north","/players/molasar/rowan/drake/nroad2");
   add_exit("south","/players/molasar/rowan/drake/road3");
   add_exit("west","/players/molasar/rowan/drake/ruin2");
}

