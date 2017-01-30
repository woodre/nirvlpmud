inherit "room/room";
   string WHAT, ME;
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="The Merchant Guild Entrance";
long_desc="You are the main entrance of the Merchant's guild.\n"+
           "All around you is the hustle and bustle of commerce.\n"+
           "The walls are constructed of polished black marble and\n"+
           "path leading in is of polished crome.  It is strange that on\n"+
   "the outside all is busy because in side you detect no motion.\n"+ 
   "These Merchants are a strange bunch...You should fit right in.\n"+
   "If you wish to join type JOIN here. \n"+
   "If you wish to no longer be one of us..type LEAVE. (Remember:DEATH!!)\n"+
   "If you need help type HELP\n"+
   " If you have lost your watch type REGISTER here.\n";
 
dest_dir=({
  "/players/heroin/closed/guild/main_hall.c", "enter",
});
}
 
}
 
init() {
    ::init();
     add_action("enter", "enter");
    add_action("help_ranks","help");
     add_action("join_guild", "join");
     add_action("leave_guild","leave");
  add_action("get_watch","register");
}
 
/* --- LEAVE --- */
leave_guild() {
   string me, name;
     object guild;
int pgexp, exp, minus, rank, myrank, level, guild_exp, leave_time;
     me = this_player()->query_real_name();
     guild = present("watch", this_player());
 
     if(!guild) {
       write("You are not a member of this Guild.\n");
       return 1;
     }
     rank = guild->query_guild_rank();
     pgexp = this_player()->query_guild_exp();
     this_player()->add_guild_exp(-pgexp);
     this_player()->set_guild_name(0);
     this_player()->set_guild_file(0);
     this_player()->set_title("LOSER");
     myrank = this_player()->query_guild_rank();
     this_player()->add_guild_rank(-myrank);
     write("You are now no longer a member of the Guild.\n");
     write("You are now just a mere mortal..congratulations.\n");
     say(capitalize(me)+" has left the Guild.\n");
     if(this_player()->query_level() < 2000) {
     name = me;
     level = this_player()->query_level();
     guild_exp = guild->query_guild_exp();
     leave_time = ctime(time());
write_file("/players/heroin/closed/guild/PROMOS",
"\n"+name+"("+level+") left the Merchants - "+leave_time+"\n\n");
     }
     exp = this_player()->query_exp();
     minus = exp/6;
     this_player()->add_exp(-minus);
     destruct(guild);
     WHAT = "quit";
   ME = this_player()->query_real_name();
    tell_members();
    this_player()->set_home("/room/church");
     return 1;
}
 
/* --- JOIN --- */
join_guild() {
object ob;
object heroin;
      int myrank, myexp;
     string me;
     me = this_player()->query_real_name();
 
     if(present("merchant", this_player())) {
       write("You are already a member.\n");
       return 1;
     }
     if(restore_object("players/heroin/closed/guild/banned/"+me)) {
     write("You have been banished. You were excommunicated.\n");
       write("You have committed the worst crime against the Merchants\n");
       write("If you wish to re-enter you must petition the Guildmasters.\n");
       return 1;
     }
if(this_player()->query_npc() == 1) {
write_file("players/heroin/closed/guild/CHEAT",
"\n"+this_player()->query_real_name()+" was dested"+
ctime()+"\n\n");
destruct(this_player());
write("GIVE ME A BREAK....");
return 1;
}
     if(this_player()->query_guild_exp() > 0) {
       write("You may only be a member of one guild!\n");
       return 1;
     }
     if(this_player()->query_level() < 6) {
 write("You must be at least 6th level to join this guild.\n");
       return 1;
     }
if(!present("recruit",this_player())) {
write("You must be recruited by a merchant in order to join.\n"+
"You must find Heroin, Unsane, or Micd.\n"+
"Go find one of them, and see if they will recruit you.\n");return 1;}
move_object(clone_object(
    "players/heroin/closed/guild/watch_2.c"), this_player());
ob = present("recruit",this_player());
destruct(ob);
myexp = this_player()->query_guild_exp();
this_player()->add_guild_exp(-myexp);
this_player()->add_guild_exp(1);
myrank = this_player()->query_guild_rank();
this_player()->add_guild_rank(-myrank);
this_player()->add_guild_rank(1);
     this_player()->set_guild_name("Merchant");
     write("You have now joined the Merchants.\n");
     write("You are now a god among men..Respect your new n");
     write("Type 'merhelp dir' for information on your new powers.\n");
     say(capitalize(me)+" has joined the Guild.\n");
 WHAT = "joined";
   ME = this_player()->query_real_name();
write_file("/players/heroin/closed/guild/PROMOS",
"\n"+this_player()->query_real_name()+" joined the Merchants - "+
ctime()+"\n\n");
  tell_members();
     return 1;
}
 
enter() {
  if(present("watch", this_player())) {
  move_object(this_player(), "players/heroin/closed/guild/main_hall.c");
say(capitalize(this_player()->query_real_name())+ " arrives.\n");
     command("look", this_player());
     return 1;
        }
  write("YOU ARE A TRESPASSER! <<<<<ALARM>>>>>\n"+
        "You are escorted back to the entrance.\n"+
        "Dont try again without being a member.\n");
  say(capitalize(this_player()->query_real_name())+" trespassed"+
  "against the Merchants.  ALL OFFENSES WILL BE PUNISHED.\n");
   return 1;
}
 
help_ranks(str) {
  if(str == "ranks") {
  cat("/players/hawkeye/closed/guild/help_ranks");
   return 1;;
}
}
 
tell_members() {
  object ob, guild, merch;
  int i;
  string me;
    ob = users();
   for(i = 0; i < sizeof(ob); i++) {
   guild = present("merch", ob[i]);
   if(guild) {
  tell_object(ob[i],
     "<<{ HEROIN }>> calls out: "+capitalize(ME)+" has "+WHAT+" the Merchants!\n");
   }
  }
  return 1;
}
 
get_watch() {
  object ob, obj, watch;
  ob = this_player();
if(present("watch", ob)) {
write("You already have a Merchant watch\n"); return 1; }
if(ob->query_guild_name() == "merchant") {
   watch = clone_object("players/heroin/closed/guild/watch_2");
   move_object(watch, ob);
 write("Your time piece is returned to you!\n"+
       "Welcome back to the Merchant guild!\n");
   command("mend", ob);
 return 1;
   } else {
 write("You are not a member of this guild!\n");
    return 1;
}
}         
