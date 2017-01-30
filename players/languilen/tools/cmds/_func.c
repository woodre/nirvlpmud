cmd_func(str){
     string name;
     string function;
     string arg;
     mixed return_val;

     object target;

     if(!str){
        write("Usage: func <who> <function>:<arg>.\n");
        return 1;
     }
     if( sscanf(str, "%s %s:%s", name, function, arg) == 3 ){
        target = present(name, this_player());
        if(!target){
           target = present(name, environment(this_player()));
           if(!target){
              write("There is no "+name+" here!\n");
              return 1;
           }
        }
        return_val = call_other(target,function,arg);
        if(return_val){
           if( stringp(return_val) ){
              write(return_val+".\n");
           }
        }
        write("done.\n");
        return 1;
     }
     if(sscanf(str, "%s %s", name, function) == 2){
        target = present(name, this_player());
        if(!target){
           write("There is no "+name+" here!\n");
           return 1;
        }
        return_val = call_other(target,function);
        if(return_val){
           if( stringp(return_val) ){
              write(return_val+".\n");
           }
        }
        write("done.\n");
        return 1;
     }
     write("Usage: func <name> <function> <args>\n");
     return 1;
}

