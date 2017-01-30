/*
        fixd()

        Ensure that the guild object is the first object in the players
        inventory and that the player doesn't have more than 40k coins.
*/
fixd() {
if(environment(this_object())) {
        move_object(this_object(),environment(this_object()));
     if(this_player())
        if(this_player()->query_money() > 40000) {
                this_player()->add_money(-(this_player()->query_money()));
                this_player()->add_money(40000);
        }
}
call_out("fixd",100);
return 1;
}


