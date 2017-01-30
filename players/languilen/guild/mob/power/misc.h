/*
 *  Misc.h
 *  Mob Misc Utility Functions
 */

/*  filters for the various who lists  */

int filter_invis(object who){
     if(!environment(who)){ return 0; }
     if(this_player()->query_level()<who->query_invis()) return 0;
     return 1;
}
int filter_mob(object who){
     if(!present("MOB_OB", who)) return 0;
     return 1;
}
int filter_fam(object who){
     if(present("MOB_OB", who)->query_family() != TPGO->query_family()) return 0;
     return 1;
}
