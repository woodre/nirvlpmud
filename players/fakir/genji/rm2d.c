#include "/players/fakir/color.h"
inherit "room/room";
int found;

reset(arg) {
  if(arg) return;
found = 1+random(2);
set_light(1);

short_desc = "Square Room of Stone (Shadowed)";
long_desc =
"   Walls of lucent stone rise on all sides, forming a square room of\n"+
"moderate size.  Trapped inside each wall, fat furry fighters stand\n"+
"frozen in time and space.  Heavy coiled ropes of braided skins rest\n"+
"within the left hand of each fighter, and red drops of blood show upon\n"+
"the braids.  The fighters each strain to escape the imprisoning walls.\n"+
"A stone 'square' glows with a dim light and hangs without support in\n"+
"the center of the room.  Three square doorways slowly rotate clock-wise\n"+
"within the stone walls.\n";

items = ({
"wall",    "Each wall holds fast a furry fighter, trapped inside",
"blood",   "Dark red blood from the veins of some defeated foe",
"room",    "A square room with walls of transparent stone",
"walls",   "Square in design, with sharp corners. They are made of lucent stone",
"fighters","Short and fat, they are covered entirely in fur.  Each carries a deadly rope",
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
notify_fail("\nA voice whispers:\n\n"+
         BLUE+"You must try to turn the square.\n"+OFF);
return 0; 
}

if(found==0) { tell_room(this_object(),"\nA voice whispers:\n\n"+
               BLUE+"     'I grow weary of watching you fight so poorly. I will no longer\n\n"+
                    "      free any warriors from the wall of stone.  Be gone with you now.'\n"+OFF);  
  return 1; } 

  if(present("digger",this_object())) {
    write("\nA voice whispers:\n\n"+
          BLUE+"        'It is foolishness to summon a warrior when you still have one to fight.'\n"+OFF);
    say  ("\nA voice whispers:\n\n"+
          BLUE+"      'Your friend has foolishly tried to summon another warrior without killing this one first?'\n"+OFF);
    return 1;
  }
  write("\nA voice whispers:\n\n"+
        BLUE+"'You have turned the magic square!  I shall test your ability as a fighter now!'\n\n"+OFF+
     BOLD+RED+"A fierce warrior is set free from the wall of stone...\n"+OFF);
  say("\nA voice whispers:\n\n"+
      BLUE+"'"+this_player()->query_name()+" has turned the square! I shall test you both now!'\n\n"+OFF+
     BOLD+RED+"A fierce warrior is set free from the wall of stone...\n"+OFF);
  move_object(clone_object("/players/fakir/woods/NPC/digger.c"),this_object());
  found=found-1; 
  return 1; 
}



