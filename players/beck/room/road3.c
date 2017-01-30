/* A road used in an ancient D&D like setting */
inherit "/room/room";
object ob;
reset(arg){
   if(arg) return;
   set_light(1);
   short_desc=("A dark road");
   long_desc=
   "This narrow road is made only of dirt and gravel.\n"+
   "The trees on either side are so thick that very little\n"+
   "light is cast around.  Small thickets of thorn bushes cover\n"+
   "the forest floor all around, making it difficult to travel\n"+
   "off the road, but providing excellent hiding places for...\n"+
   "",
   items=
   ({
         "trees","Various species of hardwood trees as well as some hemlock's\n"+
         "seem to thrive in this grove",
         "road","A road made of dirt and gravel, probally a long time ago",
         "dirt","Just a plain soil/sand mixture",
         "gravel","Crushed rocks",
         "thickets","Small areas where thick bushes are located",
         "bushes","Plants with sharp thorns and some foliage",
         "forest","A thick forest, dark within",
    });
   dest_dir=
   ({
         "players/beck/room/crossroads.c","east",
         "room/plane1.c","west",
    });
}

init(){
   ::init();
  if(!this_player()) return; /* v */
   if(!present("thief",this_object())){
      if(this_player()->query_money() > 40000 && random(20) < 2){
      tell_room(this_object(), "\nA man jumps out into the road in front of you pointing a knife.\n"+
      "He says: Give me your money now!\n"+
      "");
         ob = clone_object("/players/beck/monster/thief.c");
         move_object(ob, this_object());
         ob->set_wealthy(this_player()->query_real_name());
      }
   }
}
thief_message(){
         tell_room(environment(), "\nA man jumps out into the road in front of you pointing a knife.\n"+
            "He says: Give me your money now!\n"+
            "");
}
realm(){ return "NT"; }
