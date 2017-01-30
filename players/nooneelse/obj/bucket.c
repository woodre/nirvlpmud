/*
  bucket.c
*/

#include "/players/nooneelse/color.h"

string thing, player_name, bucket_color;
object obj, player_obj;
int random_nbr;

id(str) { return str=="bucket";}
short() {
  if (bucket_color=="red") return "A bucket of "+RED+" paint"+END;
  if (bucket_color=="yellow") return "A bucket of "+YELLOW+" paint"+END;
  if (bucket_color=="blue") return "A bucket of "+BLUE+" paint"+END;
  if (bucket_color=="green") return "A bucket of "+GREEN+" paint"+END;
  if (bucket_color=="purple") return "A bucket of "+PURPLE+" paint"+END;
}
long() {
  write("A bucket of ");
  if (bucket_color=="red") write(RED+" paint"+END);
  if (bucket_color=="yellow") write(YELLOW+" paint"+END);
  if (bucket_color=="blue") write(BLUE+" paint"+END);
  if (bucket_color=="green") write(GREEN+" paint"+END);
  if (bucket_color=="purple") write(PURPLE+" paint"+END);
  write("\nYou may throw it on someone.\n"+
        "Use:   throw paint on <player>\n\n"+
        "A small label says: Made by Nooneelse's Doodads Inc.\n");
}
get() { return 1;}

init() {
  if (!bucket_color) set_bucket_color();
  add_action("throw", "throw");
}

throw(str) {
  object bucket_stuff_obj;
  if (!str || sscanf(str, "%s on %s", thing, player_name) != 2) return;
  if (thing != "paint") return;
  player_obj=present(lower_case(player_name), environment(this_player()));
  player_name=capitalize(player_name);
  if (!player_obj) {
    write("But, "+player_name+" isn't here!\n");
    return 1;
  }
  if (lower_case(player_name)=="nooneelse") {
  /* try to hit me with my own bucket? i don't think so :) */
    player_name=this_player()->query_name();
    player_obj=this_player();
    tell_room(environment(player_obj),
      player_name+" hits "+player_obj->query_objective()+
      " self in the face with a bucket of ");
    if (bucket_color=="red")
      tell_room(environment(player_obj), RED+" paint"+END+"\n");
    if (bucket_color=="yellow")
      tell_room(environment(player_obj), YELLOW+" paint"+END+"\n");
    if (bucket_color=="blue")
      tell_room(environment(player_obj), BLUE+" paint"+END+"\n");
    if (bucket_color=="green")
      tell_room(environment(player_obj), GREEN+" paint"+END+"\n");
    if (bucket_color=="purple")
      tell_room(environment(player_obj), PURPLE+" paint"+END+"\n");
    tell_object(player_obj,
                "You are hit in the face with a bucket of ");
    if (bucket_color=="red")
      tell_object(player_obj, RED+" paint"+END+"\n");
    if (bucket_color=="yellow")
      tell_object(player_obj, YELLOW+" paint"+END+"\n");
    if (bucket_color=="blue")
      tell_object(player_obj, BLUE+" paint"+END+"\n");
    if (bucket_color=="green")
      tell_object(player_obj, GREEN+" paint"+END+"\n");
    if (bucket_color=="purple")
      tell_object(player_obj, PURPLE+" paint"+END+"\n");
    tell_object(player_obj, ".  Nice shot!\n");
  }
  else {
    write("A bucket of ");
    if (bucket_color=="red") write(RED+" paint"+END+"\n");
    if (bucket_color=="yellow") write(YELLOW+" paint"+END+"\n");
    if (bucket_color=="blue") write(BLUE+" paint"+END+"\n");
    if (bucket_color=="green") write(GREEN+" paint"+END+"\n");
    if (bucket_color=="purple") write(PURPLE+" paint"+END+"\n");
    write(" splashes all over "+player_name+".\n");
    tell_object(player_obj,
                "You are hit in the face with a bucket of ");
    if (bucket_color=="red")
      tell_object(player_obj, RED+" paint"+END+"\n");
    if (bucket_color=="yellow")
      tell_object(player_obj, YELLOW+" paint"+END+"\n");
    if (bucket_color=="blue")
      tell_object(player_obj, BLUE+" paint"+END+"\n");
    if (bucket_color=="green")
      tell_object(player_obj, GREEN+" paint"+END+"\n");
    if (bucket_color=="purple")
      tell_object(player_obj, PURPLE+" paint"+END+"\n");
    tell_room(environment(player_obj),
      this_player()->query_name()+" hits "+player_name+
      " in the face with a bucket of ");
    if (bucket_color=="red")
      tell_room(environment(player_obj), RED+" paint"+END+"\n");
    if (bucket_color=="yellow")
      tell_room(environment(player_obj), YELLOW+" paint"+END+"\n");
    if (bucket_color=="blue")
      tell_room(environment(player_obj), BLUE+" paint"+END+"\n");
    if (bucket_color=="green")
      tell_room(environment(player_obj), GREEN+" paint"+END+"\n");
    if (bucket_color=="purple")
      tell_room(environment(player_obj), PURPLE+" paint"+END+"\n");
    write("OK.   You hit 'em.\n");
  }
  bucket_stuff_obj=clone_object("/players/nooneelse/obj/bucket_stuff");
  move_object(bucket_stuff_obj, player_obj);
  bucket_stuff_obj->start_bucket_stuff(bucket_color);
  obj = first_inventory(player_obj);
  while(obj) {
    bucket_stuff_obj=clone_object("/players/nooneelse/obj/bucket_stuff");
    move_object(bucket_stuff_obj, obj);
    bucket_stuff_obj->start_bucket_stuff(bucket_color);
    obj = next_inventory(obj);
  }
  destruct(this_object());
  return 1;
}

set_bucket_color(arg) {
  if (arg) {
    bucket_color=arg;
    return 1;
  }
  random_nbr=random(5);
  if (random_nbr==0) bucket_color="red";
  if (random_nbr==1) bucket_color="yellow";
  if (random_nbr==2) bucket_color="blue";
  if (random_nbr==3) bucket_color="green";
  if (random_nbr==4) bucket_color="purple";
  return 1;
}
