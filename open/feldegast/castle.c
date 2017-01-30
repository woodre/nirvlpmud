#define DEST "room/plane12"
#include "/players/feldegast/log/logs.h"

id(str) {
  return str=="shrine";
}

short() {
    return "A Marble Shrine";
}

long() {
    write("This is a small shrine with tall marble pillars on either side of an\n"+
          "open passageway leading inside of it.  You think you could 'enter shrine'.\n");
}

init() {
    add_action("enter"); add_verb("enter");
}

enter(str) {
    if (!id(str))
	return 0;
    else {
      write("You enter the marble shrine.\n");
      this_player()->move_player("in#/players/feldegast/shrine");
#ifdef ENTERLOG
       write_file(LOG_FILE,
ctime(time())+" "+capitalize(this_player()->query_real_name())+" entered the shrine.\n");
#endif
      return 1;
    }
}

reset(arg) {
  object quest;
  if (arg) return;
  move_object(this_object(), DEST);

  /* Load jungle quest */
  if(!present("jungle_quest",find_object("room/quest_room.c"))) {
    quest=clone_object("/obj/quest_obj");
    quest->set_name("jungle_village");
    quest->set_hint("\nYou must cross the jungle and save the Chief Man's son.  But first\n"+
                    "go to the village at the edge of the jungle and ask the storyteller\n"+
                    "for help.\n");
    move_object(quest,"/room/quest_room");
  }

  /* Autoloading objects */
  call_other("/players/feldegast/obj/poison2.c","???");
  call_other("/players/feldegast/std/clothes.c","???");
  call_other("/players/feldegast/closed/tool/bug.c","???");
  call_other("/players/feldegast/obj/prize.c","???");
  call_other("/players/feldegast/crystal/gob.c", "???");
  if(extract(ctime(time()),4,9)=="Feb 14") /* Seasonal Valentine's day dispenser */
    call_other("/players/feldegast/obj/v-day.c","???");
}

is_castle(){ return 1; }
