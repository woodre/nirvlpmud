/*
 * Ascension, by Dune and Snow
 * Spirit legion fight control
 */
#include "../def.h"
#define  DELAY         5  /* beat timing */
#define  CLEANDELAY    10 /* delay to remove spirits and destruct */

string idname;

id(str) { return str == idname+"_spirit_legion" || 
                 str == "asp"; }
get() { return 0; }

begin_war(object ob, string name) {
  idname = name;
  coordinate_fight(name);
  }


coordinate_fight(string name) {
  int enemies, biggest;
  object ob, iterob, roomob, targetob;
  enemies = 0;
  biggest = 0;

  /* if player left mud, remove spirits and destruct */
  if(!find_player(name))
    cleanup_after_fight(1, name);

  ob = find_player(name);

  /* if moved or not fighting, remove spirits and destruct */
  if( (!ob->query_attack()) || 
      (!present(this_object(), environment(ob))) ) {
    cleanup_after_fight(0, name);
    return; }

  if(present("spirit_helper_mon", environment(ob))) {
    /* find highest level monster in room */
    iterob = first_inventory(environment(ob));
    while(iterob) {
      roomob = iterob;
      iterob = next_inventory(iterob);
      if(roomob->query_attack() == ob) {
        if(roomob->query_level() >= biggest) {
          biggest = roomob->query_level();
          targetob = roomob;
          }
        enemies++;
        }
      }

    /* make entire spirit legion attack the highest lv monster */
    iterob = first_inventory(environment(ob));
    while(iterob) {
      roomob = iterob;
      iterob = next_inventory(iterob);
      if(living(roomob) && roomob->id("spirit_helper_mon")) {
        /* make seperate call_out so this call_out isn't toasted */
        if(!roomob->query_attack()) roomob->provoke_attack(targetob);
        }
      }
   }
  call_out("coordinate_fight", DELAY, name);
}


cleanup_after_fight(status quit_flag, string obname) {
  /* remove all spirits and destruct this_object when done */
  object ob, iterob, roomob;
  status had_spirits;
  had_spirits = 0;
  if(present("spirit_helper_mon", environment(this_object()))) {
    iterob = first_inventory(environment(this_object()));
    while (iterob) {
      roomob = iterob;
      iterob = next_inventory(iterob);
      if( (roomob->id("spirit_helper_mon")) && 
          (roomob->query_owner() == capitalize(obname))) {
        destruct(roomob);
        had_spirits = 1; }
      }
    }
  if(quit_flag) {
    destruct(this_object());
    return; }
  ob = find_player(obname);
  IPOB->set_legion(0);
  if(had_spirits) {
    tell_room(environment(this_object()), 
      ORN+"'s spirits fly back into the heavens.\n");
    tell_object(ob, 
      "Seeing that you no longer need aid, your spirits leave.\n");
    }
  destruct(this_object());
}
