/* orginally showed exact percentage... the rules of nirvana as dictated by
  boltar states that no longer are exact numbers to be shown
  only by 10's may the information about health bee shown
  - mythos <3-16-96>
*/
object who,play;
string name;
int per,toggle;
reset(arg) {
        if(arg) return;
        name="";
        per=5;
}

 long() {
           write("                             Life Scanner 2.1\n"+
                 "This is a life scanner, you can use to stat the shape of players and\n"+
                 "monsters. Commands:\n\n"+
                 "reg <name> : registers a monster or a player(cost 10sps),\n"+
                 "sca(n)     : checks the shape of the registered monster/player(hps percentual),\n"+
                 "tog        : turns on/off the scanner monitor,\n"+
                 "rate <N>   : sets the the scanner monitor to show up every N seconds,\n"+
                 "com <msg>  : sends a msg to the registered monster.\n");
           return 1;
        }

 short() {
          return "A scanner("+name+")";
        }


id(str) {
        if( str == "scanner" ) return 1;
        return 0;
}

init() {
        add_action("register","reg");
        add_action("scan","scan");
        add_action("scan","sca");
        add_action("rate","rate");
    add_action("activate", "tog");
        add_action("com","com");
        return 1;
       }
register(arg)
 { int sp;
  if(!arg) return 0;
   sp=call_other(this_player(),"query_sp",0);
   if(sp<10){ write("[(Not enough spell points to register)]\n"); return 1; }
   who=present(arg,environment(this_player()));
   if(!who){ write("[(There is no form here named after this name)]\n"); return 1; }
  if(who->query_invis() > 18) {
    write("[(There is no form of live named after this name)]\n");
    return 1;
  }
   call_other(this_player(),"add_spell_point",-10);
   name=capitalize(call_other(who,"query_name",0));
   write("[(You registered your scanner at "+name+")]\n");
   remove_call_out("recu");
   toggle=0;
   return 1;
 }
com(arg)
 { if(!who) { write("[(You must register first!)]\n"); return 1;}
   if(!arg) { write("[(Com what???)]\n"); return 1;}
  if(who->query_invis() > 38) {
    write("[(You must register first!)]\n");
   who = 0;
    return 1;
  }
   tell_object(who,"["+capitalize(call_other(this_player(),"query_name",0))+"]-> "+arg+"\n");
   write("Com[->"+name+"]: "+arg+"\n");
   return 1;
 }
scan()
 { 
   int hp,max,perc;
   if(!who) { write("[(You must register first!)]\n"); return 1;}
   max=call_other(who,"query_mhp",0);
   hp=call_other(who,"query_hp",0);
  write("["+name+"'s stamina: "+(hp*10/max)+"/10]\n");
   return 1;
 }

activate()
 {   
   if(!who) { write("[(You must register first!)]\n"); return 1;}
   if(!toggle) 
    {
      toggle=1;
      play=this_player();
      write("[(Scanner toggled on)]\n");
      recu();
    }
   else { toggle=0; write("[(Scanner toggled off)]\n"); remove_call_out("recu"); }
   return 1;
 }
recu()
 {
   int hp,max,perc;
if(play)
  if(who) 
   if(toggle&&(play->query_attack()==who||(play->query_attack()&&play==who)))
    {
      max=call_other(who,"query_mhp",0);
      hp=call_other(who,"query_hp",0);
      tell_object(play,"["+name+"'s stamina: "+(hp*10/max)+"/10]\n");
      }
   call_out("recu",per);
return 1;
 } 


rate(arg)
 {      int secs;         
        if((!arg) || ((sscanf(arg,"%d",secs) !=1))) { write("[(The right syntax is 'rate <number>')]\n"); return 1;}
        if(secs<=0||secs>=20) { write("[(Illegal rate number, the range permitted is 1-20 )]\n"); return 1; }
        per=secs;
        write("[(You set monitor time rate at "+per+" )]\n");
        return 1;
 }    

get() {
        return 1;
}

drop() {
        return 0;
}
