inherit "obj/monster";
   object gold;
   string follow;

reset(arg){
   ::reset(arg);
   if (arg) return;
   set_name("jasmina");
   set_race("human");
   set_alias("technician");
      set_short("Jasmina, the computer technician");
     set_long("This technician works all her time with the computers.  She\n"+
              "knows all the languages, from FORTRAN 77 to Pascal to LPC and\n"+
              "also many operating systems, WIN 95/98, Linux, MAC/OS and even\n"+ 
              "the old Commodore 64 BASIC.\n");

   set_level(19);
   set_hp(475);
   set_al(100);
   set_wc(28);
   set_ac(16);
 gold = clone_object("obj/money");
 gold->set_money(1900+random(200));
 move_object(gold,this_object());
 set_aggressive(1);
 call_out("follow_it",3);
}
follow_it() {
 
    object ob;
       if(!environment()) return;
        if(attacker_ob) {
          ob = attacker_ob;
          if(environment(ob) !=environment())
          {  if(creator(this_object()) == creator(environment(ob)))
           {  move_object(this_object(),environment(ob));
              say ("Jasmina arrives.\n");
           }
           }
    call_out("follow_it",4);
}

}
