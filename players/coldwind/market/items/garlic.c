#include "/players/coldwind/ansi.h"

#define USER this_player()
#define NAME USER->query_name()
#define HP   USER->query_hp()
#define MHP  USER->query_mhp()
#define SP   USER->query_sp()
#define MSP  USER->query_msp()

int uses;

id(str){ return str == "garlic" || str == "garlic bag"; }
short() { return WHT+"Small bag of garlic "+NORM+BOLD+"["+NORM+WHT+uses+NORM+BOLD+"]"+NORM; }  
long(){
   write(
"    A few garlic peices peeled and collected together in a small \n"+
"bag. These leaves were used for centuries by the magicians as well as\n"+
"healers to increase the stat of mind.\n"+   
"It got enough for "+WHT+"["+uses+"]"+NORM+" more uses.\n"); }

query_value(){ return (uses * 400); }
query_save_flag(){ return 1; }

reset(arg){
  if(arg) return;
  uses = 3;      
  }
  
init(){
   add_action("use_heal", "eat");
   }
   
use_heal(str){
if(str == "garlic"){
if(environment(this_object()) != this_player()) return 0;
if(this_player()->query_stuffed() + 10 > (int)this_player()->query_level() *8){
    notify_fail("You are too full!\n");
    return 0;
  }
if(this_player()->query_soaked() + 10 > (int)this_player()->query_level() *8){
    notify_fail("The garlic pieces contains too much juice.\n"+
	            "Your stomach can't hold that much!\n");
    return 0;
  }
if(!call_other(this_player(),"eat_food", 10) ||
 !call_other(this_player(), "drink_soft", 10)) return 0;
write( 
"You feel more focused as the garlic's magical power runs in your veins.\n");
call_other(this_player(),"add_spell_point", 75);
write(
"  HP ("+BOLD+""+HP+""+NORM+"/"+BOLD+""+MHP+""+NORM+")"+
"  SP ("+BOLD+""+SP+""+NORM+"/"+BOLD+""+MSP+""+NORM+")"+
" Stuff["+BOLD+""+USER->query_stuffed()*100/(USER->query_level()*8)+"%"+NORM+"]  "+
" Soak["+BOLD+""+USER->query_soaked()*100/(USER->query_level()*8)+"%"+NORM+"]\n");
uses -= 1;
write("You have enough garlic pieces for "+BOLD+"["+uses+"]"+NORM+" uses.\n");
if(!uses){
	write(
	"You just ate the last garlic piece.\n");
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
