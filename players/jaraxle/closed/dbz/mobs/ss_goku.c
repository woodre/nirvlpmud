#include "/players/jaraxle/define.h"
#define moose this_object()->query_attack()
inherit "/players/vertebraker/closed/std/monster.c";
int x;
int ssb;
reset(arg)  {
   object gold;
   ssb = 0;
   ::reset(arg);
   if(arg) return;
   
   set_name("Goku");
   set_alt_name("super saiyan");
   set_alias("goku");
   set_race("saiyan");
   set_short(HIY+"Super Saiyan"+NORM+" Goku");
   
   set_level(20);
   set_hp(100+random(50));
   set_al(-1000);
   set_ac(17);
   set_aggressive(1);
   set_wc(35+random(6));
   set_wc_bonus(20);
   set_ac_bonus(6);
   set_dead_ob(this_object());
   
   set_a_chat_chance(15);
   load_a_chat("Goku yells, 'This is serious!!'\n");
   
   gold = clone_object("obj/money");
   gold->set_money(100+random(501));                              
   move_object(gold,this_object());
   
} 
long(){ write("later"); }

monster_died() {
   tell_room(environment(this_object()),
      "The fiery force surrounding Goku fades as\nhe falls defeated to the ground.\n");
   x = present("corpse",environment(this_object()));
   destruct(x);
   move_object(clone_object("/players/jaraxle/closed/dbz/1.c"),environment());
   return 0; }




kamehameha(){
   
   string ATT_NAME,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   
   say("Goku yells, 'Ka-me-ha-me-ha!'\n"+
      "\tGoku fires a "+HIY+"blast of energy"+NORM+" into "+ATT_NAME+"!\n\n");
   
   attacker_ob->add_hit_point(-30-random(12));
}


sensu_bean(){
   if(this_object()->query_hp() < 100 && ssb < 4){
      
      say("As Goku tumbles to the ground he quickly swallows a "+RED+"sensu bean"+NORM+".\n"+
         "\t"+HIC+"Goku's health and power recover"+NORM+".\n\n");
      this_object()->heal_self(100+random(51));
      ssb +=1;
      if(ssb == 3) say ("It looks like Goku has used his last sensu bean!\n");
   }
}


spirit_bomb(){
   string ATT_NAME,msg;
   object *inv;
   int lil_doggy, i;
   inv = all_inventory(environment());
   lil_doggy = sizeof(inv);
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   tell_room(environment(moose),
      "Goku raises his hands to the sky...\n\n"+
      "\tI have to borrow the spirit of nirvana and all it's creatures...\n"+
      "\t\tPlease give me all your strength!\n");
   tell_room(environment(moose),
      "\tA giant ball of energy begins to grow from his outstretched hands.\n");
   for(i = 0; i < lil_doggy; i++)
   {
      if(inv[i]->query_name() != "Goku")
         {
         if(living(inv[i]))
            {
            tell_object(inv[i], "\tThe blast from Goku's "+HIC+"spirit bomb"+NORM+" "+HIR+"burns"+NORM+" your skin!\n");
            inv[i]->hit_player(50 + random(25));
         }
       }
   }
}


heart_beat(){
   int i;
   ::heart_beat();
   if(attacker_ob){
      i = random(11);
      switch(i){
         
         case 0..3: kamehameha();
         break;
         
         case 4..6: sensu_bean();
         break;
         
         case 7: spirit_bomb();
         break;
         
         case 8..10: return 0;
         break;
      }
   }
}
