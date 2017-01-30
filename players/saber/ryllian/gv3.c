#define tp this_player()->query_name()
inherit "room/room";
object light;
int t;
reset(int arg){
if(!present("gypsy"))  {
move_object(clone_object("/players/saber/closed/new_mini/agents/gypsy.c"),this_object());  }
 if(!arg){
  set_light(1);
 short_desc="Valley End";
long_desc=
 "You have reached the end of the green valley, where the surrounding\n"+
 "mountains of the Spine of the Moon have come together to form a\n"+
 "natural cul-de-sac.\n";

items=({
 "mountain", "The valley is sheltered by tall, snow covered mountains",
 "moon","A distant crescent moon",
 "ground","The valley floor is covered with lush green grass",
 "stars","Softly gleaming stars are visible overhead",
 "valley","A luscious green valley with a pleasantly warm climate",
 "walls","The valley is sheltered by tall, snow covered mountains",
 });

  dest_dir=({
 "/players/saber/ryllian/gv2.c","east",
 "/players/saber/closed/bard/bardrooms/gypsy_q.c","south",
      });
  }   }
init(){
 ::init();
  add_action("search","search");
   add_action("in","in");
  add_action("south","south");
}

search() {
  write("You find a small cave to the north\n"+
       "Perhaps you could go 'in' to it\n");
say (tp +" searches the area\n");
 return 1;  }

in() {
   call_other(this_player(),"move_player","in#players/saber/ryllian/cave.c");
 say(tp+" enters a small cave\n");
return 1;  }

south()  {
object ob;
  ob = present("instrument",this_player());

if(!present("instrument",this_player()))  {
  write("You are not a bard.  You may not go south.\n");
  return 1;
        }

if((this_player()->query_level()) < 10)  {
  write("You are not high enough level to go south.\n");
  return 1;
        }

 if(ob->query_bard_level() !=4)  {
  write("You must be bard level 4 to go south.\n");
  return 1;
        }

call_other(this_player(),"move_player","south#players/saber/closed/bards/bardrooms/gypsy_q.c");
  return 1;
         }
