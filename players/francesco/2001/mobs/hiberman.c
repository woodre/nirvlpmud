inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   set_name("man");
   set_race("human");
   set_alias("man");
      set_short("Hibernating man");
     set_long("The hibernating man is completely naked but for a tong.  Of a very pale\n"+
              "complextion and thiny body, his eyes are about close.\n");
   set_level(10);
   set_hp(150);
   set_al(0);
   set_wc(14);
   set_ac(8);
   move_object(clone_object("/players/francesco/2001/items/pill4.c"),this_object());
}
