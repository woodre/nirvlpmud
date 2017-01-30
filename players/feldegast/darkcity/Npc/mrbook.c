/* 
This is the leader of the stranger race whom
John Murdoch defeated in psychic combat near
the end of the movie.
*/
#include "def.h"   
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(!present("knife")) {
    move_object(clone_object(PATH+"Wep/sdagger"),this_object());
    init_command("wield knife");
  }
  if(arg) return;
  set_name("Mr. Book");
  set_alt_name("book");
  set_alias("mister");
  set_short("Mr. Book");
  set_long(
"Mr. Book is an ancient, millenia old stranger with unusually\n"+
"pale, leathery skin.  He is tall, with a bulbous white skull.\n"+
"He wears a long black coat and carries a cane at his side.\n"+
"Mr. Book is the leader of the collective intelligence of the\n"+
"stranger race.\n"
  );
  set_gender("male");
  set_race("stranger");
  set_level(21);
  set_wc(35);
  set_wc_bonus(8); /* For area attack. - 12/30/00 */
  set_ac(23);
  set_hp(600);
  set_al(-1200);
  set_a_chat_chance(10);
  load_a_chat("Mr. Book warps "+BLU+"reality"+NORM+" around you.\n");
  load_a_chat(
"Mr. Book summons a meter long spike from the ground, gouging you deeply.\n"
  );
  load_a_chat("Mr. Book slashes with his knife, spilling "+RED+"blood"+NORM+" freely.\n");
  load_a_chat(
"Mr. Book's knife flies through the air like some hummingbird, striking\n"+
"his opponent from behind.\n");
  set_chance(20);
  set_spell_mess1(
"\nMr. Book projects a lance of "+HIM+"warped reality"+NORM+" at his target.\n"
  ); /* 3RD PERSON */
  set_spell_mess2(
"\nMr. Book projects a lance of "+HIM+"warped reality"+NORM+" at you.\n"
  ); /* 1ST PERSON */
  set_spell_dam(50);
  set_dead_ob(this_object());
}
monster_died(ob) {
  tell_object(this_player(),"A ball of crackling psychic energies erupts from Mr. Book's prone form\n"+
      "and strikes your forehead, pouring the knowledge of tuning into your\n"+
      "mind.  Type <tune_help> for more information.\n" 
      );
  move_object(clone_object(PATH+"Obj/tune_ob"),this_player());
}

heart_beat() {
  ::heart_beat();
 if((alt_attacker_ob && !random(5)) || (attacker_ob && !random(10))) {
    object ob,next;
    already_fight=0;
    say(
"\nMr. Book unleashes a "+HIM+"wave of distorted reality"+NORM+" that rolls\n"+
"through the room, damaging everything it touches.\n"
    );
    ob=first_inventory(environment(this_object()));
    while(ob) {
      next=next_inventory(ob);
      if(ob) /* check added by verte 6.6.01 */
      if(living(ob) && ob!=this_object()) {
          ob->heal_self(-(random(80)));
        if(ob && !ob->query_ghost()) /* check added by verte 6.6.01, bog */
       {
        say(
          ob->query_name()+" is hit by the blast!\n"
        );
        ob->attacked_by(this_object());
       }
      }
      ob=next;
    }
  }
}
