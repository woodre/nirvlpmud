/*
 *  A new gossip for the Bardic Guild or Ryllian.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */


farsong(string str, int i_emote)  {

object PERSON, MEMBER, *USERS;
int X,Y;
string MESSAGE, TEMP;

  if(spell(-50,4,1) == -1) return 0;
  
  if(!TP->on_channel("gossip"))  {
    write("You are not on the gossip channel, so you may not sing.\n");
    return 1;
       }
  
  if(!str)  {
    write("What would you like to sing to the realms of magic?\n"+
          "Syntax: < farsong > < message >\n");
    return 1;
       }
  
  TEMP = "(Songs) "+tp;
  if(!i_emote) TEMP = "(Songs) "+tp+" sings:";
  TEMP = TEMP+" "+str;
  
  USERS = users();
  
  for(X = 0; X < sizeof(USERS); ++X)  {
    PERSON = USERS[X];
      if(PERSON->on_channel("gossip"))  {
        tell_object(PERSON, format(TEMP));
    ++X;
       }
       }

  call_other(TP, "add_spell_point", -1);
  return 1;
       }
