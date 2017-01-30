#include "/players/feldegast/defines.h"
#define LOG_FILE "/players/feldegast/log/quest.log"
inherit ROOM;

int flag;
object ngana;
int first_time;

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="A tomb-like chamber";
  long_desc=
"     Statues of man-lion warriors stand sentinel along the walls\n"+
"of this tomb-like chamber.  In the center of the room lies Ngana,\n"+
"prince of the village at the edge of the jungle.\n";
  items=({
    "ngana","Ngana lies sleeping on a stone table, his powerful chest\n"+
            "rising up and down steadily",
    "statues","Giant warriors with fierce expressions carved into their\n"+
              "faces and powerful limbs to crush their foes"
  });
  dest_dir=({
    "/players/feldegast/island/path/pyramid","out"
  });
}

init() {
  ::init();
  add_action("wake","wake");
  add_action("wake","awaken");
}

wake(str) {
  if(flag) { write("He's gone!\n"); return 1; }
  if(!str) { write("Wake who?\n"); return 1; }
  if(str != "ngana" && str != "prince") {
    write("Wake who?\n");
    return 1;
  }
  items[1]="He is no longer here";
  write("\n\nYou shake the sleeping prince's shoulders and he slowly\n"+
        "awakens.\n");
  ngana=clone_object("/players/feldegast/island/path/ngana");
  move_object(ngana,this_object());
  long_desc=
"     Statues of man-lion warriors stand sentinel along the walls\n"+
"of this tomb-like chamber.  In the center of this room is an empty\n"+
"stone table that looks like it was recently occupied.\n";

/* Set quest flag. */
  if(this_player()->set_quest("jungle_village"))
    first_time=1;
  else
    first_time=0;
  write_file(LOG_FILE,
  ctime(time())+" "+TPN+" completed the jungle_village quest.\n");
  call_out("script1",1,this_player());
  flag=1;
  return 1;
}

script1(ob) {
  tell_object(ob,
"Ngana stands up and looks around him.\n");
  call_out("script2",1,ob);
}
script2(ob) {
  tell_object(ob,
"Ngana says: Thank you, adventurer.  I was afraid I'd sleep forever\n"+
"            when that evil witch, Takaya cast that curse on me.\n"+
"            Thanks to you, I can now return to my village and live\n"+
"            peacefully.  Also, now that you've destroyed the three\n"+
"            hags, our people can travel through the jungle and\n"+
"            explore these wonderful ruins our ancestors built.\n"+
"            Truly, I can't thank you enough.\n"
  );
  if(first_time)
    call_out("script3",1,ob);
  else
    call_out("script5",2,ob);
}

script3(ob) {
  tell_object(ob,
"Ngana says: As a small token of my gratitude, I'd like you to have\n"+
"            this magical amulet.\n");
  call_out("script4",1,ob);
}

script4(ob) {
  tell_object(ob, "Ngana gives you a scarab.\n");
  move_object(clone_object(ARM_PATH+"scarab.c"), ob);
  ob->add_weight(2);
  call_out("script5",1,ob);
}

script5(ob) {
  tell_object(ob, "Congratulations!  You've solved this quest!\n");
  call_out("script6",1,ob);
}

script6(ob) {
  ngana->move_player("out#players/feldegast/island/hut5");
}

realm() {
  return "NT";
}
