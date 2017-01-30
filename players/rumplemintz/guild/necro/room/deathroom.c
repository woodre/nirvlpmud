inherit "room/room";

reset(int arg){
    if(!arg){

	set_light(1);
	short_desc= "Pocket within the Realm of Death";
	long_desc=
	"Dark, swirling mists obscure your view of any tangible surroundings,\n"+
	"enhancing the sense of entrapment you feel. A sense of entrapment\n"+
	"slowly grows within you, as you see no way out.\n";

	items=({
	  "mist","The mist is dark and impenetrable",
	  "exit","There are no exits",
	  "exits","There are no exits",
	});

	dest_dir=({
	});

    }
}

init(){
    ::init();
    add_action("search","search");
}

search(){
    write("You find nothing about the area that gives any hope.\n");
    say(this_player()+" searches the area.\n");
    return 1;
}

realm() { return "NT"; }
