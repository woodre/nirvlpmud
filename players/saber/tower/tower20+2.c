#define tp this_player()->query_name()
inherit "room/room";
string rose_count;
string summon_count;
int i;
reset(int arg){
if(!present("corpse")) {
move_object(clone_object("/players/saber/stuff/corpse3.c"),this_object());
}
if(!present("thunder")) {
move_object(clone_object("/players/saber/effects/thunder3.c"),this_object());  }
 if(!arg){
  set_light(1);
 short_desc="Mountain Flower";
long_desc=
 "You stand in a small, snow covered clearing.  Overhead the\n"+
 "sky is ominously dark.  In the middle of the clearing is a\n"+
 "small mound, upon which grows a single flower.\n";

items=({
 "trail","A thin, icy trail covered with a fresh layer of virgin snow",
 "clearing","A small, snow filled clearing",
 "clouds","Dark, ominous looking storm clouds",
 "mountain","You can't see it because of the clouds",
 "snow","A fresh layer of virgin snow coveres the ground",
"rose","A single, beautiful snow rose.\n"+
     "You feel compelled to 'pick' it",
 "flower","A single, beautiful snow rose.\n"+
       "You feel compelled to 'pick' it",
 "mound","A small, snow covered hill",
 "ground","A fresh layer of virgin snow coveres the ground",
 });

  dest_dir=({
 "/players/saber/tower/tower20+1.c","south",
           });
set_heart_beat(0);
  }   }
init(){
 ::init();
  add_action("search","search");
  add_action("pick","pick");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

pick(str) {
  object ob;
  if(!this_player()) return;
  if(this_player()->is_npc()) return;
if(!str) {
write("Pick what?\n");
return 1; }
if(str == "flower" || str == "rose"){
if (rose_count < 1)  {
write("As you touch the rose it turns to ice and shatters.\n"+
     "You get a bad feeling about this.\n");
say(tp+" reaches down to pick the rose.\n"+
     "The rose turns to ice and shatters.\n"+
     "You get a bad feeling about this.\n");
/* Added by Snow for people who like to pick the rose (and not fight the monsters) 9/29/99 */
write("You feel very cold... so cold you cannot move!\n");
ob = clone_object("/players/saber/tower/frozen.c");
move_object(ob, this_player());
ob->destruct_stun(60);
/* End addition */
rose_count = rose_count + 1;
set_heart_beat(1);
return 1;
}
write("The rose has already been picked.\n");
return 1;
}
}

heart_beat() {
object ob;
summon_count = summon_count + 1;
if(summon_count == 1){
say("There is a booming    * * CRASH * *   of thunder.\n");
return 1;  }
if(summon_count == 2){
say("A low moaning sound can be heard above the wind.\n");
return 1; }
if(summon_count == 3){
say("Yooooooooooooooooooooouuuuuuuuuusssssssssssss.\n");
return 1; }
if(summon_count == 5){
say("An icy shadow begins to solidify.\n");
say("Shadow whispers: Yoooouuuusss haaaveeee freeeedeeed ussssessss moortaaaal.\n");
say("Shadow whispers: Weeeeee thaaaaankssssss yoooooouuuusssss.\n");
return 1; }
if(summon_count == 7 || summon_count == 27 || summon_count == 47 || summon_count == 67 || summon_count == 87 || summon_count == 107) {
say("The shadow has almost reached material form.\n");
return 1; }
if(summon_count == 8 || summon_count == 28 || summon_count == 48 || summon_count == 68 || summon_count == 88) {
write("The shadow reaches material form.\n");
move_object(clone_object("/players/saber/monsters/icewraith.c"),this_object());
return 1; }
if(summon_count == 108)  {
write("The final shadow reaches material form.\n");
move_object(clone_object("/players/saber/monsters/icewraith2.c"),this_object());
return 1; }
if(summon_count == 29 || summon_count == 49 || summon_count == 69 || summon_count == 89 || summon_count == 109) {
say("The shadow reaches material form.\n");
return 1;  }
if(summon_count == 25 || summon_count == 45 || summon_count == 65 || summon_count == 85 || summon_count == 105) {
say("Another icy shadow begins to solidify.\n");
return 1;  }
if(summon_count > 110) {
set_heart_beat(0);
return 1; }

}
