#include "/players/feldegast/defines.h"
#define MAX_CMDS 5

inherit "/obj/living";

object owner;
int mounted;
int led;

reset(arg) {
  if(arg)return;
  level=1;
  weapon_class=3;
  armor_class=2;
  hit_point=150;
  max_hp=150;
  is_npc=1;
  owner=TP;
  name=owner->query_name()+"'s horse";
  cap_name=name;
  enable_commands();
}

init() {
  if(mounted)
    add_action("cmd_ride","ride");
  add_action("cmd_lead","lead");
  add_action("cmd_lead","hlead");
  add_action("cmd_tie","tie");
  add_action("cmd_mount","mount");
  add_action("cmd_dismount","dismount");
  add_action("cmd_pack","pack");
  add_action("cmd_unpack","unpack");
  add_action("look","look");
  add_action("look","l");
  add_action("cmd_dirs","directions");
}

short() {
  string shrt;
  shrt="A tall white horse";
  if(mounted) shrt+=" ridden by "+owner->query_name();
  if(TP && environment(TP)==environment(this_object())) return shrt;
  else return environment()->short();
}
long() {
  write("This is a tall white horse.\n");
}

id(str) {
  return str=="horse";
}

catch_tell(str) {
  if(mounted) tell_object(owner,str);
}

follow_hb() {
  if(!owner) {
    move_object(this_object(),"/players/feldegast/realm/void.c");
    destruct(this_object());
    return;
  }
  if(!led) {
    remove_call_out("follow_hb");
    return;
  }
  if(!present(this_object(),environment(owner))) {
    move_object(this_object(),environment(owner));
    tell_room(environment(owner),short()+" arrives.\n");
  }
  call_out("follow_hb",3);
  return;
}

look(str) {
  string item;
  if(!present(TP,this_object())) return 0;
  if(!str) {
    move_object(TP,environment(this_object()));
    TP->look();
    move_object(TP,this_object());
    return 1;
  }
  if(sscanf(str,"at %s",item)) {
    move_object(TP,environment(this_object()));
    TP->look("at "+item);
    move_object(TP,this_object());
    return 1;
  }
  if(sscanf(str,"in %s",item)) {
    move_object(TP,environment(this_object()));
    TP->look("in "+item);
    move_object(TP,this_object());
    return 1;
  }
}

command_list() {
  string *room_exits;
  string *cmd_list;
  int i;
  room_exits=environment(this_object())->query_dest_dir();
  cmd_list=allocate(sizeof(room_exits));
  if(room_exits)
    for(i=1;i < sizeof(room_exits);i+=2)
      cmd_list[i/2]=room_exits[i];
  cmd_list+=({"step rift","enter castle","enter portal"});    
  return cmd_list;
}

cmd_ride(str) {
  string com;
  notify_fail("Usage: ride dir1,dir2,etc.\n");
  if(!str) return 0;
  while(sscanf(str,"%s,%s",com,str)==2)
    if(member_array(com,command_list()) > -1) {
      command(com,this_object());
      command("look",TP);
      write("Command: "+com+"\n");
    }
    else {
      write("You can't go that way.  You stop your ride.\n");
      return 1;
    }
  if(member_array(str,command_list())) {
    command(str,this_object());
    command("look",TP);
    write("Command: "+str+"\n");
  }
  else {
    write("You can't go that way.  You stop your ride.\n");
    return 1;
  }
  return 1;
}

cmd_dirs() {
  string *dirs;
  int i;
  dirs=command_list();
  for(i=0; i < sizeof(dirs); i++)
    write(dirs[i]+",");
  write("\n");
  return 1;
}


cmd_drop(str) {
  object ob;
  notify_fail("Drop what?\n");
  if(!str) return 0;
  if(str=="all") {
    drop_all(TP);
    return 1;
  }
  ob=present(str,TP);
  if(!ob) return 0;
  if(ob->drop()) {
    notify_fail("You can't drop that.\n");
    return 0;
  }
  TP->add_weight(-(ob->query_weight()));
  move_object(ob,environment(this_object()));
  tell_room(environment(this_object()),TPN+" drops "+ob->short()+".\n");
  return 1;
}

/*
cmd_pack(str) {
  object ob,bag;
  bag=present("saddlebag",this_object());
  if(!bag) {
    bag=clone_object("/players/feldegast/obj/saddlebag");
    move_object(bag,this_object());
  }
  if(!str) {
    object ob;
    ob=first_inventory(pack);
    if(!ob)
      notify_fail("The horse pack is empty.\n");
    write("The horse pack contains:\n");
    while(ob) {
      string sh;
      sh=ob->short();
      if(sh)
        write("    "+sh+"\n");
      ob=next_inventory(ob);
    }
    return 1;
  }
  itemob=present(str,TP);
  if(!itemob)
    notify_fail("You do not have a "+str+".\n");
  if(itemob->drop())
    notify_fail("You cannot do that.\n");
  weight=itemob->query_weight();
  space=pack->query_weight();
  if(space+weight > MAX_WEIGHT) {
    notify_fail("There is not enough room.\n");
    return 1;
  }
  move_object(itemob,pack);
  pack->add_weight(weight);
  TP->add_weight(-weight);
  write("Ok.\n");
  return 1;
}

unpack(str) {
  object pack, itemob;
  int weight;
  pack=present("horse_pack",this_object());
  if(!pack) {
    pack=clone_object("/players/feldegast/obj/saddlebag");
    move_object(pack,this_object());
  }
  if(!str) {
    notify_fail("What would you like to unpack?\n");
    return 0;
  }
  weight=itemob->query_weight();
  if(!this_player()->add_weight(weight)) {
    notify_fail("You cannot carry any more.\n");
    return 0;
  }
  TP->add_weight(weight);
  pack->add_weight(-weight);
  move_object(itemob,TP);
  write("You take "+str+" from pack.\n");
  return 1;
}
*/

cmd_lead(str) {
  if(!str || !id(str)) return;
  if(mounted) {
    notify_fail("You must dismount your horse first.\n");
    return 0;
  }
  if(led) {
    notify_fail("Your warhorse is already following you.\n");
    return 0;
  }
  if(!owner) {
    write("There is no owner.\n");
    return 1;
  }

  led=1;
  write("Your horse will now follow you.\n");
  call_out("follow_hb", 3);
  return 1;
}

cmd_tie(str) {
  if(!led) {
    notify_fail("Your warhorse is already tied off.\n");
    return 1;
  }
  if(str=="off" || str=="off horse") {
    led=0;
    write("Your horse is now tied off.\n");
    remove_call_out("follow_hb");
    return 1;
  }
}

cmd_mount(str) {
  if(str && !id(str))
    return 0;
  if(led) {
    notify_fail("You must tie off your horse before you can mount it.\n");
    return 0;
  }
  if(mounted) {
    notify_fail("You are already mounted on your horse.\n");
    return 0;
  }
  if(TP->query_attack()) {
    notify_fail("You can't mount your horse while fighting.\n");
    return 0;
  }
  mounted=1;
  write("You mount the horse.\n");
  TP->remote_say(TPN+" mounts the horse.\n");
  move_object(TP,this_object());
  return 1;
}

cmd_dismount(str) {
  if(str && !id(str))
    return 0;
  if(!mounted) {
    notify_fail("You are not mounted on your horse.\n");
    return 0;
  }
  if(query_attack()) {
    notify_fail("You cannot dismount your horse while in combat.\n");
    return 0;
  }
  mounted=0;
  write("You dismount from your horse.\n");
  move_object(TP,environment(this_object()));
  TP->remote_say(TPN+" dismounts from the horse.\n");
  return 1;
}

