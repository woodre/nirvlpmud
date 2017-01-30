#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(arg){
 if(!arg){
  set_light(1);
 short_desc="Orin's Hearth- Ruin";
long_desc=
 "Even this room- the once quiet lounge of the Inn was not spared\n"+
 "the dradful razing and destruction.  All things of value- ornaments,\n"+
 "pictures,even the magical firelog- have been ransacked.\n";

  dest_dir=({
 "/players/saber/ryllian/orin_ruin2.c","west",
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
