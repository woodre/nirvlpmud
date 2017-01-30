status is_peeled;
status is_eaten;

reset() {
  is_eaten  = 0;
  is_peeled = 0;
  return 1;
}

get() { return 1;}
drop() { return 0; }

query_weight() { return 1; }

query_value() { return 1; }

id(str) {
  if (is_peeled)
  return str == "banana";
  if (!is_peeled) return str == "banana" || str == "sticker";
}
init() {
  add_action("peel", "peel");
  add_action("squish", "squish");
  add_action("eat", "eat");
}
short() {
  if (is_peeled) return "a peeled banana";
  if (!is_peeled) return  "a banana";
}

long(str) {
  if (str == "banana") {
if (!is_peeled)
   write("A nice ripe banana.\n");
if (is_peeled)
   write("A peeled banana in your hands.\n");
  return 1;
  }
  if (str == "sticker") {

   write("This banana was brought to you by...\n");
   write("Mister.\n");
   return 1;
  }
}

peel(str) {
  string name;
  name = capitalize(call_other(this_player(), "query_name"));
  if (!str || !id(str)) { write("Peel what?\n"); return 1; }
  if (is_peeled) { write("This banana is already peeled.\n");
  return 1; }
  if (!is_peeled) {
  is_peeled = 1;
  write("You peel the ripe banana.\n");
   say(name+" peels a banana.\n");
   return 1;
  }
}
eat(str) {

  object peel;
  string name;
  if (!str) { write("Eat what?\n"); return 1; }
  if (!id(str)) { write("Eat whaaa?\n"); return 1; }
  if (is_eaten) { write("Someone alredy ate this banana.\n"); return 1; }
 name = capitalize(call_other(this_player(), "query_name"));
  if (!is_peeled) {
   write("You bite through the banana peel.\n Doesn't taste too great eh?\n")
;
   say(name+" the fool eats a banana whole! peel and all!\n");
   is_eaten = 1; is_peeled = 1;
   destruct(this_object());
   return 1;
  }
  is_eaten = 1;
  write("You eat a banana.\n Yummy!\n");
  write("You're left with the peel.\n");
  call_other(this_player(), "heal_self", 2);
  say(name+" eats a banana and is left with a peel.\n");
  destruct(this_object());
  return 1;
}
squish(str) {
  object ob;
  string name, targ;
  name = capitalize(call_other(this_player(), "query_name"));
  targ = capitalize(str);
 if (!str || !present(str, environment(this_player())) )
  { write("Squish the banana on who?\n"); return 1; }
   write("You squish the banana on "+targ+"'s forehead.\n");
   write("Doesn't "+targ+" look real goofy!\n");
  say(name+" squishes a banana on "+targ+"'s forehead!\n");
  ob = find_player(str);
tell_object(ob,name+" squishes a banana on your forehead!\n");
  destruct(this_object());
   return 1;
  }

