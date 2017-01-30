#define SAVE_PATH "players/data/healing/pfile/"
save_bag(){
	tell_object(USER, "Saving...\n");
	save_object(SAVE_PATH+USERRN);
	tell_object(USER, "done.\n");
	return 1;
}

silent_save(){
	save_object(SAVE_PATH+USERRN);
	return 1;
}

restore_bag(){
	write("Restoring...\n");
	restore_object(SAVE_PATH+USERRN);
	return 1;
}