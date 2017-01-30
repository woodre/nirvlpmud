#include "/players/mythos/closed/ansi.h"
#define MST "/players/mythos/prac/mchat.c"
#define tp this_player()
#define tpn tp->query_real_name()
string chats;

id(str) { return str == "chatter box" || str == "box" || str == "chatter"; }

short() { return "Chatter Box"; }

long() { write("This is a chatter box.  It allows you to make chat channels\n"+
               "That can have up to 5 members.  A fun filled toy from Mythos.\n"+
               "Commands are:\n"+
               " createchat <name of channel>                 note: max 5 chars\n"+
               " addmem <name of channel> <name of person>    adds members\n"+
               " leave_chat <name of channel>                 you leave the channel\n"+
               " cwho <name of channel>                       channel who\n"+
               " c<name of channel> <messege>                 chat\n"+
               " crush_chatter_box                            destructs box\n"+
               " listchat                                     shows what chats you are on\n"+
               "   note: if channel is named 'bob' then to chat\n"+
               "                  cbob hi\n"+
               "         to emote\n"+
               "                  cbob :bows\n"); }

drop() { return 1; }
get() { return 0;}
query_prevent_shadow() { return 1; } 

reset(arg) { if(arg) return; chats = ({""}); }


init() { 
  if(tp == environment(this_object())) {
    if(tpn == "guest") destruct(this_object());
  add_action("addmem","addmem");
  add_action("namchat","createchat");
  add_action("remmem","leave_chat");
  add_action("list","listchat");
  add_action("chatwho","cwho");
#ifndef __LDMUD__
  add_action("chat");add_xverb("c");
#else
  add_action("chat", "c", 3);
#endif
  add_action("des","crush_chatter_box");
  }
}

chat(str) {
string null,null2;
if(!str) { write("What are you doing?\n"); return 1; }
  if(environment(tp)) {
     if(sscanf(environment(tp),"%sprison",null)) {
       write("YOU ARE IN PRISON!\n");
      return 1; } }
  if(sscanf(str,"%s %s",null,null2) == 2) {
     if(member_array(null,chats) != -1) {
       MST->chat(str);
       return 1; 
     } 
  }
}

list() { 
  int h;
  if(sizeof(chats) < 2) {
    write("You are on no channels\n");
   return 1; }
   write("Channels:\n"+BLU);
  for(h=0;h<sizeof(chats);h++) {
   if(chats[h] != "") {
     write(chats[h]+"   ");
   }}
   write(NORM+"\n");
return 1; }

chatwho(str) {
  if(!str) return 0;
  MST->chat_who(str);
return 1; }

namchat(str) {
if(!str) return 0;
  if(MST->createchat(str)) { chats += ({str}); return 1; }
  else write("The chat name may be too long (max 5 chars) or\n"+
             "that chat name may already exist.\n");
return 1; }

remmem(str) {
  if(!str) return 0;
  if(member_array(str,chats) != -1) {
    if(MST->removemem(str,tpn)) { 
      chats -= ({str});
      write("You have left channel "+str+".\n"); return 1; }
    write("Say that again?\n");
  return 1; }
  write("You sure you are in that channel?\n");
return 1;}

addmem(str) {
string null,null2;
object ob;
  if(!str) return 0;
  if(sscanf(str,"%s %s",null,null2) != 2) return 0;
  if(member_array(null,chats) == -1) { write("You are not on that channel.\n"); return 1; }
  if(!find_player(null2)) { write("That person is not on.\n"); return 1; }
  if(null2 == "guest") { write("You may not add that player.\n"); return 1; }
  if(find_player(null2)->query_invis() && this_player()->query_level() < 100) { 
    write("That player is not on.\n"); return 1; }
  if(in_editor(find_player(null2))) { write("That person is in edit.\n"); return 1; }
  if(find_player(null2)->query_attack()) { write("That person is in combat.\n"); return 1; }
  ob = clone_object("/players/mythos/prac/chat_ask.c");
  ob->set_target(find_player(null2));
  ob->set_from(this_player());
  ob->set_channel(null);
  move_object(ob,find_player(null2));
return 1; }

add_chat(str) { chats += ({str}); }

des() { 
  write("You crumple up the chatter box.\n"); 
  destruct(this_object());
return 1; }
