#include "/players/wocket/closed/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

message_hit = ({
  "tickled"," in the stomach",
  "grazed","",
  "hit","",
  "hit"," hard",
  "hit"," very hard",
  "smashed"," with a bone crushing sound",
  "massacre"," to small fragments",
  });

set_name("sword");
set_alias("lies");
set_alt_name("sword of lies");
set_short("Sword of Lies");
set_long("The Sword of Lies glows a brillant blue.\nNothing is what it appears.\n");
  set_type("sword");
  set_class(18);
  set_weight(2);
  set_value(500);
  set_hit_func(this_object());
}

weapon_hit(attacker){
int W;
W = random(15);
if (W>10){
say(
  "\nThe Sword of Lies deceives its opponent, plunging deep into the heart.\n"+RED+"...BLOOD POURS AS MASSIVE DAMAGE ERUPTS...\n\n"+NORM);

write(
  "\nThe Sword of Lies deceives its opponent, plunging deep into the heart.\n"+RED+"...BLOOD POURS AS MASSIVE DAMAGE ERUPTS...\n\n"+NORM);
  return 4;
   }
return;
}

