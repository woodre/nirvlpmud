/* Seer code curtesy of Scooter@Nirvana (May 1992) */
inherit "obj/monster";
int vis;
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_long("This is a seer.  It was created by Scooter.\n");
  set_aggressive(0);
  set_level(20);
  set_ac(99);
  set_wc(0);
  set_hp(9999);
}
id(str) { return str=="seer"; }
invis(str) {
  vis=str;
  if(str==0) {
    is_invis=0;
    return;
  }
  if(str==1) {
    is_invis=10;
    return 1;
  }
}
