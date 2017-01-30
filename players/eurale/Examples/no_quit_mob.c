#include "/players/eurale/defs.h"
inherit "obj/monster";
object player;
int FIGHTING;

reset(arg)  {
  ::reset(arg);
  if(arg) return;
FIGHTING = 0;

set_name("vampire");
set_alias("figure");
set_race("undead");
set_gender("male");

set_short(BOLD+"sinister figure"+NORM);
set_long(
  "A tall, muscular figure dressed completely in black.  His hair is\n"+
  "slicked back revealing a pale white complexion.  A large scar runs\n"+
  "across his cheek from just under his right eye almost to the tip\n"+
  "of his ear.  He is wearing a black tuxedo with full tails and\n"+
  "shiney, polished shoes as if he had just come from a ball.  His\n"+
  "black eyes constantly rove about the area as if he were expecting\n"+
  "someone.\n");

set_level(21);
set_hp(750);
set_al(0);
set_wc(52);
set_ac(17);
set_heal(5,6);
set_aggressive(0);
set_dead_ob(this_object());

set_chance(14);
set_spell_dam(10 + random(20));

set_spell_mess2(
  "The "+BOLD+"Vampire BACKHANDS YOU ACROSS THE FACE!"+NORM+
  "\n\n");

set_spell_mess1(
  "The "+BOLD+"Vampire"+NORM+" quickly "+BOLD+"BACKHANDS HIS FOE!\n"+
  NORM);

}

init() {
  ::init();
  add_action("no_brandish","brandish");
  add_action("out","out");
  add_action("no_quit","quit");
}

no_quit(){
  write(
  "As you turn to run, the "+BOLD+"sinister figure"+NORM+
  "jumps on your back....\n"+
  "He "+HIR+"GRASPS YOUR NECK"+NORM+" from behind with incredible "+
  "strength...\n\n");
  TP->hit_player(35 + random(35));
  return 1; }

out() {
if(TP->query_ghost()) {
  write("The "+BOLD+"figure"+NORM+" bows, with vampiric grace, as he\n"+
        "steps aside to let you out...\n");
  TP->move_player("out#players/eurale/Vamp/RMS/foyer.c");
  return 1; }
write("Just as you reach the door, the "+BOLD+"sinister figure"+NORM+
      " grabs you from behind...\n"+
      "With incredible strength, he lifts you overhead and SLAMS you "+
      "to the ground...\n\n");
TP->hit_player(30 + random(13));
return 1;
}

no_brandish(str) {
object wand;
wand = present("wand",TP);
tell_room(environment(TO), BOLD+
  "The "+BOLD+"sinister figure"+NORM+" sees your wand.  He quickly\n"+
  "grabs it and with no effort BREAKS it into pieces.\n\n");
  TP->hit_player(30 + random(13));
  destruct(wand);
  return 1; }

monster_died() {
object ob;
ob = present("corpse",environment(TO));
tell_room(environment(TO),BOLD+
  "As the final blow is struck, the sinister figures smiles at you\n"+
  "exposing his long fangs.  He hisses, 'You have done well. You\n"+
  "have fought bravely and I am satisfied with your skills. I now\n"+
  "promote you to full vampire status and will call you "+
  HIR+"NOSFERATU'"+BOLD+"\n"+
  "\nBefore your eyes, he turns into a bat and flies away...."+NORM+
  "\n\n");
  write_file("/players/eurale/Vamp/TRIALS",
    ctime(time())+"  "+capitalize(TPRN)+" completed Trial 4.\n");
("/players/eurale/Vamp/RMS/foyer.c")->set_ONE(0);
TP->add_guild_exp(1);
TP->save_me();
destruct(ob);
return 0; }

heart_beat() {
  ::heart_beat();
if(!environment()) return;
if(attacker_ob) FIGHTING = 1;
if(!attacker_ob && FIGHTING) {
  move_object(clone_object("/players/eurale/Vamp/OBJ/vampire_note"),
      environment(TO));
  destruct(TO);
  return 1; }

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
  " it and kicks the corpse...\n\n");
  dob->hit_player(5000);
return 1; }
