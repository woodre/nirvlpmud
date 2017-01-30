#include "/room/clean.c"

#define CASINO "players/boltar/casino/"

reset(arg) {
  if( !present("machine") )
    move_object(clone_object("players/boltar/casino/floor/slots"), this_object());
  if (arg) return;
  set_light(1);
  set_no_clean(1);
}

init() {
    add_action("east","east");
    add_action("west","west");
    add_action("print","print");
}

print(string str) {

  if(present("machine",this_object())) {
    write("There is already a slot machine present.\n");
    return 1;
  }

  write("You print out a slot machine.\n");
  say(this_player()->query_name() + " prints out a slot machine.\n");
  move_object(clone_object("players/boltar/casino/floor/slots"), this_object());
  log_file("SLOT",this_player()->query_real_name() + " cloned a slot machine on " + ctime() + "\n");
  
  return 1;
  
}

east() {
  call_other(this_player(),"move_player","east#"+CASINO+"floor/casinofloor1");
  return 1;
}
west() {
  call_other(this_player(),"move_player","west#"+CASINO+"floor/casinofloor3");
  return 1;
}

short() {
    return "Casa de Nirvana, Slots Machines";
}

long(str) {
if(str) return 0;
write(
       "The deep red carpet on the floor is illuiminated by the\n"+
        "elaborate chandelier that hangs overhead. The white panels\n"+
        "of the ceiling, each decorated by a raised plaster flower in \n"+
        "various pastel shades in its center with gilding along its edges.\n"+
        "The flashing lights of slot machines demand attention from\n"+
        "everyone in the area. The sound of the slot machines is\n"+
        "overwhelming and the urge to play is strong.\n"+ 
        "If the slot machine is missing, you may 'print' another one.\n\n");
}
