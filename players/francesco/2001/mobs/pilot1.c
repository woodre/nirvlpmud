inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   set_name("captain");
   set_race("human");
   set_alias("captain");
      set_short("The captain of the Space Shuttle 5");
     set_long("The well decored suit worn by the captain means that he belongs to\n"+
              "Army.  He does his job with great responsabilyt, and continuosly\n"+
              "check the instrumentation on his control deck for the safety of the\n"+
              "spacecraft, of the crew and of the guest travellers.  He is short,\n"+
              "slim, does not speak much, but he is perfect on his duties.\n");
   set_level(14);
   set_hp(220);
   set_al(0);
   set_wc(18);
   set_ac(11);
 move_object(clone_object("/players/francesco/2001/items/map1.c"),this_object());
}
