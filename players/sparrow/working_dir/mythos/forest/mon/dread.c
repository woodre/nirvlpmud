#include "/players/mythos/closed/guild/def.h"
inherit "players/mythos/closed/guild/spells/monster2";
reset(arg) {
::reset(arg);
  if(arg) return;
    set_name("dread");
    set_race("demon");
    set_alias("Dread");
    set_short(BOLD+"Dread"+NORM);
    set_long(HIK+"A being of Anti-life.  Black outer shell, teeth- razors,\n"+
             "and claws that whisper as they move through the air.\n"+
             "This Dread has been put here by the Hunter to guard\n"+
             "the Tome of Myrax.\n"+NORM);
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
    add_spell("aura",
              HIK+"A Black aura flares around the DREAD\n\n"+
              HIY+"                       B  O  O  M\n\n"+NORM+
              HIK+"Everything explodes around you!\n"+NORM,
              0,
              15,({25,25,51}),({"other|evil","other|dark",0}),1);
    add_spell("scream",
              "The Dream releases an ear-splitting SCREAM!\n",
              "The Dream S C R E A M S!!!!!!\n",
              50,40,"other|sonic",0);
    add_money(4000+random(5000));
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
