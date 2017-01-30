#include "/players/feldegast/log/logs.h"
#include "/players/feldegast/defines.h"
inherit ROOM;

  int tear1,tear2;
reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="Pyramid";
  long_desc=
"     The steps lead up to a terrace near the top of the pyramid.\n"+
"A huge stone door here is the only way in or out of it.  The statue\n"+
"of a large adult lion stands here as sentinel against intruders.\n";
  items=({
    "pyramid","A huge construct of stone and mortar",
    "jungle","A dark place where few streaks of light penetrate the canopy",
    "door","Ancient hieroglyphs depict a lion with two tears in its eyes",
    "lion","This statue is a masterpiece of stonework.  It almost appears that\n"+
           "the lion is about to cry, but there aren't any tears",
    "statue","This statue is a masterpiece of stonework.  It almost appears that\n"+
        "the lion is about to cry, but there aren't any tears"
  });
  dest_dir=({
    "/players/feldegast/island/path/path7","down"
  });
}

init() {
  ::init();
  add_action("place","place");
  add_action("place","apply");
  add_action("place","fasten");
  add_action("enter","enter");
  add_action("open","open");
  add_action("push","push");
}
open(str) {
  if(!str) { write("Open what?\n"); return 1;}
  if(str=="door") {
    write("There aren't any handles or edges for you to open it with.\n");
    return 1;
  }
  write("Open what?\n");
  return 1;
}
push(str) {
  if(!str) { write("Push what?\n"); return 1; }
  if(str=="door") {
    write("The door remains closed.\n");
    return 1;
  }
  write("Push what?\n");
  return 1;
}
place(str) {
  if(!str) {write("Place what?\n");return 1;}
  if(str!="tear") { write("Place what?\n"); return 1; }
  if(present("marble_lion_tear",this_player())) {
#ifdef PATHLOG
    write_file(PATHLOG,ctime(time())+" "+TPN+" placed the fountain tear.\n");
#endif
    destruct(present("marble_lion_tear",this_player()));
    write("You place the tear in the statue's left eye.\n");
    tear1=1;
    call_out("open_sesame",1);
    return 1;
  }
  if(present("crystal_lion_tear",this_player())) {
    destruct(present("crystal_lion_tear",this_player()));
    write("You place the tear in the lion's right eye.\n");
    tear2=1;
    call_out("open_sesame",1);
#ifdef PATHLOG
    write_file(PATHLOG,ctime(time())+" "+TPRN+" placed the statue tear.\n");
#endif
    return 1;
  }
}
open_sesame() {
  if(tear1&&tear2) {
    tell_room(this_object(),
"The huge stone door slowly slides open, allowing entrance into the pyramid.\n"
    );
    dest_dir=({
      "/players/feldegast/island/path/finale","enter",
      "/players/feldegast/island/path/path7","down"
    });
  }
}
enter(str) {
  if(tear1&&tear2) {
    this_player()->move_player("in#players/feldegast/island/path/finale");
    return 1;
  }
}
realm() {
  return "NT";
}
