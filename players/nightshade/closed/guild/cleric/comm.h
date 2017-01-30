guild_shout(str) {
object list, badge;
int i;

 list = users();
 i = 0;
  while(i < sizeof(list)) {
    badge = present("cleric_guild", list[i]);
    if(badge) {
      tell_object(list[i], str);
    }
    i ++;
  }
  return 1;
}

avatar_shout(str) {
object list, badge;
int i;
  list = users();
  i = 0;
  while(i < sizeof(list)) {
    badge = present("cleric_guild", list[i]);
    if(badge) {
      if(badge->query_guild_class() == "Avatar" ||
          list[i]->query_real_name() == "timescape") {
      tell_object(list[i], str);
      }
    }
    i ++;
  }
  return 1;
}

avatar(str) {
int Indent;
string Mesg;
  if(MY_CLASS != "Avatar" && NAME != "timescape") {
    write("You can not speak to the Avatars.\n");
    return 1;
  }
  if(!str) {
    write("What would you like to say to your fellow Avatars?\n");
    return 1;
  }
  Mesg = Name+" (Avatar): ";
    avatar_shout(Mesg + str+ "\n");
  return 1;
}

mind_block() {
    is_quiet = !is_quiet;
    if(is_quiet) write("You are now blocking your mind from cleric chant.\n");
    else write("You are now freeing your mind for cleric chant.\n");
    return 1;
}

chat(str) {
object badge, list;
string tell_array, temp1;
int cnt, i, cnt2, blocking;
string Mesg;
int Indent;
  if(!str) {
    write("What would you like to chant to your fellow clerics?\n");
    return 1;
  }
  list = users();
  while(i < sizeof(list)) {
    if(badge = present("cleric_guild", list[i])) {
      if(!badge->query_is_quiet()) {
        Mesg = Name+" (Cleric): ";
          tell_object(list[i],Mesg + str + "\n");
      }
    }
    i ++;
  }
  if(is_quiet) is_quiet = !is_quiet;
  return 1;
}

guild_emote(str) {
object badge, list;
string tell_array, temp1;
int cnt, i, cnt2, blocking;
string Mesg;
int Indent;
  if(!str) {
    write("What would you like to emote to your fellow clerics?\n");
    return 1;
  }
  list = users();
  while(i < sizeof(list)) {
    if(badge = present("cleric_guild", list[i])) {
      if(!badge->query_is_quiet()) {
        Mesg = "(Cleric): "+Name+" ";
          tell_object(list[i],Mesg + str + "\n");
      }
    }
    i ++;
  }
  if(is_quiet) is_quiet = !is_quiet;
  return 1;
}


