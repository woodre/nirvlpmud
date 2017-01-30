#define ROSTER "/players/cosmo/clan/clanroster.c"

/* Change a member's rank */
static object *peeps;
static object peep;

ClanModRank( string clanname, string member_name, int rank ){
  int level;
  peep = find_player(member_name);
  if(!peep){
    write(capitalize(member_name)+" is not around anywhere.\n");
    return 1;
  }
  peeps = Clans[clanname];
  if(member_array(peep,peeps) < 0){
    write("That person is not a member of your clan.\n");
    return 1;
  }
  if(peep == this_player()){
    write("You cannot change your own rank.\n");
    return 1;
  }
  level = peep->query_level();
  if(peep->query_level() > 19){
    write("You can't change the rank of a wizard.\n");
    return 1;
  }
  if(rank > 5){
    write("You can't give "+capitalize(member_name)+
          " a rank higher than 5.\n");
    return 1;
  }
  if(rank < 1){
    write("You can't give anyone a rank of less than 1.\n");
    return 1;
  }
  if(rank !=2){
    if(ROSTER->UpdateClan(clanname,peep->query_name(),rank,0))
      change_rank(rank,0);
    else write("That rank is already occupied.\n");
  }
  else{
    write("What will be the responsibility of this Petty Officer?\n"+
          "1: Master-at-Arms\n"+
          "2: Boatswain's Mate\n"+
          "3: Gunner's Mate\n"+
          "4: Damage Controlman\n"+
          "5: Quartermaster\n"+
          "6: Sonar Technician\n"+
          "7: Intelligence Specialist\n");
    write("Select the appropriate number: ");
    input_to("set_title");
  }
  return 1;
}

set_title(str){
  int title;
  if(!str || str == ""){
    write("\nPlease make a selection: ");
    input_to("set_title");
    return;
  }
  if(!sscanf(str,"%d",title)){
    write("\nInvalid selection.");
    write("\nPlease make a selection: ");
    input_to("set_title");
    return;
  }
  if(title > 7 || title < 1){
    write("\nInvalid selection.");
    write("\nPlease make a selection: ");
    input_to("set_title");
    return;
  }
  if(ROSTER->UpdateClan(present("clan_object",peep)->QClanName(),
     peep->query_name(),2,title))  change_rank(2,title);
  else write("That position is already occupied.\n");
  return 1;
}

change_rank( int new_rank, int new_title ){
  int i;
  object clanob;
  clanob = present("clan_object",peep);
  clanob->SClanRank(new_rank);
  for(i=0;i<sizeof(peeps);i++)
    tell_object(peeps[i],CLANCHAN(BOLD+peep->query_name()+
                " is now "+clanob->QClanRankN()+NORM)+"\n");
  if(new_title > 0){
    clanob->SClanTitle(new_title);
    for(i=0;i<sizeof(peeps);i++)
      tell_object(peeps[i],CLANCHAN(BOLD+peep->query_name()+" has assumed "+
                  "the position of "+clanob->QClanTitleN()+NORM)+"\n");
  }
  return 1;
}
