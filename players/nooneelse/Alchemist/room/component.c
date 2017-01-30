/*
  alchemist_component.c
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

inherit "room/room";
inherit "/players/nooneelse/Alchemist/room/rooms.c";

/*
--- 5
alight          fire fly, flint                                 5, 25            =  30
assess          glass bead                                      25               =  25
refine corpse   bat fur                                         20               =  20
set home here   parchment, pencil                               10, 10           =  20
stone skin      granite, flint                                  100, 25          = 125
--- 8
cure disease    moldy bread                                     75               =  75
detect disease  green mold                                      20               =  20
flash           sulphur, fire fly                               75, 5            =  80
home            spider web                                      100              = 100
ice             ice cube, powdered iron                         75, 100          = 175
--- 12

##############

acid            arrow, adder's venom                            10, 10           =  20
grease          oil, pork rind                                  20, 75           =  95
air elemental   fan, feather                                    50, 50           = 100
earth elemental dust, chalk                                     50, 75           = 125
fire elemental  fire fly, bell                                  5, 50            =  55
peace dust      olive branch                                    60               =  60
haze            crystal bead, oil                               250, 20          = 270
--- 15
transport       arrow, mercury                                  10, 100          = 110
charity         arrow, mercury                                  10, 100          = 110
fear            sulphur, flint                                  75, 25           = 100
poison          arrow, adder's venom, vial of blood             10, 10, 350      = 370
summon          arrow, mercury, iron rod                        10, 100, 75      = 185
transfer        arrow, mercury, iron rod, crystal bead          10, 100, 75, 250 = 435
zombie corpse   moldy bread, mercury, iron rod, vampire blood   75, 100, 75, 500 = 750
--- 19
aid             fire fly, bell                                  5, 50            =  55
asell           arrow, mercury, iron rod, crystal bead          10, 100, 75, 250 = 435
hail            ice cube, iron rod                              75, 75           = 150
repair          iron rod, diamond                               75, 200          = 275
sharpen         flint, iron rod, diamond                        25, 75, 200      = 300
summon vampire  arrow, mercury, iron rod, vampire blood         10, 100, 75, 500 = 685
*/

/*
component         # used   levels used             mage spell cost

adder's venom        2     12x1, 15x1                    10
arrow                7     12x1, 15x4, 19x2              10
bell                 2     12x1, 19x1                    50
chalk                1     12x1                          75
crystal bead         3     12x1, 15x1, 19x1             250
diamond              2     19x2                         200
dust                 1     12x1                          50
fan                  1     12x1                          50
feather              1     12x1                          50
fire fly             4     5x1, 8x1, 12x1, 19x1           5
flint                4     5x2, 15x1, 19x1               25
glass bead           1     5x1                           25
granite              1     5x1                          100
green mold           1     8x1                           20
ice cube             2     8x1, 19x1                     75
iron rod             8     15x3, 19x5                    75
mercury              6     15x4, 19x2                   100
moldy bread          2     8x1, 15x1                     75
oil                  2     12x2                          20
olive branch         1     12x1                          60
parchment            1     5x1                           10
pencil               1     5x1                           10
pork rind            1     12x1                          75
powdered iron        2     5x1, 8x1                     100
spider web           1     8x1                          100
sulphur              2     8x1, 15x1                     75
vampire blood        2     15x1, 19x1                   500
vial of blood        1     15x1                         350
*/

init() {
  ::init();

  add_action("list_items", "list");
  add_action("buy_item",   "buy");
  check_membership(this_player());
}

list_items(str) {
  if (str) return;
  write("Currently available components:\n\n"+
        "  adder's venom     10     arrow             10     bell              50\n"+
        "  chalk             75     crystal bead     250     diamond          200\n"+
        "  dust              50     fan               50     feather           50\n"+
        "  fire fly           5     flint             25     granite          100\n"+
        "  ice cube          75     iron rod          75     mercury          100\n"+
        "  moldy bread       75     oil               20     olive branch      60\n"+
        "  parchment         10     pencil            10     pork rind         75\n"+
        "  powdered iron    100     sulphur           75     vampire blood    500\n"+
        "  vial of blood    350\n\n");
  return 1;
}


