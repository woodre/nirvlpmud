/*  The Clan channel  */
#define HIST "/obj/user/chistory.c"

ClanSpeak( string clanname, string msg, string speaker ){
  object *members;
  int i;
  if (!(members = Clans[clanname])) return 1;
  if(previous_object()->QClanBlock()){
    write("You first must listen in order to be heard.\n");
    return 1;
  }
  i=0;
  if(msg[0]==58)    /* Emote */
     msg = CLANCHAN(speaker+" "+msg[1..strlen(msg)])+"\n";
  else              /* Chat */
     msg = CLANCHAN(speaker+": "+msg)+"\n";
  while(i<sizeof(members)){
    if(members[i])
      if(!(present("clan_object",members[i])->QClanBlock()))
        tell_object(members[i], msg);
    i++;
  }
  HIST->add_history(clanname, msg);
  return 1;
}
