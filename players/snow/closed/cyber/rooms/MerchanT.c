inherit "obj/monster";

   int a;
   string Name, name;

reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   a = random(9) + 1;
   if (a == 1) name = "rogue";
   if (a == 2) name = "blackbeard";
   if (a == 3) name = "bluechip";
   if (a == 4) name = "sampson";
   if (a == 5) name = "derilict";
   if (a == 6) name = "einstein";
   if (a == 7) name = "parallax";
   if (a == 8) name = "bigboom";
   if (a == 9) name = "estrella";
   set_name(name);
   set_race("human");
   set_alias(name);
   Name = capitalize(name);
   set_short(Name+", the merchant");
   set_long(Name+" knows every trick of the trade.  All items\n"+
         "provided by yours truly come from not quite legal\n"+
         "organizations, but hey, who cares.  As long as you get\n"+
         "a great bargain.\n");
   set_level(8);
   set_hp(random(15)+110);
   set_al(0);
   set_wc(14);
   set_ac(8);
   gold=clone_object("obj/money");
   gold->set_money(random(150)+200);
   move_object(gold,this_object());
}

 id(str)  {
  return str == "merchant" || str == "Merchant" ||
         str == name || str == Name;
 }
