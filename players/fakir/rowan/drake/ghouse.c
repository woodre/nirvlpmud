
inherit "/players/molasar/rowan/room/room.c";

reset(arg) {
   if(arg)
     return;
   set_light(1);
   set_short("Entrance to the city of Drakeshore");
   set_long("You have arrived at the entrance to the city of Drakeshore.\n"+
"A small guardhouse off the side of the road is the only thing which\n"+
"remains to keep a vigil on the town. The city itself is barren and\n"+
"quiet, a graveyard for thousands of souls. Most of the buildings have\n"+
"been smashed to the ground or are just burnt frameworks. An eerie\n"+
"darkness seems to be covering the city casting everything into shades\n"+
"of grey.\n");
   add_item("guardhouse",
"The guardhouse used to serve as a checkpoint for traders, merchants, and\n"+
"travellers. All wares being brought in to be shipped to other realms were\n"+ 
"taxed. It has since collapsed leaving nothing more than a lone wall and a\n"+ 
"pile of rubble.");
   add_item("rubble","You find nothing of interest.");        
   add_item("wall","Scribbled on the wall near the bottom in the Bugbear\n"+
                   "tongue is the phrase 'Out for Lunch' in dull red.");
   add_exit("northeast","/players/molasar/rowan/sroad2");
   add_exit("west","/players/molasar/rowan/drake/road1");
}

