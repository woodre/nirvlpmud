
#define RANK 40
#define MASTER "sandman"

query_auto_load() { return "players/sandman/masons/guildstone:"; }

id(str) { return str == "stone" || str == "guildstone"; }

get() { return 1; }

drop() { return 1; }


query_value() { return 0; }

short() { return "A guildstone"; }

long() {
   write("The Guildmaster's personal stone.\n"+
         "\n"+
         "banish <player>          -- banishes a player from the guild\n"+
         "callin loan <member>     -- calls in the loan of <member>\n"+
         "expell <member>          -- expells <member> from the Guild\n"+
         "gexp <member> <amt>      -- adds <amt> guild exp to <member>\n"+
         "gloan <member> <amt>     -- sets guild loan to <amt> on <member>\n"+
         "glog <topic>             -- Shows log file for <topic>\n"+
         "gpromote <member> <rank> -- promotes <member> to rank <rank>\n"+
         "initiate <player>        -- initiates <player> into the Guild\n");
   write("quest <player>           -- Finds which guild quests solved.\n");
   write("setquest <player> <quest>-- Set guild quest to player.\n");
}

init() {
   add_action("gpromote","gpromote");
   add_action("log","glog");
   add_action("quest","quest");
   add_action("set_quest","setquest");
   add_action("gexp","gexp");
   add_action("initiate","initiate");
   add_action("banish","banish");
   add_action("callin","callin");
   add_action("gloan","gloan");
   add_action("expell","expell");
   add_action("pgexp","pgexp");
}

quest(str) {
   string who, quests;
   object seal;
   if(!str || sscanf(str, "%s", who) != 1) {
     write("Useage:  quest <player>\n");
     return 1;
   }
   if(!find_player(who)) {
     write(capitalize(who)+" is not on.\n");
     return 1;
   }
   seal = present("seal", find_player(who));
   if(!seal) {
     write(capitalize(who)+" is not a member.\n");
     return 1;
   }
   quests = seal->query_quest();
   write("Quests done: "+quests+"\n");
   return 1;
}

set_quest(str) {
   string quest, who;
   object seal;

   if(!str || sscanf(str, "%s %s", who, quest) != 2) {
     write("Useage:  setquest <player> <quest>\n");
     return 1;
   }
   if(!find_player(who)) {
     write(capitalize(who)+" is not on.\n");
     return 1;
   }
   seal = present("seal", find_player(who));
   if(!seal) {
     write(capitalize(who)+" is not a guildmember.\n");
     return 1;
   }
   seal->set_quest(quest);
   write(capitalize(quest)+" quest set on "+capitalize(who)+".\n");
   return 1;
}

pgexp(str) {
   string who;
   int amt;

   if(!str) {
     write("Useage: pgexp <player> / <amt>\n");
     return 1;
   }
   if(sscanf(str, "%s %d", who, amt) == 2) {
     if(!find_player(who)) {
       write(capitalize(who)+" is not on.\n");
       return 1;
     }
     find_player(who)->add_guild_exp(amt);
     write("You gave "+capitalize(who)+" "+amt+" player-guild exp pts.\n");
     return 1;
   }
   if(sscanf(str, "%s", who) == 1) {
     if(!find_player(who)) {
       write(capitalize(who)+" is not on.\n");
       return 1;
     }
     amt = find_player(who)->query_guild_exp();
     write(capitalize(who)+" has "+amt+" player-guild exp points.\n");
     return 1;
   }
   write("Useage:  pgexp <player> / <amt>\n");
   return 1;
}

log(str) {
   if(str == "advance") {
     return call_other("/closed/wiz_soul","more","/open/GUILDLOGS/ADVANCE");
   }
   if(str == "donate") {
     return call_other("/closed/wiz_soul","more","/open/GUILDLOGS/DONATE");
   }
   if(str == "gstone") {
     return call_other("/closed/wiz_soul","more","/open/GUILDLOGS/GSTONE");
   }
   if(str == "loans") {
     return call_other("/closed/wiz_soul","more","/open/GUILDLOGS/LOANS");
   }
   if(str == "recruit") {
     return call_other("/closed/wiz_soul","more","/open/GUILDLOGS/RECRUIT");
   }
   write("TOPICS:  advance, donate, gstone, loans, recruit\n");
   return 1;
}

string name, banished_by;

callin(str) {
   string who;
   object ob, dest;

   if(!str || sscanf(str, "loan %s", who) != 1) {
     write("Useage:  callin loan <member>\n");
     return 1;
   }
   if(!find_player(who)) {
     write(capitalize(who)+" is not on.\n");
     return 1;
   }
   ob = present("seal", find_player(who));
   if(!ob) {
     write(capitalize(who)+" is not a member!\n");
     return 1;
   }
   if(find_player(who)->query_money() < 1000) {
     write("The person must have over 1000 gold coins.\n");
     return 1;
   }
   dest = environment(find_player(who));
   move_object(find_player(who), "/players/sandman/masons/guild_lodge");
   command("repay", find_player(who));
   move_object(find_player(who), dest);
   tell_object(find_player(who),
       "Your loan has been called in by "+
       capitalize(this_player()->query_real_name())+".\n");
   write("The loan has been called in on "+capitalize(who)+".\n");
   write_file("/open/GUILDLOGS/GSTONE",
        capitalize(this_player()->query_real_name())+" called in "+
        capitalize(who)+"'s loan : "+ctime(time())+"\n");
   return 1;
}

