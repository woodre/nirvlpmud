#include "/players/fakir/color.h"
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
found = 1+random(2);
set_light(1);

short_desc = "Square Room of Stone (Lucent)";
long_desc =
"   Walls of lucent stone form a square room of moderate size.  Trapped\n"+
"inside each wall, fat furry fighters stand frozen in time and space.\n"+
"Heavy coiled ropes of braided skins rest within the left hand of each\n"+
"fighter, and red drops of blood show upon the braids.  Each of the fighters\n"+
"strain to escape the imprisoning walls.  A stone 'square' glows with a dim\n"+
"light and hangs without support in the center of the room.  Three square\n"+
"doorways slowly rotate clock-wise within the stone walls.\n";

items = ({
"wall",    "It is made entirely of lucent stone of unknown origin",
"room",    "A square room with walls of lucent stone",
"walls",   "Square in design, with sharp corners. They are made of lucent stone",
"fighters","Short and fat, they are covered in short fur. Each carries a deadly rope",
"ropes",   "Braided from the skins of unknown foes, they glisten with blood",
"square",  "A square stone imbued with strange magics.\n"+
           "Can you resist the urge to 'turn' the square?",
"stone",   "Enchanted with a strange magic, it glows with a dim light",
"doorways","Square doors that turn clock-wise at a slow but steady pace",
});

dest_dir = ({
"/players/fakir/genji/rm1c","door1",
"/players/fakir/genji/rm3c","door2",
"/players/fakir/genji/rm5c","door3",
});
}
init()  {
  ::init();
    add_action("turn_square","turn");
}
turn_square(arg)  {
if(!arg || arg != "square") {
notify_fail("\nA female voice softly speaks:\n\n"+
         WHITE+"You must turn the square, and be very brave.\n"+OFF);
return 0; 
}

if(found==0) { tell_room(this_object(),"\nA female voice softly speaks:\n\n"+
               WHITE+"     'The square seems to have lost all its magic.  I will need to\n\n"+
                     "      rest before I can free anymore warriors from the wall of stone.'\n"+OFF);  
  return 1; } 

  if(present("digger",this_object())) {
    write("\nA female voice softly speaks:\n\n"+
          WHITE+"        'Beware adventurer...you must kill this warrior before you summon more.'\n"+OFF);
    say  ("\nA female voice softly speaks:\n\n"+
          WHITE+"      'You must kill this warrior before I will release another.'\n"+OFF);
    return 1;
  }
  write("\nA female voice softly speaks:\n\n"+
        WHITE+"'You are very brave to turn the square.  I shall release a warrior for you to battle!'\n\n"+OFF+
     BOLD+RED+"A fierce warrior is set free from the wall of stone...\n"+OFF);
  say("\nA female voice softly speaks:\n\n"+
      WHITE+"'"+this_player()->query_name()+" has turned my magic square! I shall release a warrior!'\n\n"+OFF+
     BOLD+RED+"A fierce warrior is set free from the wall of stone...\n"+OFF);
  move_object(clone_object("/players/fakir/woods/NPC/digger.c"),this_object());
  found=found-1; 
  return 1; 
}
