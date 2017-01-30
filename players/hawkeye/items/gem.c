inherit "obj/treasure";

reset(arg) {
 if(arg) return;
    set_short("A Pretty Gem");
    set_alias("gem");
set_long("This is a very pretty gem that you just CAN'T stop looking at.\n"+
"No matter how hard you try, you cant keep your hands off it.\n"+
"You just want to rub it more and more!.\n");
   set_weight(2);
    set_value(10000);
}
 id(str) { return str == "gem" || str == "grey stone"; }

init() {
 ::init();
  add_action("rub","rub");
   add_action("stone","tell");
add_action("stone","say");
add_action("stone","sell");
add_action("stone","'");
add_action("stone","drop");
add_action("stone","get");
add_action("stone","gossip");
add_action("stone","shout");
add_action("stone","equip");
add_action("stone","junk");
add_action("stone","rt");
add_action("stone","whisper");
add_action("stone","emote");
add_action("stone",":");
add_action("stone","give");
add_action("stone","offer");
add_action("stone","tithe");
}

rub(str) {
     int was, to_be;
      object ob;
  if(!str) {
    write("rub gem.\n");
     return 1;
       }
   if (!(ob=present(str, this_player()))) {
      write("You dont have one of those!\n");
        return 1;
        }
write("You take your gem to the corner and rub it lovingly!.\n");
return 1;
}
stone() {
write("How can you possibly do that when you have this pretty gem\n" +
"to rub?\n");
return 1;
}

