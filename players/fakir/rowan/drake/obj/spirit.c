
/*
 * Spirit (4/30/94)
 */

inherit "players/molasar/rowan/obj/monster";

reset(arg) {
   if(arg)
     return;
   set_name("spirit");
   set_alias("ariand");
   set_short("The spirit of Lord Ariand");
   set_long("This the the trapped spirit of Lord Ariand.\n"+
   "Except for it's transparency it looks exactly like the late Lord\n"+
   "Ariand in every way.\n");
   set_level(30);
   set_wc(30);
   set_ac(15);
   set_hp(700);
   set_aggressive(1);
   set_al(-750);
   set_regular_chance(30);
   set_single_chance(40);
   set_single_dam(40);
   set_single_mess1("The spirit casts a ray of frost!\n");
   set_single_mess2("Your skin tingles as it's covered in ice!\n");
   set_multiple_chance(30);
   set_number_of_attacks(6);
   set_multiple_dam(15);
   set_multiple_mess1("Magical darts fly from the spirits hands!\n");
   set_multiple_mess2("Your are struck by a dart!\n");
   set_dead_ob(this_object());
   ::reset();
}

#define TELL(x) tell_room(environment(this_object()), x)

monster_died(ob) {
   object money, armor;

TELL("A thunder boom sounds as the spirit dissipates into a fine mist.\n");   
TELL("The shock waves cause part of the throne to fall away. A number\n");
TELL("of hidden items spill out of the break.\n");
call_other("/players/molasar/rowan/obj/tr_gen","get_magic2",environment(ob));
call_other("/players/molasar/rowan/obj/tr_gen","get_magic2",environment(ob));
call_other("/players/molasar/rowan/obj/tr_gen","get_magic2",environment(ob));
call_other("/players/molasar/rowan/obj/tr_gen","get_magic3",environment(ob));
call_other("/players/molasar/rowan/obj/tr_gen","get_scroll1",environment(ob));
call_other("/players/molasar/rowan/obj/tr_gen","get_scroll1",environment(ob));
call_other("/players/molasar/rowan/obj/tr_gen","get_scroll1",environment(ob));
money = clone_object("obj/money");
money->set_money(10000+random(5000));
move_object(money, environment(this_object()));
return 0;
}


