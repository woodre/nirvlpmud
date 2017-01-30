inherit "obj/armor";


reset(arg){
  ::reset(arg);
  }


init(){
  ::init();
  add_action("fratell";"fratell");
  }

fratell(str) {
  object player;
  string what;
   if(!str) {write("Tell Francesco what?\n"); return 1;}
      player = find_player("francesco");
       	if(!player) {"Francesco is not online now.\n"); return 1; }
	  tell_object(player, this_player()->query_name()+" politely speaks: "+what+" \n");
          write("You tell Francesco: "+what+"\n");
return 1; }
