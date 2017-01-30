inherit "obj/weapon";
int i,x;
reset(arg) {
   ::reset(arg);
if(arg) return;
       set_alias("crossbow");
       set_name("Crossbow of Accuracy");
set_long("This crossbow in the hands of a skilled warrior can prove very fatal to your foes..\n");
         set_class(18);
         set_weight(3);
         set_value(10000);
       set_hit_func(this_object());
}
weapon_hit(attacker) {
/*  I dont think so - mythos <6-21-96> 
if(this_player()->query_alignment() > 750) {
*/
  x = 0;
if(random(3) == 0) {
say(this_player()->query_name() + "takes dead aim and fires an arrow straight into the heart of the monster!\n");
	write("You take dead aim and fire an arrow into the heart of the monster!!\n");
  /*
  i = random(15);
  x= 0;
  x= i + 10;
  */
  i = random(5);
  x = i + 5
}
   return x;
}
