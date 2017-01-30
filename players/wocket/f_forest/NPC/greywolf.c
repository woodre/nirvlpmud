#include "/players/wocket/closed/ansi.h"
#define ENV_TO environment(this_object())
inherit "/obj/monster.c";

reset(arg){
  ::reset();
  if(arg) return;
  set_name("wolf");
  set_alt_name("w_wolf");
  set_short("A "+BLK+BOLD+"grey"+OFF+" wolf");
  set_level(20);
  set_wc(50);
  set_hp(100);
  set_ac(10);
}

init(){
::init();
  if(present("w_wolf 6",ENV_TO))
    run_away();
  if(hunted){
  if(present(hunted->query_real_name(),ENV_TO))
    this_object()->attack_object(hunted);
  }
}

catch_tell(str){
string first,second;
  if(sscanf(str,"%s leaves %s.",first,second) == 2){
    if(first == "Wolf"){
      if(present("w_wolf 2",ENV_TO) == this_object()  && !present("w_wolf 6",ENV_TO))
      call_out("follow",2,second);
    }
    if(attacker_ob && first == attacker_ob->query_name()){
      if(present("w_wolf 1",ENV_TO) == this_object())
      call_out("follow",1,second);
    }
  }
}

follow(cmd){
 remove_call_out("follow");
  command(cmd);
}

heart_beat(){
object att;
object *everything;
int i,a;
  ::heart_beat();
  if(attacker_ob && environment(attacker_ob) == ENV_TO ){
    if(!present("w_wolf 2",ENV_TO))
      run_away();
    else{
    if(!random(5)){
      attacker_ob->hit_player(50);
      tell_object(attacker_ob,HIR+"The wolf snaps at you.\n"+
                                  "Razor sharp teeth clamp onto your arm ripping flesh away.\n"+
                                  "Blood pours from your open wounds.\n"+
                                  "Pain and terror consumes you.\n"+OFF);
      attacker_ob->remote_say("The wolf bites into "+attacker_ob->query_name()+".\n");
    }
    }
  }
  if(!attacker_ob){
    everything = all_inventory(ENV_TO);
    if(!random(2))
    for(i=0,a=sizeof(everything);i<a;i++){
      if(everything[i]->id("w_wolf") && everything[i] != this_object()){
        if(att = everything[i]->query_attack()){
          tell_room(ENV_TO,HIR+"The wolf leaps to attack, assisting its kin.\n"+OFF); 
          this_object()->attack_object(att);
        }   
      }
    }
  }
  if(!attacker_ob){
    if(!random(20)){
      if(present("wolf 1",ENV_TO)  == this_object())
        run_away();
    } 
  }
}  

test_if_any_here(){
  return 1;
}