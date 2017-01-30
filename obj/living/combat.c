#pragma strong_types

#include <armor.h>
#include <wizlevels.h>
#include <prop/player.h>
#include <prop/living.h>
#include <prop/npc.h>
#include <message.h>
#include <event.h>
#include <server.h>
#include <filters.h>
#include <living_ld.h>
#include <is_wizard.h>

varargs status test_sight(object where, int silently);
void transfer_all_to(object target);
status query_ghost();
string query_name();
int query_alignment();
int query_npc();
int query_sta();
int query_int();
int query_dex();
int query_exp();
int query_hp();
int query_sp();
int query_max_hp();
void set_hp(int h);
void set_sp(int s);
int add_exp(int e);
mixed query_property(mixed prop);
int query_level();
string query_real_name();
varargs void run_away();
int query_gender();
void stop_show_long_delayed();

void recompute_armor_class();

/*
 *  obj/living/combat
 *
 *  This object consists of three sections:
 *
 *  I. Combat
 *  II. Combat Equipment
 *  III. Spells
 */

private static object previous_object_for_die;
private mixed corpse_for_die;
private int whimpy;                     // automatically run when low on HP
                                        // 1: wh_tresh in percent
                                        // 2: wh_tresh in hit points;
private mixed wh_thresh;

private static object name_of_weapon;   // to see if we are wielding a weapon
private static int    weapon_class;
private static int    armor_class;      // what armor class we have
private static object *armor;           // what armor we have
private static object hunted, hunter;   // used in the hunt mode
private static int    hunting_time;     // how long we will stay in hunting mode
private static object attacker_ob;      // our enemy
private static mapping alt_attacker_ob; // a mapping holding all other enemies
private static status passive_attack;   // were we attacked or did we attack
private static string spell_name;
private static int    spell_cost, spell_dam;
private static object last_weapon, last_armor;
private static mapping damage_map;      // how much damage made someone to me
                                        // in current combat, necessary for
                                        // splitting up exp at end of combat,
private static mixed  death_message;
                      //  0: print 'monster died', !0: print the string instead
private static int    corpse_weight;
private static int    corpse_mass;


void check_armor() {  // usually armors remove themselves upon destruction;
                      // this is for those armors that do not do it to avoid
                      // complications
  if (pointerp(armor)) {
    armor -= ({ 0 });
    recompute_armor_class();
  }
}

void set_death_mess(mixed m) {
  death_message = m;
}

int query_corpse_weight() {
  return corpse_weight || 5;
}

static void set_corpse_weight(int w) {
  corpse_weight = w;
}

int query_corpse_mass() {
  return corpse_mass;
}

static void set_corpse_mass(int m) {
  corpse_mass = m;
}

int query_ac() {
  check_armor();
  return armor_class;
}

int query_wc() {
  if (!query_npc() && weapon_class && !name_of_weapon)
    weapon_class = 0;
  return weapon_class;
}

object* query_alt_attack() {
  return alt_attacker_ob ? (m_indices(alt_attacker_ob) - ({ 0 })) : ({ });
}

object query_attack()     { return attacker_ob; }
int    query_wimpy()      { return whimpy; }
object query_wield()      { return name_of_weapon; }
int    query_wimpy_level() { return funcall(wh_thresh); }

object* query_armor() { 
  check_armor();
  return armor ? armor[0..] : ({ });
}

void set_wimpy(varargs mixed w) {
  if (!sizeof(w)) {
    if (query_npc())
      whimpy = 1;
  } else {
    whimpy = !!w[0] + (w[0] == 2);
  }
}
    
void set_wimpy_level(mixed lvl) {
  wh_thresh = lvl;
}

/*
 *  I. Combat
 */
     
/////////////////////////////
// next functions for combat events
//

void create() {
  listen_event("attack", EPRIO_CANCEL, "receive_attack_event");
  listen_event("attack", EPRIO_HANDLE, "receive_attack_event");
}

