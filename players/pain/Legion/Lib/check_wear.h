/*
        check_wear(str)

        Check to make sure that the armour that the player is
        attempting to wear is allowed by guild rules.
*/
check_wear(str) {
object what;

what = present(str,this_player());
if(!what) {
        write("You have no "+str+".\n");
        return 1;
}
if(what->query_id() != "legion_armor") {
        write(capitalize(str)+" is not acceptable armor for legionnaires.\n");
        return 1;
}
else {
        return 0;
}
}

