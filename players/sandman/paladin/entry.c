
/*
 * PALADIN GUILD ENTRY (05/03/94)
 * This room is accesible by all players.
 * They can leave or get more info about the guild
 */

#define BANISH_MASTER "/players/sandman/paladin/banish_master"

/* the paladin advancement guild */
#define PALGUILD "/players/sandman/paladin/adv_guild"

/* directory for log files */
#define LOGPATH "/players/sandman/paladin/log/"

/* directory where help files are located */
#define HELPDIR "/players/sandman/paladin/helpdir/"

/* define this to log joinings and departures */
#define LOG_MEMBERS

/* minimum level reguired to join the paladins */
#define MIN_LEVEL 5

/* minimum alignment required to join the guild */
#define MIN_ALIGN 0

reset(arg) {
   if(!arg)
     set_light(1);
}

short() { return "The entry to the Paladins Guild"; }

long() {
   write("You are in the entry to the Paladins Guild.\n");
   write("A giant arched doorway leads into the Grand Hall of the\n");
   write("Paladins Guild. Above the entrance is a shield perched\n");
   write("below two crossed swords. If you are interested in joining\n");
   write("look over the help files <info> and then find a paladin to\n");
   write("recruit you.\n");
   write("COMMANDS:  leave, info, rejoin\n");
   write("There are three obvious exits: north, south and east\n");
}

init() {
   add_action("north","north");
   add_action("south","south");
   add_action("east","east");
   add_action("info","info");
   add_action("leave","leave");
   add_action("rejoin","rejoin");
}

south() {
   this_player()->move_player("south#players/molasar/rowan/w_twn_sq");
   return 1;
}
east() {
   this_player()->move_player("east#room/eastroad1");
   return 1;
}

north() {
   if(!present("guild_medal", this_player()) &&
                     this_player()->query_level() < 21) {
     write("That area is for Paladins only.\n");
     return 1;
   }
   this_player()->move_player("north#players/sandman/paladin/hall1");
   return 1;
}

info(str) {
   if(!str) {
     cat(HELPDIR+"info");
     return 1;
   }
   if(!cat(HELPDIR+str)) 
     return 0;
   return 1;
}

rejoin() {
   object medal;
   string *banished_tmp;
   
   banished_tmp = BANISH_MASTER->query_banished();
   if(member_array(this_player()->query_real_name(), banished_tmp) != -1) {
     write("You have been banished from the Paladins Guild.\n");
     return 1;
   }
   if(!restore_object("players/sandman/paladin/members/"+
                                   this_player()->query_real_name())) {
     write("You have no guild file! If this is incorrect mail "+
           "Molasar and Sandman.\n");
     return 1;
   }
   if(!present("guild_medal", this_player())) {
     medal = clone_object("players/sandman/paladin/medal");
     medal->restore_medal();
     move_object(medal, this_player());
   } else {
     medal = present("guild_medal", this_player());
     medal->restore_medal();
   }
   return 1;
}

join() {
   object medal;
   string *banished_tmp;
   
   if(this_player()->query_npc() || this_player()->is_kid())
     return 0;
   banished_tmp = BANISH_MASTER->query_banished();
   if(member_array(this_player()->query_real_name(), banished_tmp) != -1) {
     write("You have been banished from the Paladins Guild.\n");
     return 1;
   }
   if(this_player()->query_guild_exp() > 0) {
     write("Your player file has guild experience which means you\n");
     write("are a member of another guild.\n");
     write("If this is incorrect mail Molasar.\n");
     return 1;
   }
   if(this_player()->query_level() < MIN_LEVEL) {
     write("The minimum level to join the Paladins is "+MIN_LEVEL+".\n");
     return 1;
   }
   if(this_player()->query_alignment() < MIN_ALIGN) {
     write("You are too evil for the Paladins Guild.\n");
     return 1;
   }
   medal = clone_object("players/sandman/paladin/medal");
   move_object(medal, this_player());
   medal->save_medal();
   write("Congratulations on joining the Paladins.\n");
   write("Type 'medal' to see the help files.\n\n");
   PALGUILD->correct_level(this_player());
   write("Reseting level.........\n");
   write("You are now level "+this_player()->query_level()+"\n");
   this_player()->add_guild_exp(1);
#ifdef LOG_MEMBERS   
   write_file(LOGPATH+"join",capitalize(this_player()->query_real_name())+
      " joined => "+ctime(time())+"\n");
#endif
   return 1;
}

leave() {
   object medal;
   int exp;

   medal = present("guild_medal", this_player());
   if(!medal) {
     write("You are not a Paladin.\n");
     return 1;
   }
   if(this_player()->query_level() < 20) {
     write("If you leave the Paladins you will lose 1/2 your experience.\n");
     write("Do you still wish to leave? (yes/no): ");
     input_to("verify_leave");
   }
   return 1;
}

verify_leave(str) {
   int exp, gexp;

   if(!str || (str != "yes" && str != "no")) {
     write("Do you wish to leave the Paladins? (yes/no): ");
     input_to("verify_leave");
     return 1;
   }
   if(str == "yes") {
     write("Very well...removing 1/2 your experience....\n");
     exp = this_player()->query_exp();
     exp = exp/2;
     gexp = this_player()->query_guild_exp();
     this_player()->add_guild_exp(-gexp);
    this_player()->set_guild_name(0);
     this_player()->add_exp(-exp);
     write("You lost "+exp+" experience points.\n");
   write("Correcting your level.....\n");
     call_other("/room/adv_guild", "correct_level", this_player());
     write("Your level is now: "+this_player()->query_level()+"\n");
     rm("/players/sandman/paladin/members/"+
                          this_player()->query_real_name()+".o");
     destruct(present("guild_medal", this_player()));
#ifdef LOG_MEMBERS     
     write_file(LOGPATH+"left",capitalize(this_player()->query_real_name())+
        " removed 1/2 exp ["+exp+"] => "+ctime(time())+"\n");
#endif
     return 1;
   }
   if(str == "no") {
     write("A wise choice on your part.\n");
     return 1;
   }
   write("Do you wish to leave the Paladins? (yes/no): ");
   input_to("verify_leave");
   return 1;
}
