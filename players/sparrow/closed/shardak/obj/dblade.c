/*
 * A weapon mainly used by the Servants of Shardak
 * The smith in the guild is the one who makes it. If you give him
 * a holy avenger (from the knight in Morgar's tower), he will change
 * it in 15 minutes or more, and then you can buy it from him.
 * 
 * Works best if you're lord of evil (effective wc around 18.67)
 * Can be stored, but only repaired 5 times
 */
#pragma strict_types
#include "/players/vertebraker/ansi.h"
inherit "/obj/weapon";

void
reset(int arg)
{
    if(arg) return;
    ::reset();
    set_name("demon blade");
    set_alias("blade");
    set_short("The Demon Blade");
    set_long("\
You are holding the famed Demon Blade forged from the Holy Avenger by\n\
Shardak's smith. The hilt is excessively ornamented and strange symbols\n\
are chased into the wavy two-edged blade. It whistles through the air\n\
and seems to leave a faint red glow in its wake as you swing it around.\n");
    set_class(18);
    set_type("sword");
    set_weight(3);
    set_value(1175);
    set_hit_func(this_object());
}

/*
 * I still think it is a wrong interpretation of rules to say that
 * the chance of a bonus return must be less than 33%, but hohum..
 * Here it is: The new weapon_hit. If you're very evil, there is a
 * 33% chance of a bonus of average 5 => eff. wc = 18.67
 */
mixed
weapon_hit(object opponent)
{
    int al, bonus;

    al = (int) this_player()->query_alignment();
    if (al >= -39) {
        switch (al) {
          case  321 ..  640: bonus -= 2;
          case  161 ..  320: bonus -= 6;
            if (random(100) >= 80)
              write("The blade seems to resist your efforts.\n");
            break;

          case   81 ..  160: bonus -= 2;
          case   41 ..   80: bonus -= 2;
            if (random(100) >= 80)
              write("The blade feels very heavy in your hands.\n");
            break;

          case  -39 ..   40: bonus = 0; break;
          default:
            if (random(100) >= 80) {
                write("You are hardly able to swing the blade.\n");
                say(this_player()->query_name() + " swings the demon blade with great effort.\n");
            }
            bonus = -10;
        }
    }

    else {
        /* here comes bonus: 3 + 2*random(3) */
        if (al < -639) al = -639;
        if (random(1920) < -al) {       /* 1 in 3 chance at best */  
            bonus = 5;
            switch (random(3)) {
              case 0:
                write("The demon blade leaves a faint " + RED + "red glow" + 
                 NORM + " in its lethal wake.\n");
                say(this_player()->query_name() + "'s demon blade leaves a faint " + RED 
                +"red glow" + NORM + " in its lethal wake.\n");
                break;
              case 1:
                write("The demon blade feeds on your malice to unleash the power of evil.\n");
                say(this_player()->query_name() + "'s eyes shine with malice as " +
                    this_player()->query_pronoun() + " brandishes " +
                    this_player()->query_possessive() + " demon blade.\n");
                bonus += 2;
                break;
              case 2:
                write("\
Without much effort you gracefully swing the demon blade\n\
slicing through flesh and splintering bones.\n");
                say(this_player()->query_name() + " swings " +
                    this_player()->query_possessive() +
                    " demon blade with much grace.\n" +
                    "It leaves a deep gash in " + opponent->query_name() + ".\n", opponent);
             tell_object(opponent, this_player()->query_name() + " swings " +
                this_player()->query_possessive() +
                " demon blade with much grace.\n" +
                "It leaves a deep gash in your flesh...\n");
                bonus += 4;
                break;
            }
        }
    }

    if((string)this_player()->query_guild_name() != "shardak")
      bonus -= random(8);

    return bonus;
}
