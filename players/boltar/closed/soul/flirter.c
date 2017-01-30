#include <esc.h>
query_auto_load() {
  return "/players/trix/closed/obj/flirter.c:";
}
object who;
int muffled;
me() {return this_player();}
reset(arg) {
        if(arg) return;
    who=0;
}

id( str ) {
        if(str=="flirter") return 1;
        return 0;
}

long() {
write("                  -@Trix's flirter device (Version 3.2)@-\n");
write("This nice item will be very useful for you if you don't plan to spend  all your\n");
write("mudtime fighting evil dragons or picking on poor little elves.\n");
write("Type 'hkiss' if you want to see the list of the available emotes.\n");
write("Type 'fhelp' for a general help on the other functions of the flirter.\n");
}

short()
  { return "A flirter"; }

flirts(str) {
  object us;
  int x;
  string sex;
  int invis;
  if(str) return;
  write("\n@Name@--------@Sex@-@Muffled@\n");
  us=users();
  for(x=0;x<sizeof(us);x++) {
    object flirter;
    invis=us[x]->query_invis();
    flirter=present("flirter",us[x]);
    if(flirter&& invis<this_player()->query_level()){
    if(invis) { write(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"); }
      write(capitalize(us[x]->query_real_name()));
      if(strlen(us[x]->query_real_name())>7)
        write("\t"); else write("\t\t");
        write(esc+"[0m");
        sex=us[x]->query_gender();
        if(sex=="male") write("M\t");
        else if(sex=="female") write("F\t");
        else write("C\t");
        if(flirter->query_muffled())
           write("Yes\n");
        else
           write("No\n");
   }
  }
  return 1;
}
muffli()  {
        if(!muffled)  {
                write("Flirter channel muffled.\n");
                muffled=1;
                }
        else  {
                write("Flirter channel nomore muffled.\n");
                muffled=0;
                }
        return 1;
        }
query_muffled() { return muffled; }

fli(arg) {
  object us,flirter;
  string str,name;
  int x,emote;
  if(!arg) {write("What do u want to send through the flirter channel?"); return 1;}
  if(muffled)  {
        write("Your flirter channel is muffled.\n");
        return 1;
        }
  str=arg;
  if(sscanf(arg,":%s",str))
  	emote=1;
  else
	emote=0;
  us=users();
  name=this_player()->query_name();
  if(emote)
    for(x=0;x<sizeof(us); x++) {
      flirter=present("flirter",us[x]);
      if(flirter&&!flirter->query_muffled())
        tell_object(us[x],"-'-,<@ "+name+" "+str+"\n");
    }
   else
    for(x=0;x<sizeof(us); x++) {
      flirter=present("flirter",us[x]);
      if(flirter&&!flirter->query_muffled())
        tell_object(us[x],"-@"+name+"@- "+str+"\n");
    }
  return 1;
}

init()
{
  add_action( "donate","donate");
  add_action( "dump","dump");
  add_action( "hickey","hickey");
  add_action( "flirts","flirts");
  add_action( "fhelp","fhelp");
  add_action( "fli","fli");
  add_action( "muffli","muffli");
  add_action( "kass","kass");
  add_action( "khand","khand");
  add_action( "kcheek","kcheek");
  add_action( "kneck","kneck");
  add_action( "khead","khead");
  add_action( "kwrap","kwrap");
  add_action( "hkiss","hkiss");
  add_action( "need","need");
  add_action( "ahold","ahold");
  add_action( "ballad","ballad");
  add_action( "button","button");
  add_action( "dkiss","dkiss");
  add_action( "jeans","jeans");
  add_action( "lgaze","lgaze");
  add_action( "llick","llick");
  add_action( "lscratch","lscratch");
  add_action( "ltouch","ltouch");
  add_action( "lust","lust");
  add_action( "massage","massage");
  add_action( "mchuckle","mchuckle");
  add_action( "neck","neck");
  add_action( "nuzzle","nuzzle");
  add_action( "tlip","tlip");
  add_action( "bhug","bhug");
  add_action( "smother","smother");
  add_action( "thold","thold");
  add_action( "huggle","huggle");
  add_action( "beam","beam");
  add_action( "smile","smile");
  add_action( "beg","beg");
  add_action( "blush","blush");
  add_action("bow","bow");
  add_action( "chuckle","chuckle");
  add_action("comfort","comfort");
  add_action("cry","cry");
  add_action("cuddle","cuddle");
  add_action( "flirt","flirt");
  add_action("fondle","fondle");
  add_action("french","french");
  add_action("giggle","giggle");
  add_action( "glare","glare");
  add_action("grin","grin");
  add_action( "grope","grope");
  add_action("growl","growl");
  add_action( "high5","high5");
  add_action("hold","hold");
  add_action("hug","hug");
  add_action("kick","kick");
  add_action("kiss","kiss");
  add_action("laugh","laugh");
  add_action("lick","lick");
  add_action( "love","love");
  add_action( "moan","moan");
  add_action( "nibble","nibble");
  add_action("nod","nod");
  add_action("pat","pat");
  add_action( "poke","poke");
  add_action("pout","pout");
  add_action( "ruffle","ruffle");
  add_action("shake","shake");
  add_action( "sigh","sigh");
  add_action( "slap","slap");
  add_action( "smack","smack");
  add_action("smile","smile");
  add_action("snuggle","snuggle");
  add_action( "spank","spank");
  add_action("spit","spit");
  add_action( "tackle","tackle");
  add_action( "thank","thank");
  add_action("tickle","tickle");
  add_action("wave","wave");
  add_action( "whistle","whistle");
  add_action("wink","wink");
  add_action( "worship","worship");
  return 1;
}

fhelp() { cat("/players/trix/helpdir/helpflirt"); return 1; }
hkiss() { cat("/players/trix/helpdir/flirtlist"); return 1; }
check_edit()  { if(who->query_level()>20&&in_editor(who)) return 1; }
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

hickey(arg)
{
  object hickey;
  string hickname,place;
string self,aim,others;
  hickname=arg;
  if(!sscanf(arg,"%s %s",hickname,place))
  if(!hickname) { write("The correct command is: hickey <person> <place>.\n"); return 1; }
  who=find(hickname);
  if(!who) { write("No players with that name in this room.\n"); return 1; }
  if(who==this_player()) { write("How sick! You can't give yourself a hickey!\n"); return 1; }
  if(present("hickey",who)) { write(capitalize(hickname)+"'s got a hickey yet.\n");
                                  return 1;
                                }
  hickey=clone_object("/players/trix/closed/obj/hickey");
  call_other(hickey,"set_hicker",this_player()->query_name());
  if(place) call_other(hickey,"set_place",place);
  else place="neck";
  move_object(hickey,who);
  self="You give "+name(who)+" a hickey on "+pos(who)+" "+place+".\n";
  aim=name(me())+" gives you a hickey on your "+place+".\n";
  others=name(me())+" gives "+name(who)+" a hickey on "+pos(who)+" "+place+".\n"; 
  phone(self+":"+aim+":"+others);
  return 1;
}

kass(arg) {
 string self,aim,others;
 if(!arg) { write("You must specify a player name!\n"); return 1; }
 who=find(arg);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 self="You bend over "+name(who)+"'s cute little ass.\n";
 aim=name(me())+" bends over and kisses your cute little ass.\n";
 others=name(me())+" bends over and kisses "+name(who)+"'s cute little ass.\n";
 phone(self+":"+aim+":"+others);
 return 1;
}

khand(arg) {
 string self,aim,others;
 if(!arg) { write("You must specify a player name!\n"); return 1; }
 who=find(arg);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 self="You stare "+name(who)+" in the eyes as you softly kiss "+pos(who)+" hand.\n";
 aim=name(me())+" stares you in the eyes as "+pro(me())+" softly kisses your hand.\n"; 
 others=name(me())+" stares "+name(who)+" in the eyes as "+pro(me())+" softly kisses "+pos(who)+" hand.\n";
 phone(self+":"+aim+":"+others);
 return 1;
}

kcheek(arg) {
 string self,aim,others;
 if(!arg) { write("You must specify a player name!\n"); return 1; }
 who=find(arg);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 self="You walk up to "+name(who)+" and kiss "+ogg(who)+" on the cheek.\n";
 aim=name(me())+" walks up to you and kisses you on the cheek.\n"; 
 others=name(me())+" walks up to "+name(who)+" and kisses "+ogg(who)+" on the cheek.\n";
 phone(self+":"+aim+":"+others);
 return 1;
}

kneck(arg) {
 string self,aim,others;
 if(!arg) { write("You must specify a player name!\n"); return 1; }
 who=find(arg);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 self="You kiss "+name(who)+"'s neck passionately.\n";
 aim=name(me())+" kisses your neck passionately.\n"; 
 others=name(me())+" kisses "+name(who)+"'s neck passionately.\n";
 phone(self+":"+aim+":"+others);
 return 1;
}

khead(arg) {
 string self,aim,others;
 if(!arg) { write("You must specify a player name!\n"); return 1; }
 who=find(arg);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 self="You caress "+name(who)+"'s hair and kiss "+pos(who)+" forehead.\n";
 aim=name(me())+" caresses your hair and kisses your forehead.\n"; 
 others=name(me())+" caresses "+name(who)+"'s hair and kisses "+pos(who)+" forehead.\n";
 phone(self+":"+aim+":"+others);
 return 1;
}

kwrap(arg) {
 string self,aim,others;
 if(!arg) { write("You must specify a player name!\n"); return 1; }
 who=find(arg);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 self="You wrap your arms around "+name(who)+" and start kissing "+ogg(who)+" all over.\n";
 aim=name(me())+" wraps "+pos(me())+" arms around you and starts kissing you all over.\n"; 
 others=name(me())+" wraps "+pos(me())+" arms around "+name(who)+" and starts kissing "+ogg(who)+" all over.\n";
 phone(self+":"+aim+":"+others);
 return 1;
}

need(arg) {
 write("You seem in desperate need of affection!!!\n");
 say(name(me())+" seems in desperate need of affection!!!\n",me());
 return 1;
}
ahold(arg) {
 string self,aim,others;
 if(!arg) { write("You must specify a player name.\n"); return 1; }
 who=find(arg);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 self="You hold "+name(who)+" tightly making "+ogg(who)+" feel warm and cosy.\n";
 aim=name(me())+" holds you tightly making you feel warm and cosy.\n"; 
 others=name(me())+" holds "+name(who)+" tightly making "+ogg(who)+" feel warm and cosy.\n";   
 phone(self+":"+aim+":"+others);
 return 1;
}
ballad(arg) {
 string self,aim,others;
 if(!arg) { write("You must specify a player name.\n"); return 1; }
 who=find(arg);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 self="You go down on one knee and sing a beautiful ballad in "+name(who)+"'s honour.\n";
 aim=name(me())+" goes down on one knee and sings a beautiful ballad in your honour.\n"; 
 others=name(me())+" goes down on one knee and sings a beautiful ballad in "+name(who)+"'s honour.\n";   
 phone(self+":"+aim+":"+others);
 return 1;
}
button(arg) {
 string self,aim,others;
 if(!arg) { write("You must specify a player name.\n"); return 1; }
 who=find(arg);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 self="You stick your tongue into "+name(who)+"'s belly button "+
      "and place hot kisses around it making "+ogg(who)+" shiver with delight.\n";
 aim=name(me())+" sticks "+pos(me())+" tongue into your belly button "+
     "and places hot kisses around it making you shiver with delight.\n";
 others=name(me())+" sticks "+pos(me())+" tongue into "+name(who)+"'s belly button "+
        "and places hot kisses around it making "+ogg(who)+" shiver with delight.\n";
 phone(self+":"+aim+":"+others);
 return 1;
}
    
dkiss(arg) {
 string self,aim,others;
 if(!arg) { write("You must specify a player name.\n"); return 1; }
 who=find(arg);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 self="You give "+name(who)+" a deep kiss, leaving "+ogg(who)+" gasping for air.\n";
 aim=name(me())+" gives you a deep kiss, leaving you gasping for air. Wow!\n";
 others=name(me())+" gives "+name(who)+" a deep kiss, leaving "+ogg(who)+" gasping for air.\n";
 phone(self+":"+aim+":"+others);
 return 1;
}

jeans(arg) {
 string self,aim,others;
 if(!arg) { write("You must specify a player name.\n"); return 1; }
 who=find(arg);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 self="You sneak your hands into the back pockets of "+name(who)+"'s jeans,"+
      "pull "+ogg(who)+" very close and give "+ogg(who)+" a deep, lingering kiss.\n";
aim=name(me())+" sneaks "+pos(me())+" hands into the back pockets of your jeans, pulls you very "+
     "close and gives you a deep, lingering kiss.\n";
 others=name(me())+" sneaks "+pos(me())+" hands into the back pockets of "+name(who)+"'s jeans, pulls "+
        ogg(who)+" very close and gives "+ogg(who)+" a deep, lingering kiss.\n";
 phone(self+":"+aim+":"+others);
 return 1;
}

lgaze(arg) {
 string self,aim,others;
 if(!arg) { write("You must specify a player name.\n"); return 1; }
 who=find(arg);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 self="You gaze lovingly at "+name(who)+", staring "+ogg(who)+" deep in the eyes.\n";
 aim=name(me())+" gazes lovingly at you, staring you deep in the eyes.\n";
 others=name(me())+" gazes lovingly at "+name(who)+", staring "+ogg(who)+" deep in the eyes.\n";
 phone(self+":"+aim+":"+others);
 return 1;
}

llick(arg) {
 write("You lick your lips leaving them slightly moist.\n");
 say(name(me())+" licks "+pos(me())+" lips leaving them slightly moist.\n",me());
 return 1;
}

lscratch(arg) {
 string self,aim,others;
 if(!arg) { write("You must specify a player name.\n"); return 1; }
 who=find(arg);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 self="You reach over and start scratching "+name(who)+"'s back lovingly.\n";
 aim=name(me())+" reaches over and starts scratching your back lovingly. It feels sooo\n"+
     "good you just curl up and smile.\n";
 others=name(me())+" reaches over and starts scratching "+name(who)+"'s back lovingly.\n";
 phone(self+":"+aim+":"+others);
 return 1;
}

ltouch(arg) {
 string arg1,place,place2,self,aim,others;
 arg1=arg;
 if(!sscanf(arg,"%s %s",arg1,place))
 if(!arg1) { write("You must specify a player name.\n"); return 1; }
 who=find(arg1);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 if(place) {place2=name(who)+"'s "+place; place="your "+place; }
  else { place2=name(who) ; place="you"; }
 self="You touch "+place2+" with loving hands.\n";
 aim=name(me())+" touches "+place+" with loving hands.\n";
 others=name(me())+" touches "+place2+" with loving hands.\n";
 phone(self+":"+aim+":"+others);
 return 1;
}

lust(arg) {
 string self,aim,others;
 if(!arg) { write("You must specify a player name.\n"); return 1; }
 who=find(arg);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 self="You lust for "+name(who)+".\n";
 aim=name(me())+" lusts for you.\n";
 others=name(me())+" lusts for "+name(who)+".\n";
 phone(self+":"+aim+":"+others);
 return 1;
}

massage(arg) {
 string self,aim,others;
 if(!arg) { write("You must specify a player name.\n"); return 1; }
 who=find(arg);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 self="You give "+name(who)+" a long and tender massage.\n";
 aim=name(me())+" gives you a long and tender massage. You feel completely relaxed.\n";
 others=name(me())+" gives "+name(who)+" a long and tender massage.\n";
 phone(self+":"+aim+":"+others);
 return 1;
}

mchuckle(arg) {
 write("You chuckle merrily.\n");
 say(name(me())+" chuckles merrily.\n",me());
 return 1;
}

neck(arg) {
 string self,aim,others;
 if(!arg) { write("You must specify a player name!\n"); return 1; }
 who=find(arg);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 self="You lean closer to "+name(who)+" and bite "+pos(who)+" neck lustily.\n";
 aim=name(me())+" leans closer and bites your neck lustily. It feels very nice, "+
     "sending shivers of delight down your spine.\n";
 others=name(me())+" leans closer to "+name(who)+" and bites "+pos(who)+
        " neck lustily.\n";
 phone(self+":"+aim+":"+others);
 return 1;
}

nuzzle(arg) {
 string self,aim,others;
 if(!arg) { write("You must specify a player name!\n"); return 1; }
 who=find(arg);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 self="You bury your face in "+name(who)+"'s neck and purr happily.\n";
 aim=name(me())+" buries "+pos(me())+" face in your neck and purrs happily.\n";
 others=name(me())+" buries "+pos(me())+" face in "+name(who)+"'s neck and purrs happily.\n";
 phone(self+":"+aim+":"+others);
 return 1;
}

tlip(arg) {
 string self,aim,others;
 if(!arg) { write("You must specify a player name!\n"); return 1; }
 who=find(arg);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 self="You trace a finger down "+name(who)+"'s cheek and and let it rest gently on "+
      pos(who)+" lips for a little while.\n";
 aim=name(me())+" traces a finger down your cheek and lets it rest gently on your lips "+
     "for a little while.\n";
 others=name(me())+" traces a finger down "+name(who)+"'s cheek and lets it rest gently "+
        "on "+pos(who)+" lips for a little while.\n";
 phone(self+":"+aim+":"+others);
 return 1;
}

bhug(arg) {
 string self,aim,others;
 if(!arg) { write("You must specify a player name!\n"); return 1; }
 who=find(arg);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 self="You give "+name(who)+" a giant bearhug. "+name(who)+" gasps for air.\n";
 aim=name(me())+" gives you a giant bearhug. You gasp for air.\n";
 others=name(me())+" gives "+name(who)+" a giant bearhug. "+name(who)+" gasps for air.\n";
 phone(self+":"+aim+":"+others);
 return 1;
}

smother(arg) {
 string self,aim,others;
 if(!arg) { write("You must specify a player name!\n"); return 1; }
 who=find(arg);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 self="You smother "+name(who)+" with kisses, leaving "+ogg(who)+" happily out of breath.\n";
 aim=name(me())+" smothers you with kisses. You're happily out of breath.\n"; 
 others=name(me())+" smothers "+name(who)+" with kisses.\n";
 phone(self+":"+aim+":"+others);
 return 1;
}

thold(arg) {
 string self,aim,others;
 if(!arg) { write("You must specify a player name!\n"); return 1; }
 who=find(arg);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 self="You hold "+name(who)+" damn tight!\n";
 aim=name(me())+" holds you damn tight!\n"; 
 others=name(me())+" holds "+name(who)+" damn tight!\n";
 phone(self+":"+aim+":"+others);
 return 1;
}

huggle(arg) {
 string self,aim,others;
 if(!arg) { write("You must specify a player name!\n"); return 1; }
 who=find(arg);
 if(!who) { write("No players with that name in this room.\n"); return 1; }
 self="You huggle "+name(who)+" warmly, making "+ogg(who)+" cuddle up with you.\n";
 aim=name(me())+" huggles you warmly, making you cuddle up with "+ogg(me())+".\n"; 
 others=name(me())+" huggles "+name(who)+" warmly, making "+ogg(who)+" cuddle up with "+ogg(me())+".\n";
 phone(self+":"+aim+":"+others);
 return 1;
}

beam(arg) {
 write("You beam brightly with happiness!!!\n");
 say(name(me())+" beams brightly with happiness!!! =D\n",me());
 return 1;
}

phone(arg)
{object ob;
 string self,aim,others;
 sscanf(arg,"%s:%s:%s",self,aim,others);
 write(self);
 tell_object(who,aim);
 ob=first_inventory(environment(this_player())); 
 while(ob) { if(ob!=who&&ob!=me()) tell_object(ob,others);
 ob=next_inventory(ob); } 
}  

beg(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You beg "+name(who)+" like a dog from afar.\n");
       tell_object(who,name(me())+" begs you like a dog from afar.\n");
      }
     return 1;
   }
  return;
}

