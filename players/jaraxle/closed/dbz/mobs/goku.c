#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";
int x;
reset(arg)  {
   object gold;
   ::reset(arg);
   if(arg) return;
   
   set_name("Goku");
   set_alias("goku");
   set_race("saiyan");
   set_short("Goku");
   
   set_level(20);
   set_hp(50+random(50));
   set_al(-1000);
   set_ac(17);
   set_aggressive(0);
   set_wc(35+random(6));
   set_wc_bonus(20);
   set_ac_bonus(6);
   set_dead_ob(this_object());
   
   set_a_chat_chance(15);
   load_a_chat("Goku says, 'Hey! This is a great work-out!'\n");
   load_a_chat("Goku says, 'I'm not being to hard on you am I?'\n");
   
   gold = clone_object("obj/money");
   gold->set_money(100+random(501));                              
   move_object(gold,this_object());
   
} 
long(){ write("later"); }

monster_died() {
   tell_room(environment(this_object()),
      "Goku falls to the floor beaten but not dead.\n"+
      "\tHE slowly stands before you and clinches his fists...\n"+
      "\t\tA "+HIY+"fiery"+NORM+" "+RED+"rage"+NORM+" envelopes him, changing his form and "+HIB+"power"+NORM+"!\n");
   x = present("corpse",environment(this_object()));
   destruct(x);
   move_object(clone_object("/players/jaraxle/closed/dbz/mobs/ss_goku.c"),environment());
   return 0; }




kamehameha(){
   
   string ATT_NAME,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   
   say("Goku yells, 'Ka-me-ha-me-ha!'\n"+
     "\tGoku fires a "+HIY+"blast of energy"+NORM+" into "+ATT_NAME+"!\n\n");
   
   attacker_ob->add_hit_point(-20-random(6));
}


sensu_bean(){
   
say("As Goku tumbles to the ground he quickly swallows a "+RED+"sensu bean"+NORM+".\n"+
"\t"+HIC+"Goku's health and power recover"+NORM+".\n\n");
   this_object()->heal_self(100+random(51));
}

heart_beat(){
   int i;
   ::heart_beat();
   if(attacker_ob){
      i = random(11);
      switch(i){
         
         case 0..3: kamehameha();
         break;
         
         case 4: sensu_bean();
         break;
         
         case 5..10: return 0;
         break;
      }
   }
}
