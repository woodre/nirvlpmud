#include "/players/maledicta/ansi.h"
#define USER environment()

int ammo;

short(){ return HIM+"Dagger Belt ["+HIW+ammo+NORM+HIM+"]"+NORM; }

long(){
 write(
 "This is a leather belt that holds up to 40 tiny throwing\n"+
 "daggers.  You can 'fill_belt' if you carry a dagger. Once\n"+
 "you place a dagger in the belt, it is available for throwing\n"+
 "only.\n");
 return 1;
 }

id(str){ return str == "knife_belt" || str == "belt" || str == "dagger belt"; }

minus_one(){ ammo -= 1; if(ammo < 1){  USER->recalc_carry(); destruct(this_object()); } } 

add_ammo(int i){ ammo += i; if(ammo < 1){ USER->recalc_carry(); destruct(this_object()); } }
set_ammo(int i){ ammo = i; }
query_ammo(){ return ammo; }

query_weight(){ 
if(ammo > 30) return 3;
else if(ammo > 15) return 2;
else return 1;
}
get(){ return 1; }

query_value(){ return ammo * 8; }

init(){ 
  add_action("fill_it", "fill_belt");
  }

fill_it(){
object woot;
if(ammo > 39){ write("The belt is full!\n"); return 1; }
if(woot = present("dagger", this_player())){
   if(woot->query_wielded()){ write("You are wielding it!\n"); return 1; }
   write("You fill the belt with a dagger.\n");
   destruct(woot);
   add_ammo(1);
   return 1;
   }
else if(woot = present("knife", this_player())){
   write("You fill the belt with a dagger.\n");
   destruct(woot);
   add_ammo(1);
   return 1;
   }
else{
write("You don't have a dagger.\n");
return 1;
}
}
