init()
{
    add_action("north","north");
    add_action("south","south");
}

north()
{
    call_other(this_player(), "move_player", "north#/players/lew/el_stop");
    return 1;
}


long() {
  write(""+
"This does not seem to be a very good area, there are many large, tall\n"+
"run-down buildings all around you. It might be a good idea to leave.\n"+
  "There is a CTA El Platform off to the north.\n");
}

short(){return "Stateway gardens";}

south(){
  call_other(this_player(), "move_player", "south#/players/lew/37th_state");
   return 1;
}
reset(){
     set_light(1);
}
