/* max carry for bag rules exceeded because you can't buy it, and there is only 1 */
/* I'm lowering the MAX_WEIGHT from 65 to 29.  a) Because it is illegal.  and b)
   because there is no thematic justification. and c) because there's no balance
   justification.  If it violates established rules by a wide margin, it damn well
   better be worth more than 200 coins.  And that still wouldn't make up for a & b.
   - Feldegast
*/
/*  It was already approved by one senior just a few months ago.  Did you think mal didn't notice?  but ok, i'll make a change.  lowered the max limit from 65 to 55 and upped the weight from 1 to 3, since the bag itself would be kinda heavy.  as for thematic reasons, have you ever seen a goalie bag?  they are fucking huge.  */
/*  I would also like to point out that /doc/build/RULES/bags was meant more to cover bags that are sold.  ones that are unique items and given out as treasure on a monster should fall within the discression of the wiz coding it and the senior approving it.  */
#include "/players/jenny/define.h"
/* Please do not change this back until policy can be established. - Maledicta */
/*  Uhh.. I just changed it boss.  Now it has a constant weight of 3.
    Who changed it from 3?  -V */
inherit "obj/treasure.c";
#define MAX_WEIGHT      32
int local_weight;

reset(arg) {
set_no_clean(1);
   if(arg) return;
   set_id("equipment bag");
   set_alias("bag");
   set_short("A large equipment bag");
   set_save_flag(1);
   set_value(100);
   local_weight = 1; } 
long() {
   write("This is a very large duffle bag that is used for storing goalie\n"+
      "equipment.  It is black, with a strap for carrying over the shoulder\n"+
      "and the letters CCM printed on the side.\n");
   if (first_inventory(this_object()))
      write("There is stuff in it.\n");
   else
      write("You can put things in it.\n");
}
add_weight(w) {
   if (local_weight + w > MAX_WEIGHT)
      return 0;
   local_weight += w;
   return 1;
}
can_put_and_get() { return 1; }
prevent_insert() {
   if (local_weight > 1) {
      write("You can't when there are things in the bag.\n");
      return 1;
   }
   return 0;
}
query_weight() { return (3); }
