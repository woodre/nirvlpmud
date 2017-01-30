#define tp this_player()
#define tpname this_player()->query_real_name()
#define throwout_room "/room/church"
#define owner "pathfinder"
 
inherit "room/room";
 
int shields;
 
 
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Pf's Workroom";
     long_desc = "You notice an organized mess as you enter Pathfinder's\n"+
                 "Workroom, he has piles of papers laying everywhere,\n"+
                 "serving some purpose unknown to you.\n";
  dest_dir = ({
    "room/church", "church",
    "players/pathfinder/detroit/rooms/entrance", "castle",
    "players/pathfinder/closed/shadow/rooms/meeting", "guild",
    "room/adv_inner", "adv",
             });
  items = ({
  "workroom","It hasn't been crafted into much yet, but its getting done...",
  "papers", "Various papers scattered around the room, mostly in shorthand.",
} );
}
}
 
 init() {
 
  object me;
 
  ::init();
     add_action("go_castle",       "castle");
    add_action("go_qs_wr", "qs");
    add_action("toggle_shield",     "shields");
    add_action("church", "church");
    add_action("post","post");
    add_action("advinner","advinner");
    if(shields) {
      if (tpname != owner) {
        write("You tug and tug but the door is too well sealed for you\n"+
            "to open.  Its best to try back at a later time.\n");
        move_object(tp,throwout_room);
        if(me=find_player(owner))
         tell_object(me,capitalize(tpname)+" tried to break in.\n");
        }
      }
}

go_qs_wr() {
  call_other(this_player(),"move_player","qs#players/quicksilver/workroom");
  return 1;
}

church() {
  call_other(this_player(),"move_player","church#room/church");
  return 1;
}
advinner() {
  call_other(this_player(),"move_player","adv_inner#room/adv_inner");
  return 1;
}
post() {
  call_other(this_player(),"move_player","post#room/post");
  return 1;
}
go_castle() {
  call_other(this_player(),"move_player","castle#room/forest5");
  return 1;
  }
 
toggle_shield(str) {
  if (str == "on") shields = 1;
  else if (str == "off") shields = 0;
  else if (str == "stat")
    if (shields) write ("The shields are up.\n");
    else write("The shields are down.\n");
    else write("The syntax is: shields <on|off|stat>\n");
  return 1;
}
