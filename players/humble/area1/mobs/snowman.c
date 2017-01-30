/*HUMBLE CORPS 2004*/
#include "/players/humble/area1/defs.h"
/* Change this to change how long it takes to attack a kid */
#define DELAY 5

status is_pet() { return 0; }
status is_kid() { return 0; }

inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    money=8000+random(3000);
    set_name("The Abominable Snowman");
    set_alt_name("snowman");
    set_alias("snowman");
    set_short(HIB+"T"+HIW+" h"+HIB+" e"+HIW+"   A"+HIB+" b"+HIW+" o"+HIB+" m"+HIW+" i"+HIB+" n"+HIW+" a"+HIB+" b"+HIW+" l"+HIB+" e"+HIW+"  S"+HIB+" n"+HIW+" o"+HIB+" w"+HIW+" m"+HIB+" a"+HIW+" n"+NORM+NORM);
    set_race("legend");
    set_long(
    "This is the most disagreeable and unpleasant creature you have ever seen.\n"+
    "This beast of a monster is at least twelve feet tall with long\n"+
    "charcoal black stick arms spanning the entire freezer room.\n"+
    "This could only be, oh shit, you just wet your pants.\n");
    set_gender("male");
    set_level(30);
    set_ac(30);
    set_wc(50);
    set_hp(2000+random(750));
    set_al(350);
    set_multi_cast(1);
    add_spell("artic blast",
    HIW+"The Abominable Snowman inhales air and the room instantly grows colder..\n"+NORM+
    HIB+"        ************^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^************\n"+NORM+
    HIB+"      *************** !! A R C T I C --- B L A S T !! ***************\n"+NORM+
    HIB+"        ************^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^************\n"+NORM,
    HIW+"The Abominable Snowman inhales air and the room instantly grows colder..\n"+NORM,
    3,100,"other|ice");

    add_spell("frost",
    BLU+"The Abominable Snowman swirls in a circle fighting confusion\n"+NORM+
    BLU+"His arms raise up in a strange manner.......\n"+NORM+
    HIW+"     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n"+NORM+
    HIW+"      * * * * * * * * * * * * * * F R O S T * * * * * * * * * * * * * * \n"+NORM+
    HIW+"     * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n"+NORM,
   HIW+"A bright white light floods the room and you feel weak...\n"+NORM,
    5,60,"other|ice");

    add_spell("jab",
    HIK+"The Abominable Snowman whips his arm about cruiously and rapidly jabs you.\n"+NORM+
    HIR+"    ...................  G O U G E  ....................\n"+NORM+
    HIK+" A hole is torn in your flesh.\n"+NORM,
    HIK+"The Abominbale Snowman jabs #TN# tearing the flesh..... blood sprays.\n"+NORM,
    15,35,"physical");
    }
}
heart_beat() {
    ::heart_beat();
    if(attacker_ob) {
      already_fight=0;
      attack();
      already_fight=0;
      attack();
      already_fight=0;
      attack();
  }
}
stop() {
    if(this_player()->query_ghost() == 1) { return 0; }
    if(this_player()->query_level() >12) {
      write(HIB+"You are frozen in absolute terror!!!\n"+NORM);
      return 1; 
    }

    return 0;
}

init() {
  ::init();
    add_action("stop","out");

    if (this_player() && living(this_player()) && this_player()->is_pet()) {
      if (this_object()->query_attack() == this_player()) {
        say("The Snowman "+HIR+"continues"+NORM+NORM +"to feed upon the wild kill!\n");
      }
      else {
        call_out("napalm_babies", DELAY, this_player());
      say(HIW+"The Snowman grins and his eyes light up.\n"+NORM);
      }
    }
}

void napalm_babies(object ob) {
  if (!ob || (!ob->is_pet() && !ob->is_kid()))
    return;

  if (environment(this_object()) != environment(ob)) {
      say("The Snowman grins in a sickening manner.\n");
    return;
  }
  say("The Snowman bellows in rage and attacks a kid!\n");
  this_object()->attack_object(ob);
}

