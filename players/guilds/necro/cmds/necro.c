#include "../DEFS"

int cmd(string str){
    if(!str){
	notify_fail("What would you like to say on the guild line?\n");
	return 0;
    }
    if(str == "history"){
	CHAT_D->viewhistory();
	return 1;
    }
    if(str == "who"){
	CHAT_D->guildwho();
	return 1;
    }
    if(str == "list"){
	CHAT_D->on_channel();
	return 1;
    }
    if(present("necro_ob", this_player())->query_muffled()){
	write("You can not used the guild line while muffled.\n");
	return 1;
    }
    switch(str[0]){
    case ':':
	CHAT_D->create_emote(this_player(),str);
	break;
    case '>':
	CHAT_D->create_echo(this_player(),str);
	break;
    case '^':
	CHAT_D->create_think(this_player(),str);
	break;
    default:
	CHAT_D->create_say(this_player(),str);
	break;
    }
    return 1;
}
