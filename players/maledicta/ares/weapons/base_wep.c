/*  A basic weapon that can be upgraded with specials and
    other abilities. */

inherit "obj/weapon.c";
#define USER environment()
#define ATT USER->query_attack()
int dam,dam2,chance,chance2;
string mess_me,mess_me2,mess_you,mess_you2;
int heal,heal_ch;
int mana,mana_ch;
string heal_mess,heal_mess_other;
string mana_mess,mana_mess_other;
string *opp;
string opp_mess,opp_mess_other;
int opp_dam,opp_chance;

reset(arg){
  ::reset(arg);
  if (arg) return;
set_hit_func(this_object());
}

generic_object(){ return 1; }

set_dam(int i){ dam = i; }
query_dam(){ return dam; }
set_dam2(int i){ dam2 = i; }
query_dam2(){ return dam2; }

set_mess_me(str){ mess_me = str; }
set_mess_you(str){ mess_you = str; }
set_mess_me2(str){ mess_me2 = str; }
set_mess_you2(str){ mess_you2 = str; }
set_chance(int i){ chance = i; }
set_chance2(int i){ chance2 = i; }
set_heal(int i){ heal = i; }
set_heal_ch(int i){ heal_ch = i; }
set_heal_mess(str){ heal_mess = str; }
set_heal_mess_other(str){ heal_mess_other = str; }
set_mana(int i){ mana = i; }
set_mana_ch(int i){ mana_ch = i; }
set_mana_mess(str){ mana_mess = str; }
set_mana_mess_other(str){ mana_mess_other = str; }
add_opponent(str){ 
  if(!opp) opp = ({ str });
  else opp += ({ str });
  }
set_opp_dam(int i){ opp_dam = i; }
set_opp_chance(int i){ opp_chance = i; }
set_opp_mess(str){ opp_mess = str; }
set_opp_mess_other(str){ opp_mess_other = str; }

weapon_hit(attacker){
int tot;
  if(opp && opp_dam && random(100) < opp_chance){
     int i;
     for(i=0; i < sizeof(opp); i++){
       if(call_other(ATT,"id", opp[i])){
         if(opp_mess) tell_object(USER, opp_mess+"\n");
         if(opp_mess_other) tell_room(environment(USER), opp_mess_other+"\n", ({USER}));
         tot += opp_dam;
         }
      }
  }                   
  if(heal && random(100) < heal_ch){
     if(heal_mess) tell_object(USER, heal_mess+"\n");
     if(heal_mess_other) tell_room(environment(USER), heal_mess_other+"\n", ({ USER }));
     USER->add_hit_point(heal);
     }
  if(mana && random(100) < mana_ch){
     if(mana_mess) tell_object(USER, mana_mess+"\n");
     if(mana_mess_other) tell_room(environment(USER), mana_mess_other+"\n", ({ USER }));
     USER->add_spell_point(mana);
     }
  if(dam && random(100) < chance){
     if(mess_me) tell_object(USER, mess_me+"\n");
     if(mess_you) tell_room(environment(USER), mess_you+"\n", ({ USER }));
     tot += dam;
     }
  if(dam2 && random(100) < chance2){
     if(mess_me2) tell_object(USER, mess_me2+"\n");
     if(mess_you2) tell_room(environment(USER), mess_you2+"\n", ({ USER }));
     tot += dam2;
     }
  return tot;
  }