varargs void stop_fight(status totally) {
  int l;
  object *att;
  if (totally)
    attacker_ob = 0;
  else
    attacker_ob = (l = sizeof(att = query_alt_attack())) &&
                  att[random(l)];

  if (totally)
    alt_attacker_ob = ([ ]);
  else
    alt_attacker_ob = m_delete(alt_attacker_ob || ([ ]), attacker_ob);
  if (!sizeof(alt_attacker_ob))
    alt_attacker_ob = 0;
}

object query_hunter() {
  return hunter;
}

void stop_hunter(status silently) {
  hunter = 0;
  if (!silently)
    tell_object(this_object(), "You are no longer hunted.\n");
}

object query_hunted() {
  return hunted;
}

static void stop_hunted() {
  hunted = 0;
}

void stop_attack(object attacker) {
  attacker_ob = 0;
  attacker->stop_fight();
  attacker->stop_hunter(1);
}

// returns 1 if the attack shall be stopped
static varargs status test_attack(object attacker, object attacked) {
  mixed p;

  attacked = attacked || this_object();
  if (p = attacked->query_property(P_NOT_FIGHTABLE)) {
    if (intp(p)) {
      send_message(({ M_TARGETS, attacker, "You cannot kill ",
                      M_OBJECT, M_THE, attacked, "." }));
      return 1;
    } else if (stringp(p) || closurep(p)) {
      message(funcall(p));
      return 1;
    } else if (sizeof(p) > 1) {
      if (!apply_function(p[1])) {
        message(funcall(p[0]));
        return 1;
      }
    } else {
      message(funcall(p[0]));
      return 1;
    }
  }
  return 0;
}

// returns true if there will be a fight.
status set_attack(object attacker, status force_attack, status passive) {
  mixed p,cl;
#if 0
#  if 0
  if (attacker == this_object())  // auto-aggression?
    return 1;  // ignore this.
#  endif
#else
  if (attacker == this_object())  // auto-aggression?
    return 0;  // do not start such a fight.
#endif
  if (test_attack(attacker)) {
    stop_attack(attacker);
    return 0;
  }
  if (attacker_ob &&
      (attacker==attacker_ob || member(alt_attacker_ob || ([ ]), attacker)) &&
      !force_attack)
    return 1;
  if (!attacker_ob) {
    passive_attack = passive;
    attacker_ob = attacker;
    return 1;
  }
  else if (!sizeof(alt_attacker_ob || ([ ])) && !force_attack) {
    passive_attack = passive_attack || passive;
    if (attacker)
      if (alt_attacker_ob)
        alt_attacker_ob += ([ attacker ]);
      else
        alt_attacker_ob = ([ attacker ]);  
    return 1;
  }
  else if (!force_attack)
    return 0;
  passive_attack = passive_attack || passive;
  alt_attacker_ob = (alt_attacker_ob || ([ ])) + ([ attacker_ob ]);
  attacker_ob = attacker;
  return 1;
}

// This routine is called when we are attacked by a player.
void attacked_by(object attacker) {
  set_attack(attacker, 1, 1);
  if (attacker_ob)
    set_heart_beat(1);
}

status query_attacked() {
  return query_attack() && passive_attack;
}

/*
 * Return true if there still is a fight.
 */
