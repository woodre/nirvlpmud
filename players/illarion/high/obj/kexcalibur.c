/* weapon for high/mon/killian.c */
#include "/players/illarion/dfns.h"
inherit "/obj/weapon.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("longsword");
  set_alt_name("sword");
  set_short("A gold-trimmed, ornate longsword");
  set_long(
"Elabroately engraved gold grim covers the crosspiece and pommel of this\n"+
"sword, and similar patters are etched along the blade.  However, the\n"+
"beauty of the decorations cannot conceal that this sword's primary\n"+
"purpose is to kill: the blade is sharp and nearly unbreakable, and the\n"+
"hilt is wrapped leather, not pretty, but unlikely to slip even in a\n"+
"slick with sweat or blood.\n");
  set_class(18);
  set_weight(5);
  set_value(10000);
  set_hit_func(this_object());
}
weapon_hit() {
  /* More here later */
}
