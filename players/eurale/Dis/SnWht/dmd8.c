/*  10/04/2006 - Rumplemintz
      Moved inherit above #include statements
      Changed destruct() calls - don't need second arg as it's already defined
*/

inherit "room/room";

#include "DEFS.h"

object player;

reset(arg) {

    if(!present("queen")) {
	move_object(clone_object("players/eurale/Dis/SnWht/NPC/queen"),TO); }

    if(arg) return;
    set_light(1);

    short_desc = "Greyskull Castle";
    long_desc =
    "  You have been admitted to the fortress of the evil queen.  The \n"+
    "polished, onyx floor reflects both your image and your footsteps\n"+
    "as you walk in.  The candle chandelier hanging overhead gives \n"+
    "off just enough light to see.  All the massive doors are closed \n"+
    "to prevent movement any other way in the castle. There is one \n"+
    "very large mirror hanging on the wall.\n";

    items = ({
      "floor","You see you staring back from the blackness",
      "chandelier","13 large candles, dripping wax, provide the light",
      "doors","Securely closed",
      "mirror","A full-length mirror... for vanity",
    });

    dest_dir = ({
      "players/eurale/Dis/SnWht/dmd7.c","leave",
    });

}

init() {
    ::init();
    add_action("conjure","conjure");
}

conjure(str) {
    object ob;
    ob = present("queen");
    if(ob) {
	write("The Queen says: I FORBID magic in my castle!!\n"); return 1; }

    if(!str) { write("Who do you wish to conjure?\n"); return 1; }
    if(str == "z'ranthalla" || str == "Z'ranthalla") {

	if(!present("queen") && present("piece1",this_player()) && present
	  ("piece2",this_player()) && present("piece3",this_player())
	  && present("piece4",this_player())) {
	    write("\nThe air begins to grow very cold....\n\n");
	    TP->set_quest("phantasm_puzzle");
	    write_file("/players/eurale/Dis/SnWht/PUZZLE",ctime(time())+"   "+
	      capitalize(TPRN)+" has solved the phantasm puzzle quest.\n");
	    player = this_player();
	    call_out("talk1",10);
	    return 1; }
	else { write("You do not have the necessary items to do that!\n");
	    return 1; }

	return 1; }
    return 1;
}

talk1() {
    tell_object(player,
      "A haze begins to fill the room....\n\n");
    call_out("talk2",10); return 1; }

talk2() {
    tell_object(player,
      "An apparition of a black robed old man with a long grey\n"+
      "beard steps forth.  His wrinkled skin and yellowed teeth\n"+
      "give him the look of death...\n\n");
    call_out("talk3",10);
    return 1; }

talk3() {
    tell_object(player,
      "In a voice barely audible he whispers.....\n"+
      "I have been confined to world of nothingness for a very\n"+
      "long time.  You have set my soul free....\n\n");
    call_out("talk4",10);
    return 1; }

talk4() {
    tell_object(player,
      "He smiles at you..... and continues.....\n"+
      "As a reward for this generous act, I will bestow upon you\n"+
      "the very thing you seek...advancement toward wizhood!\n\n");
    call_out("talk5",10);
    return 1; }

talk5() {
    tell_object(player,
      "He clears his throat... and coughs slightly...\n"+
      "I am also going to improve your fortune....\n"+
      "It is the very least I can do.......\n\n");
    call_out("talk6",10);
    return 1; }

talk6() {
    tell_object(player,
      "He pauses to catch his breath, and then continues...\n"+
      "I can now complete the rest of my life's journey, thanks to\n"+
      "you.  So go now.  Take your rewards and my eternal gratitude\n"+
      "and be off.....\n\n");
    call_out("talk7",10);
    return 1; }

talk7() {
    object ob1,ob2,ob3,ob4;
    ob1 = present("piece1",player);
    ob2 = present("piece2",player);
    ob3 = present("piece3",player);
    ob4 = present("piece4",player);

    tell_object(player,
      "And right before your eyes.... the old man slowly turns \n"+
      "into a dashing young wizard, full of energy... and then\n"+
      "disappears back into the haze with a wink....\n\n");
    move_object(clone_object("players/eurale/Dis/misc/reward.c"),
      player);
    /*
	destruct(ob1,player);
	destruct(ob2,player);
	destruct(ob3,player);
	destruct(ob4,player);
    */
    destruct(ob1);
    destruct(ob2);
    destruct(ob3);
    destruct(ob4);

    call_out("talk8",5);
    return 1; }

talk8() {
    tell_object(player,
      "Congratulations!  You have solved the Phantasm quest...\n\n");
    return 1; }
