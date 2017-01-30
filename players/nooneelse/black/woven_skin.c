/*
  woven_skin.c - larger skin woven from skins from corpses.
                 used by vamps to make items.
*/

inherit "obj/treasure";

string skin_msg;
int skin_strength;

query_save_flag() { return 1; }

reset(arg) {
  set_id("woven skin");
  set_alias("skin");
  set_value(25);
  set_weight(1);
}

short() { return "A processed skin"; }

long(str) {
  write("It is a large skin processed from several skins ["+
        skin_strength+"]"+".\n");
}

set_skin_strength(arg) { skin_strength=arg; }
query_skin_strength() { return skin_strength; }
