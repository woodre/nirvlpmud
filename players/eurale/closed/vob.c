/* guild login announcements located at 285  */

#include "/players/eurale/defs.h"
int SHOWFANGS,telepathy_on;
static int in_a_form,levitating;
int BLOODPTS,STORAGE;
static int SHADOW;
object littlebat_obj,wolf_obj;
object new_form_obj,form_obj;
object player;
object targ;
string bat_owner_name,target_name;
string form_description,new_form_description,form_owner_name;

set_STORAGE(num) {
  STORAGE = num;
  silent_save(); }
query_STORAGE() { return STORAGE; }

set_BLOODPTS(bpts) {
  BLOODPTS = bpts;
  if(BLOODPTS < 0) { BLOODPTS = 0; }
  silent_save(); }

add_BLOODPTS(abpts) {
  set_BLOODPTS(BLOODPTS + abpts);
  return 1; }
query_BLOODPTS() { return BLOODPTS; }

silent_save() {
  save_object(VMEMBER+environment(TO)->query_real_name());
  return 1;
}

set_SHOWFANGS(num) { SHOWFANGS = num; }
query_SHOWFANGS() { return SHOWFANGS; }

set_target_name(arg) { target_name = arg; }
query_target_name() { return target_name; }

set_telepathy(arg) { telepathy_on = arg; }
query_telepathy() { return telepathy_on; }

set_littlebat_obj(arg) { littlebat_obj = arg; }
query_littlebat_obj() { return littlebat_obj; }

set_bat_owner_name(arg) { bat_owner_name = arg; }
query_bat_owner_name() { return bat_owner_name; }

set_wolf_obj(arg) { wolf_obj = arg; }
query_wolf_obj() { return wolf_obj; }

wolf_location() {
  if(wolf_obj && environment(wolf_obj)) {
   if(environment(wolf_obj)->short())
      return environment(wolf_obj)->short(); }
  return "none"; }

set_form_description(arg) { form_description = arg; }
query_form_description() { return form_description; }

set_new_form_description(arg) { new_form_description = arg; }
query_new_form_description() { return new_form_description; }

set_form_owner_name(arg) { form_owner_name = arg; }
query_form_owner_name() { return form_owner_name; }

set_new_form_obj(arg) { new_form_obj = arg; }
query_new_form_obj() { return new_form_obj; }

set_form_obj(arg) { form_obj = arg; }
query_form_obj() { return form_obj; }

set_in_a_form(arg) { in_a_form = arg; }
remove_form() { in_a_form = 0; }
query_in_a_form() { return in_a_form; }

set_levitating(arg) { levitating = arg; }
stop_levitating() { levitating = 0; }
query_levitating() { return levitating; }


reset(arg) {
  if (arg) return 0;
BLOODPTS = 0;
SHADOW = 0;
SHOWFANGS = 1;
telepathy_on = 1;
  in_a_form = levitating = 0;

call_out("light_damage",3);
set_heart_beat(1);
}

id(str) { return (
  str == "efangs" ||
  str == "fangs" ||
  str == "vampire fangs");
}

short() {
  if(SHOWFANGS) return HIR+"bloody, dripping fangs"+NORM;
  else return;
}

long() { write(
  "A pair of long, pointed, blood_stained fangs that protrude down\n"+
  "from out of your upper gums.\n");
}

