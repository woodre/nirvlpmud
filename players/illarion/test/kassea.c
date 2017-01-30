/* Converted to add_spell and removed unneeded global vars
  - illarion 8.16.2009
  
  
  NOTE:  not finished.  see heart_beat function
*/
inherit "/obj/monster";
#include "/players/jareel/define.h"

reset(arg) {
   ::reset(arg);

if (arg) return;
    set_alias("priestess");
    set_alt_name("rune priestess");
    set_name("kassea");
    set_race("human");
    set_al(0);
    set_level(23);
    set_aggressive(0);
    set_hp(800);  /* hp bonus added by heal spell - see below */
    add_money(5000+random(1900));

MOCO("/players/jareel/armor/orlanthi_wind_priestess_robes.c"),this_object());
init_command("wear armor");

  set_ac(21);
  set_armor_params("other|wind",0,50,0);
  set_armor_params("other|electric",0,50,0);
  set_armor_params("other|earth",0,-50,0);
  set_armor_params("other|water",0,-50,0);

  set_wc(40);
  set_wc_bonus(40);  /* second attack */
  set_gender("female");

set_short(
     "Kassea - "+BOLD+BLU+"Rune Priestess"+NORM+" of Orlanth Thunderous. (neutral)");

set_long(
"Before you stands what appears to be a young woman, but appearances can\n"+
"be deceiving.  A powerful magical aura surrounds her diminutive stature.\n"+
"As you look at her the hair on your neck stands up with the electricity\n"+
"in the air.\n");

add_spell("energy bolt","Kassea fires an energy bolt from her hand.\nIt strikes you in the chest!\n",
    "Kassea fires an energy bolt from her hand.\nIt strikes #TN# in the chest!\n",
    40,50,"other|electric");
  add_spell("thunderstrike",  "Kassea waves her hand.\n"+
    "\n"+
    "        "+BLU+" B O O M ! ! !"+NORM+"\n"+
    "\n"+
    "You are thrown back by a sonic thunder blast.\n",
      "Kassea waves her hand.\n"+
    "\n"+
    "        "+BLU+" B O O M ! ! !"+NORM+"\n"+
    "\n"+
    "#TN# is thrown back by a sonic thunder blast.\n",
    15,"5-55","other|wind");
  add_spell("lightningstrike",   "Kassea unleashes lightning\n"+
    "\n"+
    ""+BLINK+BOLD+"   L I G H T N I N G "+NORM+" leaps from the blade.\n"+
    "\n",
    "Kassea unleashes lightning\n"+
    "\n"+
    ""+BLINK+BOLD+"   L I G H T N I N G "+NORM+" leaps from the blade.\n"+
    "\n",
    15,"5-65","other|electric");
  add_spell("heal1",
    BOLD+BLU+"Kassea channels energy from the robes"+NORM+".\n",
    BOLD+BLU+"Kassea channels energy from the robes"+NORM+".\n",
    10,0,0,0,"K_heal");
  add_spell("heal2",
    "Kassea intones a few words\n",
    "Kassea intones a few words\n",
    10,0,0,0,"K_heal");

    
    
  set_chat_chance(10);
  load_chat("Kassea says: 'Who let you in here.'\n");
  load_chat("Kassea says: 'Henrik, get your ass in here!'\n");
}

/* TODO: implement second attack without casting spells again
*/

heart_beat(){
  ::heart_beat();
  if(attacker_ob) {
    already_fight=0;
    attack();
  }
}

K_heal() {
  int heal;
  heal = random(30);
  hp_bonus+=heal;
  heal_self(heal);
return;
}