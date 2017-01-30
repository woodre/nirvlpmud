/*
  ruby_slippers.c
*/

inherit "obj/armor";

object original_room_obj;
int click_count;

init() {
  ::init();

  add_action("click_heels", "click");
}

click_heels(str) {
  object target_room;
  string str1, str2;
  if (!str || (str != "heels" && str != "heels together")) return 0;
  if (worn==0) {
    write("You have to wear the slippers first!\n");
    return 1;
  }
  click_count++;
  write("You hear a quiet 'click' as the heels of "+
        "the slippers tap together.\n");
  say("You hear a quiet 'click' as "+this_player()->query_name()+
      " taps the heels of "+this_player()->query_possessive()+
      " slippers tap together.\n", this_player());
  if (click_count < 3) return 1;
  str1=file_name(environment(this_player()));
  str2=0;
  sscanf(str1, "%s.c", str2);
  if (!str2) str2=str1;
  if (str2=="room/church") {
    target_room=original_room_obj;
  }
  else {
    target_room=find_object("room/church");
    original_room_obj=environment(this_player());
  }
  write("Your surroundings seem to fade for a second, to be replaced\n"+
        "by the main room of the church.\n");
  say("You see "+this_player()->query_name()+"'s form waver for a moment,\n"+
      "then disappear completely.\n", this_player());
  move_object(this_player(), target_room);
  command("look", this_player());
  click_count=0;
  return 1;
}

reset(arg) {
  if (arg) return;
  ::reset(arg);

  set_name("slippers");
  set_ac(1);
  set_weight(2);
  set_value(300);
  set_short("Ruby slippers");
  set_alias("ruby slippers");
  set_long("A pair of deep red ruby slippers.\n");
  set_type("boots");
}

query_save_flag() { return 1; }
