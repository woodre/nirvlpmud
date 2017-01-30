#include "/players/eurale/defs.h"
inherit "obj/monster";
object gold;
int FIGHTING;

reset(arg)  {
  ::reset(arg);
  if(arg) return;
FIGHTING = 0;

set_name("gentleman");
set_alias("vampire");
set_race("undead");
set_gender("male");

set_short(BOLD+"country gentleman"+NORM);
set_long(
  "A tall, handsome gentleman with brown slacks and a tan herringbone\n"+
  "coat.  His handlebar moustache of auburn adds color to his pale,\n"+
  "white face.  Black riding boots reach almost to his knees.  He is\n"+
  "charming and pleasant and smiles almost constantly.\n");

set_level(18);
set_hp(750);
set_al(0);
set_wc(42);
set_ac(15);
set_heal(3,3);
set_aggressive(0);
set_dead_ob(this_object());

set_chance(13);
set_spell_dam(10 + random(20));

set_spell_mess2(
  "The "+BOLD+"Vampire BACKHANDS YOU ACROSS THE FACE!"+NORM+
  "\n");

set_spell_mess1(
  "The "+BOLD+"Vampire"+NORM+" quickly "+BOLD+"BACKHANDS HIS FOE!\n"+
  NORM);

gold = clone_object("obj/money");
gold->set_money(1000);
move_object(gold,TO);
}

init() {
  ::init();
  add_action("out","out");
  add_action("no_quit","quit");
  add_action("Banshee","banshee");
}

Banshee() {
  write(BOLD+"The vampire LAUGHS in your face!\n"+NORM);
  return 1; }

no_quit(){
  write(
  "The "+BOLD+"Vampire"+" senses your "+HIR+"FEAR"+NORM+"... "+
    "He attacks and "+HIR+"SLAPS YOU HARD!\n\n"+NORM);
  TP->hit_player(35 + random(15));
  return 1; }

out() {
if(TP->query_ghost()) {
  write("The "+BOLD+"Vampire"+NORM+" smiles, exposing his fangs, as he\n"+
        "steps aside to let you pass by...\n");
  TP->move_player("out#players/eurale/VAMPIRES/RMS/foyer.c");
  return 1; }
write("Your "+BOLD+"EYES WATER"+NORM+" as the "+
      BOLD+"Vampire SLAPS YOU"+NORM+" for trying to leave.\n\n");
TP->hit_player(10 + random(13));
return 1;
}

monster_died() {
object ob;
tell_room(environment(TO),
  HIR+"\n'Congratulations, you've advanced to "+
  "ACOLYTE', whispers the dying "+BOLD+"Vampire\n\n"+NORM);
  write_file("/players/eurale/VAMPIRES/TRIALS",
    ctime(time())+"  "+capitalize(TPRN)+" completed Trial 2.\n");
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
  "\nThe "+BOLD+"Vampire "+HIR+"GLARES"+NORM+" at you in disgust...\n"+
  "And then with "+HIY+"LIGHTNING SPEED"+NORM+" he attacks your pet.\n"+
  "With "+BOLD+"TALONED CLAWS"+NORM+" he "+HIR+"DISEMBOWELS"+NORM+
  " it and devours the corpse...\n\n");
  destruct(dob);
return 1; }
