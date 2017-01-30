/*
  camera_poloroid.c
*/

object who_obj, picture_obj;
string who_str, str;

init() {
  add_action("aim",     "aim");
  add_action("picture", "take");
}

aim(str) {
  if (!str) {
    write("Aim the camera at what?\n");
    return 1;
  }
  sscanf (str, "camera at %s", who_str);
  if (!who_str) {
    write("Use: aim camera at <who>\n");
    return 1;
  }
  if (who_str=="nothing") {
    who_obj=0;
    write("The camera is now aimed at nothing.\n");
    return 1;
  }
  who_obj = present(who_str, environment(this_player()));
  if (!who_obj) {
    write("Sorry, you cannot locate a '"+who_str+"' in the viewfinder.\n");
    tell_room(environment(this_player()),
              this_player()->query_name()+" swivels the camera around.\n");
    return 1;
  }
  tell_room(environment(this_player()),
            this_player()->query_name()+
            " swivels the camera around until it is aimed at "+
            who_obj->query_name()+".\n");
  return 1;
}

picture(str) {
  string picture_str, stuff_str;
  object stuff, next_stuff;
  int others_counter;
  if (!str || str != "picture") return;
  if (!who_obj) {
    write("'"+who_str+"' isn't here to take a picture of!\n");
    return 1;
  }
  if (!present(who_str, environment(this_player()))) {
    write("'"+capitalize(who_str)+"' isn't here to take a picture of!\n");
    return 1;
  }
  picture_str = "This is a poloroid picture of "+who_obj->query_name()+" "+
                "standing in "+lower_case(environment(who_obj)->short())+", ";
  stuff_str = "carrying";
  stuff=first_inventory(who_obj);
  if (stuff) {
    while (stuff) {
      next_stuff=next_inventory(stuff);
      if (stuff->query_name()) stuff_str=stuff_str+" "+stuff->query_name();
      else
      if (stuff->short()) stuff_str=stuff_str+" "+stuff->short();
      if ((stuff->query_name() || stuff->short()) && next_stuff)
        stuff_str=stuff_str+",";
      stuff=next_stuff;
    }
  }
  if (stuff_str=="carrying")
    picture_str = picture_str+" nothing.\n";
  else
    picture_str = picture_str+stuff_str+".\n";
  others_counter=0;
  stuff_str="";
  stuff=first_inventory(environment(this_player()));
  if (stuff) {
    while (stuff) {
      next_stuff=next_inventory(stuff);
      if (stuff->query_name() != this_player()->query_name() &&
          stuff != who_obj) {
        others_counter++;
        if (stuff->query_name()) stuff_str=stuff_str+" "+stuff->query_name();
        else
        if (stuff->short()) stuff_str=stuff_str+" "+stuff->short();
        if (next_stuff) stuff_str=stuff_str+",";
      }
      stuff=next_stuff;
    }
    if (others_counter > 1)
      picture_str = picture_str+"Also in the picture are";
    else
      picture_str = picture_str+"Also in the picture is";
    picture_str = picture_str+stuff_str+".\n";
  }
  picture_obj = clone_object("/players/nooneelse/obj/camera_picture");
  picture_obj->set_short("a picture");
  picture_obj->set_long(picture_str);
  move_object(picture_obj, this_player());
  tell_room(environment(this_player()),
            "Click!\n"+
            this_player()->query_name()+" pushes a button on the camera.\n");
  return 1;
}

short() { return "A poloroid camera"; }

long() {
  write(
    "This is a poloroid camera.\n"+
    "A small label says: Made by Nooneelse's Doodads Inc.\n"+
    "Currently it is aimed at: ");
  if (who_obj)
    write(who_obj->short()+"\n");
  else
    write("...Nothing...\n");
  write("\nYou can 'aim camera at <what>' and 'take picture'.\n");
}

get() { return 1; }

drop() { return; }

query_weight() { return 3; }

query_value() { return 50; }

id(str) { return str=="camera" ||
                 str=="poloroid camera" ||
                 str=="poloroid";
}
