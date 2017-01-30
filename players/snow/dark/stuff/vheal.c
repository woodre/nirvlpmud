/* Heal found on ~/dark/mons/vampire.c - nonstorable */

#include "/players/snow/closed/cyber/color.h"

query_save_flag() { return 1; }
id(str) { return str == "vampire soul" || str == "soul"; }
short() { return BOLD+"DarK SouL"+OFF; }
long() { write(
    "    This is the soul of a vampire. If you were to 'merge' it to your\n\
     wounds, you would be swiftly healed... but not without a price.\n");
    return 1; }
weight() { return 1; }
get() { return 1; }
can_put_and_get() { return 1; }
value() { return 500; }
init() { add_action("merge_soul","merge"); }
int healnum;
reset(arg) { if(!arg) healnum = 3; }

merge_soul(str) {
  if(!str) { write("Merge what? <soul>\n"); return 0; }
  if(str == "soul") {
    write("You merge the vampire soul to your essence...\n");
    if(healnum == 3) write_file("/players/snow/log/heals",ctime(time())+" "+
    this_player()->query_real_name()+" used a DarK SouL.\n");
  say(capitalize(this_player()->query_real_name())+
    " merges a "+BOLD+"DarK SouL"+OFF+" to "+
  this_player()->query_possessive()+" essence.\n");
  this_player()->heal_self(75);
  this_player()->add_alignment(-200);
  healnum = healnum - 1;
  if(healnum == 0) {
    write("The "+BOLD+"DarK SouL"+OFF+" disintegrates.\n");
     destruct(this_object()); this_player()->recalc_carry();
  return 1; }
  return 1; }
}

quest_ob() { return 1; }

