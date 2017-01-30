#include "/sys/ansi.h"
inherit "/obj/armor";

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_name("armor");
  set_alias("leather");
  set_short(HIK+"A"+NORM+MAG+"rmor of the "+HIK+"D"+NORM+MAG+"arksong "+HIM+"["+NORM+"leather"+HIM+"]"+NORM);
  set_long("This leather armor has been dyed as black as the night sky. Runes\n"+
	   "have been pressed into the armor and they glow with a bright magenta\n"+
           "hue. Muse the Lich used this armor to protect herself from her own\n"+
           "sonic abilities. This helped her maintain the facade of a bard for\n"+
           "so long.\n");
  set_params("other|sonic",0,25,0);
  set_ac(3);
  set_type("armor");
  set_weight(2);
  set_value(10000);
}