#include "/players/pavlik/guild/colors.h"
#define OWN capitalize(owner->query_real_name())

/*
 * meijin room invite
 */

object owner;
object target;

id(str) { return str == "meijin_room_invite"; }

drop() {
  destruct(this_object());
  return 1;
}

init() {
  add_action("accept","xaccept");
  add_action("decline","xdecline");
}

do_invite(ob) {
  owner = ob;
  target = environment(this_object());
  tell_object(environment(this_object()),
  "\n"+OWN+" has invited you to "+owner->query_possessive()+" private guild room.\n"+
  "Do you accept the invitation? (xaccept/xdecline)\n\n");
  call_out("rid_this", 120);
  return 1;
}

rid_this() {
  if(!target && !owner) {
	destruct(this_object());
	return 1;
  }
  if(owner) {
	tell_object(owner, capitalize(target->query_real_name())+" did not respond to "+
		"your invitation.\n");
  }
  destruct(this_object());
  return 1;
}

accept() {
  if(!owner || !environment(owner)->query_guild_room()) {
	write("The person who extended this invitation is no longer avaliable.\n");
 	destruct(this_object());
	return 1;
  }
  if(environment(this_player())->realm() == "NT") {
	write("You cannot accept the invitation from this location.\n");
	write("Move to another location and try again.\n");
	return 1;
  }
  write("You accept "+capitalize(owner->query_real_name())+"'s invitation.\n");
  tell_object(owner, capitalize(this_player()->query_real_name())+" has accepted "+
	"your invitation.\n");
  say(capitalize(this_player()->query_real_name())+" leaves through a hole in the sky.\n");
  move_object(this_player(), environment(owner));
  call_other(this_player(), "look", 0);
  say(capitalize(this_player()->query_real_name())+" arrives.\n");
  destruct(this_object());
  return 1;
}

decline() {
  if(!owner) write("You decline the invitation.\n");
  else write("You decline "+capitalize(owner->query_real_name())+"'s invitation.\n");
  if(owner) tell_object(owner, capitalize(this_player()->query_real_name())+
	" declines your invitation.\n");
  destruct(this_object());
  return 1;
}

