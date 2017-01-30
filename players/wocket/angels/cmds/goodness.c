#include "/players/wocket/closed/ansi.h"

goodness(){
    this_player()->add_spell_point(-30);
    this_player()->add_alignment(1000+random(500));
    this_player()->set_al_title("Angelic");
    write("A silver light shines down upon you.\nYour heart is filled with goodness.\n");
    say("A silver light shines down upon "+this_player()->query_name()+".\n");
    return 1;
}
