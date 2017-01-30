query_weight(){ if(offhand_wght) return offhand_wght; else return 0; }
query_value(){ return 0; }
drop(){ return 1; }
get(){ return 1; }
no_spell(){ return 0; }

new_quit(){
	if(offhand) command("offhand", USER);
	save_prof();
	return;
}

/*
query_auto_load(){
	save_object(SAVE_PATH+USERRN);
	return PATH+"gobj.c:";
}
*/
