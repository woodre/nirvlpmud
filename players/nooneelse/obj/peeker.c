/*
 peeker.c
*/

inherit "obj/monster";

object peeker;
string function, type, match, str, msg_a, msg_b;

reset(arg) {
  ::reset(arg);

  function = allocate(2);
  type = allocate(2);
  match = allocate(2);

  function[0] = "test_say";
  type[0] = "says:";
  type[1] = "tells you:";

  set_match(this_object(), function, type, match);
  set_name("peeker");
  set_level(19);
  set_hp(999);
  set_ep(9999999);
  set_al(0);
  set_wc(25);
  set_ac(10);
  set_whimpy(0);
  set_aggressive(0);
  enable_commands();
  is_invis=99;
  set_light(3);
  call_out("trash_this", 10);
}

trash_this() { destruct(this_object()); }

short() { return; }

test_say(str) {
   sscanf(str, "%s: %s", msg_a, msg_b);
   this_object()->init_command(msg_b);
}

query_save_flag() { return 1; }
