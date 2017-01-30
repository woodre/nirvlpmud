
#include "/players/jaraxle/define.h"
#define moose this_object()->query_attack()
#define moosen capitalize(moose->query_name())
#define dam_count query_dam_taken_this_round()
inherit "/players/vertebraker/closed/std/monster.c";

string my_name;
reset(arg)  
{
   object gold;

  switch(random(1)){
case 0: my_name = lower_case("/players/jaraxle/closed/names"->get_male_name());
break;
case 1: my_name =
lower_case("/players/jaraxle/closed/names"->get_female_name());
break;
}

   ::reset(arg);
   if(arg) return;
   set_name(my_name);
   set_alias(my_name);
   set_race("polymorph");
   set_short(capitalize(my_name)+" the Polymorph");
   set_level(25);
   set_hp(1000+random(150));
   set_al(0);
   set_wc_bonus(25);
   set_ac(24+random(5));
   set_aggressive(0);
   set_wc(45+random(6));
   set_dead_ob(this_object());
   set_chat_chance(4);
   gold = clone_object("obj/money");
   gold->set_money(4000+random(501));                              
   move_object(gold,this_object());
   set_wander(35, 0, ({ "pass" }));
   load_chat(capitalize(my_name)+" growls and searches for someone's skull to break open.\n");
   load_chat(capitalize(my_name)+" growls and searches for someone's skull to break open.\n");
}
long(){ write(capitalize(my_name)+" is a human, 5 feet 10 inches tall, 306 lbs.\n"+
      ""+capitalize(my_name)+" can fight other players.\n"+
      ""+capitalize(my_name)+" is in good shape.\n"+
      "A bastard sword  (wielded quaternary).\n"+
      "A bastard sword  (wielded tertiary).\n"+
      "A bastard sword  (wielded secondary).\n"+
      "A bright orange sphere.\n"+
      "A bastard sword  (wielded).\n"+
      "A holy symbol of Larn (worn).\n"+
      "The scabbard of a dueling knife.\n"+
      "A well used feather.\n"+
      "A lump of magical clay.\n"); }

 monster_died() {
object bsword, bsword1, bsword2, bsword3;
bsword = clone_object("/players/saber/weapons/broadsword.c");
bsword1 = clone_object("/players/saber/weapons/broadsword.c");
bsword2 = clone_object("/players/saber/weapons/broadsword.c");
bsword3 = clone_object("/players/saber/weapons/broadsword.c");
   tell_room(environment(this_object()),
"The Tetrapod falls to the ground, dead.\n");
move_object(bsword,present("corpse", environment()));
move_object(bsword1,present("corpse", environment()));
move_object(bsword2,present("corpse", environment()));
move_object(bsword3,present("corpse", environment()));
   return 0;
}


multiple_atk(){
   string ATT_NAME;
   int total_damage, i;
   string hit_msg;
   string hit_msg2;
   string hit_msg3;
   total_damage = 0;
if(attacker_ob && present(attacker_ob)) { ATT_NAME = attacker_ob->query_name();
   
   switch(random(8)){
      case 0: hit_msg = "smashed "+ATT_NAME+" with a bonecrushing sound";
      total_damage +=14;  break;
      case 1: hit_msg = "hit "+ATT_NAME+" very hard";
      total_damage +12;  break;
      case 2: hit_msg = "hit "+ATT_NAME+" hard";
      total_damage +=9;  break;
      case 3: hit_msg = "hit "+ATT_NAME+"";
      total_damage +=8;  break;
      case 4: hit_msg = "grazed "+ATT_NAME+"";
      total_damage +=5;  break;
      case 5: hit_msg = "tickled "+ATT_NAME+" in the stomach";
      total_damage +=3;  break;
      case 6: hit_msg = "missed "+ATT_NAME+"";
      total_damage +=0;  break;
      case 7: hit_msg = "massacred "+ATT_NAME+" to small fragments";
      total_damage +=20;  break;
   }
   switch(random(8)){
      case 0: hit_msg2 = "smashed "+ATT_NAME+" with a bonecrushing sound";
      total_damage +=14;  break;
      case 1: hit_msg2 = "hit "+ATT_NAME+" very hard";
      total_damage +=12;  break;
      case 2: hit_msg2 = "hit "+ATT_NAME+" hard";
      total_damage +=9;  break;
      case 3: hit_msg2 = "hit "+ATT_NAME+"";
      total_damage +=8;  break;
      case 4: hit_msg2 = "grazed "+ATT_NAME+"";
      total_damage +=5;  break;
      case 5: hit_msg2 = "tickled "+ATT_NAME+" in the stomach";
      total_damage +=3;  break;
      case 6: hit_msg2 = "missed "+ATT_NAME+"";
      total_damage +=0;  break;
      case 7: hit_msg2 = "massacred "+ATT_NAME+" to small fragments";
      total_damage +=20;  break;
   }
   switch(random(8)){
      case 0: hit_msg3 = "smashed "+ATT_NAME+" with a bonecrushing sound";
      total_damage +=14;  break;
      case 1: hit_msg3 = "hit "+ATT_NAME+" very hard";
      total_damage +=12;  break;
      case 2: hit_msg3 = "hit "+ATT_NAME+" hard";
      total_damage +=9;  break;
      case 3: hit_msg3 = "hit "+ATT_NAME+"";
      total_damage +=8;  break;
      case 4: hit_msg3 = "grazed "+ATT_NAME+"";
      total_damage +=5;  break;
      case 5: hit_msg3 = "tickled "+ATT_NAME+" in the stomach";
      total_damage +=3;  break;
      case 6: hit_msg3 = "missed "+ATT_NAME+"";
      total_damage +=0;  break;
      case 7: hit_msg3 = "massacred "+ATT_NAME+" to small fragments";
      total_damage +=20;  break;
   }
   
   say(capitalize(my_name)+" "+hit_msg+" with his secondary attack.\n");
   say(capitalize(my_name)+" "+hit_msg2+" with his tertiary attack.\n");
   say(capitalize(my_name)+" "+hit_msg3+" with his quaternary attack.\n");
   attacker_ob->hit_player(total_damage);
/*
   say(HIY+"\t Damage: "+HIR+total_damage+NORM+"\n");
*/
}
}

