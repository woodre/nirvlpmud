/* Complete recode of treasury_entrance.c to use room/room - Rumplemintz */
#pragma strong_types

inherit "room/room";

object listener, thief;
#if 0
int trig, trig2;
string plrnam;
#endif

mixed
got_rings() {
  return (present("trlock1", this_player()) && 
          present("trlock2", this_player()) &&
          present("trlock3", this_player()));
}

#if 0
void
activate() {
  set_heart_beat(1);
  trig = 3;
  if (!listener || !living(listener)) {
    listener = clone_object("players/angmar/o/catch_password.c");
    listener->set_room("players/angmar/castle/treasury");
    listener->set_call("catch_it");
    move_object(listener,this_object());
  }
}
#endif

void
reset(status arg) {
  if ((!thief || !living(thief)) &&
      "players/angmar/castle/treasury"->query_door()) {
    object stiletto;
    thief = clone_object("obj/monster");
    thief->set_name("thief");
    thief->set_level(14);
    thief->set_hp(180 + random(80));
    thief->set_wc(18);
    thief->set_ac(11);
    thief->set_gender("male");
    thief->set_short("A suspicious looking thief");
    thief->set_long("He seems to be doing something with the doors.\n");
    thief->set_a_chat_chance(50);
    thief->load_a_chat("Thief says: Noooo!  I got here first!\n");
    thief->load_a_chat("Thief says: Get lost!  This is my treasure!\n");
    thief->load_a_chat("Thief says: It's mine it's mine it's mine1\n");
    stiletto = clone_object("obj/weapon");
    stiletto->set_name("stiletto");
    stiletto->set_short("A stiletto");
    stiletto->set_long("Ouch! Looks nasty!\n");
    stiletto->set_class(13);
    stiletto->set_weight(1);
    stiletto->set_value(700);
    move_object(stiletto, thief);
    move_object(thief, this_object());
  }    
  if (arg)
    return;
  set_light(1);
  short_desc = "The entrance to Angmar's treasury";
#if 0
  trig=0;
#endif
  dest_dir = ({
    "players/angmar/castle/midstairs", "south",
    "players/angmar/castle/treasury", "north"
  });
}

void
init() {
  room::init();
  add_action("open", "open");
  add_action("close", "close");
  add_action("north", "north");
  if(got_rings())
#if 0
    activate();
#else
    call_out("face_time", 2, this_player());
#endif
}

void
password_ok() {  /* called from treasury */
#if 0
  trig = 0;
  trig2 = 0;
#endif

  /* destruct rings */
  if (present("trlock1", this_player()) &&
      present("trlock2", this_player()) &&
      present("trlock3", this_player())) {
    destruct(present("trlock1", this_player()));
    destruct(present("trlock2", this_player()));
    destruct(present("trlock3", this_player()));
    write("Your rings begin to glow even brighter, and then they disappear!\n");
    say(this_player()->query_name()+"'s rings disappear.\n");
  }
}

void
doors_open() {
  tell_room(this_object(),
    "The doors to the treasury slam shut with a deafening boom!\n");
}

#if 0
void
heart_beat() {
  if (trig > 0) {
    trig -= 1;
    if (trig == 0) {
      say(this_player()->query_name()+"'s rings begin to glow!\n");
      say("Suddenly a face seems to materialize deep within the doors.\n");
      say("The face whispers: 'Do you have the password?'\n");
      trig2 = 15;
    }
  }
  if (trig2 > 0) {
    trig2 -= 1;
    if (trig2 == 0) {
      say("The face fades away. Your rings no longer glow.\n");
      set_heart_beat(0);
    }
  }
}
#endif

void face_time(object trigger) {
  if (!listener || !living(listener)) {
    listener = clone_object("players/angmar/o/catch_password");
    listener->set_room("players/angmar/castle/treasury");
    listener->set_call("catch_it");
    move_object(listener, this_object());
  }
  tell_room(this_object(), (string)trigger->query_name() +
            "'s rings begin to glow!\n");
  tell_room(this_object(),
            "Suddenly a face seems to materialize deep within the " +
	    "doors.\n");
  tell_room(this_object(),
            "The face whispers: 'Do you have the password?'\n");
  call_out("face_gone", 15, trigger);
}

status face_gone(object plyr) {
  tell_room(this_object(),
            "The face fades away.\n");
  tell_room(this_object(), (string)plyr->query_name() +
            "'s rings no longer glow.\n", ({ plyr }) );
  tell_object(plyr, "Your rings no longer glow.\n");
  destruct(listener);
}

void
long(string str) {
  if (str == "door" ||
      str == "doors" || 
      str == "huge iron doors" ||
      str == "twin doors" || 
      str == "giant doors" ||
      str == "giant twin doors" ||
      str == "iron doors" || 
      str == "huge doors") {
    if (!("players/angmar/castle/treasury"->query_door()))
      write("The doors to the treasury are open.\n");
    else
      write("You see reliefs of three rings on the huge iron doors.\n");
      write("The doors are closed.\n");
  }
  if("players/angmar/castle/treasury"->query_door()) {
    write("This is the entrance to Angmar's treasury. Many are the tales\n");
    write("about his hidden treasures. So far, nobody has been able to\n");
    write("enter. Maybe you will be the first one?\n");
    write("There are two giant twin doors to the north.\n");
    write("The only obvious exit is to the south.\n");
  }
  else {
    write("This is the entrance to Angmar's treasury. The doors\n");
    write("are open.\n");
  }
}

mixed
id(string str) {
  return str=="door" || str=="doors";
}

status
open(string str) {
  if (str != "door" && str !="doors")
    return 0;
  write("A blue flash strikes out and hits you as you reach for\n");
  this_player()->add_hit_point(-5);
  write("the doors. You gasp in pain.\n");
  say(this_player()->query_name() +
    " is hit by a blue flash as he reaches for the doors.\n");
  say(this_player()->query_name()+" gasps in pain.\n");
  return 1;
}

status
close(string str) {
  if (str != "door" && str != "doors")
    return 0;
  "players/angmar/castle/treasury"->close_door("door");
  return 1;
}

status
north() {
  if("players/angmar/castle/treasury"->query_door()) {
    write("The iron doors are closed.\n");
    return 1;
  }
  this_player()->move_player("north#players/angmar/castle/treasury");
  return 1;
}
