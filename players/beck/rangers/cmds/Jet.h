/* The Power Ranger Speedster used by the command 'Jet'     */

ranger_jet(string str) {
   string c1, c2, c3, c4, c5, c6, c7, c8;
   c1 = c2 = c3 = c4 = c5 = "";
if(!COMM->QMorphed() && !COMM->QNinja() ){
      return 0;
   }
   if(!str){
      write("Where are you jetting to?\n");
      return 1;
   }
   if(sscanf(str, "%s,%s,%s,%s,%s", c1, c2, c3, c4, c5) == 5) {
      cmds = ({c1,c2,c3,c4,c5});
      check_jet();
      return 1; }
   if(sscanf(str, "%s,%s,%s,%s", c1, c2, c3, c4) == 4) {
      cmds = ({c1,c2,c3,c4});
      check_jet();
      return 1; }
   if(sscanf(str, "%s,%s,%s", c1, c2, c3) == 3) {
      cmds = ({c1,c2,c3});
      check_jet();
      return 1; }
   if(sscanf(str, "%s,%s", c1, c2) == 2) {
      cmds = ({c1,c2});
      check_jet();
      return 1; }
   if(sscanf(str, "%s", c1) == 1) {
      cmds = ({c1});
      check_jet();
      return 1; }
   return 1;
}
/*  This makes sure 'Jet' is only used in legal directions for the guild */

check_jet(){
   int v;
   for( v=0; v<sizeof(cmds); v++) {
      if((cmds[v]) != "n" && (cmds[v]) != "e" && (cmds[v]) != "w" &&
            (cmds[v]) != "s" && (cmds[v]) != "se" && (cmds[v]) != "ne" && (cmds[v]) != "sw" &&
         (cmds[v]) != "nw" && (cmds[v]) != "u" && (cmds[v]) != "d" &&
         (cmds[v]) != ""){
         write("That is not a place you can 'jet' to!\n");
         return 1;}
      COMM->ASkillExp(2);
      command(cmds[v], this_player());}
   return 1;
}
