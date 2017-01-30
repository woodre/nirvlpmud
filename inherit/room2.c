/* This is revision 2 of room2 modules - since we use all its
   features it saves object overhead */

#include "/include/mudlib.h"
inherit BASE;

#include "/include/fn_specs/room.spc"
#include "/include/fn/vowel.h"
#include "/include/fn/exit_con.h"
#include "/include/fn/weather.h"
#include "/include/fn/i_to_str.h"
#include "/include/cfg/door_mac.h"
#include "/include/fn/newline.h"

#define BLIND       present("Blindness",this_player())
#define NAME        (string)this_player()->query_name()
#define CAP         (string)this_player()->query_cap_name()
#define REAL        (string)this_player()->query_name(1)
#define QUERY_INT   (int)this_player()->query_intelligence()
#define QUERY_LOCKS (int)this_player()->query_locks()
#define QUERY_TRAPS (int)this_player()->query_traps()


string *dest_dir;             /* list of exit room|directions */
string *extra_objects;        /* list of objects that can be taken */
string *items;                /* list of items that can be looked at */
string *night_items;          /* list of items in night_desc */
string *day_items;            /* list of items in day_desc */
string *search_array;
int search_complex;


string day_desc;              /* extra description of long in daylight */
string night_desc;            /* extra description of long at night */

string enter_msg;             /* string written after entering a room */
string exit_msg;              /* string written before leaving room */

int climb;                    /* climbing difficulty for up|down */
int fall_dam;                 /* damage taken if one falls whilst climbing */
int no_track;                /* This will prevent you from looking into the   
                                     room magically */
int no_summon, no_fight;              /* This will prevent fighting and
summoning from a particular room; */

string custom_exits;          /* "" == no exit list in long */

mixed *doors;                 /* list of doors */ 
mixed *detect_attempts;
mixed *disarm_attempts;
mixed *lock_attempts;


/***********************************************************************/

void reset(status arg) {
  reset_doors(0);      /* reset_doors(1) will erase secret door finders */
  if(arg) return;
}

string query_object_type() { return "Room"; }

void init() {  
  int i, size;  
  string act, tmp;

  ::init();  
  fix_day();         /* night-day cycler */
  
  /* i'd rather this in the reset */

  if(!smell_msg)     set_smell("You smell nothing special.\n");  
  if(!listen_msg)    set_listen("You hear nothing special.\n");  
  if(!dest_dir)      dest_dir = ({});
  if(!doors)         doors = ({});
  if(!extra_objects) extra_objects = ({});
  if(!items)         items = ({});
  if(!night_items)   night_items = ({});
  if(!day_items)     day_items = ({});
  if(!search_array)  search_array = ({});

  /* normal exits */

  for(i = 1, size=sizeof(dest_dir); i < size; i += 2) {  
    act = dest_dir[i];
    sscanf(act,"%s %s",act,tmp);
    add_action("ready_to_move", act);  
    add_action("ready_to_move", convert_to_brief(act));
  }

  /* doors */

  if((size = sizeof(doors))) {
    for(i = 0; i < size; i++) {  
      if(!(act = DOOR_ID)) continue;
      sscanf(act,"%s %s",act,tmp);
      add_action("door_to_move", act); 
      add_action("door_to_move",convert_to_brief(act));
    }
  }  
  if(sizeof(extra_objects)) {
    add_action("get_extra_object", "get");
    add_action("get_extra_object", "take");
  }
  add_action("close","close"); 
  add_action("open","open"); 
  add_action("lock","lock");
  add_action("unlock","unlock");
  add_action("disarm_trap","disarm"); 
  add_action("arm_trap","arm"); 
  add_action("detect","detect");
  add_action("pick_lock", "pick"); 
  add_action("search_room","search");
}  


void long(status wiz) {  
  int i, day;  
  object obj;  

  if(wiz) {
    write("File: "+file_name(this_object()) +"\n\n");
  }
  ::long(wiz);
  if(query_day()) {  
    if(day_desc) write(process_msg(day_desc));  
  }  
  else {  
    if(night_desc) write(process_msg(night_desc));  
  }  
}  


/* ids of items in room */

status id(string str) {
  int i, size;

  if(get_id_index(str,items) != -1) {
    return 1;
  }
  else if(get_id_index(str,extra_objects) != -1) {
    return 1;
  }
  else if(query_day() && get_id_index(str,day_items) != -1) {
    return 1;
  }
  else if(!query_day() && get_id_index(str,night_items) != -1) {
    return 1;
  }
  else {
    if(!doors) doors = ({});
    for(i = 0, size = sizeof(doors); i < size; i++) {
      if(DOOR_ID == str) {
        if(SECRET_DOOR && member_array(REAL,SECRET_DOOR_FINDERS) == -1) {
          return 0;  /* haven't found the secret door */
        }
        return 1;
      }
    }
  }
  return 0;  /* nothing in 'room' matching id matching 'str' */
}


/*********************************************************************/
/* sets */
  
string set_day_desc(string str)       { return day_desc = str; }  
string set_night_desc(string str)     { return night_desc = str; }  
string set_enter_msg(string s)        { return enter_msg = s; }
string set_exit_msg(string s)         { return exit_msg = s; }

string *set_exits(string *arr) {
  dest_dir = (arr) ? arr : ({});
  update_actions();
  return dest_dir;
}
string *set_extra_objects(string *arr) {
  extra_objects = arr;
  update_actions();
  return extra_objects;
}

string *set_items(string *arr)        { return items = arr; }
string *set_day_items(string *arr)    { return day_items = arr; }
string *set_night_items(string *arr)  { return night_items = arr; }

string *set_search_array(string *arr) { return search_array = arr; }
int set_search_complex(int i)         { return search_complex = i; }
 

mixed *set_doors(mixed *arr) {
  doors = (arr) ? arr : ({});
  update_actions();
  return doors;
}


