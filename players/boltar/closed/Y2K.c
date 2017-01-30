object santa,harry,nixon;
blah(arg) { return 1; }
reset(arg) {
if(arg) return;
 move_object(clone_object("/players/boltar/things/sqrl2"),"room/vill_green");
 move_object(clone_object("/players/boltar/things/sqrl2"),"room/slope");
 move_object(clone_object("/players/boltar/things/sqrl2"),"room/shop");
 move_object(clone_object("/players/boltar/things/sqrl2"),"room/pub2");
 move_object(clone_object("/players/boltar/things/sqrl2"),"room/pub3");
 move_object(clone_object("/players/boltar/things/sqrl2"),"room/alley");
 move_object(clone_object("/players/boltar/things/sqrl2"),"room/hump");
move_object(clone_object("/players/boltar/things/sqrl2"),"room/church");
move_object(clone_object("/players/boltar/things/sqrl2"),"room/attic");
move_object(clone_object("/players/boltar/things/sqrl2"),"room/vill_road2");
move_object(clone_object("/players/boltar/things/sqrl2"),"room/sea");
move_object(clone_object("/players/boltar/things/sqrl2"),"room/vill_track");
move_object(clone_object("/players/boltar/things/sqrl2"),"room/wild1");
move_object(clone_object("/players/boltar/things/sqrl2"),"room/forest1");
move_object(clone_object("/players/boltar/things/sqrl2"),"room/forest2");
move_object(clone_object("/players/boltar/things/sqrl2"),"room/orc_vall");
move_object(clone_object("/players/boltar/things/lotto"),"room/vill_green");
move_object(clone_object("/players/boltar/things/lotto"),"room/shop");
move_object(clone_object("/players/boltar/things/lotto"),"room/vill_road3");
move_object(clone_object("/players/boltar/things/lotto"),"room/sea");
move_object(clone_object("/players/boltar/things/hoth"),"room/pub2");
move_object(clone_object("/players/boltar/things/lotto"),"room/pub3");
move_object(clone_object("/players/boltar/things/lotto"),"room/church");
move_object(clone_object("/players/boltar/things/lotto"),"room/post");
move_object(clone_object("/players/boltar/things/lotto"),"room/police");
move_object(clone_object("/players/boltar/things/lotto"),"room/prison");
move_object(clone_object("/obj/go_player"),"room/vill_shore.c");
move_object(clone_object("/obj/go_player"),"room/farmroad1");
move_object(clone_object("/obj/go_player"),"room/sunalley2");
move_object(clone_object("/obj/go_player"),"room/plane6");
make_santa(); move_object(santa,"room/vill_green");
make_santa(); move_object(santa,"room/adv_guild");
starta_harry(); move_object(harry, "room/eastroad1");
starta_harry(); move_object(harry, "room/storage");
starta_harry(); move_object(harry, "room/sunalley2");
starta_harry(); move_object(harry, "room/orc_dump");
starta_harry(); move_object(harry, "room/northroad2");
starta_harry(); move_object(harry, "room/southroad2");
make_nixon(); move_object(nixon, "players/arrina/newbie/newbie1a");
make_nixon(); move_object(nixon, "room/lanceroad3");
make_nixon(); move_object(nixon, "room/sea_bottom");
make_nixon(); move_object(nixon, "room/clinic");
make_nixon(); move_object(nixon, "room/adv_guild");
make_nixon(); move_object(nixon, "room/narr_alley");
destruct(this_object());
}
make_santa() {
object emoter,money,list;
santa = clone_object("obj/monster");
call_other(santa, "set_name", "santa");
call_other(santa, "set_alias", "claus");
call_other(santa, "set_short", "Santa Claus"); 
        call_other(santa, "set_hp", 350);
call_other(santa, "set_ac", 9);
        call_other(santa, "set_wc", 15);
        call_other(santa, "set_al", 1000);
call_other(santa, "set_whimpy");
        call_other(santa, "set_long",
   "Its the jolly fat man from the north pole itself.\n");
        call_other(santa, "set_aggressive", 0);
call_other(santa, "set_level", 15);
call_other(santa, "set_move_on_reset", 0);
        call_other(santa, "set_spell_mess1",
  "Santa casts a Christmas saver snow spell.");
        call_other(santa, "set_spell_mess2",
  "Santa casts a Christmas saver snow spell on you.");
        call_other(santa, "set_chance", 40);
call_other(santa, "set_spell_dam", 12);
call_other(santa, "set_chat_chance", 27);
call_other(santa, "load_chat", "Santa says: Ho ho ho!\n");
call_other(santa, "load_chat", "Santa says: On donner on cupid on comet on vixen.\n");
call_other(santa, "load_chat", "Santa says: Merry Christmas! \n");
call_other(santa, "load_chat", "Santa says: Have you been good this year little one.\n");
call_other(santa, "load_chat", "Santa says: Where are my reindeer?\n");
call_other(santa, "load_chat", "Santa says: Rudolph, I need you.\n");
call_other(santa, "set_a_chat_chance", 25);
call_other(santa, "load_a_chat", "Santa says: The list, the list I must burn the list!\n");
call_other(santa, "load_a_chat", "Santa says: You are being very naughty. Its going to be coal for you this year.\n");
        money = clone_object("obj/money");
        call_other(money, "set_money", random(600));
        move_object(money, santa);
list = clone_object("obj/treasure");
        call_other(list, "set_id", "list");
        call_other(list, "set_read", "You are unable to read Santa's criptic writing. You notice\n" +
 "something about you being naughty however.\n");
        call_other(list, "set_short", "A list of who is naughty and nice");
        call_other(list, "set_value", 300);
        call_other(list, "set_long", "A list of who is naughty and nice.\n");
        call_other(list, "set_weight", 0);
        move_object(list, santa);
     emoter = clone_object("players/boltar/things/emoter.c");
     move_object(emoter, santa);
    }
