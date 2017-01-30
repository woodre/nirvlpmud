inherit "obj/weapon";
int i;
reset(arg) {
   ::reset(arg);
   if(arg) return;
      set_alias("axe");
	set_name("Lochibur Axe");
    set_short("Lochibur Axe");
	set_long("A beatiful piece of craftsmanship, the handle extends three feet\n"+
	"into the blade. Which is deadly to say the least. This axe was crafted by the\n"+
	"skillful dwarf, Meritor.\n");
	set_class(18);
	set_weight(3);
	set_value(1000);
	
      set_hit_func(this_object());
}
weapon_hit(attacker) {
  i=random(10);
  if (i>5) {

	say(this_player()->query_name()+"'s Mighty Axe hits suprisingly hard!\n");
	write("You hit hard with your mighty Axe.\n");
  return 1;
    }
   return 0;
}