int set_climb(int i)    { return climb = i; }  
int set_fall_dam(int i) { return fall_dam = i; }  

mixed *set_detect_attempts(mixed *arg) { return detect_attempts = arg; }
mixed *set_disarm_attempts(mixed *arg) { return disarm_attempts = arg; }
mixed *set_lock_attempts(mixed *arg)   { return lock_attempts = arg; }

int set_no_fight(int i)          { return no_fight = i; }
int set_no_track(int i)          { return no_track = i; }
int set_no_summon(int i)         { return no_summon = i; }

/**********************************************************************/
/* queries */


string query_day_desc()       { return day_desc;   }  
string query_night_desc()     { return night_desc; }  
string query_enter_msg()      { return enter_msg; }
string query_exit_msg()       { return exit_msg; }

string *query_dest_dir()      { return dest_dir; }  
string *query_extra_objects() { return extra_objects; }

string *query_items()         { return items; }
string *query_day_items()     { return day_items; }
string *query_night_items()   { return night_items; }

string *query_search_array(string *arr) { return search_array;   }
int query_search_complex(int i)         { return search_complex; }

mixed  *query_doors()         { return doors; }

mixed *query_detect_attempts() { return detect_attempts; }
mixed *query_disarm_attempts() { return disarm_attempts; }
mixed *query_lock_attempts()   { return lock_attempts; }

string query_exit_filename(string str) { 
  int i;
 
  if(!(sizeof(dest_dir) || str)) return 0;  
  if((i = member_array(str,dest_dir)) > -1) return dest_dir[i-1];  
  return 0;  
}  
  
string query_file_exitname(string file) {  
  int i;  

  if(!file) return 0;
  sscanf(file,"/%",file);
  if((i = member_array(file, dest_dir)) > -1) return dest_dir[i+1];  
  return 0;
}  
  

varargs string *query_door_exits(int arg) { /* get door exits only */
  int i;
  string *door_exits;

  door_exits = ({});
  for(i = 0; i < sizeof(doors); i++) {
    if(!arg || (arg == 1 && !CLOSED_FLAG) || (arg == 2 && CLOSED_FLAG) ||
       (arg == 3 && SECRET_DOOR)) { 
      door_exits += ({ doors[i][0], doors[i][1], });    
    }
  }
  return door_exits;
}

string *query_all_exits()    { return dest_dir + query_door_exits(); }

string *query_open_exits()   { return dest_dir + query_door_exits(1); } 

string *query_closed_exits() { return query_door_exits(2); }

string *query_exits()        { return dest_dir; }

int query_no_fight()         { return no_fight; }

int query_no_track()           {return no_track; }
int query_no_summon()         { return no_summon; }


/************************************************************************/
/* exits */

/*
 * write the exits to the room
 */

static status test_next_door(int i, int door_size, string finder) {
 i += 1;
 if(i >= door_size) return 0;
 if(SECRET_DOOR && member_array(finder,SECRET_DOOR_FINDERS) == -1) {
   return test_next_door(i,door_size,finder);
 }
 return 1;
}


void exits(status brief) {  
  string str, name, pad;
  int i, size;
  int count;  


  if(custom_exits) {
    write(custom_exits);
    return;
  }

  brief = (status)this_player()->query_brief();

  /* door exits */

  for(i = 0, size = sizeof(doors); i < size; i++) {
    if(SECRET_DOOR && member_array(REAL,SECRET_DOOR_FINDERS) == -1) continue;
    if(!count) str = "There is ";
    if(str == "") write("\n");
    str += (!count) ? "" : ((test_next_door(i,size,REAL)) ? ", " : " and ");
    str += (vowel(DOOR_ID)) ? "an " : "a ";
    str += DOOR_ID + ((CLOSED_FLAG) ? "(closed)" : "(open)");
    if(strlen(str) > 70) {
      write(str);
      str = "";
    } 
    count += 1;
  }
  if(count) write(str +".\n");
  
  size = sizeof(dest_dir);
  if(!(count || size)) {
    write("No Obvious Exits.\n");
    return;
  }
  if(!size) return;
  
  /* exits */

  str = "There "+((size == 2) ? "is " : "are ")+int_to_str(size/2)+" obvious";
  str += " exit"+ ((size == 2) ? ": " : "s: ");
  pad = "                                                               ";
  pad = extract(pad,0,strlen(str)-1);   

  for(i = 1; i < size; i += 2) {
    if(str == "") {
      write("\n");
      str = pad;
    }
    str += " "+ ((brief) ? convert_to_brief(dest_dir[i]) : dest_dir[i]);
    str += (i == size - 1) ? "."  : ((i == size - 2) ? " and" : ",");
    if(strlen(str) > 70) {
      write(str);
      str = "";
    } 
  }
  write(str +"\n");
} 

  
/**************************************************************************/
/* get ready to move */


status ready_to_move(string str) {   
  string direction, func;   
  int climb_skill, i;   
   
  direction = query_verb();   
  direction = convert_exit_name(direction);   
  if(str) direction += " " + str;

  if((direction == "up" || direction == "down") && climb > 0){   
    climb_skill = (int)this_player()->query_climb();   
    if(climb_skill < 1) climb_skill = 1;   
   
    /*** there is always a 1 in "climb" chance of climbing ***/   
   
    if(random(climb) > random(climb_skill)) {   
      write("You fall down.....\naahhhhhhhhhhhhhh!!\nThud!\n");   
      say(this_player()->query_name() + " falls down.\n");   
   
      /*** fall damage should be no greater then 6 ***/   
   
      if(fall_dam) this_player()->hit_player(random(fall_dam));   
      if(direction == "up") return 1;   
    }   
  }   

  if((i = member_array(direction,dest_dir)) == -1) return 0;
  if(sscanf(dest_dir[i-1],"@%s",func) == 1) { /* requested by tamsyn */
    return (status)call_other(this_object(),func,direction);
  }
  str = direction +"#"+ dest_dir[i-1];
 
  /*** its always slower to move in stealth ***/   
     
  if(this_player()->query_stealth_on()){   
    write("You sneak slowly "+ direction +"...\n");   
    call_out("room_move", 1, str);   
  }   
  else {   
    room_move(str);   
  }   
  return 1;   
} 


