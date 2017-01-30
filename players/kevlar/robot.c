inherit "obj/monster";
   object gold;

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Robot");
   set_race("robot");
   set_alias("robot");
	set_short("A hideous Electronic Robot");
	set_long("This is Kevlar's pet computer monster. He is a robot\n" +
	"made of leftover computer parts from the Lab of Doom and Pepsi-Cola.\n" +
	"Sparks fly from exposed wires in his joints as he glares at you.\n");
   set_level(30);
   set_hp(500);
   set_al(-1000);
   set_wc(30);
   set_ac(20);
}
