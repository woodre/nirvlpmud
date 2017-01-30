assassin_info(str){
   string named,named2;
	int i;

  if(this_player()->query_ghost()) return;
  if(!str){
		write("                    "+HIR+"{ Assassin }"+NORM+"\n");
		cat("/players/data/closed/wizard/doc/assassin/main.assassin");
		write("                      "+HIR+"   -+-    "+NORM+"\n");
		return 1;
	}
	named = lower_case(str);
	named2 = strlen(named);
	i=0;
	while(i < named2) {
		if (str[i] < 'a' || str[i] > 'z'){
			if(str[i] != "_"){
				write("Subject not found.\n");
				return 1;
			}
		}
		i += 1;
	}
	if(file_size("/players/data/closed/wizard/doc/assassin/"+str+".assassin") == -1){
		write("Subject not found.\n");
		return 1;
	}
	write("              "+HIR+"{ Assassin "+capitalize(str)+" }"+NORM+"\n");
	cat("/players/data/closed/wizard/doc/assassin/"+str+".assassin");
	write("                      "+HIR+" -+-    "+NORM+"\n");
	return 1;
}
