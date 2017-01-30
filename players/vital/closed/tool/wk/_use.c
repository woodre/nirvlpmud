#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#define CHANS ({ "gossip", "shout", "announce", "risque", "equip", "babble" })

/* has_member(string *arr, string s) */
/* { */
/*   int i, so; */
/*   so = sizeof(arr); */
/*   for(i = 0; i < so; i++) */
/*   { */
/*     if(arr[i] == s) */
/*       return i; */
/*   } */
/*   return -1; */
/* } */
/*  */
use_chan(chan, msg)
{
  int i, so;
  object ob;
  for(ob = users(), i = 0, so = sizeof(ob); i < so; i++) {
    if(ob[i]->on_channel(chan))
      tell_object(ob[i], msg);
  }
}

main(str)
{
  string chan,msg,foo;
  int n;
  if(!str || sscanf(str, "%s %s", chan, msg) != 2) {
    write("Usage: use <chan> <msg>\n");
    return 1;
  }
  if((n = member_array(CHANS, chan)) == -1) {
    write("No such channel: " + chan + "\n");
    return 1;
  }
  if(msg[0] == 'N') {
    if(msg[1] == ':') {
      sscanf(msg, "N:%s", msg);
      foo = "(" + chan + ") " + HIW + "Vital " + NORM + msg;
    } else {
      sscanf(msg, "N%s", msg);
      foo = HIW + "Vital " + chan + "s: " + msg;
    }
  } else
    foo = msg;
  use_chan(chan, foo + "\n");
  return 1;
}

get_help()
{
  string help;
  help = "Syntax: use <channel> <message>";
  return help;
}