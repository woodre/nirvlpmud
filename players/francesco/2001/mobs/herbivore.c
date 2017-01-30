inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   set_name("brontosaurus");
   set_race("animal");
   set_alias("bronto");
      set_short("Brontosaurus");
     set_long("  The brontosaurus is a very heavy animal, with a long neck which\n"+
              "might extend up to 20 feet.  It is about 60 feet long and should\n"+
              "weight several tons.  He has short legs and thus his movements are\n"+
              "very slow and not agile at all.  Being an herbivore, he tries to\n"+
              "forage through the scarce bushes of the savannah.\n");

   set_level(13);
   set_hp(195);
   set_al(-10);
   set_wc(17);
   set_ac(10);
 move_object(clone_object("/players/francesco/2001/items/toenail.c"),this_object());
}
