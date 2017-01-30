#include "/players/fakir/color.h"
#define tp this_player()->query_name()
int x;
inherit "obj/weapon.c";
reset(arg) {
   ::reset(arg);
   if (arg) return;
   set_name("blood-lance of destruction");
   set_alias("lance");
   set_type("spear");        
   set_short(BOLD+BLUE+"~"+OFF+""+RED+"Blood-Lance of Destruction"+OFF+""+BOLD+BLUE+"~"+OFF);
   set_long(
      "   Shrouded in mystery, the origin of this lance is not well known.\n"+
      "Some have said it is forged in the bowels of Nirvana, though those\n"+
      "who speak of such things often know nothing of the truth.  To wield\n"+
      "this awsome weapon is a privilege one must purchase with gold coin\n"+
      "of the realm.  Glittering gold letters twine about the lance shaft.\n");
   set_read(YELLOW+"The rune reads:\n\n"+
      "Use me once, use me wise. My power knows no bounds, as life departs."+OFF+"\n");
   set_class(21);
   set_weight(2);
   set_value(60000);
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
   write("The lance glows with "+WHITE+"Awsome Power"+OFF+" and your blood bonds the "+BOLD+BLUE+"~"+OFF+""+RED+"Lance of Destruction"+OFF+""+BOLD+BLUE+"~"+OFF+" to your hand.\n");
   say("The lance "+BOLD+RED+"handle"+OFF+" drains the blood from "+this_player()->query_name()+".....\n");
   ::wield(str);
   return 1; }

un_wield(str) {
   if(!id(str)) return 0;
   if(x) new_desc(); 
   if(!wielded) {
      notify_fail("You are not wielding the lance!\n");
      return 0; }
   write("The "+BOLD+RED+"power of the lance"+OFF+" departs and releases its blood-bond with you...\n");
   say("The "+BOLD+RED+"power of the lance"+OFF+" departs and releases its blood-bond on "+this_player()->query_name()+".....\n");
   ::un_wield(str);
   return 1; }

drop() {
   if(x) new_desc();
   ::drop();  }

new_desc() {
   short_desc ="A Broken Lance";
   long_desc = "A dull, broken lance, once used in battle but now badly damaged.\n";
   
}
weapon_hit(attacker){
   if(call_other(this_player(), "query_attrib", "pie") > random (60))
      {
      
      if(attacker->query_alignment() < this_player()->query_alignment())  {
         
         tell_room(environment(this_player()),
            
            "The Lance Of Redemption -----> "+RED+"*^*"+OFF+""+CYAN+" S T R I K E S  D E E P  I N T O  E V I L"+OFF+""+RED+" *^*"+OFF+"\n\n"+
            "      "+YELLOW+"----->|||*GREED*|||"+OFF+"\n"+
            "                   "+WHITE+"----->|||*LIES*|||"+OFF+"\n"+
            "                                "+MAGENTA+"----->|||*ENVY*|||"+OFF+"\n\n");
         return 7;
      }
      
      
   }
   return;
}
