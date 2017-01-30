inherit "/obj/treasure.c";
/*
File: prize.c
Author: Feldegast
Date: 2/23/01
Description:
  A prize awarded for the description contest.  If any
player other than Stone has this, then they have it
illegally.  Not that Stone needs yet another unique
item...
*/
#include "defs.h"
#include "/players/feldegast/std/colorize.h"


string extra_look()
{
  return environment()->query_name()+" wears a "+HIC+"sapphire"+NORM+CYN+" pendant "+NORM+"that was "+environment()->query_possessive()+" prize\n  for winning the Description Contest(2001)";
}

string query_auto_load() {
  return "/players/feldegast/obj/prize:";
}

void reset(int arg) 
{
  if(arg) return;
  set_id("sapphire pendant");
  set_long(
"This is a sapphire pendant with a silver chain.  This pendant\n"+
"grants you the following powers:\n"+
"  color_title :   Give yourself a color title.\n"+
"  flamestrike :   A special attack spell.\n"
  );
  no_clean=1;
}

drop() { return 1; }

void init() {
  add_action("cmd_attack", "flamestrike");
  add_action("cmd_ctitle", "color_title");
}

int cmd_ctitle(string str) {
  string name;
  string title;
  if(!str) {
    notify_fail(
"Usage: color_title <str>\n"+
"  You may insert the following color codes into your title:\n"+
"    "+RED+"RED "+HIR+"HIR "+NORM+
       GRN+"GRN "+HIG+"HIG "+NORM+
       YEL+"YEL "+HIY+"HIY "+NORM+
       BLU+"BLU "+HIB+"HIB "+NORM+
       MAG+"MAG "+HIM+"HIM "+NORM+
       CYN+"CYN "+HIC+"HIC "+NORM+
       WHT+"WHT "+HIW+"HIW "+NORM+
       "NORM\n"+
"  A norm code will be appended automatically.\n");
    return 0;
  }
  if(strlen(str) > 40) {
    write("That is too long.\n");
    return 1;
  }
  title=colorize(str);
  title+=NORM;
  TP->set_title(title);
  write("You have set your title to '"+title+"'.\n");
  return 1;
}

int cmd_attack(string str) {
  object target;
  string at_msg;
  int static_dam, random_dam, pts, cost;
  if(!str) target=(object)this_player()->query_attack();
  else target=present(str,environment(TP));
  if(!target) {
    write("Flamestrike who?\n");
    return 1;
  }
  if(!TP->valid_attack(target)) {
    write("You cannot attack "+capitalize(str)+".\n");
    return 1;
  }
  if(this_player()->query_level() >= 19 && TP->query_extra_level() >= 5) {
    pts=57;
    cost=25;
  } else if(TP->query_level() >= 15) {
    pts=40;
    cost=20;
  } else if(TP->query_level() >= 10) {
    pts=30;
    cost=15;
  } else if(TP->query_level() >= 5) {
    pts=20;
    cost=10;
  }
  if(target->query_ac() > pts/2)
    static_dam = pts/2;
  else
    static_dam = (int)target->query_ac();
  random_dam = pts - (static_dam*2);
  write("You cast a flamestrike spell at "+target->query_name()+".\n");
  tell_room(environment(TP),
"\n"+TPN+" bombards "+target->query_name()+" with a "+RED+"FLAMESTRIKE"+NORM+"!\n\n");  
  TP->spell_object(target,"flamestrike",
                   static_dam + random(random_dam), cost,
                   RED+target->query_name()+" burns.\n"+NORM,
                   RED+"You are surrounded by flames!\n"+NORM, 
                   "");
  return 1;
}
