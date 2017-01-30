/*
 cult_form_maker.c
*/

string form_owner_name, form_description, new_form_description, str;
int in_a_form;
object new_form_obj, form_obj;

init(str) {
  add_action("create_form",    "mist");
  add_action("create_form",    "bat");
  add_action("create_form",    "wolf");
  /* make up some soul actions for use in the forms */
  add_action("nope",    "applaud");
  add_action("nope",    "blush");
  add_action("nope",    "bounce");
  add_action("nope",    "bow");
  add_action("nope",    "burp");
  add_action("nope",    "cackle");
  add_action("nope",    "chuckle");
  add_action("nope",    "clap");
  add_action("nope",    "comfort");
  add_action("nope",    "cough");
  add_action("nope",    "cry");
  add_action("nope",    "cuddle");
  add_action("nope",    "curtsey");
  add_action("nope",    "dance");
  add_action("fart",    "fart");
  add_action("nope",    "flip");
  add_action("nope",    "fondle");
  add_action("nope",    "french");
  add_action("generic", "frown");
  add_action("nope",    "gasp");
  add_action("nope",    "giggle");
  add_action("generic", "glare");
  add_action("generic", "grin");
  add_action("nope",    "groan");
  add_action("nope",    "grope");
  add_action("generic", "growl");
  add_action("nope",    "hiccup");
  add_action("nope",    "hug");
  add_action("nope",    "kick");
  add_action("nope",    "kiss");
  add_action("nope",    "knee");
  add_action("laugh",   "laugh");
  add_action("lick",    "lick");
  add_action("nope",    "love");
  add_action("nope",    "moan");
  add_action("nope",    "nibble");
  add_action("nod",     "nod");
  add_action("nope",    "poke");
  add_action("nope",    "pout");
  add_action("nope",    "puke");
  add_action("nope",    "purr");
  add_action("nope",    "ruffle");
  add_action("nope",    "scream");
  add_action("shake",   "shake");
  add_action("nope",    "shiver");
  add_action("shrug",   "shrug");
  add_action("sigh",    "sigh");
  add_action("nope",    "sing");
  add_action("nope",    "slap");
  add_action("nope",    "smirk");
  add_action("smile",   "smile");
  add_action("nope",    "snap");
  add_action("nope",    "sneeze");
  add_action("nope",    "snicker");
  add_action("sniff",   "sniff");
  add_action("nope",    "snore");
  add_action("nope",    "snuggle");
  add_action("nope",    "spit");
  add_action("nope",    "squeeze");
  add_action("nope",    "stare");
  add_action("nope",    "strut");
  add_action("nope",    "sulk");
  add_action("thank",   "thank");
  add_action("nope",    "twiddle");
  add_action("nope",    "whistle");
  add_action("nope",    "wiggle");
  add_action("nope",    "wink");
  add_action("yawn",    "yawn");
}

create_form(str) {
  string new_form_desc_stuff;
  if (!str || str != "form") return;
  new_form_description = query_verb();
  if (in_a_form &&
      environment(this_player())!="players/nooneelse/closed/cult_form") {
    form_owner_name=0;
    form_description=0;
    in_a_form=0;
  }
  if (in_a_form) {
    write("Your "+form_description+" form seems to waiver for a moment, "+
          "then assumes the shape of a "+new_form_description+".\n");
    tell_room(environment(environment(this_player())),
           "The "+form_description+
           " seems to waiver for a moment, then assumes the shape of a "+
           new_form_description+".\n");
  }
  else {
    write("Your body seems to waiver for a moment, "+
          "then assumes the shape of a "+new_form_description+".\n");
    say(capitalize(this_player()->query_name())+
         "'s body seems to waiver for a moment, then assumes the shape of a "+
         new_form_description+".\n", this_player());
  }
  form_description=new_form_description;
  new_form_obj=move_object(clone_object("/players/nooneelse/closed/cult_form"),
                           environment(this_player()));
  form_owner_name=lower_case(this_player()->query_real_name());
  form_description = query_verb();
  new_form_desc_stuff = form_owner_name+" "+form_description;
  new_form_obj->set_form(new_form_desc_stuff);
  move_object(this_player(), new_form_obj);
  if (form_obj) destruct(form_obj);
  form_obj = new_form_obj;
  in_a_form=1;
  return 1;
}


nope() {
  if (environment(this_player()) != this_object()) return;
  write("You can't do that while in "+form_description+" form.\n");
  return 1;
}

fart() {
  if (environment(this_player()) != this_object()) return;
  if (form_description=="mist") {
    write("You can't do that while in mist form.\n");
    return 1;
  }
  write("How rude!\n");
  say("The "+form_description+" lets off a real rip-roarer.\n");
  return 1;
}

generic(str) {
  string what;
  object who;
  what = query_verb();
  if (environment(this_player()) != this_object()) return;
  if(!str) {
    write("You "+what+".\n");
    say("The "+form_description+" "+what+"s.\n");
    return 1;
  }
  who = present(lower_case(str), environment(this_object()));
  if (!who || !living(who) || who == this_player()) return;
  tell_object(who, "The "+form_description+" "+what+"s at you.\n");
  write("You "+what+" at "+capitalize(str)+".\n");
  say("The "+form_description+" "+what+"s at "+capitalize(str)+".\n", who);
  return 1;
}

