/*
 guild_coffin.c
*/

inherit "room/room";
inherit "players/nooneelse/black/new_guild_rooms";
#include "lib/defs.h"

string coffin_owner_name, new_coffin_description, str;
string coffin_description;
reset() {
  call_out("asdfghjkl",5);
}

init() {
  ::init();

  add_action("invite_guest",       "invite");
  add_action("extra_heal",         "asdfghjkl");
  add_action("revoke_invitation", "revoke");
  add_action("eject_someone",      "eject");
  add_action("leave_coffin",       "out");
  add_action("decorate_coffin",    "decorate");
  check_membership(this_player());
  if (file_size("/players/nooneelse/black/coffins/"+coffin_owner_name+".o")>=1)
    restore_object("players/nooneelse/black/coffins/"+coffin_owner_name);
}

invite_guest(str) {
  object target_obj, invitation_obj;
  if (!str) {
    write("Invite who into the coffin?\n");
    return 1;
  }
  target_obj=find_player(str);
  if (target_obj &&
      target_obj->query_invis() > 0 &&
      target_obj->query_level() >= 21) {
    write(capitalize(str)+" can't be found to deliver an invitation to.\n");
    return 1;
  }
  if (!target_obj) {
    write(capitalize(str)+" isn't playing right now.\n");
    return 1;
  }
  if (present("invitation", target_obj)) {
    write(capitalize(str)+" already has an invitation.\n");
    return 1;
  }
/*@@@@@@@@@@@@@@@@@@
  if (!present("vampire fangs", target_obj)) {
    write("Only vampires can be invited into the coffins.\n");
    return 1;
  }
@@@@@@@@@@@@@@@@@*/
  invitation_obj=
    clone_object("/players/nooneelse/black/guild_coffin_invitation");
  invitation_obj->set_coffin_owner(coffin_owner_name);
  move_object(invitation_obj, target_obj);
  tell_object(target_obj,
              "You have been given an invitation to "+
              this_player()->query_name()+"'s coffin\n"+
              "You can either use it by typing 'accept invitation' or\n"+
              "get rid of it by dropping it.\n");
  write(capitalize(str)+" has been given an invitation to your coffin.\n");
  return 1;
}

revoke_invitation(str) {
  object target_obj, target_invitation;
  if (!str) {
    write("Revoke who's invitation?\n");
    return 1;
  }
  target_obj=find_player(str);
  if (!target_obj) {
    write(capitalize(str)+" isn't playing right now.\n");
    return 1;
  }
  target_invitation=present("invitation", target_obj);
  if (!target_invitation) {
    write(capitalize(str)+" doesn't have an invitation.\n");
    return 1;
  }
  destruct(target_invitation);
  tell_object(target_obj,
              "Your invitation to "+this_player()->query_name()+"'s coffin "+
              "has been revoked.\n");
  write(capitalize(str)+"'s invitation has been revoked.\n");
  return 1;
}

eject_someone(str) {
  object target_obj;
  if (this_player()->query_real_name() != coffin_owner_name) {
    write("Only "+capitalize(coffin_owner_name)+
          " can use the eject command here.\n");
    return 1;
  }
  if (!str) {
    write("Eject who?\n");
    return 1;
  }
  target_obj=present(str, this_object());
  if (!target_obj) {
    write("But, "+capitalize(str)+" isn't here!\n");
    return 1;
  }
  command("out", target_obj);
  write("Ok, they're gone.\n");
  return 1;
}

leave_coffin(str) {
  object coffin_owner_obj, coffin_room_obj;
  if (!present("vampire fangs", this_player())) {
    call_other("players/nooneelse/blackentry", "???", 0);
    coffin_room_obj=find_object("players/nooneelse/blackentry");
    tell_object(coffin_room_obj,
                "There is a flash of light.  When your eyes refocus, you see\n"+
                this_player()->query_name()+" standing in front of you.\n");
    move_object(this_player(), coffin_room_obj);
    command("look", this_player());
    return 1;
  }
  call_other("players/nooneelse/black/guild_coffin_room", "???", 0);
  coffin_room_obj=find_object("players/nooneelse/black/guild_coffin_room");
  tell_object(coffin_room_obj, this_player()->query_name()+" steps out of "+
              "a coffin.\n");
  move_object(this_player(), coffin_room_obj);
  command("look", this_player());
  return 1;
}

decorate_coffin(str) {
  if (!str || str != "coffin") return;
  input_to("get_description");
  write("Enter the new description of the interior of your coffin.\n"+
        "Terminate with '**'.  Abort with '~q'.\n");
  write("]");
  new_coffin_description="";
  return 1;
}

get_description(str) {
  if (str=="~q") {
    write("Aborting.\n");
    return;
  }
  if (str=="**") {
    coffin_description = new_coffin_description;
    new_coffin_description=0;
    save_object("players/nooneelse/black/coffins/"+coffin_owner_name);
    write("Ok.\n");
    return;
  }
  new_coffin_description = new_coffin_description+str+"\n";
  write("]");
  input_to("get_description");
}

reset(arg) {
  if (arg) return;

  set_light(1);
  coffin_description="Your private coffin.";
  dest_dir =
    ({
      "players/nooneelse/black/guild_coffin_room", "out",
    });
  no_castle_flag=1;
  move_object(clone_object("players/nooneelse/black/guild_coffin_shelf"),
              this_object());
  move_object(clone_object("players/nooneelse/black/coffin_bed"),
              this_object());
  move_object(clone_object("players/nooneelse/black/coffin_sunlamp"),
              this_object());
  call_out("asdfghjkl",5);

}

is_castle() { return 1; }

short() { return capitalize(coffin_owner_name)+"'s coffin"; }

long() {
  write(coffin_description+"\n"+
        "\nYou can invite another vampire here with 'invite <who>'\n"+
        "or you can revoke an invitation with 'revoke <who>'\n"+
        "(the revoke only works if you use it before they accept.)\n"+
        "You can 'eject <who>' if someone is here that you don't\n"+
        "want to be here anymore.\n"+
        "Now you can give your coffin a new interior description with\n"+
        "'decorate coffin'.\n");
}
set_coffin_owner_name(str) { coffin_owner_name=str; }
query_coffin_owner_name() { return coffin_owner_name; }

id(str) { return str=="coffin" ||
                 str=="guild coffin"; }

realm() { return "NT"; }
