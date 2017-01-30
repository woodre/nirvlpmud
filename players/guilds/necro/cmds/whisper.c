int cmd(string str){
    string who, msg;
    if(!str || sscanf(str,"%s %s",who,msg) != 2){
	write("What would you like to whisper?\n");
	return 1;
    }
    if(!find_player(who) ||
      !present(who, environment(this_player())) ||
      find_player(who)->query_invis() > this_player()->query_level()){
	write("That player is not here to whisper to.\n");
	return 1;
    }
    tell_object(find_player(who), this_player()->query_name()+" whispers to you, \""+msg+"\"\n");
    write("You whisper, \""+msg+"\", to "+find_player(who)->query_name()+".\n");
    say(this_player()->query_name()+" whispers something to "+find_player(who)->query_name()+".\n", find_player(who));
    return 1;
}
