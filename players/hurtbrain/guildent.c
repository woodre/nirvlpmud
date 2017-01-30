int exp_str;
int guild_rank, guild_exp;
string guild_name;
short(){ return "Entrance to Undead Crypt"; }
long() {
 write("  To the east you can see a dark crypt.  On the entrance is written\n" +
       "  arcane symbols that have a meaning only for the Undead. It is\n"+
       "  very dark and gloomy here and the smell of death is about. This\n"+
       "  is where the Undead come to raise their power and train new skills\n"+
       "  when they are ready for them. Look at the sign for precise info.\n"+
       "    There is one obvious exit: east.\n");
}
init(){
   set_light(1);
  add_action("east","east");
}

east() { this_player()->move_player("east#room/church.c");
return 1; }
east_exit(){
   call_other(this_player(), "move_player",
      "east#players/trix/closed/guild/guild_room.c");
   return 1;
}
west_exit(){
   call_other(this_player(), "move_player","west#room/new_alley");
  return 1;
}

join_guild(){
   if(this_player()->is_kid()) return 0;
   /* kid prevent and proper check for if currently in a guild added -Bp */
      guild_name=this_player()->query_guild_name();
   if(this_player()->query_guild_exp() || guild_name && guild_name != "undead" && lower_case(guild_name)!="none"){
      write("You are already a member of the "+guild_name+" guild!\n"+
         "If you want to join the undead you must leave that guild.\n");
      return 1; }
   else if(guild_name && guild_name == "undead"){
      write("You are already a member of the Undead!\n");
      return 1;
   }
   else if(this_player()->query_level()<3){
      notify_fail("You must be at least level three to join a guild.\n"+
            "Please try again when you are at least level 3.\n");
      return 0;
   }
   else{
        int prob;
      write("Welcome to the undead!\n");
      this_player()->set_guild_name("undead");
      guild_exp=this_player()->query_guild_exp();
      this_player()->add_guild_exp(-guild_exp);
      guild_rank=this_player()->query_guild_rank();
      this_player()->add_guild_rank(-guild_rank);
      guild_channel_mess(this_player()->query_name()+" has joined the guild!");
                move_object(clone_object("/players/hurtbrain/life.c"),this_player());
      this_player()->add_guild_rank(1);
      write("You now have a guild object.\n"+
         "Type: 'com' to get a list of commands.\n");
      write("Hurtbrain, Trix & Gorgan hope you enjoy the guild.\n");
      return 1;
   }
}
query_drop_castle() {
   return 1;
}
guild_channel_mess(str){
   object *us;
   int x;
   us=users();
   for(x=0;x<sizeof(us);x++){
      if(present("soul-undead",us[x])){
         tell_object(us[x],"[*UNDEAD*]: "+str+"\n");
       }
   }
   return 1;
}
int rank, lev, xlev;
int rank_exp, lev_exp, g_exp, exp;
int cost, available;
g_exp_list(str){
   rank_exp=allocate(8);
   rank_exp[0] = 0;
   rank_exp[1] = 5000;
   rank_exp[2] = 15000;
   rank_exp[3] = 35000;
   rank_exp[4] = 75000;
   rank_exp[5] = 155000;
   rank_exp[6] = 315000;
   rank_exp[7] = 635000;
   return rank_exp[str];
}
evaluate(){
   object tp;
   tp = this_player();
   rank = tp->query_guild_rank();
   g_exp = tp->query_guild_exp();
   lev = tp->query_level();
   if(lev>19) lev=19;
   xlev = tp->query_extra_level();
   if(xlev>19) xlev = 19;
   rank_exp = g_exp_list(rank);
   exp = tp->query_exp();
   if(lev > 18&&xlev>0) lev_exp = call_other("/room/exlv_guild","get_next_exp",xlev-1);
   else lev_exp = call_other("/room/adv_guild","get_next_exp",lev-1);
   cost = rank_exp - g_exp;
   available = exp - lev_exp;
   return 1;
}
guild_advance(){
   object th;
   string name;
   th=this_player();
   name = th->query_name();
   if(this_player()->is_kid()) return 0;
   if(!present("soul-undead",this_player())){
      write("You are not a member of the Undead guild!\n");
      return 1;
   }
   if(this_player()->query_guild_rank()>=8)
    {
	write("You are already at the highest guild level!\n");
	return 1;
    }
   evaluate();
   if(cost > available){
      write("You don't have enough experience available to raise your guild rank.\n");
      return 1;
   }
   th->add_exp(-cost);
   th->add_guild_exp(cost);
   write(cost+"\n");
   th->add_guild_rank(1);
   rank = rank +1;
   write("Well done "+name+"!  You are now guild rank "+rank+".\n");
   guild_channel_mess(name+" has just advanced in the guild!\n");
   return 1;
}
advancement_cost(){
   int x;
   int y;
   x=0;
   write("Here is a list of the amount of guild experience you must\n"+
      "have for each of the levels in the guild:\n\n"+
      "	rank	guild exp\n"+
      "	-----------------\n");
   while(x<8){
      y=x+1;
      write("\t"+y+".\t");
      write(g_exp_list(x)+"\n");
      x++;
   }
   write("	-----------------\n");
   return 1;
}