blush(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You blush at "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" blushes at you from afar.\n");
      }
     return 1;
   }
  return;
}

bow(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You bow to "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" bows before you from afar.\n");
      }
     return 1;
   }
  return;
}

chuckle(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You chuckle at "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" chuckles at you from afar.\n");
      }
     return 1;
   }
  return;
}

comfort(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You comfort "+name(who)+" tenderly from afar.\n");
       tell_object(who,name(me())+" comforts you tenderly from afar.\n");
      }
     return 1;
   }
  return;
}

cry(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You cry on "+name(who)+"'s shoulder from afar.\n");
       tell_object(who,name(me())+" cries on your shoulder from afar.\n");
      }
     return 1;
   }
  return;
}

cuddle(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You cuddle "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" cuddles you from afar.\n");
      }
     return 1;
   }
  return;
}

flirt(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You flirt with "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" seems to be making advances toward you from afar.\n");
      }
     return 1;
   }
  return;
}

french(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You give "+name(who)+" a REAL kiss from afar..it lasts a long time...\n");
       tell_object(who,name(me())+" gives you a deep and passionate kiss from afar..it seems to take forever...\n");
      }
     return 1;
   }
  return;
}

giggle(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You giggle at "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" giggles at you from afar.\n");
      }
     return 1;
   }
  return;
}

