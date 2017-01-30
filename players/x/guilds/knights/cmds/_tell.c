int main(string str){
  string who, msg, verb;
  object obj;
  
  if(!str || sscanf(str, "%s %s", who, msg) != 2 ||
    previous_object()->kspeech_off())
    return 0;
    
  if(!(obj = find_player(who)) || !(obj = find_living(who)) ||
     obj->query_invis())
  {
    write("You don't see "+capitalize(who)+" on the realms of Nirvana.\n");
    return 1;
  }
  
  
  msg = (string)"/players/x/guilds/knights/daemons/lang"->translate_sentence(msg);
  
  switch(msg[strlen(msg)-1]){
    case '?':
      verb = "asked";
      break;
    case '!':
      verb = "exclaimed";
      break;
    default:
      verb = "sayeth";
      break;
  }
  
  write("From afar, you "+verb+" to "+(string)obj->query_name()+", \""+msg+"\"\n");
  tell_object(obj,
   (msg="From afar, "+(string)this_player()->query_name()+" "+verb+" to you, \""+msg+"\"\n"));
  obj->add_tellhistory(msg[0..strlen(msg)-2]);
  
  return 1;
} 
