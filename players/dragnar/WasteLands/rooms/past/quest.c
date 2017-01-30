/*
    The end station of the Wastelands' quest

    Changelog: 
	Bal 1996-03-15:
	+ removed ; after #include
	+ made inherit come first
	+ "/players/dragnar/quest.c" modified (tell_room instead of say)
	  and built into this room
	* secured that only one person can push button (and solve quest)

*/

inherit "room/room";

#include <ansi.h>

#define LOG "/players/dragnar/WasteLands/log/Quest"
#define CAP capitalize((string) this_player()->query_real_name())

object player;
int x;

string realm() { return "NT"; }

void
init()
{
	::init();
	this_player()->set_fight_area();
	add_action("smash","smash");
	add_action("push","push");
}

reset(arg)
{
	if (arg) return;
	x = 1;
	set_light(1);
	short_desc=("Wastelands Quest");
	long_desc =
"This room seems to be a high security room.  A scientist is passed out\n"+
"on the floor, he seems to be sweating very badly.  As you take a closer look\n"+
"at him, you realize it is his picture on your autorization card.  Around\n"+
"you are many control panels and monitors.  One panel catches your eye because\n"+
"it is labeled 'launch sequence'.\n";
	items=({
"launch sequence panel",
"The numbers are flashing very rapidy.  They seem to be moveing faster\n"+
"and faster as time moves on.  The panel is covered with glass and a button\n"+
"is next to the launch sequence numbers",
"glass",
"It reflects the light into your eyes and you want to smash it",
"button",
"The brightness of the red color is amazing, however it is covered by the glass",
"panel",
"The numbers are flashing very rapidy.  Them seem to be moveing  faster\n"+
"and faster as time moves on.  The panel is covered with glass and a button\n"+
"is next to the launch sequence numbers",
	});
	dest_dir=({
	});
}

status
smash(string str)
{
    if (str == "glass") {
	if (x != 1) {
	    write("The glass has already been broken.\n");
	    return 1;
	}
	if (!present("timer", this_player())) {
	    write("Your hand bounces off the glass and does no damage.\n");
	    return 1;
	}
	write("You make a fist and shatter the glass in one blow!\n");
	say(this_player()->query_name() +
	    " makes a fist and breaks the glass on the pannel.\n");
	x = 2;
	return 1;
    }
}

status
push(string str)
{
    object finished;

    if (str == "button") {
	if (x == 1) {
	    write("It is covered by the glass.\n");
	    return 1;
	}
	if (!present("timer", this_player())) {
	    write("The button won't budge.\n");
	    return 1;
	}
	if (x == 3) {
	    write("There is no effect.\n");
	    return 1;
	}
	write("You push the button and the sequence numbers stop flashing.\n");
	destruct(present("timer", this_player()));

	call_other(this_player(), "set_quest", "waste_lands");
   write_file(LOG, ctime(time())+": "+CAP+" solved Wastelands Quest.\n");
  player = this_player();

	call_out("cvcv",10);
	call_out("kkkk",25);
	call_out("jbjb",35);
	call_out("ncnc",50);
	x = 3;
	return 1;
    }
}

void
cvcv()
{
	tell_room(this_object(),
"The siren stops its erie sound.  The silence seems to be very empty\n"+
"after all of the noise.\n");
}

void
kkkk()
{
    tell_room(this_object(),
"\nThe scientist slowly awakes and stands next to you.\n");
}

void
jbjb()
{
    tell_room(this_object(),
"\nThe scientist says:  Congratulations chosen one, you have saved the\n"+
"land.  Take your reward now and go...Your time is limited here.\n");
}

void
ncnc()
{
    tell_room(this_object(),
"\nSomewhere in the town you hear a tremendous roar of cheers from\n"+
"what seems like ten thousand people.  Somehow you know that the\n"+
"Wastelands no longer exist.\n\n\n");

    if( player ) {
   player->move_player("church#/room/church");
    command("look",player);
    }
    else {
	move_object(environment(this_object()), "/room/church");
	command("look", environment(this_object()));
    }
}

void fatality()
{
    destruct(this_object());
}
