inherit "/obj/monster.c";

/* Skills that can be gained from the trainer */
mapping skills_taught;
/* Skills that can be trained by the trainer */
mapping skills_trained;
/* The unique id of the skill-enabled object the player must be carrying */
string object_id;
/* Override the default messages the trainer says */
mapping custom_messages;

/* These can be used to set an object to do extra checks on wether the player is allowed to
train or gain a skill - things like alignment checks, etc. */
object custom_gain_checker;
object custom_train_checker;

void reset(status arg) {
  ::reset(arg);
  if(!skills_taught) skills_taught=([]);
  if(!skills_trained) skills_trained=([]);
  if(!custom_messages) custom_messages=([]);
}

void init() {
  ::init();
  add_action("cmd_gain","gain");
  add_action("cmd_train","train");
}

string nice_index_list(mapping map) {
  string skill_name_list;
  string *skill_names;
  int x,s;
  skill_names=m_indices(map);
  s=sizeof(skill_names);
  skill_name_list=skill_names[0];
  for(x=1;x<s-1;x++)
    skill_name_list+=", "+skill_names[x];
  if(s>1)
    skill_name_list+=" and "+skill_names[s-1];
  return skill_name_list;
}

varargs string get_default_message(string message_id,string extra) {
  switch(message_id) {
    case "no_skills_taught":      return "I do not teach any new skills.";
    case "no_object":             return "I do not provide teaching to your kind.";
    case "skills_taught_list":    return "I can teach you in the skills of "+nice_index_list(skills_taught);
    case "invalid_taught_skill":  return "I do not teach that skill.";
    case "skill_already_learned": return "You have already learned that skill.";
    case "skill_learned":         return "Very well.  I will teach you the skill of "+extra+".";
    case "no_skills_trained":     return "I do not provide training.";
    case "skills_trained_list":   return "I can train you in the skills of "+nice_index_list(skills_trained);
    case "invalid_trained_skill": return "I do not train that skill.";
    case "skill_not_known":       return "You must learn the skill before you can train it.";
    case "no_more_to_teach":      return "I have nothing more to teach you.";
    case "not_enough_gold":       return "You need "+extra+" gold to donate.";
    case "more_xp_and_prac":      return "You need more practice and more experience.  Return when you are ready.";
    case "more_xp":               return "You have practiced enough, but you still require more experience.  I cannot train you yet.";
    case "more_prac":             return "You have enough experience, but require more practice.  I cannot train you yet.";
    case "custom_gain_check_fail":
    case "custom_train_check_fail": return "A greater power prevents me from teaching you.";
    case "skill_trained":          return "Very well.  I will train you in "+extra+".";
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
    if(member(custom_messages,message_id))
      message=custom_messages[message_id];
    else
      message=get_default_message(message_id,extra);
    if(message=="") message="I can't do that";
    tell_object(padawan,format(name+" says, to you, \""+message+"\""));
    tell_room(room,format(name+" says, to "+padawan->query_name()+", \""+message+"\""),({padawan,this_object()}));
    return 1;
    }
    return 0;
}

status cmd_gain(string str) {
  object ob;
  ob=present(object_id,this_player());
  if(!ob)
    return monster_respond("no_object");
  if(!skills_taught || skills_taught == ([]))
    return monster_respond("no_skills_taught");
  if(!str)
    return monster_respond("skills_taught_list");
  if(!member(skills_taught,str))
    return monster_respond("invalid_taught_skill");
  if((int)ob->query_skill_level(str)!=-1)
    return monster_respond("skill_already_learned");
  if(custom_gain_checker && !custom_gain_checker->custom_gain_check(this_player(),ob,str))
    return monster_respond("custom_gain_check_fail");
  ob->add_skill(str,skills_taught[str]);
  write("You have gained the skill: "+str+"\n");
  return monster_respond("skill_learned",str);
}

status cmd_train(string str) {
  object ob;
  int current_level,gold_needed;
  if(!skills_trained || skills_trained == ([]))
    return monster_respond("no_skills_trained");
  ob=present(object_id,this_player());
  if(!ob)
    return monster_respond("no_object");
  if(!str)
    return monster_respond("skills_trained_list");
  if(!member(skills_trained,str))
    return monster_respond("invalid_trained_skill");
  current_level=(int)ob->query_skill_level(str);
  if(current_level==-1)
    return monster_respond("skill_not_known");
  if((skills_trained[str][0]) && current_level+1 > (int)(skills_trained[str][0]))
    return monster_respond("no_more_to_teach");
  switch((int)ob->check_skill_advance(str)) {
    case -3: return monster_respond("more_xp_and_prac");
    case -2: return monster_respond("more_prac");
    case -1: return monster_respond("more_xp");
  }
  gold_needed = (int)(skills_trained[str][1])*(current_level+1);
  if(this_player()->query_money() < gold_needed)
    return monster_respond("not_enough_gold",gold_needed+"");
  if(custom_train_checker && !custom_train_checker->custom_train_check(this_player(),ob,str))
    return monster_respond("custom_train_check_fail");
  ob->advance_skill(str);
  write("Your skill in "+str+" is now: "+(current_level+1)+"\n");
  if(gold_needed) {
    write("You paid "+gold_needed+" coins for training.\n");
    this_player()->add_money(-gold_needed);
  }
  return monster_respond("skill_trained",str);
}
status set_skill_object_id(string str) {
  object_id=str;
  return 1;
}

status set_custom_skill_message(string message_id,string message) {
  if(!custom_messages)
    custom_messages=([]);
  if(member(custom_messages,message_id))
    custom_messages[message_id]=message;
  else
    custom_messages+=([message_id:message]);
  return 1;
}


status add_skill_taught(string skill_name,mixed *skill_stats) {
  if(!skills_taught) skills_taught=([]);
  if(member(skills_taught,skill_name))
    skills_taught[skill_name]=skill_stats;
  else
    skills_taught+=([skill_name:skill_stats]);
  return 1;
}

/* gold_cost is multiplied by the next skill level to get the cost applied.
   it can be 0 if need be.  10 is probably a good default value.
   a max_level of 0 means no limit at all
*/
status add_skill_trained(string skill_name,int max_level,int gold_cost) {
  if(!skills_trained) skills_trained=([]);
  if(member(skills_trained,skill_name))
    skills_trained[skill_name]=({max_level,gold_cost});
  else
    skills_trained+=([skill_name:({max_level,gold_cost})]);
  return 1;
}

