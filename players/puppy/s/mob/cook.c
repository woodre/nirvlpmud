#include "/players/puppy/define.h"
inherit "obj/monster.c";
#define CS "Cook Smurf"

reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("cook");
   set_alias("smurf");
   set_race("smurf");
   set_short(""+HIB+"Cook Smurf"+NORM+"");
   set_long(
      "Cook Smurf is the only Smurf that actually has a job to do.\n"+
      "He learned the value of coins and what they could do for the\n"+
      "Smurf,s a long time ago from a lost traveller.  As a baby Smurf\n"+
      "he always enjoyed when the others created Smurfy dishes to\n"+
      "eat, so he chose cooking as his profession.  If you ask him\n"+
      "nicely he may provide a 'list' of dishes that you may buy.\n");
   
   set_level(10);
   set_hp(1000000);
   set_al(115);
   set_wc(10);
   set_ac(5);
   set_aggressive(0);
   set_chat_chance(5);
   load_chat("Cook Smurf checks his wares.\n");
}

init() {
   ::init();
   add_action("buy_it","buy");
   add_action("list", "list");
}

list(){
   write("Cook Smurf says: Here is a list of some smurfy dishes.\n");
   write("\n");
   write("  COST     ITEMS\n");
   write("   40     A bottle of Smurfy Spirits\n");
   write("   40     A bottle of Smurfjuice\n");
   write("   10     A blue berry muffin\n");
   write("   160    A blue berry pancake\n");
   write("   600    A box of poptarts\n");
   write("\n");
   return 1;
}

buy_it(arg) {
   
   if(arg == "muffin" || arg == "blue berry muffin"){
      object muf;
      if(this_player()->query_money() < 40)
         return (notify_fail(
               CS+" says, \"Maybe something a little less expensive?\"\n"), 0);
      if(!this_player()->add_weight(1))
         return (notify_fail(
               CS+" says, \"I'm sorry, You can't carry that.\"\n"), 0);
      write(CS+" hands you a blue berry muffin.\n");
      tell_room(environment(this_player()),
         CS+" hands a blue berry muffin to "+this_player()->query_name()+".\n",
         ({ this_player() }));
      muf = clone_object("/players/puppy/s/heal/muffin.c");
      move_object(muf, this_player());
      this_player()->add_money(-40);
      return 1;
   }
   
   if(arg == "pancake" || arg == "blue berry pancake"){
      object pan;
      if(this_player()->query_money() < 160)
         return (notify_fail(
               CS+" says, \"Maybe something a little less expensive?\"\n"), 0);
      if(!this_player()->add_weight(1))
         return (notify_fail(
               CS+" says, \"I'm sorry, You can't carry that.\"\n"), 0);
      write(CS+" hands you a blue berry pancake.\n");
      tell_room(environment(this_player()),
         CS+" hands a blue berry pancake to "+this_player()->query_name()+".\n",
         ({ this_player() }));
      pan = clone_object("/players/puppy/s/heal/pancake.c");
      move_object(pan, this_player());
      this_player()->add_money(-160);
      return 1;
   }
   
   if(arg == "box of poptarts" || arg == "poptarts" || arg == "box"){
      object pop;
      if(this_player()->query_money() < 600)
         return (notify_fail(
               CS+" says, \"Maybe something a little less expensive?\"\n"), 0);
      if(!this_player()->add_weight(1))
         return (notify_fail(
               CS+" says, \"I'm sorry, You can't carry that.\"\n"), 0);
      write(CS+" hands you a box of blue berry poptarts.\n");
      tell_room(environment(this_player()),
         CS+" hands a box of blue berry poptarts to "+this_player()->query_name()+".\n",
         ({ this_player() }));
      pop = clone_object("/players/puppy/s/heal/poptart.c");
      move_object(pop, this_player());
      this_player()->add_money(-600);
      return 1;
   }
   
   if(arg == "spirit" || arg == "spirits"){
      object spi;
      if(this_player()->query_money() < 40)
         return (notify_fail(
               CS+" says, \"Maybe something a little less expensive?\"\n"), 0);
      if(!this_player()->add_weight(1))
         return (notify_fail(
               CS+" says, \"I'm sorry, You can't carry that.\"\n"), 0);
      write(CS+" hands you a bottle of his finest spirits.\n");
      tell_room(environment(this_player()),
         CS+" hands a bottle of his finest spirits to "+this_player()->query_name()+".\n",
         ({ this_player() }));
      spi = clone_object("/players/puppy/s/heal/spirit.c");
      move_object(spi, this_player());
      this_player()->add_money(-40);
      return 1;
   }
   
   
   if(arg == "juice" || arg == "smurfjuice"){
      object jui;
      if(this_player()->query_money() < 40)
         return (notify_fail(
               CS+" says, \"Maybe something a little less expensive?\"\n"), 0);
      if(!this_player()->add_weight(1))
         return (notify_fail(
               CS+" says, \"I'm sorry, You can't carry that.\"\n"), 0);
      write(CS+" hands you a bottle of smurfjuice.\n");
      tell_room(environment(this_player()),
         CS+" hands a bottle of smurfjuice to "+this_player()->query_name()+".\n",
         ({ this_player() }));
      jui = clone_object("/players/puppy/s/heal/juice.c");
      move_object(jui, this_player());
      this_player()->add_money(-40);
      return 1;
   }
}

heart_beat()
{
 if(hit_point < max_hp)
 {
  tell_room(environment(), "A magical aura enfolds over "+short()+".\n");
  if(attacker_ob) attacker_ob->stop_fight();
  if(attacker_ob) attacker_ob->stop_fight();
  stop_fight();
  stop_fight();
  heal_self(1000000);
 }
 ::heart_beat();
}
