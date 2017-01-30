#pragma verbose_errors

// BIN_D.C -- Bin Command Daemon v3.01
// Copyright (c) 1995,1994 Andrew T. Graham -- All Rights Reserved
// May be copied and modfied as long as this header remains attached.
// Internet Email:  atgraham@ptd.net
// Intermud Email:  Geewhiz@DragonHeart
 
// Geewhiz@Dreamtime for Dreamtime & DoD
// Modified For DragonHeart 950723G
// Further Enhancements 950805G
///////////////////////////
// Rewrite to v3.01 (Aug 31, 1998)
// Features for this release:
// o FAST! Command Lookups (as compared to bin systems which
//   check comand filesizes, etc, on each command execution)
// o Supports custom bin paths per user
// o Allows for bin commands to have secondary verb aliases
//   (e.g. _score.c can add the verb 'score' and 'sc')
// o Global Command Table Rehash; Only needs to be done once after addding
//   a command to a path.
// o Auto rehash firstime a directory path is referenced
// o Automaticly Detects (and performs) Auto-Rehashing on a command-by-command
//   basis.
// o Removes error-causing Bin Commands from the Command Table automaticly.
// o Handles any common bin command 'main' call format:
//   cmd_verb(), _verb(), verb(), & main()
///////////////////////////
 
 
#include "/include/mudlib.h"
#include "/include/cfg/levels.h"
// #include <page.h>

#define page(X) _page(X)

void _page(string str) {
    write(str);
}

// UserConfig
 
#define STANDARD_PATHS \
    ({\
        "bin/creator",\
        "bin/std",\
        "bin/player",\
    })

#define ALIAS_FUNC "query_cmd_aliases"
 
#undef FORCE_IMMEDIATE_SWAP
 
#define DEBUG_WIZ "rumplemintz"

// End Config
 
#ifdef DEBUG_WIZ
#define DBG(X) if(find_player(DEBUG_WIZ))\
                     tell_object(find_player(DEBUG_WIZ),(X)+"\n")
#else
#define DBG(X)
#endif
 
#define DIR          0
#define LEV          1
#define C_WARNING    "WARNING"
#define C_FAILURE    "FAILURE"
#define C_FATAL      "FATAL  "
#define C_INFO       "INFO   "

// This is a kludge, it is used to detect when a bin command object
// was recompiled, unloaded, etc, the following error is thrown by
// the closure funcall, and caught by catch.
#define OBJ_DEST_ERR "*Object the closure was bound to has been destructed\n"

mapping cmd_table = ([ ]);

closure do_cmd,do_help,do_rehash,print_entry,sprint_entry,short_sprint_entry;
 
  void log(string class, string msg);
status query_prevent_shadow();
  void add_cmd_verb(string p, string v, closure c, closure h, string f);
  void add_cmd_file(string path,string dir);
  void fill_cmd_table(string dir);
varargs void rehash(string dir, string *paths);
  void reset(int started);
status dumpcmdtable(string long);
status bin_dir_hook(string arg, string *paths);

string fix_directory(string dir) {
    if(dir[0] == '/') dir = dir[1..];
    if(dir[<1] == '/') dir = dir[0..strlen(dir)-1];
    return dir;
}

status query_prevent_shadow() { return 1; }
 
 
void log(string class, string msg) {
    log_file("BIND",sprintf("%s %s: %s\n",ctime(),class,msg));
}
 
 
void add_cmd_verb(string p,string v,closure c,closure h,string f) {
DBG(sprintf("c_t[%O] += ([ %O : %O; %O; %O ])",p,v,c,h,f));
    cmd_table[p] += ([ v : c; h; f ]);
}
 
void find_or_load(string path,string verb) {
    string file, msg;
    object ob;

    fix_directory(&path);

    if(!cmd_table
    || !cmd_table[path])
        return;
        
    if(ob = find_object(file = cmd_table[path][verb,3])) return;
    msg = catch(call_other(file,"_?",0));
    if(!msg) return;
    log(C_FATAL,sprintf("Path: '%s' Verb: '%s' File: '%s' -> Error: '%s'",path,verb,file,msg));
    printf("bin_d:  Cannot load file for '%s'.  Notify a wizard.\n");
}
 
