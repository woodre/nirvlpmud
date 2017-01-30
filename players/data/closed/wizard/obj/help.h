doc_help(str){
	string named,named2;
	int i;
	if(!str){
		write("                      "+HIR+"{ Warrior }"+NORM+"\n");
		cat(DOC_DIR+"main.warrior");
		write("                      "+HIR+"    -+-    "+NORM+"\n");
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
	if(file_size(DOC_DIR+str+".warrior") == -1){
		write("Subject not found.\n");
		return 1;
	}
	write("                "+HIR+"{ Warrior "+capitalize(str)+" }"+NORM+"\n");
	cat(DOC_DIR+str+".warrior");
	write("                      "+HIR+"    -+-    "+NORM+"\n");
	return 1;
}
