/*
  /players/stark/rakh/cmd/talk.h
  The channel features of the rakh guild obj.
*/
rakh_talk(str){
  int i;
  object stuff;
  string who, player_list;
if(!str) {
  write("Hmm?\n");
  return 1; }
if(life3_lvl<1){ write("You are not old enough to speak.\n"); return 1; }
player_list = users();
for(i = 0; i < sizeof(player_list); i++) {
  stuff = present("rakh_guild", player_list[i]);
    if (stuff && player_list[i]->query_level() <= 200) {
      if (TP->query_invis() > 0){
          tell_object(player_list[i],HIG+"~?~ "+NORM+str+"\n");
	  write_file("/players/stark/rakh/log/chat",HIG+"~?~ "+NORM+str+"\n");
        return 1;}
          tell_object(player_list[i],HIG+"~"+capitalize(TPRN)+"~ "+NORM+str+"\n");
	  write_file("/players/stark/rakh/log/chat",HIG+"~"+capitalize(TPRN)	+"~ "+NORM+str+"\n");
     }
}
return 1;
}

rakh_talk_emote(str){
  int i;
  object stuff;
  string who, player_list;
if(!str) {
  write("Hmm?\n");
  return 1; }
player_list = users();
for(i = 0; i < sizeof(player_list); i++) {
  stuff = present("rakh_guild", player_list[i]);
    if (stuff && player_list[i]->query_level() <= 200) {
      if (TP->query_invis() > 0){
          tell_object(player_list[i],HIG+"~Rakh~ "+NORM+"Someone "+str+"\n");
	  write_file("/players/stark/rakh/log/chat",HIG+"~Rakh~ "+NORM+"Someone "+str+"\n");
        return 1;}
          tell_object(player_list[i],HIG+"~Rakh~ "+NORM+capitalize(TPRN)+" "+str+"\n");
	  write_file("/players/stark/rakh/log/chat",HIG+"~Rakh~ "+NORM+capitalize(TPRN)+" "+str+"\n");
     }
}
return 1;
}

rakh_talk_history(){ tail("/players/stark/rakh/log/chat"); return 1;}
