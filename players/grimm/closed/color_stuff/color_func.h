#define esc ""
#define WHITE esc+"[1m"
#define BLINK esc+"[5m"
#define REVERSE esc+"[7m"
#define RED esc+"[31m"
#define GREEN esc+"[32m"
#define BROWN esc+"[33m"
#define BLUE esc+"[34m"
#define PURPLE esc+"[35m"
#define LIGHT_BLUE esc+"[36m"
#define END esc+"[0m"
#define OFF END

check_color(mrob) {
  if(!mrob) return this_player()->query_color();
  return mrob->query_color();
}

white(str,mrob) {
  if(check_color(mrob)) return WHITE+str+OFF;
  return str;
}

red(str,mrob) {
  if(check_color(mrob)) return RED+str+OFF;
  return str;
}

green(str,mrob) {
  if(check_color(mrob)) return GREEN+str+OFF;
  return str;
}

brown(str,mrob) {
  if(check_color(mrob)) return BROWN+str+OFF;
  return str;
}

blue(str,mrob) {
  if(check_color(mrob)) return BLUE+str+OFF;
  return str;
}

purple(str,mrob) {
  if(check_color(mrob)) return PURPLE+str+OFF;
  return str;
}

l_blue(str,mrob) {
  if(check_color(mrob)) return LIGHT_BLUE+str+OFF;
  return str;
}

blink(str,mrob) {
  if(check_color(mrob)) return BLINK+str+OFF;
  return str;
}

reverse(str,mrob) {
  if(check_color(mrob)) return REVERSE+str+OFF;
  return str;
}
