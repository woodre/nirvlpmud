#include "/players/sado/defines.h"

init()
{
   add_action("dsay","say");
#ifndef __LDMUD__ /* Rumplemintz */
   add_action("dsay"); add_xverb("'");
#else
   add_action("dsay", "'", 3);
#endif
   add_action("help","help");
   add_action("dgossip","gossip");
   add_action("dgossip","shout");
   add_action("dgossip","junk");
   add_action("dgossip","risque");
   add_action("dgossip","equip");
   if(tp && tp->query_level() >= 20)
      {
      add_action("dgossip", "wiz");
      add_action("dgossip", "announce");
   }
   /*
   else
      {
      add_action("check_stumble"); add_xverb("");
   }
   */
   add_action("dtell","tell");
   add_action("d_other","ddo");
}

query_auto_load()
{
   return "/players/sado/shop/drunk.c:";
}

id(str)
{
   return (str == "drunk");
}

drop()
{
   return 1;
}

dgossip(str)
{
   if(str[0]==':') tp->broadcast(str);
   else if(explode(str," ")[0]=="list") tp->broadcast(str);
   else if(explode(str," ")[0]=="off")  tp->remove_channel(query_verb());
   else tp->broadcast(distort(str));
   return 1;
}

dtell(str)
{
   string who;
   string msg;
   
   if(!str || sscanf(str, "%s %s", who, msg) != 2) return 0;
return this_player()->tell(who+" "+distort(msg));
}

dsay(str)
{
   say(tpname+" says: "+distort(str)+"\n");
   write("You say: "+distort(str)+"\n");
   return 1;
}

distort(str)
{
   string msg,temp;
   int i;
  if(!str) return "";
   msg="";
   for(i=strlen(str)-1; i >= 0; i--)
   {
      if(tp->query_intoxination() >
            random(tp->query_level()))
      {
         if(str[i]=='s') temp="sh";
         else if(str[i]=='S') temp="Sh";
         else if(str[i]=='r') temp="rr";
         else if(str[i]=='R') temp="Rr";
         else if(str[i]=='l' && i != 0 && str[i-1]=='l') temp="ll";
         else if(str[i]==' ' && random(4)==1) temp=" (hic) ";
         else if(str[i]==' ' && random(4)==1) temp=" (burp) ";
         else if(str[i]=='c' && (str[i+1]=='e' || str[i+1]=='i' || str[i+1]=='y')) temp="sh";
         else if(str[i]=='C' && (str[i+1]=='e' || str[i+1]=='i' || str[i+1]=='y')) temp="Sh";
         else if((str[i]=='\'' && str[i+1]=='t') ||
               (str[i]=='s' && str[i+1]=='s')) temp="";
         else temp=extract(str,i,i);
       }
      else temp=extract(str,i,i);
      msg = temp + msg;
   }
   return msg;
}

d_other(str)
{
   string com,what;
   if(!str)
      {
      return 0;
   }
   if(sscanf(str,"'%s' %s",com,what)!=2)
      {
      write("The syntax is: ddo '<command>' <thing to be garbled>\n(The quotes are important, ignore the <>)\n");
      return 1;
   }
   command(com+" "+distort(what),tp);
   return 1;
}

help(str)
{
   if(!id(str)) return 0;
   cat("/players/sado/shop/drunk_help");
   return 1;
}

random_walk()
{
   string exits;
   int i,j;
   object here;
   
   here=environment(environment());
   exits=here->query_dest_dir();
   i=sizeof(exits)/2;
   j=random(i);
   command(exits[j*2+1], environment());
   tell_object(environment(),"You stumble out of the room in your stupor.\n");
   tell_room(here,environment()->query_name()+" stumbles out of the room to the ");
   tell_room(here,exits[j*2+1]+".\n");
}

check_stumble(str)
{
return 0;
   if(tp->query_intoxination() >=
         (tp->query_level() * 3) / 4)
   if(random(tp->query_level())==1)
      {
      write("You try to "+query_verb()+" "+str+" but you're too drunk.\n");
      random_walk();
      return 1;
   }
   return 0;
}
