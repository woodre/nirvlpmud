
#include "base_spell.h"

int ssay(object targ, string mess);
int coins();
int item();
int herring();
int drunk();
int frog();
int impotent();
int mute();
int blind();
int shape_change();
int teleport();
int damage();
int summon_monster();
int give_birth();
int death();

void reset(int arg) {
  if(arg) return;
}

int fail_spell(int spell_level, int will) {
  int fail;
  if(random(100) < will) {
    write(format("The power flowing through you surges wildly, but you will " +
     "it back under your control.\n"));
    return 0;
  }
  write(format("The power flowing through you surges wildly and out of " +
   "control.\n"));
  fail=random(50) + spell_level;
  if(fail < 4)       coins();
  else if(fail < 8)  item();
  else if(fail < 12) herring();
  else if(fail < 16) drunk();
  else if(fail < 20) frog();
  else if(fail < 24) impotent();
  else if(fail < 28) mute();
  else if(fail < 32) blind();
  else if(fail < 36) shape_change();
  else if(fail < 40) teleport();
  else if(fail < 44) damage();
  else if(fail < 48) summon_monster();
  else if(fail < 49) give_birth();
  else               death();
  return 1;
}

int test() {
  write("Test bing.\n");
  return 1;
}

int coins() {
  object money;
  ssay(0, "Coins shower down out of the air.\n");
  money=clone_object("obj/money");
  money->set_money(random(450) + 50);
  move_object(money, environment(me));
}

int item() {
  object ob;
  string *items;
  items=({ "players/bastion/obj/wakeup", "obj/bag", "obj/beer", "obj/rope",
   "obj/stone", "obj/dice", "obj/torch", "obj/book" });
  ob=clone_object(items[random(sizeof(items))]);
  write(format(ob->short() + " appears in your hands.\n"));
  ssay(0, ob->short() + " appears in " + NAME + "'s hands.\n");
  move_object(ob, me);
}

int ssay(object targ, string mess) {
     object ob, here;
     here=environment(me);
     ob=first_inventory(here);
     while(ob) {
          if(ob!=targ)
            tell_object(ob, format(mess));
          ob=next_inventory(ob);
     }
     return 1;
}

int herring() {
  int i;
  object fish;
  ssay(0, "The room suddenly overflows with herring!\n");
  i=random(20) + 15;
  while(i) {
    fish=clone_object("players/bastion/obj/herring");
    move_object(fish, environment(me));
    i--;
  }
}

int drunk() {
  write("You suddenly feel very good.\n");
  ssay(me, NAME + " sways a bit and belches.\n");
  me->add_intoxication(100);
}

int frog() {
  me->frog_curse(1);
  ssay(me, NAME + " transforms into a frog.\n");
}

int impotent() {
  me->set_impotent(1, 3000);
  write("You have a strange feeling.\n");
}

int mute() {
  me->set_mute(1, 300);
  write("You get a tingling feeling in your throat.\n");
}

int blind() {
  me->set_blind(1, 300);
  write(format("Blackness swirls before you. All you see is darkness.\n"));
}

int shape_change() {
  string *forms;
  int x;
  forms=({ "newt", "A slimy, little newt", "chicken", "A brainless chicken",
   "penguin", "A penguin", "goat", "A billy goat", "lemming",
   "A furry lemming" });
  x=random(5);
  me->set_new_name(forms[x]);
  me->set_new_short(forms[x+1]);
  me->set_new_long(forms[x+1] + ".");
  me->set_disguise_duration(30);
  ssay(me, NAME + " is engulfed in a burst of energy, transforming into a " +
   forms[x] + ".\n");
  write(format("You are engulfed in a burst of energy. You feel changed.\n"));
}

int teleport() {
  string *dest;
  int x;
  dest=({ "room/church", "players/bastion/isle/cave3", "room/giant_path",
   "players/bastion/antaria/belgaers/clearing", "room/well", "room/path",
   "players/boltar/hotel/hotel", "players/glaendor/MAGIC/stairs" });
  x=random(8);
  write("You feel disoriented.\n");
  me->move_player("X#" + dest[x]);
}

int damage() {
  write(format("Your spell feeds back on you in an explosion of energy.\n"));
  ssay(me, NAME + " is enveloped in a blinding flash.\n");
  me->hit_player(random(50));
}

int summon_monster() {
  string *bing;
  object who;
  int x;
  bing=({ "players/bastion/monster/ogre", "players/bastion/monster/goblin",
   "players/bastion/monster/dragon", "players/bastion/monster/gull", 
   "players/bastion/monster/demon2" });
  x=random(5);
  who=clone_object(bing[x]);
  ssay(0, "A " + who->query_name() + " falls from a tear in reality.\n");
  move_object(who, environment(me));
  who->attacked_by(me);
}

int pregnant() {
  write("You give birth!\n");
  ssay(me, NAME + " gives birth.\n");
}

int death() {
  object corpse;
  ssay(me, NAME + " radiates a dim red and falls to the ground.\n");
  me->second_life();
  corpse=clone_object("obj/corpse");
  corpse->set_name(NAME);
  me->transfer_all_to(corpse);
}
