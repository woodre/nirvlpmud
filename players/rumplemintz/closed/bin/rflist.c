
__plistM(fun, obj){ return function_exists(fun, obj); }
__flistM(fun, mod){ if(fun[1]==mod) return fun[0]; }

list_functions(ob, pat1, pat2){
    string *list, plist, modules;
    int t;
    list = functionlist(ob);
    modules = inherit_list(ob);
    if(pat1) list = regexp(list, pat1);
    if(pat2) modules = regexp(modules, pat2);
    plist = map_array(list, "__plistM", this_object(), ob);
    list = transpose_array(({list, plist}));
    for(t=0;t<sizeof(modules);t++){
	write("\tFunctions of \""+modules[t]+"\":\n");
	printf("%-#*s\n", 80, implode(map_array(list,"__flistM",this_object(),modules[t][0..<3]),"\n"));
    }
    return 1;
}
