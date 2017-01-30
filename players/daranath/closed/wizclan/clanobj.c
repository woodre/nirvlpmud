/* Version 1.0 of the Wizclan object, coded by Daranath....
   --- First wizclan coded by Maledicta, who left us suddenly ---
   Started August 6th, 2002...   */

#include "/players/daranath/closed/wizclan/defs.h"
#include <ansi.h>
#define CHAT "/players/daranath/closed/wizclan/chatter.c"
#define SAVE "players/daranath/closed/wizclan/member/"
#define SPELL "/players/daranath/closed/wizclan/daemon.c"

query_auto_load() {return "/players/daranath/closed/wizclan/clanobj.c:"; }
id(str) {return str == "clan_ob" || str == "wizclan" || str == "symbol" || str == "dark symbol"; }
short() {return ("Dark Symbol of the Wizclan ("+HIR+"mk"+HIW+"2.0"+NORM+")"); }
long() {
write("The dark symbol of the wizclan, version 2.0\n"+
      "Current roster includes Daranath, Forbin, Fred\n"+
      "                        Pestilence and Reflex\n\n"+
      "For commands, type wizclan.\n");
  }

drop() { return 1;}
get() { return 0;}

init() {
if(environment(this_object()) == this_player()) {
  if(!restore_object(SAVE+tpn)) {
   save_object(SAVE+tpn);
  }
  CHAT->add_membr(tp);

add_action("quit","quit");
add_action("clan_update","wc_update");
add_action("clan_chat","cl");
add_action("clan_emote","cle");
add_action("clan_muffles","wc_hush");
add_action("clan_unmuffles","wc_unhush");
add_action("clan_who","wc_who");
add_action("clan_gwho","clan_list");
add_action("clan_gwho","clist");
add_action("clan_help","wizclan");
}
  }

save_me() {save_object(SAVE+epn); return 1; }

clan_update() {
  move_object(clone_object("/players/daranath/closed/wizclan/clanobj.c"),tp);
write("WizClan object updated.\n");
  save_me();
  destruct(this_object());
return 1; }

clan_help() {
write(HIR+"[          "+HIW+"wizclan powers"+HIR+"          ]"+NORM+"\n");
write("\nBasic Commands: cl, cle, wc_hush, wc_unhush\n"+
      "                wc_update, wizclan\n");
write("Advanced: wc_who\n\n");
write(HIR+"[          "+HIW+"wizclan powers"+HIR+"          ]"+NORM+"\n");
return 1;
}
clan_muffles() {
write("You turn off the WizClan chat line.\n");
  CHAT->sub_membr(tp);
return 1;
}

clan_unmuffles() {
write("You turn the WizClan chat line back on.\n");
  CHAT->add_membr(tp);
return 1;
}

clan_chat(str) {
  if(!str) { write("What do you want to say over the WizClan chat line?\n"); return 1; }
if(str == "history") {
tail("/players/daranath/closed/wizclan/history");
return 1; }
  CHAT->chat_line(str,tp->query_name());
write_file("/players/daranath/closed/wizclan/history",HIR+"["+HIW+"wizclan"+HIR+"] "+NORM+capitalize(tp->query_real_name())+" says: "+str+"\n");
return 1; }

clan_emote(str) {
  if(!str) { write("What do you want to emote over the WizClan chat line?\n"); return 1; }
  CHAT->chat_line(str,tp->query_name(),1);
write_file("/players/daranath/closed/wizclan/history",HIR+"["+HIW+"wizclan"+HIR+"] "+NORM+capitalize(tp->query_real_name())+" "+str+"\n");
return 1; 
}

quit() {
  CHAT->sub_membr(ep);
return 0;
}

clan_who() {SPELL->clan_who(); return 1; }

