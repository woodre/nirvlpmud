/*Multiple hit one-use projectile weapon*/

inherit "obj/weapon.c";
#include "/players/dune/closed/guild/DEFS.h"
 
int dam,mhp,parts;
 
 
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("shuriken");
    set_alias("star");
    set_alt_name("guild_weapon");
    set_short("Ice Shuriken");
    set_long(
"This is an Ice Shuriken- a deadly throwing star made of shining\n"+
"crystals of ice. You can wield it or 'shuriken' an opponent.\n");
    set_class(12);
    set_weight(1);
    set_value(150);
    set_hit_func(this_object());
}
weapon_hit(object ob) {
  string obn;
  obn = ob->query_name();
  if(!random(3)) {
  say(
TPN+" slices through "+ob->query_name()+" with "+
  TP->query_possessive()+BOLD+"Ice Shuriken"+OFF+"!\n");
  write(
"You slice through "+obn+" with your "+BOLD+"Ice Shuriken"+OFF+"!\n");
return 2;
    }
return 1;
}
 
melt_star() {
  if(wielded) {
    say("Your Ice Shuriken melts from your grasp!\n");
  command("unwield shuriken",environment(this_object()) );
destruct(this_object());
return 1;
    }
else
  say("The Ice Shuriken melts away...\n");
destruct(this_object());
return 1;
}
 
throw_star(str)  {
object ob;
string sliver, meat;
int i;
if (!str)
write("Shuriken what?\n");
else
ob = present(str,environment(this_player()));
if(!ob || !living(ob)) {
write("To use: 'shuriken <monster>'.\n");
return 1;  }

/* added to prevent starting fights in no_fight rooms
   7/23/00 - Eurale  */
if(environment(this_player())->query_no_fight()) {
  write("The shuriken refuses to fly here....\n");
  return 1; }

if (ob->query_npc()){
meat = capitalize(str);
dam = random(12)+ 6;
mhp = ob->query_hp();
parts = random(2) + 2;
sliver = BOLD+"A sliver of ice rips into the "+meat+"\n"+
     "\t"+meat+" screams in pain!\n"+OFF;
if(dam > mhp) { dam = mhp - 1; }
  say(TPN+" throws "+TP->query_possessive()+" Ice Shuriken at the "+
      meat+"!\n\n");
if( parts == 2 )  {
  write("The Shuriken splits in twain as you throw it!\n"+"\n");
  say("The Shuriken splits in twain!\n");
    }
  else {
  write("The Shuriken splits apart as you throw it!\n"+"\n");
  say("The Shuriken splits apart!\n");
    }
  for(i=0; i<parts; i++) {
    tell_room(environment(TP), sliver);
    ob->heal_self(-dam); }
this_player()->attack_object(ob);
if(living(ob)) ob->attack_object(this_player());
  if(wielded) command("unwield shuriken", this_player());
destruct(this_object());
return 1;
}
write("You cannot attack players with this.\n");
}

init()
{
  ::init();
  if((environment()==this_player()) && (find_call_out("melt_star")==-1))
     call_out("melt_star", 2000);
  add_action("throw_star", "shuriken");
}
