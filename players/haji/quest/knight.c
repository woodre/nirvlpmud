#include "std.h"

object knight;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
  if(!knight || !living(knight)) {
    knight = clone_object("obj/monster");
    call_other(knight,"set_name","knight");
    call_other(knight,"set_short","A knight who says `Ni!!!!'");
    call_other(knight,"set_ac",17);
    call_other(knight,"set_level",16);
    call_other(knight,"set_al",50);
    call_other(knight,"set_wc",16);
    call_other(knight,"set_aggressive",0);
    move_object(knight,this_object());
    call_other(knight,"set_object",this_object());
    call_other(knight,"set_function","gives");
    call_other(knight,"set_type","gives");
    call_other(knight,"set_match"," ");
    call_other(knight,"set_chat_chance",25);
    call_other(knight,"load_chat","The knight says:Bring me a shrubbery!!!!\n");
    call_other(knight,"load_chat","You cringe in terror\n as the Knight says:Ni!!!\n");
  }
}

notify(str) {
  say(str);
  write(str);
}

gives(str) {
  string who,what,whom;
  object obj, next_obj,dude;
  int found;

  if(sscanf(str,"%s gives %s to %s.\n",who,what,whom) != 3)
    return;
  if(whom != "Knight")
    return;
  if(what == "shrubbery") {
    obj = first_inventory(knight);
    if(!call_other(obj,"id","shrubbery")) {
      notify("Knight says: This isn't what I want,Ni!!!!.\n");
      notify("The Knight gives "+what+" to "+who+".\n");
      transfer(obj,find_living(lower_case(who)));
      return;
    }
    if(call_other(obj,"query_value") != 50) {
      notify("Knight says: This isn't the right shrubbery.\n");
      notify("Knight says: You shoudn't try to fool me "+who+".\n");
      destruct(obj);
      return;
    }
    notify("Knight says: Well done you have brought me the shrubbery.\n");
    notify("Knight says: You may now continue on with the quest.\n");
    destruct(obj);

    dude=clone_object("players/haji/quest/gar.c");
    move_object(dude,environment(this_player()));
    say("pick up the branch so that you may proceed.\n");
    write("pick up the branch so u may proceed.\n");
    return 1;


   }
}

TWO_EXIT("players/haji/quest/lev19.c", "south",
         "players/haji/quest/lev20.c","north",
         "A deep forest",
          "You are in a deep forest you feel\n" +
         "presence about you.\n",1)



      