void add_cmd_file(string path, string file) {
    string *verbs, verb, f, func, tmp1, tmp2;
    closure ccl, hcl;
    int i;
 
    if(!mappingp(cmd_table)) cmd_table = ([ ]);
    fix_directory(&path);   
    if(!mappingp(cmd_table[path])) cmd_table[path] = ([ ]);

    ccl = hcl = 0;
 
    f = explode(file,"/")[<1];
    if((sscanf(f,"_%s.c",verb) != 1)
    && (sscanf(f,"%s.c",verb) != 1)) return;
    if(sscanf(verb,"%s.%s",tmp1,tmp2) > 0) return;
    if(sscanf(verb,"%s_%s",tmp1,tmp2) > 0) return;
    

    cmd_table[path] = m_delete(cmd_table[path], verb);  // Failsafe
 
    if(catch(ccl = symbol_function("main",file)))
        return log(C_FAILURE,"File "+file+" would not load!");
    if(!ccl) ccl = symbol_function(sprintf("_%s",verb),file);
    if(!ccl) ccl = symbol_function(verb,file);
    if(!ccl) ccl = symbol_function("main",file);
    if(!ccl) return;
 
    hcl = symbol_function("help",file);
 
DBG(sprintf("bin_d: add_cmd_file:\t%s",verb));
    add_cmd_verb(path,verb,ccl,hcl,file);
 
#ifdef ALIAS_FUNC
    if((verbs=(string*)call_other(file,ALIAS_FUNC)) && (i=sizeof(verbs)))
        while( ( ( ( i-- ) ) && ( verbs[i] != verb ) ) ){
DBG(sprintf("\t\t\t%s",verbs[i]));
            add_cmd_verb(path,verbs[i],ccl,hcl,file);
        }
#endif /* ALIAS_FUNC */
 
#ifdef FORCE_IMMEDIATE_SWAP
     swap(find_object(file));
DBG(" Swapping " + file + ".");
#endif /* FORCE_IMMEDIATE_SWAP */
}
 

void fill_cmd_table(string dir) {
    string *files, file; 
    int i;

    if(!mappingp(cmd_table)) cmd_table = ([ ]);

    fix_directory(&dir);

    files = get_dir(sprintf("/%s/*",dir));
 
    if(!files || !(i = sizeof(files)))
        return log(C_WARNING,"No Files In /"+dir);

    if(!mappingp(cmd_table[dir])) cmd_table[dir] = ([ ]);

    while(i--) 
        add_cmd_file(dir,sprintf("/%s/%s",dir, files[i]));
}
 
 
void rehash(string arg, string *paths) {
    int i;
    if(arg && arg != "") {
        printf("%s...\n",fix_directory(&arg));
        log(C_INFO,"Rehashed path '"+arg+"'.");
        fill_cmd_table(arg);
        return;
    }
    i = sizeof(paths);
    if(i) {
        while(i--) {
            rehash(paths[i],0);
        }
    } else {
        if((paths = (string *) this_player()->query_paths())
        && sizeof(paths))
            rehash(0,paths);
        else
            printf("No paths to rehash.\n");
    }
}
     
