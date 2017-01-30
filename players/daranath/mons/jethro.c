#include <ansi.h>
#define tp this_player()->query_name()
inherit "/obj/monster";

reset(arg){
  ::reset(arg);
  if (!arg){

move_object(clone_object("/players/daranath/arms/jet_armor.c"),this_object());
move_object(clone_object("/players/daranath/arms/jet_helm.c"),this_object());
move_object(clone_object("/players/daranath/weps/jet_spear.c"),this_object());

    set_name("jethro");
    set_alias("defender");
    set_alt_name("lord jethro");
    set_race("halfling");
    set_gender("male");
    set_short("Lord Jethro, Halfling Defender");
    set_long("The halfling guardian Jethro spends most of his days\n"+
             "exploring the underground tunnels of the UnderDark. The\n"+
             "warrior's size belies his fighting prowess, many scars running\n"+
             "about his diminutive frame. Long, dark brown hair curls about\n"+
             "his shoulders and rests against his chainmail. He knows many\n"+
             "things from his time spent within the UnderDark area, perhaps\n"+
             "you could ask him for a "+HIY+"<"+NORM+" rumor "+HIY+">"+NORM+" about the realm.\n");
    set_level(22);

    init_command("wear armor");
    init_command("wear helmet");
    init_command("wield spear");

    set_ac(25);
    set_wc(35);
    set_hp(700);
    set_al(1000);
    set_aggressive(0);

    set_chat_chance(25);
    set_a_chat_chance(20);
    load_chat("Jehtro looks up at you, waiting to hear what you want.\n");
    load_chat("The halfling guardian looks annoyed at your disturbance.\n");
    load_chat("Jethro shuffles about some paperwork.\n");
    load_a_chat("Jethro strikes at you with the spear.\n");
    load_a_chat("Jethro fights like a halfling possessed.\n");
    load_a_chat("Jethro growls as you attempt to slay him.\n");
    load_a_chat("Jethro says: I wish you wouldn't have done this.\n");

    set_chance(15);
    set_spell_dam(65);
    set_spell_mess1("Jethro strikes his foe with the spear.\n");
    set_spell_mess2("Jethro gouges you with his deadly spear.\n");
    }
}

init(){
  add_action("rumor","rumor");
/* add_action("ask","ask"); */
/* add_action("quest","quest"); */
}

rumor(){
  string msg;
  msg = "Jethro looks up at you as you ask him for a rumor about the UnderDark.\n"+
        "Jethro states: ";

switch(random(20)) {
    case 0: msg += "Many items of a strong magikal nature lay within the wizard's lab.\n\n"; break;
    case 1: msg += "An entire city of dark skinned elves lay beneath the rock.\n\n"; break;
    case 2: msg += "Many passages twist about the bleak tunnels, sometimes bringing you back to the start.\n\n"; break;
    case 3: msg += "The Myconid King has a hidden treasury.\n\n"; break;
    case 4: msg += "An elemental of great power walks about the tunnels.\n\n"; break;
    case 5: msg += "Tribes of orcs have banded together and constructed a great fortress of stone within the rock.\n\n"; break;
    case 6: msg += "The great river Styx runs through the middle of the tunnels.\n\n"; break;
    case 7: msg += "The dwarven kings of the past are kept captive down in the darkness.\n\n"; break;
    case 8: msg += "A pool made of blood is a gate to hades iteself.\n\n"; break;
    case 9: msg += "Many dangers await those who stop for any amount of time within the tunnels.\n\n"; break;
    case 10: msg += "Magic itself is said to fail within the tunnels in a certain area.\n\n"; break;
    case 11: msg += "A wizard's tower is lost within the stone.\n\n"; break;
    case 12: msg += "Mines of the strongest and purest silver run throughout the rock of the lower tunnels.\n\n"; break;
    case 13: msg += "A hallway of multi-colored portals exists, though few have returned from any of the shimmering doorways.\n\n"; break;
    case 14: msg += "Blood colored sands run about an underground arena.\n\n"; break;
    case 15: msg += "Tunnels of the UnderDark run all about the lands of Nirvana, making for many entrances and exits to the darkness.\n\n"; break;
    case 16: msg += "The gaze of the gorgon turns one to stone, killing them instantly.\n\n"; break;
    case 17: msg += "A great, black winged dragon has a hoard which a hundred could not carry.\n\n"; break;
    case 18: msg += "Drow walk about the halls and passages within, and you could become one.\n\n"; break;
    case 19: msg += "Shatter the floating orb within the crypt to quell the evil within.\n\n"; break;
}

  msg += "Jethro then goes back to his work.\n";
  tell_room(environment(this_object()),msg);
  return 1;
}
