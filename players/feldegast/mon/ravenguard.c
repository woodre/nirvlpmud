/*
File: ravenguard.c
Author: Feldegast
Date: 2/25/01
Description:
  A basic guard in the Tower of Ravens in Caladon.  Low level, but
hyper aggressive.
*/
#include "defs.h"

inherit "/obj/monster.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object(ARM_PATH+"bleather.c"),this_object());
  init_command("wear leather"); /* 250 coins */
  move_object(clone_object(WEP_PATH+"ravensword.c"),this_object());
  init_command("wield sword"); /* 600 coins */
  add_money(random(300)); /* Avg. 1000 coins total */
  set_name("ravenguard");
  set_alias("guard");
  set_short(BOLD+BLK+"Ravenguard"+NORM);
  set_long(
"This is an elite guard of the Tower of Ravens.  He wears a skintight\n\
suit of black leather armor decorated with black raven feathers.  His\n\
pointed ears suggest an elven heritage, but his well-muscled frame\n\
suggests that he is also partly human.\n"
  );
  set_gender("male");
  set_race("half-elf");
  set_al(-150);
  set_level(15);
  set_wc(20);
  set_ac(10); /* +2 from armor */
  set_hp(250);
  set_ac_bonus(2); /* For armor */
  call_out("aggr_hb", 5);
}

int query_raven() { return 1; }

void aggr_hb() {
  object ob;
  if(!environment()) return;
  if(!attacker_ob) {
    ob=first_inventory(environment());
    while(ob) {
      if(ob->query_raven()) {
        if(ob->query_attack()) {
          say("The Ravenguard leaps to his companion's aid.\n");
          attacked_by(ob->query_attack());
          call_out("aggr_hb",30);
          return;
        }
      }
      if(ob->is_player()) {
         say("The Ravenguard says: Who are you?  How did you get in here?\n"+
             "Ravenguard attacks "+ob->query_name()+".\n");
         this_object()->attacked_by(ob);
         call_out("aggr_hb",30);
         return;
      }
      ob=next_inventory(ob);
    }
  }
  call_out("aggr_hb",10);
}

catch_tell(str) {
  string name, dir;
  if(query_verb()=="emote" || (this_player() && !this_player()->is_player()))
    return;
  if(sscanf(str,"%s leaves %s.",name,dir)==2)
    if(!random(2)) call_out("move_me", 3, dir);
}

move_me(dir) {
  if(!attacker_ob) command(dir,this_object());
}