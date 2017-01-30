inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   set_name("instructor");
   set_race("human");
   set_alias("instructor");
      set_short("The gym instructor");
     set_long("The gym instructor is about 6 and 1/2 feet tall and weights\n"+
              "190 pounds, perhaps.  He wears only a gym suit that barely \n"+
              "hides his strong musculature.   His well built body and his \n"+
              "gracious movements make you speechless.\n");
   set_level(13);
   set_hp(195);
   set_al(0);
   set_wc(17);
   set_ac(10);
move_object(clone_object("/players/francesco/2001/items/pill2.c"),this_object());
}
