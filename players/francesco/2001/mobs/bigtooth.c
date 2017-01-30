inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   set_name("bigtooth");
   set_race("animal");
   set_alias("bigtooth");
      set_short("Bigtooth");
     set_long("Among his kind, Big Tooth is almost a giant. He is nearly\n"+
              "four feet high, and though badly undernourished, weighs over\n"+
              "a hundred pounds. His body is of the hominid type, even though\n"+
              "his head is still nearer to ape than man. The forehead is\n"+
              "low, his gaze is almost switched off.\n");
   set_level(15);
   set_hp(250);
   set_al(-10);
   set_wc(20);
   set_ac(12);
 move_object(clone_object("/players/francesco/2001/items/apeskin.c"),this_object());
}
