#include "/players/saber/closed/esc.h"
#include <ansi.h>
#define ATT capitalize(attacker->query_name())
#define tp this_player()->query_name()
int a, w;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;

set_name("Earth Spellbook");
set_alias("earth");
set_type("exotic");
set_alt_name("spellbook");
set_short(WHT+"Magical SpellBook"+NORM+" <"+YEL+"earth"+NORM+">");
set_long("The knowledge and mastery of the Master Monk Kaya. She\n"+
         "developed this fighting style called the Pouncing Kitten.\n"+
         "You can destroy the kung fu by typing <kung fu gone>\n");
set_class(20);
set_weight(2);
set_value(4500+random(2000));
set_hit_func(this_object());
}

query_save_flag() {return 1; }

weapon_hit(attacker){
string SPELLMSG;
string here;
string color, backstr;
string gender,gender2,ogender,ogender2;
   w=random(25);
   a=random(4);
ogender2 = attacker->query_objective();
ogender = attacker->query_possessive();
gender = this_player()->query_possessive();
here = environment(this_player());

}

init()  {
  ::init();
add_action("spell_list","spells");
        }

