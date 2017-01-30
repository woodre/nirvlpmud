#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_no_clean(1);
  set_light(1);
 short_desc="Spine of the Moon";
long_desc=
 "You are traveling within the mountains of the Spine of the Moon.  Above\n"+
 "you loom massive crags and towers of dark stone, dimly illuminated by\n"+
 "the light of the moon.  To the east is the beginning of the Valley of\n"+
 "Stone, while a small clearing lies to the west.\n";

items=({
 "stars","Softly gleaming stars are visible overhead",
 "mountain","Massive crags of towering rock loom over you",
 "mountains","Massive crags of towering rock loom over you",
 "crags","Massive crags of towering rock loom over you",
 "stone","Massive crags of towreing rock loom over you",
 "valley","To the east is the beginning of the Valley of Stone",
 "clearing","A clearing lies to the west",
 });

  dest_dir=({
 "/players/saber/closed/bards/bardrooms/valley_q.c","west",
 "/players/saber/ryllian/mountain_quest.c","east",
 "/players/saber/ryllian/ayre.c","up",
 "/players/saber/ryllian/mountain1.c","down",
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
