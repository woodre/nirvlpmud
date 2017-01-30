#include "std.h"
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
extra_init() {
   add_action("pay","pay");
   add_action("kill","kill");
   add_action("spellf","missile");
   add_action("spellf","shock");
   add_action("spellf","fireball");
   add_action("spellf","flare");
   }
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
  extra_reset() {
    object own;
     if(!present("owner")) {
     own=clone_object("obj/monster.c");
       call_other(own,"set_name","owner");
       call_other(own,"set_short","Harem Owner");
       call_other(own,"set_long","This is the Owner of Haji's Harem.\n");
       call_other(own,"set_ac",15);
       call_other(own,"set_wc",15);
       call_other(own,"set_level",2);
       call_other(own,"set_al",50);
       call_other(own,"set_chat_chance",45);
       call_other(own,"load_chat","Owner says:You must pay to enter\n" +
               "and have the time of your life!!!\n");
       move_object(own,this_object());
   }
 }
  ONE_EXIT("players/haji/entrance.c", "west",

    "Harem Entrance",
        "This is the entrance to Haji's Harem.\n" +
        "To enter you must pay the owner of the harem.\n" +
        "To the west you see a clearing,and to the\n" +
        "south you see a curtain.\n",
   1)
  realm(){return "harem";}
pay(str) {
   if (str!="owner") {
     write("You must pay the OWNER.\n");
     return 1;
     }
   call_other(this_player(),"add_money",-1);
   write("The owner opens up the curtain,\n");
   write("and beckons you to go south.\n");
   add_action("south","south");
   return 1;
   }
south() {
 write("You are told to move south into the Harem\n");
 write("Prepare to have the time of your life!!\n");
   call_other(this_player(),"move_player","goes through the curtain#players/haji/harem/main1.c");
 return 1;
 }
kill(str) {
  if(str=="owner"||str=="harem owner") {
    write("You can't do that!!!!\n");
    return 1;
   }
 return 1;
 }
spellf(arg) {
   if(!"owner"||!"harem owner"||!"haremowner") {return 0;}
    write("You really shouldn't do that!!!!\n");
    return 1;
 }
