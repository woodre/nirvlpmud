

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "The Entrance Room of an Evil Fortress";
    no_castle_flag = 0;
    long_desc = 
        "You are standing in the lofty entrance room to this evil castle...\n"
        + "All around you are the sounds of suffering and death...\n"
        + "In the middle of this gloomy room is a pit with a roaring fire in it.\n"
        + "As you look in the fire you think that you see dancing devils....\n"
        + "It must be your eyes playing tricks on you, or is it that simple?\n"
        + "All around the room are banners of Armies of old... You can make out\n"
        + "the banners of a Roman legion and over to your left is one from a \n"
        + "Nazi SS battalion, and straight ahead is a banner that you do not\n"
        + "recognize... Maybe you should look at it.\n"
        + "On either side of the room you see windows looking out into the moat..\n"
        + "There is something wierd about that moat... perhaps you should examine\n"
        + "it more carefully by looking out the window...\n"
        + "You suddenly feel as if you are being watched and wonder if anyone is home...\n"
        + "Maybe you will find out sooner than you think...\n"
        + "\n"
	+ "BEWARE: This castle is not for the faint of heart, weak or those\n"
	+ "who are not secure in their pity and strong of will... \n"
	+ "Remember... you are not just fighting for your life...\n"
	+ "You are fighting for your soul as well!\n\n";
	items = ({
		"banner", "This is an silky black banner... it seems to absorb all light in the room.\n"+
		"As you look at it your blood runs cold.\n"+
		"At the center of the banner is a man with a hooded cowl and an upraised sword.\n"+
		"Beneath him lie the bodies of those who feel victim to his evil.\n"+
		"You feel your heart stop as you look at one of the faces of the damned...\n"+
		"You see what looks to be your own face staring back.\n"+
		"Around the dead burns a circle of fire... white fire not of this world.\n"+
		"You hope that you do not run into any creature that rallies to this banner!\n"+
		"At the bottom of the banner is the simple, yet chilling phrase..."+
		"\n"+
		"\nIt is better that you were never born than to serve one you fear.\n",
		"window", "This is a window that looks out onto the moat before the castle.\n"+
		"As you peer at the moat you notice something odd about it...\n"+
		"First, you notice that it is an odd color...\n"+
		"a deep dark burgundy red, almost black.\n"+
		"You find it strange that such a marvelous castle would be surrounded\n"+
		"by such brackish waters...\n"+
		"The next thi~g that you notice is that the waters reek...\n"+
		"the stench is almost unbearable.\n"+
		"As you gaze at the waters longer you begin to realize just what it is.\n"+
		"This is a moat of blood... human blood!\n"+
		"You quicky seek a corner of the room into which you could\n"+
		"retch out the contents of your stomache...\n"+
		"\nYou hope that your blood will not be added to that moat later\n\n",
	"moat", "You look out the window to the moat... you notice something strange about it.\n"+
		"This moat doesn't appear to be water... and if it is it is foul water...\n"+
		"You have never seen such brackish water in all your adventuring life.\n"+
		"You wonder what on earth this dark liquid is.\n"+
		"It appears to be thicker than water... and much darker..\n"+
		"As you stick your head further out the window to get a better look\n"+
		"you are overcome by the awful stench you encounter.\n"+
		"Wait a minute you think to yourself...\n"+
		"You suddenly come upon the horrible realization that this is not water....\n"+
		"This moat is filled with blood.... human blood!\n"+
		"You quickly run around the room to find a place to throw up!!\n",
	});
    dest_dir = 
        ({
        "players/pain/CASTLE/EVIL/evil_hall_1", "n",
        "players/pain/CASTLE/EVIL/enter_hall_1", "e",
        "players/pain/CASTLE/EVIL/road_3", "s",
        "players/pain/CASTLE/EVIL/enter_hall_9", "w",
        });
}

query_light() {
    return 1;
}
query_room_maker() {
    return 101;
}

/*
    remove the comments around the "room is modified()" code
    below to prevent changes you have done to this room to
    to be lost by using the room maker
*/
/*
room_is_modified() {
    return 1;
}
*/

/*
 make your additions below this comment, do NOT remove this comment
--END-ROOM-MAKER-CODE--
*/

