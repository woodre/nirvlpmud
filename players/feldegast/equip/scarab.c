/*
File: scarab.c
Creator: Feldegast @ Nirvana
Date: 1/25/01
Description:
  This is the reward for solving the jungle island quest.  It is an
ac1 amulet with a small return and a heal that recharges after an
hour.  It can only be obtained the first time the player solves the
quest.
*/
/* cut CHARGETIME in half, make it fully heal player when used,
  and gave it "magical" dtype protection.  It is a one
  time quest item, so it should be nice.
  -Forbin 2004.12.02 */
#include "defs.h"

#define CHARGETIME 1800 /* Was 1 hour, cut to 30 minutes -Forbin */

inherit "/obj/armor.c";

int last_use;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("scarab");
  /* set_short(HIG+"Scarab of Healing"+NORM); 
    changed short to reflect charged or not -Forbin */
  set_long("The scarab of healing has been cut from a piece of jade large\n"+
           "enough to fit in the palm of your hand.  It is an ancient relic\n"+
           "from the days of the Majiri empire.  Enchanted to provide minor\n"+
           "protection from magic, it also possesses special healing powers\n"+
           "that can be "+HIG+"use"+NORM+"d once every half hour.\n");
  set_ac(1);
  set_params("magical",0,10,"do_magical_special"); /* "magical" dtype protection -Forbin */
  set_type("misc");
  set_weight(1);
  set_value(2500);
}

int is_charged() {
  return time() >= last_use + CHARGETIME;
}

short() { 
  if(!is_charged()) 
    return GRN+"Scarab of Healing ["+NORM+"pulsing"+GRN+"]"+NORM+(this_object()->query_worn() ? " (worn)" : "");
  else
    return HIG+"Scarab of Healing ["+HBGRN+HIW+"glowing"+NORM+HIG+"]"+NORM+(this_object()->query_worn() ? " (worn)" : "");
}

void long(string str) {
  write(long_desc);
  if(!is_charged())
    write("The scarab is pulsing.\n");
  else
    write("The scarab is glowing.\n");
}

void init() {
  ::init();
  add_action("cmd_use","use");
}

int cmd_use(string str) {
  if(!str || !id(str)) {
    notify_fail("Use what?\n");
    return 0;
  }
  if(environment()!=this_player())
    return 0;
  if(!worn) {
    write("You must wear the scarab to use it.\n");
    return 1;
  }
  if(!is_charged()) {
    write("The scarab isn't done recharging yet.\n");
    return 1;
  }
  write("The scarab of healing imbues you with its healing power.\n");
  say(TPN+" uses the scarab of healing.\n");
  this_player()->heal_self(1000); /* changed from 50 to totally heal player */
  last_use=time();
  return 1;
}


int do_special(object owner) {
  if(this_player()) /* check added by verte 6.6.01 */
  if((int)this_player()->query_attrib("luc") > random(200)) {
    tell_room(owner, HIG+(string)owner->query_name()+"'s scarab flashes, blinding you!\n"+NORM, ({owner}));
    tell_object(owner,HIG+"Your scarab flashes, blinding "+TPN+" briefly!\n"+NORM);
    return 2;
  }
}

/* do_magical_special added -Forbin */
int do_magical_special(object owner) {
  if(this_player()) /* check added by verte 6.6.01 */
  if((int)this_player()->query_attrib("luc") > random(100)) {
    tell_room(owner,
      HIG+(string)owner->query_name()+"'s scarab flickers and a green aura explodes outward from "+
      (string)owner->query_objective()+"!\n"+NORM, ({owner}));
    tell_object(owner,
      HIG+"Your scarab flickers and a green aura explodes outward from you!\n"+NORM);
         return 0502;  /* 5% [05] resistance boost 2 [02] ac boost */
  }
}

string locker_arg() {
  return last_use+"";
}

void locker_init(string arg) {
  sscanf(arg,"%d",last_use);
}

generic_object() { return 1; } 

restore_thing(str) {
  restore_object(str);
  return 1;
}

save_thing(str) {
  save_object(str);
  return 1;
}
