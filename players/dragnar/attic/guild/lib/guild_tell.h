#include "/players/dragnar/guild/defs/def.h"
angel_emote(str) {
   int i;
   object people, sex;
   if(!str) {
      write("Guild emote what?\n");
      return 1;
   }
people = users();
   for(i = 0; i<sizeof(people); i++) {
      sex=(present("shardak_mark",people[i]));
      if(sex && sex->query_muffled() < 1) {
         tell_object(people[i], "\n[]: "+capitalize(this_player()->query_real_name())+" "+str+"\n");
       }
   }
   return 1;
}
angel_tell(str) {
   object ob, guild, angel;
   int i;
   string me;
   
   me = this_player();
   angel = this_object();
   if(!str) {
      Write("Tell blood brothers what?\n");
      return 1;
   }
   ob = users();
   for(i = 0; i < sizeof(ob); i++) {
      guild = present("shardak_mark", ob[i]);
      if(guild && guild->query_muffled() < 1) {
         tell_object(ob[i], "[" + me->query_name() +"]: "+str+"\n");
       }
   }
   return 1;
}
angel_who() {
   object list, guild;
   int i,level;
   string muffles;
   list = users();
   write("\n");
write("________________________________________________________________________________\n");
	write("NAME:\t\tGUILD CLASS:\tRANK:\tMUFFLED: LOCATION:\n");
	write("________________________________________________________________________________\n");
   for(i=0; i < sizeof(list); i++) {
      guild = present("shardak_mark",list[i]);
      if(guild) {
         write(capitalize(list[i]->query_real_name()));
         if(strlen(list[i]->query_real_name())>7)
            write("\t"); else write("\t\t");
	if(guild->query_guild_class() == 0) write("None\t\t");
	if(guild->query_guild_class() == 1) write("Goro\t\t");
	if(guild->query_guild_class() == 2) write("Sorcerer\t");
	if(guild->query_guild_class() == 3) write("Fighter\t\t");
	write(list[i]->query_guild_rank()+"\t");
	if(guild->query_muffled() > 0) write("Yes \t");
	else write("No \t");
         if(!environment(list[i])) write("Logging in");
         else write(environment(list[i])->short());

         write("\n");
       }
   }
write("________________________________________________________________________________\n");
   return 1;
}
angel_tell_silence() {
        int mf;
        if(guildobj->query_muffled() ==0) {
        mf = 1;
        guildobj->set_muffled(mf);
        write("You will no longer hear guild tells.\n");
        return 1; }
        if(guildobj->query_muffled() == 1) {
        mf = 0;
        guildobj->set_muffled(mf);
        write("You will now hear guild tells.\n");
        return 1; }
}
