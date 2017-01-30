#define tp this_player()->query_name()
#define TP this_player()
inherit "obj/armor";
#include "/players/saber/closed/ansi.h"

string overload_count;
string snap_count;

reset(arg){
   ::reset(arg);
  if(arg) return; /* added */
   set_name("overload amulet");
   set_short("Overload Amulet");
   set_alias("amulet");
   set_long("A stark black amulet set with a red ruby.\n"+
       "It has a faint red aura, and is covered with runes.\n");
   set_type("amulet");
   set_ac(1);
   set_weight(1);
   set_value(3000);
}

init() {
  ::init();
add_action("snap","snap");
add_action("read","read");
}

read(str) {
if(str == "amulet" || str == "overload amulet") {
write("The amulet reads:\n"+
       "To overload this amulet of protection\n"+
       "You must <snap> it and than wear it.\n");
return 1; }
}

snap(str) {
if(!str) {
write("Snap what?\n");
return 1; }
if(str == "amulet" || str == "overload amulet") {
if(snap_count < 1) {
snap_count = snap_count + 1;
set_ac(random(5) + 1);
write("The amulet begins to glow a BRIGHT "+HIR+"red"+NORM+" color.\n");
say(tp+" snaps an amulet.\n"+
       "The amulet begins to glow a bright "+HIR+"red"+NORM+" hue.\n");
call_out("melt_away",1);
return 1; }
write("The amulet has already been snapped.\n");
return 1; }
}

melt_away() {
object ob;

  overload_count = overload_count + 1;
  ob = environment(this_object());
/* Added by Snow 10/99 */
  if(!ob || !living(ob) ) {
    if(overload_count > 6) { destruct(this_object()); return; }
    else call_out("melt_away", 60); return; }

if(overload_count == 1) {
  tell_room(environment(ob), ob->query_name()+" jumps as one of "+ob->query_possessive()+" amulets starts to emit a strange noise.\n");
        }

if(overload_count == 4) {
  tell_object(ob, "The amulet gets "+HIR+"VERY"+NORM+" hot.\n");
  tell_room(environment(ob), ob->query_name()+" jumps as if stung.\n"+
        "You smell something burning.\n");
        }

if(overload_count > 6) {
  tell_room(environment(ob), ob->query_name()+" is covered in a "+HIR+"red"+NORM+" aura as the Overload Amulet explodes!\n");
  tell_object(ob, "Ouch, ouch, ouch...\n");
/* Changing this for obvious reasons. -Snow 10/99
  command("drop amulet", ob);
*/
  this_object()->drop();
  destruct(this_object());
  return 1; }

  call_out("melt_away",60);
  tell_object(ob, "The amulet hums quietly.\n");
  return 1;
}
