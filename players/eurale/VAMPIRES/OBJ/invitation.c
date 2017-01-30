/*
  guild_coffin_invitation.c
*/

inherit "obj/treasure";

string coffin_owner_name, str;

init() {
  add_action("accept_invitation", "accept");
  add_action("drop", "drop");
  add_action("drop", "give");
  add_action("quit", "quit");
}

accept_invitation(str) {
  object target_obj;
  string str1, str2, str3;
  int i;

if(!str || str != "invitation") return;

target_obj = find_player(coffin_owner_name);
if(!target_obj) {
  write(capitalize(coffin_owner_name)+
      " is no longer playing.  Invitation revoked.\n");
  destruct(this_object());
  return 1; }

str1 = file_name(environment(target_obj));
sscanf(str1, "%s#%d", str2, i);
if(str2 != "players/eurale/VAMPIRES/RMS/coffin") {
  write(capitalize(coffin_owner_name)+
        " must be in their coffin for the invitation to work.\n");
  return 1; }

str1 = file_name(environment(this_player()));
if(present("vampire fangs", this_player())) {
  if(str1 != "players/eurale/VAMPIRES/RMS/basement") {
    write("You must be in the basement for the invitation to work.\n");
  return 1; }
  }

say(this_player()->query_name()+" glows for a moment, then disappears.\n",
      this_player());
move_object(this_player(), environment(target_obj));
write("You are transported to "+capitalize(coffin_owner_name)+"'s coffin.\n");
if(this_player()->query_brief())
  tell_object(this_player(), environment(this_player())->short()+".\n");
else
  command("look", this_player());
tell_object(target_obj, this_player()->query_name()+
            " has accepted your invitation and is now here.\n");
destruct(this_object());
return 1;
}

drop(str) {
  string str2;
  str2=0;

if(str) sscanf(str, "invitation%s", str2);
if(str == "invitation" || str == "all" || str2) {
  write("As you drop your coffin invitation, it crumbles to dust.\n");
  say("As "+this_player()->query_name()+
      " drops a piece of black paper, it crumbles to dust.\n");
  destruct(this_object());
  if(str == "invitation") return 1;
  if(str == "all") return;
  }
}

quit(str) {
  drop("invitation");
  return;
}

reset(arg) {
  if (arg) return;

  set_value(0);
  set_weight(1);
}

short() {
  if (coffin_owner_name)
    return "An invitation from "+capitalize(coffin_owner_name);
  else
    return "An invitation from someone";
}

long() {
  if (present("vampire fangs", this_player())) {
    write(short()+".\n"+
          "You have been given an invitation to "+
          capitalize(coffin_owner_name)+"'s coffin.\n"+
          "You can either use it by typing 'accept invitation' while in the\n"+
          "coffin room or get rid of it by dropping it.\n");
  }
  else {
    write(short()+".\n"+
          "You have been given an invitation to "+
          capitalize(coffin_owner_name)+"'s coffin.\n"+
          "You can 'accept invitation' in the basement or drop it.\n");
  }
}

prevent_insert() {
  write("You don't really want to hide your invitation do you?\n");
  return 1;
}

set_coffin_owner(str) { coffin_owner_name=str; }

id(str) { return (str=="invitation" ||
                  str==coffin_owner_name+" invitation" ||
                  str=="coffin invitation"); }
