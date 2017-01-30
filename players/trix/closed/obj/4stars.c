reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="checker") return 1;
        return 0;
}

long() {
        write( "This is a power checker. Type 'check <name>' to check someone.\n");
}

short()
  { return "A power checker"; }
init()
{
  add_action( "check","checkk");
}

check(arg)
{  object who;
   if(!arg) { write("Check who?\n"); return 1; }
   who=find_living(arg);
   if(!who) { write("No form of life named "+arg+" on the mud.\n"); return 1; }
   write("\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
   write(capitalize(arg)+"'s hps: "+call_other(who,"query_hp")+"/"+call_other(who,"query_mhp")+".\n");
   write(capitalize(arg)+"'s sps: "+call_other(who,"query_sp")+"/"+call_other(who,"query_msp")+".\n");
   write(capitalize(arg)+"'s ac : "+call_other(who,"query_ac")+".\n");
   write(capitalize(arg)+"'s wc : "+call_other(who,"query_wc")+".\n");
   write("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
   return 1;
}

get() {
        return 1;
}
drop() {
        return 0;
}
