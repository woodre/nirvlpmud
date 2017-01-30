/*
File: flowers.c
Author: Feldegast
Date: 2/14/01 Valentine's Day!
Description:
  Flowers
*/
#include "/players/feldegast/defines.h"

inherit "/obj/treasure.c";

string card;

int delivered;

void reset(int arg) {
  if(arg) return;
  set_id("flowers");
  set_alias("bouquet");
  set_short("A "+HIG+"bouquet "+NORM+"of "+HIR+"flowers"+NORM);
  set_long(
    "This is an arrangement of fresh red and pink carnations\n"+
    "wrapped in white lace.\n"
  );
  set_weight(1);
  set_value(50);
  set_save_flag(1);
}

long() {
  ::long();
  if(!card)
    write("You can 'write' a message on the attached card.\n");
  else
    write("There is a card attached that you can read.\n");
  if(!delivered)
    write("You may 'deliver' them to another player.\n");
}

void init() {
  add_action("cmd_write","write");
  add_action("cmd_read","read");
  add_action("cmd_smell", "smell");
  add_action("cmd_deliver", "deliver");
}

int cmd_write(string str) {
  write("Enter a message.  End with **.  Abort with ~q.\n");
  write(">");
  card="";
  input_to("write_it");
  return 1;
}
 
write_it(str) {
  if(str=="**") {
    write("Done.\n");
    return;
  }
  else if(str=="~q") {
    write("Aborted.\n");
    card="";
    return;
  }
  else {
    card+=str+"\n";
    input_to("write_it");
    write(">");
    return;
  }
}

int cmd_read(string str) {
  if(str!="card") {
    notify_fail("Read what?\n");
    return 0;
  }
  write("The card reads:\n"+card);
  say(TPN+" reads the card attached to the flowers.\n");
  return 1;
}

int cmd_smell(string str) {
  if(!id(str)) {
    notify_fail("Smell what?\n");
    return 0;
  }
  write("You inhale the fresh perfume of the flowers.\n");
  say(TPN+" smells the flowers.\n");
  return 1;
}

int cmd_deliver(string str) {
  object target;
  notify_fail("Deliver <who>?\n");
  if(!str) return 0;
  target=find_player(str);
  if(!target) return 0;
  if(target->query_invis()) return 0;
  write("You send the flowers to "+(string)target->query_name()+".\n");
  tell_object(target, "A deliveryman arrives with flowers from "+TPN+".\n");
  move_object(this_object(),target);
  return 1;
}
