#include "/players/hippo/bs.h"
reset(arg) {
        if(arg) return;
}
long() {
       write("A wiztool. Type <help hiptool> for more info.\n");
        return 1;
}

short() {
   return "The hiptool";
}

id(str) {
         if(str=="hiptool") return 1;
        return 0;
}

init() {
        add_action( "trans", "trans" );
        add_action( "Heal", "hh" );
        add_action( "echo", "echo" );
        add_action( "room", "room" );
        add_action( "do_emote", "ping" );
        add_action( "dhl", "dhl" );
        add_action( "goin", "goin" );
         add_action( "help", "help" );
        add_action( "vanish", "vanish" );
        add_action( "force", "force" );
        add_action( "hsp", "hsp" );
	add_action( "leaf", "leaf" );
	add_action( "check", "check" );
        add_action( "check2", "check_ob" );
	add_action("awho","awho");
	add_action("iwho","iwho");
	add_action("wind","wind");
        return 1;
}

wind (str)  {
	int num;
	object obj,env;
	if(!str)  {
		notify_fail("Who do you want to wind?\n");
		return 0;
		}
	num=0;
	sscanf(str,"%s %d",str,num);
	obj=find_living(str);
	if(!obj)   {
		notify_fail("No "+str+" active now.\n");
		return 0;
		}
	if(obj == find_player(str))  {
		notify_fail("You can't wind a player!\n");
		return 0;
		}
	env=environment(obj);
	write("You cast a magic wind on "+ call_other(obj,"query_name")+".\n");
	tell_room(env,"A magic wind starts to blow and "+call_other(obj,"query_name")+" gets some damage from it!\n");
	if(!num)
                call_other(obj,"hit_player",(obj->query_mhp())+1);
	else
		call_other(obj,"hit_player",num);
	return 1;
}

