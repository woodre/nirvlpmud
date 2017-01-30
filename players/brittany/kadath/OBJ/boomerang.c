#include "/players/brittany/ansi"
inherit "/obj/weapon";

int delay;
int actual_time;
reset(arg){
 ::reset();
if(arg)return;

message_hit = ({
         ""+HIR+"BUTCHERED"+NORM+""," into tiny fragments", /* massacre into small fragments */
         ""+HIW+"fissured","'s skin, slicing into the bone", /*  with a bone crushing */
         ""+HIW+"hit"+NORM+""," very hard",
         ""+HIW+"hit"+NORM+""," hard",
         ""+HIW+"NICKED"+NORM+""," slightly",
         ""+YEL+"TICKLED"+NORM+""," in the stomach",
});

set_name("boomerang");
set_alias("knife");
  set_short("A boomerang");
  set_long(
"This boomerang, has a sharp-edged knife on one side of\n"+
"it.  If you were to 'throw' it, you would slash deeply\n"+
"into your opponent with deadly precision.\n");
  set_weight(2);
  set_type("knife");
  set_class(17);
set_hit_func(this_object());
  set_value(875+random(200));
set_save_flag(1);
}

weapon_hit(attacker){
int W;
W = random(9);
if(W>7)  {
  say(
  "The boomerang spins wildly, slashing into its opponent.\n");
 
  write(
  "The boomerang "+HIW+" S  P  I  N  S "+NORM+ " wildly, slashing into its opponent.\n");
 
  return 5;
   }
return;
}
init() {
  ::init();
add_action("throw","throw");
}

query_no_fight(){
 if(environment(this_player())->query_no_fight())
  write("This is a no fight area.\n");
return 1;
}

throw(str){
object attacker;
attacker=this_player()->query_attack();
  if(this_player()->query_level() < 6) return 0;    

  if(wielded == 0){ write("You have not wielded the weapon!\n");
  return 1; }

  if(this_player()->query_sp() < 18){ write("You do not have enough sps.\n");
  return 1; }

  if(!attacker){ write("Sorry, but you are not fighting!\n");
  return 1; }

if(this_player()->query_spell_dam()) {
   write("You are already using energy to power a spell.\n");
   return 1; }

this_player()->spell_object(attacker,"throw boomerang",random(8)+5,10,
    "You throw the boomerang, it flies over and slashes your opponent deeply, then returns to your grip.\n",
     "You see the boomerang spinning wildly...zzzzzz   zzzzz  zzzz zzz...\n"+
     "towards you.. CLICK! sharp knives extend out, slashing you deeply, then returns.\n",
this_player()->query_name()+" throws the boomerang\n"+
attacker->query_name()+" is slashed by a spinning boomerang.\n");
}
