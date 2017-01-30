#include "/players/tristian/lib/ansi.h"
inherit"obj/weapon";


reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("A silver scimitar named 'Twinkle'");
    set_alt_name("twinkle");
    set_alias("scimitar");
    set_short("A silver scimitar named "+HIB+"'Twinkle'"+NORM);
    set_long("Drizzt Do'Urden's famous scimitar named 'Twinkle'.\n"+
      "It is a beautifully crafted weapon that is balanced for battle.\n"+
      "Along the blade are finely crafted runes that seem to glow with\n"+
      "with an eerie light of it's own.  It feels like the sword wants\n"+
      "to feed on all the "+RED+"fire"+NORM+" in the room.\n");
    set_value(2500);
    set_weight(2);
    set_class(100);
    set_hit_func(this_object());
}
weapon_hit(attacker) {
    int i, heal, mons;
    i = random(100);
    heal = (random(75)+25);
    mons = (random(5000)+25);
    if(i > 80){
        write("Twinkle draws the life force from "+attacker->query_name()+" and you feel it drain into you.\n\n");
        attacker->heal_self(-mons);
        this_player()->add_hit_point(heal);
    }
  return 1;
}

void init() {
  if (this_player()->query_level() < 40)
    destruct(this_object());
}
