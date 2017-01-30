inherit "obj/monster";

reset(arg)
{
  int num;
  object armor, gold;

num = 9000 + random(2000);
  ::reset(arg);
  if(arg) return;
        set_name("keeper");
        set_race("human");
        set_alias("keeper");
        set_short("A Bigelow Shop Keeper");
        set_long("The Shop Keeper watches you carefully to ensure you aren't\n"+
                "robbing him blind or anything. He seems mistrustful and is\n"+
                "liable to call a town guard at a moment's notice.\n");
        set_level(25);
        set_hp(850+random(250));
        set_al(250);
        set_wc(44);
        set_ac(23);
	gold = clone_object("obj/money");
	gold->set_money(num);
	move_object(gold,this_object());
	armor = clone_object("players/pain/NEW/arm/gloves");
	move_object(armor,this_object());
	init_command("wear gloves");
	set_wc(35);
        set_ac(20);
/* The above values for wc and ac were 17 and 10 respectively. I changed to make them
consistent with the values before wearing the gloves. - Snow 12/23/98 */
}
