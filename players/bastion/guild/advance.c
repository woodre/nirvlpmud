
#include "std_old.h"
#include "tune.h"
inherit "players/bastion/guild/guildroom";

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

extra_reset(arg) {
   object ob;
   if (arg)
      return;
   ob=clone_object("/players/bastion/guild/obj/board");
   move_object(ob, this_object());
}

#undef EXTRA_INIT
#define EXTRA_INIT\
add_action("cost_for_level"); add_verb("cost");\
add_action("advance"); add_verb("advance");\
add_action("list_quests"); add_verb("list");

ONE_EXIT("players/bastion/guild/jarvis_entry", "east",
   "The Sorcerers' Guild",
   "You are in a large marble hall dimly lit by flickering wall sconces.\n" +
   "The muted echo of your footsteps oppresses you as you approach a dias\n" +
   "at the opposite end of the hall. Hooded figures regard you silently.\n" +
   "Advance your skills if you feel you are worthy.\n\n" +
   "Commands: cost, advance, list (<number>)\n" ,
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
	
	male_title_str[19]	="the apprentice Wizard";
	male_title_str[18]	="the Archmage";
	male_title_str[17]	="the Mage";
	male_title_str[16]	="the Necromancer";
	male_title_str[15]	="the Sorcerer";
	male_title_str[14]	="the Enchanter";
	male_title_str[13]	="the Magician";
	male_title_str[12]	="the Spellbinder";
	male_title_str[11]	="the Warlock";
	male_title_str[10]	="the Thaumaturgist";
	male_title_str[9]	="the Cabalist";
	male_title_str[8]	="the Theurgist";
	male_title_str[7]	="the Conjurer";
	male_title_str[6]	="the Evoker";
	male_title_str[5]	="the master trickster";
	male_title_str[4]	="the trickster";
	male_title_str[3]	="the prestidigitator";
	male_title_str[2]	="the apprentice";
	male_title_str[1]	="the student of magic";
	male_title_str[0]	="the seeker of magic";

	fem_title_str = allocate(20);

	fem_title_str[19]	="the apprentice Wizard";
	fem_title_str[18]	="the Archmage";
	fem_title_str[17]	="the Mage";
	fem_title_str[16]	="the Necromancer";
	fem_title_str[15]	="the Sorcerer";
	fem_title_str[14]	="the Enchanter";
	fem_title_str[13]	="the Magicienne";
	fem_title_str[12]	="the Spellbinder";
	fem_title_str[11]	="the Witch";
	fem_title_str[10]	="the Thaumaturgist";
	fem_title_str[9]	="the Cabalist";
	fem_title_str[8]	="the Theurgist";
	fem_title_str[7]	="the Conjuress";
	fem_title_str[6]	="the Evoker";
	fem_title_str[5]	="the master trickstress";
	fem_title_str[4]	="the trickstress";
	fem_title_str[3]	="the prestidigitator";
	fem_title_str[2]	="the apprentice";
	fem_title_str[1]	="the student of magic";
	fem_title_str[0]	="the seeker of magic";
    }

    if (!player_ob || player_ob->query_gender() == "creature")
	return male_title_str[str];
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
	
	exp_str[19]	=  3000000;
	exp_str[18]	=  2200000; 
	exp_str[17]	=  1600000;
	exp_str[16]	=  1200000;
	exp_str[15]	=  900000;
	exp_str[14]	=  675000;
	exp_str[13]	=   506250;
	exp_str[12]	=   379688;
	exp_str[11]	=   284766;
	exp_str[10]	=   213574;
	exp_str[9]	=   160180;
	exp_str[8]	=   96108;
	exp_str[7]	=   57655;
	exp_str[6]	=    34598;
	exp_str[5]	=    25759;
	exp_str[4]	=    12456;
	exp_str[3]	=    7473;
	exp_str[2]	=    4484;
	exp_str[1]	=    2690;
	exp_str[0]	=       0;
    }
    return exp_str[str];
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
    object soul;
    player_ob = this_player();
    if (!this_player()->query_sorcerer()) {
       write("Only sorcerers may advance their skills here.\n");
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
          + " and you need "+NEEDED_QP+" to become a wizard.\n");
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
    call_other(player_ob, "set_level", next_level);
    call_other(player_ob, "set_title", title);
    if (exp < next_exp)
        call_other(player_ob, "add_exp", next_exp - exp);
    say(format("The Examiner says: Congratulations " + player_ob->query_name()
      + ", you are worthy of the title " + title[4..strlen(title)] + ".\n"));
    write(format("The Examiner says: Congratulations " + name_of_player +
     ", you are worthy of the title " + title[4..strlen(title)] + ".\n"));
    if (next_level == 20) {
	shout("A new Wizard has been born.\n");
       say(format("The Examiner says: Seek Leo the Archwizard, " + 
        name_of_player + ". Only he may grant you the powers of a " +
        "Wizard.\n"));
	return 1;
    }
    soul=present("magesoul", this_player());
    soul->set_guild_level(level);
    soul->think("~is now level " + (next_level) + ".");
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
    minexp = this_player()->query_exp() - get_next_exp(this_player()->query_level()-1);
    if (expcost < -minexp) {
        write ("You don't have enough experience available to raise an attribute.\n");
    return 1;
    }
     call_other(this_player(), raise, 1);
     call_other(this_player(), "add_exp", expcost);
    return 1;
}
