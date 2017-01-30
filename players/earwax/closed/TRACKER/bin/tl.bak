/* *************************************************************************
 * tdt
 * 
 * - Earwax 9/14/03
 * 
 * Tracker channel commands
 * - history   channel history
 * - on        remove muffle
 * - off       muffle channel
 * - list      list those who can hear the channel
 * - :         emote
 *
 * *************************************************************************
*/

#include "../defs.h"

inherit WAXFUNS;

status check_muffle() {
  object ob;

  ob = present(TRACKER_ID,this_player());
  write("Tracker channel is currently ");
  write(((status)ob->query_muffle() ? HIR+"OFF" : HIR+"ON")+NORM+NORM+".\n");
  return 1;
}

status muffle_on() {
  object ob;

  ob = present(TRACKER_ID,this_player());
  ob->set_muffle(1);
  write("Tracker channel muffled.\n");
  return 1;
}

status muffle_off() {
  object ob;

  ob = present(TRACKER_ID,this_player());
  ob->set_muffle(0);
  write("Tracker channel no longer muffled.\n");
  return 1;
}

status channel_list() {
  object *members;
  int i, siz;
  string info;

  info = "";
  siz = sizeof(members = (object*)CHANNELD->manual_register());
  write("Currently listening to the Tracker Channel:\n");
  for (i = 0; i < siz; i++)
  {
    info += capitalize((string)members[i]->query_real_name());
    if (i + 1 < siz)
      info += (", ");
  }
  info = line_wrap(info);
  write(info);
  write("\n");
  return 1;
}

status channel_history() {
  int i;
  string *info;

  i = sizeof(info = (string *)CHANNELD->dump_history());
  write(HIB+"==============================================================================\n");
  write("|                             "+HIK+"Tracker History"+HIB+"                                |\n");
  write("==============================================================================\n"+NORM);
  while(i--) write(info[i]);
  write(HIB+"==============================================================================\n");
  write("|                                                                            |\n");
  write("==============================================================================\n"+NORM);
  return 1;
}

status channel_msg(string arg) {
  string name, t, n;
  object ob;

  ob = present(TRACKER_ID,this_player());

  if ((int)this_player()->query_invis() > 38)
    name = "Someone";
  else
    name = capitalize((string)this_player()->query_real_name());

  if (sscanf(arg,":%s",arg) == 1)
    t = " ";
  else
    t = ": ";

  n = "";

  if ((int) ob->query_legend() && (int)this_player()->query_level() < 20)
    n = HIB+"["+NORM+HIW+"Legend"+NORM+HIB+"] ";
  /* This was just goofing around, it's gotten old
  else if ((string)this_player()->query_real_name() == "earwax")
    n = HIB+"["+NORM+BLINK+HIR+"Earwax"+NORM+NORM+HIB+"] ";
  */
  else if ((int)this_player()->query_level() > 19)
    n = HIB+"["+HIR+"Wizard"+HIB+"] ";
  else
    if ((int)ob->query_pk_legend())
      n = HIB+"["+NORM+HIR+"PK Legend"+NORM+NORM+HIB+"] ";
  else if ((int)this_player()->query_level() > 19)
    n = HIB+"["+HIK+"Wizard"+HIB+"] ";
  if (!n || n == "0" || n == "")
    n = HIB+"["+NORM+HIK+"Tracker"+NORM+HIB+"] ";
  CHANNELD->channel_msg(n+NORM+NORM+name+t+arg+"\n");
  return 1;
}


status main(string arg) {

  if (!arg) return check_muffle();

  switch(arg) {
    case "on"      : return muffle_off();
    case "off"     : return muffle_on();
    case "history" : return channel_history();
    case "list"    : return channel_list();
    default        : return channel_msg(arg);
  }
}

