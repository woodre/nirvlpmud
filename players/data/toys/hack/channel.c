#include "/players/data/ansi.h"
#define HACK_CHANNEL "hack_channel"
int muffle;
query_muffle() { return muffle; }


channel_tell_history(str)
{
  write(">> hack History:\n\n");
  tail("/players/data/toys/channel_history");
  return 1;
}

/**
 * The guild channel. 
 * I made it mimic the standard game channels in functionality.
 * sort of.
 *
 */
channel_tell(str) 
{
   object ob, narf;
   string temp,temp2,temp3,temp4;
   int v;

   if(!str) 
   {
      write("You must give a message.\n");
      return 1;
   }

   narf = present(HACK_CHANNEL, this_player());
   if(!narf)
   {
      /* no narf, no service */
      return 0;
   }
   
   if(str == "list") 
   {
      /* lists people in a string, like channel gossip. */
      channel_tell_people();
      return 1;
   }

   if(this_player()->query_ghost())
      temp2 = "ghost";
   else temp2 = narf->query_morph_comm();

   if(!temp2) 
      temp2 = "hack";
   
   if(sscanf(str, ":%s", temp) == 1) 
   {
      if(this_player()->query_invis() > 20)
         temp = ">> (hack)" + ESC + "[0m Someone " + temp + "\n";
      else temp = ">> (hack)" + ESC + "[0m " +
         capitalize(this_player()->query_real_name()) + " " + temp + "\n";
   } else {
      if(this_player()->query_invis() > 21) temp = ">> Someone hacks:" + ESC + "[0m " + str + "\n";
      else temp = ">> " + capitalize(this_player()->query_real_name()) + " hacks:" + ESC + "[0m " + str + "\n";
   }
   temp = format(temp, 70);
   
   ob = users();

   channel_echo(ESC + "[0m" + ESC+"[1m"  + temp);
   return 1;
}

/** 
 * This function lists who is on the guild channel, standard game
 * lib style.
 *
 */
channel_tell_people() 
{
   object ob;
   string temp,a,b;
   int v;
   ob=users();
   
   temp = " ";
   for(v=0; v<sizeof(ob); v++) 
   {
      object oc;
      oc=present(HACK_CHANNEL, ob[v]);
      if(oc)
      {
         if(!ob[v]->query_invis() || ob[v]->query_invis() < 19)
            temp = temp + capitalize(ob[v]->query_real_name()) + ", ";
      }
   }
   temp = "People currently on the hack channel:" + temp;
   temp = format(temp, 70);
   write(temp + "\n");
   return 1;
}

/* ---- i should make this static --- */

channel_echo(str) 
{
   object ob;
   int v;
   ob = users();
   for(v = 0; v < sizeof(ob); v++) 
   {
      object oc;
      string od;
      oc = present(HACK_CHANNEL, ob[v]);

      if(oc && !oc->query_muffle())
      {
         tell_object(ob[v], str);
      }
   }
   write_file("/players/data/toys/channel_history", str);

}

muffle(str)
{ if(!muffle){ write("You turn on your firewall and muffle the Hack Channel.\n");
 muffle = 1; 
} 
else{ 
write("You turn the hack channel back on!\n");
 muffle = 0; 
} 
return 1; 
}
