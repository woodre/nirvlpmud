/* dragon.c - a totally ornamental dragon-type object- it can't carry
 *            items or engage in combat, but it does respond to emotes
 *            directed at it.
 */



inherit "/players/illarion/high/mon/imm_mon";
#include "/players/illarion/dfns.h"

status follow;
object owner;

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  
  set_name("dragon");
  set_short("A tiny obsidian dragon");
  set_long("A tiny, delicate creature, seemingly made entirely of gleaming\n"+
           "polished obsidian, yet undeniably moving and alive.  Tiny wings\n"+
           "that look like shadows with gleaming highlights support him\n"+
           "easily as he flits about.  His tiny face and faceted diamond\n"+
           "eyes, supported by a graceful arching neck, are amazingly\n"+
           "expressive for something so tiny, especially complimented by\n"+
           "sweeps of his long, glinting tail.\n");
  set_gender("male");
  set_level(1);
  set_wc(0);
  set_ac(0);
  set_ep(0);
  set_hp(1);
}

/* doesn't do anything when attacked */
attack() {
  return;
}

void long() {
  ::long();
  if(TP==owner) {
    write("Your dragon whispers to you from inside your head that you\n"+
          "have but to type "+BLD("dragon")+" to command him.\n");
  } 
}

/* attempts to end combat the moment something tries to hit it */
hit_player() {
  tell_room(environment(),
     "The dragon dodges, letting out a horrified screech, and flits out\n"+
     "of range of her attacker.\n");
  stop_fight();
  this_player()->stop_fight();
  return 0;
}

init() {
  ::init();
  add_action("cmd_dragon","dragon");
}

string query_name() {
  return (owner?owner->query_name()+"'s":"a")+" dragon";
}

void set_owner(object ob) {
  owner=ob;
}

status cmd_dragon(string str) {
  string cmd,arg;
  if(this_player() != owner) {
    return 0;
  }
  if(!str) {
    write("Your dragon silently tells you that he can do the following:\n");
    write("dragon follow - start or stop following you.\n");
    write("dragon emote  - cause your dragon to act\n");
    return 1;
  }
  if(sscanf(str,"%s %s",cmd,arg)!=2)
    cmd=str;
  switch(cmd) {
    case "follow":
      follow=!follow;
      write("Your dragon "+(follow?"starts":"stops")+" following you.\n");
      return 1;
    case "emote":
      if(!arg) {
        write("Your dragon looks at you with a confused expression.\n");
        return 1;
      }
      tell_room(ETO,format(query_name()+" "+arg),({TO}));
      return 1;
    default:
      write("Your dragon doesn't know what you mean.\n");
      return 1;
  }
}

void heart_beat() {
  if(owner && follow && !present(owner,ETO)) {
    say(query_name()+" flies out of the room.\n");
    move_object(TO,environment(owner));
    say(query_name()+" flies into the room and perches on "+
      owner->query_possessive()+" shoulder.\n",owner);
    tell_object(owner,
      "Your dragon flies into the room and perches on your shoulder.");
  }
  ::heart_beat();
}
