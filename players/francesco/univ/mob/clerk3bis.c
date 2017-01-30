inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   if (arg) return;
   set_name("marian");
   set_race("human");
   set_alias("librarian");
      set_short("Marian, the librarian");
     set_long("The librarian is very proud of what she did in order to keep the books\n"+
              "of the library easily accessible to the students and to the staff of\n"+
	      "the Department.  She is nice looking, nicely dressed and seems very\n"+
              "serious about her work.  Her physical aspect is what you always assumed\n"+
              "a librarian would look like:  short, well-maintained hair, thick glasses,\n"+
              "pale skin and short frame.  Even though she is close to retiring, she is\n"+
              "still a hard worker.\n");
   set_level(9);
   set_hp(140+random(30));
   set_al(100);
   set_wc(13);
   set_ac(8);
 gold = clone_object("obj/money");
 gold->set_money(420+random(70));
 move_object(gold,this_object());
   set_chat_chance(10);
   load_chat("Marian mumbles:  I like this job,  I like to help people raise their knowledge.\n");
   load_chat("Marian says:  If you want to enter the library, you should show your ID.\n");

}
