#define CHANS ({"gossip","shout","announce","wiz","risque"})
has_member(arr, s) {
  int i, so;
  for(i = 0,so = sizeof(arr); i < so; i++) {
    if(arr[i] == s)
      return i;
  }
  return -1;
}
use_chan(chan, msg) {
  int i, so;
  object ob;
  for(ob = users(), i = 0, so = sizeof(ob); i < so; i++) {
    if(ob[i]->on_channel(chan))
      tell_object(ob[i], msg);
  }
}
use(str) {
  string chan,msg,foo;
  int n;
  if(!str || sscanf(str, "%s %s", chan, msg) != 2) {
    write("Usage: use <chan> <msg>\n");
    return 1;
  }
  if((n = has_member(CHANS, chan)) == -1) {
    write("No such channel: "+chan+"\n");
    return 1;
  }
  if(msg[0] == 'N') {
    if(msg[1] == ':') {
      sscanf(msg, "N:%s", msg);
      foo = "("+chan+") Wizardchild "+msg;
    } else {
      sscanf(msg, "N%s", msg);
      foo = "Wizardchild "+chan+"s: "+msg;
    }
  } else
    foo = msg;
  use_chan(chan, foo+"\n");
  return 1;
}
