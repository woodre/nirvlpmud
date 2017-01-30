#define ME capitalize(this_player()->query_real_name())
#define OWE capitalize(owner)
inherit "obj/treasure";

string owner;

reset(arg) {
 if(arg) return;
  set_long("A Mage Summons.\n");
  set_weight(0);
  set_value(0);
  owner = "Jomama";
  call_out("times_up", 30);
}

id(str){
  return str == "summon_obj";
}

set_owner(str){ owner = str; }

init(){
 add_action("answer_yes","yes");
 add_action("answer_no","no");
}

summons(){
  object obj;

  obj = environment(this_object());
  tell_object(obj, "\n"+
  "     You have been offered a Summons by "+OWE+".\n"+
  "     If you wish to accept these summons and be magically teleported\n"+
  "     to "+OWE+" type 'yes'.  If you wish to decline the summons,\n"+
  "     please type 'no'.\n"+
  "\n");
  return 1;
}

times_up(){
  tell_object(environment(this_object()),
  "No Answer - You have declined "+OWE+"'s summons.\n");
  tell_object(find_player(owner),
  "No Answer - "+capitalize(environment(this_object())->query_name())+
  " has declined your summons.\n");
  destruct(this_object());
  return 1;
}

answer_no(){
  object obj;

  write(
  "You decline "+OWE+"'s summons.\n"+
  "The tingling sensation disappears.\n");
  obj = find_player(owner);
  tell_object(obj,
  "\n"+ME+" has declined your summons.\n"+
  "You end the summons spell.\n");
  destruct(this_object());
  return 1;
}

answer_yes(){
  object ob, obj;

  obj = find_player(owner);

  write(
  "You accept the summons of "+OWE+".\n");
  tell_object(obj,
  "\n"+ME+" has accepted your summons.\n");

  write(
  "You begin to feel a tugging force on your body.  Your whole person\n"+
  "is simultaneously ripped apart and squished together.  The ground\n"+
  "drops out from under your feet and you are magically swept away.\n");

  if(environment(this_player())->realm() == "NT"){
    write(
    "You are suddenly yanked back to where you started.  Strange forces\n"+
    "block "+OWE+"'s summons.\n");
    tell_object(obj, "\n"+
    "You begin to teleport "+ME+" through space and time, but something\n"+
    "blocks your spell.  Your summons spell ends abruptly.\n");
    say(
    "There is a bright flash and a loud 'BOOM'!\n"+
    ME+" disappears.\n"+
    ME+" suddenly reappears 10 feet off the ground.\n"+
    ME+" falls to the ground with a graceless 'Thud!'.\n");
    obj->add_spell_point(-30);
    destruct(this_object());
    return 1;
    }

  write(
  "There is a bright flash and a thundering 'BOOM'!\n"+
  "You are magically teleported across space and time to reappear\n"+
  "before "+OWE+".\n");
  say(
  "There is a bright flash and a thudering 'BOOM'!\n"+
  ME+" disappears.\n");
  tell_object(obj,
  "You magically teleport "+ME+" across space and time.\n");
  move_object(this_player(), environment(obj));
  say(
  "There is a bright flash and a thundering 'BOOM'!\n"+
  ME+" appears.\n");
  obj->add_spell_point(-80);
  destruct(this_object());
  return 1;
}
