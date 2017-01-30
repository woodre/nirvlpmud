#include "/players/mythos/closed/ansi.h"
#define MAXUSE 1000
inherit "players/mythos/prac/pet";
int use

reset(arg) {
  ::reset(arg);
  if(arg) return;
  use = 0;
}

sswitch(str) {
   if(!check_ok()) return 0;
   if(!str) return 0;
   if(id(str)) { write("You can not switch owners with this pet.\n"); 
    return 1; }
}

name(str) {  
   if(!check_ok()) return 0;
   if(!str) return 0;
   write("You can not do that with this pet.\n");
   return 1; 
}

multiple_on() { 
  set_mult(3);
  set_mult_chance(10);
  set_mult_dam1(1);
  set_mult_dam2(20); 
return 1; }
  
special_on(int n) {
  if(!n) return 1;
  if(n > 0) {
    set_a_chat_chance(10);
    load_a_chat("The "+ oowner->query_name()+"'s pet screams in rage!\n");
  }
  if(n > 1) {
    set_chance(n);
    set_spell_dam(20);
    set_spell_mess1("The "+oowner->query_name()+"'s "+name+" lashes out!\n");
    set_spell_mess2("The "+ oowner->query_name()+"'s "+name+" lashes out!\n");
  }
return 1; }

heart_beat() {
  use++;
  if(use > MAXUSE) {
    set_heart_beat(0);
    if(find_player(owned)) 
      tell_object(find_player(owned),
      "The "+name+" can no longer stay in the prime material plane.\n"+
      "It has left.\n");
    destruct(this_object());
  return 1; }
  ::heart_beat();
} 