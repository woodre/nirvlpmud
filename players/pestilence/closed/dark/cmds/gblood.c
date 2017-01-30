#include "/players/pestilence/ansi.h"

main(){
    int name, myob;
    object ob, att, blood;
   name = this_player()->query_real_name();
    if(this_player()->query_sp() < 100){
        write("You do not have the spell points available for this spell.\n");
        return 1; 
    }
if(this_player()->query_guild_rank() < 10){ write("You must be guild level 10 for this spell.\n"); return 1; }
if(present("pesty_guild",this_player())->query_recruit() > 3){ write("You have given too much blood already.\n"); return 1; }
    myob = present("pesty_guild", this_player());

    write("You slash your hand causing "+HIR+"Blood "+NORM+" to flow.\n"+HIR+"Blood "+NORM+" fills a small container easy to drink out of.\n");
    say(this_player()->query_name() +" slashes their hand causing "+HIR+"Blood "+NORM+" to flow.\n"+
        "Something happens.\n");
    write_file("/players/pestilence/closed/dark/log/blood",ctime(time())+" "+this_player()->query_name()+" gave their blood.\n");
    present("pesty_guild",this_player())->add_recruit(1);
    blood = clone_object("/players/pestilence/closed/dark/blood.c");
    blood->set_owner(name);
    blood->set_id(name+"'s blood");
    blood->set_alias("blood");
    blood->set_short(name+"'s "+RED+"blood"+NORM);
    blood->set_long("This is the blood handed down from the fallen angel, Daragor.  One might be able to drink it.\n");
  move_object(blood,this_player());
    this_player()->add_spell_point(-100);

    return 1;
}
