/*
  emotions.h
*/

#include "defs.h"

vglare(str) {
object target_obj;

if(!str) {
  say(MY_NAME_CAP+" glares about the room in disgust.\n");
  write("You glare about the room in disgust.\n");
  return 1; }
target_obj = find_player(str);
if(!target_obj) {
  write(capitalize(str)+" doesn't seem to be logged on.\n");
  return 1; }
if (target_obj->query_level() > 20 && target_obj->query_invis() > 0)
    return 0;
tell_object(target_obj,
    "You feel a chill run down your spine as "+MY_NAME_CAP+
    "'s eyes glow\n"+
    HIR+"a bloody red"+NORM+" and "+MY_PLAYER->query_pronoun() +
    " glares balefully at you.\n");
write("You see "+capitalize(target_obj->query_name())+
        " shiver as you glare balefully at "+
        target_obj->query_objective()+".\n");
return 1;
}

vkiss(str) {
  object target_obj;

  if (!str) return 0;
  target_obj = find_player(str);
  if (!target_obj) return 0;
  if (target_obj->query_level() > 20 && target_obj->query_invis() > 0)
    return 0;
  tell_object(target_obj,
    MY_NAME_CAP+" runs "+MY_PLAYER->query_possessive()+" tongue across "+
    MY_PLAYER->query_possessive()+" fangs with anticipation.\n"+
    MY_NAME_CAP+" mesmerises you with "+MY_PLAYER->query_possessive()+
    " eyes and pulls you in close.\n"+
    "Before you can do anything, "+MY_PLAYER->query_possessive()+
    " lips slide back, exposing "+MY_PLAYER->query_possessive()+" fangs.\n"+
    capitalize(MY_PLAYER->query_pronoun())+
    " kisses you deeply, and you feel "+MY_PLAYER->query_possessive()+
    " fangs nip your lower lip.\n");
  write("You run your tongue across your fangs with anticipation.\n"+
        "You focus your eyes on "+capitalize(str)+
        " and pull "+target_obj->query_objective()+" in close.\n"+
        "Before "+target_obj->query_pronoun()+" can do anything, "+
        "your lips slide back, exposing your fangs.\n"+
        "You kiss "+capitalize(str)+" deeply, and you feel your "+
        "fangs nip "+target_obj->query_possessive()+" lower lip.\n");
  return 1;
}

fart() {
  if (!MY_FANGS->query_in_a_form()) return 0;
  if (MY_FANGS->query_form_description()=="mist") {
    write("You can't do that while in mist form.\n");
    return 1;
  }
  write("How rude!\n");
  tell_room(environment(MY_ROOM),
            "The "+MY_FANGS->query_form_description()+
            " lets off a real rip-roarer.\n");
  return 1;
}

generic(str) {
  string what;
  object who;
  what = query_verb();
  if (!MY_FANGS->query_in_a_form() && what != "grin") return 0;
  if (!MY_FANGS->query_in_a_form()) {
    grin_2(str);
    return 1;
  }
  if(!str) {
    tell_room(environment(MY_ROOM),
      "The "+MY_FANGS->query_form_description()+" "+what+"s.\n");
    return 1;
  }
  who = present(lower_case(str), environment(MY_ROOM));
  if (!who || !living(who) || who==MY_PLAYER) return 0;
  tell_object(who,
    "The "+MY_FANGS->query_form_description()+" "+what+"s at you.\n");
  tell_room(environment(MY_ROOM),
            "The "+MY_FANGS->query_form_description()+" "+what+
            "s at "+capitalize(str)+".\n");
  return 1;
}

