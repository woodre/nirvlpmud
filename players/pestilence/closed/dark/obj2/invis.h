new_invis(){
/*
  write("This spell has been disabled, and deemed too powerful, and is now being retooled.\n");
return 1;
*/
        if(USER->query_ghost()) return 0;
if(this_player()->query_guild_rank() < 9){ write("You can't turn invisible until guild rank 9.\n"); return 1; }
        if(USER->query_sp() < 50){
                write("You lack the energy to perform that.\n");
                return 1;
        }
        this_player()->set_invs_sp();
        USER->add_spell_point(-50);
        tell_room(environment(USER),
                USER->query_name()+" is suddenly engulfed in "+HIK+"Darkness"+NORM+" and\n"+
                "slowly becomes one with the shadows.\n"+
        USER->query_name()+" vanishes from sight.\n", ({USER}));
        tell_object(USER,
                "You are enshrouded in "+HIK+"Darkness..."+NORM+"\n"+
                "It collects around you and begins to blend with the backdrop of the room.\n"+
        "You disappear.\n");
        return 1;
}
