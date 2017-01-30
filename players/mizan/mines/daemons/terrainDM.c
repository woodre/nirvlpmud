/**
 * What's going on here is that this object is nothing more than a glorified
 * lookup table for terrain types.
 *
 * My code is not particularly elegant, but it's functional.
 *
 *
 *
 */
#include "../definitions.h"
#include "/obj/ansi.h"

string *terrain_data;

get() { return 0; }
short() { return "A server named (terrain)"; }
id(str) { return str == "terrain" || str == "server"; }

reset(int arg)
{
	/* move ourselves home. */
	move_object(this_object(), DAEMON_HOME);

	if(!terrain_data)
	{
		terrain_data = allocate(32);
terrain_data[0] = ({ "Dirt", YEL + "n" + NORM, "This is some dirt.", 1  });
terrain_data[1] = ({ "Mud", YEL + "m" + NORM, "This is some mud.", 1 });
terrain_data[2] = ({ "Poop", YEL + "o" + NORM, "This is some poop.", 1 });
terrain_data[3] = ({ "Mud-Grassland", GRN + "." + NORM, "This is a clump of grass growing in mud.", 1 });
terrain_data[4] = ({ "Boss", HIR + "*" + NORM, "This is a boss.", 1 });
terrain_data[5] = ({ "Miniboss", RED + "*" + NORM, "This is a miniboss.", 1 });
terrain_data[6] = ({ "Vehicle", HIW + "O" + NORM, "This is a vehicle.", 1 });
terrain_data[7] = ({ "Player", HIC + "*" + NORM, "This is a player.", 1 });
terrain_data[8] = ({ "Monster", HIW + "*" + NORM, "This is a monster.", 1 });
terrain_data[9] = ({ "Something Shiny", HIY + "*" + NORM, "Something shiny.", 1 });
terrain_data[10]= ({ "A Portal", HIW + "@" + NORM, "A portal in or out.", 1 });


terrain_data[11]= ({ "East-west Road", RED + "-" + NORM, "An east-west road.", 1 });
terrain_data[12]= ({ "North-south Road", RED + "|" + NORM, "A north-south road.", 1 });
terrain_data[13]= ({ "A Crossroads", RED + "+" + NORM, "A Crossroads.", 1 });
terrain_data[14]= ({ "Shallow Water", HIB + "~" + NORM, "Shallow going water.", 0 });
terrain_data[15]= ({ "Deeper Water", BLU + "~" + NORM, "Deeper ocean water. ", 0 });
terrain_data[16]= ({ "Hills", WHT + "^" + NORM, "Hills and stuff.", 1 });
terrain_data[17]= ({ "Mountains", HIW + "M" + NORM, "Mountains.", 0 });

terrain_data[18]= ({ "Grassland", GRN + ":" + NORM, "Some nice grasses here and there.", 1 });
terrain_data[19]= ({ "Thick Grassland", HIG + ":" + NORM, "Very dense grassland growth.", 1 });
terrain_data[20]= ({ "Forest", GRN + "@" + NORM, "Trees. Big trees.", 1 });
terrain_data[21]= ({ "Thick Forest", HIG + "@" + NORM, "Many, many big trees growing close together.", 1 });
terrain_data[22]= ({ "A bridge (east-west)", YEL + "=" + NORM, "A bridge running east-west.", 1 });
terrain_data[23]= ({ "A bridge (north-south)", YEL + "H" + NORM, "A bridge running north-south.", 1 });
terrain_data[24]= ({ "A Dungeon Path", GRY + "." + NORM, "A dungeon path", 1 });
terrain_data[25]= ({ "A Dirt Wall", YEL + "%" + NORM, "A solid dirt wall", 0 });
terrain_data[26]= ({ "A Dungeon Wall", "%", "A solid stone dungeon wall", 0 });
terrain_data[27]= ({ "", "", "", 1 });
terrain_data[28]= ({ "", "", "", 1 });
terrain_data[29]= ({ "", "", "", 1 });
terrain_data[30]= ({ "", "", "", 1 });
terrain_data[31]= ({ "", "", "", 1 });

	}

}

get_icon(arg)
{
	if(arg >=0 && arg < sizeof(terrain_data)) return terrain_data[arg][1];
	else return ".";
}

get_passable(arg)
{
	/*
tell_object(find_player("mizan"), "TERR: " + terrain_data[arg][3]);
*/
	if(arg >=0 && arg < sizeof(terrain_data)) return terrain_data[arg][3];
	else return 1;
}

get_short_desc(arg)
{
        if(arg >=0 && arg < sizeof(terrain_data)) return terrain_data[arg][0];
        else return "Unknown";
}

get_long_desc(arg)
{
        if(arg >=0 && arg < sizeof(terrain_data)) return terrain_data[arg][2];
        else return "Unknown terrain.";
}

