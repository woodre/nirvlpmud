/*
 * Faction pet summoning
 * Rumplemintz
 */

int main(string str) {
  string type;
  object badge, badgepet, petob;


  type = query_verb();
  badge = present("V-GUILD", this_player());
  badgepet = (object)badge->query_pet_object();

  if (!str) str = "help";

  switch(str) {
    case "help":
      write(read_file("/players/guilds/dopplegangers/docs/" + type));
      return 1;
      break;
    case "summon":
      if (badgepet) {
        write("You already have a pet.\n");
        return 1;
      }
      if (this_player()->query_guild_rank() < 12) {
        write("You are not high enough level for that.\n");
        return 1;
      }
      if (this_player()->query_spell_point() < 100) {
        write("You do not have enough spell points for that.\n");
        return 1;
      }
      petob = clone_object("/players/guilds/dopplegangers/obj/faction_pet");
      petob->set_owner(this_player());
      petob->set_nme(capitalize((string)this_player()->query_real_name()));
      petob->set_own_name((string)this_player()->query_real_name());
      petob->set_what(type);
      petob->set_short(capitalize((string)this_player()->query_real_name()) +
                       "'s " + type);
      petob->set_level((int)this_player()->query_guild_rank());
      petob->set_wc(15 + ((int)this_player()->weapon_class()));
      petob->set_ac(5 + ((int)this_player()->armor_class()));
      petob->set_level((int)this_player()->query_level());
      petob->set_name(capitalize(type));
      petob->set_heart_beat(1);
      move_object(petob, environment(this_player()));
      badge->set_pet_object(petob);
      this_player()->add_spell_point(-100);
      write("You summon " + (type == "imp" ? "an" : "a") + " " + type +
            " to your side. (type \"" + type + " help\" for more help)\n");
      say(this_player()->query_name() + " summons " +
          (type == "imp" ? "an" : "a") + " " + type + " to " +
          this_player()->query_possessive() + " side.\n");
      return 1;
      break;
    case "bring":
      if (!badgepet) return 0;
      write("Your " + type + " runs to your side.\n");
      say(this_player()->query_name() + " orders " +
          this_player()->query_possessive() + " " + type + " to " +
          this_player()->query_possessive() + " side.\n");
      tell_room(environment(badgepet), this_player()->query_name() +
                " orders " + this_player()->query_possessive() + " " + type +
                " to " + this_player()->query_possessive() + " side.\n");
      move_object(badgepet, environment(this_player()));
      return 1;
      break;
    case "leave":
      if (!badgepet) return 0;
      write("You release your " + type + ".\n");
      say(this_player()->query_name() + " releases " +
          this_player()->query_possessive() + " " + type + ".\n");
      badge->set_pet_object(0);
      destruct(badgepet);
      return 1;
    case "follow":
      if (!badgepet) return 0;
      badgepet->follow();
      return 1;
      break;
    case "stay":
      if (!badgepet) return 0;
      badgepet->stay();
      return 1;
      break;
    case "look":
      if (!badgepet) return 0;
      badgepet->Look();
      return 1;
      break;
    default:
      if (!badgepet) return 0;
      if (str[0..2] == "say") {
        badgepet->psay(str[4..strlen(str)]);
        return 1;
      } else if (str[0..4] == "emote") {
        badgepet->pemote(str[6..strlen(str)]);
        return 1;
      } else if (str[0..3] == "tell") {
        badgepet->ptell(str[5..strlen(str)]);
        return 1;
      } else {
        badgepet->other(str);
        return 1;
      }
      break;
  }
}
