#include "/players/fakir/color.h"
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
found = 1+random(3);
set_light(1);

short_desc = "Ter'angreal of Stone (Obscure)";
long_desc =
"   A lucent, oblong room of crystal holds several hump-backed fighters captive\n"+
"within its walls and they struggle to escape.  Their movements are very slow and\n"+
"prolonged, as if time for them were moving at a much slower pace.  Each fighter\n"+
"holds a colored sphere in his right hand.  A delicate, oblong crystal "+WHITE+"'ter'angreal'"+OFF+"\n"+
"floats in the center of the room.  Three doors glide in random motion about the wall.\n"; 

items = ({
"room",        "An oblong room with walls of transparent crystal",
"fighter",     "Short hump-backed beings with thick arms and legs",
"wall",        "A single oblong wall of transparent crystal which surrounds you on all sides",
"sphere",      "A round sphere the size of a small fruit which glows bright white",
"crystal",     "A magical crystal ter'angreal. It shimmers with a dim light.\n"+
               "A few brave souls have attempted to 'invoke' the ter'angreal",
"doors",       "Oblong openings which glide about the wall in random directions",
});


dest_dir = ({
"/players/fakir/genji/rm1b","door1",
"/players/fakir/genji/rm3b","door2",
"/players/fakir/genji/rm5b","door3",
});
}
init()  {
  ::init();
    add_action("turn_terangreal","turn");
}
turn_terangreal(arg)  {
if(!arg || arg != "ter'angreal") {
notify_fail("A harsh voice rumbles:\n\n"+
         BROWN+"Try to turn the ter'angreal...oh idiot one.\n"+OFF);
return 0; 
}

if(found==0) { tell_room(this_object(),"\nA harsh voice rumbles:\n\n"+
               BROWN+"     'You have used up all the magic in the ter'angreal!  I can\n\n"+
                     "      no longer free any warriors from the wall of stone.'\n"+OFF);  
  return 1; } 

  if(present("digger",this_object())) {
    write("\nA harsh voice rumbles:\n\n"+
          BROWN+"        'Foolish one.  You must kill this warrior before you summon more.'\n"+OFF);
    say  ("\nA harsh voice rumbles:\n\n"+
          BROWN+"      'Your friend has foolishly tried to summon another warrior without killing this one first!'\n"+OFF);
    return 1;
  }
  write("\nA harsh voice rumbles:\n\n"+
        BROWN+"'You have turned the ter'angreal!  I shall release a furrie warrior!'\n\n"+OFF+
     BOLD+RED+"A furrie is set free from the wall of stone...\n"+OFF);
  say("\nA harsh voice rumbles:\n\n"+
      BROWN+"'"+this_player()->query_name()+" has turned the ter'angreal! I shall release a warrior!'\n\n"+OFF+
     BOLD+RED+"A furrie warrior is set free from the wall of stone...\n"+OFF);
  move_object(clone_object("/players/fakir/woods/NPC/digger.c"),this_object());
  found=found-1; 
  return 1; 
}
