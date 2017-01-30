
#include "std_old.h"
#include "tune.h"
inherit "players/bastion/guild/guildroom";

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

extra_reset(arg) {
   object ob;
   if (arg)
      return;
}

#undef EXTRA_INIT
#define EXTRA_INIT\
add_action("cost_for_level"); add_verb("cost");\
add_action("raise"); add_verb("raise");

ONE_EXIT("players/bastion/guild/jarvis_hall", "west",
   "Gymnasium",
   "You are in the gymnasium.\n\n" +
   "Commands: cost, raise <attribute>\n",
   1)

int next_level;
int valexp;
int next_exp;
int level;
int exp;
string title;         /* now with arrays. :) */
string guname;
object player_ob;
string banished_by;

/* some minor changes by Iggy. */
/* get level asks get_next_exp() and  get_next_title() */

cost_for_level() {
    object player;
    string temp, *attrib;
    int x, current;
    player = this_player();
    attrib = ({ "str", "sta", "wil", "mag",
     "pie", "ste", "luc", "int" });
    level = call_other(player, "query_level", 0);
    if (level > 19) {
      write("Wizards cannot advance attributes.\n");
      return 1;
    }
    write("Cost to raise:\n\n");
    for(x=0; x < sizeof(attrib); x++) {
      write((x==4 ? "\n" : "") + attrib[x] + "--");
      current = player->query_attrib(attrib[x]);
      if (current < 12) write(ATTRIB_COST);
      else if (current < 16) write(ATTRIB_COST_TWO);
      else write(ATTRIB_COST_THREE);
      write("\t");
    }
    exp = call_other(player, "query_exp", 0);
    exp -= ("players/bastion/guild/advance")->get_next_exp(player->query_level() - 1);
    if (exp < 1) exp=0;
    write("\n\nYou have " + exp + " experience points available to advance " +
     "your attributes.\n");
    return 1;
}

query_drop_castle() { return 1; }

raise(str) {
    string attrib,raise,thing;
    int new,expcost,current,minexp,level;
  if (str !="str" && str !="sta" && str != "wil" && str != "mag" && str !="pie" && str != "ste" && str != "luc" && str != "int")
     {
       write ("Raise what?\n");
       return 1;
     }
   if(!this_player()->query_sorcerer()) {
     write("Only sorcerers may raise their attributes here.\n");
     return 1;
   }
    if (call_other(this_player(), "query_level", 0) > 19) {
           write("Wizards cannot advance attributes.\n");
           return 1;
         }
   if (str == "str") attrib = "strength";
   if (str == "sta") attrib = "stamina";
   if (str == "wil") attrib = "will_power";
   if (str == "mag") attrib = "magic_aptitude";
   if (str == "pie") attrib = "piety";
   if (str == "ste") attrib = "stealth";
   if (str == "luc") attrib = "luck";
   if (str == "int") attrib = "intelligence";
     raise = "raise_" + attrib;
     current = call_other(this_player(), "query_attrib", str);
     new = current + 1;
/*
     log_file("ATTRIB", this_player()->query_real_name() + " Raised " + attrib +" from " + current + " to " + new + "\n");
*/
     if (current < 12) expcost = -ATTRIB_COST;
     if (current < 16 && current > 11) expcost = -ATTRIB_COST_TWO;
     if (current < 20 && current > 15) expcost = -ATTRIB_COST_THREE;
     if (((attrib=="strength" || attrib=="stamina") && current > 13) ||
      current > 19) {
            write (capitalize(attrib) + " is at highest possible value.\n");
            return 1;
            }
    level=this_player()->query_level();
    minexp=this_player()->query_exp();
    minexp-=("players/bastion/guild/advance")->get_next_exp(level-1);
    if (expcost < -minexp) {
     write ("You don't have enough experience available to raise an attribute.\n");
    return 1;
    }
     call_other(this_player(), raise, 1);
     call_other(this_player(), "add_exp", expcost);
    return 1;
}
