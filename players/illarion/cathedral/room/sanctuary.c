#include "../def.h"

inherit "/players/illarion/room";

void reset(status arg) {
  if(arg) return;
  
  set_short("The Cathedral Sanctuary");
  set_long("\
Long beams of colored sunlight stream down from overhead stained glass windows onto a large marble altar.  \
The altar sites on a wide marble base, which is three marble steps above an even wider \
expanse of marble floor.  Wide, heavily carved railings enclose the altar to the east \
and west, sloping up to a statue-covered wall to the north.  At the bottom of the stairs, \
a plush red carpet stretches off to the south, and there are aisles to both the east and west.\n");
  
  add_exit("west",ROOM+"sanctuary_aisle_west");
  add_exit("east",ROOM+"sanctuary_aisle_east");
  add_exit("south",ROOM+"choir");
  
  set_light(1);
  
  add_item("beams","Long beams of brilliantly colored light.");
  add_item("light","Impossibly bright, yet not painful.   Magic is clearly at play here.");
  add_item("windows","Huge stained glass windows, casting bright, beautiful light downward.  "
          +"The scenes depicted on them are not the usual subject matter.");
  add_item("scenes","The stained glass windows depict a number of unclothed and half-closed men "
          +"and women, engaged in a startling variety of explicitly carnal acts.");
  add_item("altar","A wide marble altar, with detailed friezes engraved into each side.  "
          +"A wide golden piece of cloth stretches across the top.");
  add_item("cloth","A golden piece of velvet atop the altar.");
  add_item("friezes","In a clearly-marked series around the altar, the friezes depict a man and a "
          +"woman giving each other pleasure, in progressively kinkier ways.  The climax, directly "
          +"on the front of the altar, would make a Bene Gesserit blush.");
  add_item("marble","It looks like pure white marble, but it is warm to the touch, and far softer "
          +"than natural stone ought to be.");
  add_item("railings","Steeply angled railings that enclose the altar.  They are covered in carvings.");
  add_item("carvings","Carved into the railings are alternating depictions of ideals of the male "
          +"and female forms, each more beautiful than the last.");
  add_item("statues","Two huge statues cover the wall behind the altar, one male, one female, "
          +"their bodies unclothed and thoroughly intertwined.");
  add_item("stairs","Broad marble stairs.");
  add_item("carpet","A luxuriously deep and soft red velvet carpet.");
    
  set_etime_const(600);
  set_etime_rand(120);
  add_room_emote("The brightly-colored beams of light shift slowly across the altar.");
  add_room_emote("A soft, passionate moan can be heard echoing from somewhere in the cathedral.");
  
}

void init() {
  ::init();
}