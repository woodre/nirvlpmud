inherit "/players/vertebraker/closed/std/monster.c";

#include "/players/pestilence/define.h"
#define attacker attacker_ob
int dif_sold;

reset(arg){
  ::reset(arg);
  if(arg) return;
set_race("animal");

switch(random(7)){
case 0:
    soldier9();
    break;

case 1:
    soldier9();
    break;
case 2:
    soldier10();
    break;
case 3:
    soldier12();
    break;
case 4:
    soldier13();
    break;
case 5:
    soldier10();
    break;
case 6:
    soldier9();
    break;
default:
    soldier9();
    break;
  }
}       

/* individual soldier varibles */                            
soldier9(){
dif_sold=1;
set_short("A sewer rat"+NORM+"");
set_long(
           "This is a fairly large rat.  It has very sharp teeth and brown hair.\n"+
           "Long whiskers extend outwards from the nose, and the eyes glow with a\n"+
           "dark red itensity.  This rat is commonly found in the sewers, where\n"+
           "it can feed on the things the people dont' want.\n");
set_name("sewer rat"+NORM+"");
set_alt_name("rat");
set_alias("rat");
set_level(16);
set_hp(300);
set_aggressive(1);
set_heal(4,2);
set_ac(13);
set_gender("creature");
set_wc(21+random(5));
set_al(0);
set_dead_ob(this_object());
set_chat_chance(20);
  load_chat("The rat tries to get out of the water.\n");
  load_chat("The rat nibbles on your feet.\n");
set_a_chat_chance(25);
  load_a_chat("Sewer rat leaps at you.\n");
set_chance(25);
set_spell_dam(25+random(20));
set_spell_mess1(
  "The sewer rat rips into it's attacker with it's sharp teeth.");
set_spell_mess2(
  "The sewer rat rips into you, with it's sharp teeth.");

}

soldier10(){
dif_sold=2;
set_short("A small crocodile");
set_long(
           "This is a small crocodile, most likely still very young.  It is about\n"+
           "five feet long.  For being young this animial is still very dangerous,\n"+
           "with all of the teeth projecting out of it's mouth.  The tail could do\n"+
           "some decent damage as well.  The large green scales provide for excellent\n"+
           "protection from attack.\n");
set_name("small crocodile");
set_alt_name("crocodile");
set_alias("croc");
set_level(17);
set_hp(400+random(100));
set_ac(14);
set_gender("male");
set_wc(22+random(6));

set_heal(6, 8);
set_al(0);
set_dead_ob(this_object());
set_chat_chance(20);
  load_chat("The crocodile lashes out at you.\n");
  load_chat("The crocodile searches for some food.\n");
set_a_chat_chance(25);
  load_a_chat("The crocodile looks very pissed off.\n");
  load_a_chat("The crocodile leaps at you, almost biting off your arm.\n");
set_chance(25);
set_spell_dam(30+random(20));
set_spell_mess1(
  "The small crocodile bites into it's attacker, causing "+HIR+"blood"+NORM+" to splatter all over.");
set_spell_mess2(
  "The small crocodile bites into you, causing "+HIR+"blood"+NORM+" to splatter all over.");


}

soldier12(){
dif_sold=3;
set_short("A large Crocodile");
set_long(
           "This is a large crocodile.  It is about 15 feet from it's head to it's\n"+
           "tail.  Very large teeth protrude from it's mouth.  Large green scales\n"+
           "extend down it's back.\n");
set_name("large crocodile");
set_alt_name("crocodile");
set_alias("croc");
set_level(19);
set_hp(550+random(100));
set_ac(16);
set_gender("male");
set_wc(22+random(15));
set_aggressive(0);
set_heal(5, 10);
set_al(0);
set_dead_ob(this_object());
set_chat_chance(20);
  load_chat("The crocodile spins around in the shallow water.\n");
  load_chat("The crocodile attempts to bite you.\n");
set_a_chat_chance(25);
  load_a_chat("The crocodile swings it's tail at you.\n");
  load_a_chat("The crocodile splashes water, attempting to blind you.\n");
set_chance(25);
set_spell_dam(35+random(25));
set_spell_mess1(
  "The large crocodile swings it tail fast and hard.\n"+
  "The tail "+HIR+" OBLITERATES"+NORM+" it's attacker.\n");
set_spell_mess2(
  "The large crocodile swings it tail fast and hard.\n"+
  "The tail "+HIR+" OBLITERATES"+NORM+" it's you.\n");
}
soldier13(){
dif_sold=4;
set_short("water snake");
set_long(
           "This is a very dangerous water viper.  This snake is about seven\n"+
           "feet long.  It isn't poisonous, but it has very strong constricting\n"+
           "power.  It's skin is scaley, with brown and black markings.\n");
set_name("water snake");
set_alt_name("snake");
set_alias("snake");
set_level(18);
set_hp(300+random(100));
set_ac(15);
set_gender("male");
set_wc(22+random(10));
set_al(0);
set_dead_ob(this_object());
set_chat_chance(20);
  load_chat("The snake slithers on top of the water.\n");
  load_chat("The snake tries to wrap itself around your leg.\n");
set_a_chat_chance(25);
  load_a_chat("The snake dives under the water.\n");
  load_a_chat("The snake slithers around.\n");
set_chance(25);
set_spell_dam(30+random(25));
set_spell_mess1(
  "The snake wraps itself around it's attacker\n"+
  ""+CYN+"Squeezing"+NORM+" the life out of them.\n");
set_spell_mess2(
  "The snake wraps itself around it's you\n"+
  ""+CYN+"Squeezing"+NORM+" the life out of you.\n");

}
monster_died() {
if(dif_sold == 1) {  tell_room(environment(this_object()),
        "As the rat dies, its whiskers fall from its head.\n"),
  move_object(clone_object("/players/pestilence/club/obj/whiskers.c"),
      environment(this_object()));
return 1;
}

if(dif_sold == 2) {  tell_room(environment(this_object()),
        "You quickly skin the small crocodile, as it dies.\n"),
  move_object(clone_object("/players/pestilence/club/obj/scskin.c"),
      environment(this_object()));
return 1;
}

if(dif_sold == 3) {  tell_room(environment(this_object()),
"You swiftly skin the crocodile, as it dies..\n"),
  move_object(clone_object("/players/pestilence/club/obj/lcskin.c"),
      environment(this_object()));
return 1;
}

if(dif_sold == 4) {  tell_room(environment(this_object()),
        "As the snake dies, its skin falls off its body.\n"),
  move_object(clone_object("/players/pestilence/club/obj/snakeskin.c"),
      environment(this_object()));
return 1;
}
}
