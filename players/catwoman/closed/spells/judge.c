

init() {
    add_action("judge", "judge");
}



g_shout(str) {
	object ob;
	int i;
	ob=users();
	
	while(i<sizeof(ob)) {
		if (ob[i] && present("thief",ob[i]) && ob[i]!=this_player() ) {
			tell_object(ob[i],name+" shouts to the guild: "+str+"\n");
			}
		i += 1;
		}
	write("you shout to the guild: "+str+"\n");
	return 1;
	}
	
judge(z) {
	int a,b;
	string as,bs,str;
	object oa,ob;
	if (!z || sscanf(z," %s",str)!=2) str = z;
	if (!str || sscanf(str,"%s %s",as,bs)!=2 ) {
		write("Judge what against what?\n");
		return 1;
		}
	oa=present(as,this_player());
	ob=present(bs,this_player());
	if (!oa) {
		write("Couldn't find "+as+"\n");
		return 1;
		}
	if (!ob) {
		write("Couldn't find "+bs+"\n");
		return 1;
		}
	a = oa->weapon_class();
	b = ob->weapon_class();
	if (a && b) {
		if (a==b) 
			write("A voice says: They are of equal value.\n");
		else if (a<b) 
			write("A voice says: "+bs+" is better.\n");
		else 
			write("A voice says: "+as+" is better.\n");
		return 1;	
		}
	a = oa->armour_class();
	b = ob->armour_class();
 
	if (a && b) {
		if (a==b) 
			write("A voice says: They are of equal value.\n");
		else if (a<b) 
			write("A voice says: "+bs+" is better.\n");
		else 
			write("A voice says: "+as+" is better.\n");
		return 1;	
		}
	a = oa->query_value();
	b = ob->query_value();
	if (a && b) {
		if (a==b) 
			write("A voice says: They are of equal value.\n");
		else if (a<b) 
			write("A voice says: "+bs+" is better.\n");
		else 
			write("A voice says: "+as+" is better.\n");
		return 1;	
		}
	write("A voice says: I'm confused. I think you are comparing different types of\n");
	write("of objects. Either that, or valueless ones.\n");
	return 1;
	}
	

