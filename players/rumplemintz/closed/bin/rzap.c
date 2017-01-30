#include <ansi.h>

int rzap(string str){
    object ob;
    if(!str) ob=(object)this_player()->query_attack();
    else ob = present(str, environment(this_player()));
    if(!ob || !living(ob)){
        notify_fail("Cannot find anything to rzap.\n");
	return 0;
    }
    if((string)this_player()->query_real_name()==str){
	notify_fail("You cannot rzap yourself!\n");
	return 0;
    }
    if(this_player()->query_level() < ob->query_level()){
	notify_fail("You should not use that on higher level players.\n");
	return 0;
    }
    write("You summon a flash from the sky.\n");
    say(this_player()->query_name()+" summons a "+HIW+"lightning "+HIY+"bolt"+NORM+" from the sky to strike "+ob->query_name()+"\n");
    ob->hit_player(100000);
    write("There is a big clap of thunder.\n");
    return 1;
}
