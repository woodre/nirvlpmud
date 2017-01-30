inherit "room/room";	/*  circle guild hall  */
#include "/players/zeus/circle/misc/help.h"
#include "/players/zeus/closed/all.h"
#define GUILD (string)TP->query_guild_name() == "fallen"
#define NOGUILD (string)TP->query_guild_name() != "fallen"
#define GXP query_guild_exp()
int uncovered, *mag_cost, *ste_cost, geeber, chh, y, z, guild_exp;
object circle;
string *touched, *peeps, *excluded, why;

reset(arg){
 if(arg) return;

  touched = ({});  /*  who is touching circle */
  uncovered = 1;   /*  uncovered (by default - 5/28/02) */
  geeber = 0;      /*  used in seek_cmd()     */

                   /*  the costs for ste to increase */
  ste_cost =({ 800000, 1600000, 2400000, 3200000, 4000000,
               4800000, 5600000, 6400000, 7200000, 8000000 });

                     /*  the costs for mag to increase */
  mag_cost =({ 1000000, 2000000, 3000000, 4000000, 6000000, 8000000 });

  excluded = ({ "maledicta", "zeus", "zeustest", "cobaintest", });

  short_desc = "The Fallen Lands";
  set_light(0);
  dest_dir=({ });
}

short(){ return "The Fallen Lands"; }

long(){
  if(!uncovered){
    write(
"You are standing in a very secluded part of the forest.  Directly to\n"+
"the south is a large rock covered by plants.  It seems to protrude\n"+
"from the ground like a giant dagger, with the side facing you being\n"+
"extremely flat.  Towering evergreen trees are all around you.  There\n"+
"is a small trail leading to the north that is the only way out.\n"+
"    No obvious exits.\n");
  }
  if(uncovered){
    write(
"You are standing in a very secluded part of the forest.  Directly to\n"+
"the south is a large rock that is protruding out of the ground like a\n"+
"giant dagger, with the side facing you being extremely flat.  Towering\n"+
"evergreen trees are all around you.  There is a small trail leading to\n"+
"the north that is the only way out.\n"+
"    No obvious exits.\n");
  }
}

check_touch(){  if(query_touched(TP)) sub_touched(TP); }

load_spells(object x){
  object y;
  if(!x) return 0;
  y = present("circle_object", x);
  if(y && (string)x->query_guild_name() == "fallen")
    y->load_spells();
}


void init(){
  ::init();
  if(TP) check_touch();
  add_action("north_dir2", "north");
  add_action("look_cmd", "look");
  add_action("look_cmd", "l");
  add_action("look_cmd", "exa");
  add_action("look_cmd", "examine");
  add_action("uncover_cmd", "uncover");
  add_action("read_cmd", "read");
  add_action("touch_cmd", "touch");
  add_action("trace_cmd", "trace");
  add_action("free_cmd", "free");
  add_action("seek_cmd", "seek");
  add_action("smear_cmd", "smear");
}

exit(){   if(TP) TP->clear_fight_area();     } 
realm(){  return "NT"; }
okay_follow(){ return 1; }

add_touched(object me){
  if(!query_touched(me))
    return touched += ({ me, });
  return 0;
}

sub_touched(object me){
  if(query_touched(me))
    return touched -= ({ me, });
  return 0;
}

query_touched(object me){
  if(!touched || !sizeof(touched)) return 0;
  if(index(touched, me) > -1) return me;
  return 0;
}

north_dir2(){
  write("You walk north...\n\n");
  TP->MP("north#/players/zeus/circle/rooms/path.c");
  if(query_touched(TP)) 
    sub_touched(TP);
  return 1;
}

                      /* functions included in which header file:     */
#include "look.h"     /* look_cmd                                     */
#include "advance.h"  /* smear, randmsg, learn, check, stats, guilded */
#include "seek.h"     /* seek_cmd                                     */
#include "misc.h"     /* read, uncover, touch                         */
#include "join.h"     /* trace                                        */
#include "leave.h"    /* free_cmd                                     */

