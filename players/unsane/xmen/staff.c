#include <ansi.h>
#define tp this_player()->query_name()
 inherit "obj/weapon.c";
object ob;
int w, charges;
 reset(arg) {
    ::reset(arg);
charges = 1 + random(3);
  /* changed the charges from 7 to 1 rnd 3... mythos <1-17-98> */
    if(arg)  return;
set_name("staff");
   set_alias("storm's staff");
set_short("Storm's Staff");
set_long("When you examine this staff you notice a button that says....\n"+
"'Call Lightning'.  So that's how she did that!\n");
   set_class(18);
   set_weight(2);
   set_value(3000);
   set_hit_func(this_object());
}
init(){
::init();
add_action("push","push");
add_action("push","press");
}
push(str) {
string a,b;
  if(!str) return 0; /* verte */
if (sscanf(str,"%sbutton%s",a,b) == 2) {
if (charges < 1) {
write("You are out of charges.\n");
charges -= 1;
  destruct(this_object()); /* added this in to semi-stop the save reset thing players do - mythos <12-8-96> */
return 1;}
ob = this_player()->query_attack();
if (!ob) return (write("You must be attacking something.\n"), 1);
if (ob->is_player()) {write("I'm afraid you can't fry players.\n"); return 1;}
if (ob) {
write("You call " + HIC + "lightning" + NORM + " down on your foe!\n");
say(tp+" summons the power of " + HIC + "lightning" + NORM + "!\n");
charges -= 1;
this_player()->add_spell_point(-20);
/* :D lightning from org hit_player() BORING */
ob->hit_player(random(20), "other|electric");
}
else write("You are not in battle!\n");
}
else write("Push what?\n");
return 1;
}
weapon_hit(attacker){
         w = random(20);
  if(w>18) {
say(tp+" hits their foe with a tornado!\n");
write("You throw a hurricane at your foe!\n");
attacker->hit_player(random(4), "other|wind");
/*
return 4;
*/
}
    return;
}
