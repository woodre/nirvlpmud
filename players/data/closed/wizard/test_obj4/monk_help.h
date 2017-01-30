monk_info(str){
   string named,named2;
	int i;

  if(this_player()->query_ghost()) return;
  if(!str){
		write("                      "+HIM+"{ Monk }"+NORM+"\n");
		cat("/players/data/closed/wizard/doc/monk/main.monk");
		write("                      "+HIM+"   -+-    "+NORM+"\n");
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
	if(file_size("/players/data/closed/wizard/doc/monk/"+str+".monk") == -1){
		write("Subject not found.\n");
		return 1;
	}
	write("                "+HIM+"{ Monk "+capitalize(str)+" }"+NORM+"\n");
	cat("/players/data/closed/wizard/doc/monk/"+str+".monk");
	write("                      "+HIM+" -+-    "+NORM+"\n");
	return 1;
}
