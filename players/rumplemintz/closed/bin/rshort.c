int rshort(object who){
    object short;
    if(!who) who = this_player();
    short = clone_object("/players/rumplemintz/closed/shadows/short.c");
    short->shadow_me(who);
    return 1;
}
