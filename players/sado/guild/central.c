#include "/players/sado/guild/std.h"
int money_levels;

int *quest_mask;

string *level_names;

object *friends;
int num_friends;

short() { return "A small box with blinking lights on it"; }
id(str) { return "central"==str; }

reset(arg)
{
   if(arg) return;
   friends=allocate(num_friends=0);
   quest_mask=({1,2,4,8,16,32,64,128});
   level_names=({"novice","initiate","student","internate","apprentice",
         "acolyte","master","grand master","guild master"});
   money_levels=({800,1625,3250,7500,15000,30000,60000,60000});
   move_object(this_object(),"/players/sado/rooms/workroom.c");
}

add_friend(who)
{
   int i;
   object old_friends;
   
   old_friends=friends;
   friends=allocate(++num_friends);
   for(i=0;i<num_friends-1;i++)
   {
      friends[i]=old_friends[i];
   }
   friends[i]=who;
}

is_master(who)
{
  return is_friend(who) && who->query_guild_rank()>7;
}

is_friend(who)
{
  return present("pentagram",who);
}

remove_friend(who)
{
   int i,j;
   object old_friends;
   
   old_friends=friends;
   friends=allocate(num_friends-1);
   j=0;
   for(i=0;i<num_friends;i++)
   {
      if(old_friends[i]!=who)
         {
         friends[j++]=old_friends[i];
       }
   }
   num_friends--;
}

tabify(str,len)
   {
   string result;
   int i;
   
   result=str;
   for(i=strlen(str);i<len;i++) result=result+" ";
   return result;
}


f_who()
{
   int i,l;
   
   write("The following information is classified \"Alch Eyes Only\":\n");
/*        12345678901234567890123456789012345678901234567890       */
   write("Name      Rank           Location\n");
   for(i=0;i<num_friends;i++)
   {
      l=friends[i]->query_guild_rank();
      if(l>8) l=8;
      write(tabify(capitalize(friends[i]->query_real_name()),10));
      write(tabify(capitalize(level_names[l]),15));
      write(environment(friends[i])->short()+"\n");
   }
   write("Total: "+num_friends+" Alchemists logged on.\n");
}

advance(who,money)
{
   int num_quests,i,l;
   
   for(num_quests=i=0;i<7;i++)
   {
      if((who->query_guild_exp() & quest_mask[i])!=0) num_quests++;
   }
   if(who->query_guild_rank()<=num_quests)
      {
      if(money>money_levels[num_quests])
         {
         l=num_quests++;
         who->add_guild_rank(1);
         who->set_title("the "+level_names[l]+" alchemist");
         tell_object(who,"Congratulations!  Welcome to level "+l+"\n");
         f_send("-->> "+capitalize(who->query_real_name())+" is now a "+
            level_names[l]+" alchemist.\n");
      }
   }
}

f_send(msg)
{
   int i;
   
   for(i=0;i<num_friends;i++)
   if(friends[i]) tell_object(friends[i],msg);
}

f_talk(who,msg)
{
   f_send(capitalize(who->query_real_name())+"-->> "+msg+"\n");
}

f_emote(who,msg)
{
   f_send("-->> "+capitalize(who->query_real_name())+" "+msg+"\n");
}

refresh()
{
   object *peeps;
   int i;
   
   while(num_friends>0) remove_friend(friends[0]);
   peeps=users();
   for(i=sizeof(peeps)-1;i>=0;i--)
   if(present("pentagram",peeps[i])) add_friend(peeps[i]);
}

spark(str)
{
   object mon;
   
   if(!(mon=valid_target(str))) return 1;
   if(tp->query_sp()>10)
      {
      write("You feel the air around your fingertips charge up, and feel a sudden burst.\n");
      write("A small spark leeps from your fingertips and strikes "+mon->query_name()+".\n");
      mon->hit_player(random(20));
      mon->attack_object(tp);
      tp->add_sp(-10);
   }
   else
      {
      write("You feel the air around your fingertips begin to charge, but slowly the charge\n");
      write("fades away, because you could not maintain concentration.\n");
   }
   return 1;
}

lightning(str)
{
   object mon;
   
   if(!(mon=valid_target(str))) return 1;
   if(tp->query_sp()>20)
      {
      write("You feel the air around your fingertips begin to charge, and\n");
      write("the sensation builds and builds, until a massive discharge zaps the monster.\n");
      say("A bolt of lightning leaps from the hands of "+tpname+" and strikes "+mon->query_name()+".\n");
      mon->hit_player(random(50));
      mon->attack_object(tp);
      tp->add_sp(-20);
   }
   else
      {
      write("You cannot keep you concentration long enough, and though the air charges\n");
      write("up, you cannot focus its energy.\n");
   }
   return 1;
}

recruit(str)
{
   object who;
   who=find_player(str);
   if(who && (env(who) == env(tp)))
   {
     if(!who->query_guild_name())
     {
       who->set_guild_name("alchemists");
       who->set_guild_file(PENT);
       mo(co(PENT),who);
       f_emote(who,"has just been recruited!");
       who->add_guild_rank(1-who->query_guild_rank());
       who->add_guild_exp(-who->query_guild_exp());
       tell_object(who,"You have been recruited to the alchemists' guild!\n");
     }
     else
     {
       write("That player is already in a guild, and cannot be recruited!\n");
     }
     return 1;
   }
   else
   {
     return 0;
   }
}

refresh_soon()
{
   call_out("refresh",1);
}

update()
{
   refresh();
}

brew(str)
{
   object potion;
   int i;
   potion=clone_object(POTION);
   if(!potion->have_reqs(tp,str))
   {
     write("You don't have the necessary ingredients for that potion.\n");
     destruct(potion);
     return 1;
   }

   i=transfer(potion,tp);
   if(i==1)
   {
      write("You can't carry a potion.  Drop something first.\n");
      destruct(potion);
      return 1;
   }
   potion->set_type(str);

   if(tp->query_spell_point() < potion->query_cost())
   {
     write("You don't have the spell points to brew that.\n");
     destruct(potion);
     return 1;
   }
   write("The ingredients turn into a potion of "+str+".\n");
   tp->add_spell_point(-potion->query_cost());
   potion->rm_reqs(tp,str);
   return 1;
}

valid_target(str)
{
   object mon;
   
   mon=find_living(lower_case(str));
   if(!mon)
      {
      write("That monster isn't here.\n");
      return 0;
   }
   if(env(mon)!=env(tp))
      {
      write("That monster isn't here.\n");
      return 0;
   }
   if(!(mon->query_npc()))
      {
      write("You can't use this spell on players.\n");
      return 0;
   }
   return mon;
}
