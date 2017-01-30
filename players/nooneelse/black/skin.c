/*
  skin.c - skinned from a corpse. used by vamps to make items.
*/

inherit "obj/treasure";

string skin_msg;
int skin_strength;

query_save_flag() { return 1; }

reset(arg) {
  set_id("skin");
  set_value(25);
  set_weight(1);
}

short() { return "The skin of "+skin_msg; }

long(str) {
  write("It is a skin from the corpse of "+skin_msg+" ["+
        skin_strength+"]"+".\n");
}

set_skin_msg(arg) {
  if(!arg) return 0;
    if(!sscanf(arg,"corpse of %s",skin_msg)) return 0;
  skin_msg=capitalize(skin_msg);
}
set_skin_strength(arg) { skin_strength=arg; }
query_skin_strength() { return skin_strength; }
