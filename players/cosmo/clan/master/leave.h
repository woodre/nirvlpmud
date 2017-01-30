/*  Allows a Clan member to leave the Clan */
ClanLeave( string clanname, object member ){
  object *members;
  int i;
  if(previous_object()->QClanRank() == 20){
    write("You symbiote forbids it!\n");
    return 1;
  }
  members = Clans[clanname];
  for(i=0;i<sizeof(members);i++){
    tell_object(members[i], CLANCHAN(BOLD+member->query_name()+
    " abandons the Clan"+NORM)+"\n");
  }
  Clans[clanname] -= ({ member });
  ROSTER->UpdateClan(clanname,"rm#"+member->query_name(),
     previous_object()->QClanRank(),previous_object()->QClanTitle());
  destruct(previous_object());
  return 1;
}
