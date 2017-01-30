void
init()
{
    int i;

    if(environment() && environment()->is_player()
       && ((string)environment()->query_guild_name() == GUILDNAME
       || (int)environment()->query_level() > 21))
    {
      restore_it();
      add_cmd_dir();
    }
}

