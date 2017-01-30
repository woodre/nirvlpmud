inherit "room/room";

reset(arg) {

   if(!arg) {
   short_desc="Blue Crystal";
   long_desc="\tBlue light reflects off of mirrored walls.  The light has no source,\n"+
      "but seems to eminate from the walls themselves.  Crystal walls in perfect\n"+
      "geometric symmetry rise around you with one passage leading northwest.\n"+
      "Melodic chimes can be heard from all directions.\n";
   dest_dir=({
      "/players/llew/closed/crystal/crys.c","northwest",
      });
   items=({
      "walls","You look at the mirrored walls and see your own reflection,\n"+
         "but it is not quite you.  It is yourself without any flaws. It is perfect.\n",
   });
   }
   
  if(!random(2))
   if(!present("demon")) move_object(clone_object("/players/llew/closed/crystal/demon.c"),this_object());
}
