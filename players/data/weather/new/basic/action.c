/*
 * This action is intended to be inherited by all skills
 * that use marion's brain
 * feel free to complain to sas@cs.tu-berlin.de
 * Updated, Coogan, 10-Jan-2002
 */

#pragma strong_types

#include <skilltree.h>
#include <server.h>

#define OLD_SKILLS_STILL_IN_USE   1

inherit "basic/create";

#if OLD_SKILLS_STILL_IN_USE
private string *skillpath;
#endif

private string skill_path;
private string command, specific;
private string func;
private string *default_objects;

#if OLD_SKILLS_STILL_IN_USE
// these functions are only support as long as old skills exist
private int reward;

void set_reward(int amount) {
  reward = amount;
}

int query_reward() {
  return reward;
}
#endif

string query_skill() {
  if (specific)
    return command + " " + specific;
  else
    return command;
}

void set_skill_path(string path) {
  if (member(VALID_SKILLS, path) == -1)
    raise_error("Invalid skill!\n");
  skill_path = path;
}

string query_skill_path() {
  return skill_path;
}

#if OLD_SKILLS_STILL_IN_USE
void set_skillpath(mixed what) {  // made it accept mixed, Coogan, 05-Jan-2001
  if (stringp(what))
    return set_skill_path(what);
  if ((sizeof(what)<2) || (what[0] != "skill"))
    skillpath = ({ "skill", "illegal", "badpath" });
  else
    skillpath = what;
}

string *query_skillpath() {
  return skillpath;
}
#endif

void set_command(string str) {
  command = str;
}

void set_specific(string str) {
  if (!command)
    return;
  specific = str;
}

void set_function(string str) {
  func = str;
}

void set_default_objects(string *what) {
  default_objects = what;
}

string *query_actions() {
  return ({ command, specific, func });
}

// overlay this function for other actions
string query_info(string str) {
  return "Alas, some wizard was too lazy to help you!\n";
}

void create() {
  create::create();
#if OLD_SKILLS_STILL_IN_USE
  set_skillpath(S_LORE);
#endif
  set_skill_path(S_LORE);
  set_command("use");
  set_specific("skill");
  set_function("command_default");
  set_default_objects(({ }));
}

string *init_living(object ob) {
  return allocate(0); // player is allowed to try this out
}

int command_default(string arg) {
  int index;
  string tmp;
#if !OLD_SKILLS_STILL_IN_USE
  int reward;
#endif

  if ((index = member(default_objects, arg)) >= 0) {
    if (specific)
      tmp = specific + " ";
    else
      tmp="";

    write("To '"+command+" "+tmp+default_objects[index]+"' has taught you"+
          " something!\n");
#if OLD_SKILLS_STILL_IN_USE
    if (!(random(reward*5)))
#else
    if (!random((reward = SE_SKILLS->query_reward(previous_object(), 1, 50,
                                                  query_skill_path()))))
#endif
      previous_object()->add_skill_points(skill_path, reward);
    notify_fail("But sadly nothing happens!\n");
    return 0;
  }
  notify_fail("Good idea, but alas nothing happens at all!\n");
  return 0;
}

