inherit "obj/treasure";
int lucky,waylucky;
reset(arg){
  if(arg){return;}
  set_weight(10000);
}

id(str){return (str == "statue");}
short(){return "A very peculiar looking statue";}
lone(){write("A statue like none you've ever seen before.\n"+
             "It appears as a culmination of several beasts and\n"+
             "creatures of the likes you've never glanced upon.\n"+
             "You can make out a horse with a rider, and what\n"+
             "appears to be an orc.  The statue seems a bit dusty\n"+
             "for all the traffic that passes by here.\n");}
init(){
  add_action("search","search");
  add_action("open","open");
  add_action("enter","enter");
}
search(str){
  if(str=="statue"){
    write("After wiping the dust off of the statue, and poking a bit,\n"+
          "you begin to make out a crack on one side, and hinges on\n"+
          "the other.\n");
    say(capitalize(this_player()->query_name())+" searches around the statue.\n");
    lucky = this_player();
    return 1;
  }
}
open(str){
  if(str=="statue"){
    if(lucky==this_player())
      write("You open the statue, and you discover that it's hollow inside.\n");
      say(capitalize(this_player()->query_name())+" opens the statue!\n");
      waylucky=this_player();
      return(1);
    }
  write("What?\n");
  return 1;
}
enter(){
  if(waylucky==this_player()){
    write("You hop into the statue, and notice there's no floor!\n"+
          "After falling a ways, you hit a dirt floor.\n");
    this_player()->move_player("enter#"+"room/church");
    return(1);
  }
  write("What?");
  return 1;
}
