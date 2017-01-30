#include "/players/feldegast/defines.h"
#define FAMILIAR_FILE "/players/feldegast/closed/tool/raven.c"
inherit "obj/treasure";

object familiar;

reset() {
  set_id("familiar_ob");
  set_alias("bracelet");
  set_long("This is a silver bracelet, studded with saphires and emeralds.  It is\n"+
           "used to control wizard familiars.\n"+
           "Commands:\n"+
           "  fquit              Send the familiar away\n"+
           "  fsay               Have the familiar say something\n"+
           "  femote             Have the familiar emote something\n"+
           "  fcom               Have your familiar do a command\n"+
           "  flook              Look at the familiar's environment\n"+
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
remove_object() { destruct(familiar); }
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
  add_action("flook","flook");
  if(!familiar) {
    familiar=clone_object(FAMILIAR_FILE);
    move_object(familiar,environment(TP));
  }
}
fgoto(str) {
  object target;
  target=find_living(str);
  if(target) {
    move_object(familiar,environment(target));
    write("You send your familiar to watch "+capitalize(str)+"'s room.\n");
    return 1;
  }
  write("Usage: fgoto <living>\n");
  return 1;
}
finvis() {
  if(!familiar) {
    write("Something has happened to your familiar.\n");
    return 1;
  }
  familiar->go_invis();
  write("You cast a spell of invisibility on your familiar.\n");
  return 1;
}
fquit() {
  write("You dismiss your familiar.\n");
  if(familiar) destruct(familiar);
  destruct(this_object());
  return 1;
}
fsay(str) {
  object room;
  room=environment(familiar);
  if(!room) {
    write("No environment for familiar.\n");
    return 1;
  }
  familiar->communicate(str);
  return 1;
}
femote(str) {
  object room;
  room=environment(familiar);
  if(!room) {
    write("familiar has no environment!\n");
    return 1;
  }
  familiar->emote(str);
  return 1;
}
fsnoop() {
  familiar->set_snooping();
  write("You toggle the familiar's snooping ability(Nosy!).\n");
  return 1;
}
folly(str) {
  object target;
  target=find_living(str);
  if(!target) {
    write("That living does not exist.\n");
    return 1;
  }
  familiar->set_follow(target);
  write("You send your familiar to follow "+target->query_name()+".\n");
  return 1;
}
ffile(str) {
  familiar->set_file(str);
  write("You set the familiar's log file to "+str+".\n");
  return 1;
}
fmuffle() {
  familiar->set_muffle();
  return 1;
}
fcom(str) {
  write("You command your familiar to '"+str+"'.\n");
  command(str,familiar);
  return 1;
}
flook() {
  object ob;
  string shrt;
  write(environment(familiar)->short()+" <L: "+familiar->query_light()+">\n");
  environment(familiar)->long();
  ob=first_inventory(environment(familiar));
  while(ob) {
    shrt=ob->short();
    if(!shrt) shrt=file_name(ob);
    write(shrt+".\n");
    ob=next_inventory(ob);
  }
  return 1;
}
