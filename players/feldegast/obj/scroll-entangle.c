#include "/players/feldegast/defines.h"
inherit "/obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("scroll");
  set_alias("tangle vine");
  set_short("Scroll: "+HIG+"Tangle Vine"+NORM);
  set_long(
"Magic formulae and incantations are inscribed in a spidery script on\n"+
"a tightly rolled vellum scroll.  The scroll smells of dust and the\n"+
"reagents of powerful magic.  Perhaps you could 'cast' the spell.\n"
  );
  set_weight(1);
  set_value(1000+random(500));
}
init() {
  ::init();
  add_action("cmd_cast","cast");
}

static cmd_cast(str) {
  object attacker;
  notify_fail("Cast what?\n");
  if(!str || str!="tangle vine") return 0;
  attacker=TP->query_attack();
  if(!attacker) {
    write("This spell can only be cast while in combat.\n");
    return 1;
  }
  tell_room(environment(TP),TPN+" unrolls a scroll and begins reading it.\n");
  call_out("do_spell",1,attacker);
  TP->add_spell_point(-10);
  move_object(this_object(),"/players/feldegast/realm/void");
  TP->recalc_carry();
  return 1;
}
do_spell(attacker) {
  object vine;
  if(!attacker)
    tell_object(environment(this_object()),"Your spell fails!\n");
  tell_room(environment(attacker),
"A "+HIG+"tangle vine"+NORM+" sprouts beneath "+attacker->query_name()+" and wraps "+attacker->query_objective()+"\n"+
"in its tendrils.\n");
  vine=clone_object("/players/feldegast/mon/tangle_vine");
  move_object(vine,environment(attacker));
  attacker->attack_object();
  attacker->attack_object(vine);
  tell_object(environment(),"Check.\n");
  destruct(this_object());
}

