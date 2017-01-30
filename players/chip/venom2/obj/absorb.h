/**********************************************************************
*********** Absorb Corpse - Same Ol' Also *****************************
***********************************************************************/
absorb(str){
	object corpse;
	int cvalue;
	string extra;
	
	if(USER->query_ghost()) return 0;
	
	corpse = present("corpse", environment(USER));
	
	if (!corpse) {
		write("There is no corpse.\n");
		return 1;
	}
	
	if(corpse->query_corpse_level() < 1){
		write("You cannot absorb that, it is useless.\n");
		return 1;
	}
	
	if (sscanf(file_name(corpse),"obj/corpse%s",extra)!=1) return 1;
	
	tell_room(environment(USER),
		USER->query_name()+" places his palm onto a corpse.\n"+
	HIK+"Dark Matter"+NORM+" seeps out of "+USER->query_name()+"'s palm covering the corpse.\n");
	tell_room(environment(USER),
		"The black ooze seeps back inside "+USER->query_name()+", leaving no remnants of\n"+
	"the corpse.\n");
	
	cvalue = (corpse->query_corpse_level() / 2) + random(corpse->query_corpse_level() / 2) + 5; 
	  /* changed from (corpse->query_corpse_level() / 2) + random(corpse->query_corpse_level() / 2) + 1; -Chip(4-17-09)*/
	add_mp(cvalue);
	destruct(corpse);
	return 1;
}
