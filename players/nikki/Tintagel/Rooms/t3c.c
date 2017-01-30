#include "/players/nikki/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
   if(!arg) {
set_light(-1);
short_desc = HIB+"Sartori's Penitentiary"+NORM;
long_desc = HIB+
 "   A blue aura radiates from the walls adding a jeweled contrast to the\n"+
 "darkness of the room.  Nothing but the swirling colour of the animated\n"+
 "walls can be seen in the chamber.  The center of the room appears to be\n"+
 "swallowing all illumination and energy.  Like a starving creature hungers\n"+
 "for it's next morsel of nourishment, the vortex focuses it's magnatism\n"+
 "towards the entrance.  A pulsating power imminates through the sounds of\n"+
 "a low chanting murmur.  It is almost maddening to stand in the doorway.\n"+NORM;

items = ({
  "room",HIB+"The room is very powerful with a sense of evil everywhere"+NORM,
  "chamber",HIB+"The chamber does not give a feeling of warm or welcoming"+NORM,
  "aura",HIB+"A deep blue coloured light glows from the walls"+NORM,
  "walls",HIB+"Embraced in a swirling blue hue, they seem almost alive"+NORM,
  "center",GRY+"There is a magnatism that is engulfing the life from the room"+NORM,
  "entrance","The contrast of "+HIY+"light"+NORM+" against the wall of "+GRY+"darkness"+NORM+" is unnerving",
  "doorway","A large, gothic, arched opening into the chamber",

});

dest_dir = ( {
    "players/nikki/Tintagel/Rooms/t3b.c", "down",
   
});
}}

init() {
  ::init();
  add_action("listen","listen");
}

listen(str) {
  if(str != "chanting" && str != "murmur") {
     write("What are you trying to listen for?\n");
     return 1;
      }    
  if(str == "murmur") {
     write("\nThe whispers are low but their consistency is almost deafening...\n\n");
     return 1;
     }
  if(str == "chanting") {
     write("\nYou can't hear them well enough to know what words are being said.\n\n");
     return 1;
     }
}

realm() { return "NT"; }