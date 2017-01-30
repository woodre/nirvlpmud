int main(string str){
  string verb;
  if(!str || previous_object()->kspeech_off()) return 0;
  str = (string)"/players/x/guilds/knights/daemons/lang"->translate_sentence(str);
  switch(str[strlen(str)-1]) {
    case '!': verb = "exclaimeth"; break;
    case '?': verb = "asketh"; break;
    default: verb = "sayeth"; break;
  }
  write("You "+verb+", \""+str+"\"\n\n");
  say((string)this_player()->query_name()+" \
"+verb+", \""+str+"\"\n\n");
  return 1;
}
