/* added in a random(3) == 0 into the weapon_hit
- mythos <5-15-96>
*/

inherit "obj/weapon";
object corpse;
int heal;
static int attacker_alignment;
reset(int arg) {
   ::reset(arg); 
   if (arg) return;
   set_name("staff");
   set_class(16);
   set_weight(4);
   set_value(600);
   set_short("The Shadow Staff");
   set_long("Made from the darkest magics this staff is full of evilness and\n"+
      "those who are truly evil may be able to wield this weapon\n"+
      "correctly.\n");
   set_hit_func(this_object());
}
weapon_hit(attacker) {
   if(random(3)==0) {
      if(this_player()->query_al() < -300) {
         write("The staff sends forth a horde of shadows at your opponent!\n");
         return 3;
      }
   }
   return 0;
}
init() {
   ::init();
   add_action("wield","wield");
}
wield() {
   if (this_player()->query_alignment()>200)  {
      write("You are not wicked enough to wield this weapon!\n");
      return 1;
   }
   write("You feel the Shadow staff pulse with energy.\n");
   ::wield();
   return 1;
}
