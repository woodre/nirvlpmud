/* 10/11/05 Earwax: Made room land. */

inherit "/players/earwax/housing/land.c";
#define fuck clone_object("/players/dragnar/WasteLands/mons/ninja.c");
#define shit move_object(ninja, this_object());
inherit "room/room";
object ninja;
init() {
   ::init();
   this_player()->set_fight_area();
}
exit() {
  if(this_player())
    this_player()->clear_fight_area();
}
reset(arg) {
   if(!present("assassin_book")){
     move_object(clone_object("/players/guilds/warriors/OBJ/trainer_assassin"), this_object());
}
   if(arg) return;
   set_light(1);
   short_desc=("Dark forest");
   long_desc=
   "Here you can see the ruined forest stretch for miles in front of\n"+
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
         "players/dragnar/WasteLands/rooms/forest2.c","south",
    });

  set_realm_name("Wastelands");
  set_lot_size(2);
  set_cost(105000);
  setup_land();

}
