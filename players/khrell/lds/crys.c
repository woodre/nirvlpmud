inherit "room/room";
int darkness;

reset(arg) {
   darkness=1;
   long_desc="\tBlue light reflects off of mirrored walls.  The light has no source,\n"+
      "but seems to eminate from the walls themselves.  Crystal walls in perfect\n"+
      "geometric symmetry rise around you with passages leading in all directions.\n"+
      "Melodic chimes can be heard from all directions.\n"+
      "\tIn the center of the room a darkness resides.  Blue mist from the walls\n"+
      "floats towards this unnatural blackness, feeding it's pulsing growth steadily.\n"+
      "Glancing toward the nothingness produces a vile fear and loathing, forcing you\n"+
      "to quickly turn away.\n";
if(!arg) {
   short_desc="Blue Crystal";
   dest_dir=({
      "/players/llew/closed/crystal/crys8.c","north",
      "/players/llew/closed/crystal/crys9.c","northeast",
      "/players/llew/closed/crystal/crys11.c","east",
      "/players/llew/closed/crystal/crys14.c","southeast",
      "/players/llew/closed/crystal/crys13.c","south",
      "/players/llew/closed/crystal/crys12.c","southwest",
      "/players/llew/closed/crystal/crys10.c","west",
      "/players/llew/closed/crystal/crys7.c","northwest",
      "/players/llew/closed/crystal/crys4.c","up",
      "/players/llew/closed/crystal/crys17.c","down",
      "/room/eastroad4","out"});
   items=({
      "walls","You look at the mirrored walls and see your own reflection,\n"+
         "but it is not quite you.  It is yourself without any flaws. It is perfect.\n",
      "darkness","It pulls at your soul, devouring your will.  You have the urge\n"+
         "to plunge into the darkness and end it all...\n"});
}
}
new_long() {
   long_desc="\tBlue light reflects off of mirrored walls.  The light has no source,\n"+
      "but seems to eminate from the walls themselves.  Crystal walls in perfect\n"+
      "geometric symmetry rise around you with passages leading in all directions.\n"+
      "Melodic chimes can be heard from all around.\n";
   darkness=0;
}
dark() { return darkness; }
