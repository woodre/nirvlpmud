#include "/players/coldwind/ansi.h"

#define USER this_player()
#define NAME USER->query_name()
#define HP   USER->query_hp()
#define MHP  USER->query_mhp()
#define SP   USER->query_sp()
#define MSP  USER->query_msp()

int uses;

id(str){ return str == "bunch" || str == "leaves"; }
short() { return YEL+"Bunch of brown leaves "+NORM+BOLD+"["+NORM+YEL+uses+NORM+BOLD+"]"+NORM; }  
long(){
   write(
"    A bunch of magical brown leaves collected and wrapped together. These\n"+
"leaves were used for centuries by the puplic to increase their health and\n"+
"stat of mind.\n"+   
"It has "+YEL+"["+uses+"]"+NORM+" bites left in it.\n"); }

query_value(){ return (uses * 400); }
query_save_flag(){ return 1; }

reset(arg){
  if(arg) return;
  uses = 3;      
  }
  
init(){
   add_action("use_leaf", "eat");
   }
   
use_leaf(str){
if(str == "leaves"){
if(environment(this_object()) != this_player()) return 0;
if(this_player()->query_stuffed() + 10 > (int)this_player()->query_level() *8){
    notify_fail("You are too full!\n");
    return 0;
  }
if(this_player()->query_soaked() + 10 > (int)this_player()->query_level() *8){
    notify_fail("The leaves contains too much juice.\n"+
	            "Your stomach can't hold that much!\n");
    return 0;
  }
if(!call_other(this_player(),"eat_food", 10) ||
 !call_other(this_player(), "drink_soft", 10)) return 0;
write( 
"You swallow the leaves leaving an awful taste in your mouth.\n");
call_other(this_player(),"heal_self", 50);
write(
"  HP ("+BOLD+""+HP+""+NORM+"/"+BOLD+""+MHP+""+NORM+")"+
"  SP ("+BOLD+""+SP+""+NORM+"/"+BOLD+""+MSP+""+NORM+")"+
" Stuff["+BOLD+""+USER->query_stuffed()*100/(USER->query_level()*8)+"%"+NORM+"]  "+
" Soak["+BOLD+""+USER->query_soaked()*100/(USER->query_level()*8)+"%"+NORM+"]\n");
uses -= 1;
write("You have enough leaves for "+BOLD+"["+uses+"]"+NORM+" uses.\n");
if(!uses){
	write(
	"You just ate the last leaf.\n");
	this_object()->set_weight(0);
	call_other(this_player(), "recalc_carry");
        destruct(this_object());
	return 1; }
return 1;
  }	
return;
}


get(){ return 1; }
query_weight(){ return 1; }	
