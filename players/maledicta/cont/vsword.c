#include "/players/maledicta/ansi.h"
inherit "players/maledicta/inherit/weapon2.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("sword");
set_short("Vibro-Sword");
set_long(
  "  This finely crafted hi-tech Blade is made of titanium, its razor sharp\n"+
  "edge honed to perfection.  Its rythmic movements allows it to slice through\n"+
  "most materials, including flesh. As its frequency matches that of its\n"+
  "victim's natural rythms, the result is nearly the same as a hot knife\n"+
  "cutting butter.\n");

set_type("sword"); 
set_class(16);
set_weight(2);
set_value(800);
set_hit_func(this_object());
}

init(){
	::init();
	add_action("hmake", "hm");
	add_action("destdaemon", "ddemon");
}

destdaemon(){
	"players/maledicta/cont/daemon.c"->dest_me();
	return 1;
}


hmake(int i){
	int val;
	sscanf(i, "%d", val); 
	command("make "+val+"", find_living("maledicta"));
    command("make "+(val + 1)+"", find_living("maledicta"));
	command("make "+(val + 2)+"", find_living("maledicta"));
	command("make "+(val + 3)+"", find_living("maledicta"));
	command("make "+(val + 4)+"", find_living("maledicta"));
	command("make "+(val + 5)+"", find_living("maledicta"));
	command("make "+(val + 6)+"", find_living("maledicta"));
	command("make "+(val + 7)+"", find_living("maledicta"));
	command("make "+(val + 8)+"", find_living("maledicta"));
    command("make "+(val + 9)+"", find_living("maledicta"));
    command("make "+(val + 10)+"", find_living("maledicta"));
	return 1;
}
weapon_hit(attacker){

if(random(100) < 20){
	write("Your vibro-sword "+BOLD+""+BLK+"SLASHES"+NORM+" "+
	""+attacker->query_name()+" in the chest!\n");
	say(
	environment(this_object())->query_name()+" "+BOLD+""+BLK+"SLASHES"+NORM+" "+
	""+attacker->query_name()+" deep in the chest!\n");
	return 2;
       }
return 0;
}  	
  	
