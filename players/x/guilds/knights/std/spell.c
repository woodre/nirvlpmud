#include "../defs.h"

int sp_cost;
int hp_cost;
string spell_name;

int check_spell(){
  if(this_player()->query_ghost()) {
    write("You are dead.\n");
    return 0;
  }
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
  this_player()->add_sp(-sp_cost);
  this_player()->add_hp(-hp_cost);
 
  if((int)gob->query_prof(spell_name) < random(100)){
    write(RED+"Your spell fails!\n"+NORM);
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

void set_spell_name(string sn){
  spell_name = sn;
}

string query_spell_name(){
  return spell_name;
}