init() {
int vampire;
object shadow;
if(environment(TO)) {
  if(TP) {
    if(TP->is_player()) {
      if(TP == environment(TO)) {
        call_other(MEMBER, "???", 0);
        vampire = call_other(MEMBER, "query_member", TPRN);
        if(!vampire) { destruct(TO); return 1; }
        restore_object(VMEMBER+TP->query_real_name());

  /*  Vampire Commands/Spells  */
add_action("alarm_bat","abat");
add_action("awaken","awaken");
add_action("assess_mob","assess");
add_action("attack_backhand","bac");
add_action("attack_backhand","backhand");
add_action("create_form","bat");
add_action("batsell_item","batsell");
add_action("benergy","benergy");
add_action("bite_player","bite");
add_action("call_wolf","call");
add_action("calm_fighters","calm");
add_action("cancel_summons","cancel");
add_action("check_player","check");
add_action("cure_disease","cure");
add_action("attack_damn","dam");
add_action("attack_damn","damn");
add_action("attack_demon","dem");
add_action("attack_demon","demon");
add_action("vamp_demote","ddemote");
add_action("dismiss_bat","dismiss");
add_action("drain_corpse","drain");
add_action("show_player","examine", 3);
add_action("expell_player","expell");
add_action("cause_fear","fear");
add_action("no_game_spls","fireball", 2);
add_action("fix_heart","fix");
add_action("show_vamps","friends", 3);
add_action("show_vamps2","fril");
add_action("attack_grasp","gra");
add_action("attack_grasp","grasp");
add_action("go_guild","haunt");
add_action("infuse_sp","infuse");
add_action("show_inven","inventory", 1);
add_action("leave_guild","leave");
add_action("levitate","levitate", 3);
add_action("message_bat","mbat");
add_action("create_form","mist");
add_action("no_game_spls","missile", 2);
add_action("obit_list","obits");
add_action("vamp_promote","ppromote");
add_action("vamp_quit","quit");
add_action("remove_fangs","rremove");
add_action("replace_fangs","rreplace");
add_action("vamp_save","save");
add_action("scan_wolf","scan");
add_action("show_score","score", 2);
add_action("attack_scratch","scr");
add_action("attack_scratch","scratch");
add_action("sharpen_fangs","sharpen");
add_action("shift_hp","shift", 3);
add_action("no_game_spls","shock", 2);
add_action("show_item","show");
add_action("no_game_spls","sonic", 2);
add_action("summon","summon");
add_action("telepathy","te");
add_action("telepathyfeel","tf");
add_action("telepathyfeel","tt");
add_action("transfer_item","transfer");
add_action("guild_help","vhelp");
add_action("show_whopk","who2");
add_action("show_whov","whov");
add_action("create_form","wolf");

  /* Vampire Emotes  */
add_action("vbird","bird");
add_action("vbow","bow");
add_action("vcackle","cackle");
add_action("vchortle","chortle");
add_action("vcurtsey","curtsey");
add_action("vemote","emote");
add_action("vfaint","faint");
add_action("vglare","glare");
add_action("vgrin","grin");
add_action("vhiss","hiss");
add_action("vkhand","khand");
add_action("vkiss","kiss");
add_action("vneck","kneck");
add_action("knipple","knipple");
add_action("vlaugh","laugh");
add_action("vsmile","smile");
add_action("vyawn","yawn");

if(SHADOW == 0) {
if(!TP->Etest()) {
  shadow = clone_object("/players/eurale/VAMPIRES/vshadow.c");
  shadow->start_vampstuff(TP);
  if(TP->query_real_name() == "eurale")
  tell_object(TP,TP->Etest()+"\n");
  SHADOW = 1; }
  }

      }
    }
  }
}
}

  /*  Vampire Lib Commands/Spells  */
