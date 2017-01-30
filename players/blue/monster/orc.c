inherit"obj/monster";

int i,n;
object wep;
   object coins;

reset(arg) {

   ::reset(arg);


   if(!arg) {

   set_name("orc");
   set_level(2);
   set_hp(25);
   set_ac(3);
   set_al(-20);
   set_long("A nice orc.....wonder what the swords for?\n");
   set_short("An orc");

n = random(2);
wep=clone_object("obj/weapon");

if(n==0) {
     wep->set_name("knife");
     wep->set_class(6);
     wep->set_weight(1);
     wep->set_value(40);
     wep->set_short("A knife");
     wep->set_long("Just a cheap orc knife");
  }
if (n==1) {
     wep->set_name("club");
     wep->set_class(7);
     wep->set_weight(3);
     wep->set_value(100);
     wep->set_short("A club");
     wep->set_long("This is a club that only an orc could love");
  }

   move_object(wep, this_object());
   command("wield knife",this_object());
   command("wield club",this_object());
   coins=clone_object("obj/money");
   coins->set_money(20+random(20));
   move_object(coins, this_object());

  }
}
