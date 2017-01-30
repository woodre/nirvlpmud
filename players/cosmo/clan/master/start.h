/* Start a new Clan - called from the Symbiote gob */
ClanStart( string clanname ){
  object new_object;
  object *members;
  int i;
  if(present("clan_object",this_player())){
    write("You already have a clan.\n");
    return 1;
  }
  if(ROSTER->CheckClans(clanname)){
    ROSTER->RestoreClan(clanname);
    ClanName = clanname;
    if(Clans == 0){ Clans = ([ ]); }
    Clans[clanname] = ({ this_player() });
    new_object = clone_object(CLANOB);
    new_object->SClanName(clanname);
    new_object->SClanRank(6);
    new_object->SClanTitle(0);
    ROSTER->UpdateClan(clanname,this_player()->query_name(),6,0);
    move_object(new_object,this_player());
    write(CLANCHAN(clanname+" Clan is now active")+"\n");
    return 1;
  }
  else{ write("That name is not available.\n"); return 1; }
}
