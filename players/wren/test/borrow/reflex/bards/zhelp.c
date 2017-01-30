bard_lore(str){
	string named,named2;
	int i;
	
	if(this_player()->query_ghost()) return;
	if(!str){
		write("                      "+HIW+"[ Bard Help ]"+NORM+"\n");
		cat("/players/reflex/guilds/bards/doc/main.bard");
		write("                      "+HIW+"     -+-    "+NORM+"\n");
		return 1;
	}
	named = lower_case(str);
	named2 = strlen(named);
	i=0;
	while(i < named2) {
		if ((str[i] < 'a' || str[i] > 'z') && 
           (str[i] < '0' || str[i] > '9') && str[i] != '_'){
				write("Subject not found.\n");
				return 1;
			   }
			i += 1;
		}
    
		if(file_size("/players/reflex/guilds/bards/doc/"+str+".bard") == -1){
			write("Subject not found.\n");
			return 1;
		}
		write("                "+HIW+"    [ Bard "+capitalize(str)+" ]"+NORM+"\n");
		cat("/players/reflex/guilds/bards/doc/"+str+".bard");
		write("                      "+HIW+"   -+-    "+NORM+"\n");
		
		
		return 1;
	}
