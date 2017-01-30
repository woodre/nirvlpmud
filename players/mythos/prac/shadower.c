#include "/players/mythos/closed/ansi.h"
string owner;

id(str) {return str == "shadower" || str == owner; }

long() {write("Your eyes seem unable to focus on "+capitalize(owner)+".\n");}

set_owner(str) { owner = str;}
query_owner() { return owner;}
		
get() {return 0; }

query_weight() {return 1000;}
query_value() {return 0; }

init() {
  add_action("nspell","kill");
  add_action("nspell","missile",2);
  add_action("nspell","shock",2);
  add_action("nspell","fireball",2);
  add_action("nspell","sonic",2); 
  call_out("dshadow",3);
}

nspell(str) {
  if(str == owner) {
    write("You miss.\n");
    tell_object(find_player(owner),BOLD+capitalize(this_player()->query_real_name())+
               " attempts an attack on you.\n"+NORM);
    return 1;}
}      
    
dshadow() {
object pest;
pest=find_player(owner);
if(pest->query_ghost()) {
tell_object(pest,"Shadow has disappeared.\n");
 destruct(this_object());}
 if(!present(owner,environment(this_object()))) {
 move_object(this_object(),environment(pest));}
 call_out("dshadow",3);
return 1;} 
