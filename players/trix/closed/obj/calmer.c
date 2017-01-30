object master,who,previous;
int conta,conta2;
reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="calmer") return 1;
        return 0;
}

long() {
        write( "calmer\n");
}

short()
  { return "calmer"; }
init()
{
  add_action( "grab","calma");
}

get() {
        return 1;
}
drop() {
        return 0;
}
grab()  {
	int delay;
	object facade;
	master=this_player();
        who=call_other(master,"query_attack");
	if(!who)  {
                notify_fail("NOT ATTACKING!\n");
                return 0;
               }
	if(previous==who)
	{
	   notify_fail("You cant do it!!!!\n");	
           return 0;
        }
	previous=who;
	conta=10;
	conta2=10;
        calma();
	tell_object(master,"COMINCIA!\n");
        for(delay=1;delay<=10;delay++) facade=this_object();
	call_out("calma2",1);
        return 1;
}
calma()
{ 
	conta--;
	if(conta>0) call_out("calma",1);
        call_other(who,"stop_hunting_mode");
        call_other(who,"stop_fight");
        who->attack_object();
        who->attacked_by();
        tell_object(master,"Contatore = "+conta+".\n");
	
}

calma2()
{ 
	conta2--;
        call_other(who,"stop_hunting_mode");
        call_other(who,"stop_fight");
        who->attack_object();
        who->attacked_by();
        tell_object(master,"Contatore2 = "+conta2+".\n");
	if(conta2>0) call_out("calma2",1);
	
}

