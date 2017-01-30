#define FILENAME "/players/feldegast/closed/tool/f-jikhal"
#include "/players/feldegast/defines.h"
inherit "obj/treasure";

object familiar;

reset() {
  set_id("familiar_ob");
  set_alias("bracelet");
  set_value(0);
  set_weight(0);
  set_long("This is a silver bracelet, studded with saphires and emeralds.  It is\n"+
           "used to control wizard familiars.\n"+
           "Commands:\n"+
           "  fquit              Send the familiar away\n"+
           "  fattack            Attack somebody with your familiar\n"+
           "  fstop              Stop attacking\n"+
           "  fsay               Have the familiar say something\n"+
           "  femote             Have the familiar emote something\n"+
           "  fcom               Have your familiar do a command\n"+
           "  flook              Look at the familiar's environment\n"+
           "  finvis             Make your familiar invis/vis\n"+
           "  fgoto              Send your familiar to someone\n"+
           "  folly              Have your familiar follow somebody\n"+
           "  ffile              Log all snoop information to a file\n"+
           "  fmuffle            Stop listening to your familiar\n"+
           "  fgive              give something\n"+
           "  fambush            move to and attack soembody\n"+
           "  fg,fge,fannounce   communicate\n"
        );
}
init() {

  if(TP->query_level()<20) destruct(this_object());

  add_action("fquit","fquit");
  add_action("fattack","fattack");
  add_action("fstop","fstop");
  add_action("fgoto","fgoto");
  add_action("finvis","finvis");
  add_action("fsnoop","fsnoop");
  add_action("folly","folly");
  add_action("ffile","ffile");
  add_action("fmuffle","fmuffle");
  add_action("fsay","fsay");
  add_action("femote","femote");
  add_action("flook","flook");
  add_action("fcom","fcom");
  add_action("fgossip","fgossip");
  add_action("fgossip","fg");
  add_action("fambush","fambush");
  add_action("fgossipe","fge");
  add_action("fannounce","fannounce");
  add_action("fclone","fclone");
  add_action("fgive","fgive");
  if(!familiar) {
    familiar=clone_object(FILENAME);
    familiar->set_owner(TP);
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
  target=find_object(str);
  if(target) {
    move_object(familiar,target);
    write("You send your familiar to "+target->short()+".\n");
    return 1;
  }
  write("Usage: fgoto <living>||<roompath>\n");
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
  tell_room(environment(familiar),familiar->query_name()+" has left the game.\n");
  if(familiar) {
    move_object(familiar,"/players/feldegast/closed/tower/study");
    destruct(familiar);
  }

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
  tell_room(room,"\n"+familiar->query_name()+" says: "+str+"\n");
  return 1;
}
femote(str) {
  object room;
  room=environment(familiar);
  if(!room) {
    write("Familiar has no environment!\n");
    return 1;
  }
  tell_room(room,familiar->query_name()+" "+str+"\n");
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
    familiar->set_follow(0);
    return 1;
  }
  familiar->set_follow(target);
  write("You send your familiar to follow "+target->query_name()+".\n");
  return 1;
}
ffile(str) {
  if(!str) {
    write("Log file set to null.\n");
    familiar->set_file(0);
    return 1;
  }
  familiar->set_file(str);
  write("You set the familiar's log file to "+str+".\n");
  return 1;
}
fmuffle() {
  familiar->set_muffle();
  return 1;
}
fgossip(str) {
  emit_channel("gossip",BOLD+WHT+"("+BLK+"gossip"+WHT+")"+NORM+" "+
    familiar->query_name()+" says: "+str+"\n");
  return 1;
}
fgossipe(str) {
  emit_channel("gossip",BOLD+WHT+"("+BLK+"gossip"+WHT+")"+NORM+" "+
    familiar->query_name()+" "+str+"\n");
  return 1;
}
fannounce(str) {
  emit_channel("gossip",familiar->query_name()+" announces: "+str+"\n");
  return 1;
}
ftell(str) {
  object ob;
  string target,msg;

  if(sscanf(str,"%s %s",target,msg) !=2) {
    write("Usage: ftell <player> <message>\n");
    return 1;
  }
  ob=find_player(target);
  if(!ob) {
    write("That player is not currently on.\n");
    return 1;
  }
  tell_object(ob,familiar->query_name()+" tells you: "+msg+"\n");
  ob->add_tellhistory(familiar->query_name()+" tells you: "+msg+"\n");
  write(familiar->query_name()+" tells "+ob->query_name()+": "+msg+"\n");
  return 1;
}
fclone(str) {
  object ob;
  if(!str) {
    write("Fclone what?\n");
    return 1;
  }
  ob=clone_object(str);
  if(!ob) {
    write("That object doesn't exist.\n");
    return 1;
  }
  write("Your familiar has cloned a "+str+".\n");
  move_object(ob,familiar);
  return 1;
}
fgive(str) {
  object ob, targ;
  string who,what;
  if(sscanf(str,"%s to %s",what,who)!=2) {
    write("Usage: fgive <what> to <who>\n");
    return 1;
  }
  ob=present(what,familiar);
  targ=find_living(who);
  if(!ob) {
    write("Your familiar does not possess "+what+".\n");
    return 1;
  }
  if(!targ) {
    write("That living is not logged in.\n");
    return 1;
  }
  write("Your familiar gives "+targ->query_name()+" a "+ob->short()+".\n");
  tell_object(targ,familiar->query_name()+" gives you a "+ob->short()+".\n");
  move_object(ob,targ);
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
fattack(str) {
  object targ;
  targ=present(str,environment(familiar));
  familiar->attack_object(targ);
  write("Your familiar attacks "+targ->query_name()+".\n");
  return 1;
}
fstop(str) {
  object targ;
  targ=familiar->query_attack();
  targ->attacked_by(0);
  familiar->attacked_by(0);
  tell_object(targ,familiar->query_name()+" steps back from his attack.\n");
  write("You order "+familiar->query_name()+" to retreat.\n");
  return 1;
}
fambush(str) {
  object targ;
  if(!str) return 0;
  targ=find_player(str);
  if(!targ) return 0;
  write("You ambush "+targ->query_name()+".\n");
  move_object(familiar, environment(targ));
  fattack(str);
  return 1;
}
