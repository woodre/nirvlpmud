#include "def.h"
#define MAX_HEALS 10000
#include "_phase.h"
inherit "obj/weapon";


reset(arg) {
  if(arg) return;
  set_name("staff");
  set_type("staff");
  set_short(HIM+"Staff"+NORM+" of "+HIY+"Ceremonies"+NORM);
  set_long(
"This is the official staff of the master of ceremonies at a Nirvana tournament\n"+
"or arena event.  It is a tall pole with a gold spiral along it's entire length\n"+
"that leads up to a silver eagle in flight on the head.\n"+
"Commands:\n"+
"  central\n"+
"  renew battlefield\n"+
"  load battlefield\n"+
"  peace battlefield\n"+
"  negate battlefield\n"+
"  negate peace\n"+
"  open vortex\n"+
"  close vortex\n"+
"  create portal\n"+
"  legal check\n"+
"  deepi <player>\n"+
"  remove <m?>\n"+
"  list_rooms\n"+
"");
  set_weight(5);
  set_value(15000);
  set_class(25);
}
init() {
  ::init();
  add_action("cmd_central","central");
  add_action("cmd_open","open");
  add_action("cmd_close","close");
  add_action("cmd_peace","peace");
  add_action("cmd_phase","phase");
  add_action("cmd_negate","negate");
  add_action("list_rooms","list_rooms");
  add_action("cmd_load","load");
  add_action("cmd_renew","renew");
  add_action("cmd_create","create");
  add_action("cmd_legal","legal");
  add_action("cmd_deepi","deepi");
  add_action("remove_room","remove");
/* Incorporated into 'legal'
  add_action("heal_check","heal_check");
  add_action("heal_count","heal_count");
*/
}
cmd_central() {
  write("You teleport to arena central.\n");
  say(TPN+" raises "+TP->query_possessive()+" staff high in the air and utters a word\n"+
      "of power.  Forks of "+HIB+"l i g h t n i n g"+NORM+" blind you.  When you\n"+
      "can see again, "+TPN+" is gone.\n");
  move_object(TP,PATH+"central");
  say(TPN+" steps out of the vortex.\n");
  return 1;
}
cmd_renew(str) {
  notify_fail("Renew what?\n");
  if(!str) return 0;
  if(str!="battlefield") return 0;
  process_rooms("reset",1);
  write("You renew the battlefield.\n");
  say(TPN+" waves the "+short_desc+" twice around the room and utters a few\n"+
      BOLD+"Words of Power"+NORM+".  You sense that something has changed.\n");
  return 1;
}
cmd_load(str) {
  notify_fail("Load what?\n");
  if(!str) return 0;
  if(str!="battlefield") return 0;
  process_rooms("??");
  write("You load the battlefield.\n");
  say(TPN+" waves the "+short_desc+" thrice around the room and utters a few\n"+
      HIM+"Words of Power"+NORM+".  You sense that something has changed.\n");
  return 1;
}
process_rooms(str, mixed x) {
  string *rooms;
  string room;
  int i;
  for(i=0; i<12; i++) {
    rooms=ROOMS;
    room=rooms[i];
    if(x) call_other(PATH+room,str,x);
    else call_other(PATH+room,str);
  }
}
cmd_peace(str) {
  notify_fail("Peace what?\n");
  if(!str) return 0;
  if(str!="battlefield") return 0;
  process_rooms("set_no_fight",1);
  write("You make the battlefield peaceful.\n");
  say(TPN+" waves the "+short_desc+" and you feel a sense of peace and calm.\n");
  return 1;
}
cmd_negate(str) {
  notify_fail("Negate what?\n");
  if(!str) return 0;
  if(str=="peace") {
    process_rooms("set_no_fight",0);
    write("You negate the peace spell on the battlefield.\n");
    say(TPN+" waves the "+short_desc+" and negates the aura of peace.\n");
    return 1;
  }
  if(str=="magic") {
    process_rooms("set_no_magic",1);
    write("You cast a null magic aura across the battlefield.\n");
    say(TPN+" waves the "+short_desc+".\nYou suspect "+TP->query_pronoun()+" just did something sinister.\n");
    return 1;
  }
}
cmd_open(str) {
  notify_fail("Open what?\n");
  if(str!="vortex") return 0;
  call_other(PATH+"central","set_vortex",1);
  write("You open the vortex.\n");
  say(TPN+" raises the "+short_desc+" above "+TP->query_possessive()+" head and\n"+
      "quietly utters a word of power.\n");
  tell_room(PATH+"central","With a burst of light, the vortex swirls open.\n");
  return 1;
}
cmd_close(str) {
  notify_fail("Close what?\n");
  if(str!="vortex") return 0;
  call_other(PATH+"central","set_vortex",0);
  write("You close the vortex.\n");
  say(TPN+" raises the "+short_desc+" above "+TP->query_possessive()+" head and\n"+
      "quietly utters a word of power.\n");
  tell_room(PATH+"central","With a flash of light, the vortex dilates shut.\n");
  return 1;
}
cmd_create(str) {
  object portal;
  notify_fail("Create what?\n");
  if(!str || str!="portal") return 0;
  portal=clone_object("/players/feldegast/obj/azure_portal.c");
  portal->set_destination(PATH+"central");
  move_object(portal,environment(TP));
  write("You raise your ceremonial staff high in the air and intone the Words\n"+
        "of Power.\n");
  say(TPN+" raises "+TP->query_possessive()+" staff high in the air and intones a\n"+
        "few "+BOLD+"Words of Power"+NORM+".\n");
  tell_room(environment(TP),portal->short()+" slowly opens out of thin air.\n");
  return 1;
}
cmd_legal(str) {
  object *world;
  int i;
  int heals;
  string pk;
  int alarm;
  notify_fail("Check what?\n");
  world=users();
  write(
pad("Name",15)+pad("Money",10)+pad("Status",10)+pad("Heals",10)+pad("Illegal",10)+"\n");

  for(i=0; i<sizeof(world); i++) {
    if(environment(world[i]))
    if(environment(world[i])->query_grand_arena()) {
    write(pad(capitalize(world[i]->query_real_name()),15));
    write(pad(world[i]->query_money(),10));
    switch(world[i]->query_pl_k()) {
      case 0: pk="None";
              break;
      case 1: pk="Pk";
              break;
      case 2: pk="Spar";
              break;
      case 3: pk="Spar/Pk";
              break;
    }
    write(pad(pk,10));

    heals=heal_count(world[i]);
    if(heals)
      write(pad(heals,10));
    else
      write(pad("Good",10));

    if(!heal_check(world[i]))
      write(pad("Good",10));
    else
      write(pad("BAD",10));

    write("\n");
    }
  }
  return 1;
}
heal_check(ob) {
  object *inventory;
  string *illegal;
  int i;
  int alarm;
#include "illegal.h"
  if(!ob) { write("Player not found.\n"); return 1; }
  inventory=deep_inventory(ob);
  for(i=0; i<sizeof(inventory); i++) {
    string name;
    string junk;
    name=file_name(inventory[i]);
    sscanf(name,"%s#",name);
    if(member_array(name,illegal)>-1) {
      write(inventory[i]->short()+" found!\n");
      alarm=1;
    }
  }  
  return alarm;
}
heal_count(ob) {
  mapping heals;
  object *inventory;
  int total;
  int i;
#include "heal_list.h"
  if(!ob) { write("Player not found.\n"); return 1; }
  inventory=deep_inventory(ob);
  for(i=0; i<sizeof(inventory); i++) {
    string name;
    string junk;
    name=file_name(inventory[i]);
    sscanf(name,"%s#",name);
    if(heals[name]) {
      total+=heals[name];
    }
    else
      if(ob->is_heal())
        write("Unlisted heal: "+ob->short()+".\n");
  }
  if(total > MAX_HEALS) return total;
  else return 0;
}
cmd_deepi(str) {
  object *inv;
  object targ;
  int i;
  notify_fail("Usage: deepi <player>\n");
  if(!str) return 0;
  targ=present(str,environment(TP));
  if(!targ) return 0;
  inv=deep_inventory(targ);
  for(i=0; i<sizeof(inv); i++) {
    write(file_name(inv[i])+" ");
    if(inv[i]->short()) write(inv[i]->short());
    write("\n");
  }
  return 1;
}

