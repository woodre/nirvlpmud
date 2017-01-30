#if 0
#define CHAN "/bin/channel_daemon"
#else
#define CHAN "/players/dragnar/workdir/channel_daemon"
#endif

#define TESTCHAR_D "/obj/user/testchar-d"

inherit "obj/treasure";

void
reset(int arg) {
   if (arg) return;
   set_id("ctest");
   set_short("Ctest");
   set_long(
"debug - Print out current state\n\
chan - print channel list\n\
del - remove player from a channel\n\
add - add player to a channel\n\
send - send a mesg to a channel\n");
   set_weight(0);
   set_value(1200);
   set_save_flag();
}

void init() {
/*  if(this_player()->query_level() > 39 || TESTCHAR_D->query_owner(this_player()->query_name()) ) {
    add_action("debug","debug");
    add_action("del","del");
	  add_action("add","add");
	  add_action("send","send");
    add_action("channels","chan");
  }*/
  add_action("debug","debug");
  add_action("del","del");
  add_action("add","add");
  add_action("send","send");
  add_action("channels","chan");
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
  if(!it) {
    write("Invalid Player.\n");
    return 1;
  }
  CHAN->remove_channel(chan, it);
  if( it == this_player() )
    remove_action(chan);
  return 1;
}

status
add(string str) {
  string who,chan;
  object it;
  
  if(!str) return 0;
  sscanf(str, "%s %s", who,chan);
  it = find_living(who);
  CHAN->add_channel(chan, it);
  if( it == this_player() )
    add_action( "broadcast", chan );
  return 1;
}

status
send(string str)
{
  string chan,what;
  
  if(!str) return 0;
  sscanf(str, "%s %s", chan,what);
  what = what + "\n";
  CHAN->channel_message(chan, what);
  return 1;
}

status
channels() {
  if( this_player() ) {
    CHAN->query_player_channels( this_player() );
  }
  return 1;
}

int
broadcast(string msg) {
  string channel;
  int index;

  channel = query_verb();
/* Edited by OMEGA; Reason: If no arg provided should return 0; */
  if (!msg) return 0;
  
  CHAN->channel_message(channel, msg );
  return 1;
}
