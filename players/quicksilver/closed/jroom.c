#include "/players/quicksilver/666/include/std.h"
#include "/players/quicksilver/closed/color.h"

inherit ROOM;

int i=0;
string *allowed;

static int burning;
static string *tempallow;

no_clean() { return 1; }

aura_status() {
   switch(i) {
      case 1 : return BOLD+BLA+"A faint grey aura covers the cavern's entrance."+NOSTYLE; break;
      case 2 : return RED+"A faint crimson aura covers the cavern's entrance."+NOSTYLE; break;
      case 3 : return BOLD+WHI+"A brilliant white aura covers the cavern's entrance."+NOSTYLE; break;
   }
}

short() {
  return "The House of Ill Repute";
}

long(str) {
  ::long(str);
  if(i&&!str) write(aura_status(i)+"\n");
}

reset(arg) {
     if(!arg) {
        set_light(1);
        set_long("The House of Ill Repute\n\n"+
        "You enter the room through large double doors only to find when you turn\n"+
        "around they have dissappeared into the wall of bookshelves behind you.\n"+
        "In fact, as you look about the room, you discover that bookshelves cover\n"+
        "every single wall, floor to 12 foot ceiling, and are filled with row\n"+
        "after row of bound leather volumes of many types.\n"+
        "There are two exceptions:  a large stone fireplace takes up the middle of\n"+
        "the far wall, and to your right is a curtained alcove.\n"+
        "Your feet sink into the thick, blood-red carpet.  Matching overstuffed\n"+
        "chairs and couches surround the fireplace in a semi-circle.  The room is\n"+
        "lit only by the fireplace and the many candles placed about the room.");
        tempallow = ({});
        add_item("shelves", "The shelves are made of mahogany, like the furniture.  They are filled to\n"+
                 "bursting with beautiful and interesting books.");
        add_item("books", "The sheer amount of books astounds the eye and the mind.   How could one\n"+
                 "possibly read them all?");
        add_item("fireplace", "The fireplace is made of beautiful gray stone.  Perhaps you could\n"+
                 "'light' it.");
        add_item("alcove", "Behind the thick red curtains is a small alcove that contains a gorgeous\n"+
                 "mahogany four poster bed that is clothed with red satin sheets and a red\n"+
                 "stuffed velvet comforter.  Behind the bed is a gorgeous picture window\n"+
                 "that lends an eerie glow to the alcove.");
        add_item("bed", "The bed looks horribly comfortable and inviting.  Perhaps you could 'lie'\n"+
                 "in it.");
        add_item("window", "The large window takes up the entire back wall of the alcove and depicts\n"+
                 "the lovers, Tristan and Iseult, in a passionate embrace.");
/*restore_object("players/quicksilver/closed/etc/jroom");*/
     }
     ::reset(arg);
     return 1;
}

init() {
  if(!check()) {
     tell_room(this_object(), "The aura flickers brightly and prevents "+capitalize(this_player()->query_real_name())+" from entering the room.\n");
     return;
  }
  add_action("lightfire","light");
  add_action("pull","pull");
  add_action("push","push");
  add_action("lie","lie");
  add_action("leave","leave");
  if(TP->query_real_name()=="quicksilver") {
     add_action("list","access");
     add_action("aura","aura");
     add_action("addex","addexit");
     add_action("clearex","clearexit");
     add_action("delex","delexit");
     add_action("add","addperm");
     add_action("clear","clear");
     add_action("del","delperm");
     add_action("add2","add");
     add_action("del2","del");
     add_action("trans","trans");
  }
  ::init();
}

burn() {
   burning+=random(10)+1;
   if((random(400000)-burning)>1000) {
      switch(random(4)) {
         case 0 : tell_room(TO,"The fire crackles.\n"); break;
         case 1 : tell_room(TO,"The fire pops suddenly.\n"); break;
         case 2 : tell_room(TO,"The walls of the room glow in the firelight.\n"); break;
         case 3 : if(burning<3000)
                     tell_room(TO,"The fire blazes, sending its dancing light through the room.\n");
                  else
                     tell_room(TO,"A log shifts in the fireplace, sending red embers up the chimney.\n"); break;
         case 4 : if(!random(3)) tell_room(TO,"Warmth radiates from the fireplace, giving the room a cozy feeling.\n"); break;
      }
   }
   call_out("burn",(10+(burning*random(5))));
   return 1;
}

