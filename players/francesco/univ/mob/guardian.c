inherit "obj/monster";
   object gold;
reset(arg){
   ::reset(arg);
   if (arg) return;
   set_name("bill");
   set_race("human");
   set_alias("guardian");
      set_short("Bill, the guardian of the university");
     set_long("Bill is always smiling towards anyone who might enter the University.\n"+
              "He has been appointed to this position since several years and\n"+
              "therefore he has seen hundreds of students, professors and visitors\n"+
              "climbing the stair.  Noone ever attacked him because he is really\n"+
              "a friend to everyone.  Unless his old age, he still looks like in\n"+
              "good health and his tall body well fits his role.\n");

   set_level(10);
   set_hp(150);
   set_al(300);
   set_wc(14);
   set_ac(8);
 gold = clone_object("obj/money");
 gold->set_money(360+random(150));
 move_object(gold,this_object());
}
