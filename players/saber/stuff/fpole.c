#include "/players/saber/closed/ansi.h"
#define tp this_player()->query_name()
#define TP this_player()

inherit "obj/treasure";

reset(arg)  {
  if(arg) return;
   set_id("fishing pole");
   set_short("A fishing pole");
   set_alias("pole");
   set_long(
   "A long wooden fishing pole.\n"+
   "You can use the commands <reel_fish> <play_fish> and <cast_line>\n"+
   "with it.  Or you can just carry it around a look rural.\n"+
   "                                             A "+HIR+"Candy"+HIM+" Saber"+NORM+" item.\n");
   set_weight(1);
   set_value(75);
}

init()  {
   add_action("play_fish","play_fish");
   add_action("cast_line","cast_line");
   add_action("reel_fish","reel_fish");
   }

reel_fish()  {
  write("You feel a tug on your line!\n"+
    "You slowly reel in your line.\n"+
    "You have caught a really big fish!\n");
  say(tp+"'s line begins to twitch.\n"+
    tp+" slowly reels in "+this_player()->query_possessive()+" line.\n"+
    tp+" smiles and holds up a really big fish!\n");
  return 1;
        }

cast_line()  {
  write("You cast out your line into a nearby stream.\n");
  say(tp+" casts "+this_player()->query_possessive()+" line out into a nearby stream.\n");
  return 1;
        }

play_fish()  {
  write("You slowly play the line, exausting the fish.\n");
  say(tp+" slowly plays the line, exausting the fish.\n");
  return 1;
        }
