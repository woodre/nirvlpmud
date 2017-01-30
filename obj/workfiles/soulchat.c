/*
soul.c
Chat functions written by Mythos for his chatter box,
and adapted by Feldegast for the soul.
4-15-00
*/

#define ESC ""
#define BLU ESC+"[34m"
#define NORM ESC+"[2;37;0m"

#define MST "/obj/user/mchat.c"
#define ASK "/obj/user/chat_ask.c"

string cap_name;
string msgin,msgout,mmsgin,mmsgout,msghome;
object myself;

/* A list of chat channels */
string *chats;

get() {
  cap_name = call_other(this_player(), "query_name", 0);
  return 1;
}

drop() { return 1; }

id(str) { return str == "soul" || str == "ND"; }

long() {
  write("It is transparent.\n");
}

ghost() {
  cap_name = call_other(this_player(), "query_name", 0);
  return call_other(this_player(), "query_ghost");
}


/*
init() { soul_init();}
*/

init() {
#ifndef __LDMUD__ /* Rumplemintz */
  add_action("emote"); add_xverb(":");
#else
  add_action("emote", ":", 3);
#endif

  /* Chat commands */
  add_action("addmem","addmem");
  add_action("namchat","createchat");
  add_action("remmem","leave_chat");
  add_action("list","listchat");
  add_action("chatwho","cwho");
#ifndef __LDMUD__ /* Rumplemintz */
  add_action("chat");add_xverb("c");
#else
  add_action("chat", "c", 3);
#endif
}

query_msgin() { return msgin; }
query_msgout() { return msgout; }
query_mmsgin() { return mmsgin; }
query_mmsgout() { return mmsgout; }
query_msghome() { return msghome; }

/* Some functions to set moving messages. */

setmin(m) {
    msgin = m;
    call_other(myself,"update",1);
    return 1;
}

setmmin(m) {
    mmsgin = m;
    call_other(myself,"update",2);
    return 1;
}

setmout(m) {
    msgout = m;
    call_other(myself,"update",3);
    return 1;
}

setmmout(m) {
    mmsgout = m;
    call_other(myself,"update",4);
    return 1;
}

setmhome(m) {
    msghome = m;
    call_other(myself,"update",9);
    return 1;
}


reset(arg) {
  if(arg) return;
  myself=this_player();
  chats = ({ });
}


/*
#include "soul_com.c"
*/

emote(str){
  if(ghost())
    return 0;
  if(!str)
    return 0;
 str = format(str,60);
  write("You "+str+"\n");
  say(call_other(this_player(), "query_name", 0) + " "+ str +"\n");
  return 1;
}

/*
Functions for handling chat channels. 
*/

chat(str) {
  string null,null2;
  if(!str) {
    notify_fail("Usage: c<channel name> <message>\n");
    return 0;
  }  
  if(this_player()->is_ghost()) {
    write("You cannot chat in your ghostly state.\n");
    return 1;
  }
  if(sscanf(str,"%s %s",null,null2) == 2) {
     if(member_array(null,chats) != -1) {
       MST->chat(null,null2);
       return 1; 
     } 
  }
}

list() { 
  object *members;
  int h;
  if(sizeof(chats) < 1) {
    write("You aren't on any channels\n");
    return 1; 
  }

  for(h=0; h < sizeof(chats); h++) {
    members=MST->query_members(chats[h]);
      if(!members || member_array(this_player(),members)==-1)
        chats-=({ chats[h--] });
  }

  write("Channels:\n"+BLU);
  for(h=0;h<sizeof(chats);h++) {
    if(chats[h] != "")
      write(chats[h]+"   ");
  }

  write(NORM+"\n");
  return 1; 
}

chatwho(str) {
  if(!str) {
    notify_fail("Usage: cwho <chan>\n");
    return 0;
  }
  if(this_player()->query_level() < 21 && member_array(str,chats)==-1) {
    write("You are not on that chat channel.\n");
    return 1;
  }
  MST->chat_who(str);
  return 1; 
}

namchat(str) {
  if(!str) return 0;
  if(MST->createchat(str) == 1) {
    chats += ({str});
    write("Channel '"+str+"' created.\n");
    return 1; 
  }
  else {
    write("The chat name may be too long (max 5 chars) or\n"+
          "that chat name may already exist.\n");
    return 1; 
  }
}

remmem(str) {
  if(!str) return 0;
  if(member_array(str,chats) != -1) {
    if(MST->removemem(str,this_player())) { 
      chats -= ({str});
      write("You have left channel "+str+".\n"); return 1; 
    }
    write("Say that again?\n");
    return 1; 
  }
  write("You sure you are in that channel?\n");
  return 1;
}

addmem(str) {
  string null,null2;
  object ob,target;
  if(!str) {
    notify_fail("Usage: addmem <channel> <name>\n");
    return 0;
  }
  if(sscanf(str,"%s %s",null,null2) != 2) {
    notify_fail("Usage: addmem <channel> <name>\n");
    return 0;
  }
  if(member_array(null,chats) == -1) {
    write("You are not on that channel.\n"); 
    return 1; 
  }
  target=find_player(null2);
  if(!target) {
    write("That person is not on.\n");
    return 1; 
  }
  if(null2 == "guest") {
    write("You may not add that player.\n"); 
    return 1; 
  }
  if(target->query_invis() && this_player()->query_level() < 100) { 
    write("That player is not on.\n"); 
    return 1; 
  }
  if(in_editor(target)) {
    write("That person is in edit.\n");
    return 1; 
  }
  if(target->query_attack()) {
    write("That person is in combat.\n"); 
    return 1; 
  }
  ob = clone_object(ASK);
  ob->set_target(find_player(null2));
  ob->set_from(this_player());
  ob->set_channel(null);
  move_object(ob,target);
  write("You invite "+capitalize(null2)+" to channel '"+null+"'.\n");
  return 1; 
}

add_chat(str) { chats += ({str}); }

/* Remove the player from all of his/her chat channels. */
remove_object(ob) {
  string *ctemp;
  int i;
  ctemp=chats;
  for(i=sizeof(chats)-1; i >= 0; i--)
    remmem(ctemp[i]);
}
