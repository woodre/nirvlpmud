#include "/players/eurale/defs.h"
inherit "obj/monster";
object gold;
int FIGHTING;

reset(arg)  {
  ::reset(arg);
  if(arg) return;
FIGHTING = 0;

set_name("girl");
set_alias("vampire");
set_race("undead");
set_gender("female");

set_short(BOLD+"lovely young girl"+NORM);
set_long(
  "This lovely young lady looks to be about 15 years old.  Her face\n"+
  "is covered with freckles and her eyes are a beautiful robins egg\n"+
  "blue.  She stands about 5'6: with curly auburn hair and a slender\n"+
  "build.\n");

set_level(19);
set_hp(850);
set_al(0);
set_wc(47);
set_ac(17);
set_heal(3,2);
set_aggressive(0);
set_dead_ob(this_object());

set_chance(14);
set_spell_dam(9 + random(25));

set_spell_mess1(
  "The Vampire concentrates and STARES at her foe!\n\n");

set_spell_mess2(
  "You feel your head about to "+BOLD+"EXPLODE"+NORM+" when the "+
  BOLD+"Vampire GLARES at you!\n\n"+NORM);

gold = clone_object("obj/money");
gold->set_money(2000);
move_object(gold, TO);
}

init() {
  ::init();
  add_action("no_brandish","brandish");
  add_action("out","out");
  add_action("no_quit","quit");
}

no_quit(){
  write(
  "The "+BOLD+"Vampire CACKLES DEMONICALLY"+NORM+" at your feeble "+
  "attempt to quit.\n\n");
  TP->hit_player(35 + random(25));
  return 1; }

out() {
if(TP->query_ghost()) { write(
  "The girl giggles as your ghost slips past her on the way out.\n");
  TP->move_player("out#players/eurale/VAMPIRES/RMS/foyer.c");
  return 1; }
write(
  "A "+HIR+"SHARP PAIN"+NORM+" shoots through your head as you "+
  "struggle to escape.\n\n");
TP->hit_player(22 + random(13));
return 1;
}

no_brandish(str) {
object wand;
wand = present("wand",TP);
tell_room(environment(TO), BOLD+
  "The girl "+HIR+"SQUINTS"+NORM+" and your wand disappears.\n\n");
  TP->hit_player(20 + random(16));
  destruct(wand);
  return 1; }

monster_died() {
object ob;
tell_room(environment(TO),HIR+
  "As the young girl dies, she whispers 'Congratulations NEOPHYTE!'\n\n"+
  NORM);
  write_file("/players/eurale/VAMPIRES/TRIALS",
    ctime(time())+"  "+capitalize(TPRN)+" completed Trial 3.\n");
("/players/eurale/VAMPIRES/RMS/foyer.c")->set_ONE(0);
TP->add_guild_exp(1);
TP->save_me();
return 0; }

heart_beat() {
  ::heart_beat();
if(!environment()) return;
if(present("pet",environment(TO))) {
  call_out("no_pet",1);
  return 1; }
return 1; }

no_pet() {
object dob;
dob = present("pet",environment(TO));
tell_room(environment(TO),
  "\nThe "+BOLD+"Vampiress "+HIR+"GLARES"+NORM+" at you in disgust...\n"+
  "And then with "+HIY+"LIGHTNING SPEED"+NORM+" she attacks your pet.\n"+
  "With "+BOLD+"TALONED CLAWS"+NORM+" she "+HIR+"DISEMBOWELS"+NORM+
  " it and devours the corpse...\n\n");
  destruct(dob);
return 1; }
