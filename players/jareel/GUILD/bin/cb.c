/* *************************************************************************
 * gchat
 * 
 * - Earwax 12/26/03
 * 
 * Guild channel commands
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

  ob = present(GOB_ID,this_player());
  write("Guild channel is currently ");
  write(((status)ob->query_muffle() ? HIR+"OFF" : HIR+"ON")+NORM+NORM+".\n");
  return 1;
}

status muffle_off() {
  object ob;

  ob = present(GOB_ID,this_player());
  ob->set_muffle(0);
  write("Guild channel no longer muffled.\n");
  return 1;
}

status muffle_on() {
  object ob;

  ob = present(GOB_ID,this_player());
  ob->set_muffle(1);
  write("Guild channel muffled.\n");
  return 1;
}
status channel_list() {
  object *members;
  int i, siz;
  string info;

  info = "";
  siz = sizeof(members = (object*)CHANNELD->manual_register());
  write("Currently listening to the Guild Channel:\n");
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
  write(RED+"==============================================================================\n"+NORM+NORM);
  while(i--) write(info[i]);
  write(RED+"==============================================================================\n"+NORM);
  return 1;
}

status channel_msg(string arg) {
  string name, t, n;
  object ob;

  ob = present(GOB_ID,this_player());

  if ((int)this_player()->query_invis() > 38)
    name = "Someone";
  else
    name = capitalize((string)this_player()->query_real_name());

  if (sscanf(arg,":%s",arg) == 1)
    t = " ";
  else
    t = ": ";

    n = "";

  /* Took this from the tracker, don't need it here.
  if ((int) ob->query_legend())
    n = HIB+"["+NORM+HIW+"The Legend"+NORM+HIB+"] ";
  else
    if ((int)ob->query_pk_legend())
      n = HIB+"["+NORM+HIR+"The PK Legend"+NORM+HIB+"] ";
  if (!n || n == "0" || n == "")
    n = HIB+"["+NORM+HIK+"Legends"+NORM+HIB+"] ";
  */

  n = RED+"<<<"+NORM+CYN+"The Crimson Bat"+NORM+RED+">>> ";
  CHANNELD->channel_msg(n+NORM+HIK+name+t+arg+NORM+NORM+"\n");
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

