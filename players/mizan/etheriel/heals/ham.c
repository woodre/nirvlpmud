inherit "obj/weapon";
int chunks;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("chunk of ham");
  set_alias("ham");
  set_value(5000);
  set_class(15);
  set_weight(4);
  chunks=8;
}

init() {
  ::init();
  add_action("eat","eat");
/*
  add_action("bite","bite");
*/
}

short() {
  if(wielded) return "A huge chunk of ham (wielded)";
return "A huge chunk of ham";
}

long() {
  write("This is a HUGE chunk of ham, capable of being a weapon as well\n"+
	"as sustaining an army for several weeks. It can be 'eaten' in one\n"+
      "shot, but heck, you'd need one big stomach to keep it all in.\n");
}

eat(str) {
  if(!str || str !="ham") return 0;
  if(!this_player()->eat_food(15)) {
    write("You would die if you tried to eat this thing whole.\n");
    return 1;
  }
  write("You feel as if you had just eaten a bowling ball.\n");
  say((this_player()->query_name())+" brutalizes a chunk of ham, leaving only a bone.\n");
  this_player()->heal_self(chunks * 10);
  destruct(this_object());
  return 1;
}

bite(str) {
  if(!str || str !="ham") return 0;
  this_player()->eat_food(4);
  write("You tear a bite off the chunk. It's a bit shorter now.\n");
  say((this_player()->query_name())+" takes a bite off a HUGE chunk of ham.\n");
  this_player()->heal_self(10);
  chunks=chunks-1;
   this_object()->set_wc(7 + chunks);
    if(chunks = 0) {
      write("You've finished off the ham.\n");
      destruct(this_object());
      return 1;
    }
  return 1;
}
