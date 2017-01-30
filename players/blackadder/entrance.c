#include "room.h"
object baldric;
object doormat;
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
FOUR_EXIT("/players/blackadder/workroom","east",
   "/players/blackadder/study","west",
   "/players/blackadder/hall1","north",
   "/room/south/sshore6","leave",
   "The entrance hall",
   "Blackadders magnificent entrance hall.\n" +
   "The hall is quite grandiose and is decorated in a baroque\n" +
   "style which is quite strikingly beautiful and yet completely\n" +
   "tasteless at the same time.  A sign on the wall reads:\n" +
   "    Welcome to my nightmare!!!\n" ,1)
extra_reset() {
   object money;
   if (!doormat) {
      doormat = clone_object("/players/blackadder/doormat");
      move_object(doormat,this_object());
   }
   if (!baldric || !living(baldric)) {
      baldric = clone_object("obj/monster.c");
      call_other(baldric,"set_name","baldric");
      call_other(baldric,"set_alias","manservant");
      call_other(baldric,"set_short","Baldric");
      call_other(baldric,"set_long","This is Baldric, Blackadders manservant.\n");
      call_other(baldric,"set_ac",5);
      call_other(baldric,"set_level",5);
      call_other(baldric,"set_hp",75);
      call_other(baldric,"set_wc",5);
      money = clone_object("obj/money");
      call_other(money, "set_money", random(500));
      move_object(money,baldric);
      call_other(baldric,"set_chat_chance",10);
      call_other(baldric,"set_a_chat_chance",33);
      call_other(baldric,"load_chat","Baldric says: Have you seen my dream turnip?\n");
      call_other(baldric,"load_chat","Baldric says: Wipe your feet.\n");
      call_other(baldric,"load_a_chat","You wound me deeply\n");
      call_other(baldric,"load_a_chat","I only work here!!!!\n");
      move_object(baldric,this_object());
      call_other(baldric,"set_object",this_object());
      call_other(baldric,"set_function","gives");
      call_other(baldric,"set_type","gives");
      call_other(baldric,"set_match"," ");
   }
}
extra_init() {
   add_action("search","search");
}
search() {
   write("You find nothing special.\n");
   return 1;
}
gives(str) {
   string who,what,whom;
   object tr;
   object pl;
   object ob;
   if (sscanf(str,"%s gives %s to %s.\n", who, what, whom) != 3)
      return;
   if (whom != "Baldric" && whom != "baldric")
      return;
   ob = present("turnip",baldric);
   if (!ob || !call_other(ob, "id", "turnip")) {
      say("Baldric says: Thank you!\n");
      return;
   }
   say("Baldric says: Oh!!  My Dream Turnip!!!  Sniff!\n");
   destruct(ob);
   say("Baldric reaches in his pocket and gives a trump to " + who + ".\n");
   tr = clone_object("/players/blackadder/trumps/tub");
   pl = find_player(lower_case(who));
   transfer(tr,pl);
}
