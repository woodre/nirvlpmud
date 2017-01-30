inherit "obj/monster.c";
object weapon;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("lion");
set_alias("cat");
set_short("Lion");
set_long("Its is very big in size.  It is one of the most powerful of the\n"+
         "great cats.  Like most lions he has golden brown fur with a proud\n"+
         "mane flowing in the breeze.  He doesn't look happy.\n");
 set_al(0);
set_level(17);
set_wc(1);
set_ac(14);
/*  wtf.
  verte. 8.1.01
set_200(1);
*/
set_aggressive(1);
}
 
