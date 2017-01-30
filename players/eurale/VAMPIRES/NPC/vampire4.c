#include "/players/eurale/defs.h"
inherit "obj/monster";
object player;
int FIGHTING;

reset(arg)  {
  ::reset(arg);
  if(arg) return;
FIGHTING = 0;

set_name("figure");
set_alias("vampire");
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
set_hp(1000);
set_al(0);
set_wc(60);
set_ac(30);
set_heal(10,1);
set_aggressive(0);
set_dead_ob(this_object());

set_chance(14);
set_spell_dam(45 + random(25));

set_spell_mess2(
  "The "+BOLD+"sinister figure GRASPS"+NORM+" your neck with "+HIC+
  "DEATH COLD HANDS!"+NORM+
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
  TP->move_player("out#players/eurale/VAMPIRES/RMS/foyer.c");
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
tell_room(environment(TO),HIR+"\n"+
  "The sinister figure smiles and hisses, 'You have fought well and I\n"+
  "am satisifed with your skills.  I promote you to NOSFERATU.'\n\n"+
  "And with that, he turns into a bat and flies away....\n\n"+NORM);
write_file("/players/eurale/VAMPIRES/TRIALS",
  ctime(time())+"  "+capitalize(TPRN)+" completed Trial 4.\n");
("/players/eurale/VAMPIRES/RMS/foyer.c")->set_ONE(0);
TP->add_guild_exp(1);
TP->save_me();
destruct(ob);
return 0; }

heart_beat() {
  ::heart_beat();
if(!environment()) return;
if(present("pet",environment(TO)) || present("wolf",environment(TO))) {
  call_out("no_pet",1);
  return 1; }
return 1; }

no_pet() {
object pet,wolf;
pet = present("pet",environment(TO));
wolf = present("wolf",environment(TO));
tell_room(environment(TO),
  "\nThe "+BOLD+"Vampiress "+HIR+"GLARES"+NORM+" at you in disgust...\n"+
  "And then with "+HIY+"LIGHTNING SPEED"+NORM+" she attacks your pet.\n"+
  "With "+BOLD+"TALONED CLAWS"+NORM+" she "+HIR+"DISEMBOWELS"+NORM+
  " it and kicks the corpse...\n\n");
  destruct(pet);
  destruct(wolf);
return 1; }
