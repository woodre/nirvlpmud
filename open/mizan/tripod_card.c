/**
 * This is the membership card to the Proving Grounds of the OverPowerLord.
 *
 *
 *
 */
#include "../definitions.h"
#define DATA_ROOT	"players/mizan/mines/data/tripodcards/"

/* our member variables */
object owner;
string owner_name;
int my_access_level;
int news_index;
int is_brief_mode;

/* these don't save */ 
static string new_hd;
static string new_body;

/* methods */
id(str) { return str == "card" || str == "tripod_card"; }

short()
{
	if(!owner_name) return 0;
	else
	return capitalize(owner_name) + 
	       "'s Tripod Card - Access Level " + my_access_level;
}

long()
{
	write(
  "  This is a hard plastic-like card that was issued to you at the\n"+
  "Proving Grounds of the OverPowerLord. It allows membership access\n"+
  "to the various levels within his stately underground arenas, and\n"+
  "also acts like a debit card to purchase items and services.\n"+
  "On the back of the card is some bold text saying:\n"+
  "  Give the command '3help' for instructions on how to use your card.\n\n");
	write("Your access level is '" + my_access_level + "'.\n");

}

get() { return 1; }

drop() { return 1; }

string query_auto_load() { return "/players/mizan/mine/items/tripod_card.c"; }

init()
{
   add_action("on_help","3help");

   add_action("news_post","3p");
   add_action("news_read","3r");
   add_action("news_delete","3d");
   add_action("news_headers","3h");
   add_action("news_grouplist","3l");
   add_action("news_next_group","3n");
   add_action("news_goto_group","3g");
   add_action("on_toss","3toss");
}

on_help()
{
  write("Some words appear in midair...\n\n"+
  "These are the things that you can do with your official Tripod Card,\n"+
  "available only at the Proving Grounds of the OverPowerLord, brought to\n"+
  "you by Carl's Jr...\n\n"+
  "3help      Shows the contents of this screen.\n"+
  "3toss      Toss away *gasp* this card! Why would you do such a thing!\n"+
  "3l         List available posting groups on the Tripod News Network.\n"+
  "3h         Lists the headers from within your currently selected group.\n"+
  "3r <num>   Reads the selected message within currently selected group.\n"+
  "3n         Goes to the next group in the Tripod News Network.\n"+
  "3g <num>   Goes the the specified posting group.\n"+
  "3p <title> Begins process of posting a message within current group.\n");
   return 1;
}

on_toss()
{
   write("You toss the Tripod card into the wind. You bastard!\n");
   say(this_player()->query_name() + " tosses out " + this_player()->query_possessive() +
       " Tripod card into the wind! It dies of rejection.\n");
   save_object(DATA_ROOT + owner_name);
   destruct(this_object());
   return 1;
}

reset(arg)
{
	if(arg) return;
	remove_call_out("delayed_reset");
	call_out("delayed_reset", 1);
}

delayed_reset()
{

	if(!environment(this_object()) || 
	   !environment(this_object())->is_player()) return;

	owner = environment(this_object());
	owner_name = environment(this_object())->query_real_name();

	/* if a player does not have a save file, we make one with basic
	 * access level.
	 */
	if(!restore_object(DATA_ROOT + owner_name))
	{
		/* establish a minimum level */
		if(owner->query_level() > 15) my_access_level = 12;
		else if(owner->query_level() > 5) my_access_level = 5;
		else my_access_level = 1;
		save_object(DATA_ROOT + owner_name);
	}

}

query_access_level() { return my_access_level; }
set_access_level(str) { my_access_level = str; }

is_brief_mode() { return is_brief_mode; }
toggle_brief_mode() { is_brief_mode = !is_brief_mode; }

query_news_index() { return news_index; }
set_news_index(str) { news_index = str; }

news_read(str) { return TRIPOD_DM->news_read(str); }
news_delete(str) { return TRIPOD_DM->news_delete(str); }
news_delete_group(str) { return TRIPOD_DM->news_delete_group(str); }
news_add_group(str) { return TRIPOD_DM->news_add_group(str); }
news_headers() { return TRIPOD_DM->news_headers(); }
news_grouplist() { return TRIPOD_DM->news_grouplist(); }
news_next_group() { return TRIPOD_DM->news_next_group(); }
news_goto_group(arg) { return TRIPOD_DM->news_goto_group(arg); }

news_post(str)
{
   if(!TRIPOD_DM->news_post_check(str)) return 1;
   input_to("get_body");
   new_hd = str;
   new_body = "";
   return 1;
}

get_body(str)
{
   if(str == "**")
   {
      TRIPOD_DM->news_feed(new_hd,new_body);
      new_body = 0; new_hd = 0;
      return 1;
   }

   if(str == "~q")
   {
      write("\n>> Aborted.\n");
      new_body = 0; new_hd = 0;
      return 1;
   }

   new_body = new_body + str + "\n";
   write("]");
   input_to("get_body");
}

