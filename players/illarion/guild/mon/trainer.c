/* Trainer NPC for blademaster guild.  Skill difficulties and costs
   and whatnot are all held in the main guild daemon, except for
   one thing- gold cost
 */

#include "/players/illarion/guild/def.h"
#define COINS_PER_LEVEL 100
inherit "/obj/monster.c";

/* Skills that can be trained by the trainer */
string *skills_trained;
/* Override the default messages the trainer says */
mapping custom_messages;

/* These can be used to set an object to do extra checks on wether the player is allowed to
train or gain a skill - things like alignment checks, etc. */
object custom_gain_checker;
object custom_train_checker;

void reset(status arg) {
  ::reset(arg);
  if(!skills_trained) skills_trained=({"dodge","parry","armor use","extra attack","enhanced damage","critical strike","counter"});
  if(!custom_messages) custom_messages=([]);
  if(arg) return;

  set_name("lan");
  set_alias("al'lan");
  set_race("human");
  set_short("al'Lan Mandragoran, the Seeker of Death");
  set_long("Lan is a man far out of his place and time.  He spent his days\n"+
           "and most of his nights killing unnatural things in the Blight,\n"+
           "seeking the death he felt should have come to him with the rest\n"+
           "of his people when their nation fell to the Blight.\n"+
           "No one is really sure how he got here, but for reasons of his\n"+
           "own, he has decided to train blademasters.\n");
  set_level(20);

}

void init() {
  ::init();
  add_action("cmd_train","train");
}

varargs string get_default_message(string message_id,string extra) {
  switch(message_id) {
    case "no_object":             return "I do not provide teaching to your kind.";
    case "invalid_trained_skill": return "I do not train that skill.";
    case "skill_not_known":       return "You must learn the skill before you can train it.";
    case "not_enough_gold":       return "You need "+extra+" gold to donate.";
    case "more_xp_and_prac":      return "You need more practice and more experience.  Return when you are ready.";
    case "more_xp":               return "You have practiced enough, but you still require more experience.  I cannot train you yet.";
    case "more_prac":             return "You have enough experience, but require more practice.  I cannot train you yet.";
    case "skill_trained":          return "Very well.  I will train you in "+extra+".";
    case "no_arg":                 return "What skill do you want to train?";
    default: return "";
  }
}

varargs status monster_respond(string message_id, string extra) {
  object padawan;
  object room;
  string name;
  padawan=this_player();
  room=environment();
  name=(string)this_object()->query_name();
  if(padawan && room && name && present(padawan,room)) {
    string message;
    message=get_default_message(message_id,extra);
    if(message=="") message="I can't do that";
    tell_object(padawan,format(name+" says, to you, \""+message+"\""));
    tell_room(room,format(name+" says, to "+padawan->query_name()+", \""+message+"\""),({padawan,this_object()}));
    return 1;
    }
    return 0;
}

status cmd_train(string str) {
  object ob;
  int current_level,gold_needed;
  ob=present(OB_NAME,this_player());
  if(!ob)
    return monster_respond("no_object");
  if(!str)
    return monster_respond("no_arg");
  if(member_array(str,skills_trained)==-1)
    return monster_respond("invalid_trained_skill");
  current_level=(int)ob->query_skill_level(str);
  if(current_level==-1)
    return monster_respond("skill_not_known");
  switch((int)DAEM->check_skill_advance(str,ob,TP)) {
    case -3: return monster_respond("more_xp_and_prac");
    case -2: return monster_respond("more_prac");
    case -1: return monster_respond("more_xp");
  }
  gold_needed = COINS_PER_LEVEL*(current_level+1);
  if(this_player()->query_money() < gold_needed)
    return monster_respond("not_enough_gold",gold_needed+"");
  ob->raise_skill(str);
  write("Your skill in "+str+" is now: "+(current_level+1)+"\n");
  if(gold_needed) {
    write("You paid "+gold_needed+" coins for training.\n");
    this_player()->add_money(-gold_needed);
  }
  return monster_respond("skill_trained",str);
}

