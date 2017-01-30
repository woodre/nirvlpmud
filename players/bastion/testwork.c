
int shield, anchor;
object who;

reset ( arg ) {
    if ( !arg )
        set_light(1);
    if ( shield ) return;
    move_object(clone_object("players/bastion/monster/demon6"), this_object());
    tell_room(this_object(), "A demon steps out a sulfurous cloud.\n");
}

init () {
    add_action("limbo", "limbo");
    add_action("shop", "shop");
    add_action("church", "church");
    add_action("guild", "guild");
    add_action("out", "out");
    add_action("south", "south");
    if ( this_player() == find_player("bastion") ) {
        add_action("shield_control", "shield", 2);
        add_action("anchor_me", "anchor", 2);
        add_action("inv_cleanser", "clean");
        add_action("set_defenses", "war");
        add_action("quit", "quit");
        add_action("get_staff", "staff");
    }
    else if ( shield ) {
        write("You bounce off Bastion's defense shield.\n");
        move_object(this_player(), "room/void");
        tell_room(this_object(), "" + 
                  capitalize(this_player()->query_real_name()) +
                  " just tried to enter the room.\n");
    }
}

limbo () {
     write("You enter the drifting plane of limbo...\n");
     this_player()->move_player("X#players/bastion/room/limbo");
     return 1;
}

shop () {
     this_player()->move_player("X#room/shop");
     return 1;
}

church () {
     this_player()->move_player("X#room/church");
     return 1;
}

guild () {
     if (this_player()->query_level() < 20)
          this_player()->move_player("X#room/adv_guild");
     else
          this_player()->move_player("X#room/adv_inner");
     return 1;
}

out () {
     this_player()->move_player("X#players/bastion/isle/nearshore");
     return 1;
}

south () {
     this_player()->move_player("south#players/bastion/isle/wiz/wrkroom");
     return 1;
}

valid_command () {
    return this_player() == find_player("bastion");
}

static 
shield_control (str) {
    if ( !valid_command() )
        return 0;
    if ( !str ) {
        write("The defense shield is " + (shield ? "activated" : "inactive") +
              ".\n");
        return 1; 
    }
    if ( str == "on" ) {
        shield = 1;
        write("Shield activated.\n");
        return 1;
    }
    else if ( str == "off" ) {
        shield = 0;
        write("Shield deactivated.\n");
        return 1;
    }
    notify_fail("You can only turn the shield on or off.\n");
    return 0;
}

static
get_staff () {
    if ( !valid_command() )
        return 0;
    move_object(clone_object("players/bastion/closed/staff"), this_player());
    write("Done.\n");
    return 1;
}

short () { return ("Bastion's little workroom"); }

long () {
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

static 
anchor_me (arg) {
    if ( !valid_command() ) 
        return 0;
    if(!arg) {
        write("Anchor is " + (anchor ? "on" : "off") + ".\n");
        return 1;
    }
    if ( arg == "on" ) {
        write("Anchor on.\n");
        anchor = 1;
        return 1;
    }
    if ( arg == "off" ) {
        write("Anchor off.\n");
        anchor = 0;
        return 1;
    }
    notify_fail("You can only turn the anchor on or off.\n");
    return 0;
}

static
inv_cleanser (arg) {
    if ( !valid_command() ) 
        return 0;
    if ( !arg ) {
        write("Cleanser is " + (who ? "on" : "off") + ".\n");
        return 1;
    }
    if ( arg == "on" ) {
        write("Inventory cleanser on.\n");
        set_heart_beat(1);
        who = this_player();
        return 1;
    }
    if ( arg == "off" ) {
        write("Inventory cleanser off.\n");
        set_heart_beat(0);
        who = 0;
        return 1;
    }
    notify_fail("You can only turn the cleanser on or off.\n");
    return 0;
}

static
set_defenses (arg) {
    if ( !valid_command() )
        return 0;
    if ( arg == "off" ) {
        shield_control("off");
        anchor_me("off");
        inv_cleanser("off");
        return 1;
    }
    shield_control("on");
    anchor_me("on");
    inv_cleanser("on");
    return 1;
}

heart_beat () {
   int i, clone;
   object *inv;

   tell_room(this_object(), "Lub.\n");
   inv = all_inventory(this_object());
   i = sizeof(inv);
   while ( i-- ) {
      if ( interactive(inv[i]) )
         continue;
      efun::destruct(inv[i]);
   }
   inv = all_inventory(who);
   i = sizeof(inv);
   while ( i-- ) {
      if ( sscanf(file_name(inv[i]), "players/bastion/closed/staff#%d",
           clone) == 1 ||
           sscanf(file_name(inv[i]), "closed/wiz_soul#%d", clone) == 1 )
          continue;
      efun::destruct(inv[i]); 
   }
}

quit () {
    if ( shield || anchor )
        return 1;
}

query_who () { return who; }

realm () { return "NT"; }

object X;
/*
exit () {
    if ( anchor ) 
        X = 0;
    else
        X = this_object();
    tell_room(X, capitalize(this_player()->query_real_name()) + 
                 " leaves the room.\n");
    X = 0;
}
*/
