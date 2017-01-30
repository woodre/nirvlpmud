/*  a honing stone - 1 time sharpening  */

inherit "/obj/weapon";
#include "DEFS.h"

reset(arg) {
  ::reset(arg);
  if (arg) return;
set_name("honing stone");
set_alias("stone");
set_short("an oiled honing stone");
set_long(
  "  This oiled honing stone has seen much use.  It is a rectangular\n"+
  "slab of special stone that can be held in your hand to sharpen\n"+
  "any and all weapons to like new condition.  It is slightly worn in\n"+
  "the middle of the stone from its many sharpenings.  On the under-\n"+
  "side of the stone is a small sticker which reads: 'Make sure your\n"+
  "weapon is unwielded before you attempt to sharpen it.  Then you\n"+
  "simply 'sharpen <weapon name>' and its edge or edges should be\n"+
  "restored to mint-like condition.'\n"+
BOLD+"     CAUTION:"+NORM+"  Will NOT work on [BROKEN] weapons!\n");

set_class(1);
set_weight(1);
set_value(875);
add_wear(700);
}

init() {
  ::init();
  add_action("sharpen","sharpen");
}

sharpen(str) {
object ob;
int amt;

if(!str) { write("What are you trying to sharpen?\n"); return 1; }

ob = present(str,this_player());
if(!ob) { write("You do not possess that weapon!\n"); return 1; }

if(ob->query_broke() == 1) {
  write("You feel foolish as you try to sharpen your BROKEN weapon\n"+
    "and your stone falls apart in the process.\n");
  destruct(this_object());
  return 1; }

if(TP->query_weapon() == ob) {
  write("As you begin to sharpen your worn weapon, you remember that\n"+
	"it was supposed to be unwielded first.  Alas, as you look\n"+
	"down at the crumbling stone, you feel a sinking feeling in\n"+
	"your stomach for your stupidity and realize that you just\n"+
	"wasted your hard earned coins.....\n");
  destruct(this_object());
  return 1; }

else {
  write("You carefully and gently stroke the edges of this fine\n"+
	"weapon with your honing stone.  The light glints off of\n"+
	"its newly acquired edges like diamonds....  The constant\n"+
	"rubbing, however, has reduced your stone to nothing but\n"+
	"a pile of dust.....\n");
  roomspeak(capitalize(TPRN)+" sharpens "+TP->query_possessive()+
     " "+ob->short()+".\n");
  ob->set_hits(1);
  ob->set_misses(1);
  destruct(this_object());
  return 1; }

return 1; }
