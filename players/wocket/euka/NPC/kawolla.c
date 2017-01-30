#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";

string color;
int oranges;

reset(arg){
int i,a;
  ::reset(arg);
  if(arg) return;
  set_name("kawolla");
  set_race("seussian");
  set_al(random(1000));
  msgout = HIR+"swings"+OFF;
  set_chat_chance(5);
  load_chat("The kawolla swings from branch to branch.\n");
  load_chat("The kawolla chibbers at you.\n");
  load_chat("The kawolla pulls an orange off of a branch.\n");
  load_chat("The kawolla rolls over on to its back and stretches.\n");
  load_chat("The kawolla waves at you.\n");
  load_chat("The kawolla smiles happily.\n");
  set_a_chat_chance(40);
  load_a_chat("The kawolla hisses at you.\n");
  load_a_chat("The kawolla screetches.\n");
  load_a_chat("The kawolla bangs his arms to the ground.\n");
  load_a_chat("The kawolla leaps around.\n"); 
  color = get_color();
  switch(random(8)){
  case 0: child(); break;
  case 1: mother(); break;
  case 2: father(); break;
  case 3: elder(); break;
  case 4: rebel(); break;
  case 5: young(); break;
  case 6: female(); break;
  case 7: male(); break;
  }
 for(i=0,a=random(oranges);i<a;i++){
    move_object(clone_object("/players/wocket/std/orange.c"),this_object());
  }
}

get_color(){
  switch(random(6)){
  case 0: return HIB;
  case 1: return HIR;
  case 2: return HIG;
  case 3: return HIM;
  case 4: return HIY;
  case 5: return HIC;
  }
}

child(){
  set_short(YEL+"A "+HIG+"child"+OFF+YEL+" kawolla"+OFF);
  set_alias("child");
  set_level(12);
  set_hp(225);
  set_wc(16+random(4));
  set_ac(10+random(4));
  oranges = 1;
}

mother(){
  set_short(YEL+"A "+HIR+"mother"+OFF+YEL+" kawolla"+OFF);
  set_level(16);
  set_hp(400);
  set_wc(22+random(4));
  set_ac(13+random(4));
  oranges = 4;
}

father(){
  set_short(YEL+"A "+HIY+"father"+OFF+YEL+" kawolla"+OFF);
  set_alias("father");
  set_level(15);
  set_hp(300);
  set_wc(20+random(4));
  set_ac(11+random(4));
  oranges = 4;
}

elder(){
  set_short(YEL+"A "+HIC+"elder"+OFF+YEL+" kawolla"+OFF);
  set_level(11);
  set_hp(180);
  set_wc(15+random(4));
  set_ac(9+random(4));
  oranges = 1;
}

rebel(){
  set_short(YEL+"A "+HIM+"rebel"+OFF+YEL+" kawolla"+OFF);
  set_level(13);
  set_hp(200);
  set_wc(18+random(4));
  set_ac(10+random(4));
  oranges = 3;
}

young(){
  set_short(YEL+"A "+HIG+"young"+OFF+YEL+" kawolla"+OFF);
  set_level(8);
  set_hp(170);
  set_wc(13+random(4));
  set_ac(10+random(4));
  oranges = 1;
}

male(){
  set_short(YEL+"A "+HIY+"male"+OFF+YEL+" kawolla"+OFF);
  set_level(15);
  set_hp(300);
  set_wc(20+random(4));
  set_ac(12+random(4));
  oranges = 3;
}

female(){
  set_short(YEL+"A "+HIR+"female"+OFF+YEL+" kawolla"+OFF);
  set_level(14);
  set_hp(200);
  set_wc(19+random(4));
  set_ac(11+random(4));
  oranges = 3;
}

catch_tell(str){
string name,dir;
  if(sscanf(str,"%s leaves %s.",name,dir) == 2){
    if(random(2) == 1){
      say(HIR+"The kawolla swing on some vines.\n"+OFF);
      command(dir,this_object());
    }
  }
}

heart_beat(){
object att;
  ::heart_beat();
speach();
  if(!query_attack()){
  if(present("kawolla",environment(this_object()))){
    if(att = present("kawolla",environment(this_object()))->query_attack()){
      if(random(10)==1){
        say(HIR+"The kawolla rushes to the aid of his kin.\n"+OFF);
        this_object()->attack_object(att);
      }
    }
  }
 if(present("kawolla 2",environment(this_object()))){
    if(att = present("kawolla 2",environment(this_object()))->query_attack()){
      if(random(20)==1){
        write(HIR+"The kawolla rushes to the aid of his kin.\n"+OFF);
        this_object()->attack_object(att);
      }
    }
  }
 if(present("kawolla 3",environment(this_object()))){
    if(att = present("kawolla 3",environment(this_object()))->query_attack()){
      if(random(20)==1){
        write(HIR+"The kawolla rushes to the aid of his kin.\n"+OFF);
        this_object()->attack_object(att);
      }
    }
  }
}
  if(hit_point < ((max_hp*40)/100)){
    if(random(4) == 1){
      if(present("orange",this_object()))
      command("eat orange",this_object());
    }
  }
  if(hit_point < ((max_hp*20)/100)){
    if(random(4) == 1){
      run_away();
    }
  }
}

speach(){
string str,translation;
object obj;
switch(random(3)){
case 0:  str = "Umfa lista conna she";  break;
case 1: str = "Lasta bah niill doe mecan"; break;
case 2: str = "Billeso lista doe bah"; break;
}
translation = "This test is working. :) Now clean it up.";
obj = first_inventory(environment(this_object()));
while(obj){
  tell_object(obj,"Kawolla syas, \""+str+"\"\n");
  if(present("euka_quest_translator",obj)){
    tell_object(obj,"("+translation+")\n");
  }
  obj = next_inventory(obj);
}

return 1;
}
