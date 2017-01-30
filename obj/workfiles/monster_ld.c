/*
 * A general purpose monster. Clone this object,
 * and call local functions to configure it.
 */

#pragma strong_types

#include <wizlevels.h>
#include <server.h>
#include <filter.h>
#include <living_ld.h>
#include <message.h>
#include <prop/item.h>

inherit "basic/living/chatter";
inherit "obj/living_ld";

private string alias, alt_name, race;
private int     move_at_reset;
private string  *talk_func;      // Vector of functions.
private string  *talk_match;     // Vector of strings.
private string  *talk_type;      // Vector of types.
private int     spell_chance, max_spell_dam;
private mixed   spell_mess1, spell_mess2;
private string  give_func;
private string  refuse_func;
private int     frog_all;
private int     random_pick;

private int nat_ac, nat_wc;  // natural armor and weapon class which should be
                             // taken into account when wearing or wielding
                             // armors and weapons

private static object kill_ob;
private static mixed  talk_ob;
private static mixed  dead_ob;
private static mixed  init_ob;
private static mixed  give_func_ob;
private static string create_room;
private static string the_text;
private static int    have_text;
private static int    busy_catch_tell;
private static int    aggressive;



status query_npc() {
  return 1;
}

string query_race() {
  return race;
}

void random_move() {
  run_away(1);
}

mixed query_create_room() {
  return create_room && (find_object(create_room) || create_room);
}

