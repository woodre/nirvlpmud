/*
 * Wave, the third test
 */

inherit "/obj/monster";
#include "/players/snow/closed/color.h"

object testvic;

reset(arg) {
   ::reset(arg);
   if (!arg) {
 
     set_name("wave");
    set_short(BLUE+"Wave"+OFF);
     set_race("third");
     set_alias("wav");
     set_long(
"\tYou look upon your third test, Wave.\n"+
"It is a wall of water 4 meters high and 3 meters wide.\n");
     set_level(20);
     set_ac(20);
     set_wc(25);
     set_hp(1000);
     set_heal(1,1);
     set_al(0);
     set_aggressive(1);
     set_dead_ob(this_object());
set_chance(40);
  set_spell_mess1(
"\tWave engulfs its foe!\n");
  set_spell_mess2(
"\tWave engulfs you!\n");
set_spell_dam(25);
   }
}

/* Added a nice little spell to remove sp while in combat.
   This should make a HUGE difference since he can only
   be hurt by major damage (which needs spells)
   - Jaraxle [9/6/03] */

suck_sp(){
   
   string ATT_NAME,msg;
   if(!attacker_ob) return;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   say("Wave "+BLUE+"pummels"+OFF+" you, absorbing your "+REV_MAGENTA+"mana"+OFF+"!\n");
attacker_ob->add_sp(-20-random(21));
}
/* End of new spell */

heart_beat() {
  ::heart_beat();
  find_victim();

/* For new SP Absorbing spell. [line 43-49] - Jaraxle */
switch(random(4)){
case 0: suck_sp();
break;
case 1..3: return; 
break;
}

/* End addition - Jaraxle */
  check_self(); }

monster_died() {
  object wind;
  wind = clone_object("/players/snow/closed/test/wind.c");
  tell_room(environment(this_object()),
    "\n\tThe remnants of wave seep away.\n\n"+
    "\tYou have completed the third stage of your test!\n\n"+
    "\tA violent tornado blasts into the room!\n\n");
  move_object(wind,this_object());
  wind->attack_object(testvic);
  wind->set_testvic(testvic);
    extra_xp(attacker_ob);
    logMyDeath();
  return 0;
}

hit_player(arg) {
  int num;
  num = arg;
/* Changed from 35 to 40, spells and weaps are really nasty
  now a days. -- Jaraxle [7/18/03] */
  if(num < 50) num = 0;
  ::hit_player(num);
  return num; }


#include "defenses.h"
#include "logme.h"
