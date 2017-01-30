#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";
int x;
string my_name;
string title;
reset(arg)  {

switch(random(2)){
case 0: my_name = lower_case("/players/jaraxle/closed/names"->get_male_name());
break;
case 1: my_name =
lower_case("/players/jaraxle/closed/names"->get_female_name());
break;
}
   arm_me();
   
   switch(random(6)){
      case 0: title = RED+"["+NORM+BOLD+"Templar"+NORM+RED+"] "+NORM+BOLD+"Templar General"+NORM;
      break;
      case 1: title = GRN+"["+NORM+BOLD+"Templar"+NORM+GRN+"] "+NORM+BOLD+"Grand Marshall"+NORM;
      break;
      case 2: title = GRN+"["+NORM+BOLD+"Templar"+NORM+GRN+"] "+NORM+BOLD+"Marshall"+NORM;
      break;
      case 3: title = GRN+"["+NORM+BOLD+"Templar"+NORM+GRN+"] "+NORM+BOLD+"High Commander"+NORM;
      break;
      case 4: title = GRN+"["+NORM+BOLD+"Templar"+NORM+GRN+"] "+NORM+BOLD+"Commander"+NORM;
      break;
      case 5: title = GRN+"["+NORM+BOLD+"Templar"+NORM+GRN+"] "+NORM+BOLD+"Knight"+NORM;
      break;
   }
   
   ::reset(arg);
   if(arg) return;
   
   set_name(my_name);
   set_alias("knight");
   set_alt_name("templar knight");
   set_race("human");
set_level(17);
set_hp(700);
set_hp_bonus(-5);
set_wc(30);
   set_aggressive(0);
   set_wander(30, 0, ({ "pass" }));
   set_chat_chance(15);
   load_chat(capitalize(my_name)+" warns you about the phantoms.\n");
   load_chat(capitalize(my_name)+" says, 'Beware beyond the pass.'\n");
   load_chat(capitalize(my_name)+" warns, 'Beyond the pass is very dangerous.'\n");
   load_chat(capitalize(my_name)+" says, 'Phantoms are the cause of Nirvana's demise.'\n");
   set_dead_ob(this_object());
   enable_commands();
   
   switch(random(3)){
      case 0:   move_object(clone_object("/players/saber/armor/lboots.c"),TO);
      break;
      case 1:   move_object(clone_object("/players/saber/armor/slboots.c"),TO);
      break;
      case 2:   move_object(clone_object("/players/maledicta/templar/items/sboots.c"),TO);
      break;
   }
   switch(random(3)){
      case 0: move_object(clone_object("/players/saber/armor/bshield.c"),TO);
      break;
      case 1: move_object(clone_object("/players/saber/armor/wshield.c"),TO);
      break;
      case 2: move_object(clone_object("/players/maledicta/templar/items/shield.c"),TO);
      break;
   }
   switch(random(3)){
      case 0:   move_object(clone_object("players/saber/armor/blackcloak.c"),TO);
      break;
      case 1:   move_object(clone_object("players/feldegast/equip/cloak.c"),TO);
      break;
      case 2: move_object(clone_object("/players/nightshade/armor/elf_cloak.c"),TO);
      break;
   }
   switch(random(2)){
      case 0:    move_object(clone_object("players/saber/armor/finger.c"),TO);
      break;
      case 1:    move_object(clone_object("players/saber/armor/lgloves.c"),TO);
      break;
   }
   move_object(clone_object("/players/scathe/armor/damulet.c"),TO);
   move_object(clone_object("/players/maledicta/templar/items/fullplate2.c"),TO);
   move_object(clone_object("/players/maledicta/templar/items/helmet.c"),TO);
   move_object(clone_object("players/boltar/templar/templar.c"),TO);
   move_object(clone_object("players/saber/stuff/etorch.c"), TO);
   command("wear armor",TP);
   command("wear shield",TP);
   command("wear boots",TP);
   command("wear helmet",TP);
   command("wear cloak",TP);
   command("wear amulet",TP);
   command("wear ring",TP);
   command("wear misc",TP);
   command("light torch", TP);
   command("wear cross",TP);
   
set_ac(10);
   
}
short(){ return capitalize(my_name)+" "+title; }
long(){
write(capitalize(my_name)+" is a tall person of holy might.\n"+
capitalize(my_name)+" is a human, 5 feet 7 inches tall, 178 lbs.\n"+
capitalize(my_name)+" can fight other players.\n"+
capitalize(my_name)+" is in good shape.\n"+
capitalize(my_name)+" has a small "+YEL+"gold star"+NORM+" tattoo on his inside right ankle.\n"+
capitalize(my_name)+" has a symbol of a dragon branded his your forearms.\n");
}

monster_died() {
   tell_room(environment(this_object()),
      "The Knight crumbles to the floor.\n");
   return 0; }


ice(){
   
   string ATT_NAME;
if(attacker_ob && present(attacker_ob)) { ATT_NAME = attacker_ob->query_name();
   
   tell_object(attacker_ob, capitalize(my_name)+" casts a spell of ice upon their weapon, shards piercing your skin.\n");  
   tell_room(environment(), capitalize(my_name)+" coats a weapon with ice.\n", ({ attacker_ob }));
   
   attacker_ob->hit_player(50+random(26));
}
}


heal_me(){
   
   string ATT_NAME;
if(attacker_ob && present(attacker_ob)) { ATT_NAME = attacker_ob->query_name();
   say(capitalize(my_name)+" casts a heal spell on "+capitalize(my_name)+".\n");
   this_object()->heal_self(120);
}
}

heart_beat(){
   int i;
   ::heart_beat();
   if(attacker_ob){
      i = random(15);
      switch(i){
         
         case 0..7: ice();
         break;
         
         case 8..9: heal_me();
         break;
         
         case 10..14: return 0;
         break;
      }
   }
}



arm_me(){
   "/players/jaraxle/closed/weapon/wep_gen.c"->get_wep(this_object(), 90000+random(9999));
   command("wield weapon with both hands",this_object());
   command("wield weapon",this_object());
   return 1; }