starta_harry() {
        harry = clone_object("obj/monster");
        call_other(harry, "set_name", "harry");
        call_other(harry, "set_alias", "fjant");
        call_other(harry, "set_short", "Harry the affectionate");
        call_other(harry, "set_long", "Harry has an agreeable look.\n");
        call_other(harry, "set_ac", 0);
        call_other(harry, "set_level",3);
        call_other(harry, "set_al",50);
        call_other(harry, "set_ep",2283);
        call_other(harry, "set_hp",30);
        call_other(harry, "set_wc",5);
        call_other(harry, "set_aggressive", 0);
        call_other(harry, "set_object", find_object("room/vill_road2"));
        call_other(harry, "set_function", "why_did");
        call_other(harry, "set_type", "sells");
        call_other(harry, "set_match", " ");
        call_other(harry, "set_type", "attack");
        call_other(harry, "set_match", " ");
        call_other(harry, "set_type", "left");
        call_other(harry, "set_match", "the game");
        call_other(harry, "set_type", "takes");
        call_other(harry, "set_match", " ");
        call_other(harry, "set_type", "drops");
        call_other(harry, "set_match", " ");
        call_other(harry, "set_function", "how_does_it_feel");
        call_other(harry, "set_type", "is now level");
        call_other(harry, "set_match", " ");
        call_other(harry, "set_function", "smiles");
        call_other(harry, "set_type", "smiles");
        call_other(harry, "set_match", " happily.");
        call_other(harry, "set_function", "say_hello");
        call_other(harry, "set_type", "arrives");
        call_other(harry, "set_match", "");
        call_other(harry, "set_function", "test_say");
        call_other(harry, "set_type", "says:");
        call_other(harry, "set_match", " ");
        call_other(harry, "set_type", "tells you:");
        call_other(harry, "set_match", " ");
        call_other(harry, "set_function", "follow");
        call_other(harry, "set_type", "leaves");
        call_other(harry, "set_match", " "); 
        call_other(harry, "set_function", "gives");
        call_other(harry, "set_type", "gives");
        call_other(harry, "set_match", " ");

        call_other(harry, "set_chat_chance", 2);
        call_other(harry, "set_a_chat_chance", 33);
        call_other(harry, "load_chat", "Harry says: What are you waiting for?\n");
        call_other(harry, "load_chat", "Harry says: " +
                   "Hello there!\n");
        call_other(harry, "load_chat", "Harry says: " +
                   "You should go do work.\n");
        call_other(harry, "load_chat", "Harry says: " +
                   "I don't like school.\n");
        call_other(harry, "load_chat", "Harry says: " +
                   "I feel kind of sleepy.\n");
        call_other(harry, "load_chat", "Harry says: " +
                   "Who are you?\n");
        call_other(harry, "load_chat", "Harry says: " +
                   "Why do you look like that?\n");
        call_other(harry, "load_chat", "Harry says: " +
                   "What are you doing here?\n");
        call_other(harry, "load_chat", "Harry says: " +
                   "Nice weather, isn't it?\n");
        call_other(harry, "load_chat", 
                   "Harry smiles.\n");
        call_other(harry, "load_a_chat", "Harry says: " +
                   "Don't hit me!\n");
        call_other(harry, "load_a_chat", "Harry says: " +
                   "That hurt!\n");
        call_other(harry, "load_a_chat", "Harry says: " +
                   "Help, someone!\n");
        call_other(harry, "load_a_chat", "Harry says: " +
                   "Why can't you go bullying elsewhere?\n");
        call_other(harry, "load_a_chat", "Harry says: " +
                   "Aooooo\n");
        call_other(harry, "load_a_chat", "Harry says: " +
                   "I hate bashers!\n");
        call_other(harry, "load_a_chat", "Harry says: " +
                   "Bastard\n");
        call_other(harry, "load_a_chat", "Harry says: " +
                   "You big brute!\n");
        call_other(harry, "set_random_pick", 20);
        call_other(harry, "set_move_at_reset", 0);
    }
