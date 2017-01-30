#include "/players/dragnar/guild/defs/def.h"
title(str) {
        string plus;
        if(!str) {
        write("What do you want to set your to?\n");
        return 1; }
	     if(RANK < 4) { plus = "(Shardak Initiate: "+LEV+")"; }
        if(RANK >4 && RANK < 7) { plus = "(Shardak Player: "+LEV+")"; }
        if(RANK > 7) { plus = "(Shardak Assassin: "+LEV+")"; }
		this_player()->set_title(str + " "+plus+"");
        write("Your title for the Shardak guild has been changed.\n");
        return 1;
}
