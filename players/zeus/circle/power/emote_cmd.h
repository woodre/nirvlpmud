
emote_cmd(str)
{
  if(!str) return 0;
  tell_room(environment(User), User->QN+" "+str+"\n");
  return 1;
}

