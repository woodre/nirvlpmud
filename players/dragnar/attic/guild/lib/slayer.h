#include "/players/dragnar/guild/defs/def.h"
slayer(str) {
        object slayer;
        int AMT;
            if(!str) {
        write("How strong to you wish your slayer to be?\n");
        return 1; }
	     if(str != "ready" || str != "unready") {
        sscanf(str, "%d", AMT);
        if(usp < AMT) {
        write("You do not have enough spell points to sacrifice.\n");
        return 1; }
        if(present("slayer",this_player())) {
		write("Shardak does not allow you to have more than one Slayer Sword.\n");
        return 1; }
        slayer=clone_object("/players/dragnar/guild/items/slayer.c");
        move_object(slayer, this_player());
        slayer->set_amt(AMT);
	     write("The land parts and a Slayer Sword surges from the ground into your hands.\n");
	     say("The land parts nad a Slayer Sword surges from the ground into "+capname+"'s hands.\n");
        this_player()->add_spell_point(-AMT);
        return 1; }
}
