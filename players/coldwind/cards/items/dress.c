#include "/players/coldwind/define.h"
inherit "obj/armor";
int searched;
reset(arg) { 
searched = 0;
set_name("dress");
set_alias("armor");
set_short(RED+"Dress of the Queen"+NORM);
set_long(
"A long red dress decorated with some golden lines and shapes.\n"+
"You notice a small secret pocket near the waist line of the dress.\n"+
"Hrmmm... What could be hidden in there??\n"+NORM);
set_ac(3);
set_type("armor");  
set_weight(2);
set_value(700);
}

void init(){
	::init();
	add_action("search_cmd", "search");
	add_action("look_cmd", "look");
	add_action("look_cmd", "l");
}

status search_cmd(string str){
	if(!str) return 0;
        if(str == "pocket" || str == "dress"){
		if(searched == 1){
			write("You search the secret pocket,but you find nothing.\n");
			return 1; }
		if(searched == 0){
			write("You search the secret pocket and find a key!\n");
			MOCO("/players/coldwind/cards/items/key.c"), tp);
			searched = 1;
			return 1; }
		else return 0;
		return 1; }
	else return 0;
return 1; }


status look_cmd(string str)  {
	  if(!str)		  return 0;
if(str == "pocket" || str == "at pocket")
{
		  write(
"The small secret pocket sewed on the inside of the dress near \n"+
"the waist line. Maybe you should search it.\n");
		  return 1;	  }
	  else		  return 0;
return 1;  }
