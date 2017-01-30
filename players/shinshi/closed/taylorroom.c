inherit "/room/room";
#include <ansi.h>

#define OWNER "shinshi"

int shield;

reset(arg)
{
::reset(arg);

if(!present("taylor")) {
	move_object(clone_object("/players/shinshi/closed/taylor.c"),this_object());
}

if(arg) return;
	set_light(1);
	short_desc = "Taylor Swift's Room";
	long_desc =
		"This is Taylor Swift's room. Laying on a holding rack\n"+
		"is her guitar in which she uses for everything. You\n"+
		"notice out of the corner of your eye someone step into\n"+
		"the room. Taylor Swift, the country singer, is now in\n"+
		"your presence.\n";

dest_dir =
({
	"/players/shinshi/workroom.c",	"workroom",
	});
}

query_no_fight() { return 1; }
no_light_damage() { return 1; }

taylor(str){

if(!str){ write("What would you like to request?\n"); return 1; }
if(str != "blowjob"){ write("What are you trying to do?! If you request the wrong thing, this might end badly!\n"); return 1; }
if(str == "blowjob")
{
	write("Taylor calls in two security guards. They grab you and haul you away!\n");
	say(this_player()->query_name()+" just tried to ask Taylor Swift for a blowjob! Two security guards haul him away for harassment!\n");
	call_other(this_player(), "move_player","the room by force#players/shinshi/closed/playroom.c");
	say(this_player()->query_name()+" is hauled off.\n");
	return 1;
}
}

init() {
  ::init();
  if(this_player()->query_real_name() != OWNER && shield == 1) {
    write("You feel an electric shock and see a flash of white light as\n");
    write("you rebound off of the shield.\n");
    this_player()->move_player("off the shields#room/church");
  }

	if(this_player()->query_real_name()!=OWNER) {
	add_action("taylor","request");
}
	  if(this_player()->query_real_name()==OWNER) {
	add_action("request","request");
	add_action("shields","shields");
   }
}


request(str){

if(!str){ write("What would you like to request?\n"); return 1; }
if(str != "blowjob"){ write("Try requesting a blowjob, idiot\n"); return 1; }
if(str == "blowjob")
{
	write("Taylor walks over to you, drops on her hands and knees, rips off your pants and gives you the best blowjob you have ever received.\n");
	say("You watch as Taylor Swift stands up, walks over to Shinshi and gives him a blowjob. You feel jealous.\n");
	return 1;
}
}

shields() {
  if(this_player()->query_real_name()!=OWNER)
    return 0;
  if(shield) {
    write("You deactivate the shields.\n");
    shield=0;
    return 1;
  }
  else {
    write("You activate the shields.\n");
    shield=1;
    return 1;
  }
}