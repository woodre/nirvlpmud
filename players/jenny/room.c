inherit "/room/room";
okay_follow() { return 1; }

exit(ob) { if(ob->is_player()) ob->clear_fight_area(); }

set_smell() { }
set_listen() { }
set_search() { }