laugh() {
  if (environment(this_player()) != this_object()) return;
  if (form_description=="mist") {
    write("You cause the mist to swirl quickly as you laugh.\n");
    say("The mist swirls quickly and you hear laughing.\n");
    return 1;
  }
  write("You fall down laughing.\n");
  say("The "+form_description+" falls down laughing.\n");
  return 1;
}

lick(str) {
  object who;
  if (environment(this_player()) != this_object()) return;
  if (str == 0) return;
  if (form_description=="mist") {
    write("You can't do that while in mist form.\n");
    return 1;
  }
  who = present(lower_case(str), environment(this_object()));
  if (!who || !living(who) || who == this_player()) return;
  tell_object(who, "The "+form_description+" licks you.\n");
  say("The "+form_description+" licks "+capitalize(str)+".\n", who);
  write("You lick "+capitalize(str)+".\n");
  return 1;
}

nod(str) {
  object who;
  if (environment(this_player()) != this_object()) return;
  if (form_description=="mist") {
    write("You can't do that while in mist form.\n");
    return 1;
  }
  if(!str) {
    write("You nod sagely.\n");
    say("The "+form_description+" nods sagely.\n");
    return 1;
  }
  who = present(lower_case(str), environment(this_object()));
  if (!who || !living(who) || who == this_player()) return;
  tell_object(who, "The "+form_description+" nods to you.\n");
  say("The "+form_description+" nods to "+capitalize(str)+".\n", who);
  write("You nod to "+capitalize(str)+".\n");
  return 1;
}

shake(str) {
  object who;
  if (environment(this_player()) != this_object()) return;
  if (form_description=="mist") {
    write("You can't do that while in mist form.\n");
    return 1;
  }
  if(!str) {
    write("You shake your head.\n");
    say("The "+form_description+" shakes "+this_player()->query_possessive()+
        " head.\n");
    return 1;
  }
  who = present(lower_case(str), environment(this_object()));
  if (!who || !living(who) || who == this_player()) return;
  tell_object(who, "The "+form_description+" shakes your hand with "+
              this_player()->query_possessive()+" paw.\n");
  write("You shake hands with "+capitalize(str) +".\n");
  say("The "+form_description+" shakes "+capitalize(str)+"'s hand with "+
      this_player()->query_possessive()+" paw.\n", who);
  return 1;
}

shrug() {
  if (environment(this_player()) != this_object()) return;
  if (form_description=="mist") {
    write("You can't do that while in mist form.\n");
    return 1;
  }
  write("You shrug.\n");
  say("The "+form_description+" shrugs helplessly.\n");
  return 1;
}

sigh() {
  if (environment(this_player()) != this_object()) return;
  write("You sigh.\n");
  say("The "+form_description+" seems to sigh deeply.\n");
  return 1;
}

smile(str) {
  object who;
  if (environment(this_player()) != this_object()) return;
  if (form_description=="mist") {
    write("You can't do that while in mist form.\n");
    return 1;
  }
  if(!str) {
    write("You smile happily, exposing sharp fangs.\n");
    say("The "+form_description+" smiles happily, exposing sharp fangs.\n");
    return 1;
  }
  who = present(lower_case(str), environment(this_object()));
  if (!who || !living(who) || who == this_player()) return;
  tell_object(who, "The "+form_description+
              " smiles at you, exposing sharp fangs.\n");
  write("You smile at "+capitalize(str)+", exposing sharp fangs.\n");
  say("The "+form_description+" smiles at "+capitalize(str)+
      ", exposing sharp fangs.\n", who);
  return 1;
}

sniff() {
  object who;
  if (environment(this_player()) != this_object()) return;
  if (form_description=="mist") {
    write("You can't do that while in mist form.\n");
    return 1;
  }
  if(!str) {
    write("You sniff the air.\n");
    say("The "+form_description+" sniffs the air.\n");
    return 1;
  }
  who = present(lower_case(str), environment(this_object()));
  if (!who || !living(who) || who == this_player()) return;
  tell_object(who, "The "+form_description+" sniffs you.\n");
  write("You sniff "+capitalize(str)+".\n");
  say("The "+form_description+" sniffs "+capitalize(str)+".\n", who);
  return 1;
}

thank(str) {
  object who;
  if (environment(this_player()) != this_object()) return;
  if (str == 0) return;
  who = present(lower_case(str), environment(this_object()));
  if (!who || !living(who) || who == this_player()) return;
  write("You thank "+capitalize(str)+".\n");
  say("The "+form_description+" thanks "+capitalize(str)+".\n", who);
  tell_object(who, "The "+form_description+" thanks you.\n");
  return 1;
}

yawn() {
  if (environment(this_player()) != this_object()) return;
  write("My, what big teeth you have!\n");
  say("The "+form_description+" yawns, exposing needle sharp fangs.\n");
  return 1;
}

short() {
  return "A cult form maker.  Use: <mist/bat/wolf> form";
}

long() {
  write(short()+"\n");
}

get() { return 1; }

drop() {return 1; }

id(str) { return str=="form maker" ||
                 str=="form_maker";
}

catch_tell(str) {
  string str2;
tell_object(find_player("nooneelse"), "catch_tell(str)="+str+"\n");
str2=query_verb();
tell_object(find_player("nooneelse"), "verb="+str2+"\n");
  str2=0;
  sscanf(str, "A tenuous mist %s", str2);
  if (!str2) sscanf(str, "A huge, black bat %s", str2);
  if (!str2) sscanf(str, "A large, grey wolf %s", str2);
  if (str2) return 1;
  return;
}
