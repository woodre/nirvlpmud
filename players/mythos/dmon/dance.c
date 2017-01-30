#include "/players/mythos/closed/ansi.h"
inherit "players/mythos/dmon/mon";
string bowner;
int jj;
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("dancing sword");
  set_short(RED+"Dancing Sword of the Hannya"+NORM);
  set_alias("dancing");
  set_race("sword");
  set_level(1);
  set_hp(210);
  set_al(0);
  set_wc(21);  
  set_ac(9);
  set_mult(2);
  set_extra(6);
  set_a_chat_chance(5);
  load_a_chat("The dancing sword shimmers in the air.\n");   
  load_a_chat("A blazing sword swoops down at its foe!\n");
  load_a_chat("The blade hungers for blood.\n");
  jj = 0;
  set_dead_ob(this_object());
  call_out("checks",40);
}
set_own(str) { bowner = str; }

checks() { 
  if(!environment(this_object())) return 1;
  if(!find_player(bowner)) { revert(); return 1; }
  if(environment(find_player(bowner)) != environment(this_object())) {
    revert(); return 1; }
call_out("checks",40);
return 1; }

monster_died() {
  tell_room(environment(this_object()),"The dancing blade falls to the ground!!\n");
  destruct(present("sword",this_object()));
}

revert() {
object obs;
obs = present("sword",this_object());
 obs->set_short(RED+"Dancing Sword of the Hannya"+NORM);
  if(find_player(bowner)) {
      tell_room(environment(this_object()),
       "The Dancing Blade flies back into the hands of its owner!\n");
     move_object(obs,find_player(bowner));
  } else {
    tell_room(environment(this_object()),
       "The Dancing Blade glides down and rests upon the ground.\n");
    move_object(obs,environment(this_object()));
  }
  destruct(this_object());
return 1; }
    

heart_beat() {
  ::heart_beat();
    if(environment(find_player(bowner)) == environment(this_object())) {
      if(find_player(bowner)->query_attack()) { 
        if(!query_attack()) 
        this_object()->attack_object(find_player(bowner)->query_attack());
        else if(find_player(bowner)->query_attack() != query_attack())
          this_object()->attack_object(find_player(bowner)->query_attack());
          jj = 0;
      } else {
       jj = jj + 1; 
       if(jj > 3) { revert(); return 1; }
      }
    }  
}