void create() {
  int i;

  i = 0;
  while (previous_object(i) &&
         previous_object(i) == find_object("kernel/simul_efun"))
    i++;
  create_room = previous_object(i) && object_name(previous_object(i));
  "obj/living_ld"::create();
#if 0
  call_out(#'set_default_resistance, 0);
#endif
  if (!query_once_interactive(this_object()))
    call_out(#'call_other, 0, SE_MONSTERS, "set_monster_database_id",
             this_object());
}

void configure() {
  "obj/living_ld"::configure();
  set_level(1);
  set_corpse_weight(5);
}

void refresh() {
  "obj/living_ld"::refresh();
  chatter::refresh();
  if (move_at_reset)
    random_move();
}

status id(string str) {
  return str && member(query_id() || ({ }), lower_case(str)) > -1;
}

status query_always_frog() {
  return frog_all;
}

varargs void frog_curse(status arg, int duration) {
  if (arg || frog_all != 1)
    return living_ld::frog_curse(arg, duration);
}

void set_frog(int i) {
  if (i == 444)
    frog_all = 1;
  else
    frog_all = 0;
  frog_curse(i);
}

void set_random_pick(int r) {
  random_pick = r;
}

void pick_any_obj() {
  object ob;
  int weight;

  ob = first_inventory(environment());
  while (ob) {
    if (ob->get(1) && ob->short() && !ob->query_property(P_NOT_PORTABLE)) {
      message_command(({ "take ", ob }));
      command(message2string(({"wear ",M_NONE,ob})));
      command(message2string(({"wield ",M_NONE,ob})));
      return;
    }
    ob = next_inventory(ob);
  }
}

status test_if_any_here() {
  object ob;

  if (ob = environment())
    for (ob = first_inventory(ob); ob; ob = next_inventory(ob))
      if (ob != this_object() && living(ob) && !ob->query_npc())
        return 1;
  return 0;
}

mixed test_match(string str) {
  string who, str1, type, match, func;
  int i;

  while(i<sizeof(talk_match)) {
    if (talk_type[i])
      type = talk_type[i];
    match = talk_match[i];
    if (match == 0)
      match = "";
    if (talk_func[i])
      func = talk_func[i];
    if (sscanf(str, "%s " + type + match + "%s\n", who, str1) == 2 ||
        sscanf(str,"%s " + type + " " + match + "%s\n", who, str1) == 2)
      return call_other(talk_ob, func, str);
    i++;
  }
  return 0;
}

private status monster_hurt() {
  return query_hp() < query_max_hp() ||
         query_sp() < query_max_sp();
}

status query_buty() {
  return "obj/living_ld"::query_busy() ||
         chatter::query_busy();
}

void heart_beat() {
  int c;
  mixed h;

  chatter::heart_beat();
  "obj/living_ld"::heart_beat();

  busy_catch_tell = 0;

  if (!test_if_any_here()) {
   if (have_text && talk_ob) {
     have_text = 0;
     test_match(the_text);
   } else {
      if (!query_busy())
        if (!monster_hurt() &&
            !query_soaked() &&
            !query_stuffed() &&
            !query_intoxication()) {
          set_heart_beat(0);
        }
      return;
    }
  }
  if (kill_ob && present(kill_ob, environment())) {
    if(random(2) == 1)
      return;              // Delay attack some
    attack_object(kill_ob);
    kill_ob = 0;
    return;
  }
  if (query_attack() && present(query_attack(), environment()) &&
      spell_chance > random(100)) {
    say(funcall(spell_mess1) + "\n", query_attack());
    tell_object(query_attack(), funcall(spell_mess2) + "\n");
    query_attack()->hit_player(random(max_spell_dam), this_object());
  }
  if (random_pick) {
    if (random(100) < random_pick)
      pick_any_obj();
  }
  if (have_text && talk_ob) {
    have_text = 0;
    test_match(the_text);
  }
}

void catch_tell(string text) {
  if (busy_catch_tell)
    return;
  busy_catch_tell = 1;
  if (talk_ob) {
    if (have_text) {
      test_match(the_text);
      the_text = text;
    } else {
      the_text = text;
      have_text = 1;
    }
  }
  busy_catch_tell = 0;
}

/* Call the following functions to setup the monster
 * Call them in the order they appear
 */

#if 0
void set_name(string n) {
#if 0  // this is no longer necessary
  if (n != capitalize(n) &&     // isn't capitalized yet?
      SE_NAMES->is_natural_name(n)) // and natural name?
    log_file("NAMES",
             sprintf("%s: name: %-20s ob: %s\n",
                     ctime(),n,to_string(this_object())));
#endif
  living_ld::set_name(n);
}
#endif

void set_level(int l) {
  // a NEW_LEVEL monster will have the same default stats as a player, i.e.
  // a level 1 monster will have higher stats than before NEW_LEVELS
  int s;

  s = (20 + 3 * 1);
  if (s > 140)
    s = 140;
  s = s / 4;
  set_str(s);
  set_int(s);
  set_dex(s);
  set_sta(s);
  set_mag(s);
  set_cha(s);
  set_pie(s);
  set_ste(s);
  set_luc(s);
  set_wil(s);
  "obj/living_ld"::set_level(l);

  if (l < 14)
    nat_wc = l / 2 + 3;
  else if (l < 20)
    nat_wc = (l - 9) * 2;
  else
    nat_wc = 25;
  nat_ac = l / 2;
  set_hp(42 + query_sta() * 8);
  set_sp(42 + query_mag() * 8);
  set_wimpy_level(query_max_hp() / 5);
  set_default_exp(l);
}

void set_race(string r) {
  if (race)
    remove_id(lower_case(race));
  race = r;
  if (r)
    add_id(lower_case(r));
  LIB_RACE->set_race_defaults(this_object(), r);
}

void set_wc(int wc) {
  if (wc > -1)
    nat_wc = wc;
}

void set_ac(int ac) {
  if (ac > -1)
    nat_ac = ac;
}

void set_aggressive(status a) {
  aggressive = a;
}

status query_aggressive() {
  return aggressive;
}

int query_nat_ac() {
  return nat_ac;
}

int query_nat_wc() {
  return nat_wc;
}

// The following function will yeild the armor class of possibly worn
// armors _plus_ the class of possibly present natrual armors like fur, etc.
int query_ac() {
  return "obj/living_ld"::query_ac() + nat_ac;
}

// The following function will yield the weapon class of a possibly wielded
// weapon _or_ the class of a possibly natural weapon like claws, etc.
int query_wc() {
  return "obj/living_ld"::query_wc() || nat_wc;
}

void set_move_at_reset(varargs mixed *m) {
  if (!sizeof(m))
    move_at_reset = 1;
  else
    move_at_reset = !!m[0];
}

void set_chance(int c) {
  spell_chance = c;
}

void set_spell_mess1(mixed m) {  // message to victim
  spell_mess1 = m;
}

void set_spell_mess2(mixed m) {  // message to the room
  spell_mess2 = m;
}

void set_spell_dam(int d) {
  max_spell_dam = d;
}

int init_command(string cmd) {
  return command(cmd);
}

/* Catch the talk */
void set_match(mixed ob, string *func, string *type, string *match) {
  if(sizeof(func) != sizeof(type) || sizeof(match) != sizeof(type))
    return;
  talk_ob    = ob;
  talk_func  = func;
  talk_type  = type;
  talk_match = match;
}

void set_dead_ob(object ob) {
  dead_ob = ob;
}

void set_give_ob(mixed ob, string func, string ref_func) {
  if (!func)
    func = "receive_object";
  if (!ref_func)
    ref_func = "refuse_object";
  give_func_ob = ob;
  give_func    = func;
  refuse_func  = ref_func;
}

status second_life(object corpse, object killer, object deathmark) {
  return dead_ob && dead_ob->monster_died(this_object(), corpse, killer);
}

void set_init_ob(mixed ob) {
  init_ob = ob;
}

void notify_player_arrives(object pl) {
  set_heart_beat(1);
  if (aggressive && (pl->short() &&  // visible?
                     pl->query_level() < WL_APPRENTICE))
    kill_ob = pl;
}

void init() {
  if (this_player() == this_object())
    return;
  living_ld::init();
  if (init_ob && init_ob->monster_init(this_object()))
    return;
  if (query_attack())
    set_heart_beat(1);
  if (query_busy())
    set_heart_beat(1);
  if (this_player() && !this_player()->query_npc()) {
    notify_player_arrives(this_player());
  }
}

void show_stats() {
  int i;
  string out;
  mixed h;

  out  = "--------------------------------------------------------------------"
         "-----\n";
  out += query_short() + "    (" +
         object_name(this_object()) + ")\n";
  out += "--------------------------------------------------------------------"
         "-----\n";
  out += "Name         : " + query_name() + "\n";
  out += "Level        : " + query_level() + "\n";
  out += "Alignment    : " + query_alignment() + "\n";
  out += "Experience   : " + query_exp() + "\n";
  out += "Stats        : " + "str: " + query_str() +" ("+query_real_str()+")"+
                         "    int: " + query_int() +" ("+query_real_int()+")"+
                         "    dex: " + query_dex() +" ("+query_real_dex()+")"+
                         "    sta: " + query_sta() +" ("+query_real_sta()+")"+
                         "    mag: " + query_mag() +" ("+query_real_mag()+")"+
                         "    cha: " + query_cha() +" ("+query_real_cha()+")"+
                         "    pie: " + query_pie() +" ("+query_real_pie()+")"+
                         "    wil: " + query_wil() +" ("+query_real_wil()+")"+
                         "    ste: " + query_ste() +" ("+query_real_ste()+")"+
                         "    luc: " + query_luc() +" ("+query_real_luc()+")\n";
  out += "Gender       : " + query_gender_string() + "\n";
  out += "Money        : " + (LIB_MONEY->describe_money(query_coins()) || "") +
         " (" + query_money() + ")\n";
  out += "Hit   points : "+query_hp()+" (out of max. "+query_max_hp()+")\n";
  out += "Spell points : "+query_sp()+" (out of max. "+query_max_sp()+")\n";
  out += "Weapon class : "+query_wc()+" (wielded weapon: ";
  if (h = query_wield())
    out += h->query_name();
  else
    out += "none";
  out += ")\n";
  out += "Armor class  : "+query_ac()+" (worn armor: ";
  h = query_armor();
  if (!h || !sizeof(h))
    out += "none)\n";
  else
    out += implode(map(h, #'describe, this_object()), ",")+")\n";
  out += "Carry        : " + query_carry()+" (max: "+query_max_carry() +")\n";
  if (query_attack())
    out += "Attack       : " + query_attack()->query_name() + "\n";
  if (sizeof(query_alt_attack()))
    out += "Alt attack   : " +
           make_list(describe_list(query_alt_attack())) + "\n";
  out += "Age          : " + show_age() + "\n";
  write(out);
}

void receive_object(object ob, object pl) {
  if (give_func_ob) { 
    if (give_func != "receive_object" ||
        (objectp (give_func_ob) ? give_func_ob : find_object (give_func_ob))
        != this_object ())
      call_other(give_func_ob, give_func, ob, pl);
  }
}

status refuse_object(object ob) {
  if (give_func_ob) {
    if (refuse_func != "refuse_object" || 
        (objectp (give_func_ob) ? give_func_ob : find_object (give_func_ob))
        != this_object ())
      return call_other(give_func_ob, refuse_func, ob);
  }
  return 0;
}

///////////////////////////////////////////////////////
//
// compatibility section
//
///////////////////////////////////////////////////////

void set_alias(string a) {
  if (alias)
    remove_id(lower_case(alias));
  alias = a;
  if (a)
    add_id(lower_case(a));
}

