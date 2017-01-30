/*
  bucket.c
*/

string bucket_color, thing, player_name;
object obj, player_obj;
int random_nbr;

id(str) { return str=="bucket";}

short() { return "A bucket of "+bucket_color+" paint"; }

long() {
  write("A bucket of "+bucket_color+" paint.\n"+
        "You may throw it on someone.\n"+
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
      " self in the face with a bucket of "+bucket_color+" paint.\n");
    tell_object(player_obj,
                "You are hit in the face with a bucket of "+bucket_color+
                " paint.  Nice shot!\n");
  }
  else {
    write("A bucket of "+bucket_color+" paint splashes all over "+
          player_name+".\n");
    tell_object(player_obj,
                "You are hit in the face with a bucket of "+bucket_color+
                " paint!\n");
    tell_room(environment(player_obj),
      player_name+" hits "+player_name+" in the face with a bucket of "+
      bucket_color+" paint.\n");
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

set_bucket_color(str) {
  if (str) {
    bucket_color=str;
    return 1;
  }
  random_nbr=random(5);
  if (random_nbr==0) bucket_color="red";
  if (random_nbr==1) bucket_color="yellow";
  if (random_nbr==2) bucket_color="blue";
  if (random_nbr==3) bucket_color="white";
  if (random_nbr==4) bucket_color="black";
  return 1;
}
