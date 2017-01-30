#include "/players/pestilence/ansi.h"

main(){
    
    if(this_player()->query_ghost()) return 0;
    if(this_player()->query_guild_rank() < 9){ write("You can't turn invisible until guild rank 9.\n"); return 1; }
        if(this_player()->query_sp() < 50){
                write("You lack the energy to perform that.\n");
                return 1;
        }
        this_player()->set_invs_sp();
        this_player()->add_spell_point(-50);
        tell_room(environment(this_player()),
                this_player()->query_name()+" is suddenly engulfed in "+HIK+"Darkness"+NORM+" and\n"+
                "slowly becomes one with the shadows.\n"+
        this_player()->query_name()+" vanishes from sight.\n", ({this_player()}));
        tell_object(this_player(),
                "You are enshrouded in "+HIK+"Darkness..."+NORM+"\n"+
                "It collects around you and begins to blend with the backdrop of the room.\n"+
        "You disappear.\n");
        return 1;
}
