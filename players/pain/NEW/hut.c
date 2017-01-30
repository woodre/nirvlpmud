

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "A weeping widow's hut";
    no_castle_flag = 0;
    long_desc =
        "This is an ordinary dirt floor hut with a thatched roof.\n"
        + "It seems to have fallen out of repair. The ceiling is worn\n"
        + "through in some places, allowing the sunlight into the room.\n"
        + "In one corner is a small bed, stuffed with straw, in the middle\n"
        + "of the room is a table with two chairs. A shawl is hung over the\n"
        + "back of one of them. In the window is a small planters box growing\n"
        + "a collection of herbs for the kitchen. It is a quaint little hut\n"
        + "yet you sense that there is no life in this place.\n"
        + "\n"
        + "Sitting in a rocking chair by the window is a young widow.\n";

items = ({
	"bed", "A small bed stuffed with straw. It doesn't look comfortable",
	"table", "A round table set with wooden plates and utensils",
	"chairs", "Rough hewn chairs that match the table",
	"shawl", "A raggedy old shawl. You doubt it would keep a mouse warm",
	"widow", "A young woman, aged beyond her years. She is crying and\n"
	+ "stares out the window as if she were waiting for someone to come\n"
	+ "walking up the path to the hut. You are moved by pity for the\n"
	+ "woman, and desire to help her. It looks as if she might have\n"
	+ "something interesting to speak with you about",
});
	dest_dir =
        ({
        "players/pain/NEW/path4", "out",
        });
}

init() {
	::init();
        add_action("speak", "speak");
	add_action("speak2", "speak2");
        add_action("speak3", "speak3");
        add_action("speak4", "speak4");
}
speak(str) {
string s1, s2;
object quest;

if(!str) {
	write("You speak. Perhaps you should speak with someone?\n");
	return 1;
}
sscanf(str, "%s %s",s1,s2);
if(s1 != "with") {
	write("The proper usage is <speak with whomever>.\n");
	return 1;
}

if(!s2) {
	write("With whom would you like to speak?\n");
	return 1;
}

if(s1 == "with" && s2 != "widow") {
        write("That person is not here.\n");
        return 1;
}
/*
if(!present("widow",this_object())) {
	write("The widow isn't in now, you'll have to wait until she gets "
	     +"back.\n");
	return 1;
}
*/

   tell_room(this_object(), "The widow says: My husband was the best "
      +"warrior in Majesty Pain's\n"
      +"Army. Pain gave him the rank of Protector of the Mountain Realms.\n");
call_out("speak2",10);
/*
quest = clone_object("players/pain/NEW/items/quest1.c");
move_object(quest,this_player());
*/
return 1;
}

speak2() {
   say("The widows weeps.\n\n");
   say("The widow says: My dearest Benedict took his title to heart and set\n"
      +"out to destroy the evil that pervaded the mountain side.\n\n");
call_out("speak3",10);
return 1;
}

speak3() {
   say("The widow dries her eyes.\n\n");
   say("The widow says: Three days ago, scouts from his Regiment returned\n"
      +"from the mountains having found his head, impaled on his sword at\n"
      +"the entrance of a cave suspected to be the headquarters of the\n"
      +"Blood Fisted Clan.\n\n");
call_out("speak4",15);
return 1;
}

speak4() {
say("The widow wavers and you wonder if she has the strength to continue.\n\n");
say("The widow says: I beg you to help me! Please find the leader of the\n"
   +"Blood Fisted Clan and kill him. If you can bring me his head, I will\n"
   +"give you all I have and you will be a hero.\n\n");
say("The widow settles back in her rocker and says no more.\n\n");
return 1;
}

realm() { return "NT"; }

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