lightfire(str) { 
   if((str!="fire")&&(str!="fireplace")) {
      notify_fail("Light what?\n");
      return;
   }
   write("You take a match from the mantle and light the fireplace.\n"+
   "The fire roars to life and casts a warm glow about the room.\n");
   say(capitalize(this_player()->query_name())+" take a match from the mantle and light the fireplace.\n"+
   "The fire roars to life and casts a warm glow about the room.\n");
   burning=0;
   call_out("burn",10);
   return 1;
}

lie(str) { 
   if((str!="on bed")&&(str!="in bed")) {
      notify_fail("Lie on what?\n");
      return;
   }
   write("You sink into the soft bed and realize you never want to 'leave'.\n");
   say(capitalize(this_player()->query_name())+" lies down in the comfortable bed and looks at peace.\n");
   return 1;
}

leave(str) { 
   if(str!="bed") return;
   write("You grudgingly get out of bed and hope you may return once again.\n");
   say(capitalize(this_player()->query_name())+" gets out of the bed with a grunt.\n");
   return 1;
}

pull(str) {
   if(str=="bar") { 
      write("You pull out on a book on the shelf and that section of the shelf begins to\n"+
      "rotate and a fully stocked bar is revealed.\n");
      say(capitalize(this_player()->query_name())+" pulls out on a book on the shelf and that section of the shelf\n"+
      "begins to rotate and a fully stocked bar is revealed.\n");
      add_item("bar", "A fully functional, and very beautiful, wet bar.  You can 'order' several\n"+
      "drinks by number:\n"+
      "   1. A lovely Merlot from France.\n"+
      "   2. A Widmer beer courtesy of the Widmer Brothers in Portland, Oregon.\n"+
      "   3. A Shiner Bock from the Spoetzl Brewery in Shiner, Texas.\n"+
      "   4. A Guinness.\n"+
      "   5. A steaming cup of hot cocoa.");
      if(member_array("humidor", items)==-1) set_long("The House of Ill Repute\n\n"+
      "As you look about the room, you discover that bookshelves cover every inch\n"+
      "of free wall space, floor to 12 foot ceiling, and are filled with row\n"+
      "after row of bound leather volumes of many types.\n"+
      "A large stone fireplace takes up the middle of the far wall, and to your\n"+
      "right is a curtained alcove.  Along the left wall, there is a full bar\n"+
      "manned by Coco the Houseboy.\n"+
      "Your feet sink into the thick, blood-red carpet.  Matching overstuffed\n"+
      "chairs and couches surround the fireplace in a semi-circle.  The room is\n"+
      "lit only by the fireplace and the many candles placed about the room.");
      else set_long("The House of Ill Repute\n\n"+
      "As you look about the room, you discover that bookshelves cover every inch\n"+
      "of free wall space, floor to 12 foot ceiling, and are filled with row\n"+
      "after row of bound leather volumes of many types.\n"+
      "A large stone fireplace takes up the middle of the far wall, and to your\n"+
      "right is a curtained alcove.  Along the left wall, there is a full bar\n"+
      "manned by Coco the Houseboy.\n"+
      "Your feet sink into the thick, blood-red carpet.  Matching overstuffed\n"+
      "chairs and couches surround the fireplace in a semi-circle.  A large\n"+
      "humidor sits in front of the center-most couch, easily accessible from\n"+
      "any of the chairs.  The room is lit only by the fireplace and the many\n"+
      "candles placed about the room.");
      return 1;
   } else if(str=="humidor") { 
      write(
      "You pull out on a book on the shelf and a large humidor rises up from\n"+
      "the floor amidst the chairs.\n");
      say(capitalize(this_player()->query_name())+" pulls out on a book on the shelf and a large humidor rises up\n"+
      "from the floor amidst the chairs.\n");
      add_item("humidor", "The humidor stands about a foot and a half high, with a flat surface for\n"+
      "the convenient placement of drinks.  The drawers inside are well stocked\n"+
      "with Cuban cigars.  Perhaps you would like to 'pick' one?");
      if(member_array("bar", items)!=-1) set_long("The House of Ill Repute\n\n"+
      "As you look about the room, you discover that bookshelves cover every inch\n"+
      "of free wall space, floor to 12 foot ceiling, and are filled with row\n"+
      "after row of bound leather volumes of many types.\n"+
      "A large stone fireplace takes up the middle of the far wall, and to your\n"+
      "right is a curtained alcove.  Along the left wall, there is a full bar\n"+
      "manned by Coco the Houseboy.\n"+
      "Your feet sink into the thick, blood-red carpet.  Matching overstuffed\n"+
      "chairs and couches surround the fireplace in a semi-circle.  A large\n"+
      "humidor sits in front of the center-most couch, easily accessible from\n"+
      "any of the chairs.  The room is lit only by the fireplace and the many\n"+
      "candles placed about the room.");
      else set_long("The House of Ill Repute\n\n"+
      "As you look about the room, you discover that bookshelves cover every inch\n"+
      "of free wall space, floor to 12 foot ceiling, and are filled with row\n"+
      "after row of bound leather volumes of many types.\n"+
      "A large stone fireplace takes up the middle of the far wall, and to your\n"+
      "right is a curtained alcove.\n"+
      "Your feet sink into the thick, blood-red carpet.  Matching overstuffed\n"+
      "chairs and couches surround the fireplace in a semi-circle.  A large\n"+
      "humidor sits in front of the center-most couch, easily accessible from\n"+
      "any of the chairs.  The room is lit only by the fireplace and the many\n"+
      "candles placed about the room.");
      return 1;
   }
}

