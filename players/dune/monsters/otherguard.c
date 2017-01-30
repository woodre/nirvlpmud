inherit "obj/monster";


int a;
string Name, name;


id(str)
{
  return str == "guard" || str == name || str == Name;
}


reset(arg)
{
   object gold;
   ::reset(arg);
   if(arg) return;
   a = random(9) + 1;
   if (a == 1) name = "inch";
   if (a == 2) name = "fengbald";
   if (a == 3) name = "guthwulf";
   if (a == 4) name = "john";
   if (a == 5) name = "luth";
   if (a == 6) name = "hoderund";
   if (a == 7) name = "bogey";
   if (a == 8) name = "leobardis";
   if (a == 9) name = "tonnrud";
   set_name(name);
   set_race("human");
   set_alias(name);
   Name = capitalize(name);
   set_short(Name+", the Tower guard");
   set_long(Name+" is a sturdy looking guard. His hands and face\n"+
         "look battle-worn, if not just plain ugly.\n"+
         "He looks like a true warrior.\n");
   set_level(13);
   set_hp(random(20)+185);
   set_al(0);
   set_wc(17);
   set_ac(10);
   set_aggressive(1);
   gold=clone_object("obj/money");
   gold->set_money(random(150)+650);
   move_object(gold,this_object());
}
