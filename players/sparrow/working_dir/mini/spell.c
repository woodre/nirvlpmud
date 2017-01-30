/*
 *  The spell object for version 2.0 of the Mini Guilds.
 *
 */
#define TP this_player()
#define tp this_player()->query_name()
#define TPQ this_player()->query_real_name()
#define TARG capitalize(target)
#define TARGET find_player(target)
#define ALI (int) TP->query_alignment()
#define LEVEL TP->query_level()
#define ENV environment(TP)
#define SPELL TP->query_sp()
#define NOT_GOOD "Your soul is not balanced towards the light.\n"
#define NOT_LEVEL "You have not the power to use that ability yet.\n"
#define NOT_SP "You do not have the mana to use this ability.\n"
#define CAP capitalize(str)
#define NO_PK "NO PLAYER KILLING\n"
#define GENDER this_player()->query_possessive()
#define INV environment(this_object())
#define REALM call_other(environment(this_player()), "realm", 0)
#define POSS this_player()->query_possessive()
#define OBJE this_player()->query_objective()
#define OOBJ ob->query_objective()
#define POS2 ob->query_possessive()
#define PRO2 ob->query_pronoun()
#define THAT if(!ob) { write(capitalize(str)+" is not here.\n"); return 1; }
#define OJN ob->query_name()

inherit "/players/saber/closed/new_mini/spells/save_me.c";
inherit "/players/saber/closed/new_mini/spells/restore_me.c";
inherit "/players/saber/closed/new_mini/spells/emotee.c";
inherit "/players/saber/closed/new_mini/spells/mini_guild_who.c";
inherit "/players/saber/closed/new_mini/spells/Quote.c";
inherit "/players/saber/closed/new_mini/spells/dream.c";
inherit "/players/saber/closed/new_mini/spells/bless_corpse.c";
inherit "/players/saber/closed/new_mini/spells/cure_target.c";
inherit "/players/saber/closed/new_mini/spells/find_wizard.c";
inherit "/players/saber/closed/new_mini/spells/luck.c";
inherit "/players/saber/closed/new_mini/spells/new_title.c";
inherit "/players/saber/closed/new_mini/spells/prayer_person.c";
inherit "/players/saber/closed/new_mini/spells/stealth.c";
inherit "/players/saber/closed/new_mini/spells/summon_knife.c";
inherit "/players/saber/closed/new_mini/spells/taunt.c";
inherit "/players/saber/closed/new_mini/spells/value_weapon.c";
inherit "/players/saber/closed/new_mini/spells/xcharm.c";
inherit "/players/saber/closed/new_mini/spells/nice_person.c";
inherit "/players/saber/closed/new_mini/spells/plant_item.c";
inherit "/players/saber/closed/new_mini/spells/tie_shoes.c";
inherit "/players/saber/closed/new_mini/spells/untie_shoes.c";
inherit "/players/saber/closed/new_mini/spells/mini_guild_scroll.c";
inherit "/players/saber/closed/new_mini/spells/fix_blade.c";
inherit "/players/saber/closed/new_mini/spells/draw_knife.c";
inherit "/players/saber/closed/new_mini/spells/bad_vibes.c";
inherit "/players/saber/closed/new_mini/spells/dance.c";
inherit "/players/saber/closed/new_mini/spells/succor.c";
inherit "/players/saber/closed/new_mini/spells/juggle_blades.c";
inherit "/players/saber/closed/new_mini/spells/recite_poetry.c";
inherit "/players/saber/closed/new_mini/spells/paint_face.c";
inherit "/players/saber/closed/new_mini/spells/curse.c";
inherit "/players/saber/closed/new_mini/spells/tell_fortune.c";
inherit "/players/saber/closed/new_mini/spells/value_item.c";
inherit "/players/saber/closed/new_mini/spells/master_line_talk.c";
inherit "/players/saber/closed/new_mini/spells/master_emote.c";
inherit "/players/saber/closed/new_mini/spells/master_toggle.c";
inherit "/players/saber/closed/new_mini/spells/meow_update.c";
inherit "/players/saber/closed/new_mini/spells/succubus_update.c";
inherit "/players/saber/closed/new_mini/spells/blade_update.c";
inherit "/players/saber/closed/new_mini/spells/gypsy_update.c";
inherit "/players/saber/closed/new_mini/spells/larn_update.c";
inherit "/players/saber/closed/new_mini/spells/gothic_update.c";
inherit "/players/saber/closed/new_mini/spells/kender_update.c";
inherit "/players/saber/closed/new_mini/spells/succubus_bye.c";
inherit "/players/saber/closed/new_mini/spells/succubus_talk.c";
inherit "/players/saber/closed/new_mini/spells/succubus_emote.c";
inherit "/players/saber/closed/new_mini/spells/succubus_toggle.c";
inherit "/players/saber/closed/new_mini/spells/succubus_kin.c";
inherit "/players/saber/closed/new_mini/spells/canine_muzzle.c";
inherit "/players/saber/closed/new_mini/spells/canine_lead.c";
inherit "/players/saber/closed/new_mini/spells/canine_talk.c";
inherit "/players/saber/closed/new_mini/spells/canine_emote.c";
inherit "/players/saber/closed/new_mini/spells/canine_toggle.c";
inherit "/players/saber/closed/new_mini/spells/canine_update.c";
inherit "/players/saber/closed/new_mini/spells/canine_bye.c";
inherit "/players/saber/closed/new_mini/spells/canine_kin.c";
inherit "/players/saber/closed/new_mini/spells/meow_talk.c";
inherit "/players/saber/closed/new_mini/spells/meow_emote.c";
inherit "/players/saber/closed/new_mini/spells/meow_toggle.c";
inherit "/players/saber/closed/new_mini/spells/meow_bye.c";
inherit "/players/saber/closed/new_mini/spells/meow_kin.c";
inherit "/players/saber/closed/new_mini/spells/larn_talk.c";
inherit "/players/saber/closed/new_mini/spells/larn_emote.c";
inherit "/players/saber/closed/new_mini/spells/larn_toggle.c";
inherit "/players/saber/closed/new_mini/spells/larn_bye.c";
inherit "/players/saber/closed/new_mini/spells/larn_kin.c";
inherit "/players/saber/closed/new_mini/spells/gypsy_talk.c";
inherit "/players/saber/closed/new_mini/spells/gypsy_emote.c";
inherit "/players/saber/closed/new_mini/spells/gypsy_toggle.c";
inherit "/players/saber/closed/new_mini/spells/gypsy_bye.c";
inherit "/players/saber/closed/new_mini/spells/gypsy_kin.c";
inherit "/players/saber/closed/new_mini/spells/kender_talk.c";
inherit "/players/saber/closed/new_mini/spells/kender_emote.c";
inherit "/players/saber/closed/new_mini/spells/kender_toggle.c";
inherit "/players/saber/closed/new_mini/spells/kender_bye.c";
inherit "/players/saber/closed/new_mini/spells/kender_kin.c";
inherit "/players/saber/closed/new_mini/spells/gothic_talk.c";
inherit "/players/saber/closed/new_mini/spells/gothic_emote.c";
inherit "/players/saber/closed/new_mini/spells/gothic_toggle.c";
inherit "/players/saber/closed/new_mini/spells/gothic_bye.c";
inherit "/players/saber/closed/new_mini/spells/gothic_kin.c";
inherit "/players/saber/closed/new_mini/spells/blade_talk.c";
inherit "/players/saber/closed/new_mini/spells/blade_emote.c";
inherit "/players/saber/closed/new_mini/spells/blade_toggle.c";
inherit "/players/saber/closed/new_mini/spells/blade_bye.c";
inherit "/players/saber/closed/new_mini/spells/blade_kin.c";

