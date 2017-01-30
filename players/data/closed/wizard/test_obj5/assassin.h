/* Main File for all Assassin Variables, Settings
and Actions.  This file is included by the
main GOB. 
*/
int xste;
add_xste(int i){ xste += i; }

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
	if(skills[116]){ "/players/data/closed/wizard/power/xthrow.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}

riposte_cmd(str){
	if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	if(skills[114]){ "/players/data/closed/wizard/power/riposte.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}


hide_cmd(str){
	if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	if(skills[113]){ "/players/data/closed/wizard/power/hide.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}

backstab_cmd(str){
	if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	if(skills[112]){ "/players/data/closed/wizard/power/backstab.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}