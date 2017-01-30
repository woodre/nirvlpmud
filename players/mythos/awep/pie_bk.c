/*******************************
*  check /players/mythos/amon/priest.c
*   approved by saber
*******************************/
#include "/players/mythos/closed/ansi.h"
#define tp this_player()->query_name()
int w;
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("piety");
    set_alt_name("aura");
    set_short("Aura of Piety");
    set_long("An aura of piety- the embodiment of spiritual guidance.\n"+
             "A power to be reckoned with and respected.\n");
    set_class(17);
    set_weight(5);
    set_value(10000);
    set_hit_func(this_object());
}
weapon_hit(attacker){
object ob;
int m;
m=random(200);
if(call_other(this_player(),"query_attrib","pie") > m)
 {
 int n;
  say(BOLD+"\nThe Pure and Mighty have been angered!\n"+NORM+MAG+
       "Holy Fire roars down upon "+capitalize(attacker->query_name())+"!\n\n"+NORM);
  write(MAG+"\nYou call HOLY FIRE down upon your enemy!\n"+NORM);
  ob=all_inventory(attacker);
      for(n=0; n<sizeof(ob); n++) {
        if(ob[n]->query_broke() != 1){
          if(ob[n]->weapon_class() > 0) {
            ob[n]->weapon_breaks();
        tell_object(attacker,"Your weapon shatters from heat of the HOLY FLAME!\n");
        write("You shatter your foe's weapon with the power of the HOLY FLAME!\n");
          }}}
    call_other(this_player(),"add_hit_point",-random(4)-2);
  call_other(attacker,"heal_self",-2-random(4));
  write("You stagger back from the sheer power of the aura!\n"+
        "You realize that mortals can only use immortal powers with a price!\n");
       this_player()->lower_attrib(); 
       return 2;
}
if(69==n) {
write("You fumble the power of the immortals!\n");
  this_object()->weapon_breaks();
  ob=first_inventory(this_player());
      while(ob) {
        if(ob->query_broke() != 1){
          if(ob->weapon_class() > 0) {
            ob->weapon_breaks();
    write("You shatter your weapons!\n");
          }}
        ob=next_inventory(ob);}}
}

init() {
  ::init();
  add_action("wwield","wield");
}

wwield(str) {
  if(str == "aura" || str == "piety") {
write(MAG+"You feel the powers of one of the HOLY descend onto your shoulders.\n"+NORM);
   this_player()->set_title("the HOLY");
   }
   }
   
query_save_flag()  { return 1; }
