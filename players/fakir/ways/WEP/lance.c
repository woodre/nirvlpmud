#include "/players/fakir/color.h"
#define tp this_player()->query_name()
int w;
int x;
inherit "obj/weapon.c";
reset(arg) {
   ::reset(arg);
   if (arg) return;
   set_name("lance of redemption");
   set_alias("lance");
   set_type("spear");        
   set_short(BOLD+BLUE+"~"+OFF+""+WHITE+"Lance of Redemption"+OFF+""+BOLD+BLUE+"~"+OFF);
   set_long(
      "   Warm to the touch and wrapped in a magic cloth of purest white, it is\n"+
      "the very same lance wielded by Sir San Ar'vel of the plains horsekeepers.\n"+
      "It glows with magic and power...and he who wields it shall profit if the\n"+
      "cause be just, and the aim be not for the heart, but rather for the evil\n"+
      "residing within.  An ancient script is inscribed upon the lance.\n");
   set_read(CYAN+"The script reads:\n\n"+
      "I, Sir San Ar'vel, have blessed this lance and imbued the cloth with\n"+
      "magics.  Once wielded, forsake it not until its power is spent, and\n"+
      "it shall serve thee well.  Glory in the redemption!"+OFF+"\n");
   set_class(19);
   set_weight(4);
   set_value(1000);
/*   set_save_flag(1); Make save -Bp */
   set_hit_func(this_object());
}
wield(str) {
   if(!id(str)) return 0;
   if(wielded) {
      notify_fail("The lance is already wielded!\n");
      return 0; }
   if(x) {
      notify_fail("The magics of the lance have been used up.\n");
      return 0; }
   x=1;
   write("The magic cloth glows "+WHITE+"translucent"+OFF+" and bonds the "+BOLD+BLUE+"~"+OFF+""+WHITE+"Lance of Redemption"+OFF+""+BOLD+BLUE+"~"+OFF+" to your hand.\n");
   say("The lance "+BOLD+WHITE+"handle"+OFF+" magically bonds with "+this_player()->query_name()+".....\n");
   ::wield(str);
   return 1; }

un_wield(str) {
   if(!id(str)) return 0;
   if(x) new_desc(); 
   if(!wielded) {
      notify_fail("You are not wielding the lance!\n");
      return 0; }
   write("The "+BOLD+WHITE+"magic in the lance"+OFF+" departs and releases its bond with you...\n");
   say("The "+BOLD+WHITE+"magic in the lance"+OFF+" departs and releases its bond on "+this_player()->query_name()+".....\n");
   ::un_wield(str);
   return 1; }

drop() {
   if(x) new_desc();
   ::drop();  }

new_desc() {
   short_desc ="A Broken Lance";
   long_desc = "A dull white lance, once used in battle but now badly damaged.\n";
   
}
weapon_hit(attacker){
   if(call_other(environment(), "query_attrib", "pie") > random(60))
      {
      
      if(attacker->query_alignment() < environment()->query_alignment()) {
         
         tell_room(environment(environment()),
            
            "The Lance Of Redemption -----> "+RED+"*^*"+OFF+""+CYAN+" S T R I K E S  D E E P  I N T O  E V I L"+OFF+""+RED+" *^*"+OFF+"\n\n"+
            "      "+YELLOW+"----->|||*GREED*|||"+OFF+"\n"+
            "                   "+WHITE+"----->|||*LIES*|||"+OFF+"\n"+
            "                                "+MAGENTA+"----->|||*ENVY*|||"+OFF+"\n\n");
         return 7;
      }
      
      
   }
   return;
}
locker_arg() {
  string blah;
  blah="-"+x+"="+w+"-";
  return blah;
 }
locker_init(arg) { 
  int blah,b;
  sscanf(arg,"-%d=%d-",blah,b);
  x = blah;
  w = b;
  }

