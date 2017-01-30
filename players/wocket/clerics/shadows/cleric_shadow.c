#include "../defs.h"

object player;

start_shadow(who)
{
	player = who;
	shadow(player,1);
	return 1;
}

stop_shadow()
{
	shadow(player,0);
	destruct(this_object());
	return 1;
}

quit(){
	shadow(player,0);
	player->quit();
	return 1;
}

short(){
	string ret;
	ret = player->short();
	return ret+" (Shadowed)";
}