remove_room(str) {
  object target,ob;
  object next;
  if(!str) {
    notify_fail("Remove what room?\n");
    return 0;
  }
  target=find_object(PATH+str);
  if(!target) {
    notify_fail("Target room can't be found.\n");
    return 0;
  }
  process_rooms("remove_exit",str);
  write("Removing exits...\n");

  MASTER->del_room(str);

  ob=first_inventory(target);
  while(ob) {
    next=next_inventory(ob);
    if(living(ob)) {
      tell_room(target,
"Kazanth, the black dragon swoops down and snatches "+ob->query_name()+"\n"+
" off the ground.\n",({ ob }));
      tell_object(ob,
"Kazanth, the black dragon swoops down and snatches you off the\n"+
"ground.  A few minutes later, he drops you somewhere else.\n");
      move_object(ob,PATH+(MASTER->query_rooms())[random(sizeof(MASTER->query_rooms()))]);
      tell_room(environment(ob),
"Kazanth, the black dragon swoops down and drops "+ob->query_name()+"\n"+
"roughly on the ground.\n", ({ ob }) );
      write("Moving "+ob->query_name()+"...\n");
    }
    ob=next;
  }
  list_rooms();
  target->arena_channel(
    "Kazanth, the black dragon ravages "+target->short()+".\n");
  return 1;
}
list_rooms() {
  int i;
  for(i=0; i < sizeof(MASTER->query_rooms()); i++) {
    write((MASTER->query_rooms())[i]+"\n");
  }
  return 1;
}
