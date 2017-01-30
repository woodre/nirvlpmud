#include "/players/cosmo/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name(HIY+"Frank"+NORM);
set_alias("frank");
set_alt_name("castanza");
set_race("human");
set_short("Mr. Frank Castanza");
set_long(
  "  The father of George Castanza, Frank is very different\n"+
  "from his son.  Typically loud, mean, and grouchy, Mr. C\n"+
  "rarely has a kind word to say.  He's yelled at George all\n"+
  "of his life for not having a solid job and for still living\n"+
  "at home.  You may also remember Frank for his roles in the\n"+
  "Nike commercials where he stars as Vince Lombardi.\n");

set_level(11);
  set_hp(200);
  set_al(-100);
  set_wc(9);
  set_ac(13);
  set_heal(3,20);
  set_aggressive(1);
  set_dead_ob(this_object());

set_a_chat_chance(15);
  load_a_chat("Frank yells: What are you doing in my house?\n"+
              "             Estelle, help me get rid of this trash.\n");

set_chance(10);
set_spell_dam(30);

set_spell_mess1(
  "\nMr. Castanza throws his arms up in the air.\n");
set_spell_mess2(
  "\nFrank evades your attack and then deftly grabs a vase.\n"+
  "He hurls the vase through the air and it crashes down hard\n"+
  "right on your forehead.     "+YEL+"OOOUUUUCCCCHHHH!!!!!!"+NORM+"\n");

gold = clone_object("obj/money");
gold->set_money(500+random(50));
move_object(gold,this_object());
}

monster_died() {
  if(present("estelle", environment())){
    tell_room(environment(),
	"Estelle begins to cry hysterically. "+BLU+"'What have you\n"+
        "done to my poor Frankie??'"+NORM+"\n"); }
  else {
    tell_room(environment(),
        "The room suddenly becomes very silent.\n"); }
return 0; }

