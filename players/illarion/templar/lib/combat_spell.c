/* combat_spell.c
 *
 * inheritable object for templar combat spells
 * the vars should be self-explanatory, set them up in
 * reset with direct assign.
 *
 * This allows idiotproofing and related things to be
 * done automatically, so that spells can be set up
 * quickly and easily
 *
 * note that emotes support multiple codes for customization
 *
 * they can contain &functionname& one or more times
 * which will result in that string being replaced with
 * whatever this_object()->functionname(damage) returns
 *
 * the results of that are fed through /obj/user/parse_emote.c
 * (It's best to hardcode ansi colors rather than using color
 * codes to increase efficiency, but you can use color codes
 * if you prefer.)
 *
 * Finally, the result is fed through an ansi-friendly
 * formatter, so only put newlines in your emotes where
 * you want to force a line break.
 *
 */

/* configurable variables */ 
int sp_required;
int piety_required;
int kpts_needed;
int glev_needed;

int fixed_dam;
int rand_dam;
string dam_type;

string hit_mess_caster;
string hit_mess_target;
string hit_mess_room;

string extra_func;  /* called in the event of a successful cast so you can
                       do things the code doesn't cover
                     */

status use_direct_dam; /* if 0, spell_object is used */

/* internal variables (don't set these up) */
object caster,target,room;