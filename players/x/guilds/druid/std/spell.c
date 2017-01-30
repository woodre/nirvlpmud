#include "../defs.h"

int sp_cost;
int hp_cost;
int sac_cost;
string spell_name;

int check_spell(){
  if((int)gob->query_prof(spell_name) == -1) {
    write("What?\n");
    return 0;
  }
  if(sp_cost < (int)this_player()->query_sp()){
    write("You don't have enough magical energy to cast \""+spell_name+"\".\n");
    return 0;
  }
  if(hp_cost < (int)this_player()->query_hp()){
    write("You don't have enough health to cast \""+spell_name+"\".\n");
    return 0;
  }
  if(sac_cost < (int)gob->query_sac())
  {
    write("You haven't sacrificed enough to cast \""+spell_name+"\".\n");
    return 0;
  }
  if(!this_player()->query_weapon() ||
     !this_player()->query_weapon()->id("druid_staff"))
  {
    write("You are not wielding your oaken staff.\n");
    return 0;
  }
  
  if(!this_player()->query_weapon()->valid_druid_wield()){
    write("Your staff does not respond.\n");
    return 1;
  } 
  
  this_player()->add_sp(-sp_cost);
  this_player()->add_hp(-hp_cost);
  gob->add_sac(-sac_cost);
  
  write("You hold your staff above your head.\n");
  say((string)this_player()->query_name()+" holds "+possessive(this_player())+" staff above "+
    possessive(this_player())+" head.\n");
    
  if((int)gob->query_prof(spell_name) < random(100)){
    write(RED+"Your spell fails!\n"+NORM);
    command("grumble", this_player());
    return 0;
  }
  
  return 1;
}
  

void set_sp_cost(int x){
  sp_cost = x;
}

int query_sp_cost(){
  return sp_cost;
}

void set_hp_cost(int x){
  hp_cost = x;
}

int query_hp_cost(){
  return hp_cost;
}

void set_sac_cost(int x){
  sac_cost = x;
}

int query_sac_cost(){
  return sac_cost;
}

void set_spell_name(string sn){
  spell_name = sn;
}

string query_spell_name(){
  return spell_name;
}