object who;

reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="grape") return 1;
        return 0;
}

long() { write( "A single green seedless grape, perhaps you could <peal> it for someone.\n");
}

short() { return "A green grape"; }

get()   { return 1;  }
drop()  { return 0;  }
find(arg) { return present(arg,environment(me())); }
me() {return this_player();}
sex(arg) { return call_other(arg,"query_gender"); }
name(arg){ return capitalize(call_other(arg,"query_real_name")); }
pos(arg) { if(sex(arg)=="male") return "his";
           else if(sex(arg)=="female") return "her";
           return "its";
         } 
pro(arg) { if(sex(arg)=="male") return "he";
           else if(sex(arg)=="female") return "she";
           return "it";
         } 
ogg(arg) { if(sex(arg)=="male") return "him";
           else if(sex(arg)=="female") return "her";
           return "it";
         } 
prp(arg) { if(sex(arg)=="male") return "his";
           else if(sex(arg)=="female") return "hers";
           return "its";
         } 

init()
{
  add_action( "peal","peal");
}
peal(arg)
{ string arg1,arg2;
  if(!arg) { write("You should <peal grape for someone>.\n"); return 1; }
  if(!sscanf(arg,"%s for %s",arg1,arg2)) return 0;
  if(arg1!="grape") { write("Peal what?\n"); return 1; }
  who=find(arg2);
  if(!who) { write("No players with that name in this room.\n"); return 1; }
  say(name(me())+" carefully peals "+name(who)+" a grape. Then places the grape between "+pos(me())+
  "\nlips and leans over and kisses "+name(who)+", leaving the delicious grape flavour\n"+
           "in "+name(who)+"'s mouth.\n",who);
  tell_object(who,name(me())+" carefully peals you a grape. Then places the grape between "+pos(me())+
  "\nlips and leans over and kisses you, leaving the delicious grape flavour\n"+
           "in your mouth.\n");
  write("You peal a grape for "+name(who)+".\n");
  destruct(this_object());
  return 1;
}
