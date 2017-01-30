#define ROSTER "/players/cosmo/clan/clanroster.c"

/*  Add a Clan member */
ClanAdd( string clanname, string member_name ){
  object new_object;
  object *members;
  object member;
  int i;
  member = present(member_name, environment(this_player()));
  if(!member){
    write(capitalize(member_name)+" is not here.\n");
    return 1;
  }
  if(member->query_level() > 19){
    write("Wizards cannot be added to clans.\n");
    return 1;
  }
  if(member->query_level() < 10){
    write("Clan members must be at least level 10.\n");
    return 1;
  }
  if(!member->is_player()){
    write(capitalize(member_name)+" can not be added to clans.\n");
    return 1;
  }
  if(present("clan_object",member)){
    write(capitalize(member_name)+" is already a clan member.\n");
    return 1;
  }
  if(present("venom_object",member)){
    write("Your symbiote would become insanely jealous.\n");
    return 1;
  }
  /* avoid duplicates and use empty slots */
  members = Clans[clanname];
  if(sizeof(members) > 11){
    write("This clan cannot have any additional members.\n");
    return 1;
  }
  if(member_array(member, members) < 0) {
    i = ROSTER->UpdateClan(clanname,capitalize(member_name),1,0);
    if(i == -1){
      write(capitalize(member_name)+" has been banned from this clan.\n");
      return 1;
    }
    if(i == 0){
      write("You must promote one of your Seaman before adding another.\n");
      return 1;
    }
    i = member_array(0, members);
    if(i < 0) Clans[clanname] = members + ({ member });
    else{ members[i] = member; Clans[clanname] = members; }
    members = Clans[clanname];
    for(i=0;i<sizeof(members);i++)
      tell_object(members[i], CLANCHAN(BOLD+capitalize(member_name)+
        " has joined the ranks of the "+clanname+" Clan"+NORM)+"\n");
    new_object = clone_object(CLANOB);
    new_object->SClanName(clanname);
    new_object->SClanRank(1);
    new_object->SClanTitle(0);
    move_object(new_object,member);
    return 1;
  }
  write(capitalize(member_name)+" is in your clan already.\n");
  return 1;
}