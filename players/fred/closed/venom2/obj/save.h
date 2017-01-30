/*************************************************************
**       Save, restore, etc.                                **
*************************************************************/
query_auto_load(){
	save_object(SAVE_PATH+NAME);
return "/players/maledicta/venom2/neo_venom.c:"; }

save_venom2(){
	tell_object(USER,	""+query_color()+"Saving Symbiotic Connection...."+NORM+"\n");
	save_object(SAVE_PATH+NAME);
	tell_object(USER,
	""+query_color()+"done."+NORM+"\n");
	return 1;
}

save_venom(int i){
	if(!i)	tell_object(USER,	""+query_color()+"Saving Symbiotic Connection...."+NORM+"\n");
	save_object(SAVE_PATH+NAME);
	if(!i)
	tell_object(USER,
	""+query_color()+"done."+NORM+"\n");
	return 1;
}
restore_venom(){
	write("Restoring Symbiotic Slave...\n");
	restore_object(SAVE_PATH+NAME);
	write("Done.\n");
	return 1;
}

