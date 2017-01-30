	/* pom-poms */

inherit "/obj/treasure";

reset(arg)  {
     set_id("pom-poms");
     set_alias("pom");
     set_short("a bright set of pom-poms");
     set_weight(1);
     set_value(1);
     set_long("A pair of pom-poms the likes of which \n"+
              "cheerleaders through out the ages have \n"+
              "used to encourage their teams to victory.\n"+
              "You can 'shake' them to motivate others. \n");

}

void init() {
  ::init();
add_action("shake","shake");
 }

shake() {
    write("You shake the pom-poms and scream encouragingly.\n");
    say(this_player()->query_name()+" shakes their pom-poms and screams encouragement.\n");
    return 1;
        }