blitz(){
   string ATT_NAME;
   int total_damage, i;
   int total_damage2;
   int total_damage3;
   string hit_msg;
   string hit_msg2;
   string hit_msg3;
   int combo_damage;
   total_damage = 0;
   total_damage2 = 0;
   total_damage3 = 0;
   
if(attacker_ob && present(attacker_ob)) { ATT_NAME = attacker_ob->query_name();
   say(capitalize(my_name)+" breaks into an uncontrollable fury!\n");
   switch(random(8)){
      case 0: hit_msg = "smashed "+ATT_NAME+" with a bonecrushing sound";
      total_damage +=14;  break;
      case 1: hit_msg = "hit "+ATT_NAME+" very hard";
      total_damage +=12;  break;
      case 2: hit_msg = "hit "+ATT_NAME+" hard";
      total_damage +=9;  break;
      case 3: hit_msg = "hit "+ATT_NAME+"";
      total_damage +=8;  break;
      case 4: hit_msg = "grazed "+ATT_NAME+"";
      total_damage +=5;  break;
      case 5: hit_msg = "tickled "+ATT_NAME+" in the stomach";
      total_damage +=3;  break;
      case 6: hit_msg = "missed "+ATT_NAME+"";
      total_damage +=0;  break;
      case 7: hit_msg = "massacred "+ATT_NAME+" to small fragments";
      total_damage +=20;  break;
   }
   switch(random(8)){
      case 0: hit_msg2 = "smashed "+ATT_NAME+" with a bonecrushing sound";
      total_damage2 +=14;  break;
      case 1: hit_msg2 = "hit "+ATT_NAME+" very hard";
      total_damage2 +=12;  break;
      case 2: hit_msg2 = "hit "+ATT_NAME+" hard";
      total_damage2 +=9;  break;
      case 3: hit_msg2 = "hit "+ATT_NAME+"";
      total_damage2 +=8;  break;
      case 4: hit_msg2 = "grazed "+ATT_NAME+"";
      total_damage2 +=5;  break;
      case 5: hit_msg2 = "tickled "+ATT_NAME+" in the stomach";
      total_damage2 +=3;  break;
      case 6: hit_msg2 = "missed "+ATT_NAME+"";
      total_damage2 +=0;  break;
      case 7: hit_msg2 = "massacred "+ATT_NAME+" to small fragments";
      total_damage2 +=20;  break;
   }
   switch(random(8)){
      case 0: hit_msg3 = "smashed "+ATT_NAME+" with a bonecrushing sound";
      total_damage3 +=14;  break;
      case 1: hit_msg3 = "hit "+ATT_NAME+" very hard";
      total_damage3 +=12;  break;
      case 2: hit_msg3 = "hit "+ATT_NAME+" hard";
      total_damage3 +=9;  break;
      case 3: hit_msg3 = "hit "+ATT_NAME+"";
      total_damage3 +=8;  break;
      case 4: hit_msg3 = "grazed "+ATT_NAME+"";
      total_damage3 +=5;  break;
      case 5: hit_msg3 = "tickled "+ATT_NAME+" in the stomach";
      total_damage3 +=3;  break;
      case 6: hit_msg3 = "missed "+ATT_NAME+"";
      total_damage3 +=0;  break;
      case 7: hit_msg3 = "massacred "+ATT_NAME+" to small fragments";
      total_damage3 +=20;  break;
   }
   
   combo_damage = total_damage+total_damage2+total_damage3;
   
   
   switch(random(3)){
      string hit_type;
      case 0: hit_type = "secondary attack";
      break;
      case 1: hit_type = "tertiary attack";
      break;
      case 2: hit_type = "quaternary attack";
      break;
   }
   say(capitalize(my_name)+" "+hit_msg+" with his "+hit_type+".\n");
   say(capitalize(my_name)+" "+hit_msg2+" with his "+hit_type+".\n");
   say(capitalize(my_name)+" "+hit_msg3+" with his "+hit_type+".\n");
   
   
   say(capitalize(my_name)+" begins panting heavily, and says: 'Wicked'.\n");
   say("You cringe in terror.\n");
   attacker_ob->hit_player(combo_damage);
/*
   say(HIY+"\t Damage: "+HIR+combo_damage+NORM+"\n");
*/
}
}

heart_beat(){
   int i;
   ::heart_beat();
   if(attacker_ob){
      i = random(13);
      
      multiple_atk();
      
      switch(i){
         
         case 0..8: blitz();
         break;
         
         case 9..12: return 0;
         break;
      }
   }
}