/* --------- Modified grin -------- */
grin_2(str) {
  object target_obj;
  if(!str) {
    if (MY_FANGS->query_disguise_on()) {
      MY_FANGS->tell_my_room(MY_NAME_CAP+" grins innocently.");
      write("You conceal your fangs and grin innocently.\n");
      return 1;
    }
    MY_FANGS->tell_my_room(
                 MY_NAME_CAP+" grins evilly, exposing "+
                 MY_PLAYER->query_possessive()+" fangs.");
    write("You grin widely, exposing your fangs.\n");
    return 1;
  }
  target_obj = present(lower_case(str), MY_ROOM);
  if (!target_obj) {
    target_obj = find_player(str);
    if (!target_obj) return 0;
    if (target_obj->query_level() > 20 && target_obj->query_invis() > 0)
      return 0;
    if (MY_FANGS->query_disguise_on()) {
      tell_object(target_obj,
                  MY_NAME_CAP+" grins innocently at you from afar.\n");
      write("You conceal your fangs and grin innocently at "+
            target_obj->query_name()+" in the distance.\n");
      return 1;
    }
    tell_object(target_obj,
                MY_NAME_CAP+" grins at you from afar, exposing "+
                MY_PLAYER->query_possessive()+" fangs.\n");
    write("You grin widely at "+target_obj->query_name()+
          " in the distance, exposing your fangs.\n");
    return 1;
  }
  if (!target_obj || !living(target_obj) || target_obj==MY_PLAYER) return 0;
  if (MY_FANGS->query_disguise_on()) {
    MY_FANGS->tell_my_room(MY_NAME_CAP+" grins innocently.");
    write("You conceal your fangs and grin innocently.\n");
    return 1;
  }
  MY_FANGS->tell_my_room(
              MY_NAME_CAP+" grins at "+capitalize(str)+", exposing "+
              MY_PLAYER->query_possessive()+" fangs.", str);
  write("You grin widely at "+target_obj->query_name()+
        ", exposing your fangs.\n");
  return 1;
}

laugh() {
  if (!MY_FANGS->query_in_a_form()) return 0;
  if (MY_FANGS->query_form_description()=="mist") {
    tell_room(environment(MY_ROOM),
              "The mist swirls quickly and you hear laughing.\n");
    return 1;
  }
  tell_room(environment(MY_ROOM),
            "The "+MY_FANGS->query_form_description()+
            " falls down laughing.\n");
  return 1;
}

lick(str) {
  object who;
  if (!MY_FANGS->query_in_a_form()) return 0;
  if (str == 0) return 0;
  if (MY_FANGS->query_form_description()=="mist") {
    write("You can't do that while in mist form.\n");
    return 1;
  }
  who = present(lower_case(str), environment(MY_ROOM));
  if (!who || !living(who) || who == MY_PLAYER) return 0;
  tell_object(who, "The "+MY_FANGS->query_form_description()+" licks you.\n");
  tell_room(environment(MY_ROOM),
            "The "+MY_FANGS->query_form_description()+
            " licks "+capitalize(str)+".\n");
  return 1;
}

nod(str) {
  object who;
  if (!MY_FANGS->query_in_a_form()) return 0;
  if (MY_FANGS->query_form_description()=="mist") {
    write("You can't do that while in mist form.\n");
    return 1;
  }
  if(!str) {
    tell_room(environment(MY_ROOM),
              "The "+MY_FANGS->query_form_description()+" nods sagely.\n");
    return 1;
  }
  who = present(lower_case(str), environment(MY_ROOM));
  if (!who || !living(who) || who == MY_PLAYER) return 0;
  tell_object(who, "The "+MY_FANGS->query_form_description()+" nods to you.\n");
  tell_room(environment(MY_ROOM),
            "The "+MY_FANGS->query_form_description()+
            " nods to "+capitalize(str)+".\n");
  return 1;
}

shake(str) {
  object who;
  if (!MY_FANGS->query_in_a_form()) return 0;
  if (MY_FANGS->query_form_description()=="mist") {
    write("You can't do that while in mist form.\n");
    return 1;
  }
  if(!str) {
    tell_room(environment(MY_ROOM),
              "The "+MY_FANGS->query_form_description()+" shakes "+
              MY_PLAYER->query_possessive()+" head.\n");
    return 1;
  }
  who = present(lower_case(str), environment(MY_ROOM));
  if (!who || !living(who) || who == MY_PLAYER) return 0;
  tell_object(who,
    "The "+MY_FANGS->query_form_description()+" shakes your hand with "+
    MY_PLAYER->query_possessive()+" paw.\n");
  tell_room(environment(MY_ROOM),
    "The "+MY_FANGS->query_form_description()+" shakes "+capitalize(str)+
    "'s hand with "+MY_PLAYER->query_possessive()+" paw.\n");
  return 1;
}

