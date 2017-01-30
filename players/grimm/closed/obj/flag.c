#include "/players/grimm/esc.real.h"
inherit "/obj/treasure";
reset(arg) {
  if(arg) return;
  set_short("flag");
set_long(WHITE+"A "+RED+"F"+GREEN+"l"+BROWN+"a"+BLUE+"g"+PURPLE+"."+END+"\n");
  set_alias("flag");
  set_weight(0);
  set_value(0);
}
