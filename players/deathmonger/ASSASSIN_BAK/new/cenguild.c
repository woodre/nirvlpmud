#include "std_old.h"
#include "tune.h"


#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

extra_reset(arg) {
   if (arg)
      return;
}

#undef EXTRA_INIT
#define EXTRA_INIT\
add_action("cost_for_level"); add_verb("cost");\
add_action("advance"); add_verb("advance");\
add_action("banish"); add_verb("banish");\
add_action("north"); add_verb("north");\
add_action("raise"); add_verb("raise");\
add_action("list_quests"); add_verb("list");

ONE_EXIT("players/deathmonger/closed/workroom", "north",
   "The assassins guild",
   "Welcome assassin!\n"+
   "You have to come here when you want to advance your level.\n" +
   "You can also buy points for a new level.\n" +
   "Commands: cost, advance, list (number), help.\n"+
   "raise <str, sta, wil, mag, pie, ste, luc, int>\n",
   1)

int next_level;
int valexp;
int next_exp;
int level;
int exp;
string title;
string guname;
object player_ob;
string banished_by;

/* some minor changes by Iggy. */
/* get level asks get_next_exp() and  get_next_title() */

get_level(str)
{
   level = str;
   
   next_exp   = get_next_exp(level);
   next_level = level + 1 ;
   player_ob = this_player();
   title      = get_new_title(level);
}

string male_title_str, fem_title_str, neut_title_str;
/*xxx  return title */
get_new_title(str)
{
   if (!male_title_str){
      male_title_str = allocate(20);
      
      male_title_str[19]      ="the utter novice";
      male_title_str[18]      ="the Master of Trades";
      male_title_str[17]      ="the Brother of the Blade";
      male_title_str[16]      ="the Godfather";
      male_title_str[15]      ="the sharpened apprentice";
      
      fem_title_str = allocate(20);
      
      fem_title_str[19]       ="the utter novice";
      fem_title_str[18]       ="the Mistress of Secrets";
      fem_title_str[17]       ="the Sister of the Blade";
      fem_title_str[16]       ="the Godmother";
      fem_title_str[15]       ="the sharpened apprentice";
      
      neut_title_str = allocate(20);
      
      neut_title_str[19]      ="the utter novice";
      neut_title_str[18]      ="the Master of Slaughter";
      neut_title_str[17]      ="the Creature of Destruction";
      neut_title_str[16]      ="the Sleek Avenger";
      neut_title_str[15]      ="the Deadly Animal";
      
   }
   if (!player_ob || player_ob->query_gender() == "creature")
      return neut_title_str[str];
   else if (player_ob->query_gender() == "male")
      return male_title_str[str];
   else
      return fem_title_str[str];
}


int exp_str;

/*  returns the next_exp. */
get_next_exp(str) {
   if(!exp_str){
      exp_str = allocate(20);
      
      exp_str[19]=  3000000;   /* 2500000 */
      exp_str[18]=  2500000;   /* 2000000 */
      exp_str[17]=  2000000;   /* 1367106; */
      exp_str[16]=  1500000;   /* 1040028; */
      exp_str[15]=  1000000;   /* 820028; */
      
   }
   return exp_str[str];
}

/*
* This routine is called by monster, to calculate how much they are worth.
* This value should not depend on the tuning.
*/
query_cost(l) {
   player_ob = this_player();
   level = l;
   if (level >= 20)
      return 2000000;
   get_level(level);
   valexp = 12*next_exp/30;
   return valexp;
   /*
   return next_exp;
   */
}

/*
* Special function for other guilds to call. Arguments are current level
* and experience points.
*/
query_cost_for_level(l, e) {
   level = l;
   exp = e;
   get_level();
   if (next_exp <= exp)
      return 0;
   return (next_exp - exp) * 1000 / EXP_COST;
}

cost_for_level() {
   player_ob = this_player();
   level = call_other(player_ob, "query_level", 0);
   if (level >= 20) {
      write("You will have to seek other ways.\n");
      return 1;
   }
   exp = call_other(player_ob, "query_exp", 0);
   get_level(level);
   if (next_exp <= exp) {
      write("It will cost you nothing to be promoted.\n");
      return 1;
   }
   if ((next_exp - exp) > next_exp/10 || (next_exp - exp) > 15000) {
      write("You must be closer to the next level before buying experience.\n");
      return 1;
   }
   write("It will cost you "); write((next_exp - exp) * 1000 / EXP_COST);
   write(" gold coins to advance to level "); write(next_level);
   write(".\n");
   return 1;
}

