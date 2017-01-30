reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="checker") return 1;
        return 0;
}

long() {
        write( "checklevel\n");
}

short()
  { return "an exp checker"; }
init()
{
  add_action("try","try");
}
try()
{
   object tp;
   int olev,xlev,lev_exp,spexp;
   tp = this_player();
   olev = tp->query_level();
        if(olev>19) olev=19;
   xlev = tp->query_extra_level();
   if(xlev>19) xlev = 19;
   if(olev > 18&&xlev>0) lev_exp = call_other("/room/exlv_guild","get_next_exp",xlev-1);
   else lev_exp = call_other("/room/adv_guild","get_next_exp",olev-1);
   spexp=tp->query_exp()-lev_exp;
   write("Your spare exp is "+spexp+".\n");
   return 1;
}

get() {
        return 1;
}
drop() {
        return 0;
}
