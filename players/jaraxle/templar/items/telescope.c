#define tp this_player()->query_name()
#define TP this_player()
inherit "/obj/treasure";
int lastime, WAIT;
int time;
reset(arg)  {
	WAIT == 0;
	if(arg) return;
}
id(str)  { return str == "telescope" || str == "j_scope";  }

short()  { return "A large telescope"; }

long()  {  write(
		"This is a large telescope for finding people on Nirvana.\n"+
		"You can find just about anyone by typing 'find <player>'.\n"+
"\n");  }

get()  { return 0; }

init()  {
	add_action("search_player","find");
}

search_player(str)  {
	string whoisdawiz;
	object ob;
	
	if(WAIT ==1){ write("You must wait a moment before using the telescope again.\n"); return 1; }
	
	if(!str)  {
		write("Who do you wish to find through the telescope?\n");
		return 1;
	}
	
	if(time >= time()){
         write("You must wait before using the telescope again.\n");
		return 1;
	}
	write("You peek into the telescope and begin to aim it around Nirvana...\n\n");
	say(tp+" looks through the telescope, searching over Nirvana.\n");
	
	ob = find_living(str);
	if(!ob){
          write(capitalize(str)+" is not visible through the telescope.\n");
		return 1;
	}
	if(ob->query_level() > 19){
          write(capitalize(str)+" is not visible through the telescope.\n");
		return 1;
	}
	if(environment(ob) == environment()){
          write(capitalize(str)+" is not visible through the telescope.\n");
		return 1;
	}
	if(ob->query_invis()) {
          write(capitalize(str)+" is not visible through the telescope.\n");
		return 1;
	}
	if(!environment(ob)){
          write(capitalize(str)+" is not visible through the telescope.\n");
		return 1;
	}
   if(!creator(environment(ob))){
	write(capitalize(str)+" can be found in "+call_other(environment(ob),"short")+".\n");
	write("That seems to be no one's area.\n");
   }
   else{
	write(capitalize(str)+" can be found in "+call_other(environment(ob),"short")+".\n");
	write("That seems to be "+capitalize(creator(environment(ob)))+"'s area.\n");
   }
	time = time() + 20;
	return 1;
}
