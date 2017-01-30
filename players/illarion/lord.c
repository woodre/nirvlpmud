/*
Updated to use standard monster.c - illarion 2015.08.20
*/

#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

object gold;
int loc_now;
mapping alliance;
int ally_beat;

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   no_clean = 1;
   set_name("Vulpine Lord");
   set_alt_name("lord");
   set_race("vulpine");
   set_short("Vulpine Lord");
   set_level(29);
   set_hp(2000);
   set_al(0);
   set_wc(90);
   alliance = ([
    "path" : "/players/jaraxle/closed/phoenix/mons/zerker.c",
    "beats" : 5,
    "total" : 10,
    "current" : 2
   ]);
   /* TODO: duplicate this
   set_assist("/players/jaraxle/closed/phoenix/mons/zerker.c", 10, 2, 2);
   */
/* mob is worth too much, even players bitch */
/* this stuff shouldn't be needed anymore - ill
   set_wc_bonus(25);
   set_ac(50);
   */
   set_dead_ob(this_object());
   set_chat_chance(5);
   load_chat("Vulpine Lord looks around the room.\n");
   load_chat("Vulpine Lord says, 'All who oppose me, shall die'\n");
   load_chat("Vulpine Lord bellows a loud laugh.\n");
   
   load_chat("The Vulpine Lord runs his claws along the throne.\n");
   load_chat("The Vulpine Lord sizes you down.\n");
   load_chat("The Vulpine Lord asks with a smirk, 'You think you have a chance, kid?'\n");
   set_heal(10,3);
   
   add_spell("feast",
     "#MN# feasts on your soft skin with a $HR$fearsome bite$N$!\n",
     "#MN# feasts on #TN#'s soft skin with a $HR$fearsome bite$N$\n",
     30,
     "50-90");
   add_spell("spell_drain",
     "#MN# grasps you with #MP# hands!\n$M$You feel your magic force draining.\n",
     "#MN# grasps #TN# with #MP# hands!\n$N$Purple light streams from #TN# to #MN#!\n",
     15,
     "30-50",
     "magical", 
     0,
     "spell_drain_func");
   add_spell("slash_area",
     "One of the wild slashes bites deep into your flesh!\n",
     "#TN# slashes $HW$wildly$ in all directions!\n",
     20,
     "50-50",
     "physical",
     1);
   add_spell("slash_single",
     "$HW$#MN# slashes into your flesh with blinding speed!$N$\n",
     "$HW$#MN# slashes into #TN#'s flesh with blinding speed!$N$\n",
     20,
     "20-40");
   add_spell("stomach_plunge",
       "$HR$#MN# drives #MP# $N$$Y$hands$HR$ into your stomach!$N$\n"+
       "#MP# $HW$razor sharp talons$N$ dig into your body.\n",
       "$HR$#MN# drives #MP# $N$$Y$hands$HR$ into #TN#'s stomach!$N$\n",
       20,
       "30-60");
      
  /* bonus for 30% chance for extra attack */
  set_wc_bonus((this_object()->query_wc() + this_object()->query_spell_exp()) * 30 / 100);
     
  /* What is this I can't even - ill
   set_chance(30);
  set_spell_dam(50+random(40));
   add_special("spell_drain", ({ 15, 30+random(21), "\tThe Vulpine Lord grasps you with his hands.\n\t"+MAG+"You feel your magic force draining.\n"+NORM+"","\n"}));
   add_special("area_attack", ({ 20, 50,"\tThe Vulpine Lord "+HIW+"slashes "+HIC+"wildly"+NORM+" and hacks into your skin!\n","\n"}));
   set_spell_mess2(
      "The Vulpine Lord feasts upon your soft skin with a "+HIR+"fearsome bite"+NORM+"!\n");
      
  */
   gold = clone_object("obj/money");
   gold->set_money(25000 + random(8000));
   move_object(gold,this_object());
   loc_now = 0;   
}

long(){
   write(
      "  The Vulpine Lord stands a towering ten-feet.  He has\n"+
      "large muscular arms; his hands look fearsome, with razor\n"+
      "sharp claws growing out of each finger.  He has an elongated\n"+
      "snout with metal fangs hanging over the bottom lip of his\n"+
      "mouth.\n");
   return 1;
}

init(){
   ::init();
   add_action("stop_leave","leave");
}

stop_leave(){
   if(attacker_ob && !attacker_ob->query_ghost()){
      write("The Vulpine Lord grabs you by the neck and throws you against the wall!\n");
      attacker_ob->hit_player(10+random(11));
      return 1; }
   
   if(TP->query_money() > 20001){
      write("The Vulpine Lord commands,\n"+
         "\t'You must leave all but 20000 coins on the ground.'\n");
      return 1; }
}

heart_beat(){
   ::heart_beat();

   if(attacker_ob && present(attacker_ob, environment())) {
    if(alliance && ally_beat++ > alliance["beats"]) {
      object *obs;
      object ally;
      int s, local_count;
      
      ally_beat = 0;
      
      if(alliance["total_called"] < alliance["total"]) {
      
        obs = all_inventory(environment());
        s = sizeof(obs);
        while(s--) {
          if(basename(obs[s]) == alliance["path"])
            local_count++;
        }
        if(local_count < alliance["current"]) {
            ally=clone_object(alliance["path"]);
            move_object(ally, environment());
            ally->attacked_by(attacker_ob);
            alliance["total_called"]++;
        }
      }
      
    }
   /* replaced using add_spell - ill
      if(random(100) < 60){
         if(attacker_ob && !attacker_ob->query_ghost()){
            already_fight=0;
            tell_object(attacker_ob,
               ""+HIW+"Vulpine Lord quickly slashes into you again!\n"+NORM);
            tell_room(environment(),
               ""+HIW+"Vulpine Lord qiuckly slashes into "+attacker_ob->query_name()+"'s flesh!"+NORM+"\n",
               ({attacker_ob}));
            attacker_ob->hit_player(random(40));
         }
      }
      if(random(100) < 40){
         if(attacker_ob && !attacker_ob->query_ghost()){
            already_fight=0;
            tell_object(attacker_ob,
               HIR+"Vulpine Lord drives his "+NORM+YEL+"hands"+HIR+" into your stomach!"+NORM+"\n"+
               "\tHis "+HIW+"razor sharp talons"+NORM+" dig into your body.\n"+NORM);
            tell_room(environment(),
               HIR+"Vulpine Lord drives his hands into "+attacker_ob->query_name()+"'s stomach!"+NORM+"\n"+
               "\tHis "+HIW+"razor sharp talons"+NORM+" dig into "+attacker_ob->query_name()+"'s body.\n"+NORM,
               ({attacker_ob}));
            attacker_ob->hit_player(30+random(31));
         }
      }
      
      */
      
      if(random(100) < 30){
         if(attacker_ob && !attacker_ob->query_ghost()){
            already_fight=0;
            attack();
         }
      }
   }
}

monster_died(){
   tell_room(environment(),
      HIB+"  The Vulpine Lord crumples to the floor, dead."+NORM+"\n");
   MOCO("/players/jaraxle/closed/phoenix/mask.c"),environment(this_object()));
   return 1;
}

spell_drain_func(target, room, damage) {
  target->add_spell_point(-damage/2);
}
