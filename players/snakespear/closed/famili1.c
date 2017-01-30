#include "/players/snakespear/closed/defines.h"
inherit "obj/treasure";

object djinn;

reset() {
  set_alias("bracelet");
  set_short("A bracelet");
  set_long("This is a silver bracelet, studded with saphires and emeralds.  It is\n"+
           "used to control wizard familiars.\n"+
           "Commands:\n"+
           "  fquit              Send the familiar away\n"+
           "  fsay               Have the familiar say something\n"+
           "  femote             Have the familiar emote something\n"+
           "  fcom               Have your familiar do a command\n"+
           "  finvis             Make your familiar invis/vis\n"+
           "  fgoto              Send your familiar to someone\n"+
           "  folly              Have your familiar follow somebody\n"+
           "  ffile              Log all snoop information to a file\n"+
           "  fmuffle            Stop listening to your familiar\n");
     
  set_value(0);
  set_weight(1);
}
extra_look() {
  return environment()->query_name()+" wears a silver bracelet";
}

init() {
  if(TP->query_level()<20) destruct(this_object());
  add_action("fquit","fquit");
  add_action("fgoto","fgoto");
  add_action("finvis","finvis");
  add_action("fsnoop","fsnoop");
  add_action("folly","folly");
  add_action("ffile","ffile");
  add_action("fmuffle","fmuffle");
  add_action("fsay","fsay");
  add_action("femote","femote");
  add_action("fcom","fcom");
  if(!djinn) {
    djinn=clone_object("/players/snakespear/closed/djinn.c");
    move_object(djinn,environment(TP));
  }
}
fgoto(str) {
  object target;
  target=find_living(str);
  if(target) {
    move_object(djinn,environment(target));
    write("You send your familiar to watch "+capitalize(str)+"'s room.\n");
    return 1;
  }
  write("Usage: fgoto <living>\n");
  return 1;
}
finvis() {
  if(!djinn) {
    write("Something has happened to your familiar.\n");
    return 1;
  }
  djinn->go_invis();
  write("You cast a spell of invisibility on your familiar.\n");
  return 1;
}
fquit() {
  write("You dismiss your familiar.\n");
  if(djinn) destruct(djinn);
  destruct(this_object());
  return 1;
}
fsay(str) {
  object room;
  room=environment(djinn);
  if(!room) {
    write("No environment for djinn.\n");
    return 1;
  }
  tell_room(room,"Harry says: "+str+"\n");
  return 1;
}
femote(str) {
  object room;
  room=environment(djinn);
  if(!room) {
    write("Djinn has no environment!\n");
    return 1;
  }
  tell_room(room,"Harry "+str+"\n");
  return 1;
}
fsnoop() {
  djinn->set_snooping();
  write("You toggle the djinn's snooping ability(Nosy!).\n");
  return 1;
}
folly(str) {
  object target;
  target=find_living(str);
  if(!target) {
    write("That living does not exist.\n");
    return 1;
  }
  djinn->set_follow(target);
  write("You send your familiar to follow "+target->query_name()+".\n");
  return 1;
}
ffile(str) {
  djinn->set_file(str);
  write("You set the djinn's log file to "+str+".\n");
  return 1;
}
fmuffle() {
  djinn->set_muffle();
  return 1;
}
fcom(str) {
  write("You command your familiar to '"+str+"'.\n");
  command(str,djinn);
  return 1;
}
