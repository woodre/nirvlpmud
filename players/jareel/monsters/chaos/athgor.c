inherit "/obj/monster";
#include "/players/jareel/define.h"

reset(arg) {
   ::reset(arg);
   if(arg) return;
set_name("athgor");
set_alt_name("demon");
set_short("A "+BOLD+"Huge "+BLK+"Athgor"+NORM);
set_long(
      "The Athgor is a strange, chaotic being of unnatural aspect.  It\n"+
      "resembles a centaur in basic shape, but it has the tail of a scorpion.\n"+
      "The head resembles a dog's skull, but its hide seems to be covererd\n"+
      "with a hard boney material.  Its six arms seem to move with deadly\n"+
      "speed.  This monster would instill fear in the greatest warrior.\n"
   );
   if(!random(2)) set_gender("male"); else set_gender("female");
   set_race("demon");
   set_level(25);
/*
MOCO("/players/jareel/armors/tin_shield.c"),this_object());
          init_command("wear shield");
MOCO("/players/jareel/weapons/athgors_dagger.c"),this_object());
          init_command("wield dagger");
  */
  set_wc(44);
  set_ac(23);
  set_hp(1000);
  set_al(-1000);
  add_money(5500+random(1000));
  set_chance(30);
  set_spell_mess1(
"The Athgor strikes its tail at its foe.\n");
  set_spell_mess2(
"With blinding speed the Athgor slashes at you with its tail.\n"); 
  set_spell_dam(50);
}

heart_beat() {
  ::heart_beat();
      if(attacker_ob) {
          already_fight=0;
                     attack();
          already_fight=0;
                     attack();
          already_fight=0;
                     attack();
          already_fight=0;
                     attack();
}
}

init() {
  ::init();
add_action("stop","west");
}

stop() {
if(TP->query_ghost() == 1) { return 0; }
           else{
if(TP->query_level() >8 && TP->query_level() <20) {
           write("Athgor blocks your exit.\n");
attack_object(this_player());
return 1; }}
}
