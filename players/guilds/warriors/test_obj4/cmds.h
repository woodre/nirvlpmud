/*************************** CMDS FOR WARRIOR ***************/
throw_cmd(str){
	if(skills[15]){ "/players/guilds/warriors/power/throw.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}
strike_cmd(str){
	if(skills[16]){ "/players/guilds/warriors/power/strike.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}
punch_cmd(str){
	if(skills[17]){ "/players/guilds/warriors/power/punch.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}
kick_cmd(str){
	if(skills[18]){ "/players/guilds/warriors/power/kick.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}
charge_cmd(str){
	if(skills[19]){
		blocked_wimpy = 2;
		"/players/guilds/warriors/power/charge.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}
bash_cmd(str){
	if(skills[20]){ "/players/guilds/warriors/power/bash.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}
pummel_cmd(str){
	if(skills[40]){ "/players/guilds/warriors/power/pummel.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}
finish_cmd(str){
	if(skills[41]){ "/players/guilds/warriors/power/finish.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}
firstaid_cmd(str){
/* Added following checks for so 'firstaid' and 'first aid' both work like
 * they should - Dec-01-2009 - Rumplemintz
 */
    if (!str && query_verb() == "first") return;
    if (str && str != "aid") return;
    if (skills[50])
    {
        "/players/guilds/warriors/power/firstaid.c"->main(str, TO, USER);
        return 1;
    }
    else
        return;
}
run_cmd(str){
	if(skills[60]){
		"/players/guilds/warriors/power/run.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}
