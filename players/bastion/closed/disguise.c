#include "/players/bastion/guild/spell/base_spell.h"
inherit "players/bastion/guild/spell/base_spell.c";

void reset(int arg) {
     if(arg) return;
     base_chance=60;
     spell_level=4;
     casting_time=1;
     duration=20;
     spell_cost=50;
     id_name="disguise";
     spell_name="Disguise";
     spell_desc="This spell allows you to take the form of any object " +
      "you choose. When casting, give the name of the object and the " +
      "description that will be seen when looking in a room. All changes " +
       "will be logged, however, and taking the form of another player is " +
       "strictly forbidden. Any player doing so will be asked to leave the " +
       "guild.\n\n" +
      "Cost: 50 spell points\n" +
      "Type: alteration\n" +
      "Format: cast disguise <name> <description>\n";
     properties=({ "non_parsed", "two_arguments" });
     spell_type="alteration";
}

int cast_spell(object *targ, string arg1, string arg2) {
  write(format("You focus your mind on the form of a " + arg1 + ". The " +
   "world swirls around you.\n"));
  ssay(me, NAME + " concentrates and sways from side to side.\n");
  return 1;
}

int heart_beat_spell(object *targ, string arg1, string arg2) {
  string name;
  if(!me->query_sorcerer()) {
    write(format("You sense an imbalance in the energies flowing through " +
     "you. Type \"renew.\"\n"));
    ssay(me, NAME + " appears to regain " + HIS + " balance.\n");
    return 1;
  }
  if(("players/bastion/guild/obj/is_player")->is_player(arg1)) {
    write(format("You sense deliberate intereference with your casting. " +
     "A voice tells you: \"That name is taken.\"\n"));
    ssay(me, NAME + " appears to regain " + HIS + " balance.\n");
    return 1;
  }
  if(!me->valid_name(arg1)) {
    ssay(me, NAME + " appears to regain " + HIS + " balance.\n");
    return 1;
  }
  write(format("You feel disoriented and find yourself looking at the " +
   "world from a new perspective.\n"));
  ssay(me, "The fabric of space ripples around " + NAME + " and " + HE + 
   " is transformed into a " + arg1 + ".\n");
  name=(string)me->query_real_name();
  name=capitalize(name);
  if(me->query_level() < 99)
    write_file("/players/bastion/guild/log/disguise", name + " disguised " +
     "as:  " + capitalize(arg1) + "--" + arg2 + "  " + ctime() + "\n");
  me->set_new_name(lower_case(arg1));
  me->set_new_short(arg2);
  me->set_new_long(arg2 + ".");
  me->set_disguise_duration(duration);
  return 1;
}

string casting_message(object *targ, object caster, int round) {
}
