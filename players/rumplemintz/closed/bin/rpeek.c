int rpeek(string str){
    string *directions;
    int i;
    object ob, envob;
    if(!str || !find_player(str))
      envob = environment(this_player());
    else {
      ob = find_player(str);
      if(!ob || !environment(ob)) {
	notify_fail("Cannot find "+ob+" currently.\n");
	return 0;
      }
      envob = environment(ob);
    }
    directions = (string *)envob->query_dest_dir();
    i = 0;
    if(!directions){
	notify_fail("There are no exits.\n");
	return 0;
    }
    if(sizeof(directions)){
	write("The exit(s):\n");
	while(i<sizeof(directions)){
	    write("Path = "+directions[i]);
	    i += 1;
	    write("\tDirection = "+directions[i]+"\n");
	    i += 1;
	}
    }
    write("\n");
    return 1;
}
