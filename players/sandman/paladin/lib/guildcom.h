
/*
 * GUILD COMMUNICATION (2/11/94)
 *     muffles()      -  muffle/unmuffle guild messages
 *     guild_tell()   -  talk to guildmembers
 *     guild_emote()  -  emote guild messages
 *     guild_echo()   -  echo guild messages
 *     guild_who()    -  show members logged on
 */

muffles() {
   int muffs;

   muffs = previous_object()->query_muffled();
   muffs = !muffs;
   if(muffs) {
     write(filter_color("Your muffles are ON.\n",HIG));
     previous_object()->set_muffled(1);
   }
   if(!muffs) {
     write(filter_color("Your muffles are OFF.\n",HIG));
     previous_object()->set_muffled(0);
   }
   return 1;
}

guild_tell(str) {
   object list, guild;
   int i;
   string me_tmp;
   me_tmp = capitalize(this_player()->query_name());
   if(!str) 
     notify_fail("Tell paladins what?");
   if(previous_object()->query_muffled()) 
     notify_fail("You must remove your muffles first.");
   list = users();
   for(i=0; i < sizeof(list); i++) {
      guild = present("guild_medal", list[i]);
      if(guild && !guild->query_muffled()) 
      tell_object(list[i], filter_color("[Paladin] ",HIB,list[i])+me_tmp+
                  " says '"+str+"'\n");   
   }
   return 1;
}

guild_emote(str) {
   object list, medal;
   int i;
   string me_tmp;
   
   if(!str) 
     notify_fail("What would you like to emote to the guild members?");
   if(previous_object()->query_muffled()) 
     notify_fail("You must remove your muffles first.");
   me_tmp = capitalize(this_player()->query_name());
   list = users();
   for(i=0; i < sizeof(list); i++) {
      medal = present("guild_medal", list[i]);
      if(medal && !medal->query_muffled())
        tell_object(list[i], filter_color("[Paladin] ",HIB,list[i])+
            me_tmp+" "+str+"\n");
   }
   return 1;
}

guild_echo(str) {
   object list, medal;
   int i;
   
   if(this_player()->query_level() < 100)
     notify_fail("You cannot use this command.");
   if(!str) 
     notify_fail("What would you like to emote to the guild members?");
   if(previous_object()->query_muffled()) 
     notify_fail("You must remove your muffles first.");
   list = users();
   for(i=0; i < sizeof(list); i++) {
      medal = present("guild_medal", list[i]);
      if(medal && !medal->query_muffled())
        tell_object(list[i], filter_color("[Paladin] ",HIB,list[i])+str+"\n");
   }
   return 1;
}

guild_who() {
   object list, guild;
   int i;
   string where;

   list = users();
   write("\n");
   if(previous_object()->query_color())
     write(HIB);
   write("Paladins logged on:\n");
write("[===============================================================]\n");
   if(previous_object()->query_color())
     write(NORM);
   write(justify("Level:",8)+justify("Name:",14)+justify("Location:",50));
   write("\n");
   write(justify("------",8)+justify("-----",14)+justify("---------",50));
   write("\n");
   for(i=0; i< sizeof(list); i++) {
      where = 0;
      guild = present("guild_medal", list[i]);
      if(guild) {
        string name;
        int lvl;
        name = list[i]->query_name();
        lvl = list[i]->query_level();
        if(this_player()->query_level() > 20)
          where = file_name(environment(list[i]));
        else
          if(lvl < 21)
            where = environment(list[i])->short();
        if(!where)
          where = "Nirvana";
        if(lvl > 20) lvl = "WIZ";
        if(guild->query_muffled()) 
          name = "*"+name;
        if(list[i]->query_invis() > 0) { write(""); } else 
          write(justify(lvl,8)+justify(name,14)+justify(where,50)+"\n");
      }
   }
   if(previous_object()->query_color())
     write(HIB);
write("[===============================================================]\n");
   if(previous_object()->query_color())
     write(NORM);
   return 1;
}

master_channel(str) {
   object list, guild;
   int i;

   list = users();
   for(i=0; i < sizeof(list); i++) {
      guild = present("guild_medal",list[i]);
      if(guild)
        tell_object(list[i], filter_color("[*PALADIN*] "+str, HIB, list[i]));
   }
}

