/* 50 add_spell_points, 3 charges, at 800 coins.  stuff and soak heal

   at 10/10 soaked/stuffed */



#include "/players/jaraxle/ansi.h"



#define USER this_player()

#define NAME USER->query_name()

#define HP   USER->query_hp()

#define MHP  USER->query_mhp()

#define SP   USER->query_sp()

#define MSP  USER->query_msp()



int uses;



id(str){ return str == "potion"; }

short() { return "Potion of "+HIG+"Mana"+NORM+" "+BOLD+uses+NORM+""; }  

long(){

   write(

"This is a small vial that holds magical energies that will\n"+

"infuse your body.\n"+

"To use it 'gulp' the potion.\n"+

"It has "+BOLD+"["+uses+"]"+NORM+" uses left in it.\n"); }



query_value(){ return (uses * 200); }

query_save_flag(){ return 1; }



reset(arg){

  if(arg) return;

  uses = 3;      

  }

  

init(){

   add_action("use_kit", "gulp");

   }

   

use_kit(str){

if(str == "potion" || str == "vial"){

if(environment(this_object()) != this_player()) return 0;

if(this_player()->query_stuffed() + 10 > (int)this_player()->query_level() * 8){

write(HIR+"You are too stuffed to use it!"+NORM+"\n"); return 1; }

if(this_player()->query_soaked() + 10 > (int)this_player()->query_level() * 8){

write(HIR+"You are too soaked to use it!"+NORM+"\n"); return 1; }

if(!call_other(this_player(),"eat_food", 10) || 

!call_other(this_player(), "drink_soft", 10)) return 0;

write(

"You sip from the potion and feel energized!\n");   

call_other(this_player(),"add_spell_point", 50);

call_other(this_player(),"recalc_carry");



write(

"     HP>>>"+HIB+""+SP+""+NORM+"/"+HIB+""+MSP+""+NORM+"  "+

" Stuff["+HIB+""+USER->query_stuffed()*100/(USER->query_level()*8)+"%"+NORM+"]  "+

" Soak["+HIB+""+USER->query_soaked()*100/(USER->query_level()*8)+"%"+NORM+"]\n");

uses -= 1;

write("The potion has "+HIM+"["+uses+"]"+NORM+" left.\n");



if(!uses){

	write(

	"You toss the vial away and feel a moment of sadness as you litter.\n");

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

