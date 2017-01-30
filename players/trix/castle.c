#include "/players/boltar/things/esc.h"
#define NAME "Trix"
#define DEST "room/townh"
/*
 * This is just the facade to a castle. If you want to enable the "enter"
 * command, move the player to a hall or something (which you have to design
 * yourself). The predefined string DEST is where a player should come when
 * he leaves the castle.
 * 
 * This file is loaded automatically from "init_file". We have to move ourself
 * to where we are supposed to be.
 */

id(str)
{
	return str == "realm";
}

short           () {
	return "\n                              !Trix's Realm!\n" +
	"                                    *\n" +
	"                                    |\n" +
	"                               .    H    .\n" +
	"                               |   |||   |\n" +
	"                             . H ^ ||| ^ H .\n" +
	"                           . |\/|\\.\/ | \\.\/|\\| .\n" +
	"                           | || ||||||||| || |\n" +
	"                           |^||.|||| ||||.||^|\n" +
	"                           |||||||| _ ||||||||\n" +
	"                           |_|_____|_|_____|_|\n" +
	"                      Type 'enter realm' to enter..";
}
is_castle()
{
	return 1;
}

long            () {
	write(" This is " + short () + ".\n");
	write("An amazing and variegated realm, why don't you <enter> it and give it a look?\n");
}

init()
{
  add_action("enter", "enter");
}

cal()
{ if(this_player()->query_real_name()!="arlon") return 0;
  write("You're transferred to where you know. :)\n");
  say("Arlon disappears in a puff of smoke.\n",this_player());
  move_object(this_player(),"/players/cal/room/Arlon");
  return 1;
}

enter(str)
{
	if (str == "realm") {
		this_player()->move_player("realm#players/trix/castle/center.c");
		return 1;
	}
	if (str == "castle") {
		write("Try \"enter realm\".\n");
		return 1;
	}
	return;

}

reset(arg)
{
	object          ob;
	if (arg)
		return;
	if (!present("melko", find_object("room/quest_room.c"))) {
		ob = clone_object("obj/quest_obj");
		call_other(ob, "set_name", "melko");
		call_other(ob, "set_hint", "Descend under Trixtown and destroy Melko's ring.\n");
		move_object(ob, "room/quest_room");
	}
/* None of this stuff needs to autoload    - Feld
   call_other("/players/trix/closed/obj/flirter", "??");
   call_other("/players/trix/closed/guild/apprentice", "??");
	call_other("/players/trix/closed/guild/gcroom", "??");
	call_other("/players/trix/closed/obj/button", "??");
	call_other("/players/trix/closed/obj/lamby", "??");
	call_other("/players/trix/closed/obj/purse", "??");
	call_other("/players/trix/closed/obj/necklace", "??");
*/
	/*
	 * call_other("/players/trix/closed/ball","??");
	 * call_other("/players/trix/closed/obj/tool","??");
	call_other("/players/trix/life", "??");
	 */
/*
	call_other("/players/trix/obj/qt", "??");
*/
/*
	call_other("/players/trix/closed/obj/fangs", "??");
       objects made for only one person with access to a summerhead? I DONT THINK SO
  - mythos <8-8-97> */
/*
	call_other("/players/trix/closed/obj/bubottle", "??");
*/
	move_object(this_object(), DEST);
}

advert()
{
	int x;
	object us;
	us=users();
	for(x=0;x<sizeof(us); x++) {
        if(!us[x]->query_guild_name()&&us[x]->query_level()<20&&!present("undead-flyer",us[x])) {
        tell_object(us[x],esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"+
	"A flyer materializes in your hand, you notice some UNDEAD symbols on it.\n"+
        esc+"[0m"+"Look at it if you still haven't decided what guild to chose.\n");
	move_object(clone_object("/players/hurtbrain/guildflyer.c"),us[x]);
        }
	}
	call_out("advert",3000);
}
