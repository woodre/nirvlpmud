/* Checks to ensure that member is part of the clan,
   and activates the member if necessary.             */

check_status( string clanname, object member ){
  object *members;
  int i;
  /* check if member is on the inactive roster */
  if(ROSTER->CheckClan(clanname,member->query_name())){
    /* make this member active if he's the first one to log in */
    if(!Clans[clanname]) Clans[clanname] = ({ member });
    else{
      /* get the active members */
      members = Clans[clanname];
      /* make sure the member isn't already active */
      if(member_array(member, members) < 0){
        /* if no empty slots, add member at the end of the array */
        if((i = member_array(0, members)) < 0)
          Clans[clanname] = members + ({ member });
        /* otherwise, fill in the empy slot */
        else{ 
          members[i] = member;
          Clans[clanname] = members;
        }
      }
    }
    return 1;
  }
  /* member is not actually a member! */
  else return 0;
}
