#define PLAYER_FILES "pfiles/"
#define WIZ_FILES "players/"
 
status
wiz_exists(string str)
{
    if(!str || !restore_object(WIZ_FILES + str))
      return 0;
    else return 1;
}

status
player_exists(string str)
{
    if(!str) return 0;
    if(!restore_object(PLAYER_FILES + extract(str, 0, 0) + "/" + str)) return 0;
    else return 1;
}

status
inactive_player(string str)
{
    if(!str) return 0;
    if(!restore_object("/players/inactive_saved/" + str[0..0] + "/" + str))
      return 0;
    else return 1;
}

status
banished_player(string str)
{
    if(!str) return 0;
    if(!restore_object("/banish/" + str[0..0] + "/" + str))
      return 0;
    else return 1;
}
