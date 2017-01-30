#define GUILD_ID "wizard_gob"


guild_tell_history(str)
{
  write(">> Stone History:\n\n");
  tail("/players/data/closed/wizard/data.chat_channel");
  return 1;
}

/**
 * The guild channel. 
 * I made it mimic the standard game channels in functionality.
 * sort of.
 *
 */
guild_tell(str) 
{
   object ob, gob;
   string temp,temp2,temp3,temp4;
   int v;

   if(!str) 
   {
      write("You must give a message.\n");
      return 1;
   }

   gob = present(GUILD_ID, this_player());
   if(!gob)
   {
      /* no gob, no service */
      return 0;
   }
   
   if(str == "list") 
   {
      /* lists people in a string, like channel gossip. */
      guild_tell_people();
      return 1;
   }

   if(this_player()->query_ghost())
      temp2 = "ghost";
   else temp2 = gob->query_morph_comm();

   if(!temp2) 
      temp2 = "stone";
   
   if(sscanf(str, ":%s", temp) == 1) 
   {
      if(this_player()->query_invis() > 38)
         temp = ">> (stone)" + ESC + "[0m Someone " + temp + "\n";
      else temp = ">> (stone)" + ESC + "[0m " +
         capitalize(this_player()->query_real_name()) + " " + temp + "\n";
   } else {
      if(this_player()->query_invis() > 21) temp = ">> Someone stones:" + ESC + "[0m " + str + "\n";
      else temp = ">> " + capitalize(this_player()->query_real_name()) + " stones:" + ESC + "[0m " + str + "\n";
   }
   temp = format(temp, 70);
   
   ob = users();

   guild_echo(ESC + "[0m" + ESC+"[1m"  + temp);
   return 1;
}

/** 
 * This function lists who is on the guild channel, standard game
 * lib style.
 *
 */
guild_tell_people() 
{
   object ob;
   string temp,a,b;
   int v;
   ob=users();
   
   temp = " ";
   for(v=0; v<sizeof(ob); v++) 
   {
      object oc;
      oc=present(GUILD_ID, ob[v]);
      if(oc && !oc->query_muffle()) 
      {
         if(!ob[v]->query_invis() || ob[v]->query_invis() < 19)
            temp = temp + capitalize(ob[v]->query_real_name()) + ", ";
      }
   }
   temp = "People currently on the stone channel:" + temp;
   temp = format(temp, 70);
   write(temp + "\n");
   return 1;
}

/* ---- i should make this static --- */

guild_echo(str) 
{
   object ob;
   int v;
   ob = users();
   for(v = 0; v < sizeof(ob); v++) 
   {
      object oc;
      string od;
      oc = present(GUILD_ID, ob[v]);

      if(oc && !oc->query_muffle())
      {
         tell_object(ob[v], str);
      }
   }
   write_file("/players/data/closed/wizard/data.chat_channel", str);

}

