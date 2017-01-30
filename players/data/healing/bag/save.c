
save_bag(){
	tell_object(USERN, "Saving...\n");
	save_object(SAVE_PATH+USERN);
	tell_object(USERN, "done.\n");
	return 1;
}

silent_save(){
	save_object(SAVE_PATH+USERN);
	return 1;
}

restore_bag(){
	write("Restoring...\n");
	restore_object(SAVE_PATH+USERN);
	return 1;
}
