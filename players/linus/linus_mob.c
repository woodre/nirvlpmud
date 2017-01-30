/* Ok, this is the stuff to be adding to your monster.
 * I'm assuming of course that you're inheriting /obj/monster.c or some 
 * other mob inherit, otherwise we'd have major issues heh.
 *
 * You should be able to just insert this code and follow the instructions
 * given, the only sticky stuff is debugging it (which I'll try to get to),
 * adding it to the mob code (I may get to this), and the three functions
 * you have to code.  I'll help out with those, or I'm sure Fred or Sparrow
 * or Pavlik or perhaps Khrell could help with.
 * My thought is that for the area effect, you simply divide out the total
 * damage, and deal that to everyone in the targs array.
 *
 * I listed base figures for the defines, they will no doubt be tweaked, but
 * I wanted to have something in there for you to start with.
 * NOTE:  with an sp-based monster like this, lifeblood will be a complete
 * and total crippling effect, but that's a good thing too.
 * 
 * FURTHER NOTE: right now I don't have any xp-modification going on, I'll
 * add that later, but I want to see what the mob gives first, and how it
 * compares to other mobs of that size.  With lifeblood being used, it'll make
 * it REALLY easy to nuke its sp and make it an easy kill for its size, 
 * otherwise it'll be a rough kill for its size, which may or may not be
 * the direction you wish to go in.  Just my two cents :)
 *
 * Anyways, enjoy.
 */
 
#define SPR 5
#define MAX_SP 1500

#define HEAL_COST 30
#define FOCUS_COST 100
#define AREA_COST 150

#define HEAL_AMOUNT 70
#define FOCUS_AMOUNT 100+random(50)
#define AREA_AMOUNT 300+random(150)

int sp;

int query_sp() { return sp; }
int query_msp() { return SP_MAX; }

void add_spell_point(int arg) { sp += arg; if (sp < 0) sp = 0; }
void add_sp(int arg) { sp += arg; if (sp < 0) sp = 0; }

/* in reset(0) (ie, !arg) have following lines:
 * sp = 1000;
 * add_spell("linus_is_the_shit", 0, 0, 100, 0, 0, 0, "spell_control");
 */
 
void heart_beat() {
  if (!attacker_ob) 
    sp += SPR;
  if (sp > SPR)
    sp = SPR;
    
  ::heart_beat();
}

/* You need to define the following functions:
 * void cast_heal();
 * void cast_focus(int num, object *targs);
 * void cast_area();
 *
 * For each of these spells you have to subtract the cost, apply the 
 * effect (ie, damage everyone in room, heal the mob, whatever) and
 * display the messages to the tank, rest of room.
 */
 
object *get_attackers() {
  int i;
  object *obs;
  object ob;
  
  i = 0; obs = ({ });
  ob = first_inventory(environment(this_object()));
  
  while(ob) {
    if ((object)ob->query_attack() == this_object())
      obs += ({ ob });
    
    ob = next_inventory(ob);
  }
  return obs;
}

void spell_control(object target, object room, int damage) {
  object *targs; /* array of everything hitting this bastich */
  int num;       /* how many are hitting this bastich) */
  
  /* Not enough sp to cast the lowest spell, so do other stuffs */
  if (sp < HEAL_COST) {
    /* prolly make sure that the wc is beefed */
    /* ac beefed */
    /* perhaps give players notice that it is */
    return;
  }
  
  /* First priority is staying healed */
  if (max_hp - hit_point > HEAL_AMOUNT) {
    cast_heal();
    if(sp < FOCUS_COST || random(100) < 15)
      return; /* 15% chance to cast again failed, or not enough sp */
    if (sp < AREA_COST) {
      cast_focus(); /* only has enough sp to cast the focused spell */
      return;
    }
    
  /* if 2 or more attackers, see if an area effect or targetted spell is
   * preferred.  Add 20% chance per attacker beyond the first.
   */
  num = sizeof(targs = get_attackers());
  if (num < 2 || (num -1)*20 < random(100))
    cast_area(num, targs);
  else
    cast_focus();
}
