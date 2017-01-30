/*
  spell_test.c
*/

inherit "/obj/treasure";

id(str) { return str=="spell_test"; }

init() {
  add_action("test", "test");
}

test(arg) {
  object obj;
  string spell_name, caster_msg, target_msg, room_msg;
  int spell_damage, spell_cost;

  obj = present(arg, environment(this_player()));
  if (!obj) {
    write("'"+arg+"' isn't here.\n");
    return 1;
  }
  spell_name = "Spell Test";
  spell_damage = 1;
  spell_cost = 1;
/*
  caster_msg = "Only the caster should see this.\n";
  target_msg = "Only the target should see this.\n";
  room_msg = "Only the room should see this.\n";
  this_player()->spell_object(obj, spell_name, spell_damage, spell_cost,
                              caster_msg, target_msg, room_msg);
*/
  this_player()->spell_object(obj, spell_name, spell_damage, spell_cost);
  return 1;
}
