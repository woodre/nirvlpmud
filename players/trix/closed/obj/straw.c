object who;

reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="strawberry") return 1;
        return 0;
}

long() { write( "A big red juicy strawberry, perhaps you could <eat> it.\n");
}

short() { return "An inviting strawberry"; }

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
  add_action( "eat","eat");
}
eat(arg)
{ if(!id(arg)) return ;
   say(name(me())+" holds a strawberry up in the air, tilts "+pos(me())+" head back and\n"+
                  "lowers it to "+pos(me())+" mouth. "+pro(me())+" swirls "+pos(me())+" tongue around it\n"+
                  "before "+pro(me())+" takes it into "+pos(me())+" mouth and eats it.",me());
   write("You eat it.\n");
   return 1;
}

