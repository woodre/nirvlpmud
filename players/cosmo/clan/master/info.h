/* Clan help file */
ClanInfo(){
  write(BOLD+"\t\tWelcome to the "+ClanName+" Clan"+NORM+"\n"+
    "< As a member you may do any of the following:                >\n"+
    "<                                                             >\n"+
    "< clan info...............This screen.                        >\n"+
    "< clan who................A listing of Clan members.          >\n"+
    "< clan <msg>..............Talk or emote on your Clan channel. >\n"+
    "< clan muffle.............Muffle your Clan channel.           >\n"+
    "< clan listen.............Unmuffle your Clan channel.         >\n"+
    "< clan history............A brief history of channel usage.   >\n"+
    "< clan leave..............Leave the Clan forever.             >\n"+
    "<                                                             >\n");
  if(previous_object()->QClanRank() > 5){
    write(
    "< As the Clan leader you may also do the following:           >\n"+
    "<                                                             >\n"+
    "< clan add <name>...........Add someone to your Clan.         >\n"+
    "< clan remove <name>........Remove someone from your Clan.    >\n"+
    "< clan setrank <name> <#>...Change a member's rank.           >\n"+
    "\n");
  }
  return 1;
}