advance() {
   string name_of_player;
   int cost;
   player_ob = this_player();
   guname=player_ob->query_guild_name();
   if (!guname=="assassin") {
      write("You must advance at your guild hall.");
      write("\n");
      return 1;
   }
   name_of_player = call_other(player_ob, "query_name", 0);
   level = call_other(player_ob, "query_level", 0);
   if (level == -1)
      level = 0;
   exp = call_other(player_ob, "query_exp", 0);
   title = call_other(player_ob, "query_title", 0);
   if (level >= 20) {
      write("You are still "); write(title); write("\n");
      return 1;
   }
   get_level(level);
   if(next_level == 20 && this_player()->query_quest_point() < NEEDED_QP) {
      write("You have "+this_player()->query_quest_point() + " quest points"
         + " and you need "+NEEDED_QP+" to become wizard.\n");
      return 1;
   }
   cost = (next_exp - exp) * 1000 / EXP_COST;
   if (next_exp > exp) {
      if (call_other(player_ob, "query_money", 0) < cost) {
         write("You don't have enough gold coins.\n");
         return 1;
       }
      if((next_exp - exp) > next_exp/10 || (next_exp - exp) > 15000) {
         write("You must be closer to the next level before buying experience.\n");
         return 1;
       }
      call_other(player_ob, "add_money", - cost);
   }
   say(call_other(player_ob, "query_name", 0) + " is now level " +
      next_level + ".\n");
   call_other(player_ob, "set_level", next_level);
   call_other(player_ob, "set_title", title);
   if (exp < next_exp)
      call_other(player_ob, "add_exp", next_exp - exp);
   if (next_level < 7) {
      write("You are now " + name_of_player + " " + title +
         " (level " + next_level + ").\n");
      return 1;
   }
   if (next_level < 14) {
      write("Well done, " + name_of_player + " " + title +
         " (level " + next_level + ").\n");
      return 1;
   }
   if (next_level < 20) {
      write("Welcome to your new class, mighty one.\n" +
         "You are now " + title + " (level " + next_level + ").\n");
   }
   if (next_level == 20) {
      write("A new Wizard has been born.\n");
      shout("A new Wizard has been born.\n");
      write("If you want a castle of your own, seek out Leo the archwizard,\n");
      write("and ask him.\n");
      return 1;
   }
   return 1;
}

banish(who){
   if(!who){
      write("Banish who?\n");
      return 1;
   }
   if (restore_object("players/deathmonger/ASSASSIN/banished/" + who)) {
      write("That name is already banished.\n");
      return 1;
   }
   banished_by = call_other(this_player(), "query_name");
   title = call_other(this_player(), "query_title");
   if (banished_by == "Someone") {
      write("You must not be invisible!\n");
      return 1;
   }
   save_object("players/deathmonger/ASSASSIN/banished/" + who);
   return 1;
}

north() {
   call_other(this_player(), "move_player",
      "north#players/deathmonger/closed/workroom");
   return 1;
}

list_quests(num)
{
   int qnumber;
   if (num == "all") {
      call_other("room/quest_room", "list_all");
      return 1;
   }
   if (num && (sscanf(num, "%d", qnumber) == 1))
      call_other("room/quest_room", "list", qnumber);
   else
      call_other("room/quest_room", "count", 0);
   return 1;
}

query_drop_castle() {
   return 1;
}

correct_level(player)
{
   level = call_other(player, "query_level", 0);
   exp = call_other(player, "query_exp", 0);
   /* Shouldn't "correct" wizards. */
   if (level >= 20)
      return;
   get_level(level);
   while (exp < next_exp) {
      level -= 1;
      get_level(level);
   }
   if (next_level == 20 && call_other("room/quest_room", "count", 0))
      get_level(18);
   call_other(player, "set_level", next_level);
   call_other(player, "set_title", title);
}

raise(str) {
   string attrib,raise,thing;
   int new,expcost,current,minexp;
   if (str !="str" && str !="sta" && str != "wil" && str != "mag" &&
         str != "pie" &&
      str != "ste" && str != "luc" && str != "int")
   {
      write ("Raise what?\n");
      return 1;
   }
   if(this_player()->query_guild_name() != "assassin") {
      write("You must raise your attributes at your guild hall.\n");
      return 1;
   }
   if (call_other(this_player(), "query_level", 0) > 19) {
      write("wizards cannot advance attributes.\n");
      return 1;
   }
   if (str == "str") {
      attrib = "strength";
   }
   if (str == "sta"){
      attrib = "stamina";
   }
   if (str == "wil") attrib = "will_power";
   if (str == "mag") attrib = "magic_aptitude";
   if (str == "pie") attrib = "piety";
   if (str == "ste") attrib = "stealth";
   if (str == "luc") attrib = "luck";
   if (str == "int") attrib = "intelligence";
   raise = "raise_" + attrib;
   current = call_other(this_player(), "query_attrib", str);
   new = current + 1;
   /* let's see what it costs */
   if(str == "ste" || str == "luc"){
      if(current < 12) expcost = -BONUS_ATTRIB_COST;
      if(current < 16 && current > 11) expcost = -BONUS_ATTRIB_COST_TWO;
      if(current < 24 && current > 15) expcost = -BONUS_ATTRIB_COST_THREE;
      if(current > 24){
         write(attrib+" is at highest possible value.\n");
         return 1;
      }
   }
   /* Sorry, roughing the quarterback.  Visit the penalty box. */
   else if(str == "pie" || str == "mag"){
      if(current < 12) expcost = -POOR_ATTRIB_COST;
      if(current < 16 && current < 11) expcost = -POOR_ATTRIB_COST_TWO;
      if(current < 20 && current > 15) expcost = -POOR_ATTRIB_COST_THREE;
      if(current > 15){
         write(attrib+" is at highest possible value.\n");
         return 1;
    }
   }
   else { /* use default costs */
      if (current < 12) expcost = -ATTRIB_COST;
      if (current < 16 && current > 11) expcost = -ATTRIB_COST_TWO;
      if (current < 20 && current > 15) expcost = -ATTRIB_COST_THREE;
      if (current > 19) {
         write (attrib + " is at highest possible value.\n");
         return 1;
      }
   }
   minexp = this_player()->query_exp() -
   get_next_exp(this_player()->query_level() - 1);
   if (expcost < -minexp) {
      write("You don't have enough experience available to raise"+
         " an attribute.\n");
      return 1;
   }
   call_other(this_player(), raise, 1);
   call_other(this_player(), "add_exp", expcost);
   return 1;
}
