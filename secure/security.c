/*************************************************************************/
/* security.c
 */
 
#include "/include/mudlib.h"
#include "/include/cfg/master.cfg"
#include "/include/cfg/player.cfg"
#include "/include/security.h"
#include "/include/cfg/levels.h"

/************************************************************************/
/* some function specs */
/* void remove_current_edit(string file); */


/************************************************************************/
/* 3.2 allows two people to edit same file simultaneously!!
 * here is a hack to stop that
 */

string *current_edit; /* list of files currently edited */

/* string *query_current_edit() { return current_edit; } */


status add_current_edit(string file) 
{
  string name;
  int i;

  name = capitalize((string)this_player()->query_name(1));
  if(!current_edit) current_edit = ({});
  if((i=member(current_edit, file)) != -1) 
  {
    write("Warning: "+ file +" is being edited by "+ current_edit[i+1] +".\n"); 
    return 0; /* return 0, if you want to stop editing all together */
  }
  current_edit += ({ file, name, });
  return 1;
}  

void remove_current_edit_name (string name) 
{
  int i;

  if(!current_edit) current_edit = ({});
  if((i = member(current_edit, name)) == -1) return;
  current_edit = current_edit[0..(i-2)]
               + current_edit[(i+1)..(sizeof(current_edit)-1)];
}

void remove_current_edit_file (string file) 
{
  int i;

  if(!current_edit) current_edit = ({});
  if((i = member(current_edit, file)) == -1) return;
  current_edit = current_edit[0..(i-1)]
               + current_edit[(i+2)..(sizeof(current_edit)-1)];
}

/* master object(s) have full write access - defined in security.h */

nomask status valid_master_object(object ob) {
  int i;
  string file;

  file = file_name(ob);

#ifdef MASTER_OBJECTS
  for(i = sizeof(MASTER_OBJECTS); i--; ) {
    if(file == MASTER_OBJECTS[i]) return 1;
  }
#endif

#ifdef MASTER_DIRECTORIES
  for(i = sizeof(MASTER_DIRECTORIES); i--; ) {
    if(sscanf("/"+ file, MASTER_DIRECTORIES[i], file) == 1) return 1;
  }
#endif
  return 0;
}


/* path is a 'master' file */

static status master_path(string path) {
  int i;

#ifdef MASTER_OBJECTS
  for(i = sizeof(MASTER_OBJECTS); i--; ) {
    if(path == "/"+ MASTER_OBJECTS[i] +".c") return 1;
  }
#endif

#ifdef MASTER_DIRECTORIES
  for(i = sizeof(MASTER_DIRECTORIES); i--; ) {
    if(sscanf(path, MASTER_DIRECTORIES[i], path) == 1) return 1;
  }
#endif
  return 0;
}


/* player object(s) - defined in security.h */

nomask status restricted_path_object(object ob) {
  int i, n;
  string file;

  file = object_name(ob);
  if(!file) return 0;

#ifdef RESTRICTED_PATH_OBJECTS
  for(i = sizeof(RESTRICTED_PATH_OBJECTS); i--; ) {
    if(sscanf(file, RESTRICTED_PATH_OBJECTS[i] +"#%d", n) == 1) return 1;
  }
#endif
  return 0;
}


/* 
 * certain paths are marked as restricted, to hold the integrity
 * of objects
 */

static status restricted_path(string file) {
  string *path;
  int i;
  
  path = RESTRICTED_PATHS;
#ifdef MASTER_DIR
  path += MASTER_DIR;
#endif /* MASTER_DIR */

  for(i = sizeof(path); i--; ) {
    if(sscanf(file, path[i], file)) return 1;
  }
  return 0;
}

static void fail(string str) {
  if(this_player()->query_security_level() > SEC0) {
    write(str +"\n");
  }
}


/****************************************************************************/
/* validate file writes */

