#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";
int i;
int crime;
reset(arg){
  ::reset(arg);
  if(arg) return;
set_race("seussian");
set_alt_name("ped");
set_move_at_reset(1);
set_alias("citizen");
i = random(8);
switch(i){
case 0:  man(); break;
case 1:  woman(); break;
case 2:  boy(); break;
case 3:  girl(); break;
case 4:  baby(); break;
case 5:  bbaby(); break;
case 6:  hooker(); break;
case 7:  guard(); break;
}
}


get_adj(){
string adj;
i = random(16);
switch(i){
case 0: adj = "young"; break;
case 1: adj = "old"; break;
case 2: adj = "frustrated"; break;
case 3: adj = "happy"; break;
case 4: adj = "smiling"; break;
case 5: adj = "tired"; break;
case 6: adj = "good looking"; break;
case 7: adj = "brave looking"; break;
case 8: adj = "strong"; break;
case 9: adj = "weak"; break;
case 10: adj = "normal looking"; break;
case 11: adj = "tall"; break;
case 12: adj = "short"; break;
case 13: adj = "fat"; break;
case 14: adj = "thin"; break;
case 15: adj = "healthy looking"; break;
}
adj = get_color(adj);
return adj;
}

get_color(adj){
i = random(6);
switch(i){
case 0: adj = HIR+adj+NORM; break;
case 1: adj = HIG+adj+NORM; break;
case 2: adj = HIY+adj+NORM; break;
case 3: adj = HIB+adj+NORM; break;
case 4: adj = HIM+adj+NORM; break;
case 5: adj = HIC+adj+NORM; break;
}
return adj;
}

man(){
  set_name("man");
  set_short("A "+get_adj()+" man");
  set_long("A normal looking man, he is a citizen of Turtleville.  His clothes\n"+
           "are well kept and his hair brushed back.  He smiles gently as he\n"+
           "continues to walk around.\n");
  set_gender("male");
  set_level(15);
  set_hp(225);
  set_wc(20);
  set_ac(12);
  add_money(500+random(500));
}

woman(){
  set_name("woman");
  set_short("A "+get_adj()+" woman");
  set_long("An attractive female, she is a citizen of Turtleville.  Her hair has\n"+
           "a slight wave to it.  With her supple breasts and her curving hips its\n"+
           "a miricle she isn't married already.\n");
  set_gender("female");
  set_level(15);
  set_hp(225);
  set_wc(20);
  set_ac(12);
  add_money(500+random(500));
}

boy(){
  set_name("boy");
  set_short("A "+get_adj()+" boy");
  set_long("A small boy of turtleville.  His has a small cut on his left knee\n"+
           "and holes in serveral spots on his jeans.\n");
  set_gender("male");
  set_level(11);
  set_hp(165);
  set_wc(15);
  set_ac(9);
  add_money(500);
}

girl(){
  set_name("girl");
  set_short("A "+get_adj()+" girl");
  set_long("This little girl of turtleville is dressed in a danty sundress.  Her\n"+
           "soft hair is held back by some ties made from turtleshells.\n");
  set_gender("female");
  set_level(11);
  set_hp(165);
  set_wc(15);
  set_ac(9);
  add_money(500);
}

baby(){
  set_name("baby");
  set_short("A "+get_adj()+" baby");
  set_long("A small baby dressed only in a diaper belongs to some proud parents.  They\n"+
           "like this baby are citizens of Turtleville.\n");
  set_gender("female");
  set_level(2);
  set_hp(30);
  set_wc(5);
  set_ac(3);
  set_acrime(1);
}

bbaby(){
  baby();
  set_gender("male");
}

hooker(){
  set_name("hooker");
  set_short("A "+get_adj()+" hooker");
  set_long("This hooker is wearing very little clothing and has far to much makeup on\n"+
           "to be even slightly appealing.  Her clothes are slightly tattered and her\n"+
           "hair is quite dirty.\n");
  set_alias("hooker");
  set_gender("female");
  set_level(14);
  set_hp(210);
  set_wc(18);
  set_ac(1);
  add_money(850);
}

guard(){
  set_name("guard");
  set_short("A "+get_adj()+" city guard");
  set_long("This a guard of Turtleville.  He keeps the peace among the peacefull citizens\n"+
           "of this quiet town.  He is wearing very protective turtleshell armor and has a\n"+
           "filly feather sticking out of his helmet.\n");
  set_gender("male");
  set_level(20);
  set_hp(700);
  set_wc(30+random(10));
  set_ac(17+random(5));
  add_money(4000+random(1000));
  set_acrime(1);
}

heart_beat(){
  ::heart_beat();
if(hit_point > 0)
if(hit_point < ((max_hp*10)/100)){
    if(random(4)==0) run_away();
}
}
set_acrime(int a){ if(a == 1) crime = 1; }
crime_to_attack(){ return crime; }

