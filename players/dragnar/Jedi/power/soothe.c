#include "defs.h"

inherit CMDBASE;

#define USER environment(previous_object())
#define delay previous_object()->query_force_delay()
main() {
object att,ob;
int h;
ob = all_inventory(environment(USER));
h = 0;

if(skill_check(1)){ return 1;}
if(cp_check(15)){ return 1;}
if(delay){ 
	write("You are too weary to concentrate on that.\n");
	return 1;
	}
 
 if(previous_object()->query_darkside() && random(100) < 50){
  tell_object(USER,
  "Your anger breaks your concentration, your power fails.\n");
  previous_object()->adj_cp(-8);
  return 1;
  }
 while(h<sizeof(ob)) {
  if(ob[h]->query_attack()) { 
    att = ob[h]->query_attack();
    ob[h]->stop_fight();
    att->stop_fight();
      }
h++;
   }
tell_room(environment(USER),
"You feel a soothing power flow into your mind. All the fighting in the room\n"+
"stops.\n");
previous_object()->adj_cp(-15);
previous_object()->set_force_delay(2);
return 1; 
  }

