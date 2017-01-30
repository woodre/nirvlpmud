#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";
int x;
string my_name;
string my_short;
reset(arg)  {
   object gold;
   switch(random(6)){
      case 0: my_name = "noodle";
      break;
      case 1: my_name = "merdoc";
      break;
      case 2: my_name = "sofia";
      break;
      case 3: my_name = "fossil";
      break;
      case 4: my_name = "pharrell";
      break;
      case 5: my_name = "ghenea";
      break;
   }
   switch(random(4)){
      case 0: my_short = ""+BLK+BOLD+"Shadow"+RED+"S"+BLK+BOLD+"haper"+NORM+"";
      break;
      case 1: my_short = ""+BLK+BOLD+"Shadow"+NORM+RED+"B"+BLK+BOLD+"uilder"+NORM+"";
      break;
      case 2: my_short = ""+BLK+BOLD+"Guardian "+RED+"of"+BLK+BOLD+" Shadows"+NORM+"";
      break;
      case 3: my_short = ""+BLK+BOLD+"Shaper "+RED+"of"+BLK+BOLD+" Shadows"+NORM+"";
      break;
   }
   ::reset(arg);
   if(arg) return;
   set_name(my_name);
   set_alias(my_name);
   set_race("fallen");
   set_short(capitalize(my_name)+" the "+my_short);
   set_level(20);
   set_hp(550+random(50));
   set_al(-1500);
   set_ac(15);
   set_aggressive(0);
   set_wc_bonus(20);
   set_ac_bonus(6);
   set_dead_ob(this_object());
   move_object(clone_object("/players/jaraxle/cont/carrara/mon/fallen_weap.c"),TO);
   command("wield sword",TP);
   set_wc(45+random(6));
   gold = clone_object("obj/money");
   gold->set_money(4500+random(501));                              
   move_object(gold,this_object());
   
} 
long(){
   write(capitalize(my_name)+" stands silently.  Motionless in their stance.\n"+
      "A dark hooded cloak is wrapped around "+capitalize(my_name)+"'s body,\n"+
      "allowing you to see nothing of their persona.  A slight\n"+
      "figure of"+capitalize(my_name)+"'s face can be seen fading in and out of.\n"+
      "the light.  A mysterious dark shadow shrouds the area\n"+
      "surrounding "+capitalize(my_name)+".\n");
   write(capitalize(my_name)+" is one with the shadows.\n");
}

monster_died() {
   tell_room(environment(this_object()),
      ""+capitalize(my_name)+" falls to the ground, dead.\n");
   return 0;
}


focus(){
   say(BLK+BOLD+capitalize(my_name)+" focuses the shadows around them.\n"+NORM);
}

shadowblast1(){
   
   string ATT_NAME,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   tell_object(attacker_ob, "A blast of dark energy hits you.\n");   
   tell_room(environment(), BOLD+WHT+"Shadows swirl around "+capitalize(my_name)+"...\n"+NORM+
      "    "+capitalize(my_name)+" channels the shadows through themselves...\n"+
      "\t"+capitalize(my_name)+" casts a shadow blast at "+ATT_NAME+".\n", ({ attacker_ob }));
   attacker_ob->hit_player(20+random(6));
}

shadowblast2(){
   
   string ATT_NAME,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   tell_object(attacker_ob, "A blast of dark energy hits you.\n");   
   tell_room(environment(), RED+capitalize(my_name)+" focuses their strength as flames swirl around them...\n"+NORM+"\t"+
      capitalize(my_name)+" engulfs "+ATT_NAME+" in dark flames.\n", ({ attacker_ob }));
   attacker_ob->hit_player(20+random(6));
}

shadowblast3(){
   
   string ATT_NAME,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   tell_object(attacker_ob, "A blast of dark energy hits you.\n");   
   tell_room(environment(), RED+capitalize(my_name)+" beckons as dark flames engulf them...\n"+
      NORM+"    "+capitalize(my_name)+" channels the flames through themselves...\n\t"+
      capitalize(my_name)+" casts a blast of dark flames at "+ATT_NAME+".\n", ({ attacker_ob }));
   attacker_ob->hit_player(20+random(6));
}

hurt_fallen(){
   object *inv;
   int lil_doggy, i;
   inv = all_inventory(environment());
   lil_doggy = sizeof(inv);
   for(i = 0; i < lil_doggy; i++)
   {
      if(living(inv[i]) && present("circle_object",(inv[i]))){
         inv[i]->add_sp(-7-random(5));
         tell_object(inv[i], BOLD+BLK+"The shadows pull at your soul, draining your power!\n"+NORM);
       }  
   }
}

heart_beat(){
   int i, x, y, z;
   ::heart_beat();
   if(!attacker_ob){
      y = random(3);
      switch(y){
         
         case 0: hurt_fallen();
         break;
         case 1..2: return 0;
         break;
      }
   }
   
   if(attacker_ob){
      i = random(15);
      x = random(15);
      z = random(3);
      switch(x){
         
         case 0..4: focus();
         break;
         case 5..14: return 0;
         break;
      }
      
      switch(i){
         
         case 0..1: shadowblast1();
         break;
         case 2..3: shadowblast2();
         break;
         case 4..5: shadowblast3();
         break;
         case 6..11: return 0;
         break;
      }
      switch(z){
         case 0: hurt_fallen();
         break;
         case 1..2: return 0;
         break;
      }
   }
}
