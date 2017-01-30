/*
  paintball_bazooka.c
*/

inherit "/obj/weapon";

init() {
  ::init();

  add_action("fire",   "fire");
}

fire(str) {
  object target_obj, paint_obj;
  string target_name, bucket_color;
  int random_nbr;
  target_name=0;
  sscanf(str, "bazooka at %s", target_name);
  if (!str || !target_name) return 0;
  target_obj = find_living(target_name);
  if (!target_obj || target_obj==this_player()) {
    write("You look down the barrel of your bazooka and blast yourself "+
          "in the forehead!!!\n");
    say(this_player()->query_name()+
       " looks down the barrel of a bazooka and gets blasted in the forehead\n",
       this_player());
    paint_obj=clone_object("/players/nooneelse/obj/bucket_stuff");
    random_nbr=random(5);
    if (random_nbr==0) bucket_color="red";
    if (random_nbr==1) bucket_color="yellow";
    if (random_nbr==2) bucket_color="blue";
    if (random_nbr==3) bucket_color="green";
    if (random_nbr==4) bucket_color="pink";
    paint_obj->start_bucket_stuff(bucket_color);
    move_object(paint_obj, this_player());
    return 1;
  }
  if (target_obj->query_level() > 20 &&
      this_player()->query_real_name() != "nooneelse") {
    write("Are you nuts???  You think better of it and blast "+
          "yourself instead.\n\n");
    fire("bazooka at "+this_player()->query_real_name());
    return 1;
  }
  paint_obj=clone_object("/players/nooneelse/obj/bucket_stuff");
  random_nbr=random(5);
  if (random_nbr==0) bucket_color="red";
  if (random_nbr==1) bucket_color="yellow";
  if (random_nbr==2) bucket_color="blue";
  if (random_nbr==3) bucket_color="green";
  if (random_nbr==4) bucket_color="pink";
  paint_obj->start_bucket_stuff(bucket_color);
  move_object(paint_obj, target_obj);
  write("Whomp!  You fire the bazooka and proceed to blow "+
        capitalize(target_name)+" away!!!\n"+
        "You hear a yelp of pain as you see the shell strike your target"+
        " on top the head\n"+
        "and "+bucket_color+" paint splashes everywhere.\n");
  tell_room(environment(target_obj),
    "\nWhomp!  A bazooka shell lands on top of "+capitalize(target_name)+
    "'s head\n"+
    " and splashes "+bucket_color+" paint everywhere.\n\n"+
    "As the barrage stops, you can barely make out "+
    this_player()->query_name()+"'s gleeful laughter\n"+
    "and "+capitalize(target_name)+"'s whimpering.\n\n");
  return 1;
}

reset() {
  set_alias("bazooka");
  set_name("paintball bazooka");
  set_short("Paintball bazooka");
  set_long(
  "This is a deadly bazooka!  However, someone has converted it to fire\n"+
  "paintball bombs.\n"+
  "    fire bazooka at <who>     - to shoot other players at a distance\n"+
  "\n  A small label says: Made by Nooneelse's Doodads Inc.\n");
  set_value(200);
  set_class(8);
  set_weight(2);
}
