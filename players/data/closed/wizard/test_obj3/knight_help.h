knight_info(str){
   string named,named2;
	int i;

  if(this_player()->query_ghost()) return;
  if(!str){
		write("                      "+HIW+"{ Knight }"+NORM+"\n");
		cat("/players/maledicta/closed/w/doc/knight/main.knight");
		write("                      "+HIW+"   -+-    "+NORM+"\n");
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
	if(file_size("/players/maledicta/closed/w/doc/knight/"+str+".knight") == -1){
		write("Subject not found.\n");
		return 1;
	}
	write("                "+HIW+"{ Knight "+capitalize(str)+" }"+NORM+"\n");
	cat("/players/maledicta/closed/w/doc/knight/"+str+".knight");
	write("                      "+HIW+" -+-    "+NORM+"\n");
	return 1;
}
