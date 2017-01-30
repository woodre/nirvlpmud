/* Version 1.o of the Good Clan object...   started July 3rd, 2002
   -Dar  */

#include "/players/daranath/closed/clan/good/defs.h"
#include <ansi.h>
#define CHAT "/players/daranath/closed/clan/good/chatter.c"
#define SAVE "players/daranath/closed/clan/good/member/"
#define SPELL "/players/daranath/closed/clan/good/daemon.c"

/* To change the clan name, simply edit CLANID to new name, and change id(str) plus
   the chatter device in good directory (chatter.c)  */
#define CLANID "Lion"

int clanrank;
string tats_place, title;

query_auto_load() {return "/players/daranath/closed/clan/good/clanobj.c:"; }
id(str) {return str == "clan_ob" || str == "good_clan" || str == "tattoo" || str == "lion_clan"; }
/*
id(str) {return str == "clan_ob" || str == "lion_clan" || str == "kill_check_object"; }
short() {return (HIW+"Clan Tattoo "+NORM+"<"+HIC+CLANID+"Clan"+NORM+">"); }
*/
long() {
write("A flowing "+HIC+"blue tattoo"+NORM+" of a "+CLANID+".\n"+
      "Clan abilities are available through: "+HIC+"clan_help"+NORM+".\n");
  }

drop() { return 1;}
get() { return 0;}

extra_look() {
if(!tats_place) {tats_place == "shoulder"; }

    if(environment() == this_player())
 write("You have a massive tattoo representing the "+HIC+CLANID+" Clan"+NORM+" on your "+tats_place+".\n");
   else write(environment()->query_name()+" has a tattoo of the "+HIC+CLANID+" Clan"+NORM+" on thier "+tats_place+".\n");
}

init() {
if(environment(this_object()) == this_player()) {
  if(!restore_object(SAVE+tpn)) {
  clanrank = 1;
  tats_place = "shoulder";
CHAT->chat_line("has joined the Lion Clan",tp->query_real_name(),1);
   save_object(SAVE+tpn);
  }
  CHAT->add_membr(tp);

write(HIW+"<> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <>"+NORM+"\n");
write(HIC+"       Welcome to the "+CLANID+" Clan"+NORM+"\n");
write("\n");
write(HIW+"          ----> Clan News <----"+NORM+"\n");
write("\n");
write(HIW+"<> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <>"+NORM+"\n");

add_action("quit","quit");
add_action("world_emote","emote");
add_action("clan_update","clan_update");
add_action("clan_chat","cc");
add_action("clan_emote","cce");
add_action("clan_help","clan_help");
add_action("clan_info","clan");
add_action("clan_overview","outline");
add_action("clan_quit","leave_clan");
add_action("clan_save","clan_save");
add_action("clan_muffles","clan_hush");
add_action("clan_unmuffles","clan_unhush");
add_action("clan_score","clan_score");
add_action("clan_score","csc");
add_action("clan_who","clan_who");
add_action("clan_who","cwho");
add_action("clan_gwho","clan_list");
add_action("clan_gwho","clist");
add_action("clan_title","ctitle");
add_action("clan_move","move_tattoo");
}
  }

save_me() {save_object(SAVE+epn); return 1; }

clan_save() { save_me(); tell_object(ep,"<"+HIC+"Lion Clan"+NORM+"> Clan status saved.\n"); return 1; }

clan_update() {
  move_object(clone_object("/players/daranath/closed/clan/good/clanobj.c"),tp);
  write("<"+HIC+""+CLANID+"Clan"+NORM+"> Clan Status Updated.\n");
  save_me();
  destruct(this_object());
return 1; }

clan_muffles() {
write("You turn off the chat line for the "+HIC+CLANID+" Clan"+NORM+".\n");
  CHAT->sub_membr(tp);
return 1;
}

clan_unmuffles() {
write("You turn on the chat line for the "+HIC+CLANID+" Clan"+NORM+".\n");
  CHAT->add_membr(tp);
return 1;
}

clan_overview() {
write(HIW+"<> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <>"+NORM+"\n");
write(HIC+"           "+CLANID+" Clan Overview"+NORM+"\n");
write(HIW+"<> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <>"+NORM+"\n");
cat("/players/daranath/closed/market/docs/overview2.txt");
write(HIW+"<> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <>"+NORM+"\n");
return 1; 
}

