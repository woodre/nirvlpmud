
inherit "obj/weapon";

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("voulge");
   set_short("a voulge");
   set_long("An inscription on the blade reads:\n"+
            "        The mightier the wielder, the mightier the sword.\n");
   set_value(2000);
   set_class(10);
   set_hit_func(this_object());
}
query_save_flag() { return 1; }

weapon_hit(attacker) {
   int str;
   str = this_player()->query_attrib("str");

   if(str < 10) {
     return 0;
   }
   if(str < 12) {
     return 2;
   }
   if(str < 14) {
     return 4;
   }
   if(str < 16) {
     return 6;
   }
   if(str < 18) {
     return 8;
   }
   if(str == 19) {
     return 10;
   }
   if(str == 20) {
     return 12;
   }
}

