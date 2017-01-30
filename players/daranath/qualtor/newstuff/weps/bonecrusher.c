#include <ansi.h>
#define tp this_player()->query_name()
#define targ capitalize(attacker->query_name())
#define gender this_player()->query_possessive();
 inherit "obj/weapon.c";
int a;

 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("Bonecrusher");
set_type("maul");
set_alias("bonecrusher");
set_short(BOLD+BLK+"BoneCrusher"+NORM);
set_long("According to legend, this massive maul was used by Tauros, the first\n"+
         "to unite the Minotaur tribes under a single banner in their\n"+
         "quest to destroy Qual'tor. Although simple in design -- a large\n"+
         "cylinder of steel attached to a leather-wrapped handle -- \n"+
         "it is a devastating weapon. There seems to be runes running\n"+
         "down its side.\n");
set_read("Made for Tauros, to conquer Qual'tor and the Realms of Nirvana.\n");
set_class(20);
set_weight(3);
set_value(4250);
set_hit_func(this_object());
}

query_save_flag() {return 1; }

weapon_hit(attacker){
string here;
a = random(4);
here = environment(this_player());

if(a == 0){
tell_room(here,
 tp+" slams "+BLK+BOLD+"BoneCrusher"+NORM+" down into the ground, knocking\n"+
   targ+" off balance with the blow.\n");
if(call_other(this_player(),"query_attrib","str") > random(50)) {
  return 7; }
}
if(a == 1){
tell_room(here,
 "\n"+tp+" swings "+BLK+BOLD+"BoneCrusher"+NORM+" high over "+this_player()->query_possessive()+" head, bringing\n"+
     "the mighty Maul down upon "+this_player()->query_possessive()+" foe.\n\n");
if(call_other(this_player(),"query_attrib","str") > random(50)) {
  return 5; }
}
if(a > 1){
tell_room(here,
  tp+" pummels "+this_player()->query_possessive()+" foe with "+BLK+BOLD+"BoneCrusher"+NORM+"!\n");
}
}
