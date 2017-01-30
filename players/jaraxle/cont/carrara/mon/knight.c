#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";
int x;
string my_name;
string title;
reset(arg)  {
   switch(random(10)){
      case 0: my_name = "lawrence";
      break;
      case 1: my_name = "joy";
      break;
      case 2: my_name = "insigma";
      break;
      case 3: my_name = "graham";
      break;
      case 4: my_name = "maximo";
      break;
      case 5: my_name = "jamal";
      break;
      case 6: my_name = "cautious";
      break;
      case 7: my_name = "annette";
      break;
      case 8: my_name = "priscilla";
      break;
      case 9: my_name = "robert";
      break;
   }
   
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
   set_race("knight");
   set_al(1500);
   set_aggressive(0);
   set_dead_ob(this_object());
   enable_commands();
   switch(random(6)){
      case 0:   move_object(clone_object("/players/maledicta/templar/items/axe.c"),TO);
      break;
      case 1:   move_object(clone_object("/players/maledicta/templar/items/knife.c"),TO);
      break;
      case 2:   move_object(clone_object("/players/maledicta/templar/items/pike.c"),TO);
      break;
      case 3:   move_object(clone_object("/players/maledicta/templar/items/mace.c"),TO);
      break;
      case 4:   move_object(clone_object("/players/maledicta/templar/items/hammer.c"),TO);
      break;
      case 5:   move_object(clone_object("/players/maledicta/templar/items/sword.c"),TO);
      break;
   }

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
   command("wield weapon",TP);
   command("light torch", TP);
   command("wear cross",TP);
   
   switch(random(10)){
      case 0: set_level(10); break; case 1: set_level(11); break; case 2: set_level(12); break; case 3: set_level(13); break; case 4: set_level(14); break; case 5: set_level(15); break;
      case 6: set_level(16); break; case 7: set_level(17); break; case 8: set_level(18); break; case 9: set_level(19); break; }
set_ac(armor_class - 11);

}
short(){ return capitalize(my_name)+" "+title; }
long(){
   write("A thin person, of about 5 and one half feet in height.\n"+
      "A foul stench can be smelled suffocating the air around\n"+
      ""+capitalize(my_name)+".  A glint of a sharp dagger can be seen strapped\n"+
      "in "+capitalize(my_name)+"'s belt.\n");
}

monster_died() {
   tell_room(environment(this_object()),
      "The spirit fades to nothingness.\n");
   return 0; }


ice(){
   
   string ATT_NAME,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   
   tell_object(attacker_ob, capitalize(my_name)+" casts a spell of ice upon their weapon, shards piercing your skin.\n");  
   tell_room(environment(), capitalize(my_name)+" coats a weapon with ice.\n", ({ attacker_ob }));
   
   attacker_ob->hit_player(30+random(15));
}

heal_me(){
   
   string ATT_NAME,msg;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   say(capitalize(my_name)+" casts a heal spell on "+capitalize(my_name)+".\n");
   this_object()->heal_self(50);
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

