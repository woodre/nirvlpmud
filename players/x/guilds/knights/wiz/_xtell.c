int main(string str){
  object ob;
  string who, what;
  if((string)this_player()->query_real_name()!= "x" || !str || sscanf(str, "%s %s", who, what) < 2 || !(ob = find_player(who))) return 0;
  write("You tell "+who+" "+what+"\n");
  tell_object(ob, "X tells you: "+what+"\n");
  ob->add_tellhistory("X told you: "+what+"\n");
  return 1;
}

