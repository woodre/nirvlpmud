inherit "room/room";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int teleport, clone;

reset(arg){

	teleport = 0;  if(random(TFL_TLP)) teleport = 1;

	 if(!present("guard")){   clone = random(3);   switch(clone){
		 case 0: case 1:  break;
 case 2:  MO(CO("/players/zeus/realm/NPC/gguard.c"), TO); break; return 1; }}

   if(arg) return;
 short_desc="The Fallen Lands";
 long_desc=
"The path is very clearly defined here, and on each side the trees\n"+
"are so thick that deviance from it is impossible.  Amongst the\n"+
"trees are a wide variety of plants, including some very healthy\n"+
"bushes.  The trees are blocking nearly all of the light.\n";
 set_light(1);
 items=({
	"path",
"The path is very dry here, and some faint footprints are visible\n"+
"in it.  It is slightly covered by leaves and pine needles",
	"footprints",
"The large footprints are very faint, but still noticeable.  They look\n"+
"like the prints of a large creature, not a person",
	"leaves",
"The leaves scattered over the path take on many different colors.\n"+
"Some of them are all green, while others have soft patches of red in them",
	"pine needles",
"There are many small pine needles scattered across the dirt path",
	"plants",
"There are a lot of curious looking plants growing here.  There is not much\n"+
"light here, but they seem to grow very well despite this",
	"bushes",
"The bushes are very full and healthy.  Some of them have small, plump red\n"+
"berries on them which almost look good enough to eat",
	"berries",
"The red berries are small and plump.  Some of them are oozing a sticky\n"+
"yellowish liquid, others are encrusted with it",
	"trees",
"The very tall pine and evergreen trees are blocking out nearly all the\n"+
"light here with their criss crossing braches",
   "branches",
"The branches of the trees are creating a canopy above you, which makes the\n"+
"path feel more like a tunnel than anything else",
   "canopy",
"The canopy of branches is blocking out nearly all of the sky",
   "sky",
"The soft blue sky is barely visible through the canopy of branches",
   "thorns",
"The bushes with the red berries growing on them also have very sharp thorns\n"+
"which stick out inches from the bush itself",
 });
 dest_dir=({
"/players/zeus/realm/taus/road2.c", "north",
"/players/zeus/realm/city/path21.c", "south",
 });
}

init(){
  ::init();
  add_action("n_dir", "n");
  add_action("n_dir2", "n");
  add_action("s_dir", "s");
  add_action("pick_cmd", "pick");
}

exit(){    if(TP) TP->clear_fight_area();     }
okay_follow(){ return 1; }
realm(){   if(teleport) return "NT";    }

status pick_cmd(string str)
{
object berry;
 if(!str) return 0;
 if(TP->query_al() < -100)
 {
   write("As you try to pick a berry you cut yourself on a thorn.\n");
   say(TP->QN+" cuts "+TP->OBJ+"self on a thorn.\n");
   TP->add_hp(-15);
  return 1; 
 }
 if(!TP->add_weight(1))
 {
	write("You can't carry anymore!\n");
  return 1; 
 }
 else 
 {
	 write("You pick a red berry from the bush.\n");
	 say(TP->QN+" picks a berry from the bush.\n");
     berry = CO("/players/zeus/realm/OBJ/berry.c");
	 MO(berry, TP);
	 return 1;
 }
return 1; 
}


status n_dir2()
{
	if(present("guard"))
	{
		write("The guard watches you closely.\n");
		say("The guard watches "+TP->QN+" closely.\n");
	}
}

