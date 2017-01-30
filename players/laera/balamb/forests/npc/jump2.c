inherit "room/room";
#include "/players/laera/closed/ldef.h"
#include "/players/laera/closed/ansi.h"

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = BOLD + "Gateway" + OFF;
long_desc =
	"   Clouds swirl through the sky, clearing momentarily to reveal\n"+
	"twinkling stars in the distance but there is no wind to be felt.\n" +
	"Several arched gateways hang suspended against the darkened sky.\n" +
	"There is a quiet hum in the air that can be felt more than heard.\n" +
	"Each of the gateways glows with an eerie blue light that seems to \n" +
	"beckon to travellers.  The faint outline of another world can be\n" +
	"seen beyond the glow of the light of each gateway.\n" +
	"\n" +
	BOLD + "Gateways:" + OFF + "\n" +
	"\n" +
	GRN + " Chocobo Forest" + OFF + "     " + CYN + "Beach" + OFF + "     " +
	HIG + "Eastern Forest" + OFF + "     " + HIG + "Western Forest" + OFF + "\n\n";

items =
({
  "up",				"The black sky seems to go on forever",
  "down",			"There is nothing solid at your feet.  You seem to be hanging in midair",
  "sky",			"The black sky seems to go on forever",
  "ground",			"There is nothing solid at your feet.  You seem to be hanging in midair",
  "clouds",			"As though powered by something other than wind, the clouds swirl\n" +
  		   			"ominously through the room",
  "stars",			"Twinkling stars can barely be seen behind the clouds",
  "gateways",		"Made from an unknown material, each gateway seems to glow with an\n" +
             		"odd blue light",
  "gateway",		"Made from an unknown material, each gateway seems to glow with an\n" +
            		"odd blue light",
  "light",			"This soft pulsing light seems to create its own energy",

});

dest_dir = ({

  "/room/forest8","out",

});

}

init ()
{
	::init();
	add_action("chocoboforest", "chocobo");
	add_action("beach", "beach");
	add_action("easternforest", "eastern");
	add_action("westernforest", "western");
	add_action("cmdAsk","ask");
}

chocoboforest()
{
	tp->move_player("chocobo#players/laera/cforest/cf01.c");
	write_file("/players/laera/closed/fvisit.c",ctime(time()) +
	"  " + this_player()->query_name() + "\n");
	return 1;
}

beach()
{
	tp->move_player("beach#players/laera/balamb/beach/b01.c");
	write_file("/players/laera/closed/beach.c",ctime(time()) + "  " +
	this_player()->query_name() + "\n");
	return 1;
}

easternforest()
{
	tp->move_player("eastern#players/laera/balamb/forests/forest1/f101.c");
	write_file("/players/laera/closed/forest1",ctime(time()) + "  " +
	this_player()->query_name() + "\n");
	return 1;
}

westernforest()
{
	tp->move_player("western#players/laera/balamb/forests/forest2/f201.c");
	write_file("/players/laera/closed/forest2",ctime(time()) + "  " +
	this_player()->query_name() + "\n");
	return 1;
}

cmdAsk(str)
{
	if (!str)
	{
	    write("Etien asks: Huh???\n");
    	return 1;
	}

	switch(str)
	{
		case "chocobo":
		case "chocobos":
		case "chocobo forest":
			write("Etien says: That forest contains little birds that can be fun to play with if you are a small level.\n");
			break;
		case "beach":
			write("Etien says: Balamb has a wonderful beach but it can be very dangerous if you aren't strong enough.\n");
			break;
		case "eastern":
		case "eastern forest":
			write("Etien exclaims: Thats the forest where the Dragons live!  I'm afraid to go in there alone because I'm so small!\n");
			break;
		case "western":
		case "western forest":
			write("Etien exclaims: The western forest is smaller than the Eastern forest, but its just as scary!\n");
		case "barter":
		case "bartering":
		case "trade":
			write("Etien says: I will barter with you for items that come from dragons.\n");
		default:
			write("Etien says:  I don't know anything about that yet.  Ask me about something I know.\n");
			break;
	}
}
