#include "std_old.h"
#include "tune.h"


#undef EXTRA_INIT
#define EXTRA_INIT\
add_action("cost_for_extra_level"); add_verb("cost");\
add_action("advance"); add_verb("advance");\
add_action("list_quests"); add_verb("list");

ONE_EXIT("players/bastion/guild/jarvis_entry", "west",
   "The senior advancement hall",
   "You have to come here when you want to advance your extra level.\n" +
   "You can also buy points for a new extra level.\n" +
   "Commands: cost, advance, list (number).\n" ,
  1)

int next_extra_level;
int valexp;
int next_exp;
int extra_level;
int exp;
string title;         /* now with arrays. :) */
object player_ob;
string banished_by;

/* some minor changes by Iggy. */
/* get extra_level asks get_next_exp() and  get_next_title() */

get_extra_level(str)
{
	extra_level = str;
  
	next_exp   = get_next_exp(extra_level);
	next_extra_level = extra_level + 1 ;   
player_ob = this_player();
	title      = get_new_title(extra_level);
}    

string title_str;
/*xxx  return title */
get_new_title(str)
{
    if (!title_str){
	title_str = allocate(20);
	
	title_str[19]	="the grand master elder of the mortals";
	title_str[18]	="the elder of the mortals";
	title_str[17]	="the elder sorcerer";
	title_str[16]	="the master of the seasons";
	title_str[15]	="the of the south wind";
	title_str[14]	="the master of the night sky";
	title_str[13]	="the elder of the southland";
	title_str[12]	="the elder magician";
	title_str[11]	="the elder conjurer";
	title_str[10]	="the legendary warrior";
	title_str[9]	="the master warrior";
	title_str[8]	="the legend of the east wind";
	title_str[7]	="the cave master";
	title_str[6]	="the elder warrior";
	title_str[5]	="the master of magic";
	title_str[4]	="the elder fighter";
	title_str[3]	="the grand master ranger";
	title_str[2]	="the master of the nerf ball";
	title_str[1]	="the master of silly putty";
	title_str[0]	="the master of the yo-yo secret";

    }
     if(str == -1) return "the grand master sorcerer";
	return title_str[str];
}


int exp_str;

/*  returns the next_exp. */
get_next_exp(str) {
    if(!exp_str){
	exp_str = allocate(20);
	
	exp_str[19]	=   12500000;
	exp_str[18]	=   12000000; 
	exp_str[17]	=   11500000;
	exp_str[16]	=   11000000;
	exp_str[15]	=   10500000;
	exp_str[14]	=   10000000;
	exp_str[13]	=    9500000;
	exp_str[12]	=    9000000;
	exp_str[11]	=    8500000;
	exp_str[10]	=    8000000;
	exp_str[9]	=    7500000;
	exp_str[8]	=    7000000;
	exp_str[7]	=    6500000;
	exp_str[6]	=    6000000;
	exp_str[5]	=    5500000;
	exp_str[4]	=    5000000;
	exp_str[3]	=    4500000;
	exp_str[2]	=    4000000;
	exp_str[1]	=    3500000;
	exp_str[0]	=    3000000;
    }
   if (str == -1) return 4;
    return exp_str[str];
}

/*
 * Special function for other guilds to call. Arguments are current extra_level
 * and experience points.
 */
query_cost_for_extra_level(l, e) {
    extra_level = l;
    exp = e;
    get_extra_level();
    if (next_exp <= exp)
	return 0;
    return (next_exp - exp) * 1000 / EXP_COST;
}

cost_for_extra_level() {
    player_ob = this_player();
    extra_level = call_other(player_ob, "query_extra_level", 0);
    if (extra_level >= 20) {
	write("You will have to seek other ways.\n");
	return 1;
    }
    exp = call_other(player_ob, "query_exp", 0);
    get_extra_level(extra_level);
    if (next_exp <= exp) {
	write("It will cost you nothing to be promoted.\n");
	return 1;
    }
    if ((next_exp - exp) > next_exp/10 || (next_exp - exp) > 15000) {
     write("You must be closer to the next extra_level before buying experience.\n");
    return 1;
   }
    write("It will cost you "); write((next_exp - exp) * 1000 / EXP_COST);
    write(" gold coins to advance to extra_level "); write(next_extra_level);
    write(".\n");
    return 1;
}

advance() {
    string name_of_player;
    int cost;
    player_ob = this_player();
    name_of_player = call_other(player_ob, "query_name", 0);
    extra_level = call_other(player_ob, "query_extra_level", 0);
    if (extra_level == -1)
	extra_level = 0;
    exp = call_other(player_ob, "query_exp", 0);
    title = call_other(player_ob, "query_title", 0);
    if (extra_level >= 20) {
	write("You are still "); write(title); write("\n");
	return 1;
    }
    get_extra_level(extra_level);
    cost = (next_exp - exp) * 1000 / EXP_COST;
    if (next_exp > exp) {
	if (call_other(player_ob, "query_money", 0) < cost) {
	    write("You don't have enough gold coins.\n");
	    return 1;
	}
      if((next_exp - exp) > next_exp/10 || (next_exp - exp) > 15000) {
    write("You must be closer to the next extra level before buying experience.\n");
    return 1;
    }
	call_other(player_ob, "add_money", - cost);
    }
    say(call_other(player_ob, "query_name", 0) + " is now extra level " +
	next_extra_level + ".\n");
    call_other(player_ob, "set_extra_level", next_extra_level);
    call_other(player_ob, "set_title", title);
    log_file("ADVANCE", ctime(time())+" "+name_of_player+" to extra_level "+next_extra_level + "\n");
    if (exp < next_exp)
        call_other(player_ob, "add_exp", next_exp - exp);
    if (next_extra_level < 7) {
	write("You are now " + name_of_player + " " + title +
	      " (extra level " + next_extra_level + ").\n");
	return 1;
    }
    if (next_extra_level < 14) {
	write("Well done, " + name_of_player + " " + title +
	      " (extra level " + next_extra_level + ").\n");
	return 1;
    }
    if (next_extra_level < 20) {
	write("Welcome to your new class, mighty one.\n" +
	      "You are now " + title + " (extra level " + next_extra_level + ").\n");
    }
    if (next_extra_level == 20) {
      write("You are now a grand master elder of mortals.\n");
	return 1;
    }
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
correct_extra_level(player)
{
    extra_level = call_other(player, "query_extra_level", 0);
    exp = call_other(player, "query_exp", 0);
    /* Shouldn't "correct" wizards. */
    if (extra_level >= 20)
	return;
    get_extra_level(extra_level);
    while (exp < next_exp) {
	extra_level -= 1;
        get_extra_level(extra_level);
    }
    call_other(player, "set_extra_level", next_extra_level);
   if(next_extra_level != 0)
    call_other(player, "set_title", title);
}
