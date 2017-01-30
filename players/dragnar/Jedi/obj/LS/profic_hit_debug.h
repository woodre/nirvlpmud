proficiency_hit(ob){
  int temp;  /* so we can reset modifier when done */
  int i;
  int j;   /* counting vars */

  if(!JEDI || !SKILL) return 0;

  tell_object(USER, "modtype: "+modtype+".\n");
  if(ignited) {
    if(ComboAtt && ComboAtt != ATT) ResetCombo();
    if(modifier) {
      tell_object(USER, "modifier: "+modifier+".\n");
    if(combo && sizeof(combo) > 0) {
      for(i=0, combo_no=0; i < MAX; i++) tell_object(USER, combo[i]+", ");
      tell_object(USER, "combo_no: "+combo_no+".\n");
    }
      temp = modifier;
      modifier = 0;
      if(ATT) ComboAtt = ATT;
      if(temp > 0) AddGxp(temp);
      return temp;
    }
    modtype = 0; /* Reset modtype since no attack was done */
		    
    if(combo) { 
    /* No attack was done, so go to the oldest attack and null it out */
	  if(combo_status == 1) {
        i = combo_index;
  	    j = 1;
        while(j < 11 && combo[i] == "null") {
          if(i == 9) i = 0;
          else i++;
          j++;
        }
  	  tell_object(USER, "\t\tJ: "+j+"\n");
  	  if(j > 10) combo_status = 0;
        else combo[i] = "null";
        for(i=0, combo_no=0; i < MAX; i++) tell_object(USER, combo[i]+", ");
	  }
    }
/*
    else ResetCombo();
    else combo = 0;
    if(combo && sizeof(combo) > 0)
      tell_object(USER, "combo: "+combo[combo_index]+" combo_no: "+combo_no+".\n");
       return 0;
*/
  } 
  return 0;
}

ResetCombo() {
  tell_object(USER, "\tATTACKER CHANGED!!\n");
  combo = ({ "null","null","null","null","null","null","null","null","null","null", });
  combo_no = 0;
  combo_index = 0;
}

AddGxp(int amt) {
  if(ATT) USER->add_guild_exp(amt/10*ATT->query_level());
  return;
}
