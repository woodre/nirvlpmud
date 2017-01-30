#include "def.h"

inherit AROOM;

reset(arg) {
  object body;
  ::reset(arg);
  if(arg) return;
  body=clone_object("/obj/corpse");
  body->set_name("Escher");
  move_object(body,this_object());
  set_light(1);
  short_desc="The Shop";
  long_desc=
"  A creaky old wagon, once filled to overflowing with food and\n"+
"supplies, sits at the bottom of a low green hill which is dotted\n"+
"with trees.  Not far to the north, the grassland turns to forest.  To\n"+
"the west, you see more rolling grassland.  The bloody remains of\n"+
"what might once have been a human being are strewn across the hill\n"+
"and it appears whoever it was didn't die quickly.  There is a river\n"+
"to the east.\n";
  items=({
    "wagon",
"The creaking old covered wagon is filled to overflowing with food\n"+
"and supplies.  A painted sign is hung upon the side of the wagon",
    "food","You'd have to look at a <"+HIG+"list"+NORM+"> of all the food\nand supplies",
    "supplies","You'd have to look at a <"+HIG+"list"+NORM+"> of all the food\n and supplies",
    "hill","A low green hill, dotted with trees, rises to the south and east",
    "forest","A thick green forest is to the north",
    "grassland","Lush green crabgrass covers the hills to the west",
    "sign","A painted sign with a <"+BOLD+"list"+NORM+"> of items and prices",
  });
  dest_dir=({
    PATH+"m6","north",
    PATH+"m8","west",
    PATH+"m10","east",
  });
}
init() {
  ::init();
  add_action("cmd_list","list");
  add_action("cmd_buy","buy");
}
cmd_list() {
  write(
"\t     Master Escher's Food and Supplies\n"+
"\tltab.................................2700\n"+
"\tlblast,lgoop.........................1500\n"+
"\tsoco,juice,biscuits..................1800\n"+
"\torange...............................1600\n"+
"\tpotion of full healing..............10000\n"+
"\thalberd..............................3000\n");
  say(TPN+" looks at the price list.\n");
  return 1;
}
cmd_buy(str) {
  string file;
  int weight,value;
  if(!present("escher")) {
    write("The merchant has been murdered.\n");
    return 1;
  }
  switch(str) {
    case "ltab":
      file="/players/snow/heals/lumorph"; value=2700; weight=1; break;
    case "lblast":
      file="/players/snow/heals/lpblast"; value=1500; weight=1; break;
    case "lgoop":
      file="/players/snow/heals/lsgoop"; value=1500; weight=1; break;
    case "soco":
      file="/players/feldegast/arena/heals/soco"; value=1800; weight=3; break;
    case "juice":
      file="/players/feldegast/arena/heals/juice"; value=1800; weight=3; break;
    case "biscuits":
      file="/players/feldegast/arena/heals/biscuits"; value=1800; weight=3; break;
    case "orange":
      file="/players/wocket/std/orange"; value=1600; weight=1; break;
    case "potion":
      file="/players/feldegast/arena/heals/fullheal"; value=10000; weight=1; break;
    case "halberd":
      file="/players/feldegast/wep/halberd"; value=3000; weight=5; break;
    default: write("The merchant says: I'm afraid I don't have any of those, but I will keep an\n"+
             "eye out for one for you.\n");
             return 1;
             break;
  }
  if(TP->query_money() < value) {
    write("The merchant says: I apologize, effendi, but I could not possibly let\n"+
          "that item go for less than "+value+" coins.\n");
    return 1;
  }
  if(!this_player()->add_weight(weight)) {
    write("The merchant says: I apologize, effendi, but you do not appear to be capable of\n"+
          "carrying any more weight.\n");
    return 1;
  }
  TP->add_money(-value);
  write("You buy a "+str+" from the merchant for "+value+" coins.\n");
  say(TPN+" buys a "+str+" from the merchant.\n");
  move_object(clone_object(file),TP);
  return 1;
}
