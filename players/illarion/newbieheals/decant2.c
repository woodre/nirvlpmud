/* 20 hp/sp heal, 8 tox, intox, at 480 coins. */
/*  Modified to 20 hp only, 8 tox, intox, cost 320 coins
    Softly January, 2001 */
#include "/players/softly/closed/ansi.h"

#define USER this_player()
#define NAME USER->query_name()
#define HP   USER->query_hp()
#define MHP  USER->query_mhp()
#define SP   USER->query_sp()
#define MSP  USER->query_msp()

int uses;

id(str){ return str == "decanter"; }
short() { return "Decanter of Healing ["+BOLD+uses+NORM+"]"; }  
long(){
   write(
"  This is a small decanter of healing liquid. To use\n"+
"simply 'drink' the 'liquid' from it.\n"+
"It has "+BOLD+"["+uses+"]"+NORM+" uses left in it.\n"); }

query_value(){ return (uses * 100); }
query_save_flag(){ return 1; }

reset(arg){
  if(arg) return;
  uses = 3;      
  }
  
init(){
   add_action("use_it", "drink");
   }
   
use_it(str){
	if(!str || str != "liquid"){
        notify_fail("Drink what?\n");
        return 0;
      }
    if(environment() != this_player())
      return (notify_fail("You must be carrying the heal to use it.\n"), 0);
if(!call_other(this_player(),"drink_alcohol", 8)) return 0;
write(
"You open the small decanter and drink from it.\n");   
say(
NAME+" drinks from a decanter.\n");


call_other(this_player(),"add_hit_point", 20);
call_other(this_player(),"recalc_carry");
write(
"     HP>>>"+HIM+""+HP+""+NORM+"/"+HIM+""+MHP+""+NORM+" "+
" SP>>>"+HIM+""+SP+""+NORM+"/"+HIM+""+MSP+""+NORM+" "+
" Intox["+HIM+""+(USER->query_intoxination()*100)/(USER->query_level()+3)+"%"+NORM+"]\n");
uses -= 1;
write("The container has "+HIM+"["+uses+"]"+NORM+" uses left.\n");
if(!uses){
	write(
	"Useless now, you drop the decanter.\n");
	this_object()->set_weight(0);
	call_other(this_player(), "recalc_carry");
        destruct(this_object());

	return 1; }
	
return 1; }


get(){ return 1; }

query_weight(){ 
return 1;
 }	

status is_heal() { return 1; } /* 03/13/06 Earwax */