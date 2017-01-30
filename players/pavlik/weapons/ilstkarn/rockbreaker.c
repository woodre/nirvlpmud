#include "/players/pavlik/closed/colors.h"
inherit "obj/weapon.c";
#define RB BLU+"Rockbreaker"+NORM
#define ME capitalize(this_player()->query_name())
#define IT capitalize(attacker->query_name())

string col;

reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name(BLU+"Rockbreaker"+NORM);
  set_alias("rockbreaker");
  set_alt_name("mace");
  set_short(BLU+"Rockbreaker"+NORM);
  set_long(
    "Rockbreaker is not much to look at, but you realize that this\n"+
    "weapon is capable of falling even the largest of foes.  The heavy\n"+
    "mace is comprised of a large spiked sphere of rock joined with a\n"+
    "short length of cord.\n");
  set_type("mace");
  set_class(18);
  set_weight(6);
  set_value(1000);
  set_no_clean(1);
  set_hit_func(this_object());
  message_hit = ({
    HIB+"DESTROYED"+NORM, " with a "+HIB+"massive"+NORM+" swing of "+RB,
    HIY+"POUNDED"+NORM, " into the ground",
    "swung "+RB+" in a wide arc and "+HIB+"PULVERISED"+NORM, "",
    HIB+"SMaSHeD"+NORM, " with a "+HIB+"concussive"+NORM+" blow",
    HIW+"smashed"+NORM, " with a solid blow! "+BLU+"<CRUNCH!>"+NORM,
    HIM+"bashed"+NORM, " with the heavy spiked ball",
    HIB+"tapped"+NORM, " rather ineffectively",
  });

}

weapon_hit(attacker){
  int W;
  W = random(14);

  if(!random(3)) {
      switch_colors();
  }

  if(W > 9)  {
    int which;
    which = random(4);

if(which == 0) {
write(
"You swing the mighty "+RB+" over your head and bring it "+HIB+"CRASHING\n"+NORM+
"down on "+IT+"'s skull!  The deadly blow knocks your enemy to the ground!\n");
say(
ME+" swings the mighty "+RB+" overhead and brings it "+HIB+"CRASHING"+NORM+" down\n"+
"on "+IT+"'s head!!!\n");
}
if(which == 1) {
write(
"You swing the "+RB+" and "+HIG+"SQUASH "+NORM+IT+"'s head like a soft melon!\n");
say(
ME+" swings the "+RB+" and "+HIG+"SQUASHES "+NORM+IT+"'s head like a soft melon!\n");
}
if(which == 2) {
write(
"You hear the satisfying sound of "+HIY+"breaking bones"+NORM+".\n");
say(
"You hear the satisfying sound of "+HIY+"breaking bones"+NORM+".\n");
}
if(which == 3) {
write(IT+" "+HIW+"staggers"+NORM+" and nearly collapses.\n");
say(IT+" "+HIW+"staggers"+NORM+" and nearly collapses.\n");
}
    return 7;
  }

  return;
}

init() {
  ::init();
}

switch_colors() {
  string *my_colors;

  my_colors = ({
     HIR, RED, HIB, BLU, HIM, MAG, HIY, YEL, HIG, GRN, HIC, CYN, HIW
  });

  col = my_colors[random(sizeof(my_colors))];

  message_hit = ({
    col+"DESTROYED"+NORM, " with a "+HIB+"massive"+NORM+" swing of "+RB,
    "hefted the "+RB+" and "+col+"DEMOLISHED"+NORM, "",
    "swung "+RB+" in a wide arc and "+col+"PULVERISED"+NORM, "",
    "hurled the spiked ball through the air and "+col+"SHATTERED"+NORM, "",
    col+"smashed"+NORM, " with a concussive force! "+BLU+"<CRUNCH!>"+NORM,
    col+"clubbed"+NORM, " with the heavy spiked ball",
    col+"tapped"+NORM, " with little effect",
  });

}

