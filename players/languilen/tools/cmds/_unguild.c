cmd_unguild(str){
      if(!str){
         write("Usage: unguild <player>.\n");
         return 1;
      }
      if(!find_player(str)){
         write("That player is not online.\n");
      return 1;
      }
      find_player(str)->set_guild_name(0);
      find_player(str)->add_exp(this_object()->query_guild_exp());
      find_player(str)->add_guild_exp(-this_object()->query_guild_exp());
      find_player(str)->add_guild_rank(-this_object()->query_guild_rank());
      write("Done.\n");
      return 1;
}


