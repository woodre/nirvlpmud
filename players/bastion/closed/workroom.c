
int shield, anchor;
object who;

reset(arg) {
     if(!arg)
          set_light(1);
     if(!present("demon")) {
          object demon;
          int shield_was_on;
          if(shield) {
               shield=0;
               shield_was_on=1; }
          demon=clone_object("players/bastion/monster/demon6");
          move_object(demon, this_object());
          tell_room(this_object(), "A demon steps out a sulfurous cloud.\n");
          if(shield_was_on)
               shield=1; 
          }
}

init() {
     add_action("limbo", "limbo");
     add_action("shop", "shop");
     add_action("church", "church");
     add_action("guild", "guild");
     add_action("out", "out");
     add_action("south", "south");
     if(call_other(this_player(), "query_real_name")=="damian" ||
        call_other(this_player(), "query_real_name")=="bastion") {
          add_action("shield_control", "shield");
          add_action("shield_control", "sh");
          add_action("anchor_me", "anchor");
          add_action("anchor_me", "an");
          add_action("quit", "quit");
          add_action("get_stuff", "stuff");
          add_action("get_mail_reader", "post"); }
     else if(shield) {
          string who;
          who=capitalize(call_other(this_player(), "query_real_name"));
          write("You bounce off Bastion's defense shield.\n");
          move_object(this_player(), "room/void");
          tell_room(this_object(), "" + who +
               " just tried to enter the room.\n"); }
}

limbo() {
     write("You enter the drifting plane of limbo...\n");
     this_player()->move_player("X#players/bastion/room/limbo");
     return 1;
}

shop() {
     this_player()->move_player("X#room/shop");
     return 1;
}

church() {
     this_player()->move_player("X#room/church");
     return 1;
}

guild() {
     if (this_player()->query_level() < 20)
          this_player()->move_player("X#room/adv_guild");
     else
          this_player()->move_player("X#room/adv_inner");
     return 1;
}

out() {
     this_player()->move_player("X#players/bastion/isle/nearshore");
     return 1;
}

south() {
     this_player()->move_player("south#players/bastion/isle/wiz/wrkroom");
     return 1;
}

static shield_control(str) {
     if(!str) {
          if(shield) 
               write("The defense shield is activated.\n");
          else  
               write("The defense shield is inactive.\n"); 
          return 1; }
     if(str=="on") {
          shield=1;
          write("Shield activated.\n"); }
     else if(str=="off") {
          shield=0;
          write("Shield deactivated.\n"); }
     return 1;
}


get_stuff() {
     object staff, dagger;
     staff=clone_object("players/bastion/closed/staff");
     dagger=clone_object("players/deathmonger/ASSASSIN/dagger");
     move_object(staff, this_player());
     move_object(dagger, this_player());
     write("Done.\n");
     return 1;
}

get_mail_reader() {
     object reader;
     reader=clone_object("obj/mail_reader");
     move_object(reader, this_player());
     write("Done.\n");
     return 1;
}

short() { return ("Bastion's Little Workroom"); }

long() {
   write(
   "This is Bastion's workroom. Diagrams and charts salvaged from the ruins\n"+
   "of Vision adorn the walls. The walls are panelled mahogany, the carpet\n"+
   "deep red pile. On a desk along the north wall you see stacks of papers\n"+
   "and thesis notes. A bookshelf takes up much of the opposite wall, while\n"+
   "a low table and comfortable chairs sit in one corner. A portal in the \n"+
   "west wall leads to various locations throughout the realm. An archway\n"+
   "of shimmering blue light leads south.\n"+
   "     There are five obvious exits: limbo, shop, church, guild, out.\n");
}

static anchor_me(arg) {
     if(!arg) {
          if(anchor)
               write("Anchor is on.\n");
          else
               write("Anchor is off.\n");
          return 1;
     }
     if(arg=="on") {
          set_heart_beat(1);
          who=this_player();
          write("Anchor on.\n");
          anchor=1;
          return 1;
     }
     if(arg=="off") {
          set_heart_beat(0);
          write("Anchor off.\n");
          anchor=0;
          return 1;
     }
}

static heart_beat() {
     who->destruct_inventory();
     if(!present(who))
          rescue_me();
}

rescue_me() {
     object ob;
     ob=environment(who);
     move_object(who, this_object());
     destruct(ob);
     tell_object(who, "\nYou are magically transfered to the workroom.\n");
     set_heart_beat(1);
}

quit() {
     if(shield || anchor)
          return 1;
}

query_who() { return who; }

realm() { return "NT"; }
