/* ADD BODY PARTS HERE */
add_legs() {
  write_file(LOG+"LEGS",TPRN+" "+ENV()->RN+" "+ctime(time())+"\n");
  legs++;
  save_me(ENVTO);
  return 1; }
add_arms() {
  write_file(LOG+"ARMS",TPRN+" "+ENV()->RN+" "+ctime(time())+"\n");
  arms++;
  save_me(ENVTO);
  return 1; }
add_eyes() {
  write_file(LOG+"EYES",TPRN+" "+ENV()->RN+" "+ctime(time())+"\n");
  eyes++;
  save_me(ENVTO);
  return 1; }
add_liver() {
  write_file(LOG+"LIVER",TPRN+" "+ENV()->RN+" "+ctime(time())+"\n");
  liver++;
  save_me(ENVTO);
  return 1; }
add_stomach() {
  write_file(LOG+"STOMACH",TPRN+" "+ENV()->RN+" "+ctime(time())+"\n");
  stomach++;
  save_me(ENVTO);
  return 1; }
add_reflex() {
  write_file(LOG+"REFLEX",TPRN+" "+ENV()->RN+" "+ctime(time())+"\n");
  reflex++;
  save_me(ENVTO);
  return 1; }
add_skeleton() {
  write_file(LOG+"SKELETON",TPRN+" "+ENV()->RN+" "+ctime(time())+"\n");
  skeleton++;
  save_me(ENVTO);
  return 1; }
add_armor() {
  write_file(LOG+"ARMOR",TPRN+" "+ENV()->RN+" "+ctime(time())+"\n");
  armor++;
  save_me(ENVTO);
  return 1; }
query_legs() { return legs; }
query_arms() { return arms; }
query_eyes() { return eyes; }
query_liver() { return liver; }
query_stomach() { return stomach; }
query_reflex() { return reflex; }
query_skeleton() { return skeleton; }
query_armor() { return armor; }
/* FUNCTIONAL EXPERIENCE */
/* QUERY BODY PART XP */
query_legs_xp() { return legs_xp; }
query_arms_xp() { return arms_xp; }
query_liver_xp() { return liver_xp; }
query_eyes_xp() { return eyes_xp; }
query_stomach_xp() { return stomach_xp; }
query_reflex_xp() { return reflex_xp; }
query_skeleton_xp() { return skeleton_xp; }
/* QUERY BODY PART LEVEL */
query_legs_level() { return legs_level; }
query_arms_level() { return arms_level; }
query_liver_level() { return liver_level; }
query_eyes_level() { return eyes_level; }
query_stomach_level() { return stomach_level; }
query_reflex_level() { return reflex_level; }
query_skeleton_level() { return skeleton_level; }
/* ADD BODY PART XP */
add_body_xp(string str, int num) {
  int nextnum, nextlev;
  int bodypart;
  nextnum = get_nextlevel(str);
  nextlev = convert_level(str);
  nextlev++;
  if(nextnum == 999) return;
  if(str == "legs") { legs_xp += num; bodypart = legs_xp; }
  if(str == "arms") { arms_xp += num; bodypart = arms_xp; }
  if(str == "liver") { liver_xp += num; bodypart = liver_xp; }
  if(str == "eyes") { eyes_xp += num; bodypart = eyes_xp; }
  if(str == "stomach") { stomach_xp += num; bodypart = stomach_xp; }
  if(str == "reflex") { reflex_xp += num; bodypart = reflex_xp; }
  if(str == "skeleton") { skeleton_xp += num; bodypart = skeleton_xp; }
  if(bodypart > nextnum) add_body_level(str, nextlev);
  if(TP && NOTME) write_file("/players/snow/guild/logs/BODYXP",
   TP->query_real_name()+" "+ENV()->query_real_name()+" "+str+" "+num+" "+ctime()+"\n");
  save_me();
  return 1; }
get_nextlevel(string str) {
  int bodypart;
  bodypart = convert_level(str);
  if(str == "arms") {
    if(bodypart == 1) return 1000;
    if(bodypart == 2) return 5000;
    if(bodypart == 3) return 15000;
    if(bodypart == 4) return 50000;
    if(bodypart == 5) return 999; }
  if(str == "legs") {
    if(bodypart == 1) return 1000;
    if(bodypart == 2) return 5000;
    if(bodypart == 3) return 15000;
    if(bodypart == 4) return 50000;
    if(bodypart == 5) return 999; }
  if(str == "liver") {
    if(bodypart == 1) return 1000;
    if(bodypart == 2) return 5000;
    if(bodypart == 3) return 15000;
    if(bodypart == 4) return 50000;
    if(bodypart == 5) return 999; }
  if(str == "eyes") {
    if(bodypart == 1) return 1000;
    if(bodypart == 2) return 5000;
    if(bodypart == 3) return 15000;
    if(bodypart == 4) return 50000;
    if(bodypart == 5) return 999; }
  if(str == "stomach") {
    if(bodypart == 1) return 1000;
    if(bodypart == 2) return 5000;
    if(bodypart == 3) return 15000;
    if(bodypart == 4) return 50000;
    if(bodypart == 5) return 999; }
  if(str == "reflex") {
    if(bodypart == 1) return 1000;
    if(bodypart == 2) return 5000;
    if(bodypart == 3) return 15000;
    if(bodypart == 4) return 50000;
    if(bodypart == 5) return 999; }
  if(str == "skeleton") {
    if(bodypart == 1) return 1000;
    if(bodypart == 2) return 5000;
    if(bodypart == 3) return 15000;
    if(bodypart == 4) return 50000;
    if(bodypart == 5) return 999; }
  return; }
convert_level(string str) {
  if(str == "legs") return legs_level;
  if(str == "arms") return arms_level;
  if(str == "liver") return liver_level;
  if(str == "eyes") return eyes_level;
  if(str == "stomach") return stomach_level;
  if(str == "reflex") return reflex_level;
  if(str == "skeleton") return skeleton_level;
  else return; }
add_body_level(string str, int num) {
  if(str == "arms") {
    TE(ENV(), BOLD+"\n\tYou have gained mastery of Arms function "+num+"!\n\n"+OFF);
    arms_level++; }
  if(str == "legs") {
    TE(ENV(), BOLD+"\n\tYou have gained mastery of Legs function "+num+"!\n\n"+OFF);
    legs_level++; }
  if(str == "liver") {
    TE(ENV(), BOLD+"\n\tYou have gained mastery of Liver function "+num+"!\n\n"+OFF);
    liver_level++; }
  if(str == "eyes") {
    TE(ENV(), BOLD+"\n\tYou have gained mastery of Eyes function "+num+"!\n\n"+OFF);
    eyes_level++; }
  if(str == "stomach") {
    TE(ENV(), BOLD+"\n\tYou have gained mastery of Stomach function "+num+"!\n\n"+OFF);
    stomach_level++; }
  if(str == "reflex") {
    TE(ENV(), BOLD+"\n\tYou have gained mastery of Reflex function "+num+"!\n\n"+OFF);
    reflex_level++; }
  if(str == "skeleton") {
    TE(ENV(), BOLD+"\n\tYou have gained mastery of Skeleton function "+num+"!\n\n"+OFF);
    skeleton_level++; }
  save_me();  return 1; }
