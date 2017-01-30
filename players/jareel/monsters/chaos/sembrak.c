/*
The Sembrak will be part of a quest in the future, where a player will need to kill the three Greater Ice demons, and take the weapons made from the fallen heroes, and journey to the hero plane and defeat something or role-play something haven't figured out the final step for the quest, but I have the direction to get there. The Sembraks Hell Scourge is a very powerful weapon, however it is in a room with 3 aggressive monsters that block all exits, and is no portal.  

Gaze does an average of 12dam/round
Blast does an average of 2dam/round
Flame does an average of 7dam/round
Crush does an average of 6dam/round

Demon is made of Darkness 
I made it vunerable to light 
and invulnerable to Darkness 
Change made 05/17/2006 

*/
inherit "/obj/monster";
#include "/players/jareel/define.h"

int S;
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("sembrak");
  set_race("chaos");
  set_alt_name("demon");
  set_short(CYN+"The legendary Sembrak"+NORM);
set_long(
"Among the most feared and deadly creatures in this realm, the Sembrak is one of the\n"+
"three greater Dark Demons.  It's skin is a black, whale-like, smooth, surface.  Huge\n"+
"unpleasant horns that curve into each other adorn the demons head.  Bat-like wings\n"+
"that make no sound as they flap tower from the demons back.  Ugly prehensile paws, and\n"+
"a barbed tail lash out needlessly and disquietingly. The Sembrak's face, or where it's\n"+
"face should be, only a suggestive blackness prevails.  With a shield in one hand and a\n"+
"blood dripping scourge in the other, a death will occur.\n");

  set_gender("demon");
  set_race("chaos");
  set_level(27);

MOCO("/players/jareel/weapons/chaos/hell_scourge.c"),this_object());
          init_command("wield scourge");
MOCO("/players/jareel/armor/chaos/tin_shield.c"),this_object());
          init_command("wear shield");
  
  set_heal(8,2);
  set_wc(72);
  set_wc_bonus(25);
  set_ac(14);
  set_aggressive(1);
  set_hp(1800);
  set_al(-1000);
  add_money(5500+random(1000));

                     /* Change made 05/17/2006 */
     set_armor_params("other|light",0,-100,0); /* Double damage from light */
     set_armor_params("other|dark",0,100,0); /* Immune damage from dark */

  set_chance(15);
  set_spell_mess1(
    "Sembrak swings its scourge at its foe.\n");
  set_spell_mess2(
    "Sembraks scourge "+BOLD+RED+"bites "+NORM+"into you.\n"); 
  set_spell_dam(75);
}

heart_beat() {
    ::heart_beat();
S = random(10);
  if(attacker_ob){
    if(S <= 4) S_gaze();
    if(S == 5) S_blast();
    if(S == 6) S_flame();
    else if(S >= 7) S_crush();
}
}

S_gaze()  {
tell_room(environment(TO),
  "The Sembrak's eyes "+BOLD+"glow "+NORM+"with raw power.\n");
call_other(attacker_ob,"hit_player",random(12)+18);
return;
}

S_flame() {
tell_room(environment(TO),
"Sembrak lowers his scourge spouting"+BOLD+RED+"\n"+
"          "+BOLD+RED+BLINK+"           H  E  L  L  F  I  R  E  !  !  !\n"+NORM);
call_other(attacker_ob,"hit_player",random(25)+50);
return;
}

S_blast()  {
tell_room(environment(TO),
  "Sembrak releases a "+BOLD+"\n"+
  "           BLAST!!!"+NORM+"\n"+
  "                    of mental energy into its foe!!!\n");
call_other(attacker_ob,"hit_player",random(25)+25);
return;
}

S_crush() {
tell_room(environment(TO),
"Sembrak smashes you with his barbed tail.\n");
 call_other(attacker_ob,"hit_player",random(30)+5);
return;
}

init() {
  ::init();
add_action("nogo","down");
}

nogo() {
write("Demon blocks your path.\n");
return 1;}
