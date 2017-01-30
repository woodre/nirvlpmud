
string whoname;
int level;

id(str){ return str == "scalp" || str == "deathscalp"; }

short(){ return "scalp of: "+capitalize(whoname); }

extra_look(){
   return capitalize(whoname)+
   " has been marked for death";
}

long(){
   write("You have been marked for death by the Assassins Guild.\n");
   write("Someone will be coming soon to relieve you of your scalp.\n");
   write("Thank you for supporting our business.\n");
}

set_who(str){
  whoname = str;
  level = find_player(str)->query_level();
}

query_auto_load(){ return "players/deathmonger/ASSASSIN/scalp:"+
  whoname+"#"+level; }

init_arg(arg){
   sscanf(arg, "%s#%d", whoname, level);
   write("You have been marked for death.\n");
}

get(){
   if(this_player()->query_real_name() != whoname){
      write("Looks like you can collect a bounty.\n");
      return 1;
   }
   else return 0;
}

drop(){
   /* living.c calls this when our owner dies, and we have to go
	  through these contortions because of it. */
   object owner, corpse;
   owner = environment(this_object());
   if(owner){
     corpse = present("corpse", environment(owner));
	 if(corpse){
       if(owner->short() == "ghost of "+capitalize(whoname) &&
          corpse->short() == "corpse of "+capitalize(whoname)){
			return 0;
		  }
	  }
   }
   return 1;
}
