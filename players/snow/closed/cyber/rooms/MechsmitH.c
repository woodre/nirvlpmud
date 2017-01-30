inherit "obj/monster";
 
   int a;
   string Name, name;
 
reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   a = random(9) + 1;
   if (a == 1) name = "gurag";
   if (a == 2) name = "ipedir";
   if (a == 3) name = "izzep";
   if (a == 4) name = "tran";
   if (a == 5) name = "slark";
   if (a == 6) name = "knifer";
   if (a == 7) name = "wors";
   if (a == 8) name = "nercor";
   if (a == 9) name = "petteno";
   set_name(name);
   set_race("human");
   set_alias(name);
   Name = capitalize(name);
   set_short(Name+", the mechsmith");
   set_long(Name+" does one thing and does it well. Making mechs\n"+
            "is his life. As much as he loves his creations, he\n"+
            "yearns to see them used. He eagerly awaits your order.\n");
   set_level(8);
   set_hp(random(20)+110);
   set_al(0);
   set_wc(13);
   set_ac(8);
   gold=clone_object("obj/money");
   gold->set_money(random(150)+150);
   move_object(gold,this_object());
}
 
 id(str)  {
  return str == "mechsmith" || str == "smith" ||
         str == name || str == Name;
 }
