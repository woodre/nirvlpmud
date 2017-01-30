int main(string str)
{
  if((int)this_player()->query_guild_rank() < 5)
    return 0;
  
  if(!str) {
    write("Name your dragon what?\n");
    return 1;
  }
  
  else {
    object mark;
    
    if(!(mark = present("shardak_mark", this_player()))) {
      write("Bug.\n");
      return 1;
    }
    
    if(mark->Dragon()) {
      write("You cannot change the name of your dragon.\n"+
            "You must release it first.\n");
      return 1;
    }
    
    write("Changing DragonName to \""+str+"\"...\n");
    mark->DragonName(str);
    command("gsave", this_player());
    write("Done.\n");
    return 1;
  }
} 