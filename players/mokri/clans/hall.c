#include "defs.h"
#define NEW_COST 500000
inherit "/players/vertebraker/closed/std/room.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Hall of Clans");
   set_long("You stand in a vast, almost empty room.\n"+
      "There is a sign here.\n");
   add_item("sign","From here, you may create a new clan.\n"+
      "Clans offer a channel to talk on, a who list, a customizable\n"+
      "spell, and an expandable clan hall, among other things.\n"+
      "To create a clan, type 'create_clan [name]', where '[name]' is\n"+
      "the name you would like for the clan.\n"+
      "NOTE: Clan names follow the same rules as player names. No spaces,\n"+
      "      non-letter characters, or capital letters.\n\n"+
      "      Bear in mind that we are not held responsible lost property belonging\n"+
      "      to clan names containing vulgar, crude, or hateful language.\n"+
      "      Such clans may be deleted without warning, no reimbursements,\n"+
      "      and no questions asked. Use common judgement when choosing names.\n"+
      "The cost is " + NEW_COST + " coins, payable directly from your bank account.\n");
   add_exit("/players/mokri/stuff/paintball/shack","west");
}

init()
{
   ::init();
   add_action("create_clan","create_clan");
   add_action("readsign","read");
}

int readsign(string str)
{
   if(str != "sign") return 0;
   write("From here, you may create a new clan.\n"+
      "Clans offer a channel to talk on, a who list, a customizable\n"+
      "spell, and an expandable clan hall, among other things.\n"+
      "To create a clan, type 'create_clan [name]', where '[name]' is\n"+
      "the name you would like for the clan.\n"+
      "NOTE: Clan names follow the same rules as player names. No spaces,\n"+
      "      non-letter characters, or capital letters.\n\n"+
      "      Bear in mind that we are not held responsible lost property belonging\n"+
      "      to clan names containing vulgar, crude, or hateful language.\n"+
      "      Such clans may be deleted without warning, no reimbursements,\n"+
      "      and no questions asked. Use common judgement when choosing names.\n"+

      "The cost is " + NEW_COST + " coins, payable directly from your bank account.\n");
   return 1;
}

int create_clan(string str)
{
   object obj;
   
   if(TP->query_clan_name() || C_OBJ)
      {
      write("You are already in a clan!\n");
      return 1;
   }
   
   if(TP->query_bank_balance() < NEW_COST)
      {
      write("You are too poor! You must have " + NEW_COST + " coins in the bank.\n");
      return 1;
   }
   
   if(!str)
      {
      write("Please supply a name for the clan.\n");
      return 1;
   }
   
   if(str == "hall_rooms" || str == "cmds" || str == "obj" || str == "jedi" )
      {
      write("Invalid clan name. Please try again.\n");
      return 1;
   }
   
   if(call_other(TOP_DIR + "funcs","add_clan",str) != 0)
      {
      TP->add_bank_balance(-NEW_COST);
      write("New clan created.\n");
      this_player()->set_clan_name(str);
      obj = clone_object(TOP_DIR + "object");
      obj->set_clan_short("generic clan_object");
      obj->set_clan_long("a generic clan object.\n");
      obj->set_object_name("object");
      obj->set_clan_owner(TP->query_real_name());
      obj->save_me();
      move_object(obj,this_player());
   }
   else
      {
      write("Clan creation failed.\n");
      return 1;
   }
   return 1;
}