nomask mixed valid_write(string path, object caller, string call_fun) {
  string domain, who, file;  
  int i;
  string name;
  int security_level;
  status restricted_access, restricted_caller;

  restricted_caller = restricted_path_object(caller);
  if(this_interactive()) {
    name = (string)this_interactive()->query_real_name();
    security_level = (int)this_interactive()->query_security_level();
  }
#if 1
  else if(this_player() && restricted_path_object(this_player())) {
    name = (restricted_caller) 
         ? (string)this_player()->query_real_name()
         : creator(caller);
    security_level = SEC0;
    restricted_access = 1;
  } 
  else if(stringp(creator(caller))) {
    name = creator(caller);
    security_level = SEC0;
    restricted_access = 1;
  }
#endif
  if(!path || path[0] != '/' || !caller) return 0;


  /* master object(s) have full write access */
  if(valid_master_object(caller)) 
  {
    return path[1..];
  }


  /* test if (unknown) object is trying to write to main lib */
  if(restricted_path(path)) {
    if(restricted_access && restricted_caller) {
      if(call_fun != "save_object"
      || sscanf(path,"/usr/%s",file) != 1) {
        fail("Cannot use Restricted Access for a restricted path.");
        return 0;
      }
    }
    else if(!restricted_caller) {
      fail(object_name(caller) +" cannot access a Restricted Path.");
      return 0;
    }
  }
  

  if(master_path(path) && security_level < MASTER_SECURITY) {
    fail("Need Master Security Level: "+ MASTER_SECURITY);
    return 0;
  }


  /* allow 'name' full write access to their directories */
  /* weakness - name yourself a restricted path */

  if(name) {
    if((sscanf(path,"%s/"+ name +"/%s", who, file) == 2
    || sscanf(path,"%s/"+ name +".%s", who, file) == 2)
    && sscanf(path,"/usr/%s", file) != 1) {
      if(!restricted_access                 /* using this_interactive() */
      || creator(caller) == name            /* or using your own object */
      || restricted_path_object(caller)) { /* or using valid object    */ 
        return path[1..];
      }
    }
  }
  

  /* make validations for specific efuns */

  switch(call_fun) {
    case "save_object":

#if defined(MAIL_DIR) && defined(MAILER)
      if(sscanf(path,"/"+ MAIL_DIR +"%s", file)) { /* only mailer here */
        file = object_name(caller);
        sscanf(file,"%s#%d",file,i);
#ifdef INTERMUD
        if(file == "secure/UDP_CMD_DIR/mail") return path[1..];
#endif /* INTERMUD */
        if (file == MAILER) return path[1..];
        fail("Illegal Mailer Object.");
        return 0;
      }
#endif /* MAILER */

      return path[1..];
      break;

    case "ed_start":
      if(!restricted_caller) {
        fail("Illegal object using ed()");
        return 0;
      }
 /*     remove_current_edit(path); */
      break;

    case "mkdir":
      if(!restricted_caller) {
        fail("Illegal Object using mkdir()");
        return 0;
      }
      
      /* Domain, promote stuff */
      /* Necassary to make sure Access objects are automatically made! */
      
      if(sscanf(path,DOMAIN_DIR +"%s",domain) == 1) {
        if(sscanf(domain,"%s/%s",domain,file) != 2) {
          write("Use 'domain' command to make a New Domain.\n");
          return 0; /* only create_wizard() fn can add domain creators */
        }
        if(sscanf(path,DOMAIN_DIR +"%s/w/%s",domain,file) ==  2) {
          if(sscanf(file,"%s/%s",who,file) != 2) {
            write("Use 'domain' command to add a New Creator Directory.\n");
            return 0; /* only create_wizard() fn can add domain creators */
          }
        }
      }
      if(sscanf(path,WIZARD_DIR +"%s", file) == 1) {
        if(sscanf(file,"%s/%s",who,file) != 2) {
          write("Use 'promote' command to add a New Creator Directory.\n");
          return 0; /* only create_wizard() fn can add creators */
        }
      }
      break;

    case "write_file":
      if(sscanf(path,"/log/%s",file)) {
        return path[1..];
      }

    case "cindent":
    case "rmdir":
    case "do_rename":
    case "remove_file":
    case "write_bytes":
      break;
  }

  switch(security_level) {
    case SEC9:
    case SEC8:
      return path[1..];

    case SEC7:
      if(sscanf(path, WIZARD_DIR +"%s/private/%s", who, file) == 2
      || sscanf(path, "/inherit/base/%s", file) == 1
      || sscanf(path, SHADOW_DIR, file) == 1) {
        break;
      }
      
      if(sscanf(path, WIZARD_DIR +"%s/%s", who, file) == 2
      || sscanf(path, DOMAIN_DIR +"%s/w/%s/%s", domain, who, file) == 3
      || sscanf(path, "/obj/%s", file) == 1
      || sscanf(path, "/function/%s", file) == 1  
      || sscanf(path, "/inherit/%s", file) == 1
      || sscanf(path, "/objects/%s", file) == 1) {
         return path[1..];
      }

    case SEC6:
      if(sscanf(path, "/doc/helpdir/%s", file) == 1) {
        return path[1..];
      }

    case SEC5:
      if(sscanf(path, "/room/post/%s", file) == 1) {
        break;
      }

      if(sscanf(path, "/room/%s", file) == 1) {
        return path[1..];
      }

    case SEC4:
      if(sscanf(path, "/bin/%s", who) == 1
      || sscanf(path, "/skills/%s", file) == 1) {
        return path[1..];
      }

    case SEC3:
    case SEC2:
    case SEC1:
    case SEC0:
      break;

    default:
      write("Error: Unknown Security Level.\n");
  }

#ifdef SC
  if(path == SOUL_FUNC_FILE) {
    if(member(SC, name) != -1) {
      return path[1..];
    }
  }
#endif /* SC */

  /* Open Write Files */

  if(sscanf(path, "%s/open/%s", who, file) == 2
  || sscanf(path, "/ideas/%s", file) == 1) {
    return path[1..];
  }
 

  if(sscanf(path, WIZARD_DIR +"%s/%s", who, file) == 2
  && sscanf(path, "%s/private/%s", who, file) != 2) {
    if(file != "access.c") {
      if(call_other(WIZARD_DIR+who+"/access","valid_write",path,name)) {
        return path[1..];
      }
    }
  }

  if(sscanf(path, DOMAIN_DIR +"%s", file) == 1) {
    if(file != "access.c") {
      if(call_other(DOMAIN_DIR +"/access", "valid_write",path,name)) {
        return path[1..];
      }
    }
  }

  return 0;
}


