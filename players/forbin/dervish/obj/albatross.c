/* 
 * Forbin
 * Created:   2003.08.08
 * Last edit: 2003.08.29 -forbin
 * =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
 * This npc is part of the Dervish guild quest for 
 * Nar-Tuith.  It is only accessible by Dervish that are
 * questing, and is not meant to be killed. 
 * (That is why it has 6666 hps, wc 75, and ac 125)
 * =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
 */

#include "/players/forbin/define.h"
inherit "/players/vertebraker/closed/std/monster.c";

int tired;

id(str) { return (::id(str) || str == "albatross" || str == "giant albatross" 
                            || str =="gigantic albatross" 
                            || str == "a gigantic albatross"); }

reset(arg) {
  object gold;
  ::reset(arg);
  if(arg) return;
  
  set_name("althalamas");
  set_race("bird");
  set_gender("female");
  set_short(RED+"Althal"+HIK+"amas"+NORM+" (a gigantic albatross)");
  set_long("  Towering before you, Althalamas looks at you with a firey glint of\n"+
           "wisdom in her eyes.  Large, red feathers cover her body, some of which\n"+
           "are tipped in grey and black smoothly drap over a massive bulk of a\n"+ 
           "body.  Black talons tip the ends of Althalama's claws, and her\n"+
           "darkened beak looks razor sharp.  You get the feeling by looking at\n"+ 
           "her that if you are the person she seeks, you could 'mount' her.\n");
  set_level(25);
  set_hp(6666);
  set_wc(75);
  set_wc(125);
  set_al(0);
  set_wc_bonus(0);
  set_ac_bonus(0);
  set_dead_ob(this_object());
  set_chat_chance(2);
    load_chat("The albatross whispers, \"I am Althalamas.\"\n");
    load_chat("Althalamas speaks, \"I can tell you what I know if you 'ask'.\"\"\n");
    load_chat("Althalamas speaks, \"I can tell you what I know if you 'ask'.\"\"\n");
    load_chat("The bird says, \"If you are Dervish, seek the Pillars of Dar'khune.\"\n");
    load_chat("The bird says, \"If you are Dervish, seek the Pillars of Dar'khune.\"\n");
    load_chat("The looks expectantly back towards the horizon.\n");
    load_chat("The albatross gazes at you impatiently.\n");
    load_chat("Flapping its wings, the albatross shakes sand from its feathers.\n");
  set_a_chat_chance(10);
    load_a_chat("The albatross grabs at you with a taloned claw.\n");
    load_a_chat("Your flesh is torn away by the albatross' beak.\n");
    load_a_chat("The albatross flaps its wings, slamming you to the ground.\n");
  tired = 1+random(5);
} 

long() { 
  write("  Towering before you, Althalamas looks at you with a firey glint of\n"+
        "wisdom in her eyes.  Large, red feathers cover her body, some of which\n"+
        "are tipped in grey and black smoothly drap over a massive bulk of a\n"+ 
        "body.  Black talons tip the ends of Althalama's claws, and her\n"+
        "darkened beak looks razor sharp.  You get the feeling by looking at\n"+ 
        "her that if you are the person she seeks, you could 'mount' her.\n");
  if(tired == 1) { write("There's a glimmer in her eyes, yet she looks spent.\n"); }
  if(tired == 2) { write("There's a glimmer in her eyes, yet she looks very tired.\n"); }
  if(tired == 3) { write("There's a glimmer in her eyes, yet she looks tired.\n"); }
  if(tired == 4) { write("There's a glimmer in her eyes, and she looks out of breath.\n"); }
  if(tired == 5) { write("There's a glimmer in her eyes, and she looks strong and healthy.\n"); }
}

init() {
  ::init();
  add_action("cmd_ask","ask");
  add_action("cmd_mount","mount");
}

cmd_ask(string str) {
  if(!str || (str != "albatross" && str != "bird" && str != "althalamas")) {
    notify_fail("Ask who?\n");
      return 0;
  }
  if(!present("dervish_tattoo",this_player()) {
    write("Althalamas screeches at you before taking off into the sky.\n");
    destruct(this_object());
      return 1;
  }
  write("On the other side of this great body of water lies endless desert.\n"+
        "There, if you seek and find the Pillars of Dar'khune, you will find\n"+
        "entrance to that which you seek.\n\n"+
        "If you wish, mount me and I will take you as far as I am able.\n"+
        "Be careful though, as you must be prepared to fight.\n");
    return 1;
}

cmd_mount(string str) {
  object which;
  
  if(!str || (str != "albatross" && str != "bird" && str != "althalamas")) {
    notify_fail("Mount what?\n");
      return 0;
  }
  if(!present("dervish_tattoo",this_player()) {
    write("As you try to mount the great albatross, it screeches in anger.\n"+
          "\"You are not of the sands,\" she roars furiously!\n"+
          "You try to back away from her, but it is too late.\n");
    this_player()->attacked_by(this_object());
      return 1;
  }
  say(this_player()->query_name()+" climbs onto the back of the albatross.  The giant\n"+
      "bird takes off into the sky.\n");
  if(environment()->query_where_am_i() == 1) {
    if(tired == 1) {
      which = clone_object("/players/forbin/dervish/OBJ/desert_flying.c");
      move_object(this_player(),"/players/forbin/dervish/RMS/albatrossback.c");
      move_object(this_object(),"/players/forbin/dervish/RMS/jibboo01.c");
      move_object(which,this_player());
    }
    if(tired == 2) {
      which = clone_object("/players/forbin/dervish/OBJ/desert_flying.c");
      move_object(this_player(),"/players/forbin/dervish/RMS/albatrossback.c");
      move_object(this_object(),"/players/forbin/dervish/RMS/jibboo01.c");
      move_object(which,this_player());
    }
    if(tired == 3) {
      which = clone_object("/players/forbin/dervish/OBJ/desert_flying.c");
      move_object(this_player(),"/players/forbin/dervish/RMS/albatrossback.c");
      move_object(this_object(),"/players/forbin/dervish/RMS/jibboo01.c");
      move_object(which,this_player());
    }
    if(tired == 4) {
      which = clone_object("/players/forbin/dervish/OBJ/desert_flying.c");
      move_object(this_player(),"/players/forbin/dervish/RMS/albatrossback.c");
      move_object(this_object(),"/players/forbin/dervish/RMS/jibboo01.c");
      move_object(which,this_player());
    }
    if(tired == 5) {
      which = clone_object("/players/forbin/dervish/OBJ/desert_flying.c");
      move_object(this_player(),"/players/forbin/dervish/RMS/albatrossback.c");
      move_object(this_object(),"/players/forbin/dervish/RMS/jibboo01.c");
      move_object(which,this_player());
    }
    write("\nYou climb up onto the albatross and with a great flapping of wings,\n"+
          "it takes off into the sky.\n\n");
      return 1;
  } 
  else {
    which = clone_object("/players/forbin/dervish/OBJ/beach_flying.c");
    move_object(this_player(),"/players/forbin/dervish/RMS/albatrossback.c");
    move_object(this_object(),"/players/forbin/dervish/RMS/beach02.c");
    move_object(which,this_player());
    write("\nYou climb up onto the albatross and with a great flapping of wings,\n"+
          "it takes off into the sky.\n\n");
      return 1;
  }
}
