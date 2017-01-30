inherit "obj/monster";
   object gold;
   object ring;
reset(arg){
   ::reset(arg);
   if (arg) return;
   set_name("myra");
   set_race("human");
   set_alias("Myra");
      set_short("Myra");
     set_long("This elegant lady is carrying a briefcase and is quietly talking on a\n"+
               "cellular phone.  She must be an executive of an important firm.  As a\n"+
               "matter of fact, it is very frequent that in this University you meet\n"+
               "people interested in establishing research relationships and contracts\n"+
               "with the faculties.  She is smiling and looks happy to be here since\n"+
               "she is sure that she will find those high tech answers to her needs.\n");

   set_level(10);
   set_hp(150);
   set_al(100);
   set_wc(14);
   set_ac(8);
 ring =clone_object("/players/francesco/univ/items/ring_myra");
 move_object(ring,this_object());
 gold = clone_object("obj/money");
 gold->set_money(100+random(100));
 move_object(gold,this_object());
}