/****************************************************************************/
/* move player */
  
void room_move(string str) {
  string tmp_msg;

  if(!this_player()->move_player(str)) return; /* failed to move */    
  if(exit_msg) write(process_msg(exit_msg));   
  if((tmp_msg = (string)environment(this_player())->query_enter_msg())) {
    write(process_msg(tmp_msg));
  }
}  

    
/***************************************************************************/
/* look direction */

status look_dir(string dir) {
  int i;
  status wiz;

  if(!dir) return 0;
  dir = convert_exit_name(dir);
  if((i = member_array(dir, dest_dir)) == -1) return 0; /* failure */
  wiz = (this_player()->query_security_level()) ? 1 : 0;
  call_other(dest_dir[i-1],"long",wiz);
  return 1;
}

  
/************************************************************************/
/* dynamic exits */   


status add_exit(string where, string dest) {  
  int i;  

  if(!dest_dir) dest_dir = ({});
  if((i = member_array(dest, dest_dir)) > -1) return 0; /* failure */
  dest_dir += ({ where, dest });  
  update_actions();
  return 1;  
}  
  

status remove_exit(string dest) {  
  int i, size;  

  if((i=member_array(dest,dest_dir)) < 0) return 0; /* failure */
  if((size = sizeof(dest_dir)) == 2)
    dest_dir = ({});
  else
    dest_dir = dest_dir[0..i-2] + dest_dir[i+1..size];  
  update_actions();
  return 1;
}
  

status change_exit_room(string old_dest,string new_dest) {  
    int i;  

    if((i=member_array(old_dest,dest_dir)) == -1) return 0;
    dest_dir[i] = new_dest;  
    update_actions();
    return 1;  
}  


/**********************************************************************/
/* dynamic items */


varargs status add_item(string id_item, string item_str, mixed type) {
  int i;
  string str;
  str = type +"";
  switch(str) {
    case "1": case "day":
      if(!day_items) day_items = ({});
      if((i = member_array(id_item, day_items)) != -1) return 0;
      day_items += ({ id_item, item_str, });
    break;

    case "2": case "night":
      if(!night_items) night_items = ({});
      if((i = member_array(id_item, night_items)) != -1) return 0;
      night_items += ({ id_item, item_str, });
    break;

    default:
      if(!items) items = ({});
      if((i = member_array(id_item, items)) != -1) return 0;
      items += ({ id_item, item_str, });
    break;
  }
  return 1;
}


varargs status remove_item(string id_item, mixed type) {
  int i, size;  
  string str;
  
  str = type +"";
  switch(str) {
    case "1": case "day":
      if(!day_items) day_items = ({});
      if((i=get_id_index(id_item, day_items)) == -1) return 0;
      if((size = sizeof(day_items)) == 2)
        day_items = ({});
      else
      day_items = day_items[0..i-1]+ day_items[i+2..size];  
    break;

    case "2": case "night":
      if(!night_items) night_items = ({});
      if((i=get_id_index(id_item, night_items)) == -1) return 0;
      if((size = sizeof(night_items)) == 2)
        night_items = ({});
      else
        night_items = night_items[0..i-1]+ night_items[i+2..size];  
    break;

    default:
      if(!items) items = ({});
      if((i=get_id_index(id_item, items)) == -1) return 0;
      if((size = sizeof(items)) == 2)
        items = ({});
      else
        items = items[0..i-1]+ items[i+2..size];  
    break;
  }
  return 1;
}

  
varargs status change_item(string id_item, string item_str, mixed type) {
  int i;
  string str;

  str = type +"";
  switch(str) {
    case "1": case "day":
      if(!day_items) day_items = ({});
      if((i = get_id_index(id_item, day_items)) == -1) return 0;
      day_items[i+1] = item_str;
    break;

    case "2": case "night":
      if(!night_items) night_items = ({});
      if((i = get_id_index(id_item, night_items)) == -1) return 0;
      night_items[i+1] = item_str;
    break;

    default:
      if(!items) items = ({});
      if((i = get_id_index(id_item, items)) == -1) return 0;
      items[i+1] = item_str;
    break;
  }
  return 1;
}


/**********************************************************************/
/* extra objects */


status add_extra_object(string id_extra_object, string file_extra_object) {
  int i;

  if(!extra_objects) extra_objects = ({});
  if((i = member_array(id_extra_object,extra_objects)) != -1) return 0;
  extra_objects += ({ id_extra_object, file_extra_object, });
  return 1;
}


status remove_extra_object(string id_extra_object) {
  int i, size;  
  
  if((i=member_array(id_extra_object,extra_objects)) == -1) return 0;
  if((size = sizeof(extra_objects)) == 2)
    extra_objects = ({});
  else
    extra_objects = extra_objects[0..i-1]+extra_objects[i+2..size];  
  return 1;
}


status get_extra_object(string id_extra_object) {
  int i;
  object ob;  

  if(!id_extra_object) {
    write("Usage: get <item>\n");
    return 1;
  }
  if(present(id_extra_object,this_object())) return 0;
  if((i = get_id_index(id_extra_object,extra_objects)) == -1) return 0;
  ob = clone_object(extra_objects[i+1]);
  if(!this_player()->add_weight((int)ob->query_weight())) {
    write(capitalize(id_extra_object)+" is too heavy for you.\n");
    destruct(ob);
    return 1;
  }
#ifdef NATIVE_MODE
  ob->move(this_player());
#else
  move_object(ob, this_player());
#endif /* NATIVE_MODE */
  write("You get the "+capitalize(id_extra_object)+".\n");
  say(this_player()->query_name()+" gets a "+id_extra_object+".\n");
  return 1;
}


