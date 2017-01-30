#include "/players/guilds/bards/def.h"

status main(string str){
        object ob;

        if (!str) {
                write("\n" +
                          "C*c*C*c*C*c*C*c*C*c*C*c*C*c*C*c*C*c*C*c*C*c*C*c*C*c*C*c*C\n"
                          + "\nCantrips\n" +
                          "\n 1  Bauble            ( cantrip < bauble > )   (M: 3 )\n"
                          +
                          " 2  Intoxication      ( cantrip < intox >  )   (M: 5 )\n" +
                          " 3  Bubble            ( cantrip < bubble > )   (M: 10)\n" +
                          " 6  Storm             ( cantrip < storm >  )   (M: 20)\n" +
                          " 7  Strand            ( cantrip < strand > )   (M: 5 )\n\n"
                          +
                          "C*c*C*c*C*c*C*c*C*c*C*c*C*c*C*c*C*c*C*c*C*c*C*c*C*c*C*c*C\n\n");
                return 1;
        }
        if (str == "bauble") {
                if (spell(-50, 1, 3) == -1)
                        return 0;
                move_object(clone_object(OBJ+"bauble"),
                                        this_player());
                write
                        ("You murmur strange syllables which flow softly over your tongue.\n"
                         + "A solid bauble of light materializes in your hand.\n");
                say(tp + " murmurs strange syllables which flow softly over " +
                        TP->query_possessive() + " tongue.\n" +
                        "A solid bauble of light materializes in " + tp +
                        "'s hand.\n");
                call_other(TP, "add_spell_point", -3);
                return 1;
        }
        if (str == "intox") {
                if (spell(-100, 2, 5) == -1)
                        return 0;
                call_other(TP, "drink_alcohol", 15);
                write
                        ("You trace magical symbols in the air with your little finger.\n"
                         + "You are surrounded by a dull purple aura.\n" +
                         "You feel drunk.\n");
                say(tp + " traces magical symbols in the air with " +
                        TP->query_possessive() + " little finger.\n" + tp +
                        " is surrounded by a dull purple aura.\n" + tp +
                        " looks drunk.\n");
                call_other(TP, "add_spell_point", -5);
                return 1;
        }
        if (str == "bubble") {
                if (spell(-100, 3, 10) == -1)
                        return 0;
                move_object(clone_object(OBJ+"bubble"),
                                        this_player());
                write("You utter a single sharp syllable.\n" +
                          "A solid sphere of blue light appears in your hand.\n");
                say(tp + " utters a single sharp syllable.\n" +
                        "A solid sphere of blue light appears in " +
                        TP->query_possessive() + " hand.\n");
                call_other(TP, "add_spell_point", -10);
                return 1;
        }
        if (str == "storm") {
                int duration;
                object storm_object;
                if (spell(-100, 6, 20) == -1)
                        return 0;
                storm_object=present("bard_storm_obj",environment(TP));
                /* max duration: 600 seconds */
                duration=((int)TP->query_level()+1)*((int)TP->query_attrib("wil"))/2;
                duration+=((int)TP->query_extra_level())*3;
                if(!storm_object) {
                  storm_object=clone_object("/players/guilds/bards/obj/storm_obj.c");
                  move_object(storm_object,environment(TP));
                  write("You whistle up a storm.\n");
                  say(tp + " whistles up a storm.\n");
                  tell_room(environment(TP), "\n" +
                                  HIM+"*"+NORM+"The sky darkens above...\n\n" +
                                  HIM+"  *"+NORM+"Clouds race across the sky...\n\n" +
                                  HIM+"    *"+NORM+"You hear the echoes of a distant crash of thunder...\n\n");
                } else {
                  write("You whistle a brief tune, and strengthen the storm!\n");
                  say(NAME(TP)+" whistles a brief, stormy-sounding tune.\n");
                }
                storm_object->start_storm(duration);
                call_other(TP, "add_spell_point", -20);
                return 1;
        }
        if (str == "strand") {
                if (spell(-149, 7, 5) == -1)
                        return 0;
                move_object(clone_object(OBJ+"strand"),
                                        TP);
                write("You reach through reality and grasp a strand of chaos.\n");
                say(tp +
                        " reaches through reality and pulls forth a strand of chaos.\n");
                return 1;
                call_other(TP, "add_spell_point", -5);
                return 1;
        } else {
                write("You know of no cantrip by that name...\n");
                return 1;
        }
}
