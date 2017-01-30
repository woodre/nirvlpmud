/*HUMBLE CORPS 2004*/
#include "../defs.h"

inherit "/obj/monster";

reset(arg) {
    object gold, flowers;
    ::reset(arg);
    if (!arg)  {
       gold = clone_object("obj/money");
    money=random(1000);
       move_object(gold,this_object());
      set_name("Cici");
    set_alt_name("cici");
    set_alias("cici");
    set_short(HIY+"Cici"+NORM);
    set_race("human");
    set_long(
    "Cici is an elderly woman who appears to be in her 60s.\n"+
    "She is QFC's florist.  She has bright red curly hair, what an innocent\n"+
    "creature.\n");
    set_gender("female");
    set_level(14);
    set_ac(11);
    set_wc(18);
    set_hp(240);
    set_al(850);
    set_chat_chance(5);
    load_chat(HIW+"Cici hums to herself as she waters her flowers.\n"+NORM);
}
  }
