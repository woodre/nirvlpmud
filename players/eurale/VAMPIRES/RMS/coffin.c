inherit "room/room";
#include "/players/eurale/defs.h"
#include "check.h"
string coffin_owner_name,new_coffin_description,coffin_description,str;

set_coffin_owner_name(str) { coffin_owner_name = str; }
query_coffin_owner_name() { return coffin_owner_name; }

reset(arg) {
  if(arg) return;
if(!present("shelf")) {
move_object(clone_object("players/eurale/VAMPIRES/OBJ/coffin_shelf"),TO); }
set_light(-1);
coffin_description = "Your private coffin.";

items = ({
  "plate","A small plate with lettering screwed to the wood of the\n"+
          "coffin.  Perhaps you could read it",
});
}

is_castle() { return 1; }
clean_up() { return 0; }
realm() { return "NT"; }

short() { return capitalize(coffin_owner_name)+"'s coffin"; }

long(str) {
  if(!str) {
  write(coffin_description+"\n"+
  "A long rectangular wooden coffin filled with rich, dark earth.  The\n"+
  "curved top fits tightly against the sides shutting out all the light\n"+
  "and sound. Attached to the wall at the foot of the coffin is a small\n"+
  "plate and a narrow shelf circles the top.\n");
  } else {
    if(member_array(str,items) != -1) {
    write(items[member_array(str,items)+1]);
  write("\n");
   } else write("That is not here.\n");
}
}

init() {
 ::init();
if(environment(TP) == TO) {
if(TP->is_player() && TPRN == coffin_owner_name) {
  if(!present("coffin_ob",TP) && PFANGS->query_STORAGE())
    move_object(clone_object("players/eurale/VAMPIRES/OBJ/coffin_obj"),TP);
  add_action("buy","buy");
  add_action("decorate_coffin","decorate");
  add_action("invite","invite");
  add_action("revoke","revoke");
  add_action("eject","eject");
  add_action("out","out");
  add_action("read","read");
  restore_object("players/eurale/VAMPIRES/RMS/coffins/"+coffin_owner_name);
}
  add_action("out","out");
  add_action("read","read");
}
}

out() {
  say(
    capitalize(TPRN)+" opens the coffin lid and leaves.\n");
  write("You open the lid and leave the coffin.\n");
  TP->move_player("out#players/eurale/VAMPIRES/RMS/basement.c");
  return 1; }

read(str) {
if(!str) { write("Read what?\n"); return 1; }
if(str != "plate") {
  write("You don't see that here.\n");
  return 1; }
write("A small, metal plate which reads:\n"+
      "Manufactured by Eurale Enterprise, Inc., 1999.\n"+
      "  storage commands: buy, list, retrieve, store\n"+
      "  decorate coffin - allows you to write your own coffin description\n"+
      "  invite <who>    - invites a vamp in\n"+
      "  revoke <who>    - revokes the invitation\n"+
      "  eject <who>     - user ushered 'out' of your coffin\n"+
      "  out             - leave your coffin\n\n"+
      "Problems - Contact Eurale via mud mail.\n");
return 1;
}

decorate_coffin(str) {
if(!str || str != "coffin") return;
input_to("get_description");
write(
  "Enter the new description of your coffin interior.  Terminate your\n"+
  "description with '**'.  Abort with '~q'.\n");
write(">");
new_coffin_description = "";
return 1;
}

get_description(str) {
if(str == "~q") { write("Aborting..\n"); return 1; }
if(str == "**") {
  coffin_description = new_coffin_description;
  new_coffin_description = 0;
  save_object("players/eurale/VAMPIRES/RMS/coffins/"+coffin_owner_name);
  write("OK.\n");
  return;
}
new_coffin_description = new_coffin_description+str+"\n";
write(">");
input_to("get_description");
}

exit() {
object CO;
CO = present("coffin_ob",TP);
if(CO) destruct(CO);
}
    
invite(str) {
  object who,invitation;

if(!str) {
  write("Who would you like to invite?\n"); return 1; }

who = find_player(str);

if(who->query_level() > 20) {
  write("Wizards cannot be invited into coffins.\n");
  return 1; }

if(!who) {
  write(capitalize(str)+" isn't logged on...\n");
  return 1; }

if(who->query_invis() > 0) {
  write(capitalize(str)+" doesn't appear to be logged on.\n");
  return 1; }

if(present("coffin invitation",who)) {
  write(capitalize(str)+" already has an invitation.\n");
  return 1; }

if(!present("vampire fangs",who)) {
  write("Only vampires can be invited into your coffin.\n");
  return 1; }

invitation = clone_object("players/eurale/VAMPIRES/OBJ/invitation.c");
invitation->set_coffin_owner(coffin_owner_name);
move_object(invitation,who);
tell_object(who,
  "You have been given an invitation into "+
  capitalize(TPRN)+"'s coffin.\n"+
  "You can either 'accept invitation' or get rid of it by dropping it.\n");
write(capitalize(str)+" has been invited into your coffin.\n");
return 1;
}

revoke(str) {
  object who,invitation;

if(!str) { write("Revoke who's invitation?\n"); return 1; }

who = find_player(str);
if(!who) {
  write(capitalize(str)+" isn't logged on...\n");
  return 1; }

invitation = present("invitation",who);
if(!invitation) {
  write(capitalize(str)+" doesn't have an invitation.\n");
  return 1; }

destruct(invitation);
tell_object(who,
  "Your invitation to "+capitalize(TPRN)+"'s coffin has been revoked.\n");
write(HIR+capitalize(str)+"'s invitation has been revoked.\n"+NORM);
return 1;
}

eject(str) {
  object who;

if(TPRN != coffin_owner_name) {
  write("Only "+capitalize(coffin_owner_name)+
    " can use that command here.\n");
  return 1; }

if(!str) { write("Eject who?\n"); return 1; }

who = present(str,TO);
if(!who) {
  write(capitalize(str)+" isn't here.\n");
  return 1; }

command("out",who);
write("You eject "+capitalize(str)+" from your coffin.\n");
return 1;
}

buy(str) {

if(TPRN != coffin_owner_name) {
  write("Only the coffin owner can do that here.\n");
  return 1; }

if(!str || str != "storage") { write("Buy what?\n"); return 1; }

if(PFANGS->query_STORAGE()) {
  write("You already have storage space in your coffin.\n");
  return 1; }

if(TP->query_money() < 40000) {
  write("You lack the funds to do that.\n");
  return 1; }

write("You buy some storage space in your coffin\n");
TP->add_money(-40000);
PFANGS->set_STORAGE(1);
move_object(clone_object("players/eurale/VAMPIRES/OBJ/coffin_obj"),TP);
return 1;
}
