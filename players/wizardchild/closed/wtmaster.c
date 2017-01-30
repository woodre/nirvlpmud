#define THISOB present("walkie-talkie", this_player())
#define ME this_player()
static object *active_users;
reset(arg) {
  if(arg) 
    return 0;
  active_users = allocate(3);
  active_users[0] = allocate(40);
  active_users[1] = allocate(40);
  active_users[2] = allocate(40);
  call_out("reorder_users", 1200); /* every 20 minutes, organize array */
}
okid(str) {
  return str == "radio" || str == "walkie-talkie" || str == "walkie talkie"; 
}
list_channels() {
  int i;
  for(i = 0; i < 3; i++) {
    if(on_channel(present("walkie-talkie", this_player()), i))
      write("* ");
    write("Channel "+(i+1)+" has "+sizeof(active_users[i])+" users on it.\n");
  }
  write("\n(*) - Denotes that you are on that channel.\n");
  return 1;
}
add_all(object who) {
  int i;
  for(i = 0; i < 3; i++)
    add_channel(who, i);
}
remove_all(object who) {
  int i;
  for(i = 0; i < 3; i++)
    remove_channel(who, i);
}
add_channel(object who, int chan) {
  int i;
  if(on_channel(who, chan))
    return 0;  /* don't add them twice */
  for(i = 0; i < sizeof(active_users[chan]); i++) {
    if(!active_users[chan]) {
      active_users[chan] = who;
      break;
    }
  }
  if(i == sizeof(active_users[chan]))
    active_users[chan] += ({who});
  return 1;
}
remove_channel(object who, int chan) {
  int i;
  if(!on_channel(who, chan))
    return 0;
  for(i = 0; i < sizeof(active_users[chan]); i++) {
    if(active_users[chan] == who) {
      active_users[chan] = 0;
      break;
    }
  }
  return (i == sizeof(active_users[chan]));
}
on_channel(object who, int chan) {
  int i;
  for(i = 0; i < sizeof(active_users[chan]); i++)
    if(active_users[chan] == who)
      return 1;
  return 0;
}
get_users(int chan) {
  return active_users[chan];
}
static reorder_users() {
  object *next;
  int i, x, y;
  next = allocate(3);
  for(i = 0; i < sizeof(next); i++) next[i] = allocate(40);
  for(i = 0; i < sizeof(active_users); i++) {
    for(x = 0; x < sizeof(active_users[i]); x++) {
      if(active_users[i][x])
        next[i][y++] = active_users[x][i];
    }
  }
  active_users = next;
  call_out("reorder_users", 1200);
}
 
print_help() {
  write("A simple 3 channel walkie-talkie. It's really not much to look at.\n");
  write("It can do the following things:\n");
  write(" enable <#>       Enable the specified channel.\n");
  write(" disable <#>      Disable the specified channel.\n");
  write(" talk<#> <str>    Talk on the specified channel.\n");
  write(" talk<#> :<str>   Emote on the specified channel.\n");
  write(" list_chan        List the current channels.\n");
  write(" dump_me          Dump your walkie talkie.\n");
  write(" donate <who>     Give your walkie talkie to who (note the word GIVE).\n");
  write("You can address this as \"walkie-talkie\" or \"radio\".\n");
  return 1;
}
enable(str) {
  int i;
  if(!str || !sscanf(str, "%d", i) || (i < 1 || i > 3)) {
    write("Usage: enable <channel>, where channel is 1, 2, or 3.\n");
    return 1;
  }
  if(on_channel(THISOB, i-1))
    write("You are already on that channel.\n");
  else {
    write("Channel "+i+" is now on.\n");
    add_channel(THISOB, i-1);
  }
  return 1;
}
disable(str) {
  int i;
  if(!str || !sscanf(str, "%d", i) || (i < 1 || i > 3)) {
    write("Usage: disable <channel>,s 1, 2, or 3.\n");
    return 1;
  }
  if(on_channel(THISOB, i-1))
    write("You aren't on that channel.\n");
  else {
    write("Channel "+i+" is now off.\n");
    remove_channel(THISOB, i-1);
  }
  return 1;
}
donate(str) {
  if(!str || !find_player(str) || 
     find_player(str)->query_invis() > ME->query_level()) {
    write("Usage: donate <who>\n");
    return 1;
  }
  if(find_player(str)->query_level() >= 40) {
    write("That wizard can get his own just fine.\n");
    return 1;
  }
  if(present("walkie-talkie", find_player(str))) {
    write("That person already has a walkie-talkie.\n");
    return 1;
  }
  write("You hand over your walkie-talkie.\n");
  move_object(THISOB, find_player(str));
  tell_object(find_player(str), "You are given a walkie talkie by "+ME->query_name()+".\n");
  return 1;
}
use_chan(str) {
  status emote;
  int i,x;
  string s;
  object ob;
  if(!str || sscanf(str, "%d %s", i, s) != 2 || (i < 1 || i > 3)) {
    write("Usage: talk<#> <str> or talk<#> :<str>\n");
    return 1;
  }
  ob = get_users(i-1);
  if(sscanf(s, ":%s", s)) 
    emote = 1;
  for(x = 0; x < sizeof(ob); x++) 
    /* environment because this object is passed, not player */
    tell_object(environment(ob[x]), "[Channel "+i+"] "+ME->query_name()+" "+
               (emote ? s : "says: "+s)+"\n");
  return 1;
}
