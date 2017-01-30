/*
 *  Graft.h
 *  Mob Graft Utility Functions
 */

int find_graft(object who){
    int lev, amt;
    object ob;

    ob=present("MOB_PROTECT", who);

    if(ob){
       if(ob->query_family()==present("MOB_OB", this_player())->query_family()){
          if(query_verb() == "protect"){
             write(who->query_name()+" already has the protection of your family!\n");
             return 0;
          }
          write(who->query_name()+" is under your families protection!\n");
          return 0;
       }
    }
    lev = (int)who->query_level();
    if( (int)who->query_extra_level() > 4 ) lev++;
    lev = lev - 5;
    amt = (int)who->query_money();
    if(lev < 1){
       write("newbie stuff..\n");
       return 0;
    }
    if(amt==0) return 0;
    write("they have "+amt+" coins...\n");
    amt = (amt * lev / 100 );
    write("equiling "+amt+" in graft.\n");
    return amt;
}
