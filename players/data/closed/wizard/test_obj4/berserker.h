static int rage;
set_rage(int i){ rage = i; }
add_rage(int i){ rage += i; }
query_rage(){ return rage; }

static int zerk;

set_berserker(int i){ berserker = i; }
query_berserker(){ return berserker; }

int xstr; /*  Additional Strength Bonus */
set_xstr(int i){ xstr = i; }
add_xstr(int i){ xstr += i; }
query_xstr(){ return xstr; }

rage_cmd(str){   
	if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	if(skills[120]){ "/players/data/closed/wizard/power/rage.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}
xcharge_cmd(str){
   if(set_light(0) <= 0 && !skills[70]){ write("It is too dark.\n"); return 1; }
	if(skills[123]){ "/players/data/closed/wizard/power/xcharge.c"->main(str, TO, USER);
		return 1;
	}
	else return;
}  

