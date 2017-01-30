#include "/players/vertebraker/guilds/meijin/defs.h";
#include "/players/vertebraker/guilds/meijin/room/room.h";
#define OWN capitalize(owner)

string owner;
string descrip;
string preserve;

static int line_count;

reset(arg){
  if(arg) return;
  owner = "noone";
  descrip = "A chamber in the Citadel. ('info')\n";
  preserve = 0;
}

short(){ return OWN+"'s Chamber"; }

long(){
  write(descrip);
  write("There is one obvious exit: out.\n");
  return;
}

id(str){ return str == owner+"'s room"; }
get(){ return 0; }
drop(){ return 1; }
query_guild_room() { return 1; }

set_owner(str){
  if(!str) return 0;
  owner = str;
  restore_object(SAVEPATH+"room/"+owner);
}

init(){
  add_action("set_descrip","descrip");
  add_action("go_away","out");
  add_action("room_help","info");
  add_action("invite","invite");
  add_action("eject","eject");
  add_action("locker_object","store");
  add_action("retrieve_object","retrieve");
  add_action("view_object","view");
  add_action("cleanse_room","cleanse");
  add_action("xmove", "xmove");
}

/* do not dest this object */
clean_up() {
  return 0;
}

do_save(){
  if(owner == "noone") return 1;
  save_object(SAVEPATH+"room/"+owner);
  return 1;
}

room_help(){
  if(this_player()->query_real_name() != owner) return 0;
  write("This is your own personal chamber within the Citadel.  In this\n");
  write("room you can do the following:\n");
  write("    info            - this menu.\n");
  write("    descrip         - set the room's description.\n");
  write("    invite <who>    - invite someone into your room.\n");
  write("    eject <who>     - kick a player out of your room.\n");
  write("    store <obj>     - store one object in your room.\n");
  write("    retrieve        - retrieve your stored object.\n");
  write("    cleanse         - erase stored object info.\n");
  write("    view            - view your stored object.\n");
  return 1;
}

go_away() {
  if(this_player()->query_guild_name() == "meijin")
	this_player()->move_player("out#players/pavlik/guild/room/quarters");
  else {
	write("You are escorted outside the Citadel.\n");
	this_player()->move_player("out#players/pavlik/guild/room/gate");
  }
  return 1;
}

set_descrip(){
  if(this_player()->query_real_name() != owner) return 0;
  descrip = "";
  line_count = 1;
  write("Changing the room description ... Your description may be\n");
  write("up to six lines long.  Enter '**' on a line by itself to end.\n");
  write("[1]>> ");
  input_to("addto_descrip");
  return 1;
}

addto_descrip(str){
  if(str == "**"){
	write("You redecorate the room ... Nice touch!\n");
	do_save();
	return 1;
  } else {
	line_count++;
	descrip = descrip+str+"\n";
	if(line_count == 7) {
		write("Max description length is 6 lines ... saving description.\n");
		do_save();
		return 1;
	}
	write("["+line_count+"]>> ");
	input_to("addto_descrip");
	return 1;
  }
}

invite(str){
  object obj, ob;

  if(this_player()->query_real_name() != owner) return 0;
  if(!str) {
	write("Invite who?\n");
	return 1;
  }
  obj = find_player(str);
  if(!obj) {
	write(capitalize(str)+" could not be found.\n");
	return 1;
  }
  if(obj->query_level() > 20) {
	write("You cannot invite Wizards.\n");
	return 1;
  }
  if(present("meijin_room_invite", obj)) {
	write("You have already invited "+capitalize(str)+".\n");
	return 1;
  }
  ob = clone_object("players/pavlik/guild/obj/room_invite");
  move_object(ob, obj);
  ob->do_invite(this_player());
  write("You have invited "+capitalize(str)+" to your room.\n");
  write("Waiting for a response ... \n");
  return 1;
}

eject(str) {
  object obj;

  if(this_player()->query_real_name() != owner) return 0;
  if(!str) {
	write("Eject who?\n");
	return 1;
  }
  if(str == owner) {
	write("You cannot eject yourself!\n");
	return 1;
  }
  obj = present(str, environment(this_player()));
  if(!obj) {
	write(capitalize(str)+" is not here.\n");
	return 1;
  }
  if(!obj->is_player()) {
	write("You can only eject players.\n");
	return 1;
  }
  write("You eject "+capitalize(str)+" from your room.\n");
  say(capitalize(owner)+" ejects "+capitalize(str)+" from the room.\n");
  tell_object(obj, "You have been ejected from "+capitalize(owner)+"'s room!\n");
  tell_object(obj, "You are escorted outside the Citadel.\n");
  move_object(obj, "players/pavlik/guild/room/gate");
  call_other(obj, "look", 0);
  return 1;
}

locker_object(str){
  object obj;
  string num;

  if(this_player()->query_real_name() != owner) return 0;
  if(!str){
	write("Locker what?\n");
	return 1;
  }
  if(preserve != 0){
	write("You have already preserved an item.\n");
	return 1;
  }
  obj = present(str, this_player());
  if(!obj){
	write("You do not have a "+str+".\n");
	write("You must have the object on your person.\n");
	return 1;
  }
  if(obj->query_save_flag() == 1){
	write(capitalize(str)+" cannot be stored.\n");
	return 1;
  }
  if((creator(obj)==0) || (obj->drop())){
	write(capitalize(str)+" cannot be stored.\n");
	if(this_player()->query_level() > 20) write("Creator is: "+creator(obj)+".\n");
	return 1;
  }
  sscanf(file_name(obj), "%s#%s", preserve, num);
  write("You take the "+str+" and carefully store it in your footlocker.\n");
  say(capitalize(owner)+" stores a "+str+" in "+this_player()->query_possessive()+
	" foot locker.\n");
  destruct(obj);
  do_save();
  return 1;
}

retrieve_object(){
  object obj;

  if(this_player()->query_real_name() != owner) return 0;
  if(preserve == 0){
	write("You do not have anything preserved.\n");
	return 1;
  }
  obj = clone_object(preserve);
  move_object(obj, this_player());
  write("You retrieve "+obj->short()+" from your footlocker.\n");
  say(capitalize(owner)+" gets "+obj->short()+" from a footlocker.\n");
  preserve = 0;
  do_save();
  return 1;
}

view_object(){
  object obj;
  if(this_player()->query_real_name() != owner){
	write("You don't see anything.\n");
	if(find_player(owner)) tell_object(find_player(owner),
		capitalize(this_player()->query_name())+" searched your room.\n");
	return 1;
  }
  if(preserve == 0){
	write("You do not have anything preserved.\n");
	return 1;
  }
  obj = clone_object(preserve);
  write("You have "+obj->short()+" stored in your footlocker.\n");
  destruct(obj);
  return 1;
}

cleanse_room() {
  if(this_player()->query_real_name() != owner) return 0;
  preserve = 0;
  do_save();
  write("You now have nothing preserved.\n");
  return 1;
}

