inherit "/obj/monster";
#include "/sys/lib.h"

#include "/obj/ansi.h"

int heal, x;
object *stuff;

reset(arg) {
   ::reset(arg);
  if(arg) return;
set_name("goku");
set_short(HIK+"Goku"+NORM);
set_race("saiyan");
set_long(
"A formidable opponent, he is a Saiyan, one of the most powerful warriors\n"+
"of his time. He has saved planet Earth many times from the\n"+
"forces of evil.\n");
heal = 5;
set_level(25);
set_hp(1500+random(500));
set_wc(50);
set_ac(30+random(10));
set_heal(80,4);
set_al(1000);
add_spell("kamehameha",
"The "+HIC+"KaMeHaMeHa "+NORM+RED+"  CHARS "+NORM+"your chest\n",
"#MN# puts his hands to his side and screams "+HIK+"Ka-Me-Ha-Me-Ha "+NORM+"as\n"+
"a ball of white light screams forward\n",
15,"125-150","other|laser");

add_spell("kiblast",
"The "+HIC+"Ki Blast"+NORM+" burns your stomach!\n",
"#MN# puts his hands in front of him and a"+HIY+" Ki Blast"+NORM+"shoots from\n"+
"his hands.\n",
45,"35-50","other|fire");

add_spell("flare",
"There is a blinding"+HIY+" FLASH "+NORM+"of light from the "+HIY+"SOLAR FLARE!"+NORM+"\n",
"#MN# covers his eyes with both hands and shouts: "+HIY+"SOLAR FLARE!!!"+NORM+"\n",
25, "15-30", "other|laser");

add_spell("spiritbomb",
"A large "+HIC+" BALL "+NORM+" of pure energy increases in size until it "+HIC+" SURROUNDS "+NORM+" you!!!.\n",
"#MN# gathers a "+HIC+" Large Ball of ENERGY "+NORM+" above his head and hurls it\n"+
"towards you.\n",
5, "150-175","other|laser");

/*add_spell("heal_check", 0, 0, 100, 0, 0, 0, "heal_check");*/

}

void heal_check(object target, object room, int damage) {
  if(!environment()) return ;
	
  if(heal && (this_object()->query_hp() < 400)) {
    this_object()->heal_self(750);
    tell_room( environment(this_object()), 
      GRN+"Piccolo"+NORM+" screams as he sends out an "+HIY+"Energy Burst"+NORM+"!\n");
		add_spell("energy_burst", 0, 0, 100, "120-130", "other|energy", 5, "remove_energy_burst" );
		heal--;
  }
}

void remove_energy_burst(object target, object room, int damage) {
  remove_spell("energy_burst");
}

heart_beat() {
  if( attacker_ob )
    heal_check( attacker_ob );

  ::heart_beat();
}
