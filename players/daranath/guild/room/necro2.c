#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!present("board")) {
move_object(clone_object("/players/daranath/guild/obj/misc/board.c"),this_object());
}
  if(!arg){
    
    set_light(1);
    short_desc= "Necromancer Stronghold";
    long_desc=
     "The necromancer guild hall main chamber, this room is surrounded\n"+
     "with white marble walls. The guild board is here and there is\n"+
     "a plaque mounted to one wall. Many exits lead from the chamber\n"+
     "while a spiral staircase leads up.\n";

    items=({
     "wall","The red stone walls are the same as elsewhere in the tower",
    });

    dest_dir=({
      "/players/daranath/guild/room/necro5.c","north",
      "/players/daranath/guild/room/necro1.c","south",
      "/players/daranath/guild/room/necro3.c","east",
      "/players/daranath/guild/room/necro4.c","west",
/*
      "/players/daranath/guild/room/necro6.c","up",
      "/players/daranath/guild/room/crypt1.c","crypt",
*/
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("Bits of bone and areas of dried blood are all about the room.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

/*
crypt() {
  ob = clone_object("/players/daranath/guild/room/crypts.c");
  ob->restore_owner("/players/daranath/guild/room/"+tpn);
  ob->set_owner(tpn);
  move_object(tp,ob);
write("You crawl down into your private crypt.\n");
command("look",tp);
return 1; 
}
*/
