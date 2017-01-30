inherit "obj/treasure";
reset(arg){
  if(!arg){
  set_short("The Friendship Bracelet Dispenser");
    set_long("This is Rumplemintz's friendship bracelet dispenser.\n"+
             "Push the button, and Rumplemintz will be here to give\n"+
             "you and your friend each a bracelet.\n");
    set_alias("dispenser");
  }
} 
init(){
  add_action("hit","hit");
  add_action("hit","press");
  add_action("hit","push");
  ::init();
}
hit(arg){
  if(!arg){write("Push what?\n"); return 1;}
  if(arg == "button"){
    if(find_player("rumplemintz")){
      tell_object(find_object("rumplemintz"),
      capitalize(this_player()->query_real_name()+" requests to have a friend.\n");
      write("Rumplemintz will be right with you.\n");
      return 1;
    }
  return 1;
  }
  return 1;
}
get(){return 0;}