alarm_bat(str) { return BASE->alarm_bat(str); }
assess_mob(str) { return BASE->assess_mob(str); }
awaken(str) { return BASE->awaken(str); }
static attack_backhand(str) { return BASE->attack_backhand(str); }
static attack_damn(str) { return BASE->attack_damn(str); }
static attack_demon(str) { return BASE->attack_demon(str); }
static attack_grasp(str) { return BASE->attack_grasp(str); }
static attack_scratch(str) { return BASE->attack_scratch(str); }
batsell_item(str) { return BASE->batsell_item(str); }
benergy(str) { return BASE->benergy(str); }
bite_player(str) { return BASE->bite_player(str); }
call_wolf(str) { return BASE->call_wolf(str); }
calm_fighters(str) { return BASE->calm_fighters(str); }
cancel_summons(str) { return BASE->cancel_summons(str); }
cause_fear(str) { return BASE->cause_fear(str); }
check_player(str) { return BASE->check_player(str); }
create_form(str) { return BASE->create_form(str); }
cure_disease(str) { return BASE->cure_disease(str); }
dismiss_bat(str) { return BASE->dismiss_bat(str); }
drain_corpse(str) { return BASE->drain_corpse(str); }
expell_player(str) { return BASE->expell_player(str); }
fix_heart(str) { return BASE->fix_heart(str); }
go_guild(str) { return BASE->go_guild(str); }
guild_help(str) { return BASE->guild_help(str); }
infuse_sp(str) { return BASE->infuse_sp(str); }
leave_guild(str) { return BASE->leave_guild(str); }
levitate(str) { return BASE->levitate(str); }
message_bat(str) { return BASE->message_bat(str); }
no_game_spls(str) { return BASE->no_game_spls(str); }
obit_list(str) { return BASE->obit_list(str); }
remove_fangs(str) { return BASE->remove_fangs(str); }
replace_fangs(str) { return BASE->replace_fangs(str); }
scan_wolf(str) { return BASE->scan_wolf(str); }
sharpen_fangs(str) { return BASE->sharpen_fangs(str); }
shift_hp(str) { return BASE->shift_hp(str); }
show_item(str) { return BASE->show_item(str); }
show_inven(str) { return BASE->show_inven(str); }
show_player(str) { return BASE->show_player(str); }
show_score(str) { return BASE->show_score(str); }
show_vamps(str) { return BASE->show_vamps(str); }
show_vamps2(str) { return BASE->show_vamps2(str); }
show_whopk(str) { return BASE->show_whopk(str); }
show_whov(str) { return BASE->show_whov(str); }
summon(str) { return BASE->summon(str); }
telepathy(str) { return BASE->telepathy(str); }
telepathyfeel(str) { return BASE->telepathyfeel(str); }
transfer_item(str) { return BASE->transfer_item(str); }
vamp_demote(str) { return BASE->vamp_demote(str); }
vamp_promote(str) { return BASE->vamp_promote(str); }
vamp_quit(str) { return BASE->vamp_quit(str); }
vamp_save(str) { return BASE->vamp_save(str); }

  /*  BASE emotes  */
vbird(str) { return BASE->vbird(str); }
vbow(str) { return BASE->vbow(str); }
vcackle(str) { return BASE->vcackle(str); }
vchortle(str) { return BASE->vchortle(str); }
vcurtsey(str) { return BASE->vcurtsey(str); }
vemote(str) { return BASE->vemote(str); }
vfaint(str) { return BASE->vfaint(str); }
vglare(str) { return BASE->vglare(str); }
vgrin(str) { return BASE->vgrin(str); }
vhiss(str) { return BASE->vhiss(str); }
vkhand(str) { return BASE->vkhand(str); }
vkiss(str) { return BASE->vkiss(str); }
vlaugh(str) { return BASE->vlaugh(str); }
vneck(str) { return BASE->vneck(str); }
knipple(str) { return BASE->knipple(str); }
vsmile(str) { return BASE->vsmile(str); }
vyawn(str) { return BASE->vyawn(str); }

     /*  tell my room but NOT me  */
tell_my_room(msg, ignore) {
  string players_here;

  players_here = first_inventory(ROOM);
  while (players_here) {
    if (living(players_here) &&
        !players_here->query_npc() &&
        players_here != TP &&
        players_here->query_real_name() != ignore) {
      tell_object(players_here, msg+"\n");
    }
    players_here=next_inventory(players_here);
  }
  return 1;
}

/*
init_arg() {
  write(BOLD+
    "    ~o~\n"+
    "~o~\n"+
    "   Check 'updates' to see what's new.\n"+
    "~o~\n"+
    "    ~o~\n"+
    NORM+"\n");
  return 0;
}
*/

