


id(str){ return str == "reservation"; }

long(){
      write("Reserver.\n");
	  }


init(){
   add_action("reserve", "reserve");
}

reserve(str){
   object what, ob;
   if(!str){ write("Reserve what?\n"); return 1; }
   what = present(str, environment(this_player()));
   if(!what){ write("No "+str+" here.\n"); return 1; }
   ob = clone_object("players/deathmonger/monstop");
   ob->block_attacks(what, this_player()->query_name());
   write("Monster reserved.\n");
   return 1;
}

