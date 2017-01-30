#define VOID "/players/feldegast/realm/void.c"
#include "/players/feldegast/defines.h"

inherit "/obj/armor.c";

reset(arg) {
  if(arg) return;
  set_name("cloak");
  set_type("misc");
  set_ac(2);
  set_short("A Midnight Cloak");
  set_weight(1);
  set_value(1200);
  set_long("This is a long cloak, midnight black in hue, made out of\n"+
          "fine spidersilk.  The cloak has a silver clasp with a\n"+
          "starburst emblazoned upon its surface.  You may 'gocloak'.\n");
}
init() {
  ::init();
  add_action("cmd_govoid","gocloak");
}
cmd_govoid() {
  int cost;
  string where;
  cost=55+random(5);
  if(TP->query_sp()<cost) {
    write("You try to teleport yourself from here, but lack the magical\n"+
           "energy needed to do so.\n");
    return 1;
  }
  if(environment(TP)->realm()=="NT") {
    write("You attempt to teleport yourself from here, but you are in\n"+
          "a no teleport zone.\n");
    return 1;
  }
  TP->add_spell_point(-cost);
  if(where=call_other("obj/base_tele","teleport")) {
    TP->move_player("with an astonished look#"+where);
     return 1;
  }
  write("You swirl the midnight cloak about yourself and find yourself in\n"+
        "a different place.\n");
  say(TPN+" swirls "+TP->query_possessive()+" midnight cloak about "+
      TP->query_objective()+"self and\n"+
      "suddenly disappears without a trace.\n");
  move_object(TP,VOID);
  return 1;
}
