inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc =("Deep within the Durkor Caverns");
long_desc =(
"  The gates to Sivart, the city of the Durkors stands here.  Guards can\n"+
"be seen, and an evil presence can be felt.  Many impaled heads stand\n"+
"before the gate in warning of the evil that lies within.  Goblin, ogre,human, \n"+
"and all other races can be seen atop the spears.  Noone but Durkor have been\n"+
"able to enter since they have inhabited here.\n"); 

if(!present("guard"))
	  move_object(clone_object("/players/catacomb/Cavern/mobs/Dguard.c"),
	    this_object());

items = ({
  "gates",
  "Large, beautifully-crafted gates block the entrance to Sivart.", 
  "gate",
  "Large, beautifully-crafted gates block the entrance to Sivart",
  "spears",
  "Many spears stick in the ground with a head impaled on them, warding off intruders",
  "spear",
  "Many spears stick in the ground with a head impaled on them, warding off intruders",
  "head",
  "The only remnants of early intruders into the Durkor city", 
  "heads",
  "The only remnants of early intruders into the Durkor city" 

});

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl3_3.c","east"
  });
}

query_no_fight()
{
  return 1;
}

