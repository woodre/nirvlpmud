/*
 * clothes.c - custom clothes object that can be worn, but provides no
 * armor class.  The messages for wearing it can be set using
 * set_wear_mess(which,what).  which can be wear_self, remove_self,
 * wear_room, or remove_room.  the wear_room and remove_room parts
 * must contain &NAME&, and may also contain &POSS&, &PRON&, and &OBJ&
 */

#include "/players/illarion/dfns.h"
inherit "obj/treasure";

string self_move_emote;
string room_move_emote;
int clothes;
string wear_room,wear_self,remove_room,remove_self;
object worn_by;

void init() {
  ::init();
  if(self_move_emote) {
#ifndef __LDMUD__
    add_action("move_emote_hook"); add_xverb("");
#else
    add_action("move_emote_hook", "", 3);
#endif
  }
  add_action("cmd_remove","remove");
  add_action("cmd_wear","wear");
}
void check_right_worn() {
  if(!worn_by) return;
  if(!environment()) { worn_by=0; return; }
  if(worn_by != environment()) worn_by=0;
}
short() {
  check_right_worn();
  return ::short()+(worn_by?" (worn)":"");
}
int set_wear_mess(string which,string what) {
  if(!what || !which) return 0;
  switch(which) {
    case "wear_room":   wear_room=what; return 1;
    case "wear_self":   wear_self=what; return 1;
    case "remove_room": remove_room=what; return 1;
    case "remove_self": remove_self=what; return 1;
    default: return 0;
  }
}
string get_trans(object ob,string arg) {
  switch(arg) {
    case "POSS": return (string)ob->query_possessive();
    case "OBJ":  return (string)ob->query_objective();
    case "PRON": return (string)ob->query_pronoun();
    case "NAME": return (string)ob->query_name();
    default:   return (string)ob->query_name();
  }
}
string replace_mess(object ob,string str) {
  string before,arg,after;
  if(!ob) return 0;
  if(!str) return 0;
  if(!sscanf(str,"%s&NAME&%s",before,arg,after)) return 0;
  while(sscanf(str,"%s&%s&%s",before,arg,after))
    str=(before?before:"")+get_trans(ob,arg)+(after?after:"");
  return str;
}
int cmd_wear(string str) {
  string mess;
  if(!str) FAIL("Wear what?\n");
  if(present(str,TP)!=this_object()) FAIL("Wear what?\n");
  check_right_worn();
  if(worn_by) {
    write("You already wear it.\n");
    return 1;
  } else {
    write(wear_self?format(wear_self):"You wear the "+name+".\n");
    say((mess=replace_mess(TP,wear_room))?format(mess):TPN+" wears "+name+".\n");
    worn_by=TP;
    return 1;
  }
}
int cmd_remove(string str) {
  string mess;
  if(!str) FAIL("Remove what?\n");
  if(present(str,TP)!=this_object()) FAIL("Remove what?\n");
  check_right_worn();
  if(worn_by) {
    write(remove_self?format(remove_self):"You remove the "+name+".\n");
    say((mess=replace_mess(TP,remove_room))?format(mess):TPN+" removes "+name+".\n");
    worn_by=0;
    return 1;
  } else {
    write("You are not wearing it.\n");
    return 1;
  }
}
void set_short(string str) {
   ::set_short((string)"/players/illarion/obj/addcolor"->addcolor(str));
}
void set_long(string str) {
  ::set_long(format(str,77));
}
int set_move_emote(string which,string what) {
   if(which == "self") {
      self_move_emote=what;
      return 1;
   }
   else if(which == "room") {
      room_move_emote=what;
      return 1;
   } 
   else
     return 0;
}
status move_emote_hook() {
  if(random(100))
    return 0;
  check_right_worn();
  if(!worn_by)
    return 0;
  if(self_move_emote)
     write(format(self_move_emote));
  if(room_move_emote) {
     string str;
     str=replace_mess(TP,room_move_emote);
     if(str)
        say(format(str));
   }
   return 0;
}