inherit "/players/saber/closed/new_mini/emotions/canine_bump.c";
inherit "/players/saber/closed/new_mini/emotions/canine_growl.c";
inherit "/players/saber/closed/new_mini/emotions/canine_heel.c";
inherit "/players/saber/closed/new_mini/emotions/canine_nip.c";
inherit "/players/saber/closed/new_mini/emotions/canine_tail.c";
inherit "/players/saber/closed/new_mini/emotions/canine_toy.c";
inherit "/players/saber/closed/new_mini/emotions/canine_whimper.c";
inherit "/players/saber/closed/new_mini/emotions/canine_hump.c";
inherit "/players/saber/closed/new_mini/emotions/canine_lick.c";
inherit "/players/saber/closed/new_mini/emotions/canine_pee.c";
inherit "/players/saber/closed/new_mini/emotions/canine_slobber.c";
inherit "/players/saber/closed/new_mini/emotions/canine_sniff.c";
inherit "/players/saber/closed/new_mini/emotions/canine_speak.c";

inherit "/players/saber/closed/new_mini/emotions/boggle.c";
inherit "/players/saber/closed/new_mini/emotions/kiss.c";
inherit "/players/saber/closed/new_mini/emotions/cheer.c";
inherit "/players/saber/closed/new_mini/emotions/arch.c";
inherit "/players/saber/closed/new_mini/emotions/bashful.c";
inherit "/players/saber/closed/new_mini/emotions/blush.c";
inherit "/players/saber/closed/new_mini/emotions/cold.c";
inherit "/players/saber/closed/new_mini/emotions/coo.c";
inherit "/players/saber/closed/new_mini/emotions/cool.c";
inherit "/players/saber/closed/new_mini/emotions/giggle.c";
inherit "/players/saber/closed/new_mini/emotions/giggle2.c";
inherit "/players/saber/closed/new_mini/emotions/jump.c";
inherit "/players/saber/closed/new_mini/emotions/mock.c";
inherit "/players/saber/closed/new_mini/emotions/scoff.c";
inherit "/players/saber/closed/new_mini/emotions/shy.c";
inherit "/players/saber/closed/new_mini/emotions/smile.c";
inherit "/players/saber/closed/new_mini/emotions/smolder.c";
inherit "/players/saber/closed/new_mini/emotions/spaz.c";
inherit "/players/saber/closed/new_mini/emotions/twirl.c";
inherit "/players/saber/closed/new_mini/emotions/wonder.c";
inherit "/players/saber/closed/new_mini/emotions/wry.c";
inherit "/players/saber/closed/new_mini/emotions/relax.c";
inherit "/players/saber/closed/new_mini/emotions/heartbreak.c";
inherit "/players/saber/closed/new_mini/emotions/hum.c";
inherit "/players/saber/closed/new_mini/emotions/dejected.c";
inherit "/players/saber/closed/new_mini/emotions/hopeful.c";
inherit "/players/saber/closed/new_mini/emotions/innocent.c";
inherit "/players/saber/closed/new_mini/emotions/manic.c";
inherit "/players/saber/closed/new_mini/emotions/xlaugh.c";
inherit "/players/saber/closed/new_mini/emotions/xmoan.c";
inherit "/players/saber/closed/new_mini/emotions/xlook.c";
inherit "/players/saber/closed/new_mini/emotions/xpurr.c";
inherit "/players/saber/closed/new_mini/emotions/xsexy.c";
inherit "/players/saber/closed/new_mini/emotions/xseduce.c";
inherit "/players/saber/closed/new_mini/emotions/xkiss2.c";
inherit "/players/saber/closed/new_mini/emotions/xflirt.c";
inherit "/players/saber/closed/new_mini/emotions/xlick.c";
inherit "/players/saber/closed/new_mini/emotions/xhug.c";
inherit "/players/saber/closed/new_mini/emotions/xfondle.c";
inherit "/players/saber/closed/new_mini/emotions/xremove.c";
inherit "/players/saber/closed/new_mini/emotions/mtail.c";
inherit "/players/saber/closed/new_mini/emotions/mnibble.c";
inherit "/players/saber/closed/new_mini/emotions/mscratch.c";
inherit "/players/saber/closed/new_mini/emotions/mmew.c";
inherit "/players/saber/closed/new_mini/emotions/mpurr.c";
inherit "/players/saber/closed/new_mini/emotions/mshed.c";
inherit "/players/saber/closed/new_mini/emotions/mpounce.c";
inherit "/players/saber/closed/new_mini/emotions/mgroom.c";
inherit "/players/saber/closed/new_mini/emotions/mrub.c";
inherit "/players/saber/closed/new_mini/emotions/mlick.c";
inherit "/players/saber/closed/new_mini/emotions/mchase.c";
inherit "/players/saber/closed/new_mini/emotions/mtail2.c";
inherit "/players/saber/closed/new_mini/emotions/mchomp.c";
inherit "/players/saber/closed/new_mini/emotions/pocket.c";
inherit "/players/saber/closed/new_mini/emotions/bop.c";
inherit "/players/saber/closed/new_mini/emotions/shrill.c";
inherit "/players/saber/closed/new_mini/emotions/blade_twirl.c";
inherit "/players/saber/closed/new_mini/emotions/blade_wipe.c";
inherit "/players/saber/closed/new_mini/emotions/blade_display.c";

int spell(int cutoff_ali, int min_level, int sp_cost) {
if(ALI<cutoff_ali) {notify_fail(NOT_GOOD); return -1;}
if(LEVEL<min_level) {notify_fail(NOT_LEVEL); return -1;}
if(SPELL<sp_cost) {notify_fail(NOT_SP); return -1;}
return 1;
        }

int attack_spell(int cutoff_ali, int min_level, int sp_cost, object ob) {
if(spell(cutoff_ali, min_level, sp_cost) ==-1) return -1;
if(TP->query_ghost()) {notify_fail("You must be alive to do that.\n"); return -1;}
if(!ob){notify_fail("That is not here.\n"); return -1;  }
if(!living(ob)) {notify_fail("Target must be alive to do that.\n"); return -1;}
if(ob->is_player()) {notify_fail(NO_PK); return -1;}
return 1;
        }
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
