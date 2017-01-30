#include "/players/mythos/closed/ansi.h"
#define tp this_player()->query_real_name()
inherit "room/room";
string p;
reset(arg) {
  if(!arg) {
  set_light(1);
    short_desc = "Pet Shop";
    long_desc =
    "You have entered the resident pet shop.\n"+
    "Understand that these pets are "+BOLD+"NOT"+NORM+" for combat.\n"+
    "There is a sign telling what is there to purchase.\n";
  items = ({
    "north","You see the road going through the village",
    "sign","\tThe Following may be purchased:\n\n\t\tPet Protector (1k)\n"+
           "\t\tRed Dragon (200)\n\t\tSaber-tooth Tiger (150)\n"+
           "\t\tGriffon (100)\n\t\tNightmare (100)\n"
           "\t\tGiant Scorpion (100)\n\t\tUnicorn (100)\n"+
           "\t\tPanther (50)\n\t\tDire Wolf (50)\n"+
           "\t\tWar Elephant (50)\n\t\tGiant Bat (50)\n",
  });

  dest_dir = ({
    "/players/mythos/aroom/vil2.c","north",
  });
} }

init() {
  ::init();
  add_action("buy","buy");
}

buy(str){
object ob;
if(!str) {write("What do you wish to buy?\n"); return 1;}
    if(str == "pet protector" || str == "protector") {
      if(this_player()->query_money() < 1000) {
        write("You do not have enough to purchase a pet protector!\n");
      return 1; }
     else {
        write("On what pet?  pet name: ");
        input_to("name",0);
          return 1;}
        return 1;}
     if(str == "red dragon" || str =="dragon") {
     if(this_player()->query_money() < 200) {
        write("You do not have enough to purchase a red dragon!\n");
      return 1; }
      else {
        ob=clone_object("/players/mythos/amisc/pet.c");
        ob->set_short(RED+"Red Dragon"+NORM);
        ob->set_owner(tp);
        ob->set_alias("dragon");
        ob->set_follow(1);
        ob->set_fly(1);
        ob->set_msg("flies");
        ob->set_mount(0);
        ob->set_noise(1);
        ob->set_sound1("The dragon glares at everyone.\n");
        ob->set_sound2("The dragon ROARS!\n");
        ob->set_sound3("The dragon flexes its wings.\n");
        ob->set_sound4("Smoke wafts from the dragon's jaws.\n");
        ob->set_send1("flaps its wings and flies off to give");
        ob->set_send2("flies in and tosses");
        move_object(ob,this_object());
        write("You have purchased a red dragon.\nType pethelp for commands\n");
        call_other(this_player(),"add_money",-200);
        return 1;}
        return 1;}
        if(str == "saber-tooth tiger" || str =="tiger" || str=="saber tooth tiger" ||
           str=="saber tooth" || str=="saber-tooth") {
     if(this_player()->query_money() < 150) {
        write("You do not have enough to purchase a saber-tooth tiger!\n");
      return 1; }
      else {
        ob=clone_object("/players/mythos/amisc/pet.c");
        ob->set_short(HIB+"Saber-Tooth Tiger"+NORM);
        ob->set_owner(tp);
        ob->set_alias("tiger");
        ob->set_follow(1);
        ob->set_fly(0);
        ob->set_msg("runs");
        ob->set_mount(0);
        ob->set_noise(1);
        ob->set_sound1("The saber tooth growls.\n");
        ob->set_sound2("The tiger paces the area.\n");
        ob->set_sound3("The tiger sits and watches everything.\n");
        ob->set_sound4("The Saber-Tooth Tiger SCREAMS!\n");
        ob->set_send1("growls and pounces off to hand");
        ob->set_send2("pounces in and hands");
        move_object(ob,this_object());
        write("You have purchased a saber-tooth tiger.\nType pethelp for commands\n");
        call_other(this_player(),"add_money",-150);
        return 1;}
        return 1;}
        if(str == "griffon") {
     if(this_player()->query_money() < 100) {
        write("You do not have enough to purchase a griffon!\n");
      return 1; }
      else {
        ob=clone_object("/players/mythos/amisc/pet.c");
        ob->set_short(BLU+"Griffon"+NORM);
        ob->set_owner(tp);
        ob->set_alias("griffon");
        ob->set_follow(1);
        ob->set_fly(1);
        ob->set_msg("soars");
        ob->set_mount(0);
        ob->set_noise(1);
        ob->set_sound1("The griffon soars above.\n");
        ob->set_sound2("The griffon flaps its wings.\n");
        ob->set_sound3("The griffon lets out a ROAR!\n");
        ob->set_sound4("The griffon stares at you.\n");
        ob->set_send1("soars off to give");
        ob->set_send2("soars in and gives");
        move_object(ob,this_object());
        write("You have purchased a griffon.\nType pethelp for commands\n");
        call_other(this_player(),"add_money",-100);
        return 1;}
        return 1;}
        if(str == "nightmare") {
     if(this_player()->query_money() < 100) {
        write("You do not have enough to purchase a nightmare!\n");
      return 1; }
      else {
        ob=clone_object("/players/mythos/amisc/pet.c");
        ob->set_short(BOLD+"Nightmare"+NORM);
        ob->set_owner(tp);
        ob->set_alias("nightmare");
        ob->set_follow(1);
        ob->set_fly(1);
        ob->set_msg("gallops");
        ob->set_mount(0);
        ob->set_noise(1);
        ob->set_sound1("The Nightmare tosses its head.\n");
        ob->set_sound2("The Nightmare glares at you with eyes of "+RED+"flame"+NORM+"\n");
        ob->set_sound3("The Nightmare snorts.\n");
        ob->set_sound4("Flame shoots out from the Nightmare's nostrils.\n");
        ob->set_send1("neighs and gallops off to hand");
        ob->set_send2("gallops in, with hooves smoking, and hands");
        move_object(ob,this_object());
        write("You have purchased a nightmare.\nType pethelp for commands\n");
        call_other(this_player(),"add_money",-100);
        return 1;}
        return 1;}
        if(str == "scorpion") {
     if(this_player()->query_money() < 100) {
        write("You do not have enough to purchase a scorpion!\n");
      return 1; }
      else {
        ob=clone_object("/players/mythos/amisc/pet.c");
        ob->set_short(YEL+"Giant Scorpion"+NORM);
        ob->set_owner(tp);
        ob->set_alias("scorpion");
        ob->set_follow(1);
        ob->set_fly(0);
        ob->set_msg("scurries");
        ob->set_mount(0);
        ob->set_noise(1);
        ob->set_sound1("The scorpion chitters...\n");
        ob->set_sound2("The scorpion curls and uncurls its tail.\n");
        ob->set_sound3("The scorpion snaps its claws.\n");
        ob->set_sound4("Beady eyes stare at you.\n");
        ob->set_send1("scurries off to give");
        ob->set_send2("scurries in and gives");
        move_object(ob,this_object());
        write("You have purchased a scorpion.\nType pethelp for commands\n");
        call_other(this_player(),"add_money",-100);
        return 1;}
        return 1;}
        if(str == "unicorn") {
     if(this_player()->query_money() < 100) {
        write("You do not have enough to purchase a unicorn!\n");
      return 1; }
      else {
        ob=clone_object("/players/mythos/amisc/pet.c");
        ob->set_short(CYN+"Unicorn"+NORM);
        ob->set_owner(tp);
        ob->set_alias("unicorn");
        ob->set_follow(1);
        ob->set_fly(0);
        ob->set_msg("gallops");
        ob->set_mount(0);
        ob->set_noise(1);
        ob->set_sound1("The Unicorn stamps its hoof.\n");
        ob->set_sound2("The wind blows...\n");
        ob->set_sound3("The Unicorn snorts.\n");
        ob->set_sound4("The Unicorn neighs.\n");
        ob->set_send1("tosses its head and gallops off");
        ob->set_send2("gallops in, light reflecting off its horn, and hands");
        move_object(ob,this_object());
        write("You have purchased a unicorn.\nType pethelp for commands\n");
        call_other(this_player(),"add_money",-100);
        return 1;}
        return 1;}
        if(str == "panther") {
     if(this_player()->query_money() < 50) {
        write("You do not have enough to purchase a panther!\n");
      return 1; }
      else {
        ob=clone_object("/players/mythos/amisc/pet.c");
        ob->set_short(BOLD+"Panther"+NORM);
        ob->set_owner(tp);
        ob->set_alias("panther");
        ob->set_follow(1);
        ob->set_fly(0);
        ob->set_msg("softly walks");
        ob->set_mount(0);
        ob->set_noise(1);
        ob->set_sound1("The Panther paces the area.\n");
        ob->set_sound2("GGGGRRRRRRRrrrrrrrr\n");
        ob->set_sound3("The Panther vanishes into the shadows.\n");
        ob->set_sound4("The Panther glares at everyone.\n");
        ob->set_send1("slinks off to hand");
        ob->set_send2("slinks in from the shadows and hands");
        move_object(ob,this_object());
        write("You have purchased a panther.\nType pethelp for commands\n");
        call_other(this_player(),"add_money",-50);
        return 1;}
        return 1;}
        if(str == "dire wolf" || str == "wolf") {
     if(this_player()->query_money() < 50) {
        write("You do not have enough to purchase a dire wolf!\n");
      return 1; }
      else {
        ob=clone_object("/players/mythos/amisc/pet.c");
        ob->set_short(BOLD+"Dire Wolf"+NORM);
        ob->set_owner(tp);
        ob->set_alias("wolf");
        ob->set_follow(1);
        ob->set_fly(0);
        ob->set_msg("runs");
        ob->set_mount(0);
        ob->set_noise(1);
        ob->set_sound1("The wolf howls.\n");
        ob->set_sound2("The wolf growls.\n");
        ob->set_sound3("Eyes of "+BLU+"ICE"+NORM+" stare at you.\n");
        ob->set_sound4("The wolf paces the area.\n");
        ob->set_send1("slinks off to give");
        ob->set_send2("appears from the shadows and gives");
        move_object(ob,this_object());
        write("You have purchased a die wolf.\nType pethelp for commands\n");
        call_other(this_player(),"add_money",-50);
        return 1;}
        return 1;}
        if(str == "war elephant" || str == "elephant") {
     if(this_player()->query_money() < 50) {
        write("You do not have enough to purchase a war elephant!\n");
      return 1; }
      else {
        ob=clone_object("/players/mythos/amisc/pet.c");
        ob->set_short("War Elephant");
        ob->set_owner(tp);
        ob->set_alias("elephant");
        ob->set_follow(1);
        ob->set_fly(0);
        ob->set_msg("thunders");
        ob->set_mount(0);
        ob->set_noise(1);
        ob->set_sound1("The elephant TRUMPETS!\n");
        ob->set_sound2("The elephant twitches its little tail.\n");
        ob->set_sound3("The elephant moves its trunk around- touching random objects.\n");
        ob->set_sound4("The ground shakes...\n");
        ob->set_send1("trumpets and thunders off to hand");
        ob->set_send2(BOLD+"thunders"+NORM+" in and hands");
        move_object(ob,this_object());
        write("You have purchased a war elephant.\nType pethelp for commands\n");
        call_other(this_player(),"add_money",-50);
        return 1;}
        return 1;}
        if(str == "bat") {
     if(this_player()->query_money() < 50) {
        write("You do not have enough to purchase a giant bat!\n");
      return 1; }
      else {
        ob=clone_object("/players/mythos/amisc/pet.c");
        ob->set_short(MAG+"Giant Bat"+NORM);
        ob->set_owner(tp);
        ob->set_alias("bat");
        ob->set_follow(1);
        ob->set_fly(1);
        ob->set_msg("glides");
        ob->set_mount(0);
        ob->set_noise(1);
        ob->set_sound1("The Giant Bat glides overhead.\n");
        ob->set_sound2("The bat flaps its wings.\n");
        ob->set_sound3("The bat does a quick turn in the air.\n");
        ob->set_sound4("Ssssssssssss\n");
        ob->set_send1("flaps its wings and soars off to");
        ob->set_send2("glides in and tosses");
        move_object(ob,this_object());
        write("You have purchased a giant bat.\nType pethelp for commands\n");
        call_other(this_player(),"add_money",-50);
        return 1;}
        return 1;}
return 1;}

name(p) {
  if(!present(p)) {write(capitalize(p)+" is not here!\n"); return 1;}
    write("You purchase a pet protector for "+capitalize(p)+".\n");
    say(capitalize(tp)+" purchases a pet protector.\n");
      call_other(this_player(),"add_money",-1000);
      move_object(clone_object("/players/mythos/amisc/petcare.c"),find_living(lower_case(p)));
      return 1;}
