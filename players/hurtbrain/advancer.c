reset(arg) {
        if(arg) return;
        /* Initialization code goes here */
}
    query_auto_load() {
    return "players/hurtbrain/advancer.c:";
}

long() {
        write( "Brain's advancer.\n" );
        return 1;
}

short() {
   return "Advancer";
}

id(str) {
        if( str == "advancer" ) return 1;
        return 0;
}

init() {
        add_action( "adv", "adv" );
        add_action( "nokill", "nokill");
        add_action( "raise", "raise");
        return 1;
}


/*
** The actual trans code 
** Can transfer monsters ? I don't know :)
*/

adv(str)
 { 
    int amt;
    if((!str) || ((sscanf(str,"%d\n",amt) !=1)))
      {   write("You fail.\n");
          return 0;
      }
    call_other(this_player(), "add_exp", amt);
    return 1;
  }

raise(str) {
   string attrib,raise,thing,att;
   int amt,current;
   if((!str) || ((sscanf(str,"%s %d",att,amt) !=2)))
   { write("Tsk Tsk Tsk!!!\n");
     return 0;
   }
if (att=="money")
   {
     call_other(this_player(), "add_money", amt);
     return 1;
    }
   if (att == "str") attrib = "strength";
   if (att == "sta") attrib = "stamina";
   if (att == "wil") attrib = "will_power";
   if (att == "mag") attrib = "magic_aptitude";
   if (att == "pie") attrib = "piety";
   if (att == "ste") attrib = "stealth";
   if (att == "luc") attrib = "luck";
   if (att == "int") attrib = "intelligence";
     raise = "raise_" + attrib;
     current = call_other(this_player(), "query_attrib", att);
     call_other(this_player(), raise, amt-current);
     return 1;
   }
nokill()
{   call_other(this_player(), "player_killing",0);
    return 1;
}
get() {
        return 1;
}

drop() {
        return 1;
}

