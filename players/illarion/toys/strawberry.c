/*
 * strawberry.c - an 'edible' but non-healing item
 * Illarion 4/00
 */

inherit "obj/treasure";
#include "/players/illarion/dfns.h"

void reset(status arg) {
  if(arg) return;
  
  set_id("strawberry");
  set_alias("berry");
  set_short("A large red strawberry");
  set_long("A large, juicy, deep red strawberry, with the stem already\n"+
           "removed, waiting for someone to "+BLD("eat")+" it, or to "+BLD("feed")+"\n"+
           "it to someone else.\n");
  set_weight(1);
}
void init() {
  ::init();
  add_action("cmd_eat","eat");
  add_action("cmd_feed","feed");
}
status cmd_eat(string str) {
  if(!str || (present(str,TP) != this_object()))
    FAIL("Eat what?\n");
  write("You pop the strawberry into your mouth, and bite down on it.  It\n"+
        "almost seems to burst apart, filling your mouth with its sweet, rich\n"+
        "flavor.\n");
  say(TPN+" eats a strawberry.\n");
  transfer(this_object(),"/room/void");
  destruct(this_object());
  return 1;
}
status cmd_feed(string str) {
  string what,who;
  object pers;
  if(!str || (sscanf(str,"%s to %s",what,who) != 2))
    FAIL("Feed what to whom?\n")
  if(present(what,TP) != this_object())
    FAIL("Feed what to whom?\n");
  pers=present(who,environment(TP));
  if(!pers || !pers->is_player())
    FAIL("You can't feed a strawberry to someone who isn't here.\n");
  write(format(
    "You feed the strawberry to "+pers->query_name()+".  "+
    capitalize((string)pers->query_possessive())+" lips brush your fingers as "+
    pers->query_pronoun()+" closes "+pers->query_possessive()+" mouth.\n"));
  tell_object(pers,format(
    TPN+" feeds you an incredibly sweet and rich strawberry.  Your lips "+
    "brush "+TP->query_possessive()+" fingers as you close your mouth.\n"));
  say(TPN+" feeds "+pers->query_name()+" a strawberry.\n",pers);
  transfer(this_object(),"/room/void");
  destruct(this_object());
  return 1;
}
  
