#include "defs.h"

inherit MONSTER;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("hedge monster");
  set_alt_name("monster");
  switch(random(4))
  {
    case 0: set_short(GRN+"Griffin Hedge Monster"+NORM);
            set_alias("griffin");
            break;
    case 1: set_short(GRN+"Dragon Hedge Monster"+NORM);
            set_alias("dragon");
            break;
    case 2: set_short(GRN+"Sphinx Hedge Monster"+NORM);
           set_alias("sphinx");
           break;
    case 3: set_short(GRN+"Hydra Hedge Monster"+NORM);
            set_alias("hydra");
            break;
  }
  set_long(
"This is a beautiful green hedge in the shape of a "+alias+".  It\n"+
"seems to move about in the moonlight with some primitive sentience,\n"+
"with thorns in the place of its teeth and claws, and overripe berries\n"+
"where its eyes should be.\n"
  );
  set_level(12);
  set_hp(180);
  set_wc(16);
  set_ac(9);
  set_race("plant");
  set_al(0);
  set_chat_chance(3);
  load_chat(short_desc+" ambles about the park as though it were real.\n");
  load_chat(short_desc+" stares at you with its berry red eyes.\n");
  set_a_chat_chance(5);
  load_a_chat(short_desc+" bites you with its thorned teeth.\n");
  load_a_chat(short_desc+" rakes you with its claws!\n");
  set_dead_ob(this_object());
}

void monster_died(object ob)
{
  object corpse;
  say(short_desc+" implodes into a pile of leaves.\n");
  corpse=present("corpse",environment());
  if(corpse) destruct(corpse);
  move_object(clone_object(HEAL_PATH+"leaves.c"),this_object());
}
