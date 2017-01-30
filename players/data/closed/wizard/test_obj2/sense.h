sense(){
	int i;
	string *dirs;
	
	dirs = environment(USER)->query_dest_dir();
	
	if(skills[70] < 1) return 0;
	if(USER->test_dark()){
		write("You sense that the available exits are: \n\t\t");
		i = 1;
		while(i <= sizeof(dirs)) {
			write(" ["+HIR+dirs[i]+NORM+"]");
			i += 2;
		}
		write("\n\n");
		return 1;
	}
	write("It isn't dark, you have no need to 'sense'.\n");
	return 1;
}
