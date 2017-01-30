#include "/players/guilds/bards/bard_lib/include/ansi.h"
bard_lore(str){
	string named,named2;
	int i;
	
	if(this_player()->query_ghost()) return;
	if(!str){
		write("                     "+HIW+"[ Bardic Lore ]"+NORM+"\n");
		cat("/players/guilds/bards/doc/main.bard");
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
    
		if(file_size("/players/guilds/bards/doc/"+str+".bard") == -1){
			write("Subject not found.\n");
			return 1;
		}
                write("        "+HIW+"    [ Bardic Lore: "+capitalize(str)+
                " ]"+NORM+"\n");
		cat("/players/guilds/bards/doc/"+str+".bard");
		write("                      "+HIW+"   -+-    "+NORM+"\n");
		
		
		return 1;
	}