get() { return 1; }
drop() { return 1; }
query_auto_load() { return "/players/eurale/VAMPIRES/vampob.c:"; }

  /*  sort by level  */
sort_list_of_players(str) {
  int i, j, sorted;
  object tmp;
  j = sizeof(str);
  sorted = 0;
  while(!sorted) {
    sorted = 1; j--;
      for (i=0; i < j; i++)
        if (str[i]->query_level() < str[i+1]->query_level()) {
          tmp=str[i];
          str[i]=str[i+1];
          str[i+1]=tmp;
          sorted = 0;
        }
   }
   return str;
}

  /*  Do light damage to player  */
light_damage() {
int hurt;

if(!environment()) return 1;
if(!environment(environment())) return 1;
hurt = set_light(0);
if(environment(TO)->query_level() < 20 &&
  !environment(TO)->query_ghost()) {

  if(hurt > 1)
  tell_object(environment(TO),
    "You feel the light sear your skin and flesh...\n");
if(hurt < -1 &&
  environment(TO)->query_mhp() != environment(TO)->query_hp())
    tell_object(environment(TO),
      "The soothing darkness rejuvenates your soul...\n");
  if((environment(TO)->query_hp() - hurt) > 0) {
    if(hurt > 5) hurt = 5;
    if(hurt < -5) hurt = -5;
    if(!environment(TO)->query_interactive()) hurt = 0;
    environment(TO)->add_hit_point(-hurt);
    environment(TO)->add_spell_point(-hurt);
  }
call_out("light_damage",3);
return 1; }
}

light_up(int a) {
  set_light(a);
  return 1; }

heart_beat() {
object weapon;
int noblood;
int oldwc, newwc, num, vdiv;
int speed, damage, target, adjwc;

   if(!environment()) return;
   if(!living(environment())) return;

     /* Take away blood energy at death  */
  if(environment(TO)->query_ghost()) set_BLOODPTS(0);

    /*  vampire strength = +adjwc to vampire wc  */
  oldwc = environment()->query_wc();
  weapon = environment()->query_weapon();

    /* Adjust wc according to guild level  */
  if(environment()->query_guild_exp() == 666) adjwc = 0;
  else if(environment()->query_guild_exp() == 667 ||
          environment()->query_guild_exp() == 668) adjwc = 1;
  else if(environment()->query_guild_exp() >= 668) adjwc = 2;

  if(!weapon && oldwc == 3) {
    newwc = oldwc + adjwc;
    environment()->set_wc(newwc); }
  if(weapon) {
    oldwc = environment()->query_wc();
    if(weapon->weapon_class() == oldwc) {
      newwc = oldwc + adjwc;
      environment()->set_wc(newwc); }
  }

    /*  vampire speed dependant on Luck, Stealth and Stamina  */
num = random(100);
speed = (environment()->query_attrib("sta") +
    environment()->query_attrib("luc") +
    (environment()->query_attrib("ste"))/2);
if(targ = environment()->query_attack()) {
  if(environment(targ) == environment(environment())) {
  damage = (5 + random(environment()->query_level()));
  target = environment()->query_attack()->query_hp();
    /*  factor in guild level as well as attrib stats  */
  if(environment()->query_guild_exp() == 666) vdiv =  5;
  else if(environment()->query_guild_exp() == 667) vdiv = 4;
  else if(environment()->query_guild_exp() == 668) vdiv = 3;
  else if(environment()->query_guild_exp() == 669) vdiv = 2;
  else if(environment()->query_guild_exp() >= 670) vdiv = 1;
if((damage + 10)/vdiv > target) return;
  if(num < speed) {
    tell_object(environment(),
      BOLD+"You strike "+
      capitalize(environment()->query_attack()->query_name())+
      " again with lightning quickness.\n"+NORM);
    (environment()->query_attack())->hit_player(damage/vdiv);
    return; }
}
}

}
