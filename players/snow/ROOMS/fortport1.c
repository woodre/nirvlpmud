inherit "room/room";
 
reset(arg){
 
if(!present("guardian"))  {
move_object(clone_object("/players/snow/MONSTERS/portguard1.c"),this_object());  }
 
 if(!arg){
 
 set_light(1);
  short_desc="Top of the East Tower";
 long_desc=
 "After a long climb, you have finally reached the top of the tower. You are\n\
in a small, smooth-walled room with no windows. Looking around for a\n\
possible purpose to the room, you see what appears to be a portal\n\
covering the north wall. Flowing across the portal are strange runes. The\n\
foul wind seems to originate on the other side of the portal.\n";
 
items=({
 "portal", "As you peer deeply into the portal you can see vague images of " +
              "flame and rock on the other side. Suddenly, the runes glow " +
              "brightly and Snow's voice whispers in your mind: This portal " +
              "leads to an area of great danger. Be prepared. The guardian " +
              "of this gate is a weak example of many of the monsters in the " +
              "area beyond this portal. You have been warned.",
 "runes","As you examine the strange runes, they suddenly begin to glow" +
              "brightly and Snow's voice whispers in your mind: This portal " +
              "leads to an area of great danger. Be prepared. The guardian " +
              "of this gate is a weak example of many of the monsters in the " +
              "area beyond this portal. You have been warned."
          });
 
  dest_dir=({
 "/players/snow/ROOMS/fort1.c","down",
 "/players/snow/ROOMS/death/cold1.c","death",
      });
  }   }
 
