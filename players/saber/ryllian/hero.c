#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
short_desc="Tower of Heros";
long_desc=
"You stand in the fabled Hall of the Hero.  Once long ago this tower was\n"+
"dedicated to preserving the images of the mightiest warriors of the realm.\n"+
"Its noble spirit shines forth no longer, for rumor has it that the tower\n"+
"has fallen under control of the Necromancer Su Slith.  All creatures now\n"+
"found within the tower are the twisted spirits of once mighty heros and\n"+
"villains.\n";

items=({
 "tower","You stand in the Tower of the Hero",
 "ground","The ground is constructed from dark stone",
 });

  dest_dir=({
 "/players/saber/ryllian/ryll12.c","out",
 "/players/saber/ryllian/hero1.c","north",
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
