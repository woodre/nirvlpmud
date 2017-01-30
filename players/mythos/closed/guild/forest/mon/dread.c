#include "/players/mythos/closed/guild/def.h"
inherit "players/mythos/closed/guild/spells/monster2";
reset(arg) {
::reset(arg);
  if(arg) return;
    set_name("dread");
    set_race("demon");
    set_alias("Dread");
    set_short(BOLD+"Dread"+NORM);
    set_long("A being of Anti-life.  Black outer shell, teeth- razors,\n"+
             "and claws that whisper as they move through the air.\n"+
             "This Dread has been put here by the Hunter to guard\n"+
             "the Tome of Myrax.\n");
    set_al(-1000);
    set_hp(2000);
    set_level(40);
    set_wc(50);
    set_ac(20);
    set_aggressive(1);
    set_chat_chance(10);
    set_a_chat_chance(10);
    load_chat(".....energy....is...sucked....away....\n");
    load_chat("The Dread Lord moves closer to you.\n");
    load_a_chat("The Dread screams in anger!\n");
    load_a_chat("The Dread lashes out!\n");
    set_mass_chance(15);
    set_mass_dam(random(100)+1);
    set_mass_spell("A Black aura flares around the DREAD\n\n"+
                   HIB+"                       B  O  O  M\n\n"+NORM+
                   "Everything explodes around you!\n"); 
    set_chance(50);
    set_spell_dam(40);
    set_spell_mess1("The Dread screams!\n");
    set_spell_mess2("The Dread releases an ear-splitting SCREAM!\n");
    set_mult(3);
    set_mult_chance(50);
    set_mult_dam1(1);
    set_mult_dam2(40);
    move_object(clone_object("/players/mythos/closed/guild/forest/misc/key_myrax.c"),
         this_object()); 
    call_out("gas",5);
}

gas() {
object ox;
int nu, n;
  if(!environment(this_object())) return 1;
  n = 0;
  ox = all_inventory(environment(this_object()));
  for(nu=0;nu<sizeof(ox);nu++) {
    if(living(ox[nu]) && ox[nu] != this_object()) {
      ox[nu]->heal_self(-random(3));
      n = 1;
    }
  }
  if(n) {
  tell_room(environment(this_object()),"The gaseous fumes in the air hurts your throat...\n");
  }
call_out("gas",5);
return 1; }
