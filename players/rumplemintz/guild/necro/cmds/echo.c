#include "../DEFS"

int cmd(string str){
    object ob;
    if(!present("necro_ob", this_player())->checklev(3,7))
	return 1;  
    if(!str){
	write("What would you like to echo?\n");
	return 1;
    }
    say(str+" "+BOLD+BLK+"<"+this_player()->query_name()+">\n"+OFF);
    write("You echo:\n "+str+" "+BOLD+BLK+"<"+this_player()->query_name()+">\n"+OFF);
    return 1;
}
