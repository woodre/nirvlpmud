inherit "room/room";
 
reset(arg){
 
 if(!arg){
 
 set_light(1);
  short_desc="Top of the North Tower";
 long_desc=
 "After a long climb, you have finally reached the top of the tower. You are\n\
in a small, smooth-walled room with no windows. Looking around for a\n\
possible purpose to the room, you see what appears to be a portal\n\
covering the east wall. Flowing across the portal are strange runes. The\n\
cool breeze seems to originate on the other side of the portal.\n";
 
items=({
 "portal", "As you peer deeply into the portal you can see vague images of " +
              "snow and sun on the other side. Suddenly, the runes glow " +
              "brightly and Snow's voice whispers in your mind: This portal " +
              "leads to a being of great evil and power.",
 "runes","As you examine the strange runes, they suddenly begin to glow" +
              "brightly and Snow's voice whispers in your mind: This portal " +
              "leads to a being of great evil and power. "
          });
 
  dest_dir=({
  "/players/snow/ROOMS/summit.c","portal",
 "/players/snow/ROOMS/fort3.c","down",
      });
  }   }
 
 
