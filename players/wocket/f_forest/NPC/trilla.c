inherit "/obj/monster.c";
#include "/players/wocket/closed/ansi.h"
#include "/players/wocket/f_forest/defs.h"

reset(arg){
  ::reset();
  if(arg){
    return;
  }
  set_name("trilla");
  set_short("A trilla");
  set_wc(100);
  set_hp(75);
  set_ac(9);
  set_level(19);
}

heart_beat(){
object att;
  ::heart_beat();
  if(hit_point < 10){
    if(random(4))
      run_away();
  }
  if(!query_attack()){
    if(present("trilla",environment(this_object()))){
      if(att = present("trilla",environment(this_object()))->query_attack()){
        if(random(10))
          this_object()->attack_object(att);
      }
    }  
    if(present("trilla 2",environment(this_object()))){
      if(att = present("trilla 2",environment(this_object()))->query_attack()){
        if(random(10))
          this_object()->attack_object(att);
      }
    }  
    if(present("trilla 3",environment(this_object()))){
      if(att = present("trilla 3",environment(this_object()))->query_attack()){
        if(random(10))
          this_object()->attack_object(att);
      }
    }  
  }
}
