#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("weapon");
    set_alt_name("sword");
    set_alias("test");
    set_short(BLU+"TEST"+NORM);
    set_long("     A test weapon.\n");
    set_class(16);
    set_weight(4);
    set_value(0);
    set_hit_func(this_object());
}
weapon_hit(attacker){
   int X;
   int Y;
   int V;
   int W;
   int Z;
   string how;
   string what;
   set_hits(1);
   set_misses(1);
   X = (this_player()->query_attrib("sta"));
   Y = (this_player()->query_attrib("str"));
       while(X>4) {
       Y = (Y/2);
       Z = (random(20));
       if(Z<X) {
       V = (random(Y+16));
       W = (W+(V));
    how = " to small fragments";
    what = "massacre";
    if (V < 30) {
      how = " with a bone crushing sound";
      what = "smashed";
    }
    if (V < 20) {
      how = " very hard";
      what = "hit";
    }
    if (V < 10) {
      how = " hard";
      what = "hit";
    }
    if (V < 5) {
      how = "";
      what = "hit";
    }
    if (V < 3) {
      how = "";
      what = "grazed";
    }
    if (V == 1) {
      how = " in the stomach";
      what = "tickled";
    }
    write("You " + what + " " + this_player()->query_attack()->query_name() + how + ".\n");
    say(cap_name + " " + what + " " + this_player()->query_attack()->query_name() + how +
		".\n");
}
       X = (X - 5);
}
         attacker->hit_player(W);
         return 0;
}

query_save_flag()  { return 1; }

id(str) { return str=="legion_weapon"; }


