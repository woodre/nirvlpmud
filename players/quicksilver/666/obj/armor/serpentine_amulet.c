#include "/players/quicksilver/666/include/std.h"

inherit ARMOR;

short() {
  string tmp_short;
    if (!short_desc)
	return 0;
     tmp_short = short_desc;
       if(this_player()->is_player() && size) {
         if(size == 1) tmp_short = tmp_short + " (XS)";
         if(size == 2) tmp_short = tmp_short + " (S)";
         if(size == 3) tmp_short = tmp_short + " (M)";
         if(size == 4) tmp_short = tmp_short + " (L)";
         if(size > 4) tmp_short = tmp_short + " (XL)";
              }
  if (call_other(this_player(), "query_level", 0) > 30)
   {
       tmp_short = tmp_short + "  < ac " + ac + ", " +type +" >";
     }
     if (worn || (file_name(ENVTO)==CRE_DIR+"kern"))
      return tmp_short + " (worn)";
      return tmp_short;
}

reset(arg) {
     ::reset(arg);
     if(arg) return;
     set_type("amulet");
     set_name("serpentine amulet");
     set_alias("amulet");
     set_ac(1);
     set_weight(1);
     set_short("a silver serpentine amulet");
     set_long("This amulet, made from pure silver, contains the image of a snake.  On the\n"+
              "reverse side there is an engraving.\n");
}

init() {
     ::init();
     add_action("read", "read");
}

read(str) {
     if(str != "engraving") return;
     write("The engraving reads:\n  Dorraghys Beayn\n");
     return 1;
}
