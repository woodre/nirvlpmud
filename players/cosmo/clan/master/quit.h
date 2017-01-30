/*  Removes the Clan member from the active mapping */
ClanQuit( string clanname, object member ){
  Clans[clanname] -= ({ member });
}
