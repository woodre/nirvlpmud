/* shotgun.c: midgets' shotgun */
int rounds;
inherit "obj/weapon";
reset(arg) {
  if(arg)
    return ;
  ::reset(arg);
  set_name("shotgun");
  set_alias("12-gauge shotgun");
  set_short("A 12-gauge shotgun");
  set_long("A hefty, menacing weapon. Obviously, the midget was much stronger than\n"
          +"he looked to be able to wield this item. It could probably do severe\n"
          +"damage to any opponent.\n");
  set_value(8000);
  set_class(14);
  set_weight(8);
  set_hit_func(this_object());
  rounds = 8;
}
id(str) { return str == "shotgun" || str == "12 gauge shotgun"; }
weapon_hit(attacker) {
  int i;
  object atk;
  atk = this_player()->query_attack();
  if(random(100) < 8) {
    write("You pull the trigger on your shotgun.\n");
    if(rounds == 0) {
      write("But they're no rounds left!\n");
      return 0;
    }
    rounds--;
    write("Your whole body shudders as the bullet flies through the barrel.\n");
    if(random(100) < 25) {
      write(capitalize(atk->query_name())+" is blown into pieces!\n");
      say(this_player()->query_name()+" fires a bullet straight through his foe!\n");
      i = 30+random(30);
      return (i>50?50:i);
    } else {
      write(capitalize(atk->query_name())+" is barely knicked by the shot!\n");
      say(this_player()->query_name()+" barely knicks his foe with a bullet!\n");
      return 10+random(15);
    }
  }
  return 0;
}
