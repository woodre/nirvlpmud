#include <ansi.h>
inherit "/obj/monster";
#define IT capitalize(target->query_name())

/*
 * This Ghost has the King's Sceptre (~/items/ilstkarn/kings_sceptre),
 * a powerful quest item.  The Ghost will only give up the Sceptre if
 * you give him the key of Arcydia (also a quest item).  This can only
 * be done once per reboot.  If the Ghost is killed he will not
 * reappear until after the next reboot.
 */

object target;
int num;

reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_name("Ghost of Secezeran");
 set_alias("secezeran");
 set_short("the Ghost of King Secezeran");
 set_long(
 "The luminecent figure stands eerily before you.  Secezeran was once\n"+
 "the ruler of Arcydia, which he helped build with his own hands.  He\n"+
 "ruled justly from the mighty fortress until an evil enchantress\n"+
 "tricked him and locked him away in his own dungeon.  Secezeran slowly\n"+
 "perished in this dark cell which his ghost now haunts restlessly.\n");
 set_race("kings_ghost");
 set_gender("ghost");
 set_level(30);
 set_hp(700);
 set_ac(30);
 set_wc(30+random(20));
 set_al(-(100+random(1000)));
 set_aggressive(0);
 set_a_chat_chance(30);
 load_a_chat("The Ghost of King Secezeran glides towards you.\n");
 load_a_chat("The King's Ghost says: How could I be so foolish?\n");
 load_a_chat("Ghost of Secezeran says: Get out!  Arcydia belongs to me!\n");
 load_a_chat("The King's Ghost sighs wistfully.\n");
 load_a_chat("The King's Ghost says: Return that which belongs to me!\n");
 set_dead_ob(this_object());
 move_object(clone_object("players/pavlik/armor/kings_armor"), this_object());
 move_object(clone_object("players/pavlik/armor/kings_crown"), this_object());
 move_object(clone_object("players/pavlik/armor/kings_cape"), this_object());
 move_object(clone_object("players/pavlik/items/ilstkarn/kings_weapon"), this_object());
 init_command("wield weapon");
 command("wear armor", this_object());
 command("wear cape", this_object());
 command("wear crown", this_object());
 set_wc(30+random(20));
 call_out("leave", 100);
}

id(str) {
  return str == "secezeran" || str == "king" || str == "ghost" ||
  str == "kings_ghost" || str == "ghost of secezeran";
}

init() {
  ::init();
  add_action("no_way","mi");
  add_action("no_way","sh");
  add_action("no_way","fi");
  add_action("no_way","so");
}

/* who are we fighting? */
set_target(obj){ target = obj; }
query_target(){ return target; }

/* start fighting the sucker */
begin_fight(ob) {
  target = ob;
  if(!target || !present(target, environment())) {
    return;
  }
  attack_object(target);
  return 1;
}

/* Not these spells! */
no_way() {
  write("Your magic fails you.\n");
  return 1;
}

/* No stopping this fight, amigo! */
stop_fight() {
  if(this_player()->query_level() > 20) {
    ::stop_fight();
    return 1;
  }
  return;
}

/*
 * Non of this heal_self crap
 */
heal_self(i) {
  if(i <=0) {
    return;
  }
  else {
    ::heal_self(i);
  }
  return;
}

/*
 * No modifying stats either!
 */
set_ac(x) {
  if(this_player() != this_object()) { return; }
  ::set_ac(x);
  return 1;
}

set_wc(x) {
  if(this_player() != this_object()) { return; }
  ::set_wc(x);
}

set_heal_rate(x,y) {
  if(this_player() != this_object()) { return; }
  ::set_heal_rate(x,y);
}

leave() {
  if(query_attack()) {
    call_out("leave", 100);
    return 1;
  }
  tell_room(environment(),
  "The King's Ghost turns and disappears.\n");
  move_object(this_object(), "players/pavlik/mages/rooms/master_room");
  destruct(this_object());
  return 1;
}

/* We died <sniff> */
monster_died() {
  object ob, obj;

  obj = present("corpse", environment());

  if(!obj) {
    return 0;
  }

  /*
   * No crown for you!  The crown is the key to the king's sceptre.
   * this item can only be gotten if you retrieve the key of arcydia
   * and give it to the king.
   */
  tell_room(environment(),
  "The golden crown falls to the ground and shatters!\n");

  if(present("kings_crown", obj)) {
    destruct(present("kings_crown", obj));
  }
  if(present("kings_weapon", obj)) {
    destruct(present("kings_weapon", obj));
  }

  /*
   * The king only appears once per reboot.  If he is killed he will not
   * reappear until after the next reboot.
   */
  ("players/pavlik/ilstkarn/ilstkarn_portal")->set_king(0);

  if(this_player()->query_name())
    write_file("/players/pavlik/ilstkarn/LOG",
    capitalize(this_player()->query_name())+" killed the King's Ghost. ["+ctime()+"]\n");

  return 0;
}

