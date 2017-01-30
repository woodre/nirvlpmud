inherit "obj/treasure";

reset(arg) {
 if(arg) return;
set_short("A Doppleganger Badge")
set_alias("badge");
set_long("This is a mere shell of the old Dopple badge. Long live te Dopps!\n");
   set_weight(1);
    set_value(0);

guild_who() {
   object list, guild;
   int i, rank;
   string muffles;

   list = users();
 write("<========================================>\n");
write("Rank:\tName:        \t\n");
write("-----\t-------------\t\n");
   for(i=0; i < sizeof(list); i++) {
      guild = present("badge",list[i]);
      if(guild) {
        string name;
        name = list[i]->query_name();
        name = capitalize(name);
        if(strlen(name) < 8)
          name = name + "\t";
        rank = guild->query_guild_rank();
        if(guild->query_muffled() == 0) { muffles = ""; }
        if(guild->query_muffled() == 1) { muffles = "(muffled)"; }
        if(list[i]->query_invis() > 0) { write(""); } else
        write(rank+"\t"+name+"\t"+muffles+"\n");
      }
   }
 write("<========================================>\n");
   return 1;
}
monk_tell(str) {
     object ob, guild, monk;
     int i;
     string me;

     me = this_player();
     monk = this_object();
     if(!str) {
       Write("Tell guildmembers what?\n");
       return 1;
     }
     ob = users();
     for(i = 0; i < sizeof(ob); i++) {
        guild = present("badge", ob[i]);
        if(guild && guild->query_muffled() == 0) {
        tell_object(ob[i], "{" + me->query_name() +"}: "+str+"\n");
        }
     }
     return 1;
}

:.
}
 id(str) { return str == "badge" || str == "Doppleganger Badge"; }
query_auto_load(){return "players/hawkeye/closed/badge.c";}

