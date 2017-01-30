#include "/players/khrell/ansi.h"
#include "/players/khrell/define.h"
inherit "obj/monster";
reset(arg)  {
  object gold;
  ::reset(arg);
  if(arg) return;
  set_name("a zombie dragon");
  set_short("A zombie dragon");
  set_alias("dragon");
  set_race("undead");
  set_long("     A vile animated corpse of a once proud dragon stands\n"+
           "here, it's rotted remains exude the charnel stench of death.\n"+
           "It's once mighty wings now are dried and cracked, great tears\n"+
           "and cracks have all but removed the powers of natural flight.\n"+
           "once covered in powerful scales now it's skin hangs loose and\n"+
           "ragged upon the bones of it's skeleton.\n");
  set_hp(2000);
  set_level(25);
  set_al(-1000);
  set_wc(50);
  set_ac(28);
  set_aggressive(2);
  set_heal(5,2);

  set_chat_chance(3);
  set_a_chat_chance(15);
  load_chat("The dragon looks at you with empty eye sockets.\n");
  load_chat("A clump of maggots squirm from a tear in the skin.\n");
  load_a_chat("The area gains a charnel stench of death.\n");

  set_chance(40);
  set_spell_dam(100);
  set_spell_mess1("The dragon breathes a stream of\n"+ 
  				  "                                                   \n"+							
  				  "                "RED+"\""+HIR+" \""+HIK+""    "|"+NORM+    +HIR+"/"+NORM+RED" /"+NORM                    "\n"+                        
  				  "                  "HIR+"\""+NORM+RED+" \""+HIK+"   |"+NORM+RED+"   /"+HIR" /                    \n"+
  				  ""           HIK+ "D E A T H"+NORM+"               \n"+
  				  "               "HIR+"   /"+NORM+RED+" /" +HIK+ "|"+NORM+RED+"   \""+HIR+" \""+NORM"                     \n"+
  				  "                "RED+" /"+HIR+" /"+HIK+"   |"+NORM+HIR+"    \""+RED" \                    \n"+
  				  "                                                   \n");
  
  set_spell_mess2("A bolt of "+GRN+"green death"+NORM+" slams into you, you can feel yourself being unmade.\n"+
                  "The smell of singed flesh permeates the air.\n");

  gold=clone_object("obj/money");
  gold->set_money(random(1000)+1000);
  move_object(gold,this_object());
}
