inherit "room/room";
 
reset(arg){
 
if(!present("glarvinthal"))  {
move_object(clone_object("/players/snow/MONSTERS/archwizard.c"),this_object());  }

if(!present("dispenser"))
  move_object(clone_object("/players/snow/ITEMS/mystic.c"),this_object());
 
 if(!arg){
 
 set_light(1);
  short_desc="The great hall";
 long_desc=
 "You have entered what appears to be the great hall of the fortress. The\n\
ceiling is fully 80 feet high here and the walls are covered with crystal\n\
clear gargoyles. If you are lucky, Snow's steward, Glarvinthal, may show\n\
you around the fortress. Hallways lead to the north, east, and west.\n";
 
items=({
 "ceiling",
"You feel a crick in your neck starting to form as you look up at the\n"+
"ceiling. It appears to be made of some sort of opaque, wavering crystal.\n"+
"You can see the vague outline of the sun shining through",
 "gargoyles","These fantastic creatures seem nearly alive to you.",
          });
 
  dest_dir=({
  "/players/snow/ROOMS/fort1.c","east",
 "/players/snow/ROOMS/fort2.c","west",
 "/players/snow/ROOMS/fort3.c","north",
 "/players/snow/ROOMS/fort_gate.c","leave",
               });
  }   }

clean_up() { return 1; }
