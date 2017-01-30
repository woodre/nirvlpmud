#include "../def.h"

query_gname(ob) {
	object o;

	if (present("life", ob))
           return "Undead";
	if (present("mrobe", ob))
	   return "Monk";
	if (present("new_mrobe", ob))
           return "new_monk";
	if (present("implants", ob))
           return "Cyberninja";
	if (present("vampirefangs", ob))
           return "Vampire";
	if (present("clay", ob)) 
           return "Polymorph";
	if (present("medal", ob))
           return "Paladin";
	if (present("instrument", ob))
           return "Bard";
	if (present("mark", ob))
           return "Shardak";
	if (present("spellbook", ob))
           return "Mage";
	return "None";	
}

main() {
	object ob,env;
	string name,desc,gname;
	int i,c,level;
	status pk;

	ob = users();
	c = 80;
	while (c--)
              write("-");
	write("\n");
	write(pad("Name", 15));
	write(pad("Pk", 5));
	write(pad("Level", 7));
	write(pad("Guild", 20));
	write(pad("Location", 31));
	write("\n");
	c = 80;
	while (c--)
	      write("-");
	write("\n");
	i = sizeof(ob);
	while (i--) {
              name = ob[i]->query_name();
	      pk = ob[i]->query_pl_k();
	      level = ob[i]->query_level();
	      gname = query_gname(ob[i]);
	      env = environment(ob[i]);
	      if (!env)
                 desc = "Location Unknown";
	      else
                 desc = env->short();
	      write(pad(name,15));
	      if (pk)  
		 write(pad("Yes", 5));
	      else
	         write(pad("No", 5));
	      if (level < 20) 
		 write(pad(level, 7));
	      else
	      if (level < 100) 
                 write(pad("wiz", 7));
	      else
              if (level < 10000)
                 write(pad("arch", 7));
	      else
                 write(pad("god", 7));
	      write(pad(gname,20));
	      write(pad(desc,31));
	      write("\n");
	}
	c = 80;
	while (c--)
              write("-");
	write("\n");
	write("Total # of users logged in: "+(sizeof(ob)-1)+"\n");
	c = 80;
	while (c--)
              write("-");
	write("\n");
	return 1;
}

