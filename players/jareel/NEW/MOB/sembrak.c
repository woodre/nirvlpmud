/*
The Sembrak will be part of a quest in the future, where a player will 
need to kill the three Greater Ice demons, and take the weapons made from 
the fallen heroes, and journey to the hero plane and defeat something or 
role-play something haven't figured out the final step for the quest, but 
I have the direction to get there. The Sembraks Hell Scourge is a very 
powerful weapon, however it is in a room with 3 aggressive monsters that 
block all exits, and is no portal.  

Converted all Spells to Add_Spell 7/21/2014
Changed Heal rate from (8,2) - (16,1)
Doubled Spell Damage Lowend
Changed all Spell Damage To other|Dark, other|poison, other|mental
Boosted spell chance fom 10-20 for all spells still only one spell per turn
changed half the spells to area effect spells that were  thematic to the spam.
Changes Makes the Demon more appropriate for one of the "Legendary Demons Quest"
Second Sembrak is introduced in the Cave.

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
  set_gender("demon");
  set_race("chaos");
  set_level(27);
  set_heal(16,1);
  set_wc(72);
  set_ac(14);
  set_aggressive(1);
  set_hp(1800);
  set_al(-1000);
  add_money(5500+random(1000));

set_short(
CYN+"The legendary Sembrak"+NORM);

set_long(
"Among the most feared and deadly creatures in this realm, the Sembrak is one of the\n"+
"three greater Dark Demons.  It's skin is a black, whale-like, smooth, surface.  Huge\n"+
"unpleasant horns that curve into each other adorn the demons head.  Bat-like wings\n"+
"that make no sound as they flap tower from the demons back.  Ugly prehensile paws, and\n"+
"a barbed tail lash out needlessly and disquietingly. The Sembrak's face, or where it's\n"+
"face should be, only a suggestive blackness prevails.  With a shield in one hand and a\n"+
"blood dripping scourge in the other, a death will occur.\n");

MOCO("/players/jareel/weapons/chaos/hell_scourge.c"),this_object());
          init_command("wield scourge");
MOCO("/players/jareel/armor/chaos/tin_shield.c"),this_object());
          init_command("wear shield");
  
     set_armor_params("other|light",0,-100,0); /* Double damage from light */
     set_armor_params("other|dark",0,100,0); /* Immune damage from dark */

add_spell(
    "sembrak eyes",
	"The Sembrak's eyes "+BOLD+"glow "+NORM+"with raw power.\n",
    "The Sembrak's eyes "+BOLD+"glow "+NORM+"with raw power.\n\n",
    20,"2d6+18","other|dark", 1);	
	
add_spell(
    "sembrak spout",
	"Sembrak lowers his scourge spouting"+BOLD+RED+"\n",
"          "+BOLD+RED+BLINK+"           H  E  L  L  F  I  R  E  !  !  !\n"+NORM+"\n\n",
    20,"40-80+80","other|dark", 1);	

add_spell(
    "sembrak mental",
	"Sembrak releases a "+BOLD+"\n           BLAST!!!"+NORM+"\n",
    "                    of mental energy into #TN#!!!\n\n\n",
    20,"8d6+25","other|mental");	

add_spell(
    "sembrak tail",
	"Sembrak smashes #TN# with his barbed tail.\n\n",
    "Sembrak smashes #TN# with his barbed tail.\n\n\n",
    20,"10d6+25","other|poison");	

add_spell(
    "scourge swing",
	"Sembrak swings its scourge at #TN#.\n",
    "Sembraks scourge "+BOLD+RED+"bites "+NORM+"into #TN#\n\n",
    25,"20d4","other|dark");	

}
	
init() {
  ::init();
add_action("nogo","down");
}

nogo() {
write("Demon blocks your path.\n");
return 1;}
