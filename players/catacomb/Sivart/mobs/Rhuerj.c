#include "/players/catacomb/saiyan/def.h"
inherit "obj/monster.c";
#define HOSERNN HOSER->query_name()
object dagger, boots;

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("rhuerj");
set_race("Durkor");
set_short("Rhuerj Werjor");
set_long(
  "  Rhuerj is the matriarch of House Werjor in Sivart.  She\n"+
  "gained her position through the use of her deadly art.  Her\n"+
  "face shows an agelessness that comes from the use of the \n"+
  "magic in Sivart.   Her large almond-shaped eyes glitter a \n"+
  "beautiful sky blue, but behind those eyes lies a cold-hearted\n"+
  "assassin.  Her long midnight blue hair is cut off at shoulder\n"+
  "length.  Her shapely curves act as a decoy for her victims.\n"+
  "Her deadly blade, Bonescythe, is like an extension of her own\n"+
  "body.  Don't let her sly looks fool you she is a killer.\n");
 
set_level(22);
set_hp(500);
set_al(0);
set_dead_ob(this_object());
set_aggressive(0);
add_money(random(1500)+3000);
set_chat_chance(3);
  load_chat("Rhuerj says: I shall rule over all of Sivart soon.\n");
set_chance(10);
set_spell_dam(50);
set_spell_mess1(			
  "Rhuerj mumbles some strange words and her enemy reels in pain.\n");
set_spell_mess2(			
  "You see Rhuerj mumble something then feel sharp pain all over your body.\n");

dagger = clone_object("players/catacomb/Sivart/items/bonescythe.c");
move_object(dagger, this_object());
command("wield dagger",this_object());
set_wc(40);

boots = clone_object("/players/catacomb/Sivart/items/lboots.c");
move_object(boots, this_object());
init_command("wear boots", this_object());
set_ac(19);

}
heart_beat()
{
  int chance;
  chance = random(100);
 ::heart_beat();
  if(!environment())
    return;
  if(!HOSER)
    return;
  
  if(chance >= 75)
  {
    tell_object(HOSER,
          "\n\n  Rhuerj jumps back and quickly channels the flows\n"+
              "  of fire sending a flow of fire into you.\n\n");
    HOSER->hit_player(random(30) + 10, "other|fire");
    return 1;
  }
  if(chance > 65)
  {
    tell_object(HOSER,
          "\n\n    Rhuerj locks you in a flow of air and brings \n"+
              "         Bonescythe through your abdomen\n");
    HOSER->hit_player(random (10) + 50);
    return 1;
  }
  if(chance < 15)
  {
    tell_object(HOSER,
          "\n\n  Rhuerj mumbles  and Bonescythe is coated in mist.\n"+
              "     As the blade slices clean you feel yourself\n"+
              "                    grow weak.\n");
    HOSER->hit_player(random(40) + 5, "other|evil");
    return 1;
  }
  return 1;
}

  