 
inherit "obj/monster.c";
object coin;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("art");
set_short("Art the blonde");
set_long("This is Art the blonde.  She is Thag's amphibian lova!\n");
set_al(-400);
set_level(20);
set_wc(888);
set_ac(999);
set_hp(999999);
set_aggressive(0);
coin=clone_object("obj/money");
coin->set_money(1000);
}
 
