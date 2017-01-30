#include <ansi.h>
#define CO call_other

inherit "obj/weapon";

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name(RED+"Berzerker Axe "+HIW+"["+HIC+"Chaos Honed"+HIW+"]"+NORM);
   set_class(15);
   set_weight(1);
   set_value(4000);
   set_type("axe");
   set_alias("great axe");
   set_alt_name("berzerker axe");
   set_short(RED+"Berzerker Axe "+HIW+"["+HIC+"Chaos Honed"+HIW+"]"+NORM);
   set_long(
      "This great axe is enchanted with a mystic power to make it light as a feather.\n"+
      "The mystic force seems to have taken away from its combat effectivness, maybe\n"+
      "it has a special use.\n");

   set_hit_func(this_object());
}

query_wear() {
   return 1;
}

weapon_breaks() {
   return 1;
}

weapon_hit(attacker) {

   int axehit;
   axehit=random(1000);
      if(!random(5) && check_race(attacker)){
       if(!attacker) return 1;

        tell_room(environment(this_player()),
HIC+"Chaos is unleashed!!!!!!!\n"+NORM+""+
RED+"  .o oOOOOOOOo                                            OOOo\n"+
"   Ob.OOOOOOOo  OOOo.      oOOo.                      .adOOOOOOO\n");
        tell_room(environment(this_player()),
"   OboO''''''''''''.OOo. .oOOOOOo.    OOOo.oOOOOOo..'''''''''''OO\n"+
"   OOP.oOOOOOOOOOOO 'POOOOOOOOOOOo.   `'OOOOOOOOOP,OOOOOOOOOOOB'\n");
        tell_room(environment(this_player()),
"   `O'OOOO'     `OOOOo'OOOOOOOOOOO` .adOOOOOOOOO'oOOO'    `OOOOo\n"+
"   .OOOO'            `OOOOOOOOOOOOOOOOOOOOOOOOOO'            `OO\n");
        tell_room(environment(this_player()),
"   OOOOO                  'OOOOOOOOOOOOOOOO`                 oOO\n"+
"  oOOOOOba.                .adOOOOOOOOOOba               .adOOOOo.\n");
        tell_room(environment(this_player()),
" oOOOOOOOOOOOOOba.    .adOOOOOOOOOO@^OOOOOOOba.     .adOOOOOOOOOOOO\n"+
"OOOOOOOOOOOOOOOOO.OOOOOOOOOOOOOO'`  ''OOOOOOOOOOOOO.OOOOOOOOOOOOOO\n");
        tell_room(environment(this_player()),
"OOOO'       'YOoOOOOMOIONODOO'`  .   ''OOROAOPOEOOOoOY'     'OOO'\n"+
"   Y           'OOOOOOOOOOOOOO: .oOOo. :OOOOOOOOOOO?'         :`\n");
        tell_room(environment(this_player()),
"   :            .oO%OOOOOOOOOOo.OOOOOO.oOOOOOOOOOOOO?         .\n"+
"   .            oOOP'%OOOOOOOOoOOOOOOO?oOOOOO?OOOO'OOo\n");
        tell_room(environment(this_player()),
"                '%o  OOOO'%OOOO%'%OOOOO'OOOOOO'OOO':\n");
        tell_room(environment(this_player()),
"                     `$'  `OOOO' `O'Y ' `OOOO'  o             .\n"+
"   .                  .     OP'          : o     .\n"+
"                            :\n"+NORM);

      attacker->heal_self(-(15+random(10)));
      return 1;
   }
}

check_race(object ob) {
  if(
    CO(ob,"id","chaos") ||
    CO(ob,"id","dark demon") ||
    CO(ob,"id","broo") ||
    CO(ob,"id","rhino broo") ||
    CO(ob,"id","sembrak") ||
    CO(ob,"id","cacodemon") ) return 1;
  else return 0;
}