grin(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You grin evilly at "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" grins evilly at you from afar.\n");
      }
     return 1;
   }
  return;
}

growl(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You growl at "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" growls at you from afar.\n");
      }
     return 1;
   }
  return;
}

hold(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You hold "+name(who)+" tightly from afar.\n");
       tell_object(who,name(me())+" holds you tightly from afar.\n");
      }
     return 1;
   }
  return;
}

hug(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You hug "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" hugs you from afar.\n");
      }
     return 1;
   }
  return;
}

kick(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You kick "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" kicks you from afar.  OUCH!!\n");
      }
     return 1;
   }
  return;
}

kiss(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You kiss "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" kisses you from afar.\n");
      }
     return 1;
   }
  return;
}

laugh(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You laugh at "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" laughs at you from afar.\n");
      }
     return 1;
   }
  return;
}

lick(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You lick "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" licks you from afar.\n");
      }
     return 1;
   }
  return;
}

pout(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You pout at "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" pouts at you from afar.\n");
      }
     return 1;
   }
  return;
}

shake(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You shake hands with "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" shakes your hand you from afar.\n");
      }
     return 1;
   }
  return;
}

smile(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You smile happily at "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" smiles happily at you from afar.\n");
      }
     return 1;
   }
  return;
}

snuggle(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You snuggle up to "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" snuggles up to you from afar.\n");
      }
     return 1;
   }
  return;
}