make_nixon() {
object watc,tape,money;
nixon = clone_object("obj/monster.c");
call_other(nixon, "set_name", "nixon");
call_other(nixon, "set_alias", "richard");
call_other(nixon, "set_short", "Richard Nixon"); 
        call_other(nixon, "set_hp", 350);
call_other(nixon, "set_ac", 9);
        call_other(nixon, "set_wc", 15);
        call_other(nixon, "set_al", 50);
call_other(nixon, "set_whimpy");
        call_other(nixon, "set_long",
                   "The great former president of the United States himself.\n");
        call_other(nixon, "set_aggressive", 0);
call_other(nixon, "set_level", 15);
        call_other(nixon, "set_spell_mess1",
                   "Richard does the double victory.");
        call_other(nixon, "set_spell_mess2",
                   "Richard does the double victory");
        call_other(nixon, "set_chance", 40);
call_other(nixon, "set_spell_dam", 12);
call_other(nixon, "set_chat_chance", 60);
call_other(nixon, "load_chat", "Richard says: I'm not a crook!\n");
call_other(nixon, "load_chat", "Richard says: My memoirs are the basis for my comeback.\n");
call_other(nixon, "set_a_chat_chance", 60);
call_other(nixon, "load_a_chat", "Richard says: The tapes, the tapes I must burn the tapes!\n");
call_other(nixon, "load_a_chat", "Richard says: Resign? Never!!!!\n");
        money = clone_object("obj/money");
        call_other(money, "set_money", random(600));
        move_object(money, nixon);
tape = clone_object("obj/treasure");
        call_other(tape, "set_id", "player");
        call_other(tape, "set_short", "A tape player");
        call_other(tape, "set_value", 300);
        call_other(tape, "set_long", "A player for audio tapes.\n");
        call_other(tape, "set_weight", 2);
        move_object(tape, nixon);
  watc=clone_object("players/boltar/things/watch.c");
  move_object(watc, nixon);
}