/****************************************************************************/
/* item_look */

status look_at(string str) {
  int i, size;
  string lock;

  if(!str) return 0;

  /* look thru items list */

  if((i = get_id_index(str,items)) != -1) {
    write(process_msg(add_newline(items[i+1])));
    return 1;
  }

  /* look thru day items list */

  if(query_day() && (i = get_id_index(str,day_items)) != -1) {
    write(process_msg(add_newline(day_items[i+1])));
    return 1;
  }

  /* look thru night items list */

  if(!query_day() && (i = get_id_index(str,night_items)) != -1) {
    write(process_msg(add_newline(night_items[i+1])));
    return 1;
  }

  /* look thru extra objects */

  else if((i = get_id_index(str,extra_objects)) != -1) {
    call_other(extra_objects[i+1],"long");
    return 1;
  }
  /* look in a direction */

  else if(look_dir(str)) {
    return 1;
  }

  /* look at doors */

  sscanf(str,"%s on %s", lock, str);
  sscanf(str,"%s on %s", lock, str);

  for(i = 0, size = sizeof(doors); i < size; i++) {
    if(DOOR_ID == str) {
      if(SECRET_DOOR && member_array(REAL,SECRET_DOOR_FINDERS) == -1) {
        return 0;  /* haven't found the secret door */
      }
      if(LOCK_ID && LOCK_ID == lock) {
        write(process_msg(add_newline(LOCK_DESC)));
        return 1;
      }
      if(!(str = DOOR_DESC)) {
        write("It looks like a door. Perhaps you should "+
              ((CLOSED_FLAG) ? "open" : "close") +" it.\n");
      }
      else {
        write(process_msg(add_newline(str)));
      }
      if(!CLOSED_FLAG) {
        write("Through the "+ DOOR_ID +" you see,\n");
        call_other(DOOR_DEST,"long");
      }
      else if(LOCKED_FLAG) {
        write("The "+ DOOR_ID +" appears to be locked.\n");
      }
      return 1;
    }
  }
  return 0;  /* nothing in 'room' matching id matching 'str' */
}



/***************************************************************************/
/* load door */

void load_door(mixed *arg) {
  int j, i, old_door;
  string door_id;

  if(!doors) doors = ({});
  i = sizeof(doors);
  doors += ({ allocate(DOOR_MAC_SIZE), });
  CLOSED_FLAG = 1; /* default is closed */
  for(j = 0; j < sizeof(arg); j++) {
    if(!stringp(arg[j])) continue;
    switch(arg[j]) {
case "destination": case "file":              DOOR_DEST     = arg[++j]; break;
case "direction": case "name":                DOOR_ID       = arg[++j]; break;
case "closed":                                CLOSED_FLAG   = 1;        break;
case "open":                                  CLOSED_FLAG   = 0;        break;
case "locked":                                LOCKED_FLAG   = 1;        break;
case "unlocked":                              LOCKED_FLAG   = 0;        break;
case "long": case "desc": case "description": DOOR_DESC     = arg[++j]; break;
case "lock id":                               LOCK_ID       = arg[++j]; break;
case "lock description":                      LOCK_DESC     = arg[++j]; break;
case "lock difficulty":                       DOOR_LOCK     = arg[++j]; break;
case "key":  case "key id":                   DOOR_KEY      = arg[++j]; break;
case "secret": case "secret door":            SECRET_DOOR   = arg[++j]; break;
case "door number": case "number":            DOOR_NUM      = arg[++j]; break;
case "trap on":                               TRAP_ON       = 1;        break;
case "trap off":                              TRAP_ON       = 0;        break;
case "trap description": case "trap desc":    TRAP_DESC     = arg[++j]; break;
case "trap damage":                           DOOR_TRAP     = arg[++j]; break;
case "trap message":                          DOOR_TRAP_MSG = arg[++j]; break;
case "trap room message":                DOOR_TRAP_MSG_ROOM = arg[++j]; break;
case "secret door finders":             SECRET_DOOR_FINDERS = arg[++j]; break;
    }
  }
  /* defaults */
  if(!DOOR_KEY)               DOOR_KEY  = "no_key";
  if(!LOCK_ID && LOCK_DESC)   LOCK_ID   = "lock";
  if(!DOOR_ID)                DOOR_ID   = "door";
  if(!DOOR_DESC)              DOOR_DESC = "A "+ DOOR_ID +".\n";
  if(DOOR_KEY == "city key")  LOCKED_FLAG = 0; /* city doors are unlocked */
  
  /* remove old versions */
  
  door_id = DOOR_ID;
  for(j = i,i = 0; i < sizeof(doors); i++) {
    if(door_id == DOOR_ID && i < j) {
      old_door += 1;
    }
  }
  while(old_door--) remove_door(door_id);  
  update_actions();
}  


/***************************************************************************/
/* set door attribute - change an attibute on an existing door */

