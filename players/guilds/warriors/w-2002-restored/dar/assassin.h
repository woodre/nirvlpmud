/* Main File for all Assassin Variables, Settings
and Actions.  This file is included by the
main GOB. 
*/

static int backstab;  /* Bonus wc for backstab */

set_backstab(int i){ backstab = i; }
query_backstab(){ return backstab; }

int riposte;  /* Toggle for Riposte */

set_riposte(int i){ riposte = i; }
query_riposte(){ return riposte; }

query_assassin(){ return assassin; }
set_assassin(int i){ assassin = i; }


xthrow_cmd(str){
	if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	if(skills[116]){ "/players/daranath/closed/w/power/xthrow.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}

riposte_cmd(str){
	if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	if(skills[114]){ "/players/daranath/closed/w/power/riposte.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}

move_cmd(str){
	if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	if(skills[115]){ "/players/daranath/closed/w/power/move_silent.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}

hide_cmd(str){
	if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	if(skills[113]){ "/players/daranath/closed/w/power/hide.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}

backstab_cmd(str){
	if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	if(skills[112]){ "/players/daranath/closed/w/power/backstab.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}