shrug() {
  if (!MY_FANGS->query_in_a_form()) return 0;
  if (MY_FANGS->query_form_description()=="mist") {
    write("You can't do that while in mist form.\n");
    return 1;
  }
  tell_room(environment(MY_ROOM),
            "The "+MY_FANGS->query_form_description()+" shrugs helplessly.\n");
  return 1;
}

sigh() {
  if (!MY_FANGS->query_in_a_form()) return 0;
  tell_room(environment(MY_ROOM),
    "The "+MY_FANGS->query_form_description()+" seems to sigh deeply.\n");
  return 1;
}

vsmile(str) {
object who;
if(!str) {
  say(MY_NAME_CAP+" smiles at you, exposing "+
      MY_PLAYER->query_possessive()+" sharp fangs.\n");
  write("You smile, exposing your sharp fangs.\n");
  return 1; }
who = find_player(str);
if(!who) { write("Not logged on!\n"); return 1; }
if(!present(str,environment(this_player())) && who) {
  tell_object(who,MY_NAME_CAP+" smiles at you from afar, exposing "+
    MY_PLAYER->query_possessive()+" sharp fangs.\n");
  write("You smile at "+capitalize(str)+" off in the distance, exposing"+
    " your fangs.\n");
  return 1; }
if(present(str,environment(this_player()))) {
  say(MY_NAME_CAP+" smiles at "+capitalize(str)+", exposing "+
      MY_PLAYER->query_possessive()+" sharp fangs.\n");
  write("You smile at "+capitalize(str)+", exposing your sharp fangs.\n");
  return 1; }
else {
  write("You don't see "+capitalize(str)+" here.\n");
  return 1; }
}

sniff(str) {
  object who;
  if (!MY_FANGS->query_in_a_form()) return 0;
  if (MY_FANGS->query_form_description()=="mist") {
    write("You can't do that while in mist form.\n");
    return 1;
  }
  if(!str) {
    tell_room(environment(MY_ROOM),
              "The "+MY_FANGS->query_form_description()+" sniffs the air.\n");
    return 1;
  }
  who = present(lower_case(str), environment(MY_ROOM));
  if (!who || !living(who) || who == MY_PLAYER) return 0;
  tell_object(who, "The "+MY_FANGS->query_form_description()+" sniffs you.\n");
  tell_room(environment(MY_ROOM),
    "The "+MY_FANGS->query_form_description()+" sniffs "+capitalize(str)+".\n");
  return 1;
}

thank(str) {
  object who;
  if (!MY_FANGS->query_in_a_form()) return 0;
  if (str == 0) return 0;
  who = present(lower_case(str), environment(MY_ROOM));
  if (!who || !living(who) || who == MY_PLAYER) return 0;
  tell_room(environment(MY_ROOM),
    "The "+MY_FANGS->query_form_description()+" thanks "+capitalize(str)+".\n");
  tell_object(who, "The "+MY_FANGS->query_form_description()+" thanks you.\n");
  return 1;
}

/* -------- Think command ---------- */
think(str) {
  object obj, stuff, curse_obj;
  string who, msg, player_list, junk1, junk2;
  if (!str) {
    write("Hmmm.  No thoughts at all huh?\n");
    return 1;
  }
  /* censorship! */
  if (sscanf(str, "%snanny%s", junk1, junk2)==2 ||
      sscanf(str, "%sNanny%s", junk1, junk2)==2 ||
      sscanf(str, "%sNANNY%s", junk1, junk2)==2) {
    write("\nYou asked for it!\n\n");
    curse_obj = present("guild nanny curse", MY_PLAYER);
    if (curse_obj) {
      write("You still haven't learned?\n");
    }
    else {
      obj = clone_object(GUILD_NANNY_CURSE);
      move_object(obj, MY_PLAYER);
      obj->start_curse();
    }
  }
  tell_room(MY_ROOM, RED+MY_NAME_CAP+" . o O ("+NORM+str+RED+")"+NORM+"\n");
  return 1;
}

yawn() {
  if (!MY_FANGS->query_in_a_form()) return 0;
  tell_room(environment(MY_ROOM),
    "The "+MY_FANGS->query_form_description()+
    " yawns, exposing needle sharp fangs.\n");
  return 1;
}
