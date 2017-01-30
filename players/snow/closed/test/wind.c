/*
* Wind, the fourth test
*/

inherit "/obj/monster";
#include "/players/snow/closed/color.h"

object testvic;

reset(arg) {
   ::reset(arg);
   if (!arg) {
      
      set_name("wind");
      set_short(WHITE+"Wind"+OFF);
      set_race("fourth");
      set_alias("win");
      set_long(
         "\tYou see before you your fourth test, Wind.\n"+
         "It appears to be a tornado-like being. Its motions are blurred\n"+
         "by its speed.\n");
      set_level(20);
      set_ac(10);
      set_wc(60);
      set_hp(600);
      set_heal(1,1);
      set_al(0);
      set_aggressive(1);
      set_dead_ob(this_object());
      set_chance(40);
      set_spell_mess1(
         "\tWind whips against its foe!\n");
      set_spell_mess2(
         "\tWind whips against you!\n");
      set_spell_dam(25);
   }
}

/*  Just a fun ability to do - think it will add to the 
   confusion and some theme. - Jaraxle [9/6/03] */
drop_items(){
   object inv;
   int x;
   if(!attacker_ob) return;
   inv = all_inventory(attacker_ob);
   
   say("Wind rips through your inventory!\n");
   for(x = 0; x < sizeof(inv); x++){
    if(random(100) < 20 && inv[x]->query_worn() && inv[x]->query_type() == "shield"){
         command("unkeep shield",attacker_ob);
         command("drop shield",attacker_ob);
       }       
      if(attacker_ob->query_weapon()){
         command("unkeep weapon", attacker_ob);
         command("drop weapon", attacker_ob);
       }
    if(random(100) < 20 && inv[x]->query_worn() && inv[x]->query_type() == "armor"){
         command("unkeep armor",attacker_ob);
         command("drop armor",attacker_ob);
       }
    if(random(100) < 20 && inv[x]->query_worn() && inv[x]->query_type() == "boots"){
       if(inv[x]->queryKept()) 
         command("unkeep boots",attacker_ob);
         command("drop boots",attacker_ob);
       }
    if(random(100) < 20 && inv[x]->query_worn() && inv[x]->query_type() == "ring"){
         command("unkeep ring",attacker_ob);
         command("drop ring",attacker_ob);
       }
    if(random(100) < 20 && inv[x]->query_worn() && inv[x]->query_type() == "misc"){
         command("unkeep misc",attacker_ob);
         command("drop misc",attacker_ob);
       }
    if(random(100) < 20 && inv[x]->query_worn() && inv[x]->query_type() == "helmet"){
         command("unkeep helmet",attacker_ob);
         command("drop helmet",attacker_ob);
       }
    if(random(100) < 20 && inv[x]->query_worn() && inv[x]->query_type() == "amulet"){
         command("unkeep amulet",attacker_ob);
         command("drop amulet",attacker_ob);
       }
   }
}


stun_em(){
object target;
object web;
/*
if(present("wind_stun", attacker_ob)){ say("Stunned already\n"); }
*/
/*
if(attacker_ob->pummeled()) return;
say("Wind stings you with a torrential whip of air!\n");
web = clone_object("/players/snow/closed/test/wind_confused.c");
web->set_time(5+random(10));
                web->web_person(attacker_ob);
*/
}

/* End spell addition */
heart_beat() {
   ::heart_beat();
  if(!environment()) return;
  if(!attacker_ob) return;
/*
 STUPID
if(!random(5)){ drop_items(); }
*/

/*
if(!random(5)){ stun_em(); }
*/

   find_victim();
   check_self();
   if(!random(1)) { already_fight=0; attack(); }
   if(!random(1)) { already_fight=0; attack(); }
   if(!random(2)) { already_fight=0; attack(); }
   if(!random(3)) { already_fight=0; attack(); }
}

monster_died() {
   object steel;
   steel = clone_object("/players/snow/closed/test/steel.c");
   tell_room(environment(this_object()),
      "\n\tThe remnants of wave seep away.\n\n"+
      "\tYou have completed the fourth stage of your test!\n\n"+
      "\tWhirling blades of steel float in front of you.\n\n");
   move_object(steel,this_object());
   steel->attack_object(testvic);
   steel->set_testvic(testvic);
   extra_xp(attacker_ob);
   logMyDeath();
   return 0;
}

#include "defenses.h"
#include "logme.h"
