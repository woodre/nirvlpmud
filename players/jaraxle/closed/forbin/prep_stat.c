/*
 * prep_stat by VJ productions
 */

init_arg(str) {
    if(environment()) tell_object(environment(), "CHECK 1\n");
    call_out("upd_it", 1, str);
}

upd_it(str) {
    int time_left, amount;
    string attrib;
    object x;
    tell_object(environment(), "CHECK 2\n");
    if(!environment()) return destruct(this_object());
    tell_object(environment(), "CHECK 3\n");
    move_object(x=clone_object("/players/jaraxle/closed/forbin/"+attrib),
      environment());
    tell_object(environment(), "CHECK 4\n");
    x->init_arg(str);
    tell_object(environment(), "CHECK 5\n");
    destruct(this_object());
}


drop() { return 1; }
