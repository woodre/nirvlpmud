#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";
int x;
string my_name;
string my_short;
reset(arg)  {
   object gold;

  switch(random(1)){
case 0: my_name = lower_case("/players/jaraxle/closed/names"->get_male_name());
break;
case 1: my_name =
lower_case("/players/jaraxle/closed/names"->get_female_name());
break;
}

   
   switch(random(4)){
      case 0: my_short = ""+BLK+BOLD+"the "+HIM+"Baron of Blood"+NORM+"";
      break;
      case 1: my_short = "the "+BLK+BOLD+"Nocturnal "+HIR+"Soul "+BLK+BOLD+"Hunter"+NORM+"";
      break;
      case 2: my_short = ""+BLK+BOLD+"the Lord of "+HIR+"S"+BLK+BOLD+"orcery"+NORM+"";
      break;
      case 3: my_short = "the "+BLK+BOLD+"Adept "+HIR+"of Shadows"+NORM+"";
      break;
   }
   
   ::reset(arg);
   if(arg) return;
   arm_me();
   set_name(my_name);
   set_alias(my_name);
   set_race("vampire");
   set_short(capitalize(my_name)+" "+my_short);
   
   set_level(20);
   set_hp(550+random(50));
   set_al(-1500);
   set_ac(17);
   set_aggressive(0);
   set_wc_bonus(20);
   set_ac_bonus(6);
   set_dead_ob(this_object());
   gold = clone_object("obj/money");
   gold->set_money(1000+random(501));                              
   move_object(gold,this_object());
   set_wander(30, 0, ({ "pass" }));
   MOCO("/players/jaraxle/3rd/alt/mobs/vamp_wings.c"),TO);
   MOCO("/players/eurale/VAMPIRES/vampob.c"),TO);
} 
long(){
   write("A tall figure, with a dark cloak wrapped around their body.\n"+
      ""+capitalize(my_name)+"'s arms stick out slightly from the sleeves of the\n"+
      "cloak showing metallic arms.  Eyes of ruby glow eerily\n"+
      "behind the hood of "+capitalize(my_name)+"'s hood.\n");
   write(capitalize(my_name)+" is a human, 6 feet 1 inches tall, 296 lbs.\n"+
      ""+capitalize(my_name)+" can fight other players.\n"+
     ""+capitalize(my_name)+" is in good shape.\n");
}

monster_died() {
   tell_room(environment(this_object()),
"The Vampire falls to the ground, dead.\n");
   return 0;
}

arm_me(){
"/players/jaraxle/closed/weapon/wep_gen.c"->get_wep(this_object(),90000+random(20000));
   command("wield weapon with both hands",this_object());
   command("wield weapon",this_object());
   set_wc(35+random(6));
   return 1; }

eat_me(){
   object blah;
   blah=present("corpse");
   if(blah) {
      move_object(blah,this_object());
      say(capitalize(my_name)+" takes corpse.\n");
      say(capitalize(my_name)+" sinks his fangs into the corpse and "+HIR+"SUCKS the lifeblood"+NORM+" from it.\n");
      destruct(blah);
      command("get all", this_object());
   }
}


demon(){
   
   string ATT_NAME;
if(attacker_ob && present(attacker_ob)) { ATT_NAME = attacker_ob->query_name();
   
   tell_room(environment(), BLK+BOLD+" A HOWLING BLACK DEMON appears and attacks "+ATT_NAME+" and then disappears...\n"+NORM, ({ attacker_ob }));
   tell_object(attacker_ob, BLK+BOLD+" A HOWLING BLACK DEMON appears and attacks you and then disappears...\n"+NORM);
   attacker_ob->hit_player(16+random(16));
}
}


grasp(){
   
   string ATT_NAME;
if(attacker_ob && present(attacker_ob)) { ATT_NAME = attacker_ob->query_name();
   tell_room(environment(), capitalize(my_name)+" reaches out with his "+BLK+BOLD+"DEATH COLD"+NORM+" hands and "+HIR+"GRASPS"+NORM+" "+ATT_NAME+"!\n", ({ attacker_ob }));
   tell_object(attacker_ob, capitalize(my_name)+" reaches out with his "+BLK+BOLD+"DEATH COLD"+NORM+" hands and "+HIR+"GRASPS"+NORM+" you!\n"+NORM);
   attacker_ob->hit_player(25+random(16));
}
}



heart_beat(){
   int i;
   ::heart_beat();
   if(!attacker_ob){
      x = random(2);
      switch(x){
         
         case 0: eat_me();
         break;
         case 1: eat_me();
      }
   }
   if(attacker_ob){
      i = random(20);
      switch(i){
         
         case 0..4: grasp();
         break;
         
         case 5..9: demon();
         break;
         
         case 10..14: return 0;
         break;
         case 15..19: demon();
         break;
      }
   }
}
