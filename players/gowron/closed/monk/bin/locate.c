#include "../def.h"

main(str) {
	object ob;
	string d,g;
	int pk,lev;

	if (!str) {
           write("Locate who?\n");
	   return 1;
	}
	ob = find_player(str);
	if (!ob) {
           write(str+" is not logged in right now.\n");
	   return 1;
	}
	pk = ob->query_pl_k();
	g = "players/gowron/closed/monk/bin/nirw"->query_gname(ob);
	lev = ob->query_level();
	d = environment(ob)->short();
	write(ob->short()+"\n");
	write("Guild: "+pad(g,25)+"Location: "+pad(d,37)+"\n");
	write("Level: "+pad(lev,25)+"Pk: ");
	if (!pk) 
           write("No ");
	else
           write("Yes");
	write("\n");
	return 1;
}

