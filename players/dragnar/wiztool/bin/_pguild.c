string guild_file, guild_name, home;
int guild_rank, guild_exp;

cmd_pguild( string str ) {
  mixed *guild_stats;
  string who, target;
  object fool;
  int x;

  if(!str || sscanf(str, "%s %s", who, target) != 2) {
    write("Usage: 'pguild <name> <target>'\n");
    return 1;
  }
  
  if(!(fool = find_player(who))) {
    write(capitalize(who)+" is not logged in.\n");
    return 1;
  }

  target = lower_case(target);

  if (!restore_object( "pfiles/" + target[0..0] + "/" + target )) {
    write("Unable to restore "+target+".\n");
    return 1;
  }

  if( !guild_file || !guild_name ) {
    write(capitalize(target)+" is not in a guild.\n");
    return 1;
  }
  guild_stats = ({ guild_file, guild_rank, guild_exp, home });
  
  fool->add_prestige_guild( guild_name, guild_stats );
  write("Added "+guild_name+" infor to : "+who+".\n");
  x = sizeof(guild_stats);
  while( x-- )
    write("\t"+guild_stats[x]+"\n");


  /* Reset **/
  guild_file = guild_name = home = 0;
  guild_rank = guild_exp = 0;
  return 1;
}
