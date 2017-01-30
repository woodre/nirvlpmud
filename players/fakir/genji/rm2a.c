#include "/players/fakir/color.h"
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
found = 1+random(3);
set_light(1);

short_desc = "Ter'angreal of Stone (Obscure)";
long_desc =
"   Smooth walls of obscure stone entomb your floating body.  Encased\n"+
"within each wall, fur covered warriors stand in various positions of\n"+
"combat.  Brightly colored rings of red, blue, or green adorn the neck\n"+
"of each warrior, and pulse with a subdued power.  The furry beings stare\n"+
"without expression, but strain to escape the imprisoning walls.  A square\n"+
"stone "+BROWN+"'ter'angreal'"+OFF+" glows with a dim aura and hangs without support in\n"+
"the center of the room.  Three square doorways turn steadily clock-wise\n"+
"within the stone walls.\n";

items = ({
"room",         "A square room with walls of transparent stone",
"wall",         "Transparent stone of unknown origin and strange design",
"walls",        "They are made of a transparent stone of unknown origin",
"warriors",     "Short, fur covered beings with colored rings of power about thier necks",
"rings",        "Brightly colored, the rings appear to be a signal of rank among the furries",
"ter'angreal",  "A square stone ter'angreal imbued with strange magics.\n"+
                "Can you resist the urge to 'turn' the ter'angreal?",
"stone",        "Enchanted with a strange magic, it glows with a dim light",
"doorways",     "Square doors that turn clock-wise at a slow but steady pace",
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
