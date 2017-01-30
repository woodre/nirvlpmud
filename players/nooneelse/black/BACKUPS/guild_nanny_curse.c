/*
 guild_nanny_curse.c
*/

int effect_number;

reset() {
  enable_commands();
  set_heart_beat(1);
}

drop() { return 1; }

start_curse() {
  call_out("effect", 3);
}

effect(arg) {
  mess_with_him();
  effect_number = effect_number + 1;
  if (effect_number==1) { call_out("effect", 13); }
  if (effect_number==2) { call_out("effect", 10); }
  if (effect_number==3) { call_out("effect", 7); }
  if (effect_number==4) { call_out("effect", 4); }
  if (effect_number==5) { call_out("effect", 2); }
  if (effect_number==6) { call_out("effect", 13); }
  if (effect_number==7) { call_out("effect", 10); }
  if (effect_number==8) { call_out("effect", 7); }
  if (effect_number==9) { call_out("effect", 4); }
  if (effect_number==10) { call_out("effect", 2); }
  if (effect_number==11) { destruct(this_object()); }
}

mess_with_him() {
  object who_obj;
  string whos_name;
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
  return 1;
}

id(str) { return str=="guild nanny curse" ||
                 str=="guild nanny curse" ||
                 str=="curse"; }
