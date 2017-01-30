inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc =("Deep within the Durkor Caverns");
long_desc =(
"  The sound of an anvil hitting steel resonates here.  Sharp rocks protrude\n"+
"from the wall providing cover for the guards of the Durkor city.  Many have\n"+
"lost their lives trying to enter the secretive city.  Known for their cruel\n"+
"ways, the Durkor have put up totems made from the remains of dead adventurers.\n"+
"These grim totems stand as sentinels warding off all intruders.\n"); 

items = ({
  "rocks",
  "Large rocks jutting from the ground provide the guards with the upperhand", 
  "rock",
  "Large rocks jutting from the ground provide the guards with the upperhand",
  "totems",
  "Many spears stick in the ground with a head impaled on them, warding off intruders",
  "totem",
  "One of the spears shows off an impaled dwarven head",
  "head",
  "The only remnants of early intruders into the Durkor city" 
});

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl3_1.c","east",
  "/players/catacomb/Cavern/rooms/lvl3_2.c","north",
  "/players/catacomb/Cavern/rooms/lvl3_4.c","west" 
  });
}

