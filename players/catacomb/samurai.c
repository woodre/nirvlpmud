inherit "obj/monster.c";
#define attacked (this_object()->query_attack())

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("samurai");
set_short("A kenjutsu samurai");
set_race("dragon");
set_long("  A samurai stands before you, trained in the art of\n"+
  	"kenjutsu.  Prepared to defend his emperor with the use \n"+
  	"of his razor sharp katana.\n");
   
set_level(12);
set_hp(180);
set_al(0);
set_ac(9);
set_wc(16);
set_aggressive(0);
add_money(550);
set_dead_ob(this_object());
}
 
monster_died(){
  tell_object(attacked,
  "As the kenjutsu warrior takes his last breath, he utters\n"+
  "If only I had practiced longer I could have done my emperor\n"+
  "honor.\n");
}   