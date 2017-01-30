practice_arts(str){
   string who;
   string what;
   string msg;
   string name;
   name = capitalize(this_player()->query_real_name());
   if(sscanf(str,"%s on %s",what,who) !=2){
      return 0;
   }
   if(!COMM->CheckOffense(what) && !COMM->CheckDefense(what)){
      write("You don't know that move.\n");
      return 1;
   }
   if(!present(who, environment(this_player()))){
      write(capitalize(who)+" is not here.\n");
      return 1;
   }
   if(!living(present(who, environment(this_player())))){
      write("You get better by practicing with things that are alive!\n");
      return 1;
   }
   if(present(who, environment(this_player())) == this_player()){
      write("You can't practice the martial arts on yourself!\n");
      return 1;
   }
   if(COMM->CheckOffense(what)){
      msg = show_offense(what,name,who,"");
      COMM->AMartialExp(2);
      tell_room(environment(this_player()),msg+"\n");
      return 1;
   }
   if(COMM->CheckDefense(what)){
      msg = show_defense(what,name,who,"");
      COMM->AMartialExp(2);
      tell_room(environment(this_player()),msg+"\n");
      return 1;
   }
   return 1;
}
