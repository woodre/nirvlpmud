/*************************** CMDS FOR WARRIOR ***************/
throw_cmd(str){
	if(skills[15]){ "/players/maledicta/closed/w/power/throw.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}
strike_cmd(str){
	if(skills[16]){ "/players/maledicta/closed/w/power/strike.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}
punch_cmd(str){
	if(skills[17]){ "/players/maledicta/closed/w/power/punch.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}
kick_cmd(str){
	if(skills[18]){ "/players/maledicta/closed/w/power/kick.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}
charge_cmd(str){
	if(skills[19]){
		blocked_wimpy = 2;
		"/players/maledicta/closed/w/power/charge.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}
bash_cmd(str){
	if(skills[20]){ "/players/maledicta/closed/w/power/bash.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}
pummel_cmd(str){
	if(skills[40]){ "/players/maledicta/closed/w/power/pummel.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}
finish_cmd(str){
	if(skills[41]){ "/players/maledicta/closed/w/power/finish.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}
firstaid_cmd(str){
	if(skills[50]){ "/players/maledicta/closed/w/power/firstaid.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}
run_cmd(str){
	if(skills[60]){
		"/players/maledicta/closed/w/power/run.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}
