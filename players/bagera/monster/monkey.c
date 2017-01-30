inherit "obj/monster.c";
reset(arg) {
  ::reset(arg);
  if(!arg) {
     object gold;
gold=clone_object("obj/money");
gold->set_money(150+random(150));
move_object(gold, this_object());
 set_name("monkey");
set_short("Monkey");
 set_long("This is a scrawny little monkey. He is swinging from\n"+
          "the vines hanging from the ceiling.\n");
  set_level(7);
 set_ac(6);
 set_wc(11);
 set_hp(105);
 }
}
