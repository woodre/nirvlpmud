inherit "obj/armor";
#include "/players/zeus/closed/all.h"

int searched;

reset(arg){
   ::reset(arg);

searched = 0;  /* haven't searched   */

   set_name("robe");
   set_short("A large brown hooded robe");
  set_long(
"This is a large brown robe.  It was sewn in such a way that it fits\n"+
"extremely loosely on the wearer.  It has an oversized hood which drapes\n"+
"over the wearers head, completely concealing their face.  There is one\n"+
"small pocket sewn into the inside of the robe.\n");
  set_type("armor");
  set_ac(2);
  set_weight(1);
  set_value(15);
}

void init(){
	::init();
	add_action("search_cmd", "search");
	add_action("look_cmd", "look");
	add_action("look_cmd", "l");
}

status search_cmd(string str){
	if(!str) return 0;
        if(str == "pocket" || str == "robe"){
		if(searched == 1){
			write("You search the pocket and find nothing.\n");
			return 1; }
		if(searched == 0){
			write("You search the pocket and find a key!\n");
			MO(CO("/players/zeus/realm/OBJ/hermit_key.c"), TP);
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
"The small pocket on the inside of the robe may have something in it.\n");
		  return 1;	  }
	  else		  return 0;
return 1;  }
