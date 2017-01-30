#define fuck clone_object("/players/dragnar/mons/ninja.c");
#define shit move_object(ninja, this_object());
inherit "room/room";
int x;
object ninja;
init() {
   ::init();
   add_action("search","search");
   this_player()->set_fight_area();
}
reset(arg) {
   ninja=fuck
   shit
	ninja=fuck
	shit
	ninja=fuck
	shit
	ninja=fuck
	shit
	ninja=fuck
	shit
	ninja=fuck
	shit
	ninja=fuck
	shit
   if(arg) return;
   set_light(1);
	set_heart_beat(1);
   short_desc=("Dark forest");
   long_desc=
   "Here you can see the ruined forest strech for miles in frount of\n"+
   "you, but your way is blocked by a huge gorge.  There used to be a\n"+
   "type of bridge here but the remains lie at the bottom of the gorge.\n"+
   "You can see what looks like a skeleton laying next to the ruins.\n",
   items=
   ({"bridge","As you look down at the bridge you see something seems to\n"+
         "be written on it.  It says 'DEATH' in huge letters and seems to be\n"+
         "written in blood.  You realize chaos rules this land",
         "skeleton","Most likely the remains of the owner that had his blood written\n"+
         "on the bridge",
	"shadows","It looks like a ninja is hiding in the darkness",
	"shadow","It looks like a ninja is hiding in the darkness",
    });
   dest_dir=
   ({
         "players/dragnar/rooms/forest2.c","south",
    });
}