spit(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You spit on "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" spits on you from afar.\n");
      }
     return 1;
   }
  return;
}

tickle(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You tickle "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" tickles you from afar. Hee,hee!!!\n");
      }
     return 1;
   }
  return;
}

wave(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You wave at "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" waves at you from afar.\n");
      }
     return 1;
   }
  return;
}

wink(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You wink at "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" winks suggestively at you from afar.\n");
      }
     return 1;
   }
  return;
}

glare(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You glare stonily at "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" glares at you from afar.\n");
      }
     return 1;
   }
  return;
}

grope(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You grope "+name(who)+"'s private parts from afar.\n");
       tell_object(who,name(me())+" gropes your private parts from afar.\n");
      }
     return 1;
   }
  return;
}

high5(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You run up and slap "+name(who)+" a high-five from afar!\n");
       tell_object(who,name(me())+" runs up to you and slaps you a high-five from afar!\n");
      }
     return 1;
   }
  return;
}

love(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You tell your true feelings to "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" whispers to you sweet words of love from afar.\n");
      }
     return 1;
   }
  return;
}

moan(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You start to moan at "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" starts moaning at you from afar.\n");
      }
     return 1;
   }
  return;
}

nibble(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You nibble "+name(who)+"'s ear from afar.\n");
       tell_object(who,name(me())+" nibbles on your ear from afar.\n");
      }
     return 1;
   }
  return;
}

