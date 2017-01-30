#include <ansi.h>
#include <security.h>

#define LOOT_ATTRIB "fr0stg@rd"

inherit "/obj/monster";

void generate_monster();

string loot_short;
string loot_long;
int    loot_value;
int    loot_weight;
string death_msg;

void reset(status arg)
{
  ::reset(arg);

  if(arg) return;

  generate_monster();
}


void generate_monster()
{
  set_race("animal");
  set_al(0);
  set_heal(5, 10);
  set_gender(random(2) ? "male" : "female");
  set_multi_cast(1);
  set_wander(1);
  set_wander_interval(60);
  set_wander_realm("frostgard");
  set_dead_ob(this_object());

  set_armor_params("other|ice", 0, 50, "do_special");
  set_armor_params("other|fire", 0, -10, "do_special");

  switch(random(1))
  {
    case 0:
      set_name(YEL+"Wooly Mammoth"+NORM);
      set_alias("wooly mammoth");
      set_alt_name("mammoth");
      set_short(query_name());
      set_long("\
About the height of an elephant, but heavier. The mammoth is about\n\
13' tall.  It has a thick, shaggy layer of hair over 3 feet long.\n\
The hair is greasy from the sebaceous glands leaking fatty \"sweat\"\n\
into it. It is supported by four massive legs holding its wide\n\
form up. A high, knob-like head and a shoulder hump carry more fatty\n\
deposits. A long trunk protrudes from the center of its head,\n\
wrapping down across its body. A stubby tail exits from its rear\n\
end.\n");
      set_level(20);
      set_wc(25+random(10));
      set_ac(15+random(4));
      set_hp(400+random(200));
      set_chat_chance(5);
      load_chat("The "+name+" scratches itself with its trunk.\n");
      load_chat("The "+name+" trumpets loudly with its trunk!\n");
      load_chat("The "+name+" chomps on some grass.\n");
      load_chat("The "+name+" bellows excitedly!\n");
      set_a_chat_chance(5);
      load_chat("The "+name+" TRUMPETS loudly!\n");
      load_chat("The "+name+" makes a strange, roaring sound!\n");
      load_chat("The "+name+" walks backward a few steps.\n");
      load_chat("The "+name+" chomps at you!\n");
      add_spell("trunk grab",
        "\n#MN# swiftly swings #MP# trunk around you, and HURLS you\n"+
        "into the air! You land with a hard *plop*\n\n",
        "\n#MN# swiftly swings #MP# trunk around #TN#, and HURLS #TO#\n"+
        "into the air! #TN# lands with a hard *plop*\n\n",
        25, 50, 0, 5 );
      set_message_hit(({
        HIR+"DEVASTATED"+NORM, "'s body with a massive trunk blow",
        RED+"ravaged"+NORM, " with a heavy charge",
        BOLD+"trampled"+NORM, " repeatedly",
        "struck", " hard with "+possessive(this_object())+" trunk",
        "charged at", ", knocking down its opponent",
        "bellowed at", ", trying to run into its attacker",
        "grazed", " with a trunk swing",
      }));

     loot_id="mammoth trunk";
     loot_alias="trunk";
     loot_short="a mammoth trunk";
     loot_long="\
The massive, 7 foot long trunk of a wooly mammoth. It is moist and\n\
smells awful.\n";
     loot_value = hit_point * 10;
     loot_weight = 4;
     death_msg="\n\n\tThe mammoth trumpets loudly as it dies!\n\n";
    break;
  }
}

status monster_died(){
  object loot;

  tell_room(environment(), death_msg);

  loot=clone_object("/obj/treasure");
  loot->set_id(loot_id);
  loot->set_alias(loot_id);
  loot->set_short(loot_short);
  loot->set_long(loot_long);
  loot->set_weight(loot_weight);
  loot->set_value(loot_value);

  add_attribute(LOOT_ATTRIB, loot);

  move_object(loot, environment());

  return 0;
}