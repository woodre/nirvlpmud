/*
 * This shadow object enables you to get the spell attribute array
 * loaded straight to an object, rather than using the player object.
 *
 * Usage: in your spell object
 *
 * To get the loading spell array,
 * spell = (mixed *)clone_object("obj/shadows/get_spell")->get_spell(spell);
 *
 * To get the loaded spell array, if this_player() or wand is able to cast
 * the spell wrt spell level, spell components, and spell points
 * (or casting level, and charges in the case of a wand).
 *
 * Why clone? Each shadow object will only allow the object to shadow one
 * object.  If you don't clone it, it will stuff it up for others who may
 * want to use this object
 *
 */

inherit "obj/shadows/shadow";
#include <spell.h>

#define BINS ({ "/skills/mage/", "/skills/cleric/", })

mixed *loading_spell_array;  /* array used to load the spell */


/* gets an array == spell loading array */

mixed *get_spell(string spell, string target, mixed alt_type) {
  int i;
  string file, bin;
  string spell2;

  if (sscanf(spell, "%s %s", spell, spell2) == 2) {
    target = (target) ? spell2 + " " + target : spell2;
  }
  sscanf(spell, "%s@%s", bin, spell); /* force spell from 1 bin */
  shadow_object(this_player());       /* shadows this player */
  for (i = 0; i < sizeof(BINS); i++) {
    if (bin && BINS[i] != "/skills/" + bin + "/") continue;
    if (file_size(BINS[i] + spell + ".c") > 0) {
      file = BINS[i] + spell;
      call_other(file, spell, target, alt_type);
      if (loading_spell_array) {     /* spell loaded - right bin */
        break;
      }
    }
  }
  if (!file) {
    shadow_object(0);
    return ({});
  }
  shadow_object(0);   /* destructs shadow */
  return (loading_spell_array) ? loading_spell_array : ({});
}


/* gets an array == query_loaded_spell() in living */

mixed *get_loaded_spell(string spell, string target, mixed alt_type,
                        status msg) {
  int i;
  string bin;
  mixed *arr, *loaded_spell;
  string file, tmp1, tmp2;
  string spell2;
  status player;

  if (sscanf(spell, "%s %s", spell, spell2) == 2) {
    target = (target) ? spell2 + " " + target : spell2;
  }
  sscanf(spell, "%s@%S", bin, spell);
  shadow_object(this_player());      /* shadows this player */
  for (i = 0; i < sizeof(BINS); i++) {
    if (bin && BINS[i] != "/skills/" + bin + "/") continue;
    if (file_size(BINS[i] + spell + ".c") > 0) {
      file = BINS[i] + spell;
      call_other(file, spell, target, alt_type);
      if (loading_spell_array) { /* spell loaded - right bin */
        break;
      }
    }
  }
  if (!file) {
    if (msg) {
      write("The spell " + spell + ((spell2) ? spell2 : "") +
            " has never been researched.\n");
    }
    shadow_object(0);
    return ({});
  }
  if (!loading_spell_array) {
    if (msg) {
      write("You cannot use the spell " + spell + ((spell2) ? spell2 : "") +
            " that way.\n");
    }
    shadow_object(0);
    return ({});
  }

  arr = loading_spell_array;

  loaded_spell = allocate(SPELL_ALLOCATE);
  for (i = 0; i < sizeof(arr); i++) {
    if (!stringp(arr[i])) continue;
    switch(arr[i]) {
      case "target":                    TARGET      = arr[++i];  break;
      case "name": case "spellname":    SPELL_NAME  = arr[++i];  break;
      case "school": case "sphere":     SPELL_TYPE  = arr[++i];  break;
      case "cost":                      SPELL_COST  = arr[++i];  break;
      case "damage":                    SPELL_DAM   = arr[++i];  break;
      case "msg target":                TARGET_MSG  = arr[++i];  break;
      case "msg room":                  ROOM_MSG    = arr[++i];  break;
      case "msg caster":                CASTER_MSG  = arr[++i];  break;
      case "area":                 AREA_EFFECT = this_player();  break;
      case "immune":                    IMMUNE_TYPE = arr[++i];  break;
      case "level": case "spell_level": SPELL_LEVEL = arr[++i];  break;
      case "spell object":              SPELL_OBJ   = arr[++i];  break;
      case "time": case "cast time":    SPELL_TIME  = arr[++i];  break;
      case "casting msg":               PREPARE_MSG = arr[++i];  break;
      case "casting msg room":        PREP_MSG_ROOM = arr[++i];  break;
      case "component":                 COMPONENT   = arr[++i];  break;
      case "passive":                   PASSIVE     = 1;         break;
      case "aggressive":                PASSIVE     = 0;         break;
      case "argument":                  ARGUMENT    = arr[++i];  break;
    }
  }
  if (!objectp(SPELL_TYPE)) {
    if (SPELL_TYPE) {
      prayer = (sscanf(SPELL_TYPE, "%ssphere%s", tmp1, tmp2)) ? 1 : 0;
    }
    if (COMPONENT) {  /* get component list */
      COMPONENT = (object *)this_player()->parse_component(COMPONENT);
      if (!sizeof(COMPONENT)) {
        if (msg) {
          write("You do not have the necessary components for the " +
                ((prayer) ? "prayer" : "spell") + ".\n");
        }
        shadow_object(0);
        return ({});
      }
    }
    if ((int)this_player()->query(SPELL_TYPE) < SPELL_LEVEL) {
      if (msg) {
        if (prayer)
          write("Your God will not grant you that prayer.\n");
        else
          write("You do not have enough knowledge to cast that spell.\n");
      }
      shadow_object(0);
      return ({});
    }
    if ((int)this_player()->query(SPELL_TYPE + "_points") < SPELL_COST) {
      if (msg) {
        write(((SPELL_NAME) ? "Your " + SPELL_NAME : "It") + " fizzles!!\n");
      }
      shadow_object(0);
      return ({});
    }
  }
  else { /* wand */
    COMPONENT = ({});
    if ((int)SPELL_TYPE->query_charges() < SPELL_COST) {
      if (msg) {
        write(((SPELL_NAME) ? "Your " + SPELL_NAME : "It") + " fizzles!!\n");
      }
      shadow_object(0);
      return ({});
    }
  }
  if (PREPARE_MSG && !pointerp(PREPARE_MSG)) {
    PREPARE_MSG = ({ PREPARE_MSG, });
  }
  if (PREP_MSG_ROOM && !pointerp(PREP_MSG_ROOM)) {
    PREP_MSG_ROOM = ({ PREP_MSG_ROOM, });
  }
  shadow_object(0);
  return loaded_spell;
}


/* shadowed spell loading function */

void load_spell(mixed *arg) { loading_spell_array = arg; }

