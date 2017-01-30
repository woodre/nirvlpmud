/***************************************************************
*************** Help Files!!! **********************************
**************************************************************/
link_help(str){
	string named,named2;
	int i;
	if(USER->query_ghost()) return 0;
	if(!str){
		cat("/players/chip/venom2/docs/main.sym");
		return 1;
	}
	named = lower_case(str);
	named2 = strlen(named);
	i=0;
	while(i < named2){
		if(str[i] < 'a' || str[i] > 'z'){
			write("Invalid help file " + str + "\n");
			return 1;
		}
		i += 1;
	}
	if(file_size("/players/chip/venom2/docs/"+str+".sym") < 1){
		write("There is no help for that topic.\n");
		return 1;
	}
	write("                 -=["+COLOR+"Link "+capitalize(str)+NORM+"]=-\n");
	cat("/players/chip/venom2/docs/"+str+".sym");
	write("                   ____  "+COLOR+"_"+NORM+"  ____\n");
	return 1;
}