banish(str) {
   string who;

   if(!str || sscanf(str, "%s", who) != 1) {
     write("Useage:  banish <player>\n");
     return 1;
   }
   banished_by = this_player()->query_real_name();
   name = who;
   save_object("players/sandman/masons/BANISHED/"+who);
   write(capitalize(who)+" has been banished from the Guild.\n");
   write_file("/open/GUILDLOGS/GSTONE",
        capitalize(this_player()->query_real_name())+" banished "+
        capitalize(who)+" from the Guild : "+ctime(time())+"\n");
   return 1;
}

gpromote(str) {
   string who;
   object ob, ob1;
   int rank;

   if(!str || sscanf(str, "%s %d", who, rank) != 2) {
     write("Useage:  gpromote <member> <rank>\n");
     return 1;
   }
   if(!find_player(who)) {
     write(capitalize(who)+" is not on.\n");
     return 1;
   }
   ob = present("seal", find_player(who));
   ob1 = present("seal", this_player());
   if(!ob) {
     write(capitalize(who)+" is not a member!\n");
     return 1;
   }
   if(rank >= ob1->query_guild_rank() && this_player()->query_real_name()
           != MASTER) {
     write("You cannot promote someone equal to or above your rank.\n");
     return 1;
   }
   ob->set_guild_rank(rank);
   write("You promoted "+capitalize(who)+" to rank "+rank+".\n");
   tell_object(find_player(who),
       capitalize(this_player()->query_name())+" promoted you to rank "+
       rank+".\n");
   write_file("/open/GUILDLOGS/GSTONE",
        capitalize(this_player()->query_real_name())+" promoted "+
        capitalize(who)+" to rank "+rank+" : "+ctime(time())+"\n");
   return 1;
}

gexp(str) {
   string who;
   object ob;
   int amt, old_gexp;

   if(!str || sscanf(str, "%s %d", who, amt) != 2) {
     write("Useage:  gexp <member> <amt>\n");
     return 1;
   }
   if(!find_player(who)) {
     write(capitalize(who)+" is not on.\n");
     return 1;
   }
   ob = present("seal", find_player(who));
   if(!ob) {
     write(capitalize(who)+" is not a member.\n");
     return 1;
   }
   old_gexp = ob->query_guild_exp();
   ob->set_guild_exp(amt+old_gexp);
   write("You gave "+capitalize(who)+" "+amt+" guild experience points.\n");
   tell_object(find_player(who),
       capitalize(this_player()->query_name())+" has given you "+amt+
       " guild experience points.\n");
   write_file("/open/GUILDLOGS/GSTONE",
        capitalize(this_player()->query_real_name())+" gave "+
        capitalize(who)+" "+amt+" guild exp : "+ctime(time())+"\n");
   return 1;
}

gloan(str) {
   string who;
   object ob;
   int amt;

   if(!str || sscanf(str, "%s %d", who, amt) != 2) {
     write("Useage:  gloan <member> <amt>\n");
     return 1;
   }
   if(!find_player(who)) {
     write(capitalize(who)+" is not on.\n");
     return 1;
   }
   ob = present("seal", find_player(who));
   if(!ob) {
     write(capitalize(who)+" is not a member!\n");
     return 1;
   }
   ob->set_guild_loan(amt);
   write("You set "+capitalize(who)+"'s guild loan to "+amt+".\n");
   tell_object(find_player(who),
       capitalize(this_player()->query_name())+" has set your guild loan "+
       "to "+amt+".\n");
   write_file("/open/GUILDLOGS/GSTONE",
        capitalize(this_player()->query_real_name())+" set "+capitalize(who)+
        "'s guild loan to "+amt+" : "+ctime(time())+"\n");
   return 1;
}

expell(str) {
   string who;
   object ob;
   int pgexp;

   if(!str || sscanf(str, "%s", who) != 1) {
     write("Useage:  expell <member>\n");
     return 1;
   }
   if(!find_player(who)) {
     write(capitalize(who)+" is not on.\n");
     return 1;
   }
   ob = present("seal", find_player(who));
   if(!ob) {
     write(capitalize(who)+" is not a member!\n");
     return 1;
   }
   destruct(ob);
   pgexp = find_player(who)->query_guild_exp();
   find_player(who)->add_guild_exp(-pgexp);
   write("You have expelled "+capitalize(who)+" from the Guild.\n");
   tell_object(find_player(who),
       capitalize(this_player()->query_name())+" has expelled you from "+
       "the Guild.\n");
   write_file("/open/GUILDLOGS/GSTONE",
        capitalize(this_player()->query_real_name())+" expelled "+
        capitalize(who)+" from the Guild : "+ctime(time())+"\n");
   return 1;
}

initiate(str) {
   object seal, ob;
   string who;
   
   if(!str || sscanf(str, "%s", who) != 1) {
     write("Useage:  initiate <person>\n");
     return 1;
   }
   if(!find_player(who)) {
     write(capitalize(who)+" is not on.\n");
     return 1;
   }
   ob = present("seal", find_player(who));
   if(ob) {
     write(capitalize(who)+" is already a member!\n");
     return 1;
   }
   if(find_player(who)->query_guild_exp() > 0) {
     write(capitalize(who)+" is a member of another guild.\n");
     return 1;
   }
   seal = clone_object("players/sandman/masons/seal");
   move_object(seal, find_player(who));
   write("You have initiated "+capitalize(who)+" into the Guild.\n");
   tell_object(find_player(who),
       "You have been rcruited into the Guild.\nType 'seal' for info on "+
       "your new abilities.\n");
   write_file("/open/GUILDLOGS/GSTONE",
        capitalize(this_player()->query_real_name())+" initiated "+
        capitalize(who)+" into the Guild : "+ctime(time())+"\n");
   return 1;
}

