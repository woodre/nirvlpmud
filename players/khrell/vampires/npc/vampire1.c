#include "/players/eurale/defs.h"
inherit "obj/monster";
object gold;
int FIGHTING;

reset(arg)  {
  ::reset(arg);
  if(arg) return;
FIGHTING = 0;

set_name("vampiress");
set_alias("vampire");
set_race("undead");

set_short(BOLD+"stern vampiress"+NORM);
set_long(
  "Palid of skin and with emerald green eyes, this lithe figure is\n"+
  "much more than she appears.  Her youth and beauty belies the fact\n"+
  "that she is centuries old.  Slender fingers with sharp talon-like\n"+
  "nails indicate that she would be an apt killer if she were to be\n"+
  "so inclined.  Walking among the living, she would pass as one of\n"+
  "them until it was her turn to feed.\n");

set_level(15);
set_hp(400);
set_al(0);
set_wc(33);
set_ac(13);
set_heal(2,3);
set_aggressive(0);
set_gender("female");
set_dead_ob(this_object());

set_chance(12);
set_spell_dam(5 + random(16));

set_spell_mess1(
  "The "+BOLD+"Vampiress "+HIR+"SCRATCHES a LONG GASH"+NORM+" in "+
  "its opponents throat.\n");

set_spell_mess2(
  "The "+BOLD+"Vampiress "+HIR+"SCRATCHES a LONG GASH"+NORM+
  " in your throat!\n");

gold = clone_object("obj/money");
gold->set_money(875);
move_object(gold,TO);
}

init() {
  ::init();
  add_action("out","out");
  add_action("no_quit","quit");
  add_action("No_staff","staff_blast");
  add_action("No_staff","staff_heal");
}

No_staff() {
  write("The vampiress snears, 'That puny staff will help you NOT\n"+
        "during your trial....\n\n");
  return 1; }

no_quit(){
  write(
    HIR+"'COWARD!'"+NORM+", hisses the "+BOLD+"Vampiress"+NORM+"....\n"+
    HIR+"'Either you or I will DIE... no QUITTING!\n\n"+NORM);
  TP->hit_player(30 + random(10));
  return 1; }

out() {
if(TP->query_ghost()) {
  write("The "+BOLD+"Vampiress"+NORM+" chortles demonically...\n"+
        "She whispers, 'You put a good fight, maybe next time'...\n"+
        "And she steps aside to let you pass.\n\n");
  TP->move_player("out#players/eurale/VAMPIRES/RMS/foyer.c");
  return 1; }
write("'Over my dead body', screams the "+BOLD+"Vampiress"+NORM+"...\n"+
      "Then she "+HIR+"RIPS your BACK"+NORM+" with her "+
      BOLD+"TALONED FINGERS"+NORM+".\n\n");
TP->hit_player(10 + random(13));
return 1;
}

monster_died() {
object ob;
tell_room(environment(TO),
  HIR+"\n'Congratulations, you've advanced to "+
  "NOVITIATE', whispers the dying "+BOLD+"Vampiress\n\n"+NORM);
  write_file("/players/eurale/VAMPIRES/TRIALS",
    ctime(time())+"  "+capitalize(TPRN)+" completed Trial 1.\n");
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
