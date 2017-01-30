inherit "/obj/monster";
#include "/players/saber/closed/ansi.h"

reset(arg) {
   ::reset(arg);
   if (!arg) {

  object ob;
  int gem;

  if(random(4) < 1)  {
  for(gem = 0; gem < 5; gem++)  { 
  ob = clone_object("/players/saber/gems/ruby.c");
    move_object(ob,this_object());
        }
  }  else  {
  ob = clone_object("/players/saber/weapons/wind.c");
  move_object(ob,this_object());

  for(gem = 0; gem < 3; gem++)  { 
  ob = clone_object("/players/saber/gems/ruby.c");
    move_object(ob,this_object()); 
  }
  }

     set_name( "             " );
     set_short("             ");
     set_alias("air");
     set_race( "elemental");
     set_gender("creature");
     set_long("              is a creature composed entirely from living air.\n");
     set_level(20);
     set_ac(17);
     set_wc(30);
     set_hp(600);
     set_al(-950);
     set_aggressive(1);
     set_dead_ob(this_object());
     set_chat_chance(7);
     set_a_chat_chance(10);
     load_chat("              whistles through the air.\n");
     load_chat("              circles around the gem.\n");
     load_a_chat("              slams you with a fist of compressed air.\n");
     load_a_chat("              looks you in the eyes.\n");

set_spell_mess1(
"\nAwfully breezy around here...\n");
set_spell_mess2("\nGasp.  Choke.  Too much...\n"+HIB+
"  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~         ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~\n"+
"                                   A I R\n"+
"  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~         ~  ~  ~  ~  ~  ~  ~  ~  ~  ~  ~\n"+NORM);
     set_chance(15);
     set_spell_dam(30);
   }
  }

monster_died()  {
object ob;
  tell_room(environment(this_object()),
   "\n              explodes in burst of dead air.\n\n");
  return 0;
        }
