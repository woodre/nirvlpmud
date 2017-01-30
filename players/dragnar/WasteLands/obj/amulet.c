inherit "obj/treasure";

void
reset(int arg) {
   if (arg) return;
   set_id("amulet");
   set_short("An amulet of teleportation");
   set_long(
"The face of the amulet is covered with beautiful gems.  They sparkle\n"+
"and seem to almost put you in a trance.  You have a sudden urge to rub\n"+
"the amulet and rob it of its powers.\n");
   set_value(5000);
   set_weight(1);
}

void init() { add_action("cmd_rub","rub"); }

status
cmd_rub(string str) {
   if (id(str)) {
      write(
"As you rub the amulet the gems turn into a blue mist.  You feel\n"+
"your body being transfered to another place.\n");
      this_player()->move_player("in a blue mist#players/dragnar/WasteLands/rooms/bridge");
      destruct(this_object());
      return 1;
   }
}
