

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "The beginning of a hall";
    no_castle_flag = 0;
    long_desc = 
        "You are at the beginning of a hall through this Evil castle...\n"
        + "You wonder what you might encounter on your trip through this\n"
        + "strange and powerful place... just remember... Don't Get Lost!\n"
        + "As you slowly look around you notice another window that looks out\n"
        + "over the moat... you hear sounds outside the window and wonder if\n"
        + "you should look.... As you turn your gaze the other way you notice\n"
        + "a painting on the wall... it looks Roman... maybe you should get a \n"
        + "better look at it... who knows what you could learn.\n"
        + "\n"
        + "BEWARE: You do not know the evils that lurk these hallways\n"
        + "        use extreme caution... remember not only is your life\n"
        + "        at stake... your soul is as well!\n";

items = ({
	"painting" , "This is an ancient painting, it depicts a battle between the Romans .\n"
	+"and the raiders of Gaul. In the foreground is a small patrol of the raiders \n"
	+"about to be overrun by a tight phalanx of Roman foot soldiers. In the \n"
	+"distance you see Roman cavalry wheeling to attack the partol's flank. \n"
	+"In the eyes of the patrol's soldiers you see unabashed fear like you\n"
	+"have never seen before. The cruel Romans do not intend to take any prisoners.\n"
	+"Some of the patrol's members throw up their hands, begging the soldiers \n"
	+"to spare them. In the eyes of the phalanx's leader you see hatred and loathing\n"
	+"he obviously relishes his duty, he bellows out an order which you believe \n"
	+"to be 'Kill them all!'.\n"
	+"You are moved to pity for the young men about to be slaughtered.\n",
});
    dest_dir = 
        ({
        "players/pain/CASTLE/EVIL/enter_hall_1", "e",
        "players/pain/CASTLE/EVIL/Entrance", "w",
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

