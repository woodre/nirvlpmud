#include "/players/khrell/ansi.h"


 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("slayer");
    set_alt_name("sword");
    set_alias("demon");
    set_short(RED+"Slayer of Kings"+NORM+" the"+HIK+" Demonic sword"+NORM);
    set_long("     Inside this blade is trapped the greater daemon of\n\
chaos, U'Zhul.  Aeons of imprisonment have driven it mad\n\
with rage.  Dire runes adorn the length of the blade and\n\
they pulse with a life of their own.  Holding it in ones\n\
hand give one power but at a price few are willing to pay.\n");
    set_read("The runes hurt your eyes to even look at them\n");
    set_class(18);
    set_weight(4);
    set_value(10000);
    set_hit_func(this_object());
}
status query_wear() {
  return 0;
}    
status weapon_breaks() { return 0; }
status re_break() { return 0; }
