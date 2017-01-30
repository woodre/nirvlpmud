
int xsta; /*  Additional Stamina Bonus */
set_xsta(int i){ xsta = i; }
add_xsta(int i){ xsta += i; }
query_xsta(){ return xsta; }

static object studied;
set_studied(object ob){ studied = ob; }
query_studied(){ return studied; }

query_knight(){ return knight; }
set_knight(int i){ knight = i; }

static int bcommand_delay;

set_bcommand_delay(int i){ bcommand_delay = i; }
query_bcommand_delay(){ return bcommand_delay; }

/*************************** CMDS FOR KNIGHTS ***************/
xstrike_cmd(str){   
	if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	if(skills[103]){ "/players/data/closed/wizard/power/xstrike.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}

xbash_cmd(str){   
	if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	if(skills[102]){ "/players/data/closed/wizard/power/xbash.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}

bcommand_cmd(str){   
	if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	if(skills[104]){ "/players/data/closed/wizard/power/bcommand.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}


defend_cmd(str){   
	if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	if(skills[100]){ "/players/data/closed/wizard/power/defend.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}

study_cmd(str){   
	if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	if(skills[101]){ "/players/data/closed/wizard/power/study.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}

int templar;
query_templar(){ return templar; }
set_templar(int i){ templar = i; }
