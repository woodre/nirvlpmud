
id(str) { return str=="dart"; }

short() { return "A dart"; }

long() {
   write("An arrow of the Dark Circle, dripping with poison.\n");
}

get() { return 1; }

query_value() {return 10;}

shoot(ob) {
  call_other(ob, "hit_player", 30);
  destruct(this_object());
  return 1;
}