status set_door_attribute(mixed door_id, string attribute, mixed arg) {
  int i;
  string file;
  status call_by_other_room;

  if(!doors) doors = ({});
  if(!sizeof(doors)) return 0;
  if(intp(door_id)) {
    if(previous_object()) {
      file = file_name(previous_object());
      for(i = 0; i < sizeof(doors); i++) {
        if(DOOR_DEST == file && DOOR_NUM == door_id) break;
      }
      if(i == sizeof(doors)) return 0;
      call_by_other_room = 1;
    }
    else {
      return 0;
    }
  }
  else { /* assume stringp */
    for(i = 0; i < sizeof(doors) && DOOR_ID != door_id; i++);
    if(i == sizeof(doors)) return 0;
  }
  switch(attribute) {
    case "destination": case "file":              DOOR_DEST     = arg; break;
    case "direction": case "name":                DOOR_ID       = arg; break;
    case "closed":                                CLOSED_FLAG   = 1;   break;
    case "open":                                  CLOSED_FLAG   = 0;   break;
    case "locked":                                LOCKED_FLAG   = 1;   break;
    case "unlocked":                              LOCKED_FLAG   = 0;   break;
    case "long": case "desc": case "description": DOOR_DESC     = arg; break;
    case "lock id":                               LOCK_ID       = arg; break;
    case "lock description":                      LOCK_DESC     = arg; break;
    case "lock difficulty":                       DOOR_LOCK     = arg; break;
    case "key":  case "key id":                   DOOR_KEY      = arg; break;
    case "secret": case "secret door":            SECRET_DOOR   = arg; break;
    case "secret door finders":             SECRET_DOOR_FINDERS = arg; break;
    case "trap on":                               TRAP_ON       = 1;   break;
    case "trap off":                              TRAP_ON       = 0;   break;
    case "trap description": case "trap desc":    TRAP_DESC     = arg; break;
    case "trap damage":                           DOOR_TRAP     = arg; break;
    case "trap message":                          DOOR_TRAP_MSG = arg; break;
    case "trap room message":                DOOR_TRAP_MSG_ROOM = arg; break;
    case "door number":                           DOOR_NUM      = arg; break;
    default:
      return 0;
    break;
  }
  if(call_by_other_room) return 1;
  if(catch(call_other(DOOR_DEST,"set_door_attribute",DOOR_NUM,attribute,arg))){
    write("Error loading "+ DOOR_DEST +"\n");
  }
  return 1;
}


/***************************************************************************/
/* query door attribute -  on an existing door */


mixed query_door_attribute(string door_id, string attribute) {
  int i;

  if(!doors) doors = ({});
  if(!sizeof(doors)) return -1;
  for(i = 0; i < sizeof(doors) && DOOR_ID != door_id; i++);
  if(i == sizeof(doors)) return -1;
  switch(attribute) {
    case "destination": case "file":              return DOOR_DEST;
    case "direction": case "name":                return DOOR_ID;
    case "closed":                                return CLOSED_FLAG;
    case "open":                                  return !CLOSED_FLAG;
    case "locked":                                return LOCKED_FLAG;
    case "unlocked":                              return !LOCKED_FLAG;
    case "long": case "desc": case "description": return DOOR_DESC;
    case "lock id":                               return LOCK_ID;
    case "lock description":                      return LOCK_DESC;
    case "lock difficulty":                       return DOOR_LOCK;
    case "key":  case "key id":                   return DOOR_KEY;
    case "secret": case "secret door":            return SECRET_DOOR;
    case "trap on":                               return TRAP_ON;
    case "trap off":                              return !TRAP_ON;
    case "trap description": case "trap desc":    return TRAP_DESC;
    case "trap damage":                           return DOOR_TRAP;
    case "trap message":                          return DOOR_TRAP_MSG;
    case "trap room message":                     return DOOR_TRAP_MSG_ROOM;
    case "door number":                           return DOOR_NUM;
    case "secret door finders":                   return SECRET_DOOR_FINDERS;
    default:
      return -1;
    break;
  }
  return -1;
}


/*****************************************************************/
/* remove a door from room */

status remove_door(string str) {  
  int i, size;  

  if(!str) return 0;
  for(i = 0, size = sizeof(doors); i < size; i++) {
    if(str == DOOR_ID) {
      if(size == 1) 
        doors = ({});
      else
        doors = doors[0..i-1] + doors[i+1..size-1];  
      return 1;
    }
  }
  return 0;  
}


/**********************************************************************/
/* start movement thru door (from add_action) */

status door_to_move(string str) {   
  string direction;   
  int i, size;
   
  direction = query_verb();   
  direction = convert_exit_name(direction);   
  /* default door exit appendages */
  if(!str && id(direction +" door")) str = "door";
  if(!str && id(direction +" gate")) str = "gate";

  if(str) direction += " " + str;

  for(i = 0, size = sizeof(doors); i < size; i++) {
    if(direction == DOOR_ID) {
      if(SECRET_DOOR && member_array(REAL,SECRET_DOOR_FINDERS) < 0) {
        return 0;  /* haven't found the secret door */
      }
      if(CLOSED_FLAG) {
        write("The "+ DOOR_ID +" is closed\n");
        return 1;
      }
             
      /*** its always slower to move in stealth ***/   
     
      if(this_player()->query_stealth_on()){   
        write("You sneak slowly "+ direction +"...\n");   
        call_out("room_move", 1, DOOR_ID+"#"+DOOR_DEST);   
      }   
      else {   
        room_move(DOOR_ID+"#"+DOOR_DEST);   
      }
      if(SECRET_DOOR) {
        CLOSED_FLAG = 1;
        CLOSE_NEXT_ROOM(1);
        write("The "+DOOR_ID+" closes behind you.\n");   
      }
      return 1;   
    }
  }
  return 0; /* nothing in that direction */
}   

/***************************************************************************/
/* here */

status ob_here(string str) {
  if(!str) return 0;
  return (present(str) || present(str,this_player())) ? 1 : 0;
}

/***************************************************************************/
/* search room for secret doors */

