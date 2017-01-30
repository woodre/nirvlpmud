#include "/players/fakir/color.h"
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
found = 1+random(2);
set_light(1);

short_desc = "Ter'angreal of Glass (Obscure)";
long_desc =
"   A single spherical wall of obscure glass captures your vision.\n"+
"Immages of skeletal warriors, tall and without armor, are frozen\n"+
"within the glass wall.  The warriors strain to escape, but the wall\n"+
"holds them fast.  An obscure 'ter'angreal' of glass flickers with a\n"+
"dim light and hangs without support in the center of the room.  Four\n"+
"circular doorways open and close within the glass wall, leading to\n"+
"rooms elsewhere.\n";

items = ({
"room",    "A circular room with walls of obscure glass",
"images",  "Tall snake-like warriors who seem encased within the glass wall",
"warriors","Tall and well built, wearing no armor but their skins of scales",
"wall",    "Circular in design, with no corners nor seams. It is made of obscure glass",
"ter'angreal",  "An obscure ter'angreal of glass, created in the age of legends.\n"+
                "Can you resist the urge to 'strike' the 'ter'angreal'?",
"glass",   "Enchanted with a strange magic, it flickers with a dim light",
"doorways","Round apertures, which open and close like the lens of a camera.",
});

dest_dir = ({
"/players/fakir/genji/rm5d","door1",
"/players/fakir/genji/rm2d","door2",
"/players/fakir/genji/rm4d","door3",
"/players/fakir/genji/rm1b","door4",
});
}
init()  {
  ::init();
  add_action("strike_terangreal","strike");
}

strike_terangreal(arg)  {
  if(!arg || arg != "ter'angreal") {
    notify_fail("\nA soft voice speaks:\n\n"+
                YELLOW+"                 'Try striking the ter'angreal instead.'\n"+OFF);
    return 0; 
  }
  if(found==0) { tell_room(this_object(),"\nA soft voice speaks:\n\n"+
                YELLOW+"     'The magic within the ter'angreal has been spent. It can\n\n"+
                     "      no longer free any warriors from the wall of glass.'\n"+OFF);  
  return 1; } 

  if(present("digger",this_object())) {
    write("\nA soft voice speaks:\n\n"+
          YELLOW+"        'You must kill this warrior before you can strike the ter'angreal again.'\n"+OFF);
    say  ("\nA soft voice speaks:\n\n"+
          YELLOW+"      'Someone has tried to summon another warrior. This warrior must be killed first.'\n"+OFF);
    return 1;
  }
  write("\nA soft voice speaks:\n\n"+
        YELLOW+"'You struck the ter'angreal.  I shall release a warrior!'\n\n"+OFF+
        RED+"A mighty warrior is set free from the wall of glass...\n"+OFF);
  say("\nA soft voice speaks:\n\n"+
      YELLOW+"'"+this_player()->query_name()+" has struck the ter'angreal. I shall release a warrior!'\n\n"+OFF+
      RED+"A mighty warrior is set free from the wall of glass...\n"+OFF);
  move_object(clone_object("/players/fakir/woods/NPC/digger.c"),this_object());
  found=found-1; 
  return 1; 
}






