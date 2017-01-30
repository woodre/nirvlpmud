#include "/players/fakir/color.h"
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
found = 1;
set_light(1);

short_desc = "Circle of Glass (Irridecent)";
long_desc =
"   A single spherical wall of irridecent glass enfolds your being.   Winged, flying\n"+
"warriors, caught in the act of mortal combat, are trapped within the glass\n"+
"wall. The flying warriors cannot escape the imprisoning wall.  Some appear\n"+
"to have no life remaining.  Others are drawn and pale, as if life is being\n"+
"taken from them.  One warrior, his body still flush with life, stares outward\n"+
"with unblinking eyes.  A slender 'circle' of glass shimmers with a dim light\n"+
"and hangs without support in the center of the room.  Two circular doorways\n"+
"open and close within the glass wall, leading elsewhere.\n";

items = ({
"room",    "A circular room with walls of irridecent glass",
"warriors","Some are without life, a few are near death.  One is very much alive",
"wall",    "Circular in design, with no corners nor seams. It is made of irridecent glass",
"weapons", "Odd weapons of various design, with sharp blades protruding from the shafts",
"armor",   "Breastplates of shiny metals, with helmets and arm bands of hardened skins",
"circle",  "A magic circle of glass that shimmers with a dim light.\n"+
           "If you are wise, you will resist the urge to 'strike' the circle...",
"glass",   "Enchanted with a strange magic, it shimmers with a dim light",
"doorways","Round apertures, which open and close like the lens of a camera.",
});

dest_dir = ({
"/players/fakir/genji/rm5a","door1",
"/players/fakir/genji/rm1d","door2",

});
}
init()  {
  ::init();
  add_action("strike_circle","strike");
}

strike_circle(arg)  {
  if(!arg || arg != "circle") {
    notify_fail("\nA rasping voice croaks:\n\n"+
                BROWN+"                 'Try striking the circle instead.'\n"+OFF);
    return 0; 
  }
  if(found==0) { tell_room(this_object(),"\nA rasping voice croaks:\n\n"+
                BROWN+"     'The magic within the circle has been spent. It can\n\n"+
                     "      no longer free any warriors from the wall of glass.'\n"+OFF);  
  return 1; } 

  if(present("digger",this_object())) {
    write("\nA rasping voice croaks:\n\n"+
          BROWN+"        'You must kill this warrior before you can strike the circle again.'\n"+OFF);
    say  ("\nA rasping voice croaks:\n\n"+
          BROWN+"      'Someone has tried to summon another warrior. This warrior must be killed first.'\n"+OFF);
    return 1;
  }
  write("\nA rasping voice croaks:\n\n"+
        BROWN+"'You struck the circle of glass.  I shall release a warrior!'\n\n"+OFF+
        RED+"A mighty warrior is set free from the wall of glass...\n"+OFF);
  say("\nA rasping voice croaks:\n\n"+
      BROWN+"'"+this_player()->query_name()+" has struck the circle. I shall release a warrior!'\n\n"+OFF+
      RED+"A mighty warrior is set free from the wall of glass...\n"+OFF);
  move_object(clone_object("/players/fakir/woods/NPC/digger.c"),this_object());
  found=found-1; 
  return 1; 
}






