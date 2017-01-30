inherit "obj/monster.c";
reset(arg) {
  ::reset(arg);
  if(!arg) {
object gold;
 set_name("elephant");
 set_short("A large, overweight elephant");
 set_long("This is a military elephant. He stands at attention\n"+
          "with his feet together and his trunk extended for\n"+
          "inspection.\n");
  set_level(10);
 set_ac(8);
 set_wc(14);
 set_hp(150);
gold=clone_object("obj/money");
gold->set_money(90);
move_object(gold, this_object());
 }
}
