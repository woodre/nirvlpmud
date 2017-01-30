#define CHAN "players/dragnar/daemons/chan"

inherit "obj/treasure";

void
reset(int arg) {
   if (arg) return;
   set_id("tester");
   set_short("Tester");
   set_long(
"A tester for channels.\n");
   set_weight(0);
   set_value(1200);
   set_save_flag();
}

void init() {
  if(this_player()->query_level() > 39) {
    add_action("debug","debug");
    add_action("del","del");
	add_action("add","add");
	add_action("send","send");
  }
}

status
debug(string str) {
 
  CHAN->debug();
   return 1;
}
del(str) {
  string who,chan;
  object it;
  
  if(!str) return 0;
  sscanf(str, "%s %s", who,chan);
  it = find_living(who);
  CHAN->deregister(it, chan);
  return 1;
}

status
add(string str) {
  string who,chan;
  object it;
  
  if(!str) return 0;
  sscanf(str, "%s %s", who,chan);
  it = find_living(who);
  CHAN->register(it, chan);
  return 1;
}

status
send(string str)
{
  string chan,what;
  
  if(!str) return 0;
  sscanf(str, "%s %s", chan,what);
  what = what + "\n";
  CHAN->broadcast(what, 1, chan);
  return 1;
}
