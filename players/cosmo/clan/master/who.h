#define ROSTER "/players/cosmo/clan/clanroster.c"

/*  See who is in your Clan */
ClanWho( string clanname ){
  object *members;
  if(!Clans){ 
    write("No Clans are currently active.\n");
    return 1;
  }
  members = Clans[clanname];
  ROSTER->ViewClan(clanname, members);
  return 1;
}
