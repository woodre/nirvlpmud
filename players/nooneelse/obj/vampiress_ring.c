/*
 vampiress_ring.c
*/

inherit "obj/armor";

object other_guy;

int times_used, destruct_potential;

string str, owner_of_ring, echo_msg, verb, this_player_name;

init(arg) {
  ::init(arg);

  add_action("read",      "read");
  add_action("heal",      "heal");
  add_action("sell",      "sell");
  add_action("set_owner", "set");
}

read(str) {
  if (!str && str != "ring" && str != "words") return;
  if (query_worn()) {
    write("Huh?  You can't read the writing in the ring while "+
          "it's on your finger.\n");
    return 1;
  }
  say(this_player()->query_name()+
      " examines the inside of the malachite ring.\n");
  write("The writing says, use: 'heal me' to heal yourself some.\n"+
        "                       'heal <name>' to heal 'name' some.\n"+
        "(Beware!  Using this ring on someone else could damage it!\n"+
        " Also, as with all magic items, overuse can damage it.)\n");
  return 1;
}

heal(str) { if (!str) return;
  if (!query_worn()) {
    write("Huh?  You can't use the ring unless it's on your finger.\n");
    return 1;
  }
  if (check_owner("use")) return 1;
  say(owner_of_ring+"'s malachite ring glows blue for a moment.\n");
  write("Your malachite ring glows blue for a moment.\n");
  if (str=="me") {
    write("You feel a little better.\n");
    this_player()->heal_self(10);
  }
  else {
    other_guy=present(lower_case(str), environment(this_player()));
    if (!other_guy) {
      write("But, "+capitalize(str)+" isn't here!\n");
      return 1;
    }
    tell_object(other_guy, "You feel a little better.\n");
    this_player()->heal_self(5);
  }
  times_used++;
  set_value(1000/times_used);

/* let them use it a few times at least :) */
  if (times_used < 5) return 1;

/* will it trash itself this time? */
  destruct_potential = times_used * 2;
  if (str != "me") destruct_potential += 10;
  if (random(100) < destruct_potential) {
    say(this_player()->query_name()+
        "'s malachite ring flares blue and disappears.\n");
    write("The ring flares a searing blue, blinding you for a moment!\n"+
          "When your vision clears, you see that the ring is gone!\n");
    destruct(this_object());
  }
  return 1;
}

sell(str) {
  if (!str || str != "ring") return;
  if (check_owner("sell")) return 1;
}

set_owner(str) {
  string str1, str2;
  if (this_player()->query_level() < 21) return;
  if (!str) {
    write("Use: set owner <who>\n");
    return 1;
  }
  sscanf(str, "%s %s", str1, str2);
  if (str1 != "owner" || !str2) {
    write("Use: set owner <who>\n");
    return 1;
  }
  set_owner_of_ring(capitalize(str2));
  return 1;
}

reset(arg) {
  if (arg) return;
  ::reset(arg);

  set_name("malachite ring");
  set_type("ring");
  set_value(1000);
  set_weight(1);
  set_ac(1);
  set_owner_of_ring("nooneelse");
}

short() { return "A malachite ring"; }

long() {
  write(short()+".  From it's aura, you sense that it belongs to "+
        owner_of_ring+".\n"+
        "It has a large 'N' engraved on the band.  "+
        "You can also see some words etched\n"+
        "inside the ring.\n");
}

set_owner_of_ring(str) { owner_of_ring = capitalize(str); }

check_owner(verb) {
  this_player_name=this_player()->query_name();
  if (this_player_name==owner_of_ring) return;
  write("The ring jumps out of your hands saying:\n"+
        "   What!  Who are you?  I don't belong to you!  Let me go!\n");
  echo_msg="The ring forces "+this_player_name+" to drop it and says:\n"+
           "   Help!  "+this_player_name+" is trying to "+verb+" "+
           owner_of_ring+"'s ring!\n";
  say(echo_msg);
  move_object(this_object(), environment(this_player()));
  return 1;
}

id(str) { return (str=="ring" ||
                  str=="malachite ring" ||
                  str=="vampiressring"); }
