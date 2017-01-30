#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
#include "/players/fakir/color.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Winespring Inn";
long_desc =
   "The massive grey slate fireplace looms before you, its firebox glowing\n"+
   "with the coals from a split log fire.  The firebox is fully three spans\n"+
   "in width, with a raised hearth half a span high.  The black cast iron\n"+
   "grate holding the logs is at least as thick as a mans wrist, and glows\n"+
   "from the heat.  The damper chain is pulled open and the draft from the\n"+
   "chimney pulls the smoke and fumes from the logs up and out of the fire-\n"+
   "box.  A small amout of smoke escapes the firebox and swirls upward in\n"+
   "wispy tails toward the ceiling and across the keystone of the arch\n"+
   "above the firebox.\n";

items = ({
   "fireplace", "Grey slate embedded in red mortar covers the entire wall\n"+
                "from floor to ceiling.  The slate is irregular and has fossil\n"+
                "leaves and insects etched in its rough surface from place to\n"+
                "place.  The slate has been set with great care by a master\n"+
                "craftsman, perhaps even an Ogier",
   "firebox",   "Large by any standard, this firebox is half again as tall as\n"+
                "a grown man and almost twice as wide.  Three huge logs rest\n"+
                "on a cast iron grate and burn slowly from the center out",
   "coals",     "Red hot and glowing, they turn to lighter shades of grey at\n"+
                "the outer edge of the pit as they cool",
   "fire",      "Just what you would expect, its hot and it will burn you!",
   "hearth",    "A raised portion of slate built out from the firepit the\n"+
                "width of the firebox.  It protrudes slightly into the room",
   "grate",     "Chared black from endless fires, it still holds its original\n"+
                "shape and form...a testament to the skill of the village\n"+
                "blacksmith in days gone by",
   "logs",      "Roughly a quarter span thick and a full span long, the\n"+
                "hardwood logs burn slowly and give off a great deal of\n"+
                "heat.  You wonder who was strong enough to put them in\n"+
                "the firebox in the first place",
   "chain",     "A long black linked chain used to open and shut the damper",
   "smoke",     "White with a tinge of grey, only a small amout escapes into\n"+
                "the room",
   "chimney",   "That portion of the fireplace which channels the smoke up\n"+
                "and out of the firebox.  It too is made of stone, but the\n"+
                "mortar holding this slate is a dark grey rather than red",
   "keystone",  "Wider at the top than at the bottom, it acts as a wedge and\n"+
                "binds the arch, holding it in place as if by magic.  This\n"+
                "keystone has some Ogier runes inscirbed upon it",
   "ceiling",   "Ten feet off the floor, it is made of interlocking knotted wood\n"+
                "planks, and is discolored a dark shade of grey here by the smoke\n"+
                "that sometimes escapes the firebox", 
   
   
   
   
});
if(!present("haral",this_object()))
 move_object(clone_object("/players/fakir/inn/NPC/haral.c"),this_object());
dest_dir = ({
   "/players/fakir/inn/room10.c", "north",
   "/players/fakir/inn/room12.c", "east",
   "/players/fakir/inn/room2.c",  "west",
   "/players/fakir/inn/room3.c",  "northwest",
   "/players/fakir/inn/room13.c", "northeast",
});
}
init()  {
  ::init();
  add_action("read","read");
  add_action("look","look");
  add_action("l","l");
}

read(arg) {
  write(CYAN+"The runes speak to your mind:\n\n"+OFF);
  write(RED+"\t~Beware~ ~the~ ~waygates~. ~Evil~ ~has~ ~taken~ ~hold~ ~there~.\n");
  write("\t~The~ ~day~ ~becomes~ ~night~.  ~What~ ~was~ ~good~ ~now~ ~hungers~.\n\n\n"+OFF);
  say  (TPN+" reads some ogier runes.\n");
  return 1;
}
look(arg) {
  write("Perhaps you should read the runes.\n");
  return 1;
}
l(arg)  {
  write("Perhaps you should read the runes.\n");
  return 1;
}



