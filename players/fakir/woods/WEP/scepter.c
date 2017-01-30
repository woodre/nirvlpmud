#include "/players/fakir/color.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;
  
  set_name("scepter");
  set_alias("staff");
  set_type("staff");
  set_short(WHITE+"Scepter of Light"+OFF);
  set_long("A glowing scepter carried by the King of the southern fairy\n"+
           "clan.  The clear crystal shaft pulses with the life forces\n"+
           "of his foes captured within.  There are some fairy symbols\n"+
           "etched into the crystal shaft you can read while holding the\n"+
           "staff firmly in your grip.\n");
  set_read("Power shall be granted to the low of stature and the weak, and\n"+
           "fairy magics will not perish from the realm, but endure forever.\n");
  set_class(16);
  set_weight(2);
  set_light(2);
  set_value(850);
  set_hit_func(this_object());
}
weapon_hit(attacker) {
   int w;
   w= random (30);
   if(w > 19 &&
   this_player()-> query_level() < 6) {
  say(WHITE+"The Scepter of Light"+OFF+" glows softly with the one power'\n"+
            "and captures some of the life essence of "+attacker->query_name()+".\n");
  write(WHITE+"The Scepter of Light"+OFF+" glows softly with the one power and\n"+
              "captures some of the life essence of "+attacker->query_name()+".\n");
  this_player()->heal_self(2);
return 5;
}
if(w < 6 &&
  this_player()-> query_level() < 6) {
  say(RED+"The Scepter of Light"+OFF+" ignites with the blood of its captive spirits\n"+
            "and siphons some of the life essence from "+attacker->query_name()+".\n");
  write(RED+"The Scepter of Light"+OFF+" ignites with the blood of its captive spirits\n"+
              "and siphons some of the life essence from "+attacker->query_name()+".\n");
  this_player()->heal_self(3);
return 5;
}

if(w < 11 && w > 5 && 
  this_player()->query_attrib("str") > 15) {

   write("The Scepter of Light glows and " +WHITE+" PURE FAIRY MAGIC "+OFF+ "\n\n"+

     RED+"                 S T E A L S  THE  S O U L\n\n "+OFF+

         "              from the mortal body of "+attacker->query_name()+"!!! \n\n");
return 7;
}
return;
}