clan_help() {
write(HIW+"<> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <>"+NORM+"\n");
write(HIC+"           "+CLANID+" Clan Commands"+NORM+"\n");
write(HIW+"<> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <>"+NORM+"\n");
write("Clan chat line: "+HIC+"cc"+NORM+" to talk, "+HIC+"cce"+NORM+" to emote\n");
write("Clan World who: "+HIC+"cwho"+NORM+"\n");
write("Clan who listing: "+HIC+"clist"+NORM+"\n");
write("Clan score listing: "+HIC+"csc"+NORM+"\n");
write("Muffle Clan chat line: "+HIC+"clan_hush"+NORM+"\n");
write("Unmuffle Clan chat line: "+HIC+"clan_unhush"+NORM+"\n");
write("Lion Clan Overview: "+HIC+"outline"+NORM+"\n");
write("Lion Clan title: "+HIC+"ctitle"+NORM+"\n");
write("Save your Clan status: "+HIC+"clan_save"+NORM+"\n");
write("Change location of your Clan tattoo: "+HIC+"move_tattoo"+NORM+"\n");
write("Update your Clan tattoo: "+HIC+"clan_update"+NORM+"\n");
write("Leave the Lion Clan: "+HIC+"leave_clan"+NORM+"\n");
write("This listing: "+HIC+"clan_help"+NORM+"\n");
write(HIW+"<> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <> - <>"+NORM+"\n");
return 1;
}

clan_chat(str) {
  if(!str) { write("What do you want to say over the "+CLANID+" Clan line.\n"); return 1; }
if(str == "history") {
tail("/players/daranath/closed/clan/good/history");
return 1; }
  CHAT->chat_line(str,tp->query_name());
 write_file("/players/daranath/closed/clan/good/history",HIW+"<> "+HIC+"LionClan"+HIW+" <> "+NORM+tp->query_name()+" says: "+str+"\n");
return 1; }

clan_emote(str) {
  if(!str) { write("What do you want to emote over the "+CLANID+" Clan line.\n"); return 1; }
  CHAT->chat_line(str,tp->query_name(),1);
 write_file("/players/daranath/closed/clan/good/history",HIW+"<> "+HIC+"LionClan"+HIW+" <> "+NORM+tp->query_name()+" "+str+"\n");
return 1; 
}

clan_title() {
 title = (HIC+"member of "+CLANID+" Clan"+NORM);
if(tp->query_name() == "snowcone") {title = ("the "+HIC+"Lion Clan Tester"+NORM); }

  tp->set_title(title);
 write("*"+HIC+CLANID+" Clan"+NORM+"* Clan title set.\n");
return 1; }

clan_quit() {
	  tp->reset(1);
	  command("save",tp);
write("You forsake your loyalty to the "+HIC+CLANID+" Clan"+NORM+" and leave them behind.\n"+
      "Your tattoo fades away...\n");
	  CHAT->sub_membr(tp);
	  CHAT->chat_line("has left the "+HIC+CLANID+" Clan"+NORM+".",tp->query_real_name(),1);
      rm("/"+SAVE+tpn+".o");
	  destruct(this_object());
return 1; }

quit() {
  clan_save();
  CHAT->sub_membr(ep);
return 0;
}

clan_move(str) {
if(!str) {write("Where would you like to move your tattoo?\n");
  write("Possible locations are: head, face, neck, chest, shoulder, arm, leg, back\n");
  write("Usage: move_tattoo <location>\n");
return 1; }
if(str == "head") {tats_place = "head"; }
if(str == "face") {tats_place = "face"; }
if(str == "neck") {tats_place = "neck"; }
if(str == "neck") {tats_place = "chest"; }
if(str == "chest") {tats_place = "chest"; }
if(str == "shoulder") {tats_place = "shoulder"; }
if(str == "arm") {tats_place = "arm"; }
if(str == "leg") {tats_place = "leg"; }
if(str == "back") {tats_place = "back"; }

if((str != "head") && (str != "face") && (str != "neck") && (str !=  "chest") && (str != "shoulder") && (str != "arm") && (str != "leg") && (str != "back")) {
write("Where would you like to move your tattoo?\n");
write("Possible locations are: head, face, neck, chest, shoulder, arm, leg, back\n");
return 1; }
write("You move your "+HIC+CLANID+" Clan "+NORM+"tattoo through sheer force of will.\n");
return 1; 
}

world_emote(str) {
  if(!str) return 0;
  tell_room(environment(tp),tp->query_name()+" "+str+"\n");
return 1; }

query_clanrank() { return clanrank; }
query_clan() { return CLANID; }
query_clan_align() { return 1; }

add_clanrank(int num) { clanrank += num; }

clan_score() {SPELL->clan_score(); return 1; }
clan_who() {SPELL->clan_who(); return 1; }
clan_gwho() {SPELL->clan_gwho(); return 1; }

