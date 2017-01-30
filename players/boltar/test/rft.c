init() {
  add_action("bb","bb");
}
bb() {
 string file;
 string a,b,c,d,e,f,g;
 file="/players/boltar/test/test";
 a=read_file(file,1,1);
write("ONE:\n");write(a+"\n");
 b=read_file(file,2,1);
write("TWO:\n");write(b+"\n");
 c=read_file(file,3,1);
write("THREE:\n");write(c+"\n");
 d=read_file(file,4,1);
write("FOUR:\n");write(d+"\n");
 e=read_file(file,5,1);
write("FIVE:\n");write(e+"\n");
 f=read_file(file,6,1);
write("SIX:\n");write(f+"\n");
 g=read_file(file,0,1);
write("ZERO:\n");write(g+"\n");
write("DONE\n");
write(save_object("players/boltar/test/rft")); write("\n");
return 1;
}
