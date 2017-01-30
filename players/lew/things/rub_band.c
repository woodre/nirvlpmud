
inherit "obj/treasure";
int pull;
drop(){return 1;}
reset(arg){
  if(!arg){
    set_id("band");
}
}
init(){
  ::init();
    add_action("snap"); add_xverb("");
}
snap(){
    if(pull != 10) pull=pull+1;
    if(pull == 10) {
      move_object(this_player(), "/room/church");
      write("SNAP!!!\n");
      pull = 0;
      return 1;
    }
}
