/*
File: danica.c
Author: Feldegast
Date: 2/25/01
Description:
  The captain of the guard in the tower of ravens.  Has all of
the hyper aggressiveness of basic guards.
*/
#include "defs.h"

inherit MONSTER;

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object(ARM_PATH+"bleather.c"),this_object());
  init_command("wear boots"); /* 1800 coins */
  add_money(500+random(700)); /* Avg. 3500 coins total */
  init_command("wear leather"); /* 250 coins */
  move_object(clone_object(WEP_PATH+"ravensword.c"),this_object());
  init_command("wield sword"); /* 600 coins */
  move_object(clone_object(ARM_PATH+"runeboots.c"),this_object());
  set_name("danica");
  set_alias("guard");
  set_short("Danica Starblossom");
  set_long(
"Danica Starblossom is a well-reputed mercenary and adventurer.  She\n\
wears her long strawberry blonde hair down to her waist.  Her features\n\
are beautiful, but stern.  For now, she wears the black feathered\n\
leather armor of the Ravenguard and serves as their captain.\n"
  );
  set_gender("female");
  set_race("human");
  set_al(250);
  set_level(18);
  set_wc(26);
  set_ac(13); /* +2 from armor */
  set_hp(400);
  set_ac_bonus(2); /* For armor */
  set_chat_chance(5);
  load_chat("Danica mutters to herself: What am I doing here?\n");
  load_chat("Danica mutters to herself: Time to get back out on the road...\n");
  load_spell(25,10,0, /* 10% chance of 25 hit_player damage */
    HIW+BBLK+"\nDanica's sword glows with an unearthly light!\n\n"+NORM,
    HIW+BBLK+"\nDanica's sword glows with an unearthly light!\n\n"+NORM
  );
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
          say("Danica leaps to her companion's aid.\n");
          attacked_by(ob->query_attack());
          call_out("aggr_hb",30);
          return;
        }
      }
      if(ob->is_player()) {
         say("Danica says: Who are you?  How did you get in here?\n"+
             "Danica attacks "+ob->query_name()+".\n");
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