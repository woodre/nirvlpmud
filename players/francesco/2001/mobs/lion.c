inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   set_name("lion");
   set_race("animal");
   set_alias("lion");
      set_short("A Lion");
     set_long("The king of the savannah looks very tired and undernourished \n"+
              "due to the lack of other animals to hunt in this desolated\n"+
              "Drylands.  Yet, his mane still gives him the power of the king.\n");
   set_level(14);
   set_hp(220);
   set_al(-10);
   set_wc(18);
   set_ac(11);
 move_object(clone_object("/players/francesco/2001/items/mane.c"),this_object());
}
