inherit "obj/monster";

   int a;
   string Name, name;

reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   a = random(9) + 1;
   if (a == 1) name = "snow";
   if (a == 2) name = "bloodmeister";
   if (a == 3) name = "thrasher";
   if (a == 4) name = "zixxus";
   if (a == 5) name = "death";
   if (a == 6) name = "dune";
   if (a == 7) name = "twila";
   if (a == 8) name = "darshiva";
   if (a == 9) name = "celesta";
   set_name(name);
   set_race("human");
   set_alias(name);
   Name = capitalize(name);
   set_short("Doctor "+Name+"");
   set_long(Name+" is perhaps one of the most brilliant doctors\n"+
         "and techno-scientists of the times.  With years of\n"+
         "secret study and surgical experimentation behind\n"+
         "this doctor's back, you can be confident that no\n"+
         "accident may occur.\n");
   set_level(7);
   set_hp(random(10)+100);
   set_al(0);
   set_wc(12);
   set_ac(7);
   gold=clone_object("obj/money");
   gold->set_money(random(150)+100);
   move_object(gold,this_object());
}

 id(str)  {
  return str == "doctor" || str == "doc" ||
         str == name || str == Name;
 }
