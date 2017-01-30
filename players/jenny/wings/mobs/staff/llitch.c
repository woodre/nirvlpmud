inherit "/obj/monster";
#include "/players/jenny/define.h"
int justonce;
id(str) { return str == "mike ilitch" ||  str == "mike" || str == "ilitch" || str == "Mike Ilitch"; } 
reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Mike Ilitch");
   set_race("human");
   set_gender("male");
   set_al(750+random(150));
   set_level(22);
   set_hp(600+random(200));
   set_wc(35+random(6));
   set_ac(19+random(3));
   set_heal(10,5);
   add_money(6000+random(2000));
   set_chance(23);
   set_spell_dam(45);
   set_spell_mess2("\n"+
"Mr. Ilitch reminds you that he didn't become such a powerful person by being a wimp.\n"+
                             "He then picks up a baseball bat and wacks you upside the head.  "+RED+"Blood "+NORM+"comes\n"+
                             "gushing out.\n");
   set_short(BOLD+WHT+"Mike Ilitch"+NORM);
   set_long(
      "Mike Ilitch is the owner of the Detroit Red Wings.  He is an older man\n"+
      "with short, dark, curly hair that is starting to grey.  Mike is wearing an\n"+
      "expensive black suit.  Mr. Ilitch has a reputation as one of the best owners\n"+
      "in the NHL.  He will do whatever is necessary to help his team win.  Besides\n"+
      "owning the Wings, Ilitch also owns the Detroit Tigers baseball team, the\n"+
      "Little Caesars pizza chain, and various other businesses.  He is the most\n"+
      "high profile businessman in Detroit.\n");
}
heart_beat() {
  ::heart_beat();
  if(TO->query_hp() < 250+random(200) && justonce < 1) security();
 }

      security() {
int xx;
object obj;
  if(!environment(this_object())) return 1;
  if(MEAT)
   if(environment() == environment(MEAT)) {
    say("\n"+
         BOLD+ "A security guard enters and drags you out of the office."+NORM+"\n");

obj = users();
for (xx = 0; xx < sizeof(obj); xx ++){
if(present(obj[xx], environment())) {
call_other("/players/jenny/wings/rooms/s2.c","ghettocode1");
MOCO("/players/jenny/wings/mobs/staff/security.c"),"/players/jenny/wings/rooms/s2.c");
obj[xx]->move_player("out the door#players/jenny/wings/rooms/s2.c");
}} 
call_other("/players/jenny/wings/rooms/s2.c","ghettocode2");

justonce = 2;
 return 1; }
return 1;
}