int search_room(string str) {
  int i, size, search;
  string race;
  status found_flag; /* search finds something */
  string tmp1, tmp2;

  if(!str) {
    notify_fail("search what?\n");
    return 0;
  }
  search = QUERY_INT;
  if((race = (string)this_player()->query_race())) {
    if(sscanf(race,"%self%s", tmp1, tmp2)) {
      search += 3; /* racial search bonus */
    }
  }
  if(id(str)) {
    if((i = get_id_index(str,search_array)) != -1) {
      if(random(search_complex+1) <= random(search)) {
        write(process_msg(add_newline(search_array[i+1])));
        return 1;
      }
    }
    notify_fail("You find nothing of interest.\n");
    return 0;
  }
  else if(str != "room") {
    notify_fail("There is no "+ str +" here.\n");
    return 0;
  }
  for(i = 0, size = sizeof(doors); i < size; i++) {
    if(SECRET_DOOR) {
      if(random(SECRET_DOOR) <= random(search)) {
        if(member_array(REAL,SECRET_DOOR_FINDERS) < 0) {
          SECRET_DOOR_FINDERS += ({ REAL, });
          if(!found_flag)
            write("You find a secret door!\n");
          else
            write("You find another secret door!\n");
          found_flag = 1;
        }
      }
    }
  }
  if(!found_flag) {
    write("You find nothing of interest.\n");
  }
  return 1;
}


/************************************************************************/
/* open the door */


status open(string str) {
  int i, size;

  if(!str) {
    notify_fail("open what?\n");
    return 0;
  }
  for(i = 0, size = sizeof(doors); i < size; i++) {
    if(DOOR_ID == str) {
      if(SECRET_DOOR && member_array(REAL,SECRET_DOOR_FINDERS) == -1) {
        return 0; /* its a secret door */
      }
      if(DOOR_TRAP && TRAP_ON) {     /* Is door trap set? */
        TRAP_ON = 0;    /* trap_flag off */
        TRAP_NEXT_ROOM(0);
        write(process_msg(DOOR_TRAP_MSG));
        say(process_msg(DOOR_TRAP_MSG_ROOM));
        if(this_object()->trap_sprung(i)) return 1;
        this_player()->hit_player(DOOR_TRAP); 
      }
      if(!CLOSED_FLAG) {
        write("The "+ str +" is already open.\n");
        say(NAME +" tries to open an OPEN "+ str +"!!\n");
      }
      else {
        if(!LOCKED_FLAG || DOOR_KEY == "no_key") {
          write("You open the "+ str +".\n");
          say(NAME +" opens the "+ str +".\n");
          CLOSED_FLAG = 0; /* open the door */
          CLOSE_NEXT_ROOM(0);
        }
        else {
          write("The "+ str +" appears to be locked.\n");
          say(NAME +" cannot open the "+ str +".\n");
          if(DOOR_KEY && DOOR_KEY != "no_key") {
            write("There is a "+ LOCK_ID +".\n");
          }
        }
      }
      return 1;
    }   
  }
  if(id(str) || ob_here(str))
    notify_fail("You can't do that!\n");
  else
    notify_fail("There is no "+ str +" here.\n");
  return 0;
}


/***************************************************************************/
/* close the door */

status close(string str) {
  int i, size;

  if(!str) {
    notify_fail("close what?\n");
    return 0;
  }
  for(i = 0, size = sizeof(doors); i < size; i++) {
    if(DOOR_ID == str) {
      if(SECRET_DOOR && member_array(REAL,SECRET_DOOR_FINDERS) == -1) {
        return 0; /* its a secret door */
      }
      if(DOOR_TRAP && TRAP_ON) {     /* Is door trap set? */
        TRAP_ON = 0;    /* trap_flag off */
        TRAP_NEXT_ROOM(0);
        write(process_msg(DOOR_TRAP_MSG));
        say(process_msg(DOOR_TRAP_MSG_ROOM));
        if(this_object()->trap_sprung(i)) return 1;
        this_player()->hit_player(DOOR_TRAP); 
      }
      if(!CLOSED_FLAG) {
        write("You close the "+ str +".\n");
        say(NAME +" closes the "+ str +".\n");
        CLOSED_FLAG = 1;
        CLOSE_NEXT_ROOM(1);
      }
      else {
        write("The "+ str +" is already closed.\n");
        say(NAME +" runs into the "+ str +".\n");
      }
      return 1;
    }   
  }
  if(id(str) || ob_here(str))
    notify_fail("You can't do that!\n");
  else
    notify_fail("There is no "+ str +" here.\n");
  return 0;
}

/**************************************************************************/
/* lock door */

status lock(string str) {  
  object key;  
  int i;
  string verb;
  string key_name;  
    
  if(!str || sscanf(str,"%s with %s", str, key_name) != 2) {
    notify_fail("lock <what> with <item>?\n");
    return 0;
  }
  for(i = sizeof(doors); i--; ) {
    if(DOOR_ID == str) {
      if(LOCKED_FLAG) {
        write("The "+ str +" is already locked.\n");
        return 1;
      }
      if(!(key = present(key_name, this_player()))){ 
        write("But you don't have a "+ capitalize(key_name) +"!\n"); 
        return 1; 
      } 
      if(key->id(DOOR_KEY) || DOOR_KEY == "no_key") {
        if(!CLOSED_FLAG) {
          write("You close the "+ str +".\n");
          CLOSED_FLAG = 1;
          CLOSE_NEXT_ROOM(1);
        }
        write("You lock the "+ str +" with the "+ key_name +".\n");
        say(NAME +" locks the "+ str +".\n");
        LOCKED_FLAG = 1;
        LOCK_NEXT_ROOM(1);
        return 1;
      }
    }
  }  
  if(id(str) || ob_here(str))
    notify_fail("You can't do that!\n");
  else
    notify_fail("There is no "+ capitalize(str) +" here.\n");
  return 0; 
}

/**************************************************************************/
/* unlock door */

