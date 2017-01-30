inherit "/obj/treasure.c";
#include <ansi.h>

id(str) {
return str == "popcorn" || str == "stick";
}

short() { return "A huge bag of popcorn"; }
long() {
	write("This is a large bag of popcorn. It can be\n"+
		  "used for eating, if you are hungry\n"+
		  "enough, you could possibly eat it.\n");
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
	
	if(str != "popcorn")
	{
		write("You can't eat that!\n");
		return 1;
	}
	
	if(str == "popcorn")
	{
		write("You grab a piece of popcorn and fling it into your mouth!\n");
		say("Shinshi grabs a piece of popcorn and tosses it into his mouth!\n");
		return 1;
	}
}