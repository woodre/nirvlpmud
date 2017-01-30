inherit "obj/monster";
   object gold;
reset(arg){
   object backpack;
   ::reset(arg);
   
   set_name("erica");
   set_race("human");
   set_alias("student");
      set_short("Erica, a freshman student");
      set_long("Erica is going to her classroom.  Her backpack is large and looks like\n"+
               "heavy for the books she is carrying in.  She is probably worried about\n"+
               "the lessons of Physics and thus she is carrying several books in her\n"+
               "backpack.  She is tired after been awake all night long for studying.\n"+
               "Her tiny body hides a tough will.\n");
   set_level(10);
   set_hp(150);
   set_al(100);
   set_wc(14);
   set_ac(8);
 gold = clone_object("obj/money");
 gold->set_money(80 +random(50));
 move_object(gold,this_object());
 backpack = clone_object("/players/francesco/univ/items/backpack.c"); 
 move_object(backpack,this_object()); 
 
}