status unlock(string str) {  
  object key;  
  int i;
  string verb;
  string key_name;  
    
  if(!str || sscanf(str,"%s with %s", str, key_name) != 2) {
    notify_fail("unlock <what> with <item>?\n");
    return 0;
  }
  for(i = sizeof(doors); i--; ) {
    if(DOOR_ID == str) {
      if(!LOCKED_FLAG) {
        write("The "+ str +" is already unlocked.\n");
        return 1;
      }
      if(!(key = present(key_name, this_player()))){ 
        write("But you don't have a "+ capitalize(key_name) +"!\n"); 
        return 1; 
      } 
      if(key->id(DOOR_KEY) || DOOR_KEY == "no_key") {
        write("You unlock the "+ str +" with the "+ key_name +".\n");
        say(NAME +" unlocks the "+ str +".\n");
        LOCKED_FLAG = 0;
        LOCK_NEXT_ROOM(0);
        return 1;
      }
    }
  }  
  if(id(str) || ob_here(str))
    notify_fail("You can't do that!\n");
  else
    notify_fail("There is no "+ capitalize(str) +" here.\n");
  return 0; 
}


/**************************************************************************/
/* pick lock */

status pick_lock(string str) {
  object ob;
  int i, j;

  if(QUERY_LOCKS == 0) {
    notify_fail("You do not have the skill to pick locks.\n");
    return 0;
  }
  if(!str || sscanf(str,"lock on %s",str) != 1) {
    notify_fail("pick lock on what?\n");
    return 0;
  }
  for(i = sizeof(doors); i--; ) {
    if(DOOR_ID == str) {
      if(SECRET_DOOR && member_array(REAL,SECRET_DOOR_FINDERS) == -1) {
        return 0; /* its a secret door */
      }
      if(DOOR_TRAP && TRAP_ON) {     /* Is door trap set? */
        TRAP_ON = 0;    /* trap_flag off */
        TRAP_NEXT_ROOM(0);
        write(process_msg(DOOR_TRAP_MSG));
        say(process_msg(DOOR_TRAP_MSG_ROOM));
        if(this_object()->trap_sprung(i)) return 1;
        this_player()->hit_player(DOOR_TRAP); 
      }
      if(!CLOSED_FLAG) {
        write("You close the "+ DOOR_ID +".\n");
        CLOSED_FLAG = 1;
        CLOSE_NEXT_ROOM(1);
      }
      write("You attempt to pick the lock.\n");
      if(!lock_attempts) lock_attempts = ({});
      if((j = member_array(str,lock_attempts)) == -1) {
        lock_attempts += ({ str, ({}), });
        j = member_array(str, lock_attempts);
      }
      if(member_array(REAL, lock_attempts[j+1]) != -1) {
        write("You give up...\n");
        return 1;
      }
      if(member_array(CAP, lock_attempts) != -1 ||
         random(QUERY_LOCKS+1) >= random(DOOR_LOCK+1)) {
        LOCKED_FLAG = !LOCKED_FLAG;
        tell_room(environment(this_player()),"Click!\n");
        write("You "+((LOCKED_FLAG) ? "" : "un")+"lock the "+ DOOR_ID +".\n");
        if(member_array(CAP, lock_attempts[j+1]) == -1) {
          lock_attempts[j+1] += ({ CAP, });
        }
      }
      else {
        write("You give up...\n");
        lock_attempts += ({ REAL, });
      }
      NEXT_ROOM_LOCKS();
      return 1;
    }
  }
  if(id(str) || ob_here(str))
    notify_fail("You can't do that!\n");
  else
    notify_fail("There is no "+ str +" here.\n");
  return 0;
}


/**************************************************************************/
/* disarm door trap */

status disarm_trap(string str) {
  int i, j;

  if(!str || sscanf(str,"trap on %s",str) != 1) {
    notify_fail("disarm trap on what?\n");
    return 0;
  }
  if(!detect_attempts) detect_attempts = ({});
  if((i = member_array(str, detect_attempts)) == -1 ||
    (member_array(REAL,detect_attempts[i+1]) == -1 
    && member_array(CAP,detect_attempts[i+1]) == -1)) {
    notify_fail("You have to detect a trap before you can disarm it.\n");
    return 0;
  }
  if(member_array(REAL,detect_attempts[i+1]) != -1) {
    write("You have not found a trap to disarm.\n");
    return 1;
  } 
  if(!disarm_attempts) disarm_attempts = ({});
  if((j = member_array(str, disarm_attempts)) == -1) {
    disarm_attempts += ({ str, ({}), });
    j = member_array(str, disarm_attempts);
  }
  if(member_array(REAL, disarm_attempts[j+1]) != -1) {
    write("You think you have disarmed it already.\n");
    return 1;
  }
  for(i = sizeof(doors); i--; ) {
    if(DOOR_ID == str) {
      if(random(DOOR_LOCK+1) <= random(QUERY_LOCKS+1)) {
        TRAP_ON = 0;
        TRAP_NEXT_ROOM(0);
      }
      write("You think you have disarmed the trap.\n");
      break;
    }
  }
  disarm_attempts[j+1] += ({ REAL, });
  NEXT_ROOM_DISARMS();
  return 1;
}    


/***************************************************************************/
/* arm door trap */