buy_item(str) {
  string item_name;
  int nbr_items, item_cost, total;
  object pouch_obj;

  if (!str) return;
  if (sscanf(str, "%d %s", nbr_items, item_name)!=2) {
    write("Buy how many of what?\n");
    return 1;
  }
  if (nbr_items<=0) nbr_items = 1;
  pouch_obj = present("Alchemist Pouch", this_player());

  switch (item_name) {
    case "adder's venom": item_cost=10; break;
    case "arrow": item_cost=10; break;
    case "bell": item_cost=50; break;
    case "chalk": item_cost=75; break;
    case "crystal bead": item_cost=250; break;
    case "diamond": item_cost=200; break;
    case "dust": item_cost=50; break;
    case "fan": item_cost=50; break;
    case "feather": item_cost=50; break;
    case "fire fly": item_cost=5; break;
    case "flint": item_cost=25; break;
    case "granite": item_cost=100; break;
    case "ice cube": item_cost=75; break;
    case "iron rod": item_cost=75; break;
    case "mercury": item_cost=100; break;
    case "moldy bread": item_cost=75; break;
    case "oil": item_cost=20; break;
    case "olive branch": item_cost=60; break;
    case "parchment": item_cost=10; break;
    case "pencil": item_cost=10; break;
    case "pork rind": item_cost=75; break;
    case "powdered iron": item_cost=100; break;
    case "sulphur": item_cost=75; break;
    case "vampire blood": item_cost=500; break;
    case "vial of blood": item_cost=350; break;
  }
  total = item_cost * nbr_items;
  if (this_player()->query_money() < total) {
    write("It would cost you "+total+
          " gold coins, which you don't have.\n");
    return 1;
  }
  this_player()->add_money(- total);
  switch (item_name) {
    case "adder's venom": pouch_obj->add_component("adder's venom", nbr_items); break;
    case "arrow": pouch_obj->add_component("arrow", nbr_items); break;
    case "bell": pouch_obj->add_component("bell", nbr_items); break;
    case "chalk": pouch_obj->add_component("chalk", nbr_items); break;
    case "crystal bead": pouch_obj->add_component("crystal bead", nbr_items); break;
    case "diamond": pouch_obj->add_component("diamond", nbr_items); break;
    case "dust": pouch_obj->add_component("dust", nbr_items); break;
    case "fan": pouch_obj->add_component("fan", nbr_items); break;
    case "feather": pouch_obj->add_component("feather", nbr_items); break;
    case "fire fly": pouch_obj->add_component("fire fly", nbr_items); break;
    case "flint": pouch_obj->add_component("flint", nbr_items); break;
    case "granite": pouch_obj->add_component("granite", nbr_items); break;
    case "ice cube": pouch_obj->add_component("ice cube", nbr_items); break;
    case "iron rod": pouch_obj->add_component("iron rod", nbr_items); break;
    case "mercury": pouch_obj->add_component("mercury", nbr_items); break;
    case "moldy bread": pouch_obj->add_component("moldy bread", nbr_items); break;
    case "oil": pouch_obj->add_component("oil", nbr_items); break;
    case "olive branch": pouch_obj->add_component("olive branch", nbr_items); break;
    case "parchment": pouch_obj->add_component("parchment", nbr_items); break;
    case "pencil": pouch_obj->add_component("pencil", nbr_items); break;
    case "pork rind": pouch_obj->add_component("pork rind", nbr_items); break;
    case "powdered iron": pouch_obj->add_component("powdered iron", nbr_items); break;
    case "sulphur": pouch_obj->add_component("sulphur", nbr_items); break;
    case "vampire blood": pouch_obj->add_component("vampire blood", nbr_items); break;
    case "vial of blood": pouch_obj->add_component("vial of blood", nbr_items); break;
  }
  write("OK.\n");
  return 1;
}

reset(arg) {
  if (arg) return;
    
  set_light(1);
  short_desc=("Alchemist Guild's Component Shop");
  no_castle_flag=1;
  long_desc=
    "This is where you purchase the components of your potions,\n"+
    "tonics, oils, ointments, philters, & powders.\n\n"+
    "Type 'list' to see what is available and the price for each.\n"+
    "Type 'buy <#> <what> to purchase a component.\n"+
    "  (Use 'help <skill> to see what components you will nead.)\n"+
    "  (Buy enough for your needs! You don't want to be caught short!)\n\n";
  dest_dir=
    ({
      ALCHEMIST_CENTRAL, "northwest",
    });
}
