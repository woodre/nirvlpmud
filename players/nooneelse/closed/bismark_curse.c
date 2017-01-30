/*
  bismark_curse.c - to stop bismark from licking people
*/

inherit "obj/treasure";

reset(arg) {
  if (arg) return 0;

  set_id("bismark curse");
  set_alias("curse");
  set_weight(0);
  set_value(0);
  enable_commands();
  set_heart_beat(1);
}

init() {
  add_action("wiz_stuff", "wiz");
}

wiz_stuff(str) {
  string str1, str2;
  if (!str) return 0;
  str1=0;
  str2=0;
  sscanf(str, "%s lick %s", str1, str2);
  if (!str1) sscanf(str, "%s lick", str1);
  if (!str1) sscanf(str, "lick%s", str1);
  if (str1 != 0) mess_with_him();
  return 0;
}

catch_tell(str) {
  string str1, str2;
  if (!str) return 0;
  str1=0;
  str2=0;
  sscanf(str, "%s lick %s", str1, str2);
  if (!str1) sscanf(str, "%s lick", str1);
  if (!str1) sscanf(str, "lick%s", str1);
  if (str1 != 0) mess_with_him();
  return 0;
}

mess_with_him() {
  object who_obj;
  who_obj = environment(this_object());
  command("sneeze", who_obj);
  command("cough", who_obj);
  command("cough", who_obj);
  command("burp", who_obj);
  command("cough", who_obj);
  command("sneeze", who_obj);
  command("fart", who_obj);
  command("fart", who_obj);
  command("puke", who_obj);
  command("puke", who_obj);
  tell_object(who_obj,
              "\n\n\nYou were asked not to lick people weren't you?\n\n\n");
  return 1;
}