status attack() {
  int tmp, fighter;
  mixed whit;
  string name_of_attacker;
  object ob;

  if (!attacker_ob) {
    spell_cost = 0;
    spell_dam = 0;
    return 0;
  }
  name_of_attacker = attacker_ob->short();
  if (attacker_ob->query_ghost() ||
      environment(attacker_ob) != environment()) {
    if (!hunter && name_of_attacker && !attacker_ob->query_ghost()) {
      send_message(({ M_WRITE, "You are now hunting ", M_OBJECT,
                      M_THE, attacker_ob, "." }));
      hunted = attacker_ob;
      hunting_time = 10;
    }
    spell_cost = 0;
    spell_dam = 0;
    attacker_ob = 0;
    if (!tmp = sizeof(alt_attacker_ob || ([ ])))
      return 0;
    attacker_ob = m_indices(alt_attacker_ob || ([ ]))[random(tmp)];
    alt_attacker_ob = m_delete(alt_attacker_ob, attacker_ob);
    if (tmp == 1)
      alt_attacker_ob = 0;
    if (attack()) {
      if (attacker_ob)
        send_message(({ M_ME_THE, M_ME_VERB, "turn", " to attack ", M_THE,
                        M_OBJECT, attacker_ob, "." }));
      return 1;
    }
    return 0;
  }
  if (spell_cost) {
    set_sp(query_sp()-spell_cost);
    spell_cost = 0;
    tell_object(attacker_ob, "You are hit by a "+spell_name+".\n");
    write("You cast a "+spell_name+".\n");
  }
  if (ob = query_wield()) {
    whit = ob && ob->hit(attacker_ob);
    if (!attacker_ob) {
      if (!query_wield())  // added check for selfdestructing of selfremoving
        return 1;          // weapons (there are some with aligment checks),
      tell_object(this_object(), "CRACK!\nYour weapon broke!\n");
      log_file("BAD_SWORD", ob->short() + ", " + creator(ob) + " XX !\n");
      spell_cost = 0;
      spell_dam = 0;
      destruct(ob);
      return 1;
    }
  }
  if (whit == "miss")
    tmp = 0;
  else
#if 1  // for normal players this is about the same,
       // but non-spell casters will be a bit better
    tmp = (  (query_wc() + whit) + query_dex()) / 2;
#else
    tmp = (2*(query_wc() + whit) + query_dex()) / 3;
#endif
  whit = 0;
#if 1  // added this as random() tends to choose
       // small values with a higher priority
  fighter = 0;
  if (query_dex() > 35) {
    fighter = tmp - 35;
    tmp = 35;
  }
  tmp=attacker_ob->hit_player(random(tmp) + spell_dam + fighter, this_object());
#else
  tmp=attacker_ob->hit_player(random(tmp) + spell_dam, this_object());
#endif

  tmp -= spell_dam;
  if (!query_npc()
      && query_wield()
      && tmp > 20
      && random(100) < query_wc() - query_level() * 2 / 3 - 14) {
    tell_object(this_object(), "CRACK!\nYour weapon broke!\n");
    tell_object(this_object(),
                "You are too inexperienced for such a weapon.\n");
    log_file("BAD_SWORD", query_wield()->short()+", "
             + creator(query_wield())+"\n");
    spell_cost = 0;
    spell_dam = 0;
    destruct(query_wield());
    return 1;
  }
  tmp += spell_dam;
  if (!attacker_ob)
    return 0;
  if (tmp == 0) {
    send_message(({ M_ME_THE, M_ME_VERB, "miss", M_THE, M_OBJECT,
                    attacker_ob, "." }));
    spell_cost = 0;
    spell_dam = 0;
    return 1;
  }
  add_exp(tmp);
  tmp -= spell_dam;
  spell_cost = 0;
  spell_dam = 0;

  // driver complains about: Call from destructed object '' ignored.
  // program: obj/living/combat.c, object: xxxxx line 391; this is the line
  // with the ghost check below. So check for this_object() first.
  if (!this_object()) {
    attacker_ob = 0;
    alt_attacker_ob = ([ ]);
    return 0;
  }

  /* Does the enemy still live? */
  if (attacker_ob && !attacker_ob->query_ghost()) {
    string what, how;
    if (tmp < 2) {
      what = "tickle";
      how = " in the stomach";
    } else if (tmp < 3) {
      what = "graze";
      how = "";
    } else if (tmp < 5) {
      what = "hit";
      how = "";
    } else if (tmp < 10) {
      what = "hit";
      how = " hard";
    } else if (tmp < 20) {
      what = "hit";
      how = " very hard";
    } else if (tmp < 30) {
      what = "smash";
      how = " with a bone crushing sound";
    } else {
      what = "massacre";
      how = " to small fragments";
    }
    send_message(({ M_ME_THE, M_ME_VERB, what, M_OBJECT, M_THE, attacker_ob,
                    how, "." }));
    if (tmp && query_wield())
      query_wield()->decay(tmp/7 + 1);

    // 1:SWITCH_TARGET to switch attack_ob and alt_attack_ob, only monsters
    if (sizeof(filter(query_alt_attack(),
                      #'present, environment())) &&
        !random(SWITCH_TARGET) && query_npc()) {
      ob = attacker_ob;
      attacker_ob = query_alt_attack()[random(sizeof(query_alt_attack()))];
      alt_attacker_ob = m_delete(alt_attacker_ob, attacker_ob);
      alt_attacker_ob += ([ ob ]);
      if (name_of_attacker = attacker_ob->short()) {
        send_message(({ M_ME_THE, M_ME_VERB, "turn", " to attack ",
                        M_THE, M_OBJECT, attacker_ob, "." }));
      }
    }
    return 1;
  }
  if (alt_attacker_ob && sizeof(alt_attacker_ob)) {
    attacker_ob = m_indices(alt_attacker_ob)[random(sizeof(alt_attacker_ob))];
    m_delete(alt_attacker_ob, attacker_ob);
    if (!sizeof(alt_attacker_ob))
      alt_attacker_ob = 0;
  } else
    attacker_ob = 0;
  if (attacker_ob)
    return 1;
  return 0;
}

// this function is called e.g. by kill() in the player object
void attack_object(object ob) {
  if (!ob)
    return;
  if (ob->query_ghost())
    return;
  set_heart_beat(1);   /* For monsters, start the heart beat */
  if (attacker_ob == ob) {
    attack();
    return;
  }
  if (alt_attacker_ob && member(alt_attacker_ob, ob)) {
    if (attacker_ob)
      alt_attacker_ob += ([ attacker_ob ]);
    m_delete(alt_attacker_ob, ob);  
    attacker_ob = ob;
    attack();
    return;
  }
  if (set_attack(ob, 1, 0)) {
    ob->attacked_by(this_object());
    attack();
  }
}

static void log_illegal_armors(object a) {
  string type;
  int class;

  type = a->query_type();
  class = a->query_class();
  
  if (!query_once_interactive(this_object())  // don't log npcs
      || !class                               // don't log if class == 0
      || last_armor == a 
      || this_object()->query_level()>=WL_APPRENTICE)
                                              // no wizzes
    return;

  if ((member(ARMOR_TYPES,type) < 0)          // no legal armor type or...
      || (class > 1 && type != "armor")       // not "armor" and class >1...
      || class > 4)                           // or class > 4
    {
    last_armor = a;
    log_file("ARMOR", ctime (time ()) + ": "
             + (load_name (a) != "obj/armor" ?
              load_name (a) : 
              "armor created by " + a->query_cloned())
             + ", type "+type+", AC "+class+", worn by "
             + this_object()->query_real_name()+".\n");
  }
}

static void log_illegal_weapon(object weapon) {
  int wc;
  status own_file;

  wc = weapon->query_class();

  if (!query_once_interactive(this_object())     // don't log npcs
      || (wc <= 17                               // normal weapon
      || (wc <= 19 &&                            // twohander
          member(inherit_list(weapon), "obj/twohander.c") >= 1))
      || last_weapon == weapon                   // not again
      || this_object()->query_level () >= WL_APPRENTICE)
                                                 // no wizzes
    return;

  last_weapon = weapon;
  if (load_name(weapon) != "obj/weapon" &&
      load_name(weapon) != "obj/twohander")
    own_file = 1;
  log_file("WEAPON", ctime() + ": " +
           (own_file ? load_name (weapon)
                     : "weapon created by " + weapon->query_cloned()) +
           ", WC " + wc + ", wielded by " + query_real_name() + ".\n");
}

/* Wear some armor. */
object wear(object a, status silently) {
  int i;
  string type;
	
  if (!armor)
    armor = ({ });
  recompute_armor_class();
  type = a->query_type();
  for (i=0; i<sizeof(armor); i++)
    if (armor[i]->query_type()==type)
      return armor[i];
  armor += ({ a });
  log_illegal_armors(a);
  recompute_armor_class();
  return 0;
}

void recompute_armor_class() {
  int i, s;
  if (!armor)
    return armor_class = 0;
  armor = filter(armor, "armor_filter", this_object());
  for (s=0, i=0; i<sizeof(armor); i++) 
    s += armor[i]->armour_class();
  armor_class = s;
}

void add_armor(object arms) {
  if (!objectp(arms))
    return;
  if (!armor)
    armor = ({});
  armor += ({arms});
  log_illegal_armors(arms);
  recompute_armor_class();
}

void subtract_armor(object arms) {
  if (!objectp(arms))
    return;
  armor -= ({arms});
  recompute_armor_class();
}

void stop_wielding() {
  if (!name_of_weapon) {
    /* This should not happen! */
    log_file("wield_bug", "Weapon not wielded!\n");
    write("Bug! The weapon was marked as wielded! (fixed)\n");
    return;
  }
  name_of_weapon->unwield(query_ghost());
  name_of_weapon = 0;
  weapon_class = 0;
}

void wield(object weapon, status silently) {
  if (!objectp(weapon))
    return raise_error("Bad argument 1 to wield()!\n");
  if (name_of_weapon && name_of_weapon != weapon)
    stop_wielding();
  name_of_weapon = weapon;
  if (!(weapon_class = weapon->query_class()))
    weapon_class = weapon->weapon_class();
  log_illegal_weapon(weapon);
}

void stop_wearing(object a, status silently) {
  if (!armor)
    armor = ({ });
  armor -= ({ a });
  recompute_armor_class();
}

object get_random_protecting_armor() {
  if (!sizeof(armor))
    return 0;
  return armor[random(sizeof(armor))];
}

static status armor_filter(object a) {
  return objectp(a) &&  environment(a)==this_object();
}

void leave_combat() {
  hunting_time -= 1;
  spell_cost = 0;
  spell_dam = 0;
  if (hunting_time <= 0) {
    if (hunter)
      hunter->stop_hunter();
    hunter = 0;
    hunted = 0;
  }
  if (attacker_ob && present(attacker_ob)) {
    hunting_time = 10;
    if (hunter != attacker_ob && attacker_ob)
      tell_object(this_object(), "You are now hunted by " +
                  describe(attacker_ob, ARTICLE_THE, DESCRIBE_FULL)+".\n");
    hunter = attacker_ob;
  }
}

void enter_combat() {
  if (hunted && present(hunted))
    attack_object(hunted);
  if (hunter && present(hunter))
    hunter->attack_object(this_object());
}

varargs void perform_death(object from, object orig_from) {
  object corpse;
  if (!query_property(P_NO_CORPSE))
    corpse = funcall(query_property(P_CORPSE) || "obj/corpse");
  if (corpse && stringp(corpse))
    corpse = clone_object(corpse);
  if (corpse)
    corpse->set_race(this_object()->query_race());
  send_event("death",
             ([ E_AGENT : orig_from || attacker_ob,
                E_FROM  : from,
                E_TARGET: this_object(),
                E_OBJECT: previous_object(), // for the wizlist in die()
                E_TO    : corpse,
                ]), get_room(this_object()));
}

void receive_attack_event(mapping e, string type, int prio) {
  object from, orig_from, tmp;
  mixed corpse;
  int hp;  // our hp
  int dam;

  switch (prio) {
  case EPRIO_CANCEL:
    if (e[E_CANCELLED])
      return;
    if (e[E_TARGET] != this_object())
      return;
    if (!query_npc() && !query_ip_number(this_object())) {
      /* Don't hurt statues */
      write("Don't attack statues. You would only hurt yourself.\n");
      stop_fight();
      if (this_player())
        this_player()->stop_fight();
      e[E_CANCELLED] = 1;
      return;
    }
    break;

  case EPRIO_HANDLE:
    if (e[E_HANDLED] || e[E_CANCELLED])
      return;
    if (e[E_TARGET] != this_object())
      return;
    e[E_HANDLED] = 1;
    if (!attacker_ob)
      set_heart_beat(1);
    from = e[E_AGENT];
    dam = e[E_DAMAGE];
    if (from) {
      if (living(from)) {
        orig_from = from;  // a hit from the side
                           // (not from attacker_ob) can kill us. We need
                           // 'from' for the death event, if we really die.
        set_attack(from, 0, 1);
        from = 0;  // from==0 means that a living (stored in attacker_ob)
                   // is attacking us
      }
    }
    else if (from != this_object() &&
             (from = this_player() || previous_object())) {
      set_attack(from, 0, 1);
      from = 0;
    }
    if (!query_attack() && !from) {
      e[E_DAMAGE] = 0;
      return;
    }
    /* Don't damage wizards too much! */
    if (is_wizard(this_object(), IW_APPRENTICE) &&
        dam >= query_hp()) {
      tell_object(this_object(),
                  "Your wizardhood protects you from death.\n");
      e[E_DAMAGE] = 0;
      return;
    }
    if (query_ghost()) {
      e[E_DAMAGE] = 0;
      return;       /* Or someone who is dead */
    }
    dam -= random(query_ac() + 1);
    dam -= query_dex()/10;
    if (dam <= 0) {
      e[E_DAMAGE] = 0;
      return;
    }
    if (dam > query_hp() + 1)
      dam = query_hp() + 1;

    e[E_DAMAGE] = dam;
    e[E_SUCCESS] = 1;

    hp = query_hp() - dam;

    if (tmp = get_random_protecting_armor())
      tmp->decay(dam/4 + 1);

    tmp = orig_from || this_player();
    if (tmp) {
      if (!damage_map)
        damage_map = ([ tmp : dam ]);
      else {
        sizeof(damage_map);
        damage_map[tmp] += dam;
      }
    }
    set_hp(hp);  // this can't be lower than 0

    if (hp < 0) {  // but our temporary variable can
#if 0 // if E_AGENT is a living, from is 0 already here as a sign that
      // this living already known as attacker has attacked us.
      from      =      from || this_object();
      orig_from = orig_from || this_object();
#endif
      perform_death(from, orig_from);
    }
    if (orig_from &&
        orig_from == this_object() &&   // stop fights from this_object(),
        passive_attack)                 // when they are passive.
      stop_attack(orig_from);
    break;  // EPRIO_HANDLE
  }
}

/*
 * This function is called from other players when they want to make
 * damage to us. We return how much damage we received, which will
 * change the attackers score. This routine is probably called from
 * heart_beat() from another player.
 * Compare this function to reduce_hit_point(dam).
 */
varargs int hit_player(int dam, object from) {
  mapping attack_event;
  mapping hit_event;
  object liv;

  // known usages of hit_player()
  // 1) with from: a room (by player action): liv->hit_player(X, this_object());
  //    --> no fight
  // 2) w/o  from: a room (--"--, compat code style): liv->hit_player(X);
  //    --> no fight
  // 3) with from: an other living: other_liv->hit_player(X, this_object())
  //    --> fight
  // 4) with from: player's equip: other_liv->hit_player(X, player)
  //    --> fight
  // 5) w/o  from: player's equip: other_liv->hit_player(X)
  //    --> fight
  // 6) with from: player's equip: other_liv->hit_player(X, equip) [WRONG BEHAV]
  //    --> fight, from must be set to the player to correct it
  // 7) an item in the room hurts us, e.g. a grenade explodes
  //    with or without from: --> from = the item, no fight
  // 8) an item in our equip hurts ourselves, e.g. grenade explodes in the hand
  //    --> from = the item, no fight

  hit_event    = ([ E_TYPE  : "hit"; "hit",
                    E_TARGET: this_object(); 0,
                    E_WEAPON: (from || previous_object())->query_wield(); 0,
                    E_DAMAGE: dam; 0,
                 ]);

  attack_event = ([ E_TYPE  : "attack"; "attack",
                    E_TARGET: this_object(); 0,
                    E_WEAPON: (from || previous_object())->query_wield(); 0,
                    E_DAMAGE: dam; 0,
                 ]);

  from = from || previous_object();
  // from can be !living; but if there's really an attack from a player,
  // then also this_interactive() must be set, otherwise it can happen that
  // this_player() is still the NPC itself
  // TODO: Clean up hit_player() through the mud!
#if 0
  if (!living(from) && this_player() && this_interactive())
    from = this_player();
#else
  if (get_room(from) == from) {
    // this handles cases 1, 2
    ;
  }
  else if ((liv = find_living_environment(from))) {
    // this handles cases 3, 4, 5, 6, 8 and even corrects case 6
    if (liv != this_object())  // != because of case 8, don't attack ourselves
      from = liv;
  }
  // case 7 doesn't need a special handling here
#endif

  attack_event[E_AGENT] = from;
  hit_event[E_AGENT] = from;

#if 0  // for testing purpose
  if (is_wizard(this_object(), IW_TOOLUSER) ||
      is_wizard(from,          IW_TOOLUSER)) {
      // TODO: only hit here. no automated fight because of attack
    send_event("hit", hit_event, get_room(this_object()));
    if (hit_event[E_CANCELLED])
      return 0;
    return hit_event[E_DAMAGE];
  }
#endif
  send_event("attack", attack_event, get_room(this_object()));
  if (attack_event[E_CANCELLED])
    return 0;
  return attack_event[E_DAMAGE];
}

static void die(object from, object death_mark, object killer) {
  mixed tmp;
  int i, damage_sum;
  object corpse;
  int loss;

  if (hunter)
    hunter->stop_hunter();
  hunter = 0;
  hunted = 0;
  if (stringp(death_message) ||
      closurep(death_message))
    efun::say(funcall(death_message));
  else
    send_message(({ M_ME_THE, " died." }));

// update_achievements() adds the temporary experience
// to the total experience, of course we want a dying player to lose as
// much experience as possible, don't we?
  if (interactive(this_object()))
    this_object()->update_achievements();

  loss = query_exp() / 60;
  if (!query_npc() && previous_object_for_die)
      "global/wizlist"->add_exp(-loss, previous_object_for_die);
  set_hp(10);
  /* The player killing us will update his alignment! */
  /* If he exists */
  if (killer && !from) {
    // changed attacker_ob to killer, which is more precise
    killer->add_alignment(ADJ_ALIGNMENT(query_alignment()));
    if (!damage_map || !sizeof(damage_map)) {
      killer->add_exp(loss);
      SE_MONSTERS->monster_killed(this_object(), killer, loss, 100);
    }
    else {
      tmp = m_values(damage_map);
      for (i=sizeof(tmp); i--;)
        damage_sum += tmp[i];
      tmp = m_indices(damage_map) - ({ 0 });
      for (i=sizeof(tmp); i--;) {
        tmp[i]->add_exp((loss * damage_map[tmp[i]]) / damage_sum);
        if ((100 * damage_map[tmp[i]]) / damage_sum >= 25)
          SE_MONSTERS->monster_killed(this_object(), tmp[i], loss,
                                      (100*damage_map[tmp[i]]) / damage_sum);
      }
    }
    damage_map = 0;
  }
  if (corpse_for_die) {
    corpse_for_die->set_name(describe(this_object()));
    corpse_for_die->set_gender(query_gender());
    if (query_npc())
      corpse_for_die->set_weight(corpse_weight);
    transfer_all_to(corpse_for_die);
    move_object(corpse_for_die, environment());
  }
  if (!this_object()->second_life(corpse_for_die, from || killer || attacker_ob,
                                  death_mark))
    destruct(this_object());
  else
    move_object(clone_object(GHOST_MARK), this_object());
  if (!query_npc())
      this_object()->save_me(1);
  stop_show_long_delayed();
}

void receive_death_event(mapping e, string type, int prio) {
  if (e[E_TARGET] == this_object() && prio == 0) {
#if 0 // up to now it is only possible to notify this event (no changes)
    set_attack(e[E_AGENT], 0, 0);
#endif
    // wizards cannot die
    if (!query_npc() && is_wizard(this_object(), IW_APPRENTICE)) {
      cancel_event();
      return;
    }
    previous_object_for_die = e[E_OBJECT];
    corpse_for_die = e[E_TO];
    die(e[E_FROM], e[E_DEATH_MARK], e[E_AGENT]);
  }
}

static void reset_damage_map() {
  damage_map = 0;
}

void heart_beat() {
  if (query_hp() == query_max_hp())
    reset_damage_map();
  if (alt_attacker_ob && !sizeof(alt_attacker_ob))
    alt_attacker_ob = 0;
  if (query_attack())
    attack();
  if (query_attack() &&
      (whimpy == 2 && query_hp() < funcall(wh_thresh) ||
       whimpy == 1 && query_hp() < (query_max_hp() * funcall(wh_thresh)) / 100))
    run_away();
}

/////////////////////////////
// the next functions are taken from obj/player
//

static void missile_object(object ob) {
  if (query_sp() < 10) {
    write("You are too low on power.\n");
    return;
  }
  spell_name = "magic missile";
  spell_dam = random(20);
  spell_cost = 10;
  if (!set_attack(ob, 1, 0))
    spell_cost = 0;
}

static void shock_object(object ob) {
  if (query_sp() < 15) {
    write("You are too low on power.\n");
    return;
  }
  spell_name = "shock";
  spell_dam = random(30);
  spell_cost = 15;
  if (!set_attack(ob, 1, 0))
    spell_cost = 0;
}

static void fire_ball_object(object ob) {
  if (query_sp() < 20) {
    write("You are too low on power.\n");
    return;
  }
  spell_name = "fire ball";
  spell_dam = random(40);
  spell_cost = 20;
  if (!set_attack(ob, 1, 0))
    spell_cost = 0;
}

status spell_missile(string str) {
  object ob;
  if (!test_sight(environment()))
    return 1;
  if (query_level() < 5)
    return 0;
  if (!str)
    ob = attacker_ob;
  else
    ob = present(lower_case(str), environment(this_player()));
  if (!ob || !living(ob)) {
    write("At whom?\n");
    return 1;
  }
  if (ob == this_object())
    return 0;
  missile_object(ob);
  return 1;
}

status spell_shock(string str) {
  object ob;
  if (!test_sight(environment()))
    return 1;
  if (query_level() < 10)
    return 0;
  if (!str)
    ob = attacker_ob;
  else
    ob = present(lower_case(str), environment(this_player()));
  if (!ob || !living(ob)) {
    write("At whom?\n");
    return 1;
  }
  if (ob == this_object())
    return 0;
  shock_object(ob);
  return 1;
}

status spell_fire_ball(string str) {
  object ob;
  if (!test_sight(environment()))
    return 1;
  if (query_level() < 15)
    return 0;
  if (!str)
    ob = attacker_ob;
  else
    ob = present(lower_case(str), environment(this_player()));
  if (!ob || !living(ob)) {
    write("At whom?\n");
    return 1;
  }
  if (ob == this_object())
    return 0;
  fire_ball_object(ob);
  return 1;
}
