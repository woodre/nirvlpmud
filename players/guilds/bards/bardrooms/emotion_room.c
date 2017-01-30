#include "/players/guilds/bards/def.h"
#define SOCIAL "/players/guilds/bards/socials/social_create.c"
#define APPROVE_FILE "/players/guilds/bards/socials/approved_bards.txt"

inherit "/room/room";

realm() { return "NT"; }

void reset(status arg) {
  ::reset(arg);
  if(arg) return;
  
  set_light(1);
  short_desc=HIM+"The Bardic Emotions Room"+NORM;
 
  long_desc=
"The Emotions room is a round chamber made entirely of white\n"+
"marble; the walls, floor, ceiling, and the single column\n"+
"in the middle of the chamber. The ceiling glows softly,\n"+
"providing illumination.  A archway to the south opens\n"+
"into the Songs room.\n";
  
  items=({"column","A smooth, perfect cylinder of white marble.  If you "+
                   "seek Bard Level 10, grab the column",
          "wall","The walls are perfectly smooth and without blemish",
          "walls","The walls are perfectly smooth and without blemish",
          "floor","A very subtle ringed pattern keeps the floor from being "+
                  "too disorienting",
          "ceiling","The ceiling glows softly, but is otherwise exactly like "+
                    "the walls",
          "archway","A gracefully curved archway leading to the rest of the "+
                    "guild hall",
          "marble","Pure white marble, clearly created with magic"
        });
  
  dest_dir=({"/players/guilds/bards/bardrooms/songs.c","south"});
}

void init() {
  ::init();
  add_action("cmd_touch","grab");
}

status check_for_approval(object play) {
  string *approved;
  approved=explode(read_file(APPROVE_FILE),"\n");
  if(member_array(play->query_real_name(),approved) > -1)
    return 1;
  return 0;
}

status cmd_touch(string str) {
  object gob;
  if(!str || str != "column")
    FAIL("Touch what?\n");
  gob=GOB;
  if(!gob)
    FAIL("You shouldn't even be here.\n");
  if(BLVL>=10)
    FAIL("You have already passed this trial.\n");
  if(BLVL<9)
    FAIL("Only a Master Bard may become a Legendary Bard.\n");
  if((int)TP->query_extra_level()<5)
    FAIL("You must reach the rank of Elder Fighter in the Realms of Magic\n"+
         "before you may become a Legendary Bard.\n");
  if(check_for_approval(TP)) {
    write("Congratulations!  You are now a Legendary Bard!\n");
    GOB->set_bard_level("10");
    return 1;
  }
  write("When you press enter, you will be taken into the emotion\n"+
        "making process.  Be sure to read the directions carefully,\n"+
        "and take care using the proper codes in your emotion, or\n"+
        "You will most likely be asked to redo it.\n"+
        "You can come back at any time and edit your emotion, or\n"+
        "even withdraw it and create a new one.\n");
  write("When your emotion has been approved, you will get mudmail\n"+
        "letting you know.  To be awarded your level, return here\n"+
        "and grab the column again.\n");
  write("<Press Enter to start the process>");
  input_to("start_emotion_trial");
  return 1;
}

start_emotion_trial() {
  object socob;
  socob=present("bard_social_creator",this_player());
  if(!socob) {
    socob=clone_object(SOCIAL);
    move_object(socob,this_player());
  }
  socob->start_create();
}