#include "/players/francesco/univ/ansi.h"
#define tpn this_player()->query_name()

inherit "obj/armor";
int worn;
int a;
object ob;
string filetext;
string *lines;

reset(arg) {

if(arg) return;
  ::reset(arg);
set_name("cloak");
set_alias("university cloak");
set_short("University cloak");
set_long(
   "This cloak is made by very light and smooth silk.  You can 'wrap' it around\n"+
   "your neck and you will enjoy the soft embrace of it.  Delicate drawings are \n"+
   "painted over it, reporting some actions of the past life in the Dept. of Mech.\n"+
   "Engr. of the Nirvana University.  Be proud of wearing it.\n");
set_ac(1);
set_type("misc");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(1);
set_value(350);
}

init() {
::init();
  add_action("trade","trade");
  add_action("wear","wear");
  return 1;
}

wear(str) {
   if(!str) {notify_fail("Wear what?\n"); return 0;} 
   if(!id(str) || environment() != this_player() || worn) return 0;
if(read_file("/players/francesco/quest/log/cloak"+this_player()->query_real_name(),1,1)) 
{ if(present("bug",this_player())) return 0;
  ::wear(str);   return 1; }
   else 
    {notify_fail("Eheh, you didnt get this armor by yourself.\n"); 
  return 0;}
return 0; }

do_special(owner) {
if(!environment()) return;
  if(!environment(this_object())->is_player()) return;
  tell_room(environment(owner),"ok\n");
  a = random(9);
  if(!random(2)) owner->heal_self(a);
return 1;
}

query_save_flag() { return 0; }
