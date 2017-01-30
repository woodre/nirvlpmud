#include "/players/sado/defines.h"

#define LONG_WORD 5

int active;

reset(arg)
{
   if(!arg) active = 0;
}

add_actions()
{
   add_action("help","help");
   add_action("iznon", "iznon");
   add_action("iznoff", "iznoff");
   add_action("dsay","say");
#ifndef __LDMUD__
        add_action("dsay");  add_xverb("'");
#else
           add_action("dsay","'",3);
#endif
   add_action("dgossip","gossip");
   add_action("dgossip","shout");
   add_action("dgossip","junk");
   add_action("dgossip","risque");
   add_action("dgossip","equip");
   add_action("dgossip","babble");
   if(tp && tp->query_level() >= 20)
      {
      add_action("dgossip", "wiz");
      add_action("dgossip", "announce");
   }
   add_action("dtell","tell");
   add_action("d_other","izn");
}

init()
{
   add_actions();
}

iznon()
{
   active = 1;
   write("Actiznivated...\n");
   return 1;
}

iznoff()
{
   active = 0;
   write("Dizneactivated.\n");
   return 1;
}

query_auto_load()
{
   return "/players/sado/toys/tiznoy.c:";
}

id(str)
{
   return (str == "tiznoy"  ||  str == "izn");
}

get()
{
   return 1;
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

islongword(str)
{
   int i;
   if(!stringp(str)) return 0; /* added by verte 8.3.01 */
   i = strlen(str);
   if(i < LONG_WORD) return 0;
   for(i--; i >= 0; i--)
   if(!isalpha(str,i))
      {
      return 0;
   }
   return 1;
}

distort(str)
{
   array strs;
   int i, j, num_long;
   
   if(!active) return str;
   
   strs = explode(str," ");
   
   /* Count the number of big words without apostrophes */
   num_long = 0;
   for(i=sizeof(strs)-1; i>=0; i--) if(islongword(strs[i])) num_long++;
   
   if(num_long == 0) return str;
   
   /* pick a big word to iznify */
      j = random(num_long)+1;
   
   /* find the big word again */
   num_long = 0;
   for(i=sizeof(strs)-1; i>=0; i--)
   {
      if(islongword(strs[i]))
         if(++num_long == j)
         {
         /* iznify and return */
            strs[i] = iznify(strs[i]);
         return implode(strs," ");
       }
   }
}

isalpha(str, pos)
{
   string l;
   l = lower_case(extract(str,pos,pos));
   
   return (l == "a" ||
      l == "b" ||
      l == "c" ||
      l == "d" ||
      l == "e" ||
      l == "f" ||
      l == "g" ||
      l == "h" ||
      l == "i" ||
      l == "j" ||
      l == "k" ||
      l == "l" ||
      l == "m" ||
      l == "n" ||
      l == "o" ||
      l == "p" ||
      l == "q" ||
      l == "r" ||
      l == "s" ||
      l == "t" ||
      l == "u" ||
      l == "v" ||
      l == "w" ||
      l == "x" ||
      l == "y" ||
      l == "z");
}

isvowel(str, pos)
{
   string l;
   l = lower_case(extract(str,pos,pos));
   
   if(l == "u" && pos != 0) return !(lower_case(extract(str,pos-1,pos-1)) == "q");
   
   return (l == "a"  ||
      l == "e"  ||
      l == "i"  ||
      l == "o"  ||
      l == "u"  ||
      l == "y");
}

isconsonant(str, pos)
{
   string l;
   l = lower_case(extract(str,pos,pos));
   
   if(l == "u" && pos != 0) return (lower_case(extract(str,pos-1,pos-1)) == "q");
   
   return (l == "b"  ||
      l == "c"  ||
      l == "d"  ||
      l == "f"  ||
      l == "g"  ||
      l == "h"  ||
      l == "j"  ||
      l == "k"  ||
      l == "l"  ||
      l == "m"  ||
      l == "n"  ||
      l == "p"  ||
      l == "q"  ||
      l == "r"  ||
      l == "s"  ||
      l == "t"  ||
      l == "v"  ||
      l == "w"  ||
      l == "x"  ||
      l == "z");
}

iznify(str)
   {
   int i;
   
   /* find first consonant */
   for(i=0; isvowel(str,i) && i < strlen(str); i++) {}
   
   if(i == strlen(str)) return "izn" + str;
   
   /* yoink over the consonants till we hit a vowel or the end of the word*/
   for(; isconsonant(str,i) && i < strlen(str); i++) {}
   
   if(i == strlen(str)) return str + "izn";
   
   if(i == 0) return str;
   
   /* now insert izn at position i */
   return extract(str,0,i-1) + "izn" + extract(str,i);
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
      write("The syntax is: izn '<command>' <thing to be garbled>\n(The quotes are important, ignore the <>)\n");
      return 1;
   }
   command(com+" "+distort(what),tp);
   return 1;
}

help(str)
{
   if(!id(str)) return 0;
   write("iznon to turn on Izn mode.\n");
   write("iznoff to turn off Izn mode.\n");
   write("\"izn '<command>' <thing to be Izned>\" to Izn non-standard channels\n");
   return 1;
}
