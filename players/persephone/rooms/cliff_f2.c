inherit "/players/persephone/closed/thingys.c";
reset(arg){
 if(arg) return;
  set_light(1);
  short_desc="Cliff Path";
  long_desc="You are still travelling along the rough path that provides access\n" +
            "between the base of the cliff and the top of the cliff. The Limestone\n" +
            "here is much smoother here than it is further down cliff. By all \n" +
            "appearences you are two thirds of the way up the cliff face and the\n" +
            "the climb up appears easier than the one down. Far below you still\n" +
            "see large waves pounding against the base of the cliff. While above\n" +
            "you see the beautiful sky.\n";
  dest_dir=({"players/persephone/rooms/clifft","up",
             "players/persephone/rooms/cliff_f1","down",
  });
}
realm(){ return "NT";}
