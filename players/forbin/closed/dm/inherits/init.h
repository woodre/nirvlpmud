void init()
{
  if(!environment()) return;
  if(!this_player()->is_player()) return;

/*
    && (string)this_player()->query_real_name() != "forbin"
    && (string)this_player()->query_real_name() != "vertebraker"
    && (string)this_player()->query_real_name() != "boltar") 
  {
    destruct(this_object());
    return;
  }
*/
  GXPGain = 15;
  Talent = 0;

  Learned = ({ });
  
  /* 
  // takes a total of  anywhere 16,276044 to 32,552,087 exp of killing 
  // eqivalent needed to max glevel in guild  
  // the rate of guildexp gain is dependant on GXPGain, a randomly set
  // stat that ranges from 15-30
  // players start @ level 1 after first task (so 0 & 1 positions in array are zero) 
  */
  GuildLevelCosts = ({ 0, 0, 20000, 50000, 125000, 312500, 781250, 1953125, 4882813 });
  SizeofGLC = sizeof(GuildLevelCosts);
  
  if(!this_player()->query_dm_player_shadow())  /* shadow player */
  {
    dms = clone_object(DIR+"OBJ/dm_player_shadow.c");
    dms->set_dm_player_shadow(this_player());
  }

  if(!restore_gob()) { save_gob(); }
  
  c = sizeof(cmds = files(CMDDIR + "*.c"));  /* add guild commands */
  while(c--) 
  {
    sscanf(cmds[c], "%s.c", cmd);
    add_action("cmd_hook", cmd);
  }
  
  if((int)this_player()->query_level() < 21)
    "/players/forbin/closed/dm/OBJ/advancedaemon.c"->load_it();
  
}
