#include <ansi.h>
#define USER environment(previous_object())
#define ENV environment(USER)

main(string str){
	
if(previous_object()->query_wep_life() <= 0){
  tell_object(USER, "What?\n");
   return 1;
  }		

if(!str){ tell_object(USER,
           "Unlatch what?\n");
           return 1;
        }
        
if(str == "lightsaber" || str == "saber"){
object ls;
say(USER->query_name()+" unlatches "+USER->query_possessive()+" lightsaber.\n");
tell_object(USER,
"You unlatch your lightsaber from your belt.\n");
ls = clone_object("/players/dragnar/Jedi/obj/saber.c");
ls->set_wep_color(previous_object()->query_wep_color());
ls->set_wep_life(previous_object()->query_wep_life());
move_object(ls, USER);
previous_object()->set_wep_color(NORM);
previous_object()->set_wep_life(0);
return 1;
 }
tell_object(USER, "What?\n");
return 1;
}
