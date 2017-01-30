inherit "obj/treasure";

reset(arg) {
 if(arg) return;
    set_short("A Stone");
    set_alias("stone");
  set_long("This is a very magical stone of light and dark, maybe you could rub it.\n");
   set_weight(2);
    set_value(5000);
}
 id(str) { return str == "stone" || str == "grey stone"; }

init() {
 ::init();
  add_action("rub","rub");
}

rub(str) {
     int was, to_be;
      object ob;
  if(!str) {
    write("rub STONE.\n");
     return 1;
       }
   if (!(ob=present(str, this_player()))) {
      write("You dont have one of those!\n");
        return 1;
        }
  if(this_player()->query_exp() < 50000) {
write("You cant do that with such little XP!\n");
return 1;
}
if(random(100) < 90) {
  this_player()->add_exp(50000);
  write("The stone shivers in your hand and in a flash of light, gives you 50,000 experience points\n");
destruct(this_object());
return 1;
}
  else {
  this_player()->add_exp(-50000);
   write("The stone shivers in your hand and in a flash of light, steals 50,000 experience points\n");
destruct(this_object());
  return 1;
}
}
