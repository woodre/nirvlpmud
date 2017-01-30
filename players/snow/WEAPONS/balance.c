/* WC: 15, non-storable, balances hps and sps if player is above lev.10
 * Return only possible if player has extralevels and
 * then a return of 4 at a chance of extra_level/30
 * Found on a huge Snow Demon with 1000 hps.
 */

inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("broadsword of balance");
    set_alias("broadsword");
    set_short("The Broadsword of Balance");
   set_type("sword");
    set_long(
"  This is the famed Broadsword of Balance. It is made of some unknown\n"+
"magical material and looks quite deadly. There are some inscriptions\n"+
"along the blade.\n");
    set_read("\n\t***** MIGHT ******\n\n\t***** MAGIC *****\n");
    set_class(15);
    set_weight(2);
    set_value(2000);
    set_hit_func(this_object());
message_hit = ({
  "hacked"," into a bloody, squirming mess on the floor",
  "sliced", " with a critical strike",
  "diced", " into tiny, pathetic little pieces",
  "pierced", " deeply, causing great pain",
  "chopped", " with a mad surgeon's grace",
  "slapped", " viciously with the flat of the blade",
  "cut", " lightly across the chest"
  });
}

/* So players can't switch weapons in combat */
wield(arg) {
  if(!id(arg) || (this_player() != environment())) return 0;
  if(this_player()->query_attack()) {
    write("You can't wield the Broadsword of Balance while in combat!\n");
    return 1; }
  ::wield(arg);
  return 1; }

weapon_hit(ob) {
  int lev, xlev, hp, sp, mhp, msp, num;
  object me, att;
  me = this_player();
  lev = me->query_level();
  xlev = me->query_extra_level();
  hp = me->query_hp();
  sp = me->query_sp();
  mhp = me->query_mhp();
  msp = me->query_msp();
  att = ob;
  if(lev < 10) return 0;
  if(!random(5)) {  /* 20% chance of balance */
  if(hp > (sp + 2) && !(hp > msp)) {
    num = hp - sp;
    num = num / 2;
    me->add_hit_point(-num);
    me->add_spell_point(num);
    write("\t***** MAGIC *****\n"); }
  if(sp > (hp + 2) && !(sp > mhp)) {
    num = sp - hp;
    num = num / 2;
    me->add_hit_point(num);
    me->add_spell_point(-num);
    write("\t***** MIGHT *****\n"); }
  }
  if(random(30) < xlev) return 4;
  else return; }
