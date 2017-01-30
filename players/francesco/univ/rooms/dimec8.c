#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("tecnico4")) {
  move_object(clone_object("/players/francesco/univ/mob/tecnico4.c"),
	this_object());  }

set_light(1);

short_desc = "Mechanical tests laboratory" ;
long_desc =
     "   Typical instrumentations for a mechanical tests lab are present\n"+
     "here:  a hardness tester, two universal tensile test machines, a set\n"+
     "of many fatigue test benchtables,  a Charpy pendulum,  and several\n"+
     "general purposes tools are in this room.  They are perfectly clean\n"+
     "and set to any kind of tests.  Some are working as well under the\n"+
     "supervision of a technician.  Some students walk in and out carrying\n"+
     "with themselves the specimens to be tested.\n",
items = ({
   "tester","It can be used to measure both the Brinell and the Vickers hardness of materials",
   "machines","They can determine the yield strength and the rupture strength of materials",
   "benchtables","Fatigue tests are performed with these machines under cyclic loads",
   "pendulum","It applies dynamic forces in order to determine the impact strenght of materials",
 

});

dest_dir = ({
   
   "/players/francesco/univ/rooms/dimec9.c","east",
   
   
});

}
