/* **********************************************************************
*
********************************************************************** */

inherit "/obj/monster";
#include "/players/jareel/define.h"

  reset(arg) {
    ::reset(arg);
  if(arg) return;

  set_race("troll");
  set_name("lord");
  set_alt_name("kygor");

  set_short("A "+BOLD+BLK+"Kygor Litor - Lord"+NORM);

  set_long(
    "This large hunched over form of a humanoid looms over\n"+
    "you.  The trolls eyes are narrowed slits focused along\n"+
    "its long narrow snout.\n");

  if(!random(2)) set_gender("male"); else set_gender("female");
  set_level(23);
  set_wc(40);
  set_ac(21);
  set_hp(800);
  set_al(-1000);
  add_money(5500+random(2500));

  set_armor_params("other|light",0,-100,0); /* Double damage from light */
  set_armor_params("other|dark",0,100,0); /* Immune from dark */

  set_chance(50);
  set_spell_mess1(
    HIK+"The Lord strikes at its foe.\n"+NORM);
  set_spell_mess2(
    HIK+"With blinding speed the Lord strikes at you.\n"+NORM); 
  set_spell_dam(50);
  }

  heart_beat() {
    ::heart_beat();
  if(attacker_ob) {
    already_fight=0;
    attack();
    already_fight=0;
    attack();
  }
}
