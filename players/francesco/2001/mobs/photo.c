inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   set_name("photographer");
   set_race("human");
   set_alias("photographer");
      set_short("A photographer");
     set_long("Wearing a full space suit with a helmet, his voice comes with a \n"+
              "metallic sound.  Nothwithstanding the weight of his suit, he moves \n"+
              "rapidly and precisely, due to the lack of gravity here.\n");
   set_level(11);
   set_hp(165);
   set_al(0);
   set_wc(15);
   set_ac(9);
   set_chat_chance(6);
   load_chat("Excuse me, gentlemen, if you'd all line up on this side of the walkway we'd\n"+
             "like to take a few photographes. Dr. Floyd, would you stand in the middle....\n"+
             "Dr. Michaels on that side...... Mr. Halvorsen on the other........ thank you.\n");
   move_object(clone_object("/players/francesco/2001/items/camera.c"),this_object());
}
