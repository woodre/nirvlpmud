#include "../def.h"

main() {
	object ob;
	int dam;

	if (RANK < 2) {
	   LOW_RANK;
	   return 1;
	}
	if (MYSP < 10) {
           NO_SP;
	   return 1;
	}
	ob = TP->query_attack();
	if (!ob) {
           write("You must be in combat to use this spell.\n");
	   return 1;
	}
	if (ob->query_npc() != 1) {
           write("You cannot use this spell against a player.\n");
	   return 1;
	}
	dam = 10 + random(RANK);
	ob->hit_player(dam);
	write("You hit "+ob->query_name()+" with a circle kick.\n");
	say(ME+" hits "+ob->query_name()+" with a circle kick.\n");
	return 1;
}

