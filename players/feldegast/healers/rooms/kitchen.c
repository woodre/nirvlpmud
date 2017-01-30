#include "def.h"

inherit "/players/feldegast/std/generic_pub.c";

reset(arg) {
  ::reset(arg);

  if(!present("tanya"))
    move_object(clone_object(NPCPATH+"tanya.c"), this_object());

  if(arg) return;

  set_light(1);

  short_desc=AREANAME;
  long_desc=
"  This room is aswirl with the fresh smells of bread baking and soups\n"+
"simmering.  Neatly arranged cooking implements are hung by hooks from\n"+
"the ceiling around a cutting table in the center of the L shaped room.\n"+
"In the corner of the L is a huge baking oven.  Along the long part is\n"+
"a fireplace with a huge kettle of soup boiling.  A door leads east back\n"+
"into the hall, while another one leads north.\n";

  items=({
    "implements","Assorted cooking tools, such as large spoons, bowls, collanders,\n"+
                 "wire whisks, and other items",
    "table","A simple, but sturdy table scarred by cutting knives and hot pans",
    "oven","You see fresh bread baking in the oven through the window",
    "fireplace","A brick fireplace used for roasting meat and boiling soups",
    "kettle","A pot would call it black",
    "soup","Delicious soup, spiced to perfection by a magnificent cook",
  });

  dest_dir=({
    ROOMPATH+"workshop","north",
    ROOMPATH+"hall","east"
  });
  set_prop("kitchen proprietor");
  add_item("A loaf of bread", ({ "loaf", "bread" }),
           "You order a loaf of fresh baked bread slathered with fresh-churned butter.\n",
           " orders a loaf of bread.\n",
           240, 35, 14, "stuff");
  add_item("Tubor Root Tea", ({ "tea", "root tea" }),
           "You order a fresh hot cup of tubor root tea, a well-known remedy for\n"+
           "common aches and ills.\n",
           " orders a cup of tubor root tea.\n",
           240, 35, 14, "soak");
  add_item("Tanya's Terrible Tonic", ({ "tonic", "ttt" }),
           "You order a bubbling beaker of Tanya's Terrible Tonic.  Holding your\n"+
           "nose, you bravely pour it down the hatch.  You immediately feel MUCH\n"+
           "better, if you ignore the taste in your mouth.\n",
           " orders some of Tanya's Terrible Tonic.\n",
           240, 35, 14, "intox");
  add_item("Blueberry Pie", ({ "pie", "blueberry pie" }),
           "You order a slice of bubbling hot blueberry pie.  Mmm!\n",
           " orders a slice of blueberry pie.\n",
           800, 50, 12, "stuff");
  add_item("Joyous Juice", ({ "juice", "joyous juice" }),
           "You order some of the so-called joyous juice; a blend of 8 vegetables\n"+
           "mixed with the water from a mountain spring.  It tastes familiar.\n",
           " orders some v-8.\n",
           800, 50, 12, "soak");
  add_item("Mystic's Medicine", ({ "medicine", "mm" }),
           "You order some of the powerful clear liquid in a shot glass.  Within\n"+
           "seconds you're transcending the physical plane and feeling no pain.\n",
           " orders some mystic's medicine.\n",
           800, 50, 12, "intox");
}

realm() { return "NT"; }
