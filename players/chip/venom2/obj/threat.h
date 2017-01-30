/*******************************************************************
******** Threat List, Same as Original - Exactly *******************
*******************************************************************/
new_who(){
	int i;
	int b;
	int namer;
	int gspacer;
	int guilder;
	int spacer;
	object *plist;
	if(USER->query_ghost()) return 0;
	if(!USER->query_pl_k()){
		write("Why would you care about such things when your own pk isn't set?\n");
		return 1;
	}
	
	plist = users();
	write(
		"               "+BOLD+"-=[  "+HIR+"Threat List"+NORM+BOLD+"  ]=-"+NORM+"\n\n"+
		""+HIR+"Name"+NORM+BOLD+":         "+HIB+"Guild"+NORM+BOLD+":"+
	"        Room:"+NORM+"\n");
	
	for(i=0; i<sizeof(plist); i++){
		if(plist[i]->query_invis() && plist[i]->query_level() >= USER->query_level()) continue;
		if(plist[i]->query_level() < 20){
			if(plist[i]->query_pl_k() || plist[i]->query_fight_area()){
				namer = strlen(plist[i]->query_name());
				spacer = 14 - namer;
				write(
				HIR+plist[i]->query_name()+""+NORM);
				for(b=0;b<spacer;b++) {
					write(" ");
				}
				if(plist[i]->query_guild_name()){
					guilder = strlen(plist[i]->query_guild_name());
					gspacer = 14 - guilder;
					write(
					HIB+plist[i]->query_guild_name()+NORM+"");
				}
				else{
					gspacer = 10;
					write(HIB+"none"+NORM);
				}
				for(b=0;b<gspacer;b++) {
					write(" ");
				}
				if(environment(plist[i])){
					write(environment(plist[i])->short()+"\n");
				}
				else{
					write("Unknown Location\n");
				}
			}
		}
	}
	write("\n\n");
	return 1;
}

