inherit "/obj/monster";
object ob;

reset(arg) {
ob = clone_object("/players/saber/closed/bards/bardsword2.c");
move_object(ob,this_object());
init_command("wield bardsword");
  no_clean=1;
   ::reset(arg);
if (!arg){
     set_name("bardguard");
     set_short("A large Guard wearing Bardic colors");
     set_alt_name("guard");
     set_alias("brian");
     set_race( "human");
     set_long("Brian of the West Wall is a tall man with flowing black hair and dark\n"+
       "eyes.  He is dressed in Bardic blue and black, and wields a Bardsword.\n"+
       "Brian carries CHILDRENS PASSES, which will grant kids enterance to the\n"+
       "guild proper.  To get a pass, type <pass>.\n");
     set_gender("male");
     set_level(19);
     set_ac(17);
     set_wc(30);
     set_hp(575);
     set_al(900);
     set_aggressive(0);
set_chance(10);
   set_spell_dam(random(40));
     set_spell_mess1("\nBrian punches his foe in the solax plex.\n");
     set_spell_mess2("\nBrian punches you in the solar plex!\n"+
       "Ouch\nOuch\Ouch\n");

set_object(this_object());
   set_function("hi_there");
   set_type("arrives");
   set_match("");
   }

}
notify(str)  {
  say(str);
}

hi_there(str) {
string who;
if(sscanf(str, "%s arrives.", who) == 1)  {
  notify("Brian of the West Wall nods at "+who+".\n");
}  }

init()  {
  ::init();
   add_action("pass","pass");
   add_action("north","north");
   add_action("up","up");
        }

north()  {
if(!present("instrument",this_player()))  {
  say("Brian steps in front of "+this_player()->query_name()+".\n"+
  "Brian says \"\I'm sorry, but only Bards may pass.\"\n");
  return 1;
        }
say("Brian steps aside to let "+this_player()->query_name()+" pass into the Bardic Guild.\n");
        }

up()  {
if(!present("coat",this_player()))  {
say("Brian says \"\You must be a member of the Alliance to go up\"\.\n");
  return 1;
        }
say("Brian bows to "+this_player()->query_name()+" as "+this_player()->query_pronoun()+" climbs the stairs.\n");
        }

pass(str)  {
object kid;
  if(!str)  { write("Give a pass to what kid?\n");
   return 1;        }
  if(!find_living(str))  { return 1; }
  kid = find_living(str);
  if(kid->is_pet())  {
  say("Brian hands "+capitalize(str)+" something.\n");
  ob = clone_object("/players/saber/closed/bards/bard_mark.c");
  move_object(ob,kid);
  return 1;
        }
  write(capitalize(str)+" is not a kid!\n");
  return 1;
        }

