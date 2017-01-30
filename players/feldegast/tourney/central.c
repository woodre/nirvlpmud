#include "/players/feldegast/log/logs.h"
#include "def.h"

inherit AROOM;

mapping money; /* Temp money storage */
status vortex;
status lockers;
string *room_list;

is_arena_central() { return 1; }
query_spar_area() { return 1; }

void reset(int arg) {
  if(!present("table"))
    move_object(clone_object(PATH+"Obj/table.c"),this_object());
  if(arg) return;
  vortex=0; /* Vortex is closed at first. */
  set_light(1);
  set_no_fight(1);
  short_desc=BLK+BOLD+"Arena Central"+NORM;
  long_desc=
"  This massive triangular hall is the center of the grand arena.  In\n"+
"the center of the room is a solid stone table with a lifesized map of\n"+
"the battlefield on it.  Along one wall is a bank of lockers where\n"+
"excess money is kept.  On the west wall is a plaque describing the\n"+
"rules of engagement.  In front of the north wall, a swirling vortex\n"+
"of light leads to the battlefield.\n";
  items=({
    "hall",
"The floor of the hall is tiered so that the table at the center can\n"+
"be easily viewed.  The stone ceiling is easily ten meters above the\n"+
"hall's deepest point.  Each of the hall's three walls is thirty meters\n"+
"in length",
    "lockers",
"These lockers are for the temporary storage of coins in order to\n"+
"comply with spending limits inside the arena.  Please pick up your\n"+
"coins before reboot or they will be lost.\n"+
"Commands: deposit, withdraw, and inquire\n",
    "plaque",
"A huge bronze plaque plainly spells out the current rules of\n"+
"engagement.  You may 'read' it",
    "wall","The walls of the triangular hall are granite, and bare of\n"+
           "all adornment except for a bronze plaque and a row of lockers",
    "vortex","The vortex appears to be a swirling gateway of light and\n"+
             "shadow, perpendicular to the floor.  Through it, the combatants\n"+
             "will reach the battlefield.  You may 'enter vortex' when the\n"+
             "time is right"
  });
  dest_dir=({
    "/room/vill_green.c","leave",
  });
  money=([ ]);
  room_list=ROOMS;
}
int cmd_smell(string str) {
  write("You smell the stink of sweat and fear.\n");
  return 1;
}
int cmd_listen(string str) {
  write("Sounds reverberate throughout the great hall.\n");
  return 1;
}
void init() {
  ::init();
  add_action("cmd_read","read");
  add_action("cmd_enter","enter");
  add_action("cmd_deposit","deposit");
  add_action("cmd_withdraw","withdraw");
  add_action("cmd_inquire","inquire"); 
}  

cmd_read(str) {
  notify_fail("Read what?\n");
  if(str!="plaque" && str!="rules") return 0;
  cat(PATH+"rules.txt");
  return 1;
}

set_vortex(x) {
  vortex=x;
}
set_lockers(x) {
  lockers=x;
}

record_me() {
  object *obs;
  int i;
  string file;
  file = PATH+"Logs/"+TPRN;
  write_file(file, ctime(time())+"\n"+TPRN+
             "\nLevel: "+TP->query_level()+"+"+TP->query_extra_level()+"\n"+
             "Money: "+TP->query_money()+"\nExperience: "+TP->query_exp()+
             "\nInventory:\n");
  obs = deep_inventory(TP);
  for(i=0; i < sizeof(obs); i++) {
    write_file(file, "("+file_name(obs[i])+") "+obs[i]->short()+" ["+obs[i]->query_value()+"]\n");
  }
}

cmd_enter(str) {
  string dest;
  notify_fail("Enter what?");
  if(str!="vortex") return 0;
  if(!vortex) {
    write("The vortex is closed.\n");
    return 1;
  }
  if(TP->query_pl_k() < 2) {
    TP->set_pl_k("spar");
    if(TP->query_pl_k() < 2) {
      write("You try to step into the vortex, but fly right back out.\n");
      say(TPN+" tries to step into the vortex, but flies right back out.\n");
      return 1;
    }
  }
  write(
"You find yourself surrounded by a swirling kaleidoscope of "+HIW+"light\n"+NORM+
"and "+BLK+BOLD+"darkness"+NORM+".  When you blink, you find yourself in a different\n"+
"place.\n\n");
  say(TPN+" steps into the "+
      BLK+BOLD+"v"+HIW+"o"+BLK+BOLD+"r"+HIW+"t"+BLK+BOLD+"e"+HIW+"x"+NORM+".\n");
  switch(random(9)) { 
    case 0: dest=PATH+"m1";break;
    case 1: dest=PATH+"m2";break;
    case 2: dest=PATH+"m3";break;
    case 3: dest=PATH+"m4";break;
    case 4: dest=PATH+"m5";break;
    case 5: dest=PATH+"m6";break;
    case 6: dest=PATH+"m7";break;
    case 7: dest=PATH+"m8";break;
    case 8: dest=PATH+"m9";break;
  }
  move_object(TP,dest);
  TP->heal_self(500);
  record_me();
  say("A swirling vortex of "+HIW+"light"+NORM+" and "+BLK+BOLD+"darkness"+NORM+
      "whirls across the landscape.\n"+
      "When it leaves, "+TPN+" is here.\n");
  return 1;
}
cmd_deposit(str) {
  int amt;
  notify_fail("Usage: deposit <money>\n");
  if(!lockers) {
    write("The money lockers are only open for tournaments.\n");
    return 1;
  }
  if(!str) return 0;
  sscanf(str,"%d",amt);
  if(amt<1) return 0;
  if(TP->query_money()<amt) {
    write("You only have "+TP->query_money()+" coins.\n");
    return 1;
  }
  TP->add_money(-amt);
  money[this_player()->query_real_name()]+=amt;
  write_file(LOCKER_LOG,ctime(time())+" "+TPN+" +"+amt+"\n");
  write("You put "+amt+" coins into your bank.\n");
  return 1;
}
cmd_withdraw(str) {
  int amt;
  int temp;
  notify_fail("Usage: withdraw <money>\n");
  if(!str) return 0;
  sscanf(str,"%d",amt);
  if(amt<1) return 0;
  if(money[TP->query_real_name()]<amt) {
    write("You only have "+money[TP->query_real_name()]+" coins in your bank.\n");
    return 1;
  }
  write("You take "+amt+" coins out of your locker.\n");
  money[TP->query_real_name()]-=amt;
  TP->add_money(amt);
  write_file(LOCKER_LOG,ctime(time())+" "+TPN+" -"+amt+"\n");
  return 1;
}
cmd_inquire(str) {
  write("You have "+money[TP->query_real_name()]+" coins in your bank.\n");
  return 1;
}


query_rooms() {
  return room_list;
}

remove_room(str) {
  room_list-=({ str });
}

set_rooms(arg) {
  room_list = arg;
}
