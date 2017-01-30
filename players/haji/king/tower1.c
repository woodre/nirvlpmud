#include "std.h"
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
extra_init() {
   add_action("read","read");
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
     if(!present("seer")) {
     own=clone_object("obj/monster.c");
       call_other(own,"set_name","seer");
       call_other(own,"set_short","The King's Seer");
       call_other(own,"set_long","You see before you the king's seer.\n");
       call_other(own,"set_ac",15);
       call_other(own,"set_wc",15);
       call_other(own,"set_level",2);
       call_other(own,"set_al",50);
       call_other(own,"set_chat_chance",45);
      call_other(own,"load_chat","Seer says:Tell me what to read my crystal ball on!!!\n");
       move_object(own,this_object());
   }
 }
  TWO_EXIT("players/haji/king/towent.c", "down",
           "players/haji/king/tower2.c", "up",

    "The Seer's Room",
      "This is the seer's room,before you you see\n" +
      "an old man lowered over a crystal ball.\n" +
      "He appears to be saying something you might\n" +
      "want to listen to what he has to say.\n",1)
  realm(){return "harem";}
read(str) {
    string r,o,m;
       object ob;
      sscanf(str,"%s %s",o,m);
      if(o!="on") {
         write("The seer stands up and says:You must read ON something.\n");
         return 1;
      }
      if(m==0) {
       write("The seer stands up and says:You must read on SOMETHING.\n");
       return 1;
       }
    ob=find_living(m);
      if(ob==0) {
       write("The seer stands up and says:Nothing by that name is currently alive.\n");
      return 1;
      }
    if ((ob->query_level())>30) {
        write("You cannot read the ball on creatures of that high a level.\n");
       return 1;
       }
if(this_player()->query_level()<21) {
  write("The seer's crystal ball explodes and he runs to the corner to cry.\n");
  return 1;
}
    write("The seer looks up and says:The creature you are referring to has stats of:\n");
    write("Name:\t" + call_other(ob,"query_name",0)+"\n");
    write("Level:\t" + call_other(ob,"query_level",0)+"\n");
    write("AC:\t" + (call_other(ob,"query_ac",0)*100/9+random(10))+"%\n");
    write("WC:\t" + (call_other(ob,"query_wc",0)*100/18+random(10))+"%\n");
/*
    write("Max HP:\t" + call_other(ob,"query_mhp",0)+"\n");
*/
    return 1;
  }
kill(str) {
  if(str=="seer"||str=="the king's seer") {
   write("You can't do that!!!!\n");
   return 1;
  }
 return 1;
 }
spellf(str) {
    if(str=="seer"||str=="the king's seer") {
     write("You can't do that!!!!\n");
     return 1;
     }
  return 1;
  }
