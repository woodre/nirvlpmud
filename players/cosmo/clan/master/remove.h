/*  Allows Clan leader to remove a member  */
ClanRemove( string clanname, string member_name ){
  object *members;
  object member;
  object clanob;
  int i;
  member = find_living(member_name);
  if(!member){
     write(capitalize(member_name)+" can't be found anywhere.\n");
     return 1;
  }
  if(member == this_player()){
     write("Your symbiote won't allow it.\n");
     return 1;
  }
  if(members = Clans[clanname]){
    if(member_array(member,members) < 0){
       write(capitalize(member_name)+" is not a member of your clan.\n");
       return 1;
    }
    Clans[clanname] -= ({ member });
    clanob = present("clan_object",member);
    ROSTER->UpdateClan(clanname,"rm#"+capitalize(member_name),
            clanob->QClanRank(),clanob->QClanTitle());
    for(i=0;i<sizeof(members);i++)
       tell_object(members[i], CLANCHAN(BOLD+capitalize(member_name)+
                   " has been removed from the Clan"+NORM)+"\n");
    destruct(clanob);
    return 1;
  }
  return 1;
}
