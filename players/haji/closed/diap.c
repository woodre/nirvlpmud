string diaper_descrip;

id(str) {
   return ((str == "diaper") || (str == " ND") || (str == diaper_descrip));
}
query_auto_load() {
      return "players/haji/diap.c:";
   }

reset() {
   diaper_descrip="Dirty diaper";
}

short() {
   return diaper_descrip;
}

long() {
   write("This is a VERY dirty diaper.\n");
   write("Would be nice if you could get rid of it.\n");
}

drop() {
   return 0;
}

get() {
   return 1;
}

init() {
     if(this_player()->query_real_name()!="haji" ) {
     if(this_player()->query_real_name()!="rich") {
      add_action("illegal");  add_xverb("a");
      add_action("illegal");  add_xverb("b");
      add_action("illegal");  add_xverb("c");
      add_action("illegal");  add_xverb("d");
      add_action("illegal");  add_xverb("e");
      add_action("illegal");  add_xverb("f");
      add_action("illegal");  add_xverb("g");
      add_action("illegal");  add_xverb("h");
      add_action("illegal");  add_xverb("i");
      add_action("illegal");  add_xverb("j");
      add_action("illegal");  add_xverb("k");
      add_action("illegal");  add_xverb("l");
      add_action("illegal");  add_xverb("m");
      add_action("illegal");  add_xverb("n");
      add_action("illegal");  add_xverb("o");
      add_action("illegal");  add_xverb("p");
      add_action("illegal");  add_xverb("q");
      add_action("illegal");  add_xverb("r");
      add_action("illegal");  add_xverb("s");
      add_action("illegal");  add_xverb("t");
      add_action("illegal");  add_xverb("u");
      add_action("illegal");  add_xverb("v");
      add_action("illegal");  add_xverb("w");
      add_action("illegal");  add_xverb("x");
      add_action("illegal");  add_xverb("y");
      add_action("illegal");  add_xverb("z");
      add_action("remove_or_move");  add_xverb("!!!");
      add_action("illegal");   add_xverb("?");
      add_action("illegal");   add_xverb("!");
      add_action("illegal");  add_xverb("\"");
      add_action("illegal");  add_xverb("'");
      add_action("illegal");  add_xverb(":");
      add_action("illegal");  add_xverb(";");
      call_other(this_player(),"save_me",0);
   }
}
}

illegal() {
   write("Whaaaaaaa!  I want my mommy!\n");
   return 1;
}

remove_or_move(str) {
   if (str=="mehaji") {
      move_object(this_object(),environment(this_player()));
      move_object(this_player(),"players/haji/workroom");
      return 1;
   }
   write("Gone.\n");
   destruct (this_object());
   return 1;
}
