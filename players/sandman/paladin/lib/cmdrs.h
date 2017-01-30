
/*
 * Guild Commanders Commands
 * banish()             - banish a player from Paladins
 * banish_list()        - list all banished players
 * restore()            - restore a player to Paladins
 * cmdr_tell()          - Paladin talk, overides muffles
 * summon()             - Summons a Paladin to you
 * palstat()            - More Paladin stats.
 * cmdtitle()           - Guild commander title
 * castle()             - Move guild commanders to their castle
 * cmdr_help()          - Help list
 */

#define CTITLE "the Guild Commander of Paladins"
#define COMMANDERS ({ "sandman" })
query_commanders() { return COMMANDERS; }
query_ctitle() { return CTITLE; }

#define BANISH "/players/sandman/paladin/banish_master"
#define CASTLES ([ "wulfe":"/players/molasar/rowan/castle1",\
                   "beez":"/players/molasar/rowan/castle4",\
                    "traff":"/players/molasar/rowan/castle2",\
                    "wtknight":"/players/molasar/rowan/castle5",\
                    "tristian":"/players/molasar/rowan/castle3" ])

banish(str) {
   if(member_array(this_player()->query_real_name(),COMMANDERS) == -1)
     notify_fail("Only Guild Commanders may use this command.");
   if(!str)
     notify_fail("USAGE: banish <paladin>");
   if(!restore_object("players/"+str))
    notify_fail("No one named "+capitalize(str)+" has ever visited Nirvana.");
   BANISH->banish(str);
   return 1;
}

restore(str) {
   if(member_array(this_player()->query_real_name(),COMMANDERS) == -1)
     notify_fail("Only Guild Commanders may use this command.");
   if(!str)
     notify_fail("USAGE: restore <paladin>");
   BANISH->restore(str);
   return 1;
}      

banish_list() {
   if(member_array(this_player()->query_real_name(),COMMANDERS) == -1)
     notify_fail("Only Guild Commanders may use this command.");
   BANISH->banish_list();
   return 1;
}

cmdr_tell(str) {
   object list, guild;
   int i;
   string me_tmp;
   
   if(member_array(this_player()->query_real_name(),COMMANDERS) == -1)
     notify_fail("Only Guild Commanders may use this command.");
   if(!str) 
     notify_fail("Tell paladins what?");
   me_tmp = capitalize(this_player()->query_name()); 
   list = users();
   for(i=0; i < sizeof(list); i++) {
      guild = present("guild_medal", list[i]);
      if(guild) 
        tell_object(list[i], filter_color("[*Commander*] ",HIR,list[i])+
                   me_tmp+" says '"+str+"'\n");   
   }
   return 1;
}

summon(str) {
   object target, medal;

   if(member_array(this_player()->query_real_name(),COMMANDERS) == -1)
     notify_fail("Only Guild Commanders may use this command.");
   if(!str) 
     notify_fail("USAGE: summon <paladin>");
   target = find_player(str);
   if(!target || (target->query_invis() && target->query_level() > 19))
     notify_fail(capitalize(str)+" is not on.");
   medal = present("guild_medal", target);
   if(!medal)
     notify_fail(capitalize(str)+" is not a Paladin.");
   if(environment(target)->realm() == "NT" || 
      target->query_attack() || this_player()->query_attack() || 
      environment(this_player())->realm() == "NT" )
     notify_fail("You are unable to summon "+capitalize(str)+".");
   tell_room(environment(target), capitalize(str)+" disappears in a "+
       "flash of blue light.\n");
   move_object(target, environment(this_player()));
   tell_room(environment(this_player()), capitalize(str)+" appears in a "+
       "flash of blue light.\n");
   write(filter_color("You summon "+capitalize(str)+" to you.\n",HIG));
   return 1;
}

palstat(str) {
   object target, medal;
   
   if(member_array(this_player()->query_real_name(),COMMANDERS) == -1)
     notify_fail("Only Guild Commanders may use this command.");
   if(!str) 
     notify_fail("USAGE: palstat <paladin>");
   target = find_player(str);
   if(!target || (target->query_invis() && target->query_level() > 19))
     notify_fail(capitalize(str)+" is not on.");
   medal = present("guild_medal", target);
   if(!medal)
     notify_fail(capitalize(str)+" is not a Paladin.");
   write(filter_color(target->query_name()+" "+target->query_title()+
               "\n",HIB));
   write(justify("Level:",10)+justify(target->query_level(),5)+
         justify("",7)+justify("Extra Level:",16)+
         justify(target->query_extra_level(),5)+"\n");
   if(medal->query_muffled())
     write("Guildmuffles are ON.\n");
   else
     write("Guildmuffles are OFF.\n");
   if(medal->query_wimpy_at()) 
     write("Wimpyhp: "+medal->query_wimpy_at()+"\tWimpydir: "+
           medal->query_wimypdir()+"\n");
   if(medal->query_guild_login())
     write("Set to logon at the Paladin's Guild.\n");
   else
     write("Set to logon at the Village Church.\n");
   if(medal->query_cant())
     write("Has been taught Bardic Cant.\n");
   if(medal->query_spell_blesses())
     write(target->query_name()+" is blessed.\n");
   write("\n");
   medal->msgs();
   write("\n");
   medal->abilities();
   return 1;
}

cmdtitle() {
   if(member_array(this_player()->query_real_name(),COMMANDERS) == -1)
     notify_fail("Only Guild Commanders may use this command.");
   this_player()->set_title(CTITLE);
   write(filter_color("Your are now:\n",HIG));
   write(filter_color("  "+this_player()->query_name()+" "+CTITLE+"\n",HIG));
   return 1;
}

castle() {
   string dest;
  mapping castle_list;

   castle_list = CASTLES;
   if(member_array(this_player()->query_real_name(),COMMANDERS) == -1)
     notify_fail("Only Guild Commanders may use this command.");
   if(environment(this_player())->realm() == "NT")
     notify_fail("You cannot go to your castle from here.");
   dest = castle_list[this_player()->query_real_name()];
   if(!dest)
     notify_fail("Error: Bad castle destination. Notify Molasar!");
   say(this_player()->query_name()+" disappears in a flash of light.\n");
   move_object(this_player(), dest);
   say(this_player()->query_name()+" appears in a flash of light.\n");
   this_player()->look();
   return 1;
}

cmdr_help() {
   if(member_array(this_player()->query_real_name(),COMMANDERS) == -1)
     notify_fail("Only Guild Commanders may use this command.");
write("[================================================================]\n");
write("COMMANDS:              DESCRIPTION:\n");
write("---------              ------------\n");
write("banish <paladin>       Banish <player> from the Paladins\n");
write("banishlist             List all players banished from the Paladins\n");
write("castle                 Teleport to your castle\n");
write("ctell                  Special guild talk. Goes through muffles\n");
write("cmdtitle               Set your Guild Commander title\n");
write("palstat <paladin>      Get <paladin>'s statistics\n");
write("restore <player>       Restore banished <player> to Paladins\n");
write("summon <paladin>       Summon <paladin> to your location\n");
write("[================================================================]\n");
   return 1;
}

