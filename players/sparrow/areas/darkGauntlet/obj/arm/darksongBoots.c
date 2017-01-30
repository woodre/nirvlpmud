#include "/sys/ansi.h"
inherit "/obj/armor";

void reset(status arg) {
  ::reset(arg);
  if(arg) return;

  set_name("boots");
  set_short(HIK+"B"+NORM+MAG+"oots of the "+HIK+"D"+NORM+MAG+"arksong "+HIM+"["+NORM+"leather"+HIM+"]"+NORM);
  set_long("These leather boots were once worn by the Lich Demon Muse. She used these\n"+
           "boots to help protect her from her own sonic magic, giving the impression\n"+
           "of being a powerful bard with tremendous ability of song. These boots are\n"+
           "made of incredibly black stained leather with glowing magenta runes etched\n"+
           "into the soles\n");
  set_params("other|sonic",0,10,0);
  set_ac(2);
  set_type("boots");
  set_weight(1);
  set_value(3750);
}