#include "def.h"

inherit MYROOM;

int there;

reset(arg) {
  if(!present("karl")) 
    move_object(clone_object(PATH+"Npc/unclkarl"));
  if (arg) return;
  set_light(1);
  short_desc="Uncle Karl's Place";
  long_desc=
"     This is a cluttered old apartment behind Neptune's Kingdom.\n"+
"It consists of a series of small rooms filled with countless\n"+
"mementos of days gone by.\n";
  items=({
    "mementos","Too many to enumerate"
  });
  dest_dir=({
    PATH+"aquarium","west"
  });
  there=1;
}   

init() {
  ::init();
  add_action("cmd_search","search");
}

cmd_search() {
  if(!there) {
    write("You find nothing of interest.\n");
    return 1;
  }
  write("You find a dog-eared drawing book written by a child.\n");
  {
    object book;
    book=clone_object("/obj/treasure");
    book->set_id("book");
    book->set_short("A crude book");
    book->set_weight(1);
    book->set_value(10);
    book->set_read(
"The pages of the book are completely, utterly, definitely blank.\n");
    book->set_long(
"This book is made out of colorful sheets of paper bound together by\n"+
"some yarn.  Ancient wads of hardened chewing gum dot the edges.  The\n"+
"cover reads: Guide to Shell Beach by Johnny Murdoch Age 9.\n");
    move_object(book,this_player());
    this_player()->add_weight(1);
    there=0;
  }
  return 1;
}

