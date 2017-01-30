inherit "/obj/monster";

#include "/players/guilds/bards/def.h"

object master;

status follow;

string fly_away_message,fly_in_message;

void reset(status arg) {
  if(!present("instrument"),this_object())
    move_object(clone_object("/players/guilds/bards/bard_mark.c"),this_object());
  ::reset(arg);
  if(arg) return;
  
  set_race("pegasus");
  set_alt_name("pet");
  
}

status set_master(object who) {
  object gob,level_temp;
  master=who;
}

void init() {

  ::init();
  if(TP == master)
    add_action("cmd_pet","pet");

}

status is_pet() { return 1; }

status set_fly_away_message(string str) {
  fly_away_message=str;
  if(fly_away_message) return 1;
}

status set_fly_in_message(string str) {
  fly_in_message=str;
  if(fly_in_message) return 1;
}

void fly_away() {
  if(!environment()) return;
  tell_room(environment(),(fly_away_message?fly_away_message:
     "The pegasus flies away.\n"));
}

void fly_in() {
  if(!environment()) return;
  tell_room(environment(),(fly_in_message?fly_in_message:
     "A pegasus flies into the room.\n"));
}

void no_more_pet() {
  fly_away();
  destruct(this_object());
}

status cmd_pet(string str) {
  if(TP != master) return 0;
  return (status)PET->cmd_pet(str,master,this_object());
}

status set_follow(status what) {
  remove_call_out("do_follow");
  if(what) {
    call_out("do_follow",2);
    return (follow=1);
  } else
    return (follow=0);
}

void do_follow() {
  object where;
  if(!master)
    return no_more_pet();
  if(!follow)
    return;
  where = environment(master);

  if(environment(TO) == where) {
    call_out("do_follow",6);
    return;
  }

  if(!where) {
    tell_object(master,NAME(TO) + " cannot follow you here.\n");
    follow = 0;
    return;
  }
  fly_away();
  move_object(TO,where);
  fly_in();
  call_out("do_follow",6);
}

heart_beat() {
  if(!master) return no_more_pet();
  ::heart_beat();
}