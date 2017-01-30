#include "/players/maledicta/ansi.h"
inherit "/obj/generic_heal";

#define USER this_player()
#define NAME USER->query_name()
#define HP   USER->query_hp()
#define MHP  USER->query_mhp()
#define SP   USER->query_sp()
#define MSP  USER->query_msp()

int uses;

id(str){ return str == "food" || str == "meat"; }
short() { return "A slab of meat"; }  
long(){
   write(
"  This is a large slab of meat. It is probably from an alligator or\n"+
"some other amphibious creature. You can 'eat' the 'meat'.\n"); }

query_value(){ return (uses * 650); }
query_save_flag(){ return 1; }

reset(arg){
  if(arg) return;
  uses = 3;      
  }
  
init(){
   add_action("use_it", "eat");
   }
   
use_it(str){
if(!str) return;

if(str != "meat") return;

if(!call_other(this_player(),"eat_food", 8)) return 0;

write(
"You gorge yourself on the delicious meat.\n");   
say(
NAME+" eats some meat.\n");


call_other(this_player(),"heal_self", 41 + random(20));
call_other(this_player(),"recalc_carry");
uses -= 1;
write("The meat has "+BOLD+uses+NORM+" bites left.\n");
if(!uses){
	write(
	"Useless now, you drop the bone to the ground.\n");
	this_object()->set_weight(0);
	call_other(this_player(), "recalc_carry");
        destruct(this_object());

	return 1; }
	
return 1; }


get(){ return 1; }
query_weight(){ return 1; }	
