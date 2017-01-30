#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
   short_desc="Arena Foyer";
long_desc=
 "You stand in the foyer of the arena, a dwarf amidst the towering columns\n"+
 "and arches.  To the east is the City of Ryllian, while to the west is a set\n"+
 "of massive iron bound double doors leading to the pit where the gladiators\n"+
 "duel.  You wonder if you are allowed in there...\n";

items=({
 "arena","An imposing looking structure of colossal proportions",
 "foyer","The foyer of the arena",
 "columns","Large columns which support the arena",
 "ground","The floor is constructed from dark stone",
 "door","Massive iron bound double doors leading to the gladiator pit",
 "pit","The arena where the gladiators duel",
 });

  dest_dir=({
 "/players/saber/ryllian/ryllian2.c","east",
 "/players/saber/ryllian/arena1.c","in",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }
