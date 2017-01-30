inherit "room/room";
 
reset(arg){
 
if(!present("guardian"))  {
move_object(clone_object("/players/snow/MONSTERS/portguard2.c"),this_object());  }
 
 if(!arg){
 
 set_light(1);
  short_desc="Top of the West Tower";
 long_desc=
 "After a long climb, you have finally reached the top of the tower. You are\n\
in a small, smooth-walled room with no windows. Looking around for a\n\
possible purpose to the room, you see what appears to be a portal\n\
covering the south wall. Flowing across the portal are strange runes. The\n\
chill wind seems to originate on the other side of the portal.\n";
 
items=({
 "portal", "As you peer deeply into the portal you can see vague images of " +
              "snow and rock on the other side. Suddenly, the runes glow " +
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
  "/players/snow/ROOMS/tundra/entrance.c","portal",
 "/players/snow/ROOMS/fort2.c","down",
      });
  }   }
 
