#include "/players/wocket/closed/ansi.h"
inherit "/obj/weapon.c";
object player;

reset(arg){
  set_alias("bow");
  set_alias("pro_object");
  set_id("bow");
  set_short(HIR+"Bow of the Angels"+NORM);
  set_long("Light shines from the bow so intensely that you cannot look \n"+
  "directly upon it.  It seems to be made from a heavy wood\n"+
  "but is fairly easy to carry.  The grip is\n"+
  "nice and soft and the string wond very taunt.\n");
  set_hit_func(this_object());
  set_value(50000);
  set_weight(4);
  set_type("bow");
  set_class(0);
}


init(){
::init();
  if(environment(this_object())->is_player()){
  player = this_player();
  }
}

weapon_hit(att){
string ATTN;
string msg1,msg2,msg3;
ATTN = att->query_name();
switch(random(7)){
case 0: msg1 = HIB+"You draw back your bow and fire an arrow through the air.\n"+OFF;
break;
case 1: msg1 = HIB+"You take aim upon "+ATTN+" and release your string.\n"+NORM;
break;
case 2: msg1 = HIB+"Your arrow glows bright white as it fires into "+ATTN+".\n"+OFF;
player->add_spell_point(-3);
break;
case 3:  msg1 = HIB+"You draw back your bow in fear.\n"+OFF;
player->heal_self(-2);
break;
case 4:  msg1= HIB+"Your arrow peirces through the armor of "+ATTN+".\n"+OFF;
break;
case 5:  msg1 = HIB+"Your arrow ignites with holy fire.\n"+OFF+"You feel drained.\n";
player->add_spell_point(-5);
break;
case 6: msg1 = HIB+"Your arrow rips through "+ATTN+".\n"+OFF;
break;
default: break;
}
write(msg1);
return ;
}
query_pro_weapon(){ return 1; }
proficiency_hit(){
int damage;
int percent;
int i;
i = environment(this_object())->query_attrib("str");
percent = (player->query_hp()*10)/player->query_mhp();
damage = ((i+20)*percent)/10;
player->set_ac(2);
player->add_hit_point(-random(10));
return damage;
}
