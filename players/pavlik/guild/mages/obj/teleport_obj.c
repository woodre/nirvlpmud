inherit "/obj/treasure";
#define ME capitalize(this_player()->query_real_name())
#define OWE capitalize(owner)
#define IT capitalize(obj->query_name())

string owner, what;
string error_room;
int spell_fail;

reset(arg) {
 if(arg) return;
  set_long("A Mage Summons.\n");
  set_weight(0);
  set_value(0);
  owner = "Jomama";
  what = "goto";
  spell_fail = 0;

  error_room = allocate(10);
  error_room[0] = "room/shop";
  error_room[1] = "room/church";
  error_room[2] = "room/slope";
  error_room[3] = "room/mount_pass";
  error_room[4] = "room/farmroad1";
  error_room[5] = "room/sea";
  error_room[6] = "room/inn";
  error_room[7] = "room/fortress";
  error_room[8] = "room/path1";
  error_room[9] = "room/big_tree";

  call_out("times_up", 80);
}

id(str){
  return str == "summon_obj";
}

set_owner(str){ owner = str; }
set_what(str){ what = str; }
set_spell_fail(str){ spell_fail = str; }

init(){
  add_action("answer_no","tpno");
  add_action("answer_yes","tpyes");
}

do_tlp(){
  object obj;

  obj = environment(this_object());

  if(what == "goto")
    tell_object(obj, OWE+" has asked your permission to teleport to you.\n");
  else
    tell_object(obj, OWE+" has offered to teleport you to him.\n");

  tell_object(obj,
  "If you wish to accept "+OWE+"'s request, type 'tpyes'.\n"+
  "If you wish to decline the request, type 'tpno'.\n");
  return 1;
}

times_up(){
  object obj;

  obj = environment(this_object());

  if(!obj) {
	destruct(this_object());
	return 1;
  }

  tell_object(obj,
  "No Answer - You have declined "+OWE+"'s summons.\n");

  if(find_player(owner))
    tell_object(find_player(owner),
    "No Answer - "+capitalize(environment(this_object())->query_name())+
    " has declined your summons.\n");

  destruct(this_object());
  return 1;
}

answer_no(){
  object obj;

  write("You have declined "+OWE+"'s teleport.\n");

  if(find_player(owner))
    tell_object(find_player(owner),
    "\n"+ME+" has declined your summons.\n"+
    "You end the summons spell.\n");

  destruct(this_object());
  return 1;
}

answer_yes(){
  object ob, obj;

  if(!find_player(owner)){
    write("The teleport has been cancelled.\n");
    destruct(this_object());
    return 1;
  }

  if(what == "bring") obj = this_player();
  else obj = find_player(owner);

  write("You accept "+OWE+"'s teleport request.\n");
  tell_object(find_player(owner), ME+" has accepted teleportation.\n");

  tell_object(obj,
  "You begin to feel a tugging force on your body.  Your whole person\n"+
  "is simultaneously ripped apart and squished together.  The ground\n"+
  "drops out from under your feet and you are magically swept away.\n");

  if(environment(find_player(owner))->realm() == "NT" ||
  environment(this_player())->realm() == "NT"){
    tell_object(obj,
    "You are suddenly yanked back to where you started!\n"+
    "Strange forces block "+OWE+"'s summons.\n");
    tell_object(find_player(owner),
    "Your teleport spell is Blocked!\n");
    say(
    "There is a bright flash and a loud 'BOOM'!\n"+
    IT+" disappears.\n"+
    IT+" suddenly reappears 10 feet off the ground.\n"+
    IT+" falls to the ground with a graceless 'Thud!'.\n");
    find_player(owner)->add_spell_point(-20);
    destruct(this_object());
    return 1;
  }

  tell_object(obj,
  "There is a bright flash and a thundering 'BOOM'!\n"+
  "You are magically teleported across time and space.\n");
  say(
  "There is a bright flash of light and a thundering 'BOOM'!\n"+
  IT+" disappears!\n");

  if(spell_fail == 1) {
    if(what == "bring") {
      tell_object(find_player(owner),
      "Something has gone wrong with your spell, "+ME+" has become lost!\n");
    }
    tell_object(obj,
    "Something has gone wrong with the spell!\n"+
    "You reappear in a new location.\n");

    move_object(obj, error_room[random(sizeof(error_room))]);
  }

  if(what == "bring")
    tell_object(find_player(owner),
    "You teleport "+ME+" across time and space.\n");

  if(what == "bring")
    move_object(this_player(), environment(find_player(owner)));
  else
    move_object(find_player(owner), environment(this_player()));

  tell_room(environment(this_player()),
  IT+" appears in a crescendo of thunder and lightning!\n");

  find_player(owner)->add_spell_point(-80);
  destruct(this_object());
  return 1;
}
