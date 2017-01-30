#include <ansi.h>;
inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  ::reset(arg);
  set_name("skull");
  set_short("An "+MAG+"A"+HIK+"lien"+NORM+"'s skull");
  set_long("This shield is nothing more than an emptied alien skull. It\n"+
           "still looks fully intact on the outside. It is probably very\n"+
           "effective protection against most corrosive substances\n");
  set_type("shield");
  set_ac(3);
  set_weight(2);
  set_value(10000);
}

do_special(owner){
  if(!worn) return;
  if(random(20) < 8)
  {
    write("The alien skull deflects your opponent's attack.\n");
    owner->add_hit_point(random(5));
    return 1;
  }
  return;
}
