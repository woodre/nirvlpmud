inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   set_name("ape");
   set_race("humanoid");
   set_alias("member");
      set_short("A member of the tribe of the Moonwatcher");
     set_long("The same tribe than the Moonwatcher, yet definately smaller.\n"+
              "Also his shape relates more to apes than to men.  He often\n"+
              "wanders around to looking for food as he mostly enjoys berries.\n"+
              "His main concern is also to avoiding the lions who wander the\n"+
              "valley.  He moves cautiously.  He saw several of his tribemates\n"+
              "falling down in no time under the lions' sharp, point and nasty\n"+
              "teeth.\n");
   set_level(12);
   set_hp(180);
   set_al(-10);
   set_wc(16);
   set_ac(9);
 move_object(clone_object("/players/francesco/2001/items/berries.c"),this_object());
}
