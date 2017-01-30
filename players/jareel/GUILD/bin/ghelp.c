#include "/players/jareel/GUILD/defs.h"

main(str) {
  write("\n");
  write(HIM+"\tKnowledge flows into your mind...\n"+NORM+BLU+BOLD);
  if(!str) {
    cat("/players/jareel/GUILD/help/general.txt");
    write("\n"+NORM); return 1; }
  if(str == "drawbacks"){cat("/players/jareel/GUILD/help/drawbacks.txt");
    write("\n"+NORM); return 1;}
  if(str == "general2"){cat("/players/jareel/GUILD/help/general2.txt");
    write("\n"+NORM); return 1;}
  if(str == "specialty guilds"){cat("/players/jareel/GUILD/help/specialty_guild.txt");
    write("\n"+NORM); return 1;}
  if(str == "rules"){cat("/players/jareel/GUILD/help/rules.txt");
    write("\n"+NORM); return 1;}
  if(str == "healing"){cat("/players/jareel/GUILD/help/healing.txt");
    write("\n"+NORM); return 1;}
  if(str == "leaveguild"){cat("/players/jareel/GUILD/help/leaveguild.txt");
    write("\n"+NORM); return 1;}
  if(str == "alignment"){cat("/players/jareel/GUILD/help/alignment.txt");
    write("\n"+NORM); return 1;}
  if(str == "transfuse"){cat("/players/jareel/GUILD/help/transfuse.txt");
    write("\n"+NORM); return 1;}
  if(str == "bladesharp"){cat("/players/jareel/GUILD/help/bladesharp.txt");
    write("\n"+NORM); return 1;}
  if(str == "bludgeon"){cat("/players/jareel/GUILD/help/bludgeon.txt");
    write("\n"+NORM); return 1;}
  if(str == "progood"){cat("/players/jareel/GUILD/help/progood.txt");
    write("\n"+NORM); return 1;}
  if(str == "proevil"){cat("/players/jareel/GUILD/help/proevil.txt");
    write("\n"+NORM); return 1;}
  if(str == "demoralize"){cat("/players/jareel/GUILD/help/demoralise.txt");
    write("\n"+NORM); return 1;}
  if(str == "disrupt"){cat("/players/jareel/GUILD/help/disrupt.txt");
    write("\n"+NORM); return 1;}
  if(str == "befuddle"){cat("/players/jareel/GUILD/help/befuddle.txt");
    write("\n"+NORM); return 1;}
  if(str == "coordination"){cat("/players/jareel/GUILD/help/coordination.txt");
    write("\n"+NORM); return 1;}
  if(str == "countermagic"){cat("/players/jareel/GUILD/help/ocountermagic.txt");
    write("\n"+NORM); return 1;}
  if(str == "fanaticism"){cat("/players/jareel/GUILD/help/fanaticism.txt");
    write("\n"+NORM); return 1;}
  if(str == "fire arrow"){cat("/players/jareel/GUILD/help/fire_arrow.txt");
    write("\n"+NORM); return 1;}
  if(str == "fire blade"){cat("/players/jareel/GUILD/help/fire_blade.txt");
    write("\n"+NORM); return 1;}
  if(str == "ice maul"){cat("/players/jareel/GUILD/help/ice_maul.txt");
    write("\n"+NORM); return 1; }
  if(str == "invisibility"){cat("/players/jareel/GUILD/help/invisibility.txt");
    write("\n"+NORM); return 1;}
  if(str == "light"){cat("/players/jareel/GUILD/help/light.txt");
    write("\n"+NORM); return 1;}
  if(str == "mindspeech"){cat("/players/jareel/GUILD/help/mindspeech.txt");
    write("\n"+NORM); return 1;}
  if(str == "protection"){cat("/players/jareel/GUILD/help/protection.txt");
    write("\n"+NORM); return 1;}
  if(str == "forge"){cat("/players/jareel/GUILD/help/forge.txt");
    write("\n"+NORM); return 1;}
  if(str == "spirit shield"){cat("/players/jareel/GUILD/help/spirit_shield.txt");
    write("\n"+NORM); return 1;}
  if(str == "vigor"){cat("/players/jareel/GUILD/help/vigor.txt");
    write("\n"+NORM); return 1;}
  if(str == "dual wielding"){cat("/players/jareel/GUILD/help/dual_wield.txt");
    write("\n"+NORM); return 1;}
  if(str == "double strike"){cat("/players/jareel/GUILD/help/double_strike.txt");
    write("\n"+NORM); return 1;}
  if(str == "critical strike"){cat("/players/jareel/GUILD/help/criticle_strike.txt");
    write("\n"+NORM); return 1;}
  if(str == "impale strike"){cat("/players/jareel/GUILD/help/impale_strike.txt");
    write("\n"+NORM); return 1;}
  if(str == "weapon special"){cat("/players/jareel/GUILD/help/weapon_special.txt");
    write("\n"+NORM); return 1;}
  if(str == "weapons"){cat("/players/jareel/GUILD/help/weapons.txt");
    write("\n"+NORM); return 1;}
  if(str == "parry"){cat("/players/jareel/GUILD/help/parry.txt");
    write("\n"+NORM); return 1;}
  if(str == "block"){cat("/players/jareel/GUILD/help/parry.txt");
    write("\n"+NORM); return 1; }
  if(str == "dodge"){cat("/players/jareel/GUILD/help/dodge.txt");
    write("\n"+NORM); return 1;}
  if(str == "alchemy"){cat("/players/jareel/GUILD/help/alchemy.txt");
    write("\n"+NORM); return 1;}
  if(str == "acid"){cat("/players/jareel/GUILD/help/acid.txt");
    write("\n"+NORM);
    write(NORM+BOLD+BLINK+"       W A R N I N G: Brewing Acid and or Poisen may Hazadouse to your health.\n"+NORM); 
    return 1;}
  if(str == "poisen"){cat("/players/jareel/GUILD/help/acid.txt");
    write("\n"+NORM); return 1;}
  if(str == "ahealing"){cat("/players/jareel/GUILD/help/ahealing.txt");
    write("\n"+NORM); return 1;}
  if(str == "language"){cat("/players/jareel/GUILD/help/language.txt");
    write("\n"+NORM); return 1;}
  if(str == "storm tounge"){cat("/players/jareel/GUILD/help/storm_tounge.txt");
    write("\n"+NORM); return 1;}
  if(str == "earth tounge"){cat("/players/jareel/GUILD/help/earth_tounge.txt");
    write("\n"+NORM); return 1;}
  if(str == "fire speech"){cat("/players/jareel/GUILD/help/fire_speech.txt");
    write("\n"+NORM); return 1;}
  if(str == "lunar tounge"){cat("/players/jareel/GUILD/help/luner_tounge.txt");
    write("\n"+NORM); return 1;}
  if(str == "camouflage"){cat("/players/jareel/GUILD/help/camoflage.txt");
    write("\n"+NORM); return 1;}
  if(str == "move silently"){cat("/players/jareel/GUILD/help/move_silently.txt");
    write("\n"+NORM); return 1;}
  if(str == "armor specials"){cat("/players/jareel/GUILD/help/armor_special.txt");
    write("\n"+NORM); return 1;}
  if(str == "armor"){cat("/players/jareel/GUILD/help/armors.txt");
    write("\n"+NORM); return 1;}
  if(str == "rune"){cat("/players/jareel/GUILD/help/rune.txt");
    write("\n"+NORM); return 1; }
  if(str == "death rune"){cat("/players/jareel/GUILD/help/death_rune.txt");
    write("\n"+NORM); return 1;}
  if(str == "chaos rune"){cat("/players/jareel/GUILD/help/chaos_rune.txt");
    write("\n"+NORM); return 1;}
  if(str == "moon rune"){cat("/players/jareel/GUILD/help/moon_rune.txt");
    write("\n"+NORM); return 1;}
  if(str == "darkness rune"){cat("/players/jareel/GUILD/help/darkness_rune.txt");
    write("\n"+NORM); return 1;}
  if(str == "water rune"){cat("/players/jareel/GUILD/help/water_rune.txt");
    write("\n"+NORM); return 1;}
  if(str == "earth rune"){cat("/players/jareel/GUILD/help/earth_rune.txt");
    write("\n"+NORM); return 1;}
  if(str == "air rune"){cat("/players/jareel/GUILD/help/air_rune.txt");
    write("\n"+NORM); return 1;}
  if(str == "fire rune"){cat("/players/jareel/GUILD/help/fire_rune.txt");
    write("\n"+NORM); return 1;}
  if(str == "sky rune"){cat("/players/jareel/GUILD/help/sky_rune.txt");
    write("\n"+NORM); return 1;}
  if(str == "plant room"){cat("/players/jareel/GUILD/help/plant_rune.txt");
    write("\n"+NORM); return 1;}
  if(str == "beast rune"){cat("/players/jareel/GUILD/help/beast_rune.txt");
    write("\n"+NORM); return 1;}
  if(str == "man rune"){cat("/players/jareel/GUILD/help/man_rune.txt");
    write("\n"+NORM); return 1;}
  if(str == "dragonewt rune"){cat("/players/jareel/GUILD/help/dragonewt_rune.txt");
    write("\n"+NORM); return 1;}
  if(str == "spirit rune"){cat("/players/jareel/GUILD/help/spirit_rune.txt");
    write("\n"+NORM); return 1; }
  if(str == "mastery rune"){cat("/players/jareel/GUILD/help/mastery_rune.txt");
    write("\n"+NORM); return 1;}
  if(str == "disorder rune"){cat("/players/jareel/GUILD/help/disorder_rune.txt");
    write("\n"+NORM); return 1;}
  if(str == "fertility rune"){cat("/players/jareel/GUILD/help/fertility_rune.txt");
    write("\n"+NORM); return 1;}
  if(str == "stasis rune"){cat("/players/jareel/GUILD/help/stasis_rune.txt");
    write("\n"+NORM); return 1;}
  if(str == "movement rune"){cat("/players/jareel/GUILD/help/movement_rune.txt");
    write("\n"+NORM); return 1;}
  if(str == "truth rune"){cat("/players/jareel/GUILD/help/truth_rune.txt");
    write("\n"+NORM); return 1;}
  if(str == "illusion rune"){cat("/players/jareel/GUILD/help/illusion_rune.txt");
    write("\n"+NORM); return 1;}
  if(str == "luck rune"){cat("/players/jareel/GUILD/help/luck_rune.txt");
    write("\n"+NORM); return 1;}
  if(str == "fate rune"){cat("/players/jareel/GUILD/help/fate_rune.txt");
    write("\n"+NORM); return 1;}
  if(str == "heat rune"){cat("/players/jareel/GUILD/help/heat_rune.txt");
    write("\n"+NORM); return 1;}
  if(str == "light rune"){cat("/players/jareel/GUILD/help/light_rune.txt");
    write("\n"+NORM); return 1;}
  if(str == "cold rune"){cat("/players/jareel/GUILD/help/cold_rune.txt");
    write("\n"+NORM); return 1;}
  if(str == "ice rune"){cat("/players/jareel/GUILD/help/ice_rune.txt");
    write("\n"+NORM); return 1;}
  if(str == "undead rune"){cat("/players/jareel/GUILD/help/undead_rune.txt");
    write("\n"+NORM); return 1; }
  if(str == "crimson bat"){cat("/players/jareel/GUILD/help/crimson_bat.txt");
    write("\n"+NORM); return 1;}
  if(str == "orlanth"){cat("/players/jareel/GUILD/help/orlanth.txt");
    write("\n"+NORM); return 1;}
  if(str == "yelmalio"){cat("/players/jareel/GUILD/help/yelmalio.txt");
    write("\n"+NORM); return 1;}
  if(str == "humakt"){cat("/players/jareel/GUILD/help/humakt.txt");
    write("\n"+NORM); return 1;}
  if(str == "seven mothers"){cat("/players/jareel/GUILD/help/seven_mothers.txt");
    write("\n"+NORM); return 1;}
  if(str == "kygor litor"){cat("/players/jareel/GUILD/help/kygor_litor.txt");
    write("\n"+NORM); return 1;}
  if(str == "zorak zoron"){cat("/players/jareel/GUILD/help/zorak_zoron.txt");
    write("\n"+NORM); return 1;}
  if(str == "bagog"){cat("/players/jareel/GUILD/help/bagog.txt");
    write("\n"+NORM); return 1;}
  write("That help topic is not available.\n"+NORM+NORM); return 1; }
