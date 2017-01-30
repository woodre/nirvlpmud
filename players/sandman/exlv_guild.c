#include "std_old.h"
#include "tune.h"

int tlv,tnum;

#undef EXTRA_INIT
#define EXTRA_INIT\
add_action("cost_for_extra_level"); add_verb("cost");\
add_action("advance"); add_verb("advance");\
add_action("list_quests"); add_verb("list");

ONE_EXIT("room/adv_guild", "down",
   "The senior adventurers guild",
   "At the top of the stairs you find the senior adventurers guild.\n"+
   "Here is where you may come to advance your level beyond 19.\n"+
    "This room is a furnished better than the guild room below, wood\n"+
    "paneling on the walls with many nice chairs to sit on.\n"+
   "You have to come here when you want to advance your level to 20 and beyond.\n" +
   "You can also buy experience for a new level.\n" +
   "Commands: cost, advance, list (number).\n" +
   "It will cost 4000 coins per level to advance plus the cost of any experience\n"+
  "you need to buy.\n"+
   "There are some stairs leading down.\n",1)

int next_extra_level;
int valexp;
int next_exp;
int extra_level;
int exp;
string title;         /* now with arrays. :) */
object player_ob;
string banished_by;

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
	title_str = allocate(24);
	
        title_str[22]   ="no one should have this title";
        title_str[21]   ="the near apprentice wizard";
        title_str[20]   ="the grand master elder of the mortals";
	title_str[19]	="the grand master elder sorcerer";
	title_str[18]	="the elder of the mortals";
	title_str[17]	="the elder sorcerer";
	title_str[16]	="the master of the seasons";
	title_str[15]	="the master of the south wind";
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
	exp_str = allocate(24);
	
        exp_str[22]     = 999999999;
        exp_str[21]     = 12121212;
        exp_str[20]     = 11111111;
	exp_str[19]	= 10000000;
	exp_str[18]	=  9000000; 
	exp_str[17]	=  8100000;
	exp_str[16]	=  7300000;
	exp_str[15]	=  6900000;
	exp_str[14]	=  6600000;
	exp_str[13]	=   6300000;
	exp_str[12]	=   6000000;
	exp_str[11]	=   5700000;
	exp_str[10]	=   4800000;
	exp_str[9]	=   5100000;
	exp_str[8]	=   4800000;
	exp_str[7]	=   4500000;
	exp_str[6]	=    4200000;
	exp_str[5]	=    3900000;
	exp_str[4]	=    3600000;
	exp_str[3]	=    3300000;
	exp_str[2]	=    2900000;
	exp_str[1]	=    2700000;
	exp_str[0]	=       2500000;
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
    if (extra_level >= 21) {
        write("If your quests are complete, you may advance to wizard level downstairs.\n");
	return 1;
    }
    exp = call_other(player_ob, "query_exp", 0);
    get_extra_level(extra_level);
    if (next_exp <= exp) {
	write("It will cost you nothing to be promoted.\n");
	return 1;
    }
    if ((next_exp - exp) > next_exp/10 || (next_exp - exp) > 15000) {
     write("You must be closer to the next level before buying experience.\n");
    return 1;
   }
    write("It will cost you "); write((next_exp - exp) * 1000 / EXP_COST);
    tnum = this_player()->query_level() + next_extra_level;
    tlv = this_player()->query_level();
    write(" gold coins to advance to level "); write(tlv+"+"+next_extra_level+" ("+tnum+")");
    write(".\n");
    return 1;
}

advance() {
    string name_of_player;
    int cost;
    player_ob = this_player();
    name_of_player = call_other(player_ob, "query_name", 0);
    extra_level = call_other(player_ob, "query_extra_level", 0);
    if(this_player()->query_money() < 4000){
      write("You need at least 4000 coins to advance your level.\n");
     return 1;
      }
    if (extra_level == -1)
	extra_level = 0;
    exp = call_other(player_ob, "query_exp", 0);
    title = call_other(player_ob, "query_title", 0);
    if (extra_level >= 21) {
	write("You are still "); write(title); write("\n");
        write("If your quests are complete you may advance to wizard level downstairs.\n");
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
    call_other(player_ob, "set_extra_level", next_extra_level);
    call_other(player_ob, "set_title", title);
    tnum = this_player()->query_level() + next_extra_level;
    tlv = this_player()->query_level();
   say(call_other(player_ob, "query_name", 0) + " is now level " +
	tlv+"+"+next_extra_level+" .\n");
    log_file("ADVANCE", ctime(time())+" "+name_of_player+" to player_level "+tlv+"+"+next_extra_level+" \n");
    this_player()->add_money(-4000);
   write("You pay your 4000 coin advancement/training fee.\n");
    if (exp < next_exp)
        call_other(player_ob, "add_exp", next_exp - exp);
    if (next_extra_level < 7) {
	write("You are now " + name_of_player + " " + title +
	      " (level " + tlv+"+"+next_extra_level+" ).\n");
	return 1;
    }
    if (next_extra_level < 14) {
	write("Well done, " + name_of_player + " " + title +
	      " (level " + tlv+"+"+next_extra_level+" ).\n");
	return 1;
    }
    if (next_extra_level < 21) {
	write("Welcome to your new class, mighty one.\n" +
	      "You are now " + title + " (level " + tlv+"+"+next_extra_level+" ).\n");
    }
    if (next_extra_level == 21) {
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
    if (extra_level >= 42)
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
check_level(arg) {
   int a1,a2,a3;
   a2 = arg - 1;
   a1=get_next_exp(a2);
   return a1;
}

