#include "std.h"

object hitler;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
  if(!hitler || !living(hitler)) {
    hitler = clone_object("obj/monster");
    call_other(hitler,"set_name","hitler");
    call_other(hitler,"set_short","Adolf Hitler");
    call_other(hitler,"set_ac",17);
    call_other(hitler,"set_level",16);
    call_other(hitler,"set_al",-50);
    call_other(hitler,"set_wc",16);
    call_other(hitler,"set_aggressive",0);
    move_object(hitler,this_object());
    call_other(hitler,"set_object",this_object());
    call_other(hitler,"set_function","gives");
    call_other(hitler,"set_type","gives");
    call_other(hitler,"set_match"," ");
    call_other(hitler,"set_chat_chance",25);
   call_other(hitler,"load_chat","Hitler says:Bring me Jones' diary!!!\n");
   call_other(hitler,"load_chat","Hitler says:Hial me!!!!!\n");
  }
}

notify(str) {
  say(str);
  write(str);
}

gives(str) {
  string who,what,whom;
  object obj, next_obj,dude;
  int found;

  if(sscanf(str,"%s gives %s to %s.\n",who,what,whom) != 3)
    return;
  if(whom != "Hitler")
    return;
  if(what == "diary") {
    obj = first_inventory(hitler);
    if(!call_other(obj,"id","diary")) {
      notify("Hitler says: This isn't what I want!!!!.\n");
      notify("Hitler gives "+what+" to "+who+".\n");
      transfer(obj,find_living(lower_case(who)));
      return;
    }
    if(call_other(obj,"query_value") != 47) {
      notify("Hitler says: This isn't the right diary.\n");
      notify("Hitler says: You shoudn't try to fool me "+who+".\n");
      destruct(obj);
      return;
    }
    notify("Hitler says: Well done you have brought me the diary.\n");
    notify("Hitler says: You may now continue on with the quest.\n");
    notify("Hitler signs the diary and drops it.\n");
destruct(obj);
    dude=clone_object("players/haji/quest/diarysub");
    say("pick up the diary so you may continue your quest.\n");
    write("pick up the diary so you may proceed.\n");
    move_object(dude,this_object());
    return 1;
   }
}

TWO_EXIT("players/haji/quest/lev27.c", "south",
         "players/haji/quest/lev30.c", "north",
         "A town",

       "You are in a town something EVIL is about.\n",1)


      

