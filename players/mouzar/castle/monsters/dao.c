 
inherit "obj/monster.c";
object weapon, ring;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("dao");
set_alias("genie");
set_short("A big muscular genie");
set_long("He is bald and squat.  He has a beard and a moustache which are well groomed.\n"+  
         "The moustache is sculpted in to a ridiculous point.  His ears are pointy and\n"+
         "he has finger nails that will make any woman jealous.  He is a Dao genie\n");
set_al(0);
set_level(18);
set_wc(26);
set_ac(15);
set_hp(450);
set_aggressive(0);
if(!present("nose ring")) {
weapon = clone_object("players/mouzar/castle/armor/daonring.c");
move_object(weapon,this_object());
}
if(!present("ringring")) {
ring = clone_object("players/mouzar/castle/armor/daoring.c");
move_object(ring,this_object());
}
}
 