poke(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You poke "+name(who)+" in the ribs from afar.\n");
       tell_object(who,name(me())+" pokes you in the ribs from afar.\n");
      }
     return 1;
   }
  return;
}

ruffle(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You ruffle "+name(who)+"'s hair playfully from afar.\n");
       tell_object(who,name(me())+" ruffles your hair playfully from afar.\n");
      }
     return 1;
   }
  return;
}

sigh(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You sigh at "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" sighs at you from afar.\n");
      }
     return 1;
   }
  return;
}

slap(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You slap "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" slaps you from afar.\n");
      }
     return 1;
   }
  return;
}

smack(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You smack "+name(who)+" across the face from afar.\n");
       tell_object(who,name(me())+" smacks you across the face from afar!\n");
      }
     return 1;
   }
  return;
}

spank(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You spank "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" spanks you from afar. Kinky!!!\n");
      }
     return 1;
   }
  return;
}

tackle(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You tackle "+name(who)+" to the ground from afar.\n");
       tell_object(who,name(me())+" tackles you from afar!\n");
      }
     return 1;
   }
  return;
}

thank(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You thank "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" thanks you from afar.\n");
      }
     return 1;
   }
  return;
}

whistle(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You whistle appreciatively at "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" whistles appreciatively at you from afar.\n");
      }
     return 1;
   }
  return;
}

