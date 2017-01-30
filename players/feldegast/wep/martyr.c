#include "defs.h"

inherit "/obj/weapon.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("spear of the martyr");
  set_alias("spear");
  set_type("polearm");
  set_short("Spear of the "+RED+"Martyr"+NORM);
  set_long(
"This is a holy weapon of the P'kalian people.  It is said that during\n"+
"their escape from their Majiri oppressors, one of their leaders\n"+
"remained behind to delay their pursuers so that hundreds of P'kalians\n"+
"could escape into the countryside.  Before he was captured and\n"+
"executed he slayed over a dozen Majiri warriors.  This is the simple\n"+
"spear that he used, and its wooden haft still bears his green blood\n"+
"as well as the blood of the Majiri he killed.\n");
  set_class(18);
  set_weight(4);
  set_value(1500);
  set_hit_func(this_object());
}

int weapon_hit(object attacker) {
  if((int)this_player()->query_attrib("pie") + 5 > random(100)) {
    write(RED+"You sacrifice your blood for victory.\n"+NORM);
    this_player()->add_hit_point(-random(5));
    if((int)attacker->query_alignment() < (int)TP->query_alignment()) {
      write(BOLD+"Your staff glows with the strength of the righteous.\n"+NORM);
      say(BOLD+TPN+"'s staff glows with the strength of the righteous.\n"+NORM);
      if((int)attacker->is_player())
        attacker->add_hit_point(-random(5));
      else
        attacker->heal_self(-random(5));
    }
    return random(5);
  }
}
