#include "/players/maledicta/ansi.h"
#define crime present("criminal_object_derellia", this_player())
#define associate present("guard_derellia", environment(this_object()))
inherit "obj/monster.c";

int coins;
object gold;

reset(arg)  {

  ::reset(arg);
  if(arg) return;

set_name("guard");
set_alt_name("guard_derellia");
set_race("human");
set_aggressive(0);
set_heart_beat(2);

switch(random(10)){
  case 7..9:
    guard1();
    coins = random(500) + 1000;
   break;
  case 5..6:
    guard2();
    coins = random(800) + 1000;
   break;
  case 4:
    guard1();
    coins = random(500) + 1000;
   break;
  case 3:
    guard2();
    coins = random(800) + 1000;
   break;
  case 2:
    guard3();
    coins = random(2000) + 2000;
   break;
  case 1:
    guard4();
    coins = random(2500) + 3500;
   break;
  case 0:
    guard5();
    coins = random(3000) + 4000;
   break;
  default:
    guard1();
    coins = random(500) + 1000;
   break;
  }
gold = clone_object("obj/money");
gold->set_money(coins);
move_object(gold,this_object());
}	


                             
guard1(){
set_short("a "+HIG+"Derellian"+NORM+" Guard "+BOLD+""+BLK+"[private]"+NORM+"");
set_long(
"  This is a private in the military guard of Derellia IV. His dark\n"+
"green armor is well kept and shines brightly in the light. Strapped\n"+
"to his waist is a ceremonial sword, its hilt decorated with an ivory\n"+
"griffins head. A flowing cape drapes from one shoulder, a gold braid\n"+
"chain attaching it to the opposite shoulder of his armor. A blaster\n"+
"pistol is strapped to his hip. He seems alert and proud.\n");
set_level(14);
set_hp(300);
set_ac(9);
set_wc(22);
set_al(500);
set_chance(25);
set_spell_dam(random(25)+10);
set_spell_mess1(
  "The guard takes aim and "+HIY+"BLASTS"+NORM+" his opponent!\n");
set_spell_mess2(
  "The guard takes aim and "+HIY+"BLASTS"+NORM+" you!\n");

}

guard2(){
set_short("a "+HIG+"Derellian"+NORM+" Guard "+BOLD+""+BLK+"[corporal]"+NORM+"");
set_long(
"  This is a corporal in the military guard of Derellia IV. His dark\n"+
"green armor is well kept and shines brightly in the light. Strapped\n"+
"to his waist is a ceremonial sword, its hilt decorated with an ivory\n"+
"griffins head. A flowing cape drapes from one shoulder, a gold braid\n"+
"chain attaching it to the opposite shoulder of his armor. A blaster\n"+
"pistol is strapped to his hip. He seems alert and proud.\n");
set_level(15);
set_hp(425);
set_ac(10);
set_wc(24);
set_al(500);
set_chance(25);
set_spell_dam(random(25)+15);
set_spell_mess1(
  "The guard takes aim and "+HIY+"BLASTS"+NORM+" his opponent!\n");
set_spell_mess2(
  "The guard takes aim and "+HIY+"BLASTS"+NORM+" you!\n");
}	

guard3(){
set_short("a "+HIG+"Derellian"+NORM+" Guard "+BOLD+""+BLK+"[sergeant]"+NORM+"");
set_long(
"  This is a sergeant in the military guard of Derellia IV. His armor\n"+
"is bulkier than the standard-issue, and carries a small powerpak which\n"+
"is strapped to his left leg. A large vibro-sword is sheathed on his\n"+
"hip, its hilt decorated in gold. A blaster rifle is slung over his\n"+
"right shoulder, while a short green cape hangs over his left. He looks\n"+
"about the town with a careful eye to detail.\n"); 
set_level(16);
set_hp(500);
set_ac(13);
set_wc(25);
set_al(500);
set_chance(25);
set_spell_dam(random(25)+20);
set_spell_mess1(
  "The sergeant takes aim and "+HIY+"BLASTS"+NORM+" his opponent!\n");
set_spell_mess2(
  "The sergeant takes aim and "+HIY+"BLASTS"+NORM+" you!\n");
}

guard4(){
set_short("a "+HIG+"Derellian"+NORM+" Guard "+BOLD+""+BLK+"[lt. commander]"+NORM+"");
set_long(
"  This is a lt. commander in the military guard of Derellia IV. His\n"+
"armor is a lightweight version of the standard issue, its glossy\n"+
"surface resistant to most attacks. His helmet is overly decorated\n"+
"with a small plume and gold braiding. A special targeting goggle\n"+
"covers one eye. Strapped to his right hip is a heavy blaster pistol\n"+
"its black steel polished to a high gleam. A long cape drapes from\n"+
"his back, flowing down to his ankles.\n");
set_level(17);
set_hp(600);
set_ac(14);
set_wc(25);
set_al(500);
set_chance(25);
set_spell_dam(random(25)+25);
set_spell_mess1(
  "The guard takes aim with his blaster pistol and...\n\n"+
  "                 "+HIY+"BLASTS"+NORM+"\n\n"+
  "                        his opponent in the chest!\n");
set_spell_mess2(
  "The guard takes aim with his blaster pistol and...\n\n"+
  "                 "+HIY+"BLASTS"+NORM+"\n\n"+
  "                          you in the chest!\n");
}

guard5(){
set_short("a "+HIG+"Derellian"+NORM+" Guard "+BOLD+""+BLK+"[captain]"+NORM+"");
set_long(
"  This is a captain in the military guard of Derellia IV. His\n"+
"armor is a lightweight version of the standard issue, its glossy\n"+
"surface resistant to most attacks. His helmet is overly decorated\n"+
"with a small plume and gold braiding. A special targeting goggle\n"+
"covers one eye. Strapped to his right hip is a heavy blaster pistol\n"+
"its black steel polished to a high gleam. A long cape drapes from\n"+
"his back, flowing down to his ankles.\n");
set_level(20);
set_hp(800);
set_ac(14);
set_wc(26);
set_al(500);
set_chance(25);
set_spell_dam(random(25)+30);
set_spell_mess1(
  "The captain takes aim with his blaster pistol and...\n\n"+
  "                 "+HIY+"BLASTS"+NORM+"\n\n"+
  "                          his opponent in the chest!\n");
set_spell_mess2(
  "The captain takes aim with his blaster pistol and...\n\n"+
  "                 "+HIY+"BLASTS"+NORM+"\n\n"+
  "                          you in the chest!\n");
}

heart_beat(){
::heart_beat();		
if(!query_attack() && associate->query_attack()){
attack_object(associate->query_attack());
tell_room(environment(this_object()),
"The guard rushes to assist his comrade!\n");
		
   }
  }		
		  	