#include "../DEFS"

int cmd(string str){
    if(!present("necro_ob", this_player()))
	return 0;
    CHAT_D->guildwho();
    return 1;
}
