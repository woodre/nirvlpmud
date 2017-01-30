/* weight adjusted by Pain - there needs to be some drawback at least - 11/27/96 */

/* sheesh - changed by saber 2/9/97 - a 15 wt for a non saveable */
/* armor on a tough monster is stupid - wt changed to 5          */
/* and whoever set it's weight to 0 - you suck  */
/* AC 5 ARMOUR???? AC 4 is supposed to be the HIGHEST --
And the monster you have this on is NOT tough...
I have seen at least 4 players on at a time with this
armour it is BULLSHIT, I'll comprimise Weight 10 */

/* Monster was revised by Mythos, 75-80k kill now. Wt 10 on this armor is 
   rediculous now.  Sword is wt 12, also rather stupid */
/* You are all morons.  Changed weight to 4. - Maledicta */
/* returned weight to 12, made save. -Bp jun-03 */

/* Monster is now 160k.  wt 12 armor is useless, even with
   added defense against fire.  changed to 7 Illarion Dec 2004
 */

#include "/players/daranath/closed/ansi.h"
inherit "obj/armor";
reset(arg){
   ::reset(arg);
   set_name("red Dragon Armor");
   set_short(RED+"Red Dragon Armor"+NORM);
   set_alias("scale");
   set_long("A suit of armor made from the scales of a Red Dragon!\n");
   set_long("A magical suit of red armor made from the fire-resistant\n"+
   "scales of a Red Dragon!\n");
   set_ac(5);
   set_params("other|fire",0,50,"fire_emote"); /* 50% fire damage */
/* Powerful magic items should protect against magic */
   set_params("magical",2);
   set_weight(7);
   set_value(6000);
/*   set_save_flag(0);*/
}

quest_ob()  { return 1; }
fire_emote() {
  if(environment()) tell_object(environment(),"Your red dragon armor absorbs some flames.\n");
}
