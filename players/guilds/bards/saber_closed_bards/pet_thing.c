#define tp this_player()->query_name()
#define TP this_player()
#define SPELL TP->query_sp()
#define ALI (int) TP->query_alignment()

inherit "obj/treasure";
#include "/players/saber/closed/bards/zpet2.c"

reset(arg)  {
   if (arg) return;
    set_id("circle");
   set_short("A blue circle of power");
   set_alias("circle of power");
    set_long(
    "A circle of blue power floating about six inches off of the floor.\n"+
    "If you stand within it, you can summon an animal companion.\n"+
    "Type: animal <animal type> <animal name> to summon your pet to you.\n"+
    "Type animal_list, animal_list2 and animal_list3 for help.\n");
   set_weight(100);
   set_value(0);
}

init()  {
   add_action("summon_pet","animal");  }

int spell(int cutoff_ali, int min_level, int sp_cost)  {
object TO;
  TO = present("instrument",this_player());
if(ALI<cutoff_ali) { notify_fail("Your soul is not balanced towards the light.\n"); return -1;}
if(SPELL<sp_cost){notify_fail("You don't have enough mana.\n"); return -1;}
return 1;  }