/**********************************************************************/
/* validate file reads */

nomask mixed valid_read(string path, object caller, string call_fun) {
  string domain, who, file;  
  string name;
  int security_level;
  mixed *error;
  status restricted_caller;
  int i;

  restricted_caller = restricted_path_object(caller);
  if(this_interactive()) {
    name = (string)this_interactive()->query_real_name();
    security_level = (int)this_interactive()->query_security_level();
  }
#if 1
  else if(this_player() && restricted_path_object(this_player())) {
    name = (string)this_player()->query_real_name();
    security_level = SEC0;
  }
  else if(stringp(creator(caller))) {
    name = creator(caller);
    security_level = SEC0;
  }
#endif

#if 0 /* amylaar can use this, but mudlib handles it better */
  if(!path) {
    if(call_fun == "ed_start") {
      error = get_error_file((string)this_player()->query_real_name());
      if(!error || error[3]) {
        write("No error.\n");
        return 0;
      }
      write(extract(error[0],1)+" line "+error[1]+": "+error[2]+"\n");
      return error[0];
    }
    return 0;
  }
#else
  if(!path) return 0;
#endif /* AMYLAAR */

  if(path[0] != '/' || !caller) return 0;
 
  if(valid_master_object(caller)) 
  {
    return path[1..];
  }

  switch(call_fun) {
    case "restore_object": 
#if defined(MAIL_DIR) && defined(MAILER)
      if(sscanf(path,MAIL_DIR +"%s",file)) {
        file = object_name(caller);
        sscanf(file,"%s#%d",file,i);
#ifdef INTERMUD
        if(file == "secure/UDP_CMD_DIR/mail") return 1;
#endif
        if(file != MAILER) { 
          fail("Illegal Mailer Object");
          return 0;
        }
      }
#endif /* MAILER */
      return 1;
      break;


    case "file_size":
      return path[1..];
      break;

    case "tail":
    case "cat":
    case "read_bytes":
    case "read_file":
      if(member(OPEN_FILES, path) != -1) {
        return path[1..];
      }
      break;

    case "ed_start":
      if(!restricted_caller) {
        fail("Illegal Object using ed()");
        return 0;
      }
  /* if(!add_current_edit(path)) return 0; /* someone is already editing */
      break;

    case "file_time":
    case "get_dir":
      if(restricted_caller) {
        return path[1..];
      }
      break;

    case "do_rename":
    case "print_file":
      break;
  }

#if 0
  if ((file = valid_write(path, caller, 0))) 
  {
    return file;
  }
#endif

  if(name) 
  {
    if((sscanf(path,"%s/"+ name +"/%s", who, file) == 2
     || sscanf(path,"%s/"+ name +".%s", who, file) == 2
     || sscanf(path,"%s/"+name,file) == 1)
    && sscanf(path,"/usr/%s", file) != 1) 
    {
      return path[1..];
    }
  }
 
  if(member(OPEN_FILES, path) != -1) 
  {
    return path[1..];
  }

#ifdef QC
  if(sscanf(path, "%s/private/%s", who, file) != 2) 
  {
    if(member(QC, name) != -1) 
    {
      return path[1..];
    }
  }
#endif /* QC */

  switch(security_level) {
    case SEC9:
    case SEC8:
      return path[1..];

    case SEC7:
    case SEC6:
      if(sscanf(path, "%s/private/%s", who, file) == 2
      || sscanf(path, "/room/post/%s", file) == 1) {
        break;        
      }
      return path[1..];

    case SEC5:
    case SEC4:
    case SEC3:
      if(sscanf(path, "/room/post/%s", file) == 1
      || sscanf(path, "%s/private/%s", who, file) == 2) {
        break;
      }

      if(sscanf(path, "/inherit/%s", file) == 1
      || sscanf(path, "/obj/%s", file) == 1
      || sscanf(path, "/function/%s", file) == 1  
      || sscanf(path, "/inherit/%s", file) == 1
      || sscanf(path, "/objects/%s", file) == 1
      || sscanf(path, "/doc/%s", file) == 1
      || sscanf(path, "/room/%s", file) == 1
      || sscanf(path, "/bin/%s", who) == 1
      || sscanf(path, "/skills/%s", file) == 1) {
        return path[1..];
      }

    case SEC2:
    case SEC1:
      if(sscanf(path, "/room/post/%s", file) == 1
      || sscanf(path, "%s/private/%s", who, file) == 2) {
        break;
      }
  
      if (sscanf(path, "/ideas/%s", file) == 1
       || sscanf(path, "/doc/%s", file) == 1
       || sscanf(path, "/log/%s", file) == 1
       || sscanf(path, "/info/%s", file) == 1
       || sscanf(path, "/inherit/%s", file) ==1
       || sscanf(path, "/room/%s", file) == 1
       || sscanf(path, "/manuals/%s", file) == 1
       || sscanf(path, "/objects/%s", file) == 1) 
      {
        return path[1..];
      }

    case SEC0:
      if(sscanf(path, "/room/post/%s", file) == 1
      || sscanf(path, "%s/private/%s", who, file) == 2) 
      {
        break;
      }

      if (sscanf(path, "%s/open/%s", who, file) == 2
       || sscanf(path, "/manuals/%s", file) == 1
       || sscanf(path, "/help/%s", file) == 1
       || sscanf(path, "/info/%s", file) == 1
       || sscanf(path, "/news/%s", file) == 1
       || sscanf(path, "%s.dat", file) == 1)
      {
        return path[1..];
      }
      break;

    default:
      write("Error: Unknown Security Level.\n");

  } 

  if(sscanf(path, WIZARD_DIR +"%s/%s", who, file) == 2) {
    if(call_other(WIZARD_DIR+who+"/access","valid_read",path,name)) {
      return path[1..];
    }
  }

  if(sscanf(path, DOMAIN_DIR +"%s", file) == 1) {
    if(call_other(DOMAIN_DIR +"/access", "valid_read",path,name)) {
      return path[1..];
    }
  }

  return 0;
}

