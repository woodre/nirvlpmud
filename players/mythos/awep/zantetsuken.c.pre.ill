/*******************************
*  check /players/mythos/amon/smith.c
*   approved by saber
*******************************/
#include "/players/mythos/closed/ansi.h"
#define tp this_player()->query_name()
 inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("zantetsuken");
    set_alt_name("sword");
    set_alias("katana");
    set_short(BLU+"Zantetsuken"+NORM);
  set_long("This is the legendary Zantetsuken.  It was known\n"+
    "to have cut through stone with great ease.  A very\n"+
    "valuable and dangerous weapon.\n");
    set_class(17);
    set_weight(5);
    set_value(100000);
    set_hit_func(this_object());
}
weapon_hit(attacker){
  object ob;
  string title;
  int n;
  n=random(300);
if(this_player())
if(call_other(this_player(),"query_attrib","ste") > n)
 if(random(20) < 10)
/* make much more rare. -Bp */
 {
 int m;
  say(HIB+"\n\n\tZantetsuken slices through "+attacker->query_name()+
  " with ease!\n\n"+NORM);
  write(HIB+"\n\n\tYou slice through your foe with ease!\n\n"+NORM);
  ob=all_inventory(attacker);
  for(m=0; m<sizeof(ob); m++) {
    if(ob[m]->armor_class() > 0) {
  attacker->set_ac(attacker->query_ac() - ob[m]->armor_class());
/* Change this to use broken function -Bp
        ob[m]->set_ac(0);
        ob[m]->set_value(0);
   title = "";
        title=ob[m]->short();
    ob[m]->set_save_flag(1); 
*/ /* Make broken armor unsavable. -Feldegast 10-31-00 */ /*
   if(title)
    if(title != "")
    ob[m]->set_short(title+"  <broken>");
*/
    ob[m]->armor_breaks();
        write("You slice through your opponent's armor!\n");
        say(capitalize(tp)+" slices through armor!\n");
    }}
    call_other(this_player(),"add_hit_point",-2-random(4));
  call_other(attacker,"heal_self",-2-random(4));
  write("You feel the power of the sword- it is immense!\n"+
         "Power comes with price....\n");
       this_player()->lower_attrib();
    return 2;
}
if(68==n) {
write("You fumble the power of the immortals!\n");
  this_object()->weapon_breaks();
  this_player()->hit_player(random(80));
}
if(69==n) {
write("You fumble the power of the immortals!\n");
  this_object()->weapon_breaks();
  ob=first_inventory(this_player());
      while(ob) {
       if(ob->armor_class() > 0) {
/* Again, use armor breaking function -Bp
        ob->set_ac(0);
        ob->set_value(0);
       ob->set_save_flag(1);
        title=ob->query_name();
        ob->set_short(capitalize(title)+" <broken>");
*/
        ob->armor_breaks();
        command("remove "+ob->query_name(),this_player());
    write("You shatter your armor!\n");
          }
        ob=next_inventory(ob);}}
}


/* make save -Bp
query_save_flag()  { return 1; }
jan -03 */

