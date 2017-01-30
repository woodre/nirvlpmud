#include "/players/fakir/color.h"
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
found = 1+random(3);
set_light(1);

short_desc = "Ter'angreal of Glass (Transparent)";
long_desc =
"   A single circular wall of transparent glass encompasses your vision.\n"+
"Immages of snake-like warriors, engaged in combat, are fused within the\n"+
"glass wall.  Armed with odd weapons of destruction and clothed in various\n"+
"forms of strange armor, the warriors strain to escape the imprisoning glass\n"+
"wall.  A transparent "+CYAN+"'ter'angreal'"+OFF+" of glass shimmers with a dim light and\n"+
"hangs without support in the center of the room.  Three circular doorways\n"+
"open and close as they drift about upon the surface of the wall, leading\n"+
"to rooms elsewhere in the tower.\n";

items = ({
"wall",         "Circular in design, with no corners nor seams. It is made of transparent glass",
"glass",        "Enchanted with a strange magic, it shimmers with a dim light",
"room",         "A circular room comprised of a single wall of transparent glass",
"images",       "Odd snake-like warriors who are fused within the glass wall",
"warriors",     "Short and slender beings...with powerful, tightly coiled arms and legs",
"weapons",      "Odd weapons of various design, with sharp blades protruding from the shafts",
"armor",        "Breastplates of shiny metals, with helmets and arm bands of hardened skins",
"ter'angreal",  "A magic ter'angreal of glass, created in the age of legends.\n"+
                "Can you resist the urge to 'strike' the 'ter'angreal'?",
"doorways",     "Round apertures, which open and close like the lens of a camera.",
});

dest_dir = ({
"/players/fakir/genji/rm5b","door1",
"/players/fakir/genji/rm2b","door2",
"/players/fakir/genji/rm4b","door3",
});
}
init()  {
  ::init();
  add_action("strike_terangreal","strike");
}

strike_terangreal(arg)  {
  if(!arg || arg != "ter'angreal") {
    notify_fail("\nA distant voice hisses:\n\n"+
                CYAN+"                 'Try striking the ter'angreal instead.'\n"+OFF);
    return 0; 
  }
  if(found==0) { tell_room(this_object(),"\nA distant voice hisses:\n\n"+
                CYAN+"     'The magic within my ter'angreal has been spent. It can\n\n"+
                     "      no longer free any warriors from the wall of glass.'\n"+OFF);  
  return 1; } 

  if(present("digger",this_object())) {
    write("\nA distant voice hisses:\n\n"+
          CYAN+"        'You must kill this warrior before you can strike the ter'angreal again.'\n"+OFF);
    say  ("\nA distant voice hisses:\n\n"+
          CYAN+"      'Someone has tried to summon another warrior. This warrior must be killed first.'\n"+OFF);
    return 1;
  }
  write("\nA distant voice hisses:\n\n"+
        CYAN+"'You struck the ter'angreal.  I shall release a warrior!'\n\n"+OFF+
        RED+"A mighty warrior is set free from the wall of glass...\n"+OFF);
  say("\nA distant voice hisses:\n\n"+
      CYAN+"'"+this_player()->query_name()+" has struck the ter'angreal. I shall release a warrior!'\n\n"+OFF+
      RED+"A mighty warrior is set free from the wall of glass...\n"+OFF);
  move_object(clone_object("/players/fakir/woods/NPC/digger.c"),this_object());
  found=found-1; 
  return 1; 
}


