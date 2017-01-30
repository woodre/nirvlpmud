#include "../def.h"

main() {
	int i,u;
	object ob;
	
	ob = CHATD->query_users();
	i = sizeof(ob);
	u = 0;
	while (i--) {
	      if (ob[i] != 0) {
	         write(ob[i]->query_name()+" is ");
	         write("rank "+present("new_mrobe", ob[i])->query_rank());
	         if (!present("new_mrobe", ob[i])->query_muffle())
	            write(" and is muffled\n");
	         else
                    write("\n");
		u++;
		}
	}
	write(u+" monks logged in right now.\n");
	return 1;
}
