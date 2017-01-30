#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster.c";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;

  move_object(clone_object("/players/pestilence/club/arm/gstring.c"),
        this_object());
  command("wear g-string");
  set_name("destinee"); 
  set_alias("stripper");
  set_short("Destinee the stripper");
set_long("Destinee is 5 foot tall, and weighs around 110.  She has long wavy\n"+
         "brown hair with bright green eyes.  Her skin is smooth looking.  Her\n"+
         "body is one the best looking bodies you have ever seen.  Her measurements\n"+
         "are 36-23-35.");
  set_race("human");
  set_gender("female");
  set_level(19);
  set_wc(28);
  set_ac(16);
  set_hp(450);
  set_heal(5,4);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(0);
  load_chat("Destinee says: Come on baby give me a dollar and I will show you my ass.\n");
  load_chat("Destinee rubs up against you, pushing her tits in your face.\n");
  load_chat("Destinee pushes her ass against your crotch and starts to grind.\n");
  set_chat_chance(20);
  load_a_chat("Destinee says: if you don't kill me maybe i will give you oral treats.\n");
  load_a_chat("Destinee moans erotically.\n");
  load_a_chat("Destinee scratches you with her pierced labia.\n");
  set_a_chat_chance(30);
set_spell_mess2("Destinee's labia piercing "+RED+"gouges you drawing blood"+NORM+".\n");
set_spell_mess1("Destinee's labia piercing "+RED+"gouges her attacker, drawing blood"+NORM+".\n");
  set_chance(20);
  set_spell_dam(15);
}

monster_died() {
  move_object(clone_object("/players/pestilence/club/obj/money.c"),
      environment(this_object()));
  move_object(clone_object("/players/pestilence/club/obj/money.c"),
      environment(this_object()));
  move_object(clone_object("/players/pestilence/club/obj/money.c"),
      environment(this_object()));
  move_object(clone_object("/players/pestilence/club/obj/money.c"),
      environment(this_object()));
  move_object(clone_object("/players/pestilence/club/obj/money.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
        "As Destinee falls to the floor, you hear her say: All i wanted to do was fuck.\n");
return 0; }
