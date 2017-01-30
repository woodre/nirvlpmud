#include "/players/mythos/closed/guild/def.h"
nightmare_maj() {
object ob;
  write("someone abused this and got boltar yelling.. its gone.\n- Mythos <7-22-1998>\n");
return 1;
if(qtf < 10) { write("Your control over fae is not enough!\n"); return 1;}
if(tsp < 25) { write("You do not have enough energy!\n"); return 1;}
if(scrp < 75) { write("The darkness calls for a sacrifice.\n"); return 1;}
ob = clone_object("/players/mythos/closed/guild/spells/monster2.c");
ob->set_name("nightmare");
ob->set_race("demon");
ob->set_alias("demonling");
ob->set_short("Demonling");
ob->set_long("A thing of hideous features. \nA being that exists to torment others.\n");
ob->set_al(-random(1000));
ob->set_hp(100+random(10+qtf));
ob->set_level(5+random(qtf/2));
ob->set_wc(7+random(qtf/2));
ob->set_ac(random(qtf/2));
ob->set_aggressive(0);
ob->set_spec_aggres();
ob->set_can_kill(1);
ob->set_exx(0);
if(0== random(4)) {
ob->set_wander();}
ob->set_a_chat_chance(10);
ob->load_a_chat("The Demonling screams!\n");
ob->load_a_chat("The Demonling lashes out with its claws!\n");
move_object(ob,environment(tp));
tp->add_spell_point(-25);
pp->add_sacrifice(-75);
write("You allow fear and hunger to envelope you.\n"+
      "A Nightmare appears.\n");
say("A Demonling comes into existance.\n");
return 1;}
