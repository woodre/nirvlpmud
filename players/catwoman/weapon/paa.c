
id(str) { return str== "dart"; }

short() { return "Type AA poison dart"; }

long() {
   write("A poison dart to be used with a blowgun.\n");
}

get() { return 1; }

query_value() { return 10; }

shoot(ob) {
  call_other(ob, "hit_player", random(5));
  destruct(this_object());
  call_other(this_player(), "add_weight", -1);
  return 1;
}

query_weight() { return 1; }

