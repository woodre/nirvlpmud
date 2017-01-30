/* Growth weapon inspired by Anshar guild ideas */
 
inherit "obj/weapon.c";
#include "/players/snow/closed/cyber/color.h"
 
int lev_hits, changes;
object user;
 
query_lev_hits() { return lev_hits; }
query_wear() { return 0; ::query_wear(); }
 
 reset(arg) {
  ::reset(arg);
  if (arg) return;
  set_name("titanium staff");
  set_alias("staff");
  set_short("Titanium Staff");
  set_long(
"This is a long staff made of shining titanium. There appear\n"+
"to be some sigils inscribed along its length.\n");
  set_read("As you study the staff, the sigils become clear:\n\n"+
           "\t"+BOLD+"<< My power grows with impact >>"+OFF+"\n\n");
  set_class(10);
  set_weight(3);
  set_value(100);
  set_hit_func(this_object());
  set_save_flag(0);
  lev_hits = 0; changes = 0;
}
 
weapon_hit(ob) {
  int oblev, mylev, adds;
  object me, att;
  me = this_player();
  oblev = ob->query_level();
  mylev = me->query_level();
  att = ob->query_attack();
  if(mylev < 10) {
    write("You swing ineffectually.\n"); return 0; }
  if(!user || user != me) {
    reset();
    user = me; }
  if(oblev > mylev) adds += oblev/4;
  if(att == me) {
    if(ob->query_wc() > 20) adds += (ob->query_wc() - 20)/2;
    if(ob->query_ac() > 10) adds += (ob->query_ac() - 10)/2; }
  if(att != me) adds --;
  lev_hits += adds;
  if(mylev > 20) {
    write("Lev_hits: "+lev_hits+" Changes: "+changes+"\n"); }
  if(changes == 0) {
    if(lev_hits > 50) {
      write(BOLD+"Your Titanium Staff grows in might!"+OFF+"\n");
      set_class(12);
      changes ++;
      do_change(me); }
  }
  if(changes == 1) {
    if(lev_hits > 150) {
      write(BOLD+"Your Titanium Staff grows in might!"+OFF+"\n");
      set_class(14);
      set_short(BLUE+"Titanium Staff"+OFF);
      changes ++;
      do_change(me); }
  }
  if(changes == 2) {
    if(lev_hits > 400) {
      write(BOLD+"Your Titanium Staff grows in might!"+OFF+"\n");
      set_class(16);
      set_short(REV_GREEN+"Titanium Staff"+OFF);
      changes ++;
      do_change(me); }
  }
  if(changes == 3) {
    if(lev_hits > 1000) {
      write(BOLD+"Your Titanium Staff grows in might!"+OFF+"\n");
      set_class(18);
      set_short(RED+"Titanium Staff"+OFF);
      changes ++;
      do_change(me); }
  }
  if(changes == 4) {
    if(lev_hits > 3000) {
      write(BOLD+"Your Titanium Staff grows in might!"+OFF+"\n\n"+
            REV_RED+"YOUR TITANIUM STAFF GLOWS WITH FURY!"+OFF+"\n");
      set_class(20);
      set_short(RED+"Titanium Staff"+OFF);
      changes ++;
      do_change(me); }
  }
  if(changes > 4) {
    if(att == me) me->add_hit_point(random(changes));
    if(random(3) == 1) {
      write("You bring the "+RED+"Titanium Staff"+OFF+
            " crashing onto "+ob->query_name()+"!\n");
      tell_room(environment(me), "\n"+BOLD+ob->query_name()+
            " reels backward in pain!"+OFF+"\n\n");
      ob->heal_self(-changes); }
    if(lev_hits > 10000) changes = 6;
    if(lev_hits > 20000) changes = 7;
  }
  return;
}
 
do_change(object ob) {
  command("unwield titanium staff", ob);
  command("wield titanium staff", ob);
  return 1;
}
