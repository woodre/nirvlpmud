/******************************************************************************
 *  
 *  File:           human.c
 *  
 *  Author(s):      Vital@Nirvana
 *  
 *  Copyright:      Copyright (c) 1997 Vital@Nirvana
 *                  All Rights Reserved.
 *  
 *  Source:			Started 1/15/01
 *  
 *  Notes:			
 *  
 *  Change History: 1/23/01,9/25/01
 *  
 *  
 *****************************************************************************/

#include <ansi.h>
#include "/players/vital/closed/headers/vital.h"
#include "/players/vital/dest/include/spaceport.h"
#include "/obj/clean.c"

int name_num, dest_num, name_size, dest_size;
int x, time;
string *name_desc, *dest_desc;
string short_desc, long_desc, info, name, dest, str;
string *ids;
object shuttle;

int
id(string str) {
  return (member_array(str, ids) >= 0);
}

void
set_id(string *new_ids) {
  ids = new_ids;
}

string
short() {
  return short_desc;
}

void
set_info(string str) {
  info = str;
}

int
query_time() {
    "/players/vital/dest/spaceport/shuttles/shuttle_daemon.c"->query_shuttle_timer(TO);
    return time;
}

void
long() {
    int time;
    time = query_time();
    write(long_desc+"The shuttle will lift of in "+time+" ticks.\n");
}

void
set_name(string str) {
  name = str;
}

query_name() {
  return name;
}

void
set_dest(string str) {
  dest = str;
}

query_dest() {
  return dest;
}

void
set_short(string str) {
  short_desc = str;
  long_desc = "You see nothing special.\n";
}

void
set_long(string str) {
  long_desc = str;
}


int
get() {
  return 0;
}

reset(arg){
   if(arg) return;
   shuttle = "/players/vital/dest/spaceport/shuttles/shuttle_daemon.c";
   x = random(2);
   switch(x) {
     case 0: str = "1"; break;
     case 1: str = "2"; break;
   }
name_desc = explode(read_file(SPT+"shuttles/shuttle_name"+str,20),"#");
dest_desc = explode(read_file(SPT+"shuttles/shuttle_dest",20),"#");
    name_size = sizeof(name_desc);
    dest_size = sizeof(dest_desc);
    dest_num=random((dest_size)-1);
    name_num=random((name_size)-1);
    set_name(name_desc[name_num]);
    set_dest(dest_desc[dest_num]);
    set_id(({"shuttle","css"}));
    set_short("The "+HIB+"Shuttle"+NORM+" "+CAP(name)+HIW+" ["+NORM+"CSS"+HIW+"]"+NORM);
    set_long("  "+short_desc+" bound for "+dest+".\n\
"+short_desc+" is a standard commercial N.U.T.S. shuttle. \nThe alloy is \
deep, dark "+BOLD+BLK+"grey"+NORM+" and there are lines of windows around \
the upper half. It is about 3 meters in diameter and 4.5 meters tall and in \
the general shape of an egg.\n");
    set_info("Shuttle: ");
    call_out("time_move",1);    
}


init() {
  add_action("enter_shuttle","enter");
  remove_action("leave");
}

enter_shuttle(str) {
  if(!str) {
    notify_fail("What are you trying to do?\n");
    return 0;
  }
  if(str != name) {
    write("You must 'enter <shuttlename>' to get the right shuttle.\n");
    return 1;
  }
  else 
  write("You climb into the shuttle.\n");
  say(TPN+" climbs into the shuttle.\n");
  move_object(TP,TO);
  add_action("exit_shuttle","leave");
  remove_enter();
  command("look",this_player());
  say(TPN+" enters the shuttle.\n");
  return 1;
}

exit_shuttle() {
    write("You leave the shuttle.\n");
    say(TPN+" leaves the shuttle.\n");
    move_object(TP,environment(TO));
    add_action("enter_shuttle","enter");
    remove_leave();
    command("look",this_player());
    say(TPN+" arrives from the shuttle.\n");
    return 1;
}

remove_enter() { remove_action("enter"); }
remove_leave() { remove_action("leave"); }

remove_object() {
    write("The shuttle explodes in a shower of pieces, sparks and fire.\n");
    "players/vital/dest/spaceport/shuttles/shuttle_daemon.c"->remove_shuttle(name);
}
