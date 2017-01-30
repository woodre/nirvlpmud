#include "/sys/ansi.h"
inherit "/obj/armor";

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_name("cloak");
  set_alias("cape");
  set_short(HIK+"C"+NORM+MAG+"loak of the "+HIK+"D"+NORM+MAG+"arksong "+HIM+"["+NORM+"silk"+HIM+"]"+NORM);
  set_long("The Cloak of the Darksong is a fine silk cloak. The outside of the cloak is the color\n"+
           "of the night sky while the inside is a brilliant magenta. It closes around the neck\n"+
           "with a mithril and amethyst clasp. It was once worn by Muse, the Dark Bard.\n");
  set_params("other|sonic",0,20,0);
  set_ac(0);
  set_type("cloak");
  set_weight(1);
  set_value(5750);
}