#include "/sys/ansi.h"
inherit "/obj/armor";

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_name("circlet");
  set_alias("helm");
  set_short(HIK+"C"+NORM+MAG+"irclet of the "+HIK+"D"+NORM+MAG+"arksong "+HIM+"["+NORM+"mithril"+HIM+"]"+NORM);
  set_long("This circlet is composed of braided bands of mithril that are studded with glowing\n"+ 
           "amethyst stones. This circlet was once worn by the Lich Demon Muse in her bard form.\n"+
           "It is said that this circlet awarded her protection from all manner of sound\n"+
           "barrages or attacks.\n");
  set_params("other|sonic",0,10,0);
  set_ac(1);
  set_type("helmet");
  set_weight(1);
  set_value(2750);
}