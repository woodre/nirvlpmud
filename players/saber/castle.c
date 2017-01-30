#define tp this_player()->query_name();
#define NAME "Saber"
#define DEST "room/sunalley1"

object ob;

id(str) { return str == "rift"; }

short() {
    return "A Rift in space and time";
}

long() {
  write("A rift of space and time, leading to the legendary\n"+
  "city of Ryllian.  You think that you could 'step' in to it.\n");
}

init() {
  add_action("step", "step");
}
/* Modified to require correct syntax of 'step rift' -forbin 2003.08.18 */
step(str) {
  if(!str || str != "rift") {
  write("Step in to what?\n");
   return 1;
       }
call_other(this_player(), "move_player", "through the rift"+"#"+"/players/saber/ryllian/rift.c");
    return 1;
}

reset(arg) {
    if (arg)
  return;
    move_object(this_object(), DEST);
if(!present("hoopak"))  {
move_object(clone_object("/players/saber/closed/new_mini/kender.c"),this_object());  }
if(!present("medallion"))  {
move_object(clone_object("/players/saber/closed/new_mini/gypsy.c"),this_object());  }
if(!present("scabbard"))  {
move_object(clone_object("/players/saber/closed/new_mini/blade.c"),this_object());  }
if(!present("symbol"))  {
move_object(clone_object("/players/saber/closed/new_mini/larn.c"),this_object());  }
if(!present("ball"))  {
move_object(clone_object("/players/saber/closed/new_mini/feline.c"),this_object());  }
if(!present("collar"))  {
move_object(clone_object("/players/saber/closed/new_mini/canine.c"),this_object());  }
if(!present("choker"))  {
move_object(clone_object("/players/saber/closed/new_mini/succubus.c"),this_object());  
        }
if(!present("attitude"))  {
move_object(clone_object("/players/saber/closed/new_mini/gothic.c"),this_object());  }
if(!present("rings"))  {
move_object(clone_object("/players/saber/closed/master.c"),this_object());  }
if(!present("instrument"))  {
move_object(clone_object("/players/saber/closed/bards/instrument.c"),this_object());  }
/*
if(!present("coat"))  {
move_object(clone_object("/players/saber/closed/bards/coat_of_arms.c"),this_object());  }
*/
if(!present("flu"))  {
move_object(clone_object("/players/saber/closed/virus/flu.c"),this_object());  }


ob = present("flu");
destruct(ob);
ob = present("hoopak");
destruct(ob);
ob = present("medallion");
destruct(ob);
ob = present("symbol");
destruct(ob);
ob = present("ball");
destruct(ob);
ob = present("collar");
destruct(ob);
ob = present("choker");
destruct(ob);
ob = present("scabbard");
destruct(ob);
ob = present("attitude");
destruct(ob);
ob = present("rings");
destruct(ob);
ob = present("instrument");
destruct(ob);
clone_object("/players/saber/closed/old_bard/instrument.c");
}
is_castle(){return 1;}