worship(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You worship "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" worships at your feet from afar.\n");
      }
     return 1;
   }
  return;
}

fondle(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You fondle "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" fondles you from afar.\n");
      }
     return 1;
   }
  return;
}

nod(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You nod curtly at "+name(who)+" from afar.\n");
       tell_object(who,name(me())+" nods curtly at you from afar.\n");
      }
     return 1;
   }
  return;
}

pat(arg)
{
  if(!arg) return;
  who=find_living(arg);
  if(who&&!find(arg)&&who->query_invis()<this_player()->query_level())
   {
     if(check_edit())
       write(name(who)+" is editing, try later.\n");
     else
      {
       write("You pat "+name(who)+" on the head from afar.\n");
       tell_object(who,name(me())+" pats you on the head from afar.\n");
      }
     return 1;
   }
  return;
}

query_version() { return 4; }
get() {
        return 1;
}
drop() {
        return 1;
}
donate(arg)
{ object who,flirter;
   if(!arg)  {
      write("Whom do you want to donate a flirter?\n");
      return 1;
   }
   who=present(arg,environment(this_player()));
   if(!who||!who->query_interactive()){
      write("No "+arg+"'s in this room.\n");
      return 1;
   }
   if(present("flirter",who))
      {
      write(capitalize(arg)+"'s got a flirter yet!!!\n");
      return 1;
   }
   flirter=clone_object("/players/trix/closed/obj/flirter");
   move_object(flirter,who);
   write("You donate "+capitalize(arg)+" a flirter.\n");
  say(this_player()->query_name()+" donates "+who->query_name()+" a flirter.\n",who);
   tell_object(who,this_player()->query_name()+" donates you a flirter.\n");
   return 1;
}
dump(arg)
{  if(arg!="flirter") return;
   write("You throw the flirter in the nearest thrash bin.\n");
   destruct(this_object());
   return 1;
}
