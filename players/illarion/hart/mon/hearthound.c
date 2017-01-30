inherit "obj/monster";
#include "/players/illarion/dfns.h"

void reset(status arg) {
   ::reset(arg);
   if(arg) return;

   set_name("hound");
   set_alias("heart");
   set_race("demon");
   set_short("A huge, slavering heart hound");
   set_long(
"About the size of a small cow, the heart hound is covered in short tan\n"+
"fur that does not hide rippling, powerful muscles.  Two coal black\n"+
"eyes look out of its face, shining with pure malignance, and a pair of\n"+
"ears that look like they belong on a rabbit perk up above.  Most\n"+
"frightening, though, is the immense and numerous teeth that show when\n"+
"it is biting or snarling, which is almost always.\n");
   set_level(18);
   set_hp(400);
   set_wc(40);
   set_al(-500);
   set_ac(10);
/* Meant to approximate an appropriate bonus for the healing factor.  When
   the monster is below half hit points, it has a 1/3 chance of healing 10-19
   points of damage.  If that were always active, it woul work out to a bonus
   of 10, but since it's not, I lowered it to 8.
*/
   set_ac_bonus(8);


   set_chat_chance(5);
   set_a_chat_chance(5);
   load_chat("The heart hound snarls angrily\n");
   load_chat("The heart hound looks at you and drools through its sharp fangs\n");
   load_a_chat("The stink of death and decay is almost overpowering.\n");
   load_a_chat("The heart hound howls loudly in anger and hunger!\n");
   load_a_chat("The heart hound's huge fangs run red with blood.\n");
}
attack() {
   if(attacker_ob && present(attacker_ob,environment()) &&
           !random(15)) {
      object *items,barmor;
      int s,x;
      items=all_inventory(attacker_ob);
      s=sizeof(items);
      for(x=0;x<s;x++) {
         if(items[x]->query_worn() &&
               (string)items[x]->query_type() == "armor") {
            barmor=items[x];
            break;
         }
      }
      tell_object(attacker_ob,
"The heart hound breaks past your defense and plunges it's head toward\n"+
"your chest, biting down with great force!\n");
      tell_room(ETO,format(
"The hearthoud's slavering mouth finds "+TPN+"'s chest, and it bites down\n"+
"with great force!\n"),({attacker_ob}));
      if(barmor)
         if(transfer(barmor,"/room/void")==0) {
            tell_room(ETO,format(
capitalize(barmor->short())+" is destroyed by the force of the hearthoud's\n"+
"bite!\n"));
            destruct(barmor);
         }
   } else if(hit_point < max_hp/2 && !random(3)) {
      say("Sickly "+HIG+"green"+NORM+" light glows in the heart hounds wounds,\n"+
          "and they begin to close.\n");
      hit_point+=10+random(10);
   }
   ::attack();
}
query_message_hit(int tmp) {
  switch(tmp) {
  case 20..29:
    return ({" with a bone breaking sound",HIR+"crunched"+NORM});
  case 10..19:
    return ({" very hard",RED+"gnawed"+NORM});
  case 6..9:
    return ({" hard",RED+"bit"+NORM});
  case 4..5:
    return ({"","bit"});
  case 2..3:
    return ({"","grazed"});
  case 1:
    return ({" in the stomach","tickled"});
  default:
    return ({" to small fragments",HIR+"chewed"+NORM});
  }
}
