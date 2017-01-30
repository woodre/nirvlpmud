#define NAME "Mythos"
#define DEST "room/sea"
#define SAVER "/players/mythos/prac/test.c"
#define HOLD "/players/mythos/closed/hold.c"
#include "/players/mythos/closed/guild/def.h"
#include "/players/mythos/closed/dd.h"
int reboot_time;
id(str) { return str == "mist"; }

short() {
    return "Mist to the --east--";
}

long() {
    write("You are still swimming in the sea.\n");
    write("You do see a great wall of mist to the east.\n");
    write("You can go east or west.\n");
}

init() {
  add_action("go_east","east");
  add_action("go_west","west");
}

go_east() {
  this_player()->move_player("east#players/mythos/portal.c");
return 1;
}

go_west() {
  this_player()->move_player("west#room/jetty2.c");
return 1;
}
reset(arg) {
    if (arg)
	return;
	reboot_time = time();
  move_object(this_object(),"/room/vill_green.c");
	move_object(this_object(),HOLD);
	move_object(this_object(), DEST);
	mover();
}
is_castle(){return 1;}

query_reboot() { return reboot_time;}

mover() {
  /* 10/26/07 Earwax: commented these out */
  /*
    clone_object("/players/mythos/closed/guild/obb.c");
    clone_object("/players/mythos/closed/guild/ob.c");
    clone_object("/players/mythos/closed/guild/hunger.c");
    clone_object("/players/mythos/closed/guild/curse.c");
   clone_object("/players/mythos/closed/guild/blood_bind.c");
  */
  /* This is obsolete. LD mud no like. -Bp
  clone_object("/players/mythos/prac/qt.c");
  */
    clone_object("/players/mythos/closed/play/xtell.c");
    clone_object("/players/mythos/closed/play/itell.c");
    clone_object("/players/mythos/closed/play/mtell.c");
/*
  move_object(clone_object("/players/mythos/prac/vending.c"),"/room/vill_green.c");
*/
/* OBSOLETE, same as other qt. -Bp
      clone_object("/players/mythos/closed/play/qt.c");
*/
    clone_object("/players/mythos/closed/play/garble.c");
    clone_object("/players/mythos/closed/play/darker.c");
    clone_object("/players/mythos/prac/dar_cloak.c");
    clone_object("/players/mythos/amisc/tochau.c");
    clone_object("/players/mythos/prac/brooch.c");
     clone_object("/players/mythos/closed/fake_beater.c");
   clone_object("/players/mythos/closed/play/autocheck.c");
    clone_object("/players/mythos/amisc/tsolin.c");
     clone_object("/players/mythos/amisc/forest/dark.c");
    clone_object("/players/mythos/amisc/forest/resur.c");
move_object(clone_object("/players/mythos/closed/play/updates.c"),"/players/mythos/prac/test.c");

  move_object(clone_object("/players/cosmo/jb/jukebox.c"),"/room/pub2.c");
  clone_object("/players/mythos/closed/marry/omring.c");
  clone_object("/players/mythos/closed/play/moo/moo3.c");
  clone_object("/players/mythos/closed/play/moo/MOOO.c");
  move_object(clone_object("/players/mythos/healerguild/obj/block.c"),"/room/exlv_guild.c");
  move_object(clone_object("/players/mythos/healerguild/obj/block.c"),"/room/adv_guild.c");
  clone_object("/players/mythos/healerguild/guildob.c");
    call_other("/players/mythos/healerguild/obj/reinstate_spell", "???");
}
