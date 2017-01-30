inherit "obj/monster";

reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("lea");
   set_short("Lea the Lythe");
   set_long("A beautiful elf, Lea has made her money from stealing from\n"+
            "the hands of evil.  Now she is at an impass and can't seem\n"+
            "to find her way.\n");
   set_level(6);
   set_hp(90);
   set_ac(5);
   set_wc(10);
   set_al(100);
   gold=clone_object("obj/money");
   gold->set_money(250);
}
