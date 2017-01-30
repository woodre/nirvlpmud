#include "/players/boltar/things/esc.h"
#define myself this_player()
static string it;
reset(arg) {
        if(arg) return;
        /* Initialization code goes here */
}
    query_auto_load() {
    return "/players/trix/closed/obj/tool.c:";
}

long() {
        write( "A magic tool entirely built by Trix, your trustable wizard!!!\n" );
        return 1;
}

short() {
  string who;
  who=this_player()->query_real_name();
  if(who!=environment(this_object())->query_real_name()) {
    tell_object(environment(this_object()),esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m");
    tell_object(environment(this_object()),capitalize(who)+" has just checked your inventory.");
    tell_object(environment(this_object()),esc+"[0m"+"\n");
   }
  return "Trix's (wiz)tool";
}

id(str) {
        if( str == "tool" ) return 1;
        return 0;
}

init() {
  add_action( "try","trye");
add_action("bb","bb");
       add_action( "ipquery","ipquery");
        add_action( "nclone", "nclone" );
        add_action( "trans", "trans" );
        add_action( "wlife","wlife");
        add_action( "changii","changii");
        add_action( "nukii", "nukii" );
        add_action( "domote", ";" );
        add_action( "dhl", "dhl" );
        add_action( "go" , "go" );
        add_action( "goin", "goin" );
   add_action("repfli","repfli");
        add_action("enviro","enviro");
        add_action("setguest","setguest");
        add_action("sethost","sethost");
        add_action( "se","se");
        add_action( "spaventa","spaventa");

        add_action( "seeinv","seeinv");
        add_action("awho","ow");
        add_action("awho","awho");
        add_action("iwho","iwho");
        add_action( "panna", "panna" );    
        add_action( "setnum","setnum");
        add_action( "set2num","set2num");
        add_action( "setword","setword");
        add_action( "check","check");
        add_action( "help", "help" );
        add_action( "steal", "steal");
        add_action( "pregn","pregn");
        add_action( "vanish", "vanish" );
        add_action( "force", "force" );
        add_action( "start", "start" );
        add_action( "snop","snop");
        add_action( "movee", "move" );
        add_action( "query_mail","qmail");
        add_action("obset","obset");
        add_action( "qidle","qidle");
        add_action( "Clone","Clone");
        add_action( "llook","Look");
        add_action( "psend","psend");
        return 1;
}


/*
** The actual trans code 
** Can transfer monsters ? I don't know :)
*/

trans( str ) {
        object  who;
        object  env;
   object       envwho;
        string  filenm;

        who = find_living( str );
        if( !who ) {
                write( "You cannot trans non-living things!\n" );
                return 1;
        }

        env = environment( this_player() );
        if( !env ) {
                write( "Bug! You have no environment!?!\n" );
                return 1;
        }


   if( !interactive( who ) ) {
                move_object( who, env );
                write( "Ok.\n" );
                return 1;
        }

        envwho = environment( who );
   tell_object( who, "\nYou lose consciousness for a while and when you wake up you see Trix in front\n" +
           "of you.\n" );
   tell_room(  env, "\nYou see a weird mist invading the room and taking the shape of " +
               who->query_name() + ".\n");
        move_object( who, env );
   tell_room(  envwho, "\nYou see " + who->query_name() + 
               " losing consistence and slowly disappearing.\n");
        return 1;
}
dhl(str)
 { 
    string stuff,rece;
    object stuff1,rece1;
    if((!str) || ((sscanf(str,"%s %s",stuff,rece) !=2)))
      {   write("You fail to send.\n");
          return 1;
      }
    if(!present(stuff) || !find_living(rece))
      {   write("Stuff or receiver not present.\n");
          return 1;
      }
    rece1=find_living(rece);
    stuff1=present(stuff);
    move_object(stuff1,rece1);
    tell_object(rece1,"A "+stuff+" is sent to u by Trix.\n");
    write( "Ok.\n" );
    return 1;
  }

go (arg) {
    object who,where;
    who= find_living(arg);
     if(!who) {
        write("No players with that name on.\n");
        return 1;
      }
    where=environment(who);
    say("Trix trembles, he suddenly seems to shine of a strange blinking light then \n"+
        "he fades away, a blue comet bounces with great blue flashes from satellite to\n"+
        "satellite ... Trix is far away.\n",this_player());
    tell_room(where,"The sky suddenly gets dark, you see electric blue reflexes above you and as\n"+
                                 "you look down , you see Trix staring at you.\n");
    move_object(this_player(),where);
    write("Ok.\n");
    return 1;
  }
   
pregn(arg)
{ object who;
  string sex;
     who= find_living(arg);
     if(!who) {
        write("No players with that name on.\n");
        return 1;
      }
  sex=who->query_gender();
  call_other(who,"set_gender","female");
  who->set_pregnancy();
  who->child_birth();
  call_other(who,"set_gender",sex);
  return 1;
}

goin (arg) {
    object who;
    who= find_living(arg);
     if(!who) {
        write("No players with that name on.\n");
        return 1;
      }
    move_object(this_player(),who);
    write("Ok.\n");
    return 1;
  }

seeinv(arg)
{
    object who,env;
    who= find_living(arg);
     if(!who) {
        write("No players with that name on.\n");
        return 1;
      }
    env=environment(this_player());
    move_object(this_player(),environment(who));
    command("look at "+lower_case(who->query_name()),this_player());
    move_object(this_player(),env);
    return 1;
  }



vanish(str)
  {
    string thing,ppl;
    object thing1,ppl1;
       if((!str) || ((sscanf(str,"%s %s",thing,ppl) !=2)))
        {  write("Vanish: Wrong syntax!\n");
           return 1;
         }
       ppl1= find_living(ppl);
       thing1= present(thing,ppl1);
       if(!ppl1 || !thing1) 
         { write("Vanish: Player or item not present!\n");
           return 1;
         }
       destruct(thing1);
      write("Ok.\n");
      tell_object(ppl1,"Trix incinerates a "+thing+" from your inventory.\n");
         return 1;
  }
       
steal(str)
  {
    string thing,ppl;
    object thing1,ppl1;
       if((!str) || ((sscanf(str,"%s %s",thing,ppl) !=2)))
        {  write("Vanish: Wrong syntax!\n");
           return 1;
         }
       ppl1= find_living(ppl);
       thing1= present(thing,ppl1);
       if(!ppl1 || !thing1) 
         { write("Vanish: Player or item not present!\n");
           return 1;
         }
       move_object(thing1,this_player());
      write("Ok.\n");
      return 1;
  }

help (arg) 
 { 
   if (arg=="tool") {
     cat("/players/trix/helpdir/helptool.c");
     return 1;
    }
 }
force(str) {
  object who;
  string what;
  if(sscanf(str,"%s %s",who,what)==2) {
    if(!find_living(who)) {
      write("That is not on the MUD!\n");
      return 1;
    }
    command(what,find_living(who));
    write("Done.\n");
        write("You forced :"+who+" to "+what+".\n");
    return 1;
  }
  write("Usage: force <player> <action>\n");
  return 1;
}

start()
{ object env,what;
  env=environment(this_player());
/*
  this_player()->set_guild_name("vampire");
  move_object(this_player(),"/players/nooneelse/black/cult_hall");
  command("sharpen fangs",this_player());
   if(!present("enhancer",this_player())) 
	{
	what=clone_object("/players/static/obj/enhancer");
	move_object(what,this_player());
	}  
*/
   if(!present("ball",this_player()))
	{
	what=clone_object("/players/trix/closed/ball");
	move_object(what,this_player());
	}
   if(!present("flirter",this_player()))
	{
	what=clone_object("/players/trix/closed/obj/flirter");
	move_object(what,this_player());
	}
   if(!present("life",this_player()))
	{
	what=clone_object("/players/trix/life");
	move_object(what,this_player());
	}
  if(!present("quicktyper",this_player()))
   {
	what=clone_object("/players/trix/obj/qt");
	move_object(what,this_player());
	command("alias a alias",this_player());
  	command("a la look at",this_player());
  	command("a gg get all",this_player());
  	command("a gf gg from",this_player());
  	command("a gc gf corpse",this_player());
  	command("a co get coins from corpse",this_player());
  	command("a ma a v la",this_player());
  	command("a gt gossip",this_player());
  	command("a gw g list",this_player());
  	command("a wl wizlist",this_player());
  	command("a h history",this_player());
  	command("a gu log trix.f",this_player());
	command("a qi qidle joan",this_player());
  	command("a ri obset ring trix set_owner trix",this_player());
  	command("a CL Clone /players/bastion/closed/ring",this_player());
  	command("a SP obset ring trix set_spouse",this_player());
  	command("a SO obset ring trix set_owner",this_player());
  	command("a guy clone ~/castle/dismonst/guy",this_player());
   command("a new do clone ~/closed/obj/tool,clone ~/closed/ball",this_player());
   }
/*
   if(present("ring",this_player())) destruct(present("ring",this_player()));
   command("Clone players/bastion/closed/ring",this_player());
   command("get ring",this_player());
   command("obset ring trix set_spouse butterfly",this_player());
   command("obset ring trix set_owner trix",this_player());
   move_object(this_player(),env);
*/
  return 1;
}



check(arg)
{ object who;
  string ppl,funct;
  if((!arg) || ((sscanf(arg,"%s %s",ppl,funct) !=2)))
         {  write("Check: Wrong syntax!\n");
            return 1;
          }
  who=find_living(ppl);
  if(!who) { write("No player with that name on.\n"); return 1; }
  write(capitalize(ppl)+"'s "+funct+": "+call_other(who,funct,)+".\n");
  return 1;
}

setnum(arg)
{ object who;
  string ppl,funct;
  int num;
  if((!arg) || ((sscanf(arg,"%s %s %d",ppl,funct,num) !=3)))
         {  write("Check: Wrong syntax!\n");
            return 1;
          }
  who=find_living(ppl);
  if(!who) { write("No player with that name on.\n"); return 1; }
  write("Ok.\n"); call_other(who,funct,num);
  return 1;
}

set2num(arg)
{ object who;
  string ppl,funct;
  int num,num2;
  if((!arg) || ((sscanf(arg,"%s %s %d %d",ppl,funct,num,num2) !=4)))
         {  write("Check: Wrong syntax!\n");
            return 1;
          }
  who=find_living(ppl);
  if(!who) { write("No player with that name on.\n"); return 1; }
  write("Ok.\n"); call_other(who,funct,num,num2);
  return 1;
}
setword(arg)
{ object who;
  string ppl,funct,word;
  if((!arg) || ((sscanf(arg,"%s %s %s",ppl,funct,word) !=3)))
         {  write("Check: Wrong syntax!\n");
            return 1;
          }
  who=find_living(ppl);
  if(!who) { write("No player with that name on.\n"); return 1; }
  write("Ok.\n"); call_other(who,funct,word);
  return 1;
}

get() {
        return 1;
}

drop() {
        return 1;
}

se(str) {
        if(!str) return 0;
        write("A Ghost "+str+"\n");
        say("Someone "+str+"\n");
        return 1;
        }
domote( str ) {
        if(!str) { write("Emote what?!?\n"); return 1;}
        write("You emote: "+call_other(this_player(),"query_name")+" "+str+"\n" );
        say(call_other(this_player(),"query_name")+" "+str+"\n" );
        return 1;
}

iwho(str) {
  object us;
string is_invis;
  int x, y;
  if(str) return;
  us=users();
write("[-----*inv player*--------*location*-------------------------------------------]\n");
  for(x=0;x<sizeof(us);x++) {
        is_invis = us[x]->short();
        y = x+1;
        if(is_invis==0){
        write("["+y + "]\t" + capitalize(us[x]->query_real_name()));
      if(strlen(us[x]->query_real_name())>7)
        write("\t"); else write("\t\t");
      write(environment(us[x])->short());
      write("\n");
        }
  }
  return 1;
}

awho(str){
object us;
int x;
if(str) return;
us = users();
write("*-----------------------------------------------------------------------------*\n");
write("*Name------Sex-Level---Guild---------Location---------------------------------*\n");
write("*-----------------------------------------------------------------------------*\n");
for(x=0;x<sizeof(us);x++){
int invis;
invis=us[x]->query_invis();
if(invis<this_player()->query_level()){
if(invis) { write(esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"); }
        write(capitalize(us[x]->query_real_name()));
        if(strlen(us[x]->query_real_name())>7)
                write("\t"); else write("\t\t");
write(esc+"[0m");
write("\b\b\b\b");
if(us[x]->query_gender()=="male")
   write("M   ");
else
   if(us[x]->query_gender()=="female")
   write("F   ");
else 
    write("C   ");
write(us[x]->query_level()+"\t\b");
if(us[x]->query_guild_name())
        if(us[x]->query_guild_name()=="Black Circle Mage")
                write("BC Mage\t\t");
        else
                write(capitalize(us[x]->query_guild_name())+"\t");

else 
      write("None\t");
if(!us[x]->query_guild_name()||strlen(us[x]->query_guild_name())<=8) write("\t");
      write("\b\b\b\b");
        if(!environment(us[x])) write("Logging in");
                else write(environment(us[x])->short());
        write("\n");}
                }
write("*-----------------------------------------------------------------------------*\n");
write("*----------------------Players currently logged on: "+x);
if(x<10) write("-");
write("------------------------*\n");
write("*-----------------------------------------------------------------------------*\n");
        return 1;
        }

snop(str)
{ object who;
  who=find_living(str);
  if(!who){ write("No players with that name.\m"); return 1; }
  write("Ok :\n");
  call_other(this_player(),"snoop",who);
  return 1;
}

movee(str)
{ if(!str) {write("Where do u want to go?\n"); return 1;}
  move_object(this_player(),"/players/"+str);
  write("Ok.\n");
  return 1;
}
enviro()
{ object env;
  env=environment(this_player());
  move_object(this_player(),environment(env));
  write("Ok.\n");
  return 1;
}
query_mail(name) {
int new_mail;
    string new,messages;
    if(!name) { write("Whose mail do u want to check???"); }
    if (!restore_object("post_dir/" + name) || messages == "") return 0;
    new = "";
    if (new_mail)
        new = " NEW";
    write("\nThere is" + new + " mail to you in the post office\n"+
        "   (south from village road).\n\n");
    return 1;
}
obset(str)
  {
    string thing,ppl,funct,value;
    object thing1,ppl1;
       if((!str) || ((sscanf(str,"%s %s %s %s",thing,ppl,funct,value) !=4)))
        {  write("obset: Wrong syntax!\n");
           return 1;
         }
       ppl1= find_living(ppl);
       thing1= present(thing,ppl1);
       if(!ppl1 || !thing1) 
         { write("Obset: Player or item not present!\n");
           return 1;
         }
       call_other(thing1,funct,value);
      write("Ok.\n");
      return 1;
  }
qidle(arg) {
    object who;
    who= find_living(arg);
     if(!who) {
        write("No players with that name on.\n");
        return 1;
      }
    write(capitalize(arg)+"'s idle : "+query_idle(who)+"\n");
    return 1;
 }
Clone(str) {
  if(!str) return;
  move_object(clone_object(str),this_player());
  return 1;
}
llook(str) {
    object ob, ob_tmp;
    string item;
    int max;
    if (!str) {
        if (call_other(this_player(), "query_brief")) {
            write(call_other(environment(), "short")); write("\n");
        } else {
            call_other(environment(), "long");
        }
        ob = first_inventory(environment());
        max = 20;
        while(ob && max > 0) {
            if (ob != myself) {
                string short_str;
                short_str = call_other(ob, "short");
                if (short_str) {
                    max -= 1;
                    write(short_str + ".\n");
                    it = short_str;
                }
            }
            ob = next_inventory(ob);
        }
        return 1;
    }
    if (sscanf(str, "at %s", item) == 1 || sscanf(str, "in %s", item) == 1) {
        item = lower_case(item);
        ob = present(item, this_player());
        if (!ob && call_other(environment(this_player()), "id", item))
            ob = environment(this_player());
        if (!ob)
            ob = present(item, environment(this_player()));
        if (!ob) {
            write("There is no " + item + " here.\n");
            return 1;
        }
        it = item;
        call_other(ob, "long", item);
        if (!call_other(ob, "can_put_and_get", item))
            return 1;
        if (living(ob)) {
            object special;
            special = first_inventory(ob);
            while (special) {
                string extra_str;
                extra_str = call_other(special, "extra_look");
                if (extra_str)
                    write(extra_str + ".\n");
                special = next_inventory(special);
            }
        }
        ob_tmp = first_inventory(ob);
        while (ob_tmp && call_other(ob_tmp, "short") == 0)
            ob_tmp = next_inventory(ob_tmp);
        if (ob_tmp) {
            if (living(ob))
                write("\t" + capitalize(item) + " is carrying:\n");
            else
                write("\t" + capitalize(item) + " contains:\n");
        }
        max = 20;
        ob = first_inventory(ob);
        while (ob && max > 0) {
            string sh;
            sh = call_other(ob, "short");
            if (sh)
                write(sh + ".\n");
            ob = next_inventory(ob);
            max -= 1;
        }
        return 1;
    }
    write("Look AT something, or what?\n");
    return 1;
}
setguest(str)
{ object horse;
  horse=clone_object("/players/hurtbrain/guildflyer");
  move_object(horse,"/players/trix/closed/room/oroom");
  if(str) call_other("/players/trix/closed/room/oroom","setguest",str);
  write("PPL: "+
  call_other("/players/trix/closed/room/oroom","queryppl")+".\n");
  destruct(horse);
  return 1;
}

sethost(str)
{ object horse;
  horse=clone_object("/players/hurtbrain/guildflyer");
  move_object(horse,"/players/trix/closed/room/oroom");
  if(str) call_other("/players/trix/closed/room/oroom","sethost",str);
  write("PPL: "+
  call_other("/players/trix/closed/room/oroom","queryppl")+".\n");
  destruct(horse);
  return 1;
}

psend(arg)
{
  object who;
  string person,room;
  if(!arg||sscanf(arg,"%s %s",person,room)!=2) 
     {    write("Syntax: psend <person> <room>\n");
	  return 1;
     }
  who=find_living(person);
  if(!who)
     {    write("No form of life called "+person+".\n");
	  return 1;
     }
  move_object(who,room);
  return 1;
}
nukii(str)
{ object what;
  if(!str) {write("Nukii what?\n"); return 1; }
  what=find_object(str);
  while(what) {
    write("Destroyed: "+str+".\n");
    write("OBJ: ");
    write(what);
    write("\n");
    what=find_object(str+str);
  }
  write("Ok.\n");
  return 1;
}
changii(str)
{ object what,ob;
  int num;
  string strwho;
  if(!str) {write("changii what?\n"); return 1; }
  if(sscanf(str,"%s %d",strwho,num)!=2) { write("Syntax: changii <who> <ac-num>\n"); return 1; }
  what=environment(find_living(strwho));
  ob=first_inventory(what);
  while(ob) {
    if(ob->query_name()=="Mercenary")
        call_other(ob,"set_ac",num);
    ob=next_inventory(ob);
    write("Yeah!\n");
  }
  write("Ok.\n");
  return 1;
}
wlife(str) {
  object us;
  int x;
  string who;
  if(str) return;
  us=users();
  for(x=0;x<sizeof(us);x++) {
if(present("soul-undead",us[x])){
	write(capitalize(us[x]->query_real_name()));
	if(strlen(us[x]->query_real_name())>7)
	write("\t"); else write("\t\t");
write(esc+"[0m");
	who=call_other(present("soul-undead",us[x]),"query_dirname");
	write(": "+who+".\n");
  }
  }
  return 1;
}
repfli(arg){
object us,fli;
int x;
us = users();
for(x=0;x<sizeof(us);x++){
   fli=present("flirter",us[x]);
   if(fli)
    {   write("Updated "+us[x]->query_name()+"'s flirter.\n");
	tell_object(us[x],esc+"[0m"+esc+"[1m"+esc+"[5m"+esc+"[32m"+esc+"[40m"+
                    "You now have a newer version of the flirter.\n");
        if(arg) tell_object(us[x],capitalize(arg)+".\n");
        tell_object(us[x],esc+"[0m");
        destruct(fli);
        fli=clone_object("/players/trix/closed/obj/flirter");
        move_object(fli,us[x]);
    }
 }
 return 1;
}
bb() {
shout("\n     ________________                           ______________\n");
shout("    \/                \\                         \/ \/            \\---_\n");
shout("   \/ \/          \\ \\   \\                       |     -    -         \\\n");
shout("   |                  |                       | \/         -   \\  _  |\n");
shout("  \/                  \/                        \\    \/  \/   \/\/    __   \\\n");
shout(" |      ___\\ \\| | \/ \/                          \\\/ \/\/ \/\/ \/ \/\/\/  \/      \\\n");
shout(" |      \/          \\                           |             \/\/\\ __   |\n");
shout(" |      |           \\                          \\              \/\/\/     \\\n");
shout("\/       |      _    |                           \\               \/\/  \\ |\n");
shout("|       |       \\   |    Hurtbrain               \\   \/--          \/\/  |\n");
shout("|       |       _\\ \/|     sucks!!!!               \/ (o-            \/ \\|\n");
shout("|      __\\     <_o)\\o-        \/                  \/            __   \/\\ |\n");
shout("|     |             \\        \/     Yeah,        \/              .)  \/  |\n");
shout(" \    ||             \\      \/      Heh Heh Heh \/   __          &\/ \/ \\ |\n");
shout("  |   |__          _  \\    \/       Heh Heh. \\ (____ *)         -  |   |\n");
shout("  |   |           (*___)  \/                  \\    \/               |  |\n");
shout("  |   |       _     |    \/                    \\  (____            |  |\n");
shout("  |   |    \/\/_______\/                             ####\\           |  |\n");
shout("  |  \/       | UUUUU__   \\                    \/   ____\/ )         |_\/\n");
shout("   \\|        \\_nnnnnn_\\~\\ \\                  \/   (___             \/\n");
shout("    |       ____________\/  \\                \/     \\____          |\n");
shout("    |      \/             Ya, ya,       Trix           \\          |\n");
shout("    |_____\/               YA!         is  Cool!        \\__________\\\n");
return 1;
}

try()
{ string prova;
this_player()->add_spell_point("iueyrwieouryeiuwytrioueyriouruyteytewioutyiorewuytrewiouytiewutyioreuytiourewytriueytieourtyreiouytioeuoireuqoieuteqoirueytrqeiouqreioutyreiuyoituwwoye");
  return 1;
}
nclone(str) {
   int i,number;
   string stuff;
   if((!str) || ((sscanf(str,"%s %d",stuff,number) !=2)))
     {   write("Syntax: nclone <number> <objpath>.\n");
         return 1;
     }
   for(i=1;i<=number;i++)
   move_object(clone_object(stuff),environment(this_player()));
   write("Ok.\n");
   return 1;
}
panna(str) {
  object us;
  int x;
  if(str) return;
  us=users();
  for(x=0;x<sizeof(us);x++) {
      if(us[x]->query_level()<20||us[x]->query_level())
      {
      write(us[x]->query_name()+"\n");
      move_object(clone_object("/players/trix/castle/dismonst/machine/panna.c"),us[x]);
      tell_object(us[x],"A portion of Panna Elena lands in your hands.\n"+
                  "This is a gift, but you can buy more in the restaurant under the EclYpsE.\n");
      } 
    }
  return 1;
  }
ipquery(arg)  {
   object mate;
   string m_morph;
   if(!arg) {
      write("Whose stats do u want to check?\n");
      return 1;
   }
   mate=clone_object("/players/trix/closed/guild/qgm");
   call_other(mate,"set_search",arg);
   move_object(mate,this_player());
   if(mate->query_name()=="<noone>") {
         write("No players called "+arg+".\n");
         return 1;
      }
   write("IP NUMBER: "+mate->query_last_ip()+">\n");  
   destruct(mate);
   return 1;
   }
spaventa(str) {
   object us;
   int x;
   if(!str) return;
   us=find_living(str);

tell_object(us,"Hydra arrives.\n");
tell_object(us,"Hydra smashes you with a bone crashing sound.\n");
tell_object(us,"You missed.\n");
tell_object(us,"Hydra hits you very hard.\n");
tell_object(us,"\n");
tell_object(us,"You feel very weak as your badly damaged body ");
tell_object(us,"falls to the ground to die.\n\n");
tell_object(us,"You die.\n");
tell_object(us,"You have a strange feeling.\n");
tell_object(us,"You can see your own dead body from above.\n");
tell_object(us,"\n");
tell_object(us,"setting hit points to 1/3 max....\n\n\n");

   return 1;
}