iwho(str) {
  object us;
string is_invis;
  int x, y;
  if(str) return;
  us=users();
write("Invisible player------------>location\n");
  for(x=0;x<sizeof(us);x++) {
        is_invis = us[x]->short();
        y = x+1;
        if(is_invis==0){
        write(y + ".\t"+capitalize(us[x]->query_real_name()));
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
int x, y;
if(str) return;
us = users();
write("]-------|player|----------|location|------------------------------------------->\n");
for(x=0;x<sizeof(us);x++){
        y = x + 1;
        write(y + ".\t" + capitalize(us[x]->query_real_name()));
        if(strlen(us[x]->query_real_name())>7)
                write("\t"); else write("\t\t");
        if(!environment(us[x])) write("Logging in");
                else write(environment(us[x])->short());
        write("\n");
        }
return 1;
}

check(arg)
{ object who;
  string ppl,funct;
  int nset;
  nset=0;
  if((!arg) || (!(sscanf(arg,"%s %s %d",ppl,funct,nset))))
         {  notify_fail("Check: Wrong syntax!\n");
            return 0;
          }
  who=find_living(ppl);
  if(!who) { write("No player with that name on.\n"); return 1; }
  write(capitalize(ppl)+"'s "+funct+": "+call_other(who,funct,nset)+".\n");
  return 1;
}


check2(arg)
{ object who;
  string ppl,funct;
  int nset;
  nset=0;
  if((!arg) || (!(sscanf(arg,"%s %s %d",ppl,funct,nset))))
         {  notify_fail("Check: Wrong syntax!\n");
            return 0;
          }
  who=present(ppl,this_player());
  if(!who) { write("No object with that name on.\n"); return 0; }
  write(capitalize(ppl)+"'s "+funct+": "+call_other(who,funct,nset)+".\n");
  return 1;
}



leaf(str)
 {
      string stuff,rece;
       object stuff1,rece1;
       rece=str;
       if((!str))
	      {   notify_fail("You fail to send.\n");
              return 0;
	      }
     if(!present("letter") || !find_living(rece))
               { notify_fail ("Letter or receiver not present."+BS);
               return 0;
             }
 rece1=find_living(rece);
 stuff1=present("letter");
 move_object(stuff1,rece1);
write("You send a letter to "+rece1->query_name()+"."+BS);
tell_object(rece1,"You just got a letter from Hippo. The envelope says: 'read this immediately!'"+BS);
 return 1;
 }
 

       
hsp(str) {
  object who;
  string what;
  if(str) {
    who=find_living(str);
    if(!who) {
      notify_fail("That is not on the MUD!\n");
      return 0;
    }
        write(who->query_name()+" : hit points: "+who->query_hp()+"; spell points: "+who->query_sp()+".\n");
    return 1;
  }
  write("Usage: hsp <monster>\n");
  return 1;
}

echo(str)
{
if(!str)  {
	shout("\n");
	write("\n");
	return 1;
	}
shout(str+"\n");
write(str+"\n");
return 1;
}

room(str)
{
if(!str)  {
	tell_room(environment(this_player()),"\n");
	return 1;
	}
tell_room(environment(this_player()),str+"\n");
return 1;
}

trans( str ) {
        object  who;
        object  env;
   object       envwho;
        string  filenm;

        who = find_living( str );
        if( !who ) {
                notify_fail( "You cannot trans non-living things!\n" );
                return 0;
        }

        env = environment( this_player() );
        if( !env ) {
                notify_fail( "Bug! You have no environment!?!\n" );
                return 0;
        }

   if( !interactive( who ) ) {
                move_object( who, env );
                write( "Ok.\n" );
                return 1;
        }

        envwho = environment( who );
   tell_object( who, "Wow.. what is this, man?? You are thorn away from where you were, and put on a chair in front of Hippo."+BS);
   tell_room(  env, "As Hippo blinks, " +who->query_name() +
       " appears at his feet.\n");
        move_object( who, env );
   tell_room(  envwho, "\nYou see a flash of light ." +who->query_name() + 
               " disappears in it.\n");
        return 1;

}
dhl(str)
 { 
    string stuff,rece;
    object stuff1,rece1;
    if((!str) || ((sscanf(str,"%s %s",stuff,rece) !=2)))
      {   notify_fail("You fail to send.\n");
          return 0;
      }
    if(!present(stuff) || !find_living(rece))
      {   notify_fail("Stuff or receiver not present.\n");
          return 0;
      }
    rece1=find_living(rece);
    stuff1=present(stuff);
    move_object(stuff1,rece1);
   tell_object(rece1,"'Here, you are!', you hear Hippo saying, as he gives a "+stuff+" to you"+BS);
    write("You send a "+stuff+" to "+rece1->query_name()+".\n");

    return 1;
  }
goin (arg) {
    object who;
    who= find_living(arg);
     if(!who) {
        notify_fail("No players with that name on.\n");
        return 0;
     }
    move_object(this_player(),who);
    write("Ok.\n");
    return 1;
  }

vanish(str)
  {
    string thing,ppl;
    object thing1,ppl1;
       if((!str) || ((sscanf(str,"%s %s",thing,ppl) !=2)))
        {  notify_fail("Vanish: Wrong syntax!\n");
           return 0;
         }
       ppl1= find_living(ppl);
       thing1= present(thing,ppl1);
       if(!ppl1 || !thing1) 
         { notify_fail("Vanish: Player or item not present!\n");
           return 0;
         }
       destruct(thing1);
      write("Ok.\n");
     tell_object(ppl1,"Hippo keeps looking friendly, but with a quick snap, he grabs a "+thing+" from your inventory."+BS);
         return 1;
  }
       
force(str) {
  object who;
  string what;
  if(sscanf(str,"%s %s",who,what)==2) {
    if(!find_living(who)) {
      notify_fail("That is not on the MUD!\n");
      return 0;
    }
    command(what,find_living(who));
    write("Done.\n");
    write("You forced :"+who+" to "+what+".\n");
    return 1;
  }
  write("Usage: force <player> <action>\n");
  return 1;
}

get() {
        return 1;
}

drop() {
        return 1;
}

do_emote( str ) {
        if( !str ) return 0;
        write( "You "+str+".\n" );
      say( "Hippo "+ str + "."+BS );
        return 1;
}

Heal(str)
{
	call_other(this_player(),"heal_self",1000);
	return 1;
}


help (arg) 
 { 
   if (arg=="hiptool") {
   cat ("/players/hippo/misc/hiptool_help.txt");
     return 1;
    }
 }