status arm_trap(string str) {
  int i, j, k;
  string door_id;

  if(!str || sscanf(str,"trap on %s",str) != 1) {
    notify_fail("arm trap on what?\n");
    return 0;
  }
  if(!detect_attempts) detect_attempts = ({});
  if((k = member_array(str, detect_attempts)) == -1 ||
    (member_array(REAL,detect_attempts[k+1]) == -1 
    && member_array(CAP,detect_attempts[k+1]) == -1)) {
    notify_fail("You have to detect any traps first.\n");
    return 0;
  }
  if(member_array(REAL,detect_attempts[k+1]) != -1) {
    write("You have not found a trap to arm.\n");
    return 1;
  } 
  if(!disarm_attempts) disarm_attempts = ({});
  if((j = member_array(str, disarm_attempts)) == -1) {
    disarm_attempts += ({ str, ({}), });
    j = member_array(str, disarm_attempts);
  }
  for(i = sizeof(doors); i--; ) {
    if(DOOR_ID == str) {
      if(random(DOOR_LOCK+1) <= random(QUERY_LOCKS+1)) {
        TRAP_ON = 1;
        TRAP_NEXT_ROOM(1);
        disarm_attempts[j+1] = ({});
        detect_attempts[k+1] = ({ CAP, });       
        write("You arm the trap.\n");
        NEXT_ROOM_DISARMS();
        NEXT_ROOM_DETECTS();
      }
      else {
        TRAP_ON = 0;    /* trap_flag off */
        TRAP_NEXT_ROOM(0);
        write(process_msg(DOOR_TRAP_MSG));
        say(process_msg(DOOR_TRAP_MSG_ROOM));
        if(this_object()->trap_sprung(i)) return 1;
        this_player()->hit_player(DOOR_TRAP);
      }
      return 1;
    }
  }
  return 1;
}    

/**********************************************************************/
/* detect door trap */

status detect(string str) {
  int i, j;

  if(QUERY_TRAPS == 0) {
    notify_fail("You do not have the skill to detect traps.\n");
    return 0;
  }
  if(!str || sscanf(str,"trap on %s",str) != 1) {
    notify_fail("detect trap on what?\n");
    return 0;
  }
  say(this_player()->query_name()+" examines the door for traps.\n");
  for(i = sizeof(doors); i--; ) {
    if(DOOR_ID == str) {
      if(SECRET_DOOR && member_array(REAL,SECRET_DOOR_FINDERS) == -1) {
        break; /* its a secret door */
      }
      if(!detect_attempts) detect_attempts = ({});
      if((j = member_array(str,detect_attempts)) == -1) {
        detect_attempts += ({ str, ({}), });
        j = member_array(str, detect_attempts);
      }
      if(!DOOR_TRAP || member_array(REAL,detect_attempts[j+1]) != -1) {
        write("There are no traps that you can detect.\n");
        if(member_array(REAL, detect_attempts[j+1]) == -1) {
          detect_attempts[j+1] += ({ REAL, });
        }
        return 1;
      }
      if(member_array(CAP,detect_attempts[j+1]) != -1) {
        write(process_msg(TRAP_DESC));
        return 1;
      }
      if(random(DOOR_LOCK+1) <= random(QUERY_TRAPS+1)) {
        TRAP_ON = 0;
        TRAP_NEXT_ROOM(0);
        detect_attempts[j+1] += ({ CAP, });
        write(process_msg(TRAP_DESC));
      }
      NEXT_ROOM_DETECTS();
      return 1;
    }
  }
  if(id(str) || ob_here(str))
    notify_fail("You can't do that!\n");
  else
    notify_fail("There is no "+ str +" here.\n");
  return 0;
}    


/***************************************************************************/
/* set door trap flag */

varargs status set_door_trap(string filename, status trap, int door_num) {
  int i, size;

  for(i = 0, size = sizeof(doors); i < size; i++) {
    if(DOOR_DEST == filename) {
      if(door_num != DOOR_NUM) continue;
      TRAP_ON = trap;
      return 1;
    }
  }
  return 0;
}


/**************************************************************************/
/* set door closed flag */

varargs status set_door_closed(string filename, status close, int door_num) {
  int i, size;

  for(i = 0, size = sizeof(doors); i < size; i++) {
    if(DOOR_DEST == filename) {
      if(door_num != DOOR_NUM) continue;
      CLOSED_FLAG = close;
      tell_room(this_object(),
        "The "+DOOR_ID+((close) ? " closes" : " opens")+".\n");
      return 1;
    }
  }
  return 0;
}

/**************************************************************************/
/* set door locked flag */

varargs status set_door_lock(string filename, status locked, int door_num) {
  int i, size;

  for(i = 0, size = sizeof(doors); i < size; i++) {
    if(DOOR_DEST == filename) {
      if(door_num != DOOR_NUM) continue;
      LOCKED_FLAG = locked;
      tell_room(this_object(),"Click!.\n");
      return 1;
    }
  }
  return 0;
}
   

/***************************************************************************/
/* close all doors */

void reset_doors(status arg) {
  int i, size;
  object room;

  if(!doors) doors = ({});
  for(i = 0, size = sizeof(doors); i < size; i++) {
    TRAP_ON = 1;
    TRAP_NEXT_ROOM(1);
    CLOSED_FLAG = 1;
    CLOSE_NEXT_ROOM(1);
    LOCKED_FLAG = (DOOR_KEY == "city key") ? 0 : 1;
    LOCK_NEXT_ROOM(LOCKED_FLAG);
    detect_attempts = ({});
    NEXT_ROOM_DETECTS();
    disarm_attempts = ({});
    NEXT_ROOM_DISARMS();
    lock_attempts   = ({});
    NEXT_ROOM_LOCKS();
    if(arg) SECRET_DOOR_FINDERS = ({});
  }
}


/***************************************************************************/
/* get index */

int get_id_index(string str,string *arr) {
  int i;
  string *ids;

  if(!arr) return -1;
  for(i = 0; i < sizeof(arr); i += 2) {
#ifdef OLD_EXPLODE
    ids = explode(arr[i]+"#", "#");
#else
    ids = explode(arr[i], "#");
#endif
    if(member_array(str,ids) != -1) return i;
  }
  return -1;
}     

/****************************************************************************/
/* set_sign */

varargs void set_sign_message(string str, string lang) {
  object obj;

  if(!str) return;
  obj = clone_object("inherit/sign");
  obj->set_message(str);
  if(lang) obj->set_language(lang);
#ifdef NATIVE_MODE
  obj->move(this_object());
#else
  move_object(obj, this_object());
#endif /* NATIVE_MODE */
}
string query_name() { return file_name(this_object()); }

