#define REALM call_other(environment(this_object()), "realm", 0)
#define capowner capitalize(owner)
#define Room tell_room(environment(this_object()),
#define nme this_object()->query_name()

inherit "/obj/monster";

int mount, follow_flag, busy_flag;
string bwho, variable, command_list, owner, message;
object bringer, target, thingy;

reset(arg) {
  ::reset();
  if(arg) return;
  set_name("C3P0");
  set_short("A protocol droid");
  set_alias("droid");
  set_ep(0);
  set_ac(3);
  set_wc(20);
  set_hp(175);
  call_out("hb", 2);
  set_dead_ob(this_object());
}

id(str) {
   return str =="droid" || str==variable;
}

monster_died() {
  object body,att;

  att = this_object()->query_attack();
  body = present("corpse",environment());
  if(body) destruct(body);
  tell_room(environment(), nme+" explodes in a rain of metal shards.\n");
  if(att) {
    tell_object(att, "A piece of the droid sticks in your flesh!.\n");
    att->hit_player(random(50));
  }
  return;
}
hb() {
  if(!owner) {
    destruct(this_object());
    return;
  }
  if(!find_player(owner)) {
    destruct(this_object());
    return;
  }
  call_out("hb", 300);
}

heart_beat() {
  ::heart_beat();
  if(follow_flag == 1 && busy_flag == 0) {
    if(environment(find_player(owner)) != environment(this_object())) {
      say(nme+" walks out of the room.\n");
      move_object(this_object(), environment(find_player(owner)));
      say(nme+" enters the room.\n");
    }
  }
}

set_variable(idstr) { variable=idstr; }
set_owner(ownstr) { owner = ownstr; }

long() {
  object ob;
  ob = this_player();
  if(ob->query_real_name() != owner || owner == 0) {
    write("A basic droid.\n");
  }
  if(ob->query_real_name() == owner) {
    write("A basic droid.\n"+
    "[HPS: "+this_object()->query_hp()+"]\n");
  }
}

init() {
  ::init();
  add_action("droid_follow","follow");
  add_action("release","release");
  add_action("transport","transport");
  add_action("SendMessage","message");
  add_action("help","help");
}

help(string str) {
  if(!str || str != "droid") return 0;
  write(pad("Command",25)+pad(" Function",50)+"\n");
  write(pad("",25,'-')+" "+pad("",50,'-')+"\n");
  write(pad("transport <what> to <who>",26)+pad("Carry the <what> to the person <who>",50));
  return 1;
}

release() {
  if(this_player()->query_real_name() == owner) {
    say(capowner+" removes "+nme+"'s restraning bolt.\n");
    destruct(this_object());
    return 1;
  }
}
 
droid_follow() {
  if(this_player()->query_real_name() == owner) {
    if(follow_flag == 0) {
      write(nme+" says: Yes master, we will follow you.\n");
      set_heart_beat(1);
      follow_flag = 1;
      return 1;
    }
    if(follow_flag == 1) {
      write(nme+" says: Yes master, we will stay here.\n");
        set_heart_beat(0);
        follow_flag = 0;
        return 1;
    }
  }
}
   
transport(str) {
  string who, what;
  if(this_player()->query_real_name() == owner) {
    if(!str) {
      write(nme+" says: You must tell us what object, and who to take it to.\n");
      return 1;
    }
    if(busy_flag) {
      write(nme+" says: I am already doing a command, master.\n");
      return 1;
    }
    sscanf(str, "%s to %s",what, who);
    if(!who || !what) {
      write(nme+" says: which item, and to who master?\n");
      return 1; }
    target=find_player(who);
    if(!target) {
      write(nme+" says: I can't find "+capitalize(who)+" master.\n");
      return 1; }
    thingy=present(what, this_object());
    if(!thingy) {
      write(nme+" says: I don't have a "+what+", master.\n");
      return 1; }
    say(nme+" walks out of the room.\n");
    busy_flag = 1;
    gototarget();
    return 1;
  }
}

SendMessage(str) {
  string who;
  if(this_player()->query_real_name() == owner) {
    if(!str) {
      write(nme+" says: Send what to whom, master?\n");
      return 1;
    }
    sscanf(str, "%s %s",who, message);
    if(!who || !message) {
      write(nme+" says: Send what to whom, master?\n");
      return 1; }
    target=find_player(who);
    if(!target) {
      write(nme+" says: I can't find "+capitalize(who)+" master.\n");
      return 1; }
    message = format(message, 50);
    write(nme+" says: As you wish, master.\n");
    busy_flag = 1;
    call_out("gototarget2",6);
    return 1;
  }
}
gototarget() {
  move_object(this_object(), environment(target));
  say(nme+" walks into the room.\n");
  move_object(thingy, target);
  say(nme+" says: A gift to you, "+capitalize(target->query_real_name())+" from my master, "+capowner+".\n");
  call_out("backtoowner",30);
  return 1; 
}

gototarget2() {
  if(!target) return;
  say(nme+" walks out of the room.\n");
  move_object(this_object(), environment(target));
  say(nme+" walks into the room.\n");
  say(nme+" says: My master, "+capowner+", has instructed me to deliver this\n"+
    "message to you, "+target->query_name()+".\n\n");
  say(message+"\n\n");
  call_out("backtoowner",random(30));
  return 1;
}
   
backtoowner() {
  say(nme+" walks out of the room.\n");
  move_object(this_object(), environment(find_player(owner)));
  say(capowner+"'s droid walks into the room.\n");
  busy_flag = 0;
  return 1;
}
   
is_pet() { return 1; }
query_owner() { return owner; }
