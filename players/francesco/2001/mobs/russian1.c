inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   set_name("russian");
   set_race("human");
   set_alias("scientist");
      set_short("A russian scientist");
     set_long("This russian scientist has been enrolled into the space mission only\n"+
              "because his country generously participated into the construction of\n"+
              "the first lunar basis.  Yet his gaze is sad, and his suit of a cheap\n"+
              "decore.  He cant forget the economics troubles of his country, dating\n"+
              "back to the fall of the Wall of Berlin.\n");
   set_level(12);
   set_hp(180);
   set_al(0);
   set_wc(16);
   set_ac(9);
 move_object(clone_object("/players/francesco/2001/items/rubli.c"),this_object());
}