void reset(int started) {
DBG(sprintf("bin_d: reset(%d);",started));
    call_out("rehash",0,0,STANDARD_PATHS);
    if(started) return;
    log(C_INFO,"Bin_D Loaded");
 
   do_rehash = lambda( ({ 'func, 'path, 'verb, 'arg }),
    ({ #',,
      ({ #'?,
        ({ #'&&,
            ({#'m_contains, ({#'&,'bin }),({#'cmd_table}), 'path }),
            ({#'m_contains,({#'&,'ccl }), ({#'&,'hcl}),({#'&,'file}),'bin,'verb})
        }),
        ({ #',,
            ({ #'log,C_WARNING,({#'sprintf,"Auto Rehashed %O",'file})}),
            ({ #'add_cmd_file, 'bin, 'file }),
            ({ #'funcall, 'func, 'path, 'verb, 'arg })
        }), 0
      })
    }));
 
    do_cmd = lambda( ({ 'path, 'verb, 'arg }),
    ({ #',,
      ({ #'?,
        ({ #'&&,
            ({#'m_contains,({#'&,'bin}),({#'cmd_table}), 'path }),
            ({#'m_contains,({#'&,'ccl}),({#'&,'hcl}),({#'&,'file}),'bin,'verb})
        }),
        ({#'funcall,'ccl,'arg}),
        0 
      })
    }));
 
    do_help = lambda( ({ 'path, 'verb, 'null }),
    ({ #',,
        ({ #'?,
        ({ #'&&,
            ({#'m_contains,({#'&,'bin}),({#'cmd_table}), 'path }),
            ({#'m_contains,({#'&,'ccl}),({#'&,'hcl}),({#'&,'file}),'bin,'verb})
        }),
        ({ ({#'funcall,'hcl}), 1 }),
        0
        })
    }));
 
    print_entry = lambda( ({ 'verb, 'c, 'h, 'l, 'f }),
        ({ #'sprintf, "%-10s : %O %O\n", 'verb, 'c, 'h }) 
    ); 
 
    sprint_entry = lambda( ({ 'verb, 'c, 'h, 'l, 'f, 'ret }),
        ({ #'+=, 'ret, ({ #'sprintf, "%-10s [%3d] %s %-30s\n",
                 'verb, 'l, ({ #'?, 'h, "*", " "}), 'f })
    })); 
 
    short_sprint_entry = lambda( ({ 'verb, 'c, 'h, 'l, 'f, 'ret }),
        ({ #'+=, 'ret, ({ #'sprintf, "%s, ", 'verb }) })
    ); 
}
 
mapping query_cmdtable(string path) {
    if(!path)
        return copy(cmd_table);
    return copy(cmd_table[fix_directory(path)]);
}

int exec_cmd(string path, string verb, string arg) {    
    int ret;
    string err;
    
    if(!member(cmd_table,path))
        rehash(0,({ path }));

    if(verb == "help") {
        err = catch(ret = funcall(do_cmd,path,verb,arg));
        if(err || !ret) {
            find_or_load(path,arg);
            err = catch(ret = funcall(do_help,path,arg));
            if(err && err == OBJ_DEST_ERR) {
                notify_fail("Auto-Rehash failed on 'help "+arg+"'.\n");
                ret = funcall(do_rehash,do_help,path,arg,arg);
            }
            return ret;
        }
        return ret;
    }

    find_or_load(path,verb);

    err = catch(ret = funcall(do_cmd,path,verb,arg,0));
    if(err && err == OBJ_DEST_ERR) {
        notify_fail("Auto-Rehash failed on '"+verb+"'.\n");
        ret = funcall(do_rehash,do_cmd,path,verb,arg);
    }

    if(stringp(err)) {
        log(C_WARNING,sprintf("Cmd %O Err %O",verb,err));
        if(this_player()->query_security_level())
            printf("bin_d: Warning:\n  Command %O generated error:\n  %s\n",verb,err);
    }
    return ret;
}

 
status dumpcmdtable(string long) {
    string *verbs, header, data;
DBG(sprintf("bin_d: dumpcmdtable(%O);",long));
    log(C_INFO,"Command Table Dumped" + (long ? "(Long)" : "(Short)"));
    if(!long) {
        header = sprintf("%|79s\n","Standard Commands"); 
        data = "";
        walk_mapping(cmd_table,short_sprint_entry,&data);
        data = implode(sort_array(explode(data,", "),#'>),", ");
        data = header + sprintf("%-=79s\n",data[2..]);
    } else {
        header = sprintf("%|10s %|5s %s\n%|10s %|5s %s %|30s",
                       "","SEC","Help Available","Verb","Level","|","File"); 
        data = "";
        walk_mapping(cmd_table,sprint_entry,&data);
        data = implode(sort_array(explode(data,"\n"),#'>),"\n");
        data = header+data;
    }
    return page(data),1;
}
 
status bin_dir_hook(string arg, string *paths) {
    string verb, err;
    status ret;
    int i;

    verb = query_verb();
    
DBG(sprintf("bin_d: bin_dir_hook:  %s(%O);",verb,arg));

    if(!cmd_table || !mappingp(cmd_table)) 
        cmd_table = ([ ]);

    switch(verb) {
        case "rehash": 
            printf("Rehashing command lookup table...\n");
            rehash(arg, paths); printf("Done.\n"); return 1; break;
//        case "dumpcmdtable":
//            return dumpcmdtable(arg,paths); break;
    }
    
    i = sizeof(paths);
    if(i) while(i--)
        if(exec_cmd(paths[i],verb,arg))
            return 1;
    return 0;
}

