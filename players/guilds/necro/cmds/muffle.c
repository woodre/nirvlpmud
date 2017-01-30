#include "../DEFS"

int cmd(string str){
    if(str == "necro"){
	write("You muffle the necromancer guild line.\n");
	present("necro_ob", this_player())->set_muffle(1);
	CHAT_D->resetchannel();
	return 1;
    }
    notify_fail("What would you like to muffle?\n");
    return 0;
}
