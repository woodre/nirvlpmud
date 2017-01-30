#define tp this_player()->query_name()
inherit "room/room";
reset(arg) {
  
  if(!arg) {
  set_light(1);
    short_desc = "Qual'tor Depository";
    long_desc =
    "A small building that has been newly built within the ruins of the city.\n"+
	"Deposits are taken here for citizens who wish to build a domicile within\n"+
	"city limits. Players can deposit, deposit_list and inquire here.\n";
	
  items = ({
   "building","The small building is newly made from wood and stone",
  });

  dest_dir = ({
    "/players/daranath/qualtor/merch_way.c","north",
  });
} }

init() {
  ::init();
    if(!present("depositor",this_player())) 
	  move_object(clone_object("/players/daranath/qualtor/obj/depositor.c"),this_player());
	add_action("search","search");
   add_action("deplist","deposit_list");
}

search() {
 write("Sorry, noone has dropped any coins recently.\n");
 say(tp +" searches the area.\n");
 return 1;
}

exit() {
object dep;
  if(this_player()) if(dep = present("depositor",this_player())) destruct(dep);
}

deplist(){
write("The deposit listing is current under repair....\n"+
      "I hope to have it fixed soon   -Dar\n");
return 1;
}
