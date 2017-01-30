#include "../define.h"
inherit WEAPON;

reset(arg) {
   if(arg) return;
   set_name("staff");
   set_alias("bladed staff");
   set_type("club");
   set_value(1000+random(100));
   set_long(
      " Leathery grips on the pommels of this staff are just\n"+
      "inside of three foot iron blades on either side of this\n"+
      "six foot staff.\n");
   set_weight(4);
   set_class(16); 
   set_wield_func(TO);
   set_message_hit(({
            BOLD+"slashed"+NORM," with great force",
            "tore away","'s flesh to the bone",
            "ripped into"," with pointed blades",
            "scathed"," with one end of the staff",
            "cut"," deeply, wounding the opponent",
            "scratched"," with a slight blow",
            "nicked"," gracefully", }));
   set_hit_func(TO);
}

weapon_hit(attacker) {
   string blob, msg1, msg2;
   int x, hit, dmg;
   x = random(3);
   hit = random(7);
   blob = attacker->QN;
   if(!x && (USER->query_attrib("ste") < random(30))) {
      tell_object(USER,"\n\nYou mishandle the bladed staff and it cuts into you!\n\n\n");
      say(USER->QN+" mishandles the bladed staff!\n",USER);
      USER->hit_player(5); }
   if(x) {
      x = 1+random(6);
      dmg = x;
      x*=2; x++;
      msg1 = message_hit[x-1]; msg2 = message_hit[x];
      write("You "+msg1+" "+attacker->QN+msg2+".\n");

      say(USER->QN+" "+msg1+" "+(attacker->QN) + msg2+".\n");
      return dmg; } }

query_save_flag() { return 1; }

wield(str) {
   object shield;
   if(id(str)) {
      shield = present("shield",TP);
      if(shield && shield->query_worn()) {
         FAIL("You cannot wield this weapon while wearing a shield!\n");
         return 0; }
   }
   ::wield(str);
   return 1; }

id(str) {  
   if(previous_object() && previous_object()->query_type() == "shield") return str == "notarmor"; else return str == "bladed staff" || str == "club" || str == "staff"; }


short()
{
    return "A bladed staff" + (wielded ? " (wielded in both hands)" : "");
}
