inherit "obj/treasure.c";

init()
{
   ::init();
#ifndef __LDMUD__
   add_action("dsay"); add_xverb("'");
#else
  add_action("dsay", "'", 3);
#endif
   add_action("dsay","say");
   add_action("dsay","dsay");
   add_action("dgossip","gossip");
   add_action("dgossip","shout");
   add_action("dgossip","junk");
   add_action("dgossip","risque");
   add_action("dgossip","equip");
   add_action("dgossip","wiz");
   add_action("dgossip","announce");
   add_action("dtell","tell");
   add_action("d_other","ddo");
}

query_auto_load() { return "/players/sado/shop/drunk.c:"; }

reset(arg) { if(!arg) set_id("drunk"); }

drop() { return 1; }

dgossip(str)
{
   if(str[0]==':') this_player()->broadcast(str);
   else if(explode(str," ")[0]=="list") this_player()->broadcast(str);
   else this_player()->broadcast(distort(str));
   return 1;
}

dtell(str)
{
   string *parse;
   string what;
   int i;
   
   if(!str) return 0;
   parse=explode(str," ");
   if(sizeof(parse)<2) return 0;
   what=parse[1];
   for(i=2;i<sizeof(parse);i++)
   what=what+" "+parse[i];
   tell(parse[0]+" "+distort(what));
   return 1;
}

tell(str) {
   object ob;
   string it;
   string who;
   string msg;
   if (!str || sscanf(str, "%s %s", who, msg) != 2) {
      write("Tell what?\n");
      return 1;
   }
   it = lower_case(who);
   ob = find_player(it);
   if (!ob) ob = find_living(it);
   if (!ob) {
      write("No player with that name.\n");
      return 1;
   }
   if (interactive(ob)) {
      if (in_editor(ob)) {
         write("That person is editing. Please try again later.\n");
         return 1;
       }
   }
   msg = format(msg, 60);
   tell_object(ob, this_player()->query_name() + " tells you: " + msg + "\n");
   write("You tell "+who+ " " + msg);
   return 1;
}

dsay(str)
{
   say(this_player()->query_name()+" says: "+distort(str)+"\n");
   write("You say: "+distort(str)+"\n");
   return 1;
}

distort(str)
{
   string msg,temp,letter;
   int i;
   msg="";
   for(i=0;i<strlen(str);i++)
   {
      letter=extract(str,i,i);
      if(this_player()->query_intoxination()>random(this_player()->query_level()))
         {
         if(lower_case(letter)=="s") temp="h";
         else if(lower_case(letter)=="r") temp="r";
         else if(letter=="l" && extract(str,i-1,i-1)=="l") temp="l";
         else if(letter==" " && random(4)==1) temp="(hic) ";
         else if(letter==" " && random(4)==1) temp="(burp) ";
         else temp="";
         if((letter=="'" && str[i+1]=='t') ||
               (letter=="s" && str[i+1]=='s')) i++;
         msg=msg+letter+temp;
       } else msg=msg+letter;
   }
   return msg;
}

d_other(str)
{
   string com,what;
   if(!str) {write("Drunken Do"); return 0;}
   if(sscanf(str,"'%s' %s",com,what)!=2)
      {
      write("The syntax is: ddo '<command>' <thing to be garbled>\n");
      return 1;
   }
   command(com+" "+distort(what),this_player());
   return 1;
}
