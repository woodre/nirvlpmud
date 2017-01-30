
inherit "obj/monster";

reset(){
set_name("baphomet");
set_alias("minotaur");
set_short("Baphomet, Lord of the Minotaurs");
set_long("Baphomet is the god of all minotaurs.  You have no hope of\n"+
"defeating him unless you have the right blessings.\n");
set_level(16);
set_wc(22);
set_ac(13);
set_chat_chance(15);
load_chat("Baphomet scoffs at your threats.\n");
load_chat("Baphomet throws back his head and cackles with glee.\n");
::reset();
}

init(){
     if(!present("blessing", this_player())){
        add_action("kill","kill");
        add_action("kill","fireball");
        add_action("kill","fi");
        add_action("kill","shock");
        add_action("kill","sh");
        add_action("kill","missile");
        add_action("kill","mi");
        add_action("kill","cast");
        add_action("kill","harm");
        add_action("kill","use");
        add_action("kill","fear");
         }
::init();
}

kill(){
     object disease;
     int points;
     write("Baphomet opens his gaping mouth and blasts you with a torrent\n");
     write("of unholy water.  You suddenly feel very sick.\n");
     disease = clone_object("players/deathmonger/QUEST/disease");
     disease->set_who(this_player()->query_real_name());
     move_object(disease, this_player());
     points = this_player()->query_hp();
     this_player()->add_hp(points - (points - 10));
     this_player()->run_away();
     return 1;
}
