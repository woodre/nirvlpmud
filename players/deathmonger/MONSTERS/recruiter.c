
inherit "/obj/monster";
string whostr;
object who;

reset(){
    set_name("assassin");
    set_short("Dark Assassin");
    set_long("The Guild of Assassins has reopened and is currently\n"+
      "engaged in a membership drive.  Perhaps this dark figure is\n"+
      "not a recruiter.  Maybe you shouldn't ask him to 'join' if you\n"+
      "are interested in the guild.\n");
    set_hp(10000);
    set_ac(1000);
   set_level(50);
    set_wc(20);
    ::reset();
}

catch_tell(str){
    string trash, garbage;
     if(sscanf(str, "%sjoin%s", trash, garbage)==2){
     if(sscanf(str, "%s says:%s", trash, garbage)==2){
     whostr = trash;
     call_out("start_join", 3);
      }
     }
     if(sscanf(str, "%syes%s", trash, garbage)){
     join2();
   return 1;
}
}

start_join(){
   string whoname;
   whoname = lower_case(whostr);
   who = present(lower_case(whoname), environment(this_object()));
   if(!who) return 1;
   tell_object(who,
   "Dark Assassin whispers to you: Why yes, we *are* looking for some \n"+
   "fresh talent for our guild...\n");
   tell_object(who,
   "Would you be interested in an apprenticeship?\n");
    return 1;
}

join2(){
   int quest;
    object lic;
    if(who->query_guild_exp() > 0 || present("license", who)){
         tell_object(who,
    "You are already a member of another guild.\n"+
    "You have to quit that guild before becoming an assassin.\n");
          return 1;
       }
     if(who->query_guild_exp() == 1234){
        write("You have been banished from all guilds.  Including this one.\n");
       return 1;
      }
        if(!who->query_pl_k()){
         tell_object(who,
         "What's the point of being an assassin if you don't have\n"+
         "your player killing set?  You need to set your player killing\n"+
         "before becoming an assassin.\n");
        return 1;
       }
       if(present("license", who)){
          tell_object(who,
          "Duh! You are already an assassin! Double duh!\n");
          return 1;
      }
      quest = 1;
       lic = clone_object("/players/deathmonger/ASSASSIN/license");
       move_object(lic, who);
       who->add_guild_exp(1);
      lic->set_guild_exp(1);
      lic->set_guild_quest(quest);
      lic->set_guild_name();
       write_file("/players/deathmonger/ASSASSIN/JOIN",
                who->query_name() + "\n");
         tell_object(who,
       "You have been issued a license to kill by the Guild of Assassins.\n"+
       "Type 'license' for a list of abilities.\n");
}
