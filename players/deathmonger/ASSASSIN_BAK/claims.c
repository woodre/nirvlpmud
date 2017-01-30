
#include "defs.h"
#define notify_fail(A) write(A+"\n"); return 1;

inherit "room/room";

object broom, froom;
string name;
int reward;

reset(arg){
   object un, sign;
   if(arg) return;
   short_desc = "Undertaker's Room";
   long_desc =
"The undertaker handles bounty claims for the bounty hunters' guild.  He is\n"+
"in charge of body collection and reward distribution.  If you have a scalp\n"+
"of someone on the hitlist, you can 'claim' your reward here.\n";
   if(!present("undertaker", this_object())){
     un = clone_object("players/deathmonger/object");
     un->set_name("undertaker");
     un->set_short("The Undertaker");
     un->set_long("The undertaker is in charge of handling bounty claims.\n");
     move_object(un, this_object());
     }
     set_light(1);
}

init(){
     broom = find_object(APATH+"bounty");
    froom = find_object(APATH+"fame");
   add_action("claim", "claim");
   add_action("hitlist", "hitlist");
}

claim(){
   write("Undertaker says: Bagged one, eh?\n");
   write("What is the wanted player's name? ");
   input_to("claim2");
   return 1;
}

claim2(str){
   object scalp;
   if(!str) return 1;
   name = str;
   if(!broom->member_hitlist(name)){
      write("That person is not on the official hitlist.\n");
      return 1;
   }
   reward = broom->query_bounty(name);
   scalp = present("deathscalp", this_player());
   if(!scalp || scalp->query_who() != name){
write("You need to bring the scalp of your victim so we can verify\n"+
   "your kill.  Come back when you have it.\n");
	  return 1;
   }
   if(scalp->query_who() == this_player()->query_real_name()){
      notify_fail("The bounty hunters' guild has not, is not, and "+
           "will not ever reward suicide.\n");
   }
   write("Ok, here's your reward!\n");
   reward(scalp->query_level(), scalp->query_extra_level());
   broom->remove_hitlist(name);
   froom->add_killer(this_player()->query_real_name(), 
            scalp->query_level(), scalp->query_extra_level());
   destruct(scalp);
   return 1;
}


hitlist(){
   broom->hitlist();
   return 1;
}

reward(int level, int exlevel){
   int exp_rew;
   this_player()->add_money(reward);
   write("The bounty for this person was "+reward+".\n");
   if(present("guild_license", this_player())){
       if(level > 5)
         exp_rew += (level - 2) * 250;
      if(level > 10)
         exp_rew += (level - 5) * 500;
      if(level > 15)
         exp_rew += (level - 10) * 1000;
      if(level > 18){
         write("Congratulations, you bagged a big one!\n");
         exp_rew += (level - 15) * 1500; }
      if(exlevel > 4)
         exp_rew += exlevel * 2000;
   this_player()->add_exp(exp_rew);
   write("You get "+exp_rew+" experience points for this kill.\n");
   }
   return 1;
}  
