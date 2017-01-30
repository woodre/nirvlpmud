reset(arg) {
        if(arg) return;
}
query_auto_load() {
  return "/players/trix/flirter.c:";
}

id( str ) {
        if(str=="flirter") return 1;
        return 0;
}

long() {
        write( "This is a flirter device, type 'hkiss' to get a help menu.\n");
        return 1;
}

short()
  { return "A flirter"; }
init()
{
  add_action( "kass","kass");
  add_action( "khand","khand");
  add_action( "kcheek","kcheek");
  add_action( "kneck","kneck");
  add_action( "khead","khead");
  add_action( "kwrap","kwrap");
  add_action( "hkiss","hkiss");
  return 1;
}
me() { return this_player(); }

hkiss() { cat("/players/trix/helpdir/helpflirt"); return 1; }
find(arg) { return present(arg,environment(me())); }
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

kass(arg) {
 object who;
 string self,aim,others;
 who=find(arg);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 self="You bend over "+name(who)+"'s cute little ass.\n";
 aim=name(me())+" bends over and kisses your cute little ass.\n";
 others=name(me())+" bends over and kisses "+name(who)+"'s cute little ass.\n";
 phone(lower_case(name(who))+":"+self+":"+aim+":"+others);
 return 1;
}

khand(arg) {
 object who;
 string self,aim,others;
 if(!arg) { write("You must specify a player name!\n"); return 1; }
 who=find(arg);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 self="You stare "+name(who)+" in the eyes as you softly kiss "+pos(who)+" hand.\n";
 aim=name(me())+" stares you in the eyes as "+pro(me())+" softly kisses your hand.\n"; 
 others=name(me())+" stares "+name(who)+" in the eyes as "+pro(me())+" softly kisses "+pos(who)+" hand.\n";
 phone(lower_case(name(who))+":"+self+":"+aim+":"+others);
 return 1;
}

kcheek(arg) {
 object who;
 string self,aim,others;
 if(!arg) { write("You must specify a player name!\n"); return 1; }
 who=find(arg);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 self="You walk up to "+name(who)+" and kiss "+ogg(who)+" on the cheek.\n";
 aim=name(me())+" walks up to you and kisses you on the cheek.\n"; 
 others=name(me())+" walks up to "+name(who)+" and kisses "+ogg(who)+" on the cheek.\n";
 phone(lower_case(name(who))+":"+self+":"+aim+":"+others);
 return 1;
}

kneck(arg) {
 object who;
 string self,aim,others;
 if(!arg) { write("You must specify a player name!\n"); return 1; }
 who=find(arg);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 self="You kiss "+name(who)+"'s neck passionately.\n";
 aim=name(me())+" kisses your neck passionately.\n"; 
 others=name(me())+" kisses "+name(who)+"'s neck passionately.\n";
 phone(lower_case(name(who))+":"+self+":"+aim+":"+others);
 return 1;
}

khead(arg) {
 object who;
 string self,aim,others;
 if(!arg) { write("You must specify a player name!\n"); return 1; }
 who=find(arg);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 self="You caress "+name(who)+"'s hair and kiss "+pos(who)+" forehead.\n";
 aim=name(me())+" caresses your hair and kisses your forehead.\n"; 
 others=name(me())+" caresses "+name(who)+"'s hair and kisses "+pos(who)+" forehead.\n";
 phone(lower_case(name(who))+":"+self+":"+aim+":"+others);
 return 1;
}

kwrap(arg) {
 object who;
 string self,aim,others;
 if(!arg) { write("You must specify a player name!\n"); return 1; }
 who=find(arg);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 self="You wrap your arms around "+name(who)+" and start kissing "+ogg(who)+" all over.\n";
 aim=name(me())+" wraps "+pos(me())+" arms around you and starts kissing you all over.\n"; 
 others=name(me())+" wraps "+pos(me())+" arms around "+name(who)+" and starts kissing "+ogg(who)+" all over.\n";
 phone(lower_case(name(who))+":"+self+":"+aim+":"+others);
 return 1;
}

phone(arg)
{object who,ob;
 string name,self,aim,others;
 sscanf(arg,"%s:%s:%s:%s",name,self,aim,others);
 write(self);
 who=find(name);
 tell_object(who,aim);
 ob=first_inventory(environment(this_player())); 
 while(ob) { if(ob!=who&&ob!=me()) tell_object(ob,others);
 ob=next_inventory(ob); } 
 return 1;
}  
get() {
        return 1;
}
drop() {
        return 1;
}