push(str) {
   if(str=="bar") { 
      if(member_array("bar", items)==-1) return;
      write("You push a button under the bar and it revolves back around.  The\n"+
      "bookcase takes its place once again, leaving no trace of what was once\n"+
      "there.\n");
      say(capitalize(this_player()->query_name())+
      " pushes a button under the bar and it revolves back around.  The\n"+
      "bookcase takes its place once again, leaving no trace of what was once\n"+
      "there.\n");
      del_item("bar");
      if(member_array("humidor", items)!=-1) set_long("The House of Ill Repute\n\n"+
      "As you look about the room, you discover that bookshelves cover every inch\n"+
      "of free wall space, floor to 12 foot ceiling, and are filled with row\n"+
      "after row of bound leather volumes of many types.\n"+
      "A large stone fireplace takes up the middle of the far wall, and to your\n"+
      "right is a curtained alcove.\n"+
      "Your feet sink into the thick, blood-red carpet.  Matching overstuffed\n"+
      "chairs and couches surround the fireplace in a semi-circle.  A large\n"+
      "humidor sits in front of the center-most couch, easily accessible from\n"+
      "any of the chairs.  The room is lit only by the fireplace and the many\n"+
      "candles placed about the room.");
      else set_long("The House of Ill Repute\n\n"+
      "You enter the room through large double doors only to find when you turn\n"+
      "around they have dissappeared into the wall of bookshelves behind you.\n"+
      "In fact, as you look about the room, you discover that bookshelves cover\n"+
      "every single wall, floor to 12 foot ceiling, and are filled with row\n"+
      "after row of bound leather volumes of many types.\n"+
      "There are two exceptions:  a large stone fireplace takes up the middle of\n"+
      "the far wall, and to your right is a curtained alcove.\n"+
      "Your feet sink into the thick, blood-red carpet.  Matching overstuffed\n"+
      "chairs and couches surround the fireplace in a semi-circle.  The room is\n"+
      "lit only by the fireplace and the many candles placed about the room.");
      return 1;
   } else if(str=="humidor") { 
      if(member_array("humidor", items)==-1) return;
      write("You pull out on a book on the shelf and the humidor silently sinks back\n"+
      "into the floor.\n");
      say(capitalize(this_player()->query_name())+" pulls out on a book on the shelf and the humidor sinks\n"+
      "back into the floor.\n");
      del_item("humidor");
      if(member_array("bar", items)!=-1) set_long("The House of Ill Repute\n\n"+
      "As you look about the room, you discover that bookshelves cover every inch\n"+
      "of free wall space, floor to 12 foot ceiling, and are filled with row\n"+
      "after row of bound leather volumes of many types.\n"+
      "A large stone fireplace takes up the middle of the far wall, and to your\n"+
      "right is a curtained alcove.  Along the left wall, there is a full bar\n"+
      "manned by Coco the Houseboy.\n"+
      "Your feet sink into the thick, blood-red carpet.  Matching overstuffed\n"+
      "chairs and couches surround the fireplace in a semi-circle.  The room is\n"+
      "lit only by the fireplace and the many candles placed about the room.");
      else set_long("The House of Ill Repute\n\n"+
        "You enter the room through large double doors only to find when you turn\n"+
        "around they have dissappeared into the wall of bookshelves behind you.\n"+
        "In fact, as you look about the room, you discover that bookshelves cover\n"+
        "every single wall, floor to 12 foot ceiling, and are filled with row\n"+
        "after row of bound leather volumes of many types.\n"+
        "There are two exceptions:  a large stone fireplace takes up the middle of\n"+
        "the far wall, and to your right is a curtained alcove.\n"+
        "Your feet sink into the thick, blood-red carpet.  Matching overstuffed\n"+
        "chairs and couches surround the fireplace in a semi-circle.  The room is\n"+
        "lit only by the fireplace and the many candles placed about the room.");
      return 1;
   }
}

