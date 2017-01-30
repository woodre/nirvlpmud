#define tp this_player()->query_name()
inherit "room/room";
int i;
reset(int arg){
 if(!arg){
  set_light(1);
 short_desc="Mountain Climb";
long_desc=
 "You are half way up the icy wall.  Looking down, you\n"+
 "sincerely hope that you do not 'fall' off of the mountain wall.\n";

items=({
 "clouds","Dark, ominous looking storm clouds",
 "mountain","A mountain peak, far to the west",
 "peak","A mountain peak, far to the west",
 "plain","The icy mountain plane seems very far beneath you",
 "down","The icy mountain plane seems very far beneath you",
 "ice","Large chunks of frozen ice",
 "wall","Large, towering walls which dissapear up into the clouds",
 "walls","Large, towering walls which dissapear up into the clouds",
 "ground","The ground is covered with great chunks of frozen ice",
 });

  dest_dir=({
 "/players/saber/tower/tower20+8.c","up",
 "/players/saber/tower/tower20+7.c","down",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
  add_action("fall","fall");
}

search() {
  write("You find nothing.\n");
say (tp +" searches the area\n");
 return 1;  }

fall() {
object ob;
string gender;
  write("Oh sh*t!  You loose your grip and fall off the mountain wall!\n"+
   "\n\n"+
    "This could be very painful...\n\n"+
    "The ground rushes up to meet you.\n\n"+
     "This could be very painful...\n\n\n"+
      "                 S  P  L  A  T\n"+
  "\n\n\n"+
     "It is.\n\n\n");
ob = this_player();
gender = "its";
if(this_player()->query_gender() == "female"){gender = "her";}
if(this_player()->query_gender() == "male"){gender = "his";}
 say(tp+" looses "+gender+" grip and falls off the face of the mountain wall.\n"+
     "You hear "+tp+" screaming for a long time before you hear\n"+
    "the sickening thud of meat impacting upon VERY solid ice...\n");

ob->hit_player(random(40)+22);
call_other(this_player(),"move_player","down#players/saber/tower/tower20+7.c");
 return 1; }
