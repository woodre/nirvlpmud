inherit "obj/monster";

reset(arg)
{
  int num;
  object gold;

num = 2050 + random(2000);
  ::reset(arg);
  if(arg) return;
        set_name("keeper");
        set_race("elf");
        set_alias("keeper");
        set_short("An Elven Shop Keeper");
        set_long("The Shop Keeper watches you carefully to ensure you aren't\n"+
                "robbing him blind or anything. He seems mistrustful and is\n"+
                "liable to call a flet guard at a moment's notice.\n");
        set_level(25);
        set_hp(500+random(250));
        set_al(250);
        set_wc(35);
        set_ac(20);
	gold = clone_object("obj/money");
	gold->set_money(num);
	move_object(gold,this_object());
	set_wc(17);
        set_ac(10);
}
