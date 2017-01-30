cmd(str){
  object ob;
  string who;
  string msg;
  if(!str || sscanf(str,"%s %s",who,msg) != 2){
    write("What would you like to whisper?\n");
    return 0;
  }
  who = lower_case(who);
  ob = find_player(who);
  if(!ob || !present(who,environment(this_player())) ){
    write("That player is not here to whisper to.\n");
    return 1;
  }
  if(ob->query_invis() > this_player()->query_level()){
    write("That player is not here to whisper to.\n");
    return 1;
  }
  tell_object(ob,this_player()->query_name()+" whispers to you, \""+msg+"\"\n");
  write("You whisper, \""+msg+"\", to "+ob->query_name()+".\n");
say(this_player()->query_name()+" whispers something to "+ob->query_name()+".\n",ob);
  return 1;
}
