/*
  staff_of_striking.c
*/

inherit "obj/weapon";

reset(arg){
  if(arg) return;
  ::reset(arg);

  set_name("Staff of striking");
  set_alt_name("staff");
  set_alias("staff");
  set_short("A staff.:");
  set_long("This is a mysterious, glowing, staff.\n");
  set_class(16);
  set_weight(3);
  set_value(7000);
  set_hit_func(this_object());
}

set_save_flag() { save_flag = 1; }
query_save_flag() { return save_flag; }

weapon_hit(attacker){
  int i;
  if (random(100) > 75) {
    command("unwield staff of striking", this_player());
    i = random(100);
    if (i <= 10){
      this_object()->set_class(8);
      this_object()->set_short("A puny dagger.:");
      say(capitalize(this_player()->query_name())+
          "'s Staff of Striking flahes brightly.\n"+
          "It becomes a puny dagger.\n\n");
      write("The Staff of Striking glows brightly!\n"+
            "You now wield a puny dagger.\n");
    }
    if (i > 10 && i <= 30) {
      this_object()->set_class(13);
      this_object()->set_short("A hand axe.:");
      say(capitalize(this_player()->query_name())+
          "'s Staff of Striking flahes brightly.\n"+
          "It becomes a hand axe.\n\n");
      write("The Staff of Striking glows brightly!\n"+
            "You now wield a hand axe.\n");
    }
    if (i > 30 && i <= 70) {
      this_object()->set_class(17);
      this_object()->set_short("A fine longsword.:");
      say(capitalize(this_player()->query_name())+
          "'s Staff of Striking flahes brightly.\n"+
          "It becomes a fine longsword.\n\n");
      write("The Staff of Striking glows brightly!\n"+
            "You now wield a fine longsword.\n");
    }
    if (i > 70 && i <= 95) {
      this_object()->set_class(20);
      this_object()->set_short("A superb halberd.:");
      say(capitalize(this_player()->query_name())+
          "'s Staff of Striking flahes brightly.\n"+
          "It becomes a superb halberd!\n\n");
      write("The Staff of Striking glows brightly!\n"+
            "You now wield a superb halberd!\n");
    }
    if (i > 95) {
      this_object()->set_class(30);
      this_object()->set_short("A glowing longsword.:");
      say(capitalize(this_player()->query_name())+
          "'s Staff of Striking flahes brightly.\n"+
          "It becomes a glowing longsword!\n\n");
      write("The Staff of Striking glows brightly!\n");
      write("A glowing longsword has appeared!\n");
    }
    command("wield staff of striking", this_player());
    return;
  }
}

id(str) { return str=="staff" || str=="staff of striking"; }
