/*
        check_wield(str)

        Check to make sure that the weapon that the player is
        attempting to wield is allowed by guild rules.
*/
check_wield(str) {
object what;

what = present(str,this_player());
if(!what) {
        write("You have no "+str+".\n");
        return 1;
}
if(what->query_id() != "legion_weapon") {
        write(capitalize(str)+" is not an acceptable weapon for legionnaires.\n");
        return 1;
}
else {
        return 0;
}
}