check() {
  if((this_player()->query_real_name()=="quicksilver")||!i) return 1;
  switch(i) {  
     case 2 : if((member_array((this_player()->query_real_name()),allowed)==-1)&&(member_array((this_player()->query_real_name()),tempallow)==-1)) {
                 write("Quicksilver tells you: I am not currently accepting visitors.\n");
                 move_object(this_player(), "room/church");
                 return 0;
              } else {
                 write("You pass through the crimson aura with ease.\n");
                 return 1;
              } break;
  }
}
  
trans(arg) {
  object ob,rm;
  ob=find_player(arg);
  if(!ob) return 0;
  rm=environment(ob);
  tell_object(ob, "Darkness envelops you.  Your environment fades...\nYou arrive elsewhere.\n");
  move_object(ob, this_object());
  tell_room(rm, capitalize(ob->query_name())+" disappears as "+ob->query_pronoun()+" is enveloped in a shroud of darkness.\n");
  write("Ok.\n");
  return 1;
}

aura(str) {
  switch(str) {
     case "off" :	tell_room(this_object(), "The aura fades away.\n");
     			i=0;
     			break; 
     case "grey" :	tell_room(this_object(), "A faint grey aura leaps up at the entryway.\n");
     			i=1;
     			break;
     case "red" :	tell_room(this_object(), "A faint crimson aura leaps up at the entryway.\n");
     			i=2;
     			break; 
     case "white" :	tell_room(this_object(), "A brilliant white aura leaps up at the entryway.\n");
     			i=3;
     			break; 
  } 
  save_object("players/quicksilver/closed/etc/jroom");  
  return 1;
}

add(str) {
  allowed += ({ str });
  write(capitalize(str)+" has been allowed access.\n");
  save_object("players/quicksilver/closed/etc/jroom");  
  return 1;
}

clear(str) {
  switch(str) {
     case "all" :  allowed = ({});  tempallow = ({});
                   write("Both the temporary and perminant access lists have been cleared.\n");
                   save_object("players/quicksilver/closed/etc/jroom");
                   break;  
     case "temp" : tempallow = ({});
                   write("The temporary access list has been cleared.\n");
                   break;  
     case "perm" : allowed = ({});
                   write("The perminant access list has been cleared.\n");
                   save_object("players/quicksilver/closed/etc/jroom");
                   break;
     default:      notify_fail("Clear which list?  usage: clear [all|temp|perm]\n");
                   return 0;
                   break;
  }
  return 1;
}

del(str) {
  if(member_array(str,allowed)==-1) return write(capitalize(str)+" was not on the allowed list.\n");
  allowed -= ({ str });
  write(capitalize(str)+" has been removed from the allowed list.\n");
  save_object("players/quicksilver/closed/etc/jroom");  
  return 1;
}

add2(str) {
  tempallow += ({ str });
  write(capitalize(str)+" has been allowed temporary access.\n");
  return 1;
}

del2(str) {
  if(member_array(str,tempallow)==-1) return write(capitalize(str)+" was not on the allowed list.\n");
  tempallow -= ({ str });
  write(capitalize(str)+" has been removed from the allowed list.\n");
  return 1;
}

clearex() {
  dest_dir = 0;
  write("Exits cleared.\n");
  save_object("players/quicksilver/closed/etc/jroom");  
  return 1;
}

addex(str) {
  string dest, dir;
  
  if(sscanf(str,"%s %s", dir, dest)!=2) return 1;
  add_exit(dest, dir);
  write("Exit "+dir+" added, and leads to "+dest+".\n");
  save_object("players/quicksilver/closed/etc/jroom");  
  return 1;
}

delex(str) {
  notify_fail("Invalid exit.\n");
  if(del_exit(str)) return save_object("players/quicksilver/closed/etc/jroom");  
  else return;
}

list() {
  int i;
  string name, name2;

  write("    Perm            Temp\n");
  write("=-=-=-=-=-=-=   =-=-=-=-=-=-=\n");
  for(i = 0; (i < sizeof(allowed))||(i < sizeof(tempallow)); i++)
        {
          name=(i < sizeof(allowed)) ? allowed[i] : "";
          name2=(i < sizeof(tempallow)) ? tempallow[i] : "";
          write((name ? capitalize(name) : "") + ((strlen(name) < 8) ? "\t\t" : "\t") + 
                (name2 ? capitalize(name2) : "") + "\n");
        }
    return 1;
}
