
#define me this_player()
#define FIELDS ({ "alchemy", "alteration", "astrology", "conjuration",           "demonology", "enchantment", "necromancy" })
inherit	"room/room";
inherit "players/bastion/guild/guildroom";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Registrar's Office";
  long_desc = 
   "This is the registrar's office. You may register for classes here.\n";
  dest_dir = ({"/players/bastion/guild/room/admin2", "northeast"});
  }
}

init(arg) {
  add_action("register", "register");
  ::init(arg);
}

register(area) {
  object form;
  if(!area) {
    notify_fail("The registrar says: What department do you wish to " +
     "register in?\n");
    return 0;
  }
  area=lower_case(area);
  if(member_array(area, FIELDS)==-1) {
    write(format("The registrar says: I don't know where you think you are, " +
     "but we don't offer instruction in " + area + " here.\n"));
    return 1;
  }
  if(!present("bursar's receipt", me)) {
    write(format("The registrar says: You'll have to take this form and see " +
     "the bursar. Pay your tuition there.\n"));
    form=clone_object("obj/treasure");
    form->set_id("registration form");
    form->set_alias("form");
    form->set_short("A registration form");
    form->set_long("Perhaps you should read it.\n");
    form->set_read("You notice a red box box labelled \"tuition paid\". It " +
     "\nis empty.\n");
    move_object(form, me);
    return 1;
  }
  if(!present("registration form", me) || !present("bursar's receipt", me)) {
    write(format("The registrar says: I need to see your validated " +
     "registration form along with your receipt.\n"));
    return 1;
  }
  write("The registrar says: Everything appears to be in order.\n");
  write("She files your receipt and completes your registration form.\n");
  destruct(present("receipt", me));
  form=present("registration form", me);
  form->set_id("validated registration form");
  form->set_short("A validated registration form");
  form->set_read("It says you are registered in " + area + ".\n");
  form->set_info(area);
  return 1;
}
