#include "/players/feldegast/defines.h"
inherit ROOM;
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="A hut on the beach";
  long_desc=
"     The chief man's hut also doubles as an office and\n"+
"meeting hall for the rest of the village.  A long table\n"+
"surrounded by chairs runs the length of the hut.  A cot\n"+
"lies in the back of the hut for the chief man to sleep in.\n";
  items=({
    "table","An old table approximately 3 meters long made out\n"+
            "of bamboo",
    "chairs","Wicker chairs with cushions on each seat",
    "cot","A spartan pallet"
  });
  dest_dir=({
    "/players/feldegast/island/beach4","out"
  });
}

init() {

  ::init();
  add_action("sell","sell");
  add_action("buy","buy");
}
sell(str) {
  object ob;
  if(!str) { write("Sell what?\n"); return 1; }
  ob=present(str,this_player());
  if(!ob) { write("That is not present.\n"); return 1; }
  this_player()->add_money(ob->query_value());
  write("You get "+ob->query_value()+" coins for "+ob->short()+".\n");
  destruct(ob);
  return 1;
}
