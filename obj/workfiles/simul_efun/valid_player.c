#define VALID_PLAYER_D    "/obj/user/valid_player.c"

status valid_active_player(string nm)
{
  return (int)VALID_PLAYER_D->dvalid_active_player(nm);  
}

status valid_wizard(string nm)
{
  return (int)VALID_PLAYER_D->dvalid_wizard(nm);
}

status valid_banished_player(string nm)
{
  return (int)VALID_PLAYER_D->dvalid_banished_player(nm);
}

status valid_inactive_player(string nm)
{
  return (int)VALID_PLAYER_D->dvalid_inactive_player(nm);
}

int valid_player(string nm)
{
  return (int)VALID_PLAYER_D->dvalid_player(nm);
}       
