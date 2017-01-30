inherit "/obj/treasure.c";
#include <ansi.h>

id(str) {
return str == "bacon" || str == "shinshi_bacon";
}

short() { return "Ten Pounds of Bacon"; }
long() {
	write("This is ten pounds of wonderful bacon!! Who could\n"+
		  "possible eat this much bacon? Wonder what it is for...\n");
}

get() { return 1; }
query_weight() { return 10; }
query_value(){ return 0; }


init()
{
	::init();
	
	add_action("eat", "eat");
}

eat(str){
	
	if(!str)
	{
		write("What would you like to eat?\n");
		return 1;
	}
	
	if(str != "bacon")
	{
		write("You can't eat that!\n");
		return 1;
	}
	
	if(str == "bacon")
	{
		write("You just ate ten pounds of bacon.. FATTY!\n");
		destruct(this_object());
		return 1;
	}